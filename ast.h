#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ═══════════════════════════════════════════════════════════════════════════
   1. NODE TYPE ENUM - Complete taxonomy of all C constructs
   ═══════════════════════════════════════════════════════════════════════════ */

typedef enum {
    /* Program structure */
    NODE_PROGRAM,
    NODE_FUNCTION_DECL,
    NODE_COMPOUND_STMT,

    /* Declarations and statements */
    NODE_VAR_DECL,
    NODE_ASSIGN_STMT,
    NODE_IF_STMT,
    NODE_WHILE_STMT,
    NODE_FOR_STMT,
    NODE_RETURN_STMT,
    NODE_EXPR_STMT,
    NODE_BREAK_STMT,
    NODE_CONTINUE_STMT,

    /* Expressions */
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_CALL_EXPR,
    NODE_IDENTIFIER,
    NODE_INT_LITERAL,
    NODE_FLOAT_LITERAL,
    NODE_STRING_LITERAL,
    NODE_ARRAY_ACCESS,

    /* Special */
    NODE_ERROR
} NodeType;

/* ═══════════════════════════════════════════════════════════════════════════
   2. DATA TYPE ENUM - Type system for expressions
   ═══════════════════════════════════════════════════════════════════════════ */

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_POINTER,
    TYPE_ARRAY,
    TYPE_UNKNOWN,
    TYPE_ERROR
} DataType;

/* ═══════════════════════════════════════════════════════════════════════════
   3. SCOPE STRUCTURE - Nested scopes for variable lookup
   ═══════════════════════════════════════════════════════════════════════════ */

typedef struct ASTNode ASTNode;

typedef struct Scope {
    struct Scope *parent_scope;      /* Link to parent scope for variable lookup */
    ASTNode *compound_stmt;          /* Pointer back to the compound statement that owns this scope */
    int scope_level;                 /* 0 = global, 1+ = nested */
} Scope;

/* ═══════════════════════════════════════════════════════════════════════════
   4. MAIN AST NODE STRUCTURE
   ═══════════════════════════════════════════════════════════════════════════ */

typedef struct ASTNode {
    /* Type and metadata */
    NodeType type;
    char *name;                      /* Identifier, operator symbol, or literal value */
    DataType dataType;               /* Type of expression or variable */
    int lineNumber;
    Scope *scope;                    /* Pointer to scope this node belongs to */

    /* Variable state */
    bool isInitialized;

    /* Children nodes */
    struct ASTNode **children;
    int childCount;
    int childCapacity;

    /* Function-specific fields */
    DataType returnType;             /* For NODE_FUNCTION_DECL */
    struct ASTNode **params;         /* For NODE_FUNCTION_DECL */
    int paramCount;

    /* Error handling */
    char *errorMessage;              /* For NODE_ERROR */

} ASTNode;

/* ═══════════════════════════════════════════════════════════════════════════
   5. AST NODE CREATION FUNCTIONS
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Creates a generic AST node with the given type
 */
ASTNode* createNode(NodeType type, int lineNumber);

/**
 * Creates an identifier node
 */
ASTNode* createIdentifierNode(const char *name, DataType type, int lineNumber);

/**
 * Creates a literal node (int, float, string)
 */
ASTNode* createIntLiteralNode(long value, int lineNumber);
ASTNode* createFloatLiteralNode(double value, int lineNumber);
ASTNode* createStringLiteralNode(const char *value, int lineNumber);

/**
 * Creates a binary operation node
 * left and right are expression nodes
 * op is operator string (e.g., "+", "-", "*", "/", "==", "<", etc.)
 * resultType is the result type after implicit promotion
 */
ASTNode* createBinaryOpNode(const char *op, ASTNode *left, ASTNode *right,
                            DataType resultType, int lineNumber);

/**
 * Creates a unary operation node
 * op is operator string (e.g., "-", "!", "&", "*", "+", "~")
 */
ASTNode* createUnaryOpNode(const char *op, ASTNode *operand,
                           DataType resultType, int lineNumber);

/**
 * Creates variable declaration node
 */
ASTNode* createVarDeclNode(const char *name, DataType type, int lineNumber);

/**
 * Creates assignment statement node
 * lhs must be NODE_IDENTIFIER or NODE_ARRAY_ACCESS
 * rhs is any expression node
 */
ASTNode* createAssignStmtNode(ASTNode *lhs, ASTNode *rhs, int lineNumber);

/**
 * Creates an if statement node
 * condition, thenBody, and elseBody are provided
 * elseBody can be NULL
 */
