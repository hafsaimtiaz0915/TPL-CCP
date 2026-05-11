/* ═══════════════════════════════════════════════════════════════════════════
   AST ENHANCED PRINTING HEADER
   
   Provides improved AST visualization with hierarchical tree display
   and comprehensive statistics.
   
   ═══════════════════════════════════════════════════════════════════════════ */

#ifndef AST_ENHANCED_H
#define AST_ENHANCED_H

#include "ast.h"
#include "codegen.h"
#include <stdio.h>

/**
 * Print AST with enhanced visual formatting to stdout
 * Shows hierarchical tree structure with meaningful node info
 */
void printASTEnhancedStdout(ASTNode *node);

/**
 * Print AST with enhanced visual formatting to file
 */
void printASTEnhancedToFile(ASTNode *node, FILE *file);

/**
 * Print AST statistics (node counts, structure analysis)
 */
void printASTStatistics(ASTNode *node);

/**
 * Enhanced TAC display for CodeGenerator (current compiler architecture)
 * Shows three-address code in hierarchical format with meaningful operations
 */
void printTACEnhanced(CodeGenerator *cg);

#endif /* AST_ENHANCED_H */
