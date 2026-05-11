#include "ast.h"
#include <stdarg.h>

/* ═══════════════════════════════════════════════════════════════════════════
   INTERNAL HELPER FUNCTIONS
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Internal function to create a base node with minimal initialization
 */
static ASTNode* allocateNode(NodeType type, int lineNumber) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    if (node == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed for AST node\n");
        return NULL;
    }

    node->type = type;
    node->name = NULL;
    node->dataType = TYPE_UNKNOWN;
    node->lineNumber = lineNumber;
    node->scope = NULL;
    node->isInitialized = false;

    node->children = NULL;
    node->childCount = 0;
    node->childCapacity = 0;

    node->returnType = TYPE_VOID;
    node->params = NULL;
    node->paramCount = 0;

    node->errorMessage = NULL;

    return node;
}

/* ═══════════════════════════════════════════════════════════════════════════
   STRING UTILITIES
   ═══════════════════════════════════════════════════════════════════════════ */

const char* nodeTypeToString(NodeType type) {
    switch (type) {
        case NODE_PROGRAM:          return "Program";
        case NODE_FUNCTION_DECL:    return "FunctionDecl";
        case NODE_COMPOUND_STMT:    return "CompoundStmt";
        case NODE_VAR_DECL:         return "VarDecl";
        case NODE_ASSIGN_STMT:      return "AssignStmt";
        case NODE_IF_STMT:          return "IfStmt";
        case NODE_WHILE_STMT:       return "WhileStmt";
        case NODE_FOR_STMT:         return "ForStmt";
        case NODE_RETURN_STMT:      return "ReturnStmt";
        case NODE_EXPR_STMT:        return "ExprStmt";
        case NODE_BREAK_STMT:       return "BreakStmt";
        case NODE_CONTINUE_STMT:    return "ContinueStmt";
        case NODE_BINARY_OP:        return "BinaryOp";
        case NODE_UNARY_OP:         return "UnaryOp";
        case NODE_CALL_EXPR:        return "CallExpr";
        case NODE_IDENTIFIER:       return "Identifier";
        case NODE_INT_LITERAL:      return "IntLiteral";
        case NODE_FLOAT_LITERAL:    return "FloatLiteral";
        case NODE_STRING_LITERAL:   return "StringLiteral";
        case NODE_ARRAY_ACCESS:     return "ArrayAccess";
        case NODE_ERROR:            return "ERROR";
        default:                    return "Unknown";
    }
}

const char* dataTypeToString(DataType type) {
    switch (type) {
        case TYPE_INT:      return "int";
        case TYPE_FLOAT:    return "float";
        case TYPE_CHAR:     return "char";
        case TYPE_VOID:     return "void";
        case TYPE_POINTER:  return "pointer";
        case TYPE_ARRAY:    return "array";
        case TYPE_UNKNOWN:  return "unknown";
        case TYPE_ERROR:    return "error";
        default:            return "?";
    }
}

/* ═══════════════════════════════════════════════════════════════════════════
   SCOPE MANAGEMENT
   ═══════════════════════════════════════════════════════════════════════════ */

Scope* createScope(Scope *parentScope, int scopeLevel) {
    Scope *scope = (Scope *)malloc(sizeof(Scope));
    if (scope == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed for Scope\n");
        return NULL;
    }

    scope->parent_scope = parentScope;
    scope->compound_stmt = NULL;
    scope->scope_level = scopeLevel;

    return scope;
}

void destroyScope(Scope *scope) {
    if (scope == NULL) return;
    free(scope);
}

/* ═══════════════════════════════════════════════════════════════════════════
   CORE AST NODE CREATION
   ═══════════════════════════════════════════════════════════════════════════ */

ASTNode* createNode(NodeType type, int lineNumber) {
    return allocateNode(type, lineNumber);
}

ASTNode* createProgramNode(void) {
    ASTNode *prog = allocateNode(NODE_PROGRAM, 1);
    if (prog) {
        prog->name = strdup("program");
    }
    return prog;
}

