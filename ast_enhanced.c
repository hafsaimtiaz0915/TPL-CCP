/* ═══════════════════════════════════════════════════════════════════════════
   ENHANCED AST PRETTY-PRINTER
   
   This is an improved version of the AST printing functionality that shows:
   - Clear hierarchical tree structure with visual indicators
   - Meaningful node information
   - Better formatting for readability
   - Context-aware details
   
   ═══════════════════════════════════════════════════════════════════════════ */

#include "ast.h"
#include "codegen.h"

#include <stdio.h>

/* ═══════════════════════════════════════════════════════════════════════════
   VISUAL TREE PRINTING UTILITIES
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Print tree branch structure (ASCII version for Windows compatibility)
 */
static void printTreeBranch(int depth, int isLast, FILE *file) {
    for (int i = 0; i < depth - 1; i++) {
        fprintf(file, "  | ");
    }
    if (depth > 0) {
        fprintf(file, isLast ? "  +- " : "  +- ");
    }
}

/**
 * Get a concise description of a node for inline display
 */
static const char* getNodeDescription(ASTNode *node) {
    if (!node) return "(null)";
    
    switch (node->type) {
        case NODE_PROGRAM:              return "Program";
        case NODE_FUNCTION_DECL:        return "Function";
        case NODE_COMPOUND_STMT:        return "Block";
        case NODE_VAR_DECL:             return "Declaration";
        case NODE_ASSIGN_STMT:          return "Assignment";
        case NODE_IF_STMT:              return "If Statement";
        case NODE_WHILE_STMT:           return "While Loop";
        case NODE_FOR_STMT:             return "For Loop";
        case NODE_RETURN_STMT:          return "Return";
        case NODE_EXPR_STMT:            return "Expression";
        case NODE_BREAK_STMT:           return "Break";
        case NODE_CONTINUE_STMT:        return "Continue";
        case NODE_BINARY_OP:            return "Binary Op";
        case NODE_UNARY_OP:             return "Unary Op";
        case NODE_CALL_EXPR:            return "Function Call";
        case NODE_IDENTIFIER:           return "Identifier";
        case NODE_INT_LITERAL:          return "Integer";
        case NODE_FLOAT_LITERAL:        return "Float";
        case NODE_STRING_LITERAL:       return "String";
        case NODE_ARRAY_ACCESS:         return "Array Access";
        case NODE_ERROR:                return "ERROR";
        default:                        return "Unknown";
    }
}

/* ═══════════════════════════════════════════════════════════════════════════
   ENHANCED PRETTY-PRINTER (IMPROVED FORMAT)
   ═══════════════════════════════════════════════════════════════════════════ */

