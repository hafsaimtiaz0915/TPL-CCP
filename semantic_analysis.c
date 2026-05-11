/* ═══════════════════════════════════════════════════════════════════════════
   SEMANTIC ANALYSIS IMPLEMENTATION
   
   Comprehensive type checking, control flow analysis, and validation.
   
   ═══════════════════════════════════════════════════════════════════════════ */

#include "semantic_analysis.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global error tracking */
static int semantic_error_count = 0;
static int semantic_warning_count = 0;

/* ═══════════════════════════════════════════════════════════════════════════
   1. ERROR REPORTING
   ═══════════════════════════════════════════════════════════════════════════ */

void reportSemanticError(int line, const char *category, const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "[SEMANTIC ERROR] Line %d [%s]: ", line, category);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    va_end(args);
    semantic_error_count++;
}

void reportSemanticWarning(int line, const char *category, const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "[SEMANTIC WARNING] Line %d [%s]: ", line, category);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    va_end(args);
    semantic_warning_count++;
}

int getSemanticErrorCount(void) {
    return semantic_error_count;
}

void resetSemanticErrorCount(void) {
    semantic_error_count = 0;
    semantic_warning_count = 0;
}

/* ═══════════════════════════════════════════════════════════════════════════
   2. TYPE CHECKING FUNCTIONS
   ═══════════════════════════════════════════════════════════════════════════ */

bool isImplicitConversionAllowed(DataType from, DataType to) {
    /* Exact match */
    if (from == to) return true;
    
    /* VOID matches nothing */
    if (from == TYPE_VOID || to == TYPE_VOID) return false;
    
    /* ERROR type matches nothing */
    if (from == TYPE_ERROR || to == TYPE_ERROR) return false;
    
    /* Integer promotion: char -> int */
    if (from == TYPE_CHAR && to == TYPE_INT) return true;
    
    /* Integer to float is allowed */
    if (from == TYPE_INT && to == TYPE_FLOAT) return true;
    if (from == TYPE_CHAR && to == TYPE_FLOAT) return true;
    
    /* Float to int: warning-level allowed but not ideal */
    if (from == TYPE_FLOAT && to == TYPE_INT) return true;
    
    return false;
}

DataType inferExpressionType(ASTNode *expr) {
    if (expr == NULL) return TYPE_ERROR;
    
    switch (expr->type) {
        case NODE_IDENTIFIER:
            return expr->dataType;
            
        case NODE_INT_LITERAL:
            return TYPE_INT;
            
        case NODE_FLOAT_LITERAL:
            return TYPE_FLOAT;
            
        case NODE_STRING_LITERAL:
            return TYPE_CHAR;  /* String is char array, treat element as char */
            
        case NODE_UNARY_OP:
            return expr->dataType;
            
        case NODE_BINARY_OP: {
            DataType left = (expr->childCount > 0) ? 
                            inferExpressionType(expr->children[0]) : TYPE_ERROR;
            DataType right = (expr->childCount > 1) ? 
                             inferExpressionType(expr->children[1]) : TYPE_ERROR;
            
            if (left == TYPE_ERROR || right == TYPE_ERROR) return TYPE_ERROR;
            
            /* Arithmetic operators promote to common type */
            if (left == TYPE_FLOAT || right == TYPE_FLOAT) return TYPE_FLOAT;
            return TYPE_INT;
        }
        
        case NODE_CALL_EXPR:
            return expr->returnType;
            
        case NODE_ARRAY_ACCESS:
            return expr->dataType;
            
        default:
            return TYPE_ERROR;
    }
}

bool validateExpressionType(ASTNode *expr, DataType expectedType, 
                            char **error_message) {
    DataType inferredType = inferExpressionType(expr);
    
    if (inferredType == TYPE_ERROR) {
        if (error_message) {
            *error_message = "Could not infer expression type";
        }
        return false;
    }
    
    if (!isImplicitConversionAllowed(inferredType, expectedType)) {
        if (error_message) {
            static char buffer[256];
            snprintf(buffer, sizeof(buffer), 
                     "Expected '%s' but got '%s'",
                     dataTypeToString(expectedType),
                     dataTypeToString(inferredType));
            *error_message = buffer;
        }
        return false;
    }
    
    return true;
}