ASTNode* createIdentifierNode(const char *name, DataType type, int lineNumber) {
    ASTNode *node = allocateNode(NODE_IDENTIFIER, lineNumber);
    if (node) {
        node->name = strdup(name);
        node->dataType = type;
    }
    return node;
}

ASTNode* createIntLiteralNode(long value, int lineNumber) {
    ASTNode *node = allocateNode(NODE_INT_LITERAL, lineNumber);
    if (node) {
        char buffer[64];
        snprintf(buffer, sizeof(buffer), "%ld", value);
        node->name = strdup(buffer);
        node->dataType = TYPE_INT;
    }
    return node;
}

ASTNode* createFloatLiteralNode(double value, int lineNumber) {
    ASTNode *node = allocateNode(NODE_FLOAT_LITERAL, lineNumber);
    if (node) {
        char buffer[64];
        snprintf(buffer, sizeof(buffer), "%f", value);
        node->name = strdup(buffer);
        node->dataType = TYPE_FLOAT;
    }
    return node;
}

ASTNode* createStringLiteralNode(const char *value, int lineNumber) {
    ASTNode *node = allocateNode(NODE_STRING_LITERAL, lineNumber);
    if (node) {
        node->name = strdup(value);
        node->dataType = TYPE_POINTER;
    }
    return node;
}

ASTNode* createBinaryOpNode(const char *op, ASTNode *left, ASTNode *right,
                            DataType resultType, int lineNumber) {
    ASTNode *node = allocateNode(NODE_BINARY_OP, lineNumber);
    if (node) {
        node->name = strdup(op);
        node->dataType = resultType;
        addChild(node, left);
        addChild(node, right);
    }
    return node;
}

ASTNode* createUnaryOpNode(const char *op, ASTNode *operand,
                           DataType resultType, int lineNumber) {
    ASTNode *node = allocateNode(NODE_UNARY_OP, lineNumber);
    if (node) {
        node->name = strdup(op);
        node->dataType = resultType;
        addChild(node, operand);
    }
    return node;
}

ASTNode* createVarDeclNode(const char *name, DataType type, int lineNumber) {
    ASTNode *node = allocateNode(NODE_VAR_DECL, lineNumber);
    if (node) {
        node->name = strdup(name);
        node->dataType = type;
        node->isInitialized = false;
    }
    return node;
}

ASTNode* createAssignStmtNode(ASTNode *lhs, ASTNode *rhs, int lineNumber) {
    ASTNode *node = allocateNode(NODE_ASSIGN_STMT, lineNumber);
    if (node) {
        /* Inherit type from RHS, but validate compatibility */
        if (rhs) {
            node->dataType = rhs->dataType;
        }
        addChild(node, lhs);
        addChild(node, rhs);
    }
    return node;
}

ASTNode* createIfStmtNode(ASTNode *condition, ASTNode *thenBody,
                          ASTNode *elseBody, int lineNumber) {
    ASTNode *node = allocateNode(NODE_IF_STMT, lineNumber);
    if (node) {
        /* Pre-allocate 3 children: condition, then-body, else-body */
        node->children = (ASTNode **)malloc(3 * sizeof(ASTNode *));
        if (node->children) {
            node->childCapacity = 3;
            node->childCount = 3;
            node->children[0] = condition;
            node->children[1] = thenBody;
            node->children[2] = elseBody;  /* Can be NULL */
        }
    }
    return node;
}

ASTNode* createWhileStmtNode(ASTNode *condition, ASTNode *body, int lineNumber) {
    ASTNode *node = allocateNode(NODE_WHILE_STMT, lineNumber);
    if (node) {
        node->children = (ASTNode **)malloc(2 * sizeof(ASTNode *));
        if (node->children) {
            node->childCapacity = 2;
            node->childCount = 2;
            node->children[0] = condition;
            node->children[1] = body;
        }
    }
    return node;
}