void printASTEnhanced(ASTNode *node, int depth, FILE *file) {
    if (node == NULL) {
        return;
    }
    
    int isLeaf = (node->childCount == 0 && 
                  (node->type != NODE_FUNCTION_DECL || node->paramCount == 0));
    
    /* Print tree structure and node type */
    printTreeBranch(depth, isLeaf, file);
    
    /* Color-code node types */
    if (node->type == NODE_ERROR) {
        fprintf(file, "[ERROR] ");
    }
    
    fprintf(file, "%s", getNodeDescription(node));
    
    /* Print meaningful details based on node type */
    switch (node->type) {
        case NODE_FUNCTION_DECL:
            fprintf(file, " \"%s\" returns %s", 
                    node->name ? node->name : "???",
                    dataTypeToString(node->returnType));
            break;
            
        case NODE_VAR_DECL:
            fprintf(file, " \"%s\" : %s", 
                    node->name ? node->name : "???",
                    dataTypeToString(node->dataType));
            if (node->isInitialized) {
                fprintf(file, " (initialized)");
            }
            break;
            
        case NODE_IDENTIFIER:
            fprintf(file, " \"%s\" : %s", 
                    node->name ? node->name : "???",
                    dataTypeToString(node->dataType));
            break;
            
        case NODE_INT_LITERAL:
            fprintf(file, " %s : %s", 
                    node->name ? node->name : "0",
                    dataTypeToString(node->dataType));
            break;
            
        case NODE_FLOAT_LITERAL:
            fprintf(file, " %s : %s", 
                    node->name ? node->name : "0.0",
                    dataTypeToString(node->dataType));
            break;
            
        case NODE_STRING_LITERAL:
            fprintf(file, " \"%s\"", 
                    node->name ? node->name : "");
            break;
            
        case NODE_BINARY_OP:
            fprintf(file, " %s : %s", 
                    node->name ? node->name : "?",
                    dataTypeToString(node->dataType));
            break;
            
        case NODE_UNARY_OP:
            fprintf(file, " %s : %s", 
                    node->name ? node->name : "?",
                    dataTypeToString(node->dataType));
            break;
            
        case NODE_CALL_EXPR:
            fprintf(file, " %s() returns %s", 
                    node->name ? node->name : "???",
                    dataTypeToString(node->returnType));
            break;
            
        case NODE_ASSIGN_STMT:
            fprintf(file, " (assigns to %s)", 
                    (node->childCount > 0 && node->children[0]) ? 
                    node->children[0]->name : "???");
            break;
            
        case NODE_IF_STMT:
            fprintf(file, " (if-else)");
            break;
            
        case NODE_WHILE_STMT:
            fprintf(file, " (while loop)");
            break;
            
        case NODE_FOR_STMT:
            fprintf(file, " (for loop)");
            break;
            
        case NODE_RETURN_STMT:
            fprintf(file, " (returns %s)", 
                    dataTypeToString(node->dataType));
            break;
            
        case NODE_ARRAY_ACCESS:
            fprintf(file, " (array[index] : %s)", 
                    dataTypeToString(node->dataType));
            break;
            
        default:
            break;
    }
    
    /* Print line number and scope info */
    fprintf(file, " @ line %d", node->lineNumber);
    if (node->scope && node->scope->scope_level > 0) {
        fprintf(file, " [scope %d]", node->scope->scope_level);
    }
    
    /* Print error message if present */
    if (node->type == NODE_ERROR && node->errorMessage) {
        fprintf(file, "\n");
        printTreeBranch(depth + 1, 1, file);
        fprintf(file, "Error: %s\n", node->errorMessage);
        return;
    }
    
    fprintf(file, "\n");
    
    /* Print parameters for function declarations */
    if (node->type == NODE_FUNCTION_DECL && node->params != NULL && node->paramCount > 0) {
        printTreeBranch(depth + 1, node->childCount == 0, file);
        fprintf(file, "Parameters:\n");
        for (int i = 0; i < node->paramCount; i++) {
            printASTEnhanced(node->params[i], depth + 2, file);
        }
    }
    
    /* Recursively print children */
    for (int i = 0; i < node->childCount; i++) {
        int isLastChild = (i == node->childCount - 1);
        if (node->params && node->paramCount > 0) {
            isLastChild = 0;  /* Force more branches if there are params after */
        }
        printASTEnhanced(node->children[i], depth + 1, file);
    }
}

/**
 * Main entry point for enhanced printing to stdout
 */
void printASTEnhancedStdout(ASTNode *node) {
    if (node == NULL) {
        printf("(Empty AST)\n");
        return;
    }
    
    printf("\n+==================================================+\n");
    printf("|       ABSTRACT SYNTAX TREE (Enhanced View)        |\n");
    printf("+==================================================+\n\n");
    
    printASTEnhanced(node, 0, stdout);
    
    printf("\n+==================================================+\n");
}

/**
 * Print to file
 */
void printASTEnhancedToFile(ASTNode *node, FILE *file) {
    if (node == NULL) {
        fprintf(file, "(Empty AST)\n");
        return;
    }
    
    fprintf(file, "\n+==================================================+\n");
    fprintf(file, "|       ABSTRACT SYNTAX TREE (Enhanced View)        |\n");
    fprintf(file, "+==================================================+\n\n");
    
    printASTEnhanced(node, 0, file);
    
    fprintf(file, "\n+==================================================+\n");
}

/* ═══════════════════════════════════════════════════════════════════════════
   AST STATISTICS FUNCTIONS
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Count nodes by type
 */
typedef struct {
    int totalNodes;
    int functionDecls;
    int varDecls;
    int assignments;
    int controlStructures;
    int expressions;
    int literals;
    int errorNodes;
} ASTStatistics;