/* ═══════════════════════════════════════════════════════════════════════════
   3. VARIABLE VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

bool validateVarUsage(const char *varName, int line, SymbolTable *symTable) {
    if (!varName || !symTable) return false;
    
    Symbol *sym = lookup_symbol(symTable, varName);
    if (sym == NULL) {
        reportSemanticError(line, "UNDECLARED_VAR", 
                           "Variable '%s' is not declared", varName);
        return false;
    }
    
    return true;
}

bool validateVarDecl(ASTNode *varDecl, SymbolTable *symTable, int currentScope) {
    if (!varDecl || varDecl->type != NODE_VAR_DECL) return false;
    
    /* Check for duplicate in current scope */
    Symbol *existing = lookup_symbol(symTable, varDecl->name);
    if (existing && existing->scope_level == currentScope) {
        reportSemanticError(varDecl->lineNumber, "DUPLICATE_VAR",
                           "Variable '%s' already declared at line %d",
                           varDecl->name, existing->line_declared);
        return false;
    }
    
    return true;
}

bool validateAssignment(ASTNode *assignStmt) {
    if (!assignStmt || assignStmt->type != NODE_ASSIGN_STMT) return false;
    if (assignStmt->childCount < 2) return false;
    
    ASTNode *lhs = assignStmt->children[0];
    ASTNode *rhs = assignStmt->children[1];
    
    /* LHS must be assignable (identifier or array access) */
    if (lhs->type != NODE_IDENTIFIER && lhs->type != NODE_ARRAY_ACCESS) {
        reportSemanticError(assignStmt->lineNumber, "INVALID_ASSIGN_LHS",
                           "Assignment LHS must be variable or array element");
        return false;
    }
    
    /* Check type compatibility */
    char *error_msg = NULL;
    if (!validateExpressionType(rhs, lhs->dataType, &error_msg)) {
        reportSemanticError(assignStmt->lineNumber, "TYPE_MISMATCH",
                           "%s", error_msg ? error_msg : "Type mismatch in assignment");
        return false;
    }
    
    return true;
}

/* ═══════════════════════════════════════════════════════════════════════════
   4. ARRAY VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

bool validateArrayAccess(ASTNode *arrayAccess) {
    if (!arrayAccess || arrayAccess->type != NODE_ARRAY_ACCESS) return false;
    if (arrayAccess->childCount < 2) return false;
    
    ASTNode *array = arrayAccess->children[0];
    ASTNode *index = arrayAccess->children[1];
    
    /* Array must be array type */
    if (array->dataType != TYPE_ARRAY) {
        reportSemanticError(arrayAccess->lineNumber, "NOT_ARRAY",
                           "Variable '%s' is not an array", 
                           array->name ? array->name : "???");
        return false;
    }
    
    /* Index must be integer */
    DataType indexType = inferExpressionType(index);
    if (indexType != TYPE_INT) {
        reportSemanticError(arrayAccess->lineNumber, "ARRAY_INDEX_NOT_INT",
                           "Array index must be integer, got '%s'",
                           dataTypeToString(indexType));
        return false;
    }
    
    return true;
}

bool validateArrayDecl(ASTNode *arrayDecl) {
    /* This would check array size is positive integer literal */
    /* For now, simplified - actual implementation depends on grammar */
    return true;
}

/* ═══════════════════════════════════════════════════════════════════════════
   5. FUNCTION VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

bool validateFunctionDecl(ASTNode *funcDecl, SymbolTable *symTable) {
    if (!funcDecl || funcDecl->type != NODE_FUNCTION_DECL) return false;
    
    /* Check for duplicate function definition */
    Symbol *existing = lookup_symbol(symTable, funcDecl->name);
    if (existing && existing->is_function) {
        reportSemanticError(funcDecl->lineNumber, "DUPLICATE_FUNC",
                           "Function '%s' already declared at line %d",
                           funcDecl->name, existing->line_declared);
        return false;
    }
    
    return true;
}

bool validateReturnStmt(ASTNode *returnStmt, DataType functionReturnType) {
    if (!returnStmt || returnStmt->type != NODE_RETURN_STMT) return false;
    
    /* For void functions: no return value allowed */
    if (functionReturnType == TYPE_VOID) {
        if (returnStmt->childCount > 0 && returnStmt->children[0] != NULL) {
            reportSemanticError(returnStmt->lineNumber, "VOID_RETURN_VALUE",
                               "void function should not return a value");
            return false;
        }
        return true;
    }
    
    /* For non-void functions: must have return value */
    if (returnStmt->childCount == 0 || returnStmt->children[0] == NULL) {
        reportSemanticError(returnStmt->lineNumber, "MISSING_RETURN_VALUE",
                           "non-void function must return a value");
        return false;
    }
    
    /* Check return value type compatibility */
    ASTNode *returnValue = returnStmt->children[0];
    DataType returnType = inferExpressionType(returnValue);
    
    if (!isImplicitConversionAllowed(returnType, functionReturnType)) {
        reportSemanticError(returnStmt->lineNumber, "RETURN_TYPE_MISMATCH",
                           "function returns '%s' but return value is '%s'",
                           dataTypeToString(functionReturnType),
                           dataTypeToString(returnType));
        return false;
    }
    
    return true;
}