ASTNode* createForStmtNode(ASTNode *init, ASTNode *condition,
                           ASTNode *update, ASTNode *body, int lineNumber) {
    ASTNode *node = allocateNode(NODE_FOR_STMT, lineNumber);
    if (node) {
        /* Pre-allocate 4 children: init, condition, update, body */
        node->children = (ASTNode **)malloc(4 * sizeof(ASTNode *));
        if (node->children) {
            node->childCapacity = 4;
            node->childCount = 4;
            node->children[0] = init;       /* Can be NULL */
            node->children[1] = condition;  /* Can be NULL */
            node->children[2] = update;     /* Can be NULL */
            node->children[3] = body;
        }
    }
    return node;
}

ASTNode* createReturnStmtNode(ASTNode *returnValue, int lineNumber) {
    ASTNode *node = allocateNode(NODE_RETURN_STMT, lineNumber);
    if (node) {
        if (returnValue) {
            addChild(node, returnValue);
            node->dataType = returnValue->dataType;
        } else {
            node->dataType = TYPE_VOID;
        }
    }
    return node;
}

ASTNode* createCallExprNode(const char *funcName, ASTNode **args,
                            int argCount, DataType returnType, int lineNumber) {
    ASTNode *node = allocateNode(NODE_CALL_EXPR, lineNumber);
    if (node) {
        node->name = strdup(funcName);
        node->dataType = returnType;
        if (argCount > 0 && args) {
            node->children = (ASTNode **)malloc(argCount * sizeof(ASTNode *));
            if (node->children) {
                node->childCapacity = argCount;
                node->childCount = argCount;
                for (int i = 0; i < argCount; i++) {
                    node->children[i] = args[i];
                }
            }
        }
    }
    return node;
}

ASTNode* createArrayAccessNode(ASTNode *array, ASTNode *index,
                               DataType elementType, int lineNumber) {
    ASTNode *node = allocateNode(NODE_ARRAY_ACCESS, lineNumber);
    if (node) {
        node->dataType = elementType;
        addChild(node, array);
        addChild(node, index);
    }
    return node;
}

ASTNode* createCompoundStmtNode(int lineNumber) {
    ASTNode *node = allocateNode(NODE_COMPOUND_STMT, lineNumber);
    if (node) {
        node->name = strdup("block");
    }
    return node;
}

ASTNode* createFunctionDeclNode(const char *funcName, DataType returnType,
                                ASTNode **params, int paramCount, int lineNumber) {
    ASTNode *node = allocateNode(NODE_FUNCTION_DECL, lineNumber);
    if (node) {
        node->name = strdup(funcName);
        node->returnType = returnType;
        node->dataType = returnType;
        node->paramCount = paramCount;

        if (paramCount > 0 && params) {
            node->params = (ASTNode **)malloc(paramCount * sizeof(ASTNode *));
            if (node->params) {
                for (int i = 0; i < paramCount; i++) {
                    node->params[i] = params[i];
                }
            }
        }
    }
    return node;
}

ASTNode* createErrorNode(const char *errorMessage, int lineNumber) {
    ASTNode *node = allocateNode(NODE_ERROR, lineNumber);
    if (node) {
        node->errorMessage = strdup(errorMessage);
        node->dataType = TYPE_ERROR;
    }
    return node;
}

ASTNode* createExprStmtNode(ASTNode *expr, int lineNumber) {
    ASTNode *node = allocateNode(NODE_EXPR_STMT, lineNumber);
    if (node) {
        if (expr) {
            addChild(node, expr);
            node->dataType = expr->dataType;
        }
    }
    return node;
}

ASTNode* createBreakStmtNode(int lineNumber) {
    ASTNode *node = allocateNode(NODE_BREAK_STMT, lineNumber);
    if (node) {
        node->name = strdup("break");
    }
    return node;
}

ASTNode* createContinueStmtNode(int lineNumber) {
    ASTNode *node = allocateNode(NODE_CONTINUE_STMT, lineNumber);
    if (node) {
        node->name = strdup("continue");
    }
    return node;
}