ASTNode* createIfStmtNode(ASTNode *condition, ASTNode *thenBody,
                          ASTNode *elseBody, int lineNumber);

/**
 * Creates a while loop node
 */
ASTNode* createWhileStmtNode(ASTNode *condition, ASTNode *body, int lineNumber);

/**
 * Creates a for loop node
 * init, condition, and update can each be NULL
 */
ASTNode* createForStmtNode(ASTNode *init, ASTNode *condition,
                           ASTNode *update, ASTNode *body, int lineNumber);

/**
 * Creates a return statement node
 * returnValue can be NULL for void return
 */
ASTNode* createReturnStmtNode(ASTNode *returnValue, int lineNumber);

/**
 * Creates a function call expression node
 * funcName is the function name
 * args is an array of argument expression nodes
 * argCount is the number of arguments
 */
ASTNode* createCallExprNode(const char *funcName, ASTNode **args,
                            int argCount, DataType returnType, int lineNumber);

/**
 * Creates an array access expression node
 * array is the array identifier node
 * index is the index expression node
 */
ASTNode* createArrayAccessNode(ASTNode *array, ASTNode *index,
                               DataType elementType, int lineNumber);

/**
 * Creates a compound statement (block) node
 */
ASTNode* createCompoundStmtNode(int lineNumber);

/**
 * Creates a function declaration node
 * returnType is the return type
 * funcName is the function name
 * params is an array of parameter declaration nodes (or NULL)
 * paramCount is the number of parameters
 */
ASTNode* createFunctionDeclNode(const char *funcName, DataType returnType,
                                ASTNode **params, int paramCount, int lineNumber);

/**
 * Creates a program node (root of AST)
 */
ASTNode* createProgramNode(void);

/**
 * Creates an error node
 * errorMessage describes what went wrong
 */
ASTNode* createErrorNode(const char *errorMessage, int lineNumber);

/**
 * Creates an expression statement node
 */
ASTNode* createExprStmtNode(ASTNode *expr, int lineNumber);

/**
 * Creates a break statement node
 */
ASTNode* createBreakStmtNode(int lineNumber);

/**
 * Creates a continue statement node
 */
ASTNode* createContinueStmtNode(int lineNumber);

/* ═══════════════════════════════════════════════════════════════════════════
   6. NODE MANIPULATION FUNCTIONS
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Adds a child node to a parent node
 * Dynamically resizes the children array as needed
 */
void addChild(ASTNode *parent, ASTNode *child);

/**
 * Sets a specific child by index
 * Used for control flow structures with fixed child positions
 */
void setChild(ASTNode *parent, int index, ASTNode *child);

/**
 * Gets a child by index
 */
ASTNode* getChild(ASTNode *parent, int index);

/* ═══════════════════════════════════════════════════════════════════════════
   7. SCOPE MANAGEMENT
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Creates a new scope with the given parent
 */
Scope* createScope(Scope *parentScope, int scopeLevel);

/**
 * Destroys a scope (does not destroy child AST nodes)
 */
void destroyScope(Scope *scope);

/* ═══════════════════════════════════════════════════════════════════════════
   8. AST PRINTING / PRETTY-PRINTER
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Pretty-prints the AST to stdout
 * Indents by depth, shows node type, name, type, line number, scope level
 * Marks error nodes visually
 */
void printAST(ASTNode *node, int depth);

/**
 * Pretty-prints the entire tree to a file
 */
void printASTToFile(ASTNode *node, int depth, FILE *file);

/**
 * Returns a string representation of NodeType
 */
const char* nodeTypeToString(NodeType type);

/**
 * Returns a string representation of DataType
 */
const char* dataTypeToString(DataType type);

/* ═══════════════════════════════════════════════════════════════════════════
   9. MEMORY MANAGEMENT
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Recursively frees an entire AST
 * Frees all children first, then the node itself
 * Handles NULL nodes safely
 */
void freeAST(ASTNode *node);

/**
 * Frees only the node (not its children)
 * Used internally by freeAST
 */
void freeNode(ASTNode *node);

/* ═══════════════════════════════════════════════════════════════════════════
   10. UTILITY FUNCTIONS
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Counts the total number of nodes in the AST
 */
int countNodes(ASTNode *node);

/**
 * Gets the maximum depth of the AST
 */
int getMaxDepth(ASTNode *node);

/**
 * Validates type compatibility between two types
 * Returns true if types are compatible
 */
bool areTypesCompatible(DataType lhs, DataType rhs);

/**
 * Performs implicit type promotion between two types
 * Returns the promoted type
 */
DataType promoteTypes(DataType lhs, DataType rhs);

#endif /* AST_H */