bool validateFunctionReturns(ASTNode *funcDecl, ControlFlowAnalysis *analysis) {
    if (!funcDecl || funcDecl->type != NODE_FUNCTION_DECL) return false;
    
    /* Void functions don't need return */
    if (funcDecl->returnType == TYPE_VOID) return true;
    
    /* Non-void functions must return on all paths */
    if (!analysis->allPathsReturn) {
        reportSemanticWarning(funcDecl->lineNumber, "NO_RETURN",
                             "non-void function '%s' does not return on all paths",
                             funcDecl->name);
        return false;  /* This is an error, not just warning */
    }
    
    return true;
}

bool validateFunctionCall(ASTNode *callExpr, SymbolTable *symTable) {
    if (!callExpr || callExpr->type != NODE_CALL_EXPR) return false;
    
    /* Check function exists */
    Symbol *funcSym = lookup_symbol(symTable, callExpr->name);
    if (!funcSym || !funcSym->is_function) {
        reportSemanticError(callExpr->lineNumber, "UNDEFINED_FUNC",
                           "Function '%s' is not defined", callExpr->name);
        return false;
    }
    
    /* Note: Full parameter checking would require more metadata */
    /* This is a simplified version */
    
    return true;
}

/* ═══════════════════════════════════════════════════════════════════════════
   6. CONTROL FLOW ANALYSIS
   ═══════════════════════════════════════════════════════════════════════════ */

bool analyzeControlFlow(ASTNode *node, ControlFlowAnalysis *analysis) {
    if (!node || !analysis) return false;
    
    switch (node->type) {
        case NODE_RETURN_STMT:
            analysis->hasReturn = true;
            analysis->allPathsReturn = true;
            analysis->lineOfLastReturn = node->lineNumber;
            break;
            
        case NODE_IF_STMT:
            /* If-else where both branches return: all paths return */
            if (node->childCount >= 3) {
                ControlFlowAnalysis thenBranch = {0};
                ControlFlowAnalysis elseBranch = {0};
                analyzeControlFlow(node->children[1], &thenBranch);
                analyzeControlFlow(node->children[2], &elseBranch);
                
                if (thenBranch.allPathsReturn && elseBranch.allPathsReturn) {
                    analysis->hasReturn = true;
                    analysis->allPathsReturn = true;
                }
            }
            break;
            
        case NODE_WHILE_STMT:
        case NODE_FOR_STMT:
            analysis->inLoop = true;
            break;
            
        default:
            break;
    }
    
    return true;
}

/* ═══════════════════════════════════════════════════════════════════════════
   7. FULL AST VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

static void validateNode(ASTNode *node, SymbolTable *symTable) {
    if (!node) return;
    
    switch (node->type) {
        case NODE_VAR_DECL:
            validateVarDecl(node, symTable, 0);
            break;
            
        case NODE_IDENTIFIER:
            validateVarUsage(node->name, node->lineNumber, symTable);
            break;
            
        case NODE_ASSIGN_STMT:
            validateAssignment(node);
            break;
            
        case NODE_ARRAY_ACCESS:
            validateArrayAccess(node);
            break;
            
        case NODE_FUNCTION_DECL:
            validateFunctionDecl(node, symTable);
            break;
            
        case NODE_CALL_EXPR:
            validateFunctionCall(node, symTable);
            break;
            
        case NODE_RETURN_STMT: {
            /* Simplified: assume we're in a main function returning int */
            validateReturnStmt(node, TYPE_INT);
            break;
        }
        
        default:
            break;
    }
    
    /* Validate children */
    for (int i = 0; i < node->childCount; i++) {
        if (node->children[i]) {
            validateNode(node->children[i], symTable);
        }
    }
}

bool performSemanticAnalysis(ASTNode *astRoot, SymbolTable *symTable) {
    if (!astRoot || !symTable) return false;
    
    resetSemanticErrorCount();
    
    validateNode(astRoot, symTable);
    
    return semantic_error_count == 0;
}