/* ═══════════════════════════════════════════════════════════════════════════
   NODE MANIPULATION
   ═══════════════════════════════════════════════════════════════════════════ */

void addChild(ASTNode *parent, ASTNode *child) {
    if (parent == NULL) return;

    if (parent->childCount >= parent->childCapacity) {
        int newCapacity = (parent->childCapacity == 0) ? 4 : parent->childCapacity * 2;
        ASTNode **newChildren = (ASTNode **)realloc(parent->children,
                                                     newCapacity * sizeof(ASTNode *));
        if (newChildren == NULL) {
            fprintf(stderr, "ERROR: Memory reallocation failed for children array\n");
            return;
        }
        parent->children = newChildren;
        parent->childCapacity = newCapacity;
    }

    parent->children[parent->childCount++] = child;
}

void setChild(ASTNode *parent, int index, ASTNode *child) {
    if (parent == NULL || index < 0 || index >= parent->childCapacity) {
        return;
    }

    /* Extend childCount if needed */
    if (index >= parent->childCount) {
        parent->childCount = index + 1;
    }

    parent->children[index] = child;
}

ASTNode* getChild(ASTNode *parent, int index) {
    if (parent == NULL || index < 0 || index >= parent->childCount) {
        return NULL;
    }
    return parent->children[index];
}

/* ═══════════════════════════════════════════════════════════════════════════
   AST PRINTING / PRETTY-PRINTER
   ═══════════════════════════════════════════════════════════════════════════ */

static void printIndent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}

static void printIndentToFile(int depth, FILE *file) {
    for (int i = 0; i < depth; i++) {
        fprintf(file, "  ");
    }
}

void printAST(ASTNode *node, int depth) {
    printASTToFile(node, depth, stdout);
}

void printASTToFile(ASTNode *node, int depth, FILE *file) {
    if (node == NULL) {
        return;
    }

    printIndentToFile(depth, file);

    /* Print node type */
    if (node->type == NODE_ERROR) {
        fprintf(file, "[ERROR] %s", nodeTypeToString(node->type));
    } else {
        fprintf(file, "%s", nodeTypeToString(node->type));
    }

    /* Print name if available */
    if (node->name != NULL) {
        fprintf(file, " | name=%s", node->name);
    }

    /* Print data type */
    if (node->dataType != TYPE_UNKNOWN) {
        fprintf(file, " | type=%s", dataTypeToString(node->dataType));
    }

    /* Print return type for function declarations */
    if (node->type == NODE_FUNCTION_DECL && node->returnType != TYPE_VOID) {
        fprintf(file, " | returnType=%s", dataTypeToString(node->returnType));
    }

    /* Print line number */
    fprintf(file, " | line=%d", node->lineNumber);

    /* Print scope level */
    if (node->scope != NULL) {
        fprintf(file, " | scope=%d", node->scope->scope_level);
    }

    /* Print initialization status for var declarations */
    if (node->type == NODE_VAR_DECL) {
        fprintf(file, " | initialized=%s", node->isInitialized ? "true" : "false");
    }

    /* Print error message */
    if (node->type == NODE_ERROR && node->errorMessage != NULL) {
        fprintf(file, "\n");
        printIndentToFile(depth + 1, file);
        fprintf(file, "Message: %s", node->errorMessage);
    }

    fprintf(file, "\n");

    /* Recursively print children */
    for (int i = 0; i < node->childCount; i++) {
        printASTToFile(node->children[i], depth + 1, file);
    }

    /* Print parameters for function declarations */
    if (node->type == NODE_FUNCTION_DECL && node->params != NULL) {
        printIndentToFile(depth + 1, file);
        fprintf(file, "Parameters:\n");
        for (int i = 0; i < node->paramCount; i++) {
            printASTToFile(node->params[i], depth + 2, file);
        }
    }
}

/* ═══════════════════════════════════════════════════════════════════════════
   MEMORY MANAGEMENT
   ═══════════════════════════════════════════════════════════════════════════ */