void countNodesByType(ASTNode *node, ASTStatistics *stats) {
    if (node == NULL) return;
    
    stats->totalNodes++;
    
    switch (node->type) {
        case NODE_FUNCTION_DECL:  stats->functionDecls++; break;
        case NODE_VAR_DECL:       stats->varDecls++; break;
        case NODE_ASSIGN_STMT:    stats->assignments++; break;
        case NODE_IF_STMT:
        case NODE_WHILE_STMT:
        case NODE_FOR_STMT:
        case NODE_BREAK_STMT:
        case NODE_CONTINUE_STMT:
            stats->controlStructures++;
            break;
        case NODE_BINARY_OP:
        case NODE_UNARY_OP:
        case NODE_CALL_EXPR:
        case NODE_ARRAY_ACCESS:
            stats->expressions++;
            break;
        case NODE_INT_LITERAL:
        case NODE_FLOAT_LITERAL:
        case NODE_STRING_LITERAL:
            stats->literals++;
            break;
        case NODE_ERROR:          stats->errorNodes++; break;
        default:                  break;
    }
    
    for (int i = 0; i < node->childCount; i++) {
        countNodesByType(node->children[i], stats);
    }
    
    if (node->type == NODE_FUNCTION_DECL) {
        for (int i = 0; i < node->paramCount; i++) {
            countNodesByType(node->params[i], stats);
        }
    }
}

/**
 * Print AST statistics
 */
void printASTStatistics(ASTNode *node) {
    ASTStatistics stats = {0};
    countNodesByType(node, &stats);
    
    printf("\n+==================================================+\n");
    printf("|              AST STATISTICS                        |\n");
    printf("+==================================================+\n\n");
    
    printf("  Total Nodes:            %d\n", stats.totalNodes);
    printf("  Function Declarations:  %d\n", stats.functionDecls);
    printf("  Variable Declarations:  %d\n", stats.varDecls);
    printf("  Assignments:            %d\n", stats.assignments);
    printf("  Control Structures:     %d\n", stats.controlStructures);
    printf("  Expressions:            %d\n", stats.expressions);
    printf("  Literals:               %d\n", stats.literals);
    
    if (stats.errorNodes > 0) {
        printf("  [ERROR] ERROR NODES:    %d\n", stats.errorNodes);
    }
    
    printf("\n");
}

/* ═══════════════════════════════════════════════════════════════════════════
   TAC-BASED AST DISPLAY (For CodeGenerator compatibility)
   ═══════════════════════════════════════════════════════════════════════════ */

/**
 * Display TAC instructions in enhanced hierarchical format
 * This is a CodeGenerator-compatible version for current compiler architecture
 */
void printTACEnhanced(CodeGenerator *cg) {
    if (!cg || cg->code_size == 0) {
        printf("(Empty program)\n");
        return;
    }
    
    printf("\n+==================================================+\n");
    printf("|    INTERMEDIATE REPRESENTATION (Hierarchical)     |\n");
    printf("+==================================================+\n\n");
    
    printf("Program Structure:\n");
    
    int depth = 1;
    printf("  +- Main Execution Block\n");
    
    for (int i = 0; i < cg->code_size; i++) {
        TACInstruction *instr = &cg->code[i];
        printf("     | [%2d] ", i);
        
        switch (instr->op) {
            case TAC_ASSIGN:
            case TAC_ASSIGN_CONST:
                printf("ASSIGN: %s = %s\n", instr->result, instr->arg1);
                break;
            case TAC_ADD:
                printf("ADD: %s = %s + %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_SUB:
                printf("SUB: %s = %s - %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_MUL:
                printf("MUL: %s = %s * %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_DIV:
                printf("DIV: %s = %s / %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_MOD:
                printf("MOD: %s = %s %% %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_LT:
                printf("LT: %s = %s < %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_GT:
                printf("GT: %s = %s > %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_EQ:
                printf("EQ: %s = %s == %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_NE:
                printf("NE: %s = %s != %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_LE:
                printf("LE: %s = %s <= %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_GE:
                printf("GE: %s = %s >= %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_LABEL:
                printf("+-LABEL: %s\n", instr->result);
                break;
            case TAC_GOTO:
                printf("+-GOTO: %s\n", instr->result);
                break;
            case TAC_IF_FALSE:
                printf("+-IF_FALSE: %s -> %s\n", instr->arg1, instr->result);
                break;
            case TAC_IF_TRUE:
                printf("+-IF_TRUE: %s -> %s\n", instr->arg1, instr->result);
                break;
            case TAC_CALL:
                printf("CALL: %s = %s(...)\n", instr->result, instr->arg1);
                break;
            case TAC_RETURN:
                printf("RETURN: %s\n", instr->arg1 ? instr->arg1 : "(void)");
                break;
            case TAC_PARAM:
                printf("PARAM: %s\n", instr->arg1);
                break;
            case TAC_ARRAY_LOAD:
                printf("ARRAY_LOAD: %s = %s[%s]\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_ARRAY_STORE:
                printf("ARRAY_STORE: %s[%s] = %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            default:
                printf("UNKNOWN OP (%d)\n", instr->op);
                break;
        }
    }
    
    printf("     +- End Block\n\n");
}
