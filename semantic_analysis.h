/* ═══════════════════════════════════════════════════════════════════════════
   ENHANCED SEMANTIC ANALYSIS MODULE
   
   This module provides production-grade semantic validation functions that
   complement the existing symbol table with type checking, scope analysis,
   and control flow validation.
   
   ═══════════════════════════════════════════════════════════════════════════ */

#ifndef SEMANTIC_ANALYSIS_H
#define SEMANTIC_ANALYSIS_H

#include "ast.h"
#include "symbol_table.h"

/* ═══════════════════════════════════════════════════════════════════════════
   1. TYPE CHECKING FUNCTIONS
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Validates that an expression's inferred type matches the expected type.
 * Returns true if types are compatible (including implicit conversions).
 * Sets *error_message if incompatible.
 */
bool validateExpressionType(ASTNode *expr, DataType expectedType, 
                            char **error_message);

/**
 * Infers the type of an expression based on its operator and operands.
 * Returns the inferred type, or TYPE_ERROR if inference fails.
 */
DataType inferExpressionType(ASTNode *expr);

/**
 * Checks if implicit conversion is allowed from 'from' to 'to' type.
 * Follows C type promotion rules (int->float OK, float->int with warning, etc.)
 */
bool isImplicitConversionAllowed(DataType from, DataType to);

/* ═══════════════════════════════════════════════════════════════════════════
   2. CONTROL FLOW ANALYSIS
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Tracks control flow state through function bodies.
 * Used to detect unreachable code and missing returns.
 */
typedef struct {
    bool hasReturn;              /* Function has at least one return statement */
    bool allPathsReturn;         /* All code paths return a value */
    bool inLoop;                 /* Currently inside a loop */
    bool unreachableCode;        /* Dead code after return/break/continue */
    int lineOfLastReturn;        /* Line number of last return statement */
} ControlFlowAnalysis;

/**
 * Analyzes control flow of a statement or function body.
 * Returns true if analysis is valid, false if control flow errors found.
 */
bool analyzeControlFlow(ASTNode *node, ControlFlowAnalysis *analysis);

/* ═══════════════════════════════════════════════════════════════════════════
   3. FUNCTION DECLARATION & RETURN TYPE VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Validates a function declaration:
 * - Checks for duplicate function definitions
 * - Validates parameter types
 * - Checks return type is non-void for non-void functions
 * Returns true if valid, false if validation errors.
 */
bool validateFunctionDecl(ASTNode *funcDecl, SymbolTable *symTable);

/**
 * Validates a return statement:
 * - Checks return value type matches function return type
 * - Ensures return statement is inside a function
 * - For void functions: return value must be NULL
 * - For non-void functions: return value type must be compatible
 * Returns true if valid, false if validation errors.
 */
bool validateReturnStmt(ASTNode *returnStmt, DataType functionReturnType);

/**
 * Validates that a function has a return statement if non-void.
 * Used to ensure all non-void functions return a value on all paths.
 */
bool validateFunctionReturns(ASTNode *funcDecl, ControlFlowAnalysis *analysis);

/* ═══════════════════════════════════════════════════════════════════════════
   4. VARIABLE VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Validates variable declaration:
 * - Checks for duplicate declarations in same scope
 * - Validates initial value type (if provided)
 * Returns true if valid, false if validation errors.
 */
bool validateVarDecl(ASTNode *varDecl, SymbolTable *symTable, int currentScope);

/**
 * Validates variable usage:
 * - Checks if variable is declared
 * - Checks if variable is initialized before use
 * Returns true if valid, false if validation errors.
 */
bool validateVarUsage(const char *varName, int line, SymbolTable *symTable);

/**
 * Validates an assignment statement:
 * - Checks LHS is assignable (variable or array element)
 * - Checks RHS type is compatible with LHS
 * Returns true if valid, false if validation errors.
 */
bool validateAssignment(ASTNode *assignStmt);

/* ═══════════════════════════════════════════════════════════════════════════
   5. ARRAY VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Validates array access:
 * - Checks array is actually an array type
 * - Checks index is integer type
 * Returns true if valid, false if validation errors.
 */
bool validateArrayAccess(ASTNode *arrayAccess);

/**
 * Validates array declaration:
 * - Checks array size is a positive integer literal
 */
bool validateArrayDecl(ASTNode *arrayDecl);

/* ═══════════════════════════════════════════════════════════════════════════
   6. FUNCTION CALL VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Validates function call:
 * - Checks function is declared
 * - Checks argument count matches parameter count
 * - Checks argument types match parameter types
 * Returns true if valid, false if validation errors.
 */
bool validateFunctionCall(ASTNode *callExpr, SymbolTable *symTable);

/* ═══════════════════════════════════════════════════════════════════════════
   7. ERROR REPORTING
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Reports a semantic error with formatted message.
 * Tracks error count for compilation failure.
 */
void reportSemanticError(int line, const char *category, 
                         const char *format, ...);

/**
 * Reports a semantic warning (doesn't fail compilation).
 */
void reportSemanticWarning(int line, const char *category, 
                           const char *format, ...);

/**
 * Gets total semantic error count.
 */
int getSemanticErrorCount(void);

/**
 * Resets semantic error count (for multi-file compilation).
 */
void resetSemanticErrorCount(void);

/* ═══════════════════════════════════════════════════════════════════════════
   8. FULL AST VALIDATION
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Performs comprehensive semantic analysis on entire AST.
 * Runs all validation checks and reports all errors found.
 * Returns true if valid (no errors), false if errors found.
 */
bool performSemanticAnalysis(ASTNode *astRoot, SymbolTable *symTable);

#endif /* SEMANTIC_ANALYSIS_H */