void freeNode(ASTNode *node) {
    if (node == NULL) return;

    if (node->name != NULL) {
        free(node->name);
    }

    if (node->errorMessage != NULL) {
        free(node->errorMessage);
    }

    if (node->children != NULL) {
        free(node->children);
    }

    if (node->params != NULL) {
        free(node->params);
    }

    free(node);
}

void freeAST(ASTNode *node) {
    if (node == NULL) return;

    /* Recursively free children */
    for (int i = 0; i < node->childCount; i++) {
        freeAST(node->children[i]);
    }

    /* Free parameters if function declaration */
    if (node->type == NODE_FUNCTION_DECL && node->params != NULL) {
        for (int i = 0; i < node->paramCount; i++) {
            freeAST(node->params[i]);
        }
    }

    /* Free the node itself */
    freeNode(node);
}

/* ═══════════════════════════════════════════════════════════════════════════
   UTILITY FUNCTIONS
   ═══════════════════════════════════════════════════════════════════════════ */

int countNodes(ASTNode *node) {
    if (node == NULL) return 0;

    int count = 1;  /* Count this node */

    /* Count children */
    for (int i = 0; i < node->childCount; i++) {
        count += countNodes(node->children[i]);
    }

    /* Count parameters if function declaration */
    if (node->type == NODE_FUNCTION_DECL && node->params != NULL) {
        for (int i = 0; i < node->paramCount; i++) {
            count += countNodes(node->params[i]);
        }
    }

    return count;
}

int getMaxDepth(ASTNode *node) {
    if (node == NULL) return 0;

    int maxChildDepth = 0;

    /* Get max depth from children */
    for (int i = 0; i < node->childCount; i++) {
        int childDepth = getMaxDepth(node->children[i]);
        if (childDepth > maxChildDepth) {
            maxChildDepth = childDepth;
        }
    }

    /* Get max depth from parameters if function declaration */
    if (node->type == NODE_FUNCTION_DECL && node->params != NULL) {
        for (int i = 0; i < node->paramCount; i++) {
            int paramDepth = getMaxDepth(node->params[i]);
            if (paramDepth > maxChildDepth) {
                maxChildDepth = paramDepth;
            }
        }
    }

    return 1 + maxChildDepth;
}

bool areTypesCompatible(DataType lhs, DataType rhs) {
    /* Exact match */
    if (lhs == rhs) return true;

    /* Unknown types are compatible with anything */
    if (lhs == TYPE_UNKNOWN || rhs == TYPE_UNKNOWN) return true;

    /* Error types are not compatible */
    if (lhs == TYPE_ERROR || rhs == TYPE_ERROR) return false;

    /* Implicit conversions */
    if ((lhs == TYPE_INT || lhs == TYPE_FLOAT) &&
        (rhs == TYPE_INT || rhs == TYPE_FLOAT)) {
        return true;
    }

    /* Pointers to different types may be compatible in some contexts */
    if (lhs == TYPE_POINTER && rhs == TYPE_POINTER) {
        return true;
    }

    return false;
}

DataType promoteTypes(DataType lhs, DataType rhs) {
    /* Error type propagates */
    if (lhs == TYPE_ERROR || rhs == TYPE_ERROR) {
        return TYPE_ERROR;
    }

    /* Unknown type doesn't promote */
    if (lhs == TYPE_UNKNOWN && rhs == TYPE_UNKNOWN) {
        return TYPE_UNKNOWN;
    }

    if (lhs == TYPE_UNKNOWN) return rhs;
    if (rhs == TYPE_UNKNOWN) return lhs;

    /* Float is higher precedence than int */
    if (lhs == TYPE_FLOAT || rhs == TYPE_FLOAT) {
        return TYPE_FLOAT;
    }

    /* Both ints */
    if (lhs == TYPE_INT && rhs == TYPE_INT) {
        return TYPE_INT;
    }

    /* Mixed types default to the explicit type */
    return lhs;
}
