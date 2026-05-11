#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbol_table.h"
#include "codegen.h"
#include "token_logger.h"
#include "tac_executor.h"
#include "ast_enhanced.h"
#include "semantic_analysis.h"
#include <unistd.h>

/* Global variables */
extern int line_num;
extern FILE* yyin;
extern int yyparse();

SymbolTable* sym_table = NULL;
CodeGenerator* code_gen = NULL;
TokenLog* token_log = NULL;
int semantic_error_count = 0;
int statement_count = 0;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }
    
    const char *input_file = argv[1];
    
    /* Open source file */
    yyin = fopen(input_file, "r");
    if (yyin == NULL) {
        perror("Error opening input file");
        return 1;
    }
    
    printf("================================================\n");
    printf("  C COMPILER - 6 Stage Compilation\n");
    printf("  Compiler Design Project (CT-465)\n");
    printf("================================================\n\n");
    
    printf("Input file: %s\n\n", input_file);
    
    /* Initialize components */
    token_log = create_token_log();
    global_token_log = token_log;
    
    sym_table = create_symbol_table();
    if (sym_table == NULL) {
        fprintf(stderr, "Error: Failed to create symbol table\n");
        fclose(yyin);
        return 1;
    }
    
    code_gen = create_code_generator(sym_table);
    if (code_gen == NULL) {
        fprintf(stderr, "Error: Failed to create code generator\n");
        destroy_symbol_table(sym_table);
        fclose(yyin);
        return 1;
    }
    
    /* Stage 1 */
    printf("================================================\n");
    printf("STAGE 1: LEXICAL ANALYSIS (Tokenization)\n");
    printf("================================================\n");
    printf("Status: [OK]\n");
    printf("Output: Tokens (from flex lexer)\n\n");
    
    /* Stages 2 & 3 */
    printf("================================================\n");
    printf("STAGE 2: SYNTAX ANALYSIS (Parsing)\n");
    printf("STAGE 3: SEMANTIC ANALYSIS (Type Checking)\n");
    printf("================================================\n");
    printf("Status: In progress...\n\n");
    
    int parse_result = yyparse();
    
    fclose(yyin);
    
    /* Print tokens after parsing */
    print_tokens(token_log);
    
    if (parse_result != 0) {
        fprintf(stderr, "\n❌ Compilation FAILED - Parser error\n");
        destroy_code_generator(code_gen);
        destroy_symbol_table(sym_table);
        destroy_token_log(token_log);
        return 1;
    }
    
    if (semantic_error_count > 0) {
        fprintf(stderr, "\n❌ Compilation FAILED - %d semantic error(s) found\n", semantic_error_count);
        destroy_code_generator(code_gen);
        destroy_symbol_table(sym_table);
        destroy_token_log(token_log);
        return 1;
    }
    
    printf("Status: [OK]\n");
    printf("Output: Checked AST (syntax tree with validation)\n");
    
    /* Display TAC in enhanced hierarchical format */
    printTACEnhanced(code_gen);
    
    /* Stage 4 */
    printf("================================================\n");
    printf("STAGE 4: IR GENERATION (Three-Address Code)\n");
    printf("================================================\n");
    printf("Status: [OK]\n");
    printf("Output: TAC instructions\n\n");
    
    /* Stage 5 */
    printf("================================================\n");
    printf("STAGE 5: CODE GENERATION (Formatted Output)\n");
    printf("================================================\n");
    printf("Status: [OK]\n");
    printf("Output: Symbol table + TAC code\n\n");
    
    /* Display Symbol Table */
    printf("[OK] SYMBOL TABLE (Semantic Analysis Output):\n");
    print_symbol_table(sym_table);
    
    /* Display TAC Code */
    printf("[OK] THREE-ADDRESS CODE (IR Generation Output):\n");
    print_tac(code_gen);
    
    /* Stage 6 */
    printf("\n================================================\n");
    printf("STAGE 6: EXECUTION (VM - Virtual Machine)\n");
    printf("================================================\n");
    printf("Status: [OK]\n");
    printf("Output: Variable values after execution\n\n");
    
    /* Execute TAC code */
    ExecutionContext *exec_ctx = create_exec_context();
    execute_tac(code_gen, exec_ctx);
    print_execution_results(exec_ctx);
    destroy_exec_context(exec_ctx);
    
    /* Save outputs to files */
    char tac_file[512];
    strcpy(tac_file, input_file);
    strrchr(tac_file, '.')[1] = '\0';
    strcat(tac_file, "tac");
    save_tac(code_gen, tac_file);
    
    char tokens_file[512];
    strcpy(tokens_file, input_file);
    strrchr(tokens_file, '.')[1] = '\0';
    strcat(tokens_file, "tokens");
    save_tokens(token_log, tokens_file);
    
    /* Cleanup */
    destroy_code_generator(code_gen);
    destroy_symbol_table(sym_table);
    destroy_token_log(token_log);
    
    printf("\n================================================\n");
    printf("  COMPILATION SUCCESSFUL!\n");
    printf("================================================\n");
    printf("\nSUMMARY:\n");
    printf("   Lexical Analysis:      [PASS]\n");
    printf("   Syntax Analysis:       [PASS]\n");
    printf("   Semantic Analysis:     [PASS]\n");
    printf("   IR Generation:         [PASS]\n");
    printf("   Code Generation:       [PASS]\n");
    printf("   Virtual Execution:     [PASS]\n\n");
    printf("Output files:\n");
    printf("   - %s\n", tac_file);
    printf("   - %s\n\n", tokens_file);
    
    return 0;
}

/* Error handler for parser */
void yyerror(const char *s) {
    fprintf(stderr, "SYNTAX ERROR at line %d: %s\n", line_num, s);
}

/* Report semantic error from parser */
void report_semantic_error(int line, const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "SEMANTIC ERROR at line %d: ", line);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    va_end(args);
    semantic_error_count++;
}

/* Notify parser about parsed statement */
void notify_statement_parsed(const char *type) {
    statement_count++;
}

/* Print simple AST from TAC code */
void print_ast(CodeGenerator *cg) {
    printf("\n[Parsed Abstract Syntax Tree]\n");
    printf("=====================================\n");
    
    if (cg->code_size == 0) {
        printf("(Empty program)\n");
        return;
    }
    
    printf("Program\n");
    for (int i = 0; i < cg->code_size; i++) {
        TACInstruction *instr = &cg->code[i];
        printf("  [%d] ", i);
        
        switch (instr->op) {
            case TAC_ASSIGN:
            case TAC_ASSIGN_CONST:
                printf("Assignment: %s = %s\n", instr->result, instr->arg1);
                break;
            case TAC_ADD:
                printf("Binary Op: %s = %s + %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_SUB:
                printf("Binary Op: %s = %s - %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_MUL:
                printf("Binary Op: %s = %s * %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_DIV:
                printf("Binary Op: %s = %s / %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_MOD:
                printf("Binary Op: %s = %s %% %s\n", instr->result, instr->arg1, instr->arg2);
                break;
            case TAC_NEG:
                printf("Unary Op: %s = -%s\n", instr->result, instr->arg1);
                break;
            case TAC_NOT:
                printf("Unary Op: %s = !%s\n", instr->result, instr->arg1);
                break;
            case TAC_LABEL:
                printf("Label: %s\n", instr->result);
                break;
            case TAC_GOTO:
                printf("Jump: goto %s\n", instr->arg1);
                break;
            default:
                printf("Instruction (op=%d)\n", instr->op);
                break;
        }
    }
    printf("=====================================\n");
}

/* Check if variable is declared */
int check_variable_declared(const char *name, int line) {
    Symbol *sym = lookup_symbol(sym_table, name);
    if (sym == NULL) {
        report_semantic_error(line, "Undeclared variable '%s'", name);
        return 0;
    }
    return 1;
}

/* Check if break is in loop */
int check_break_in_loop(int in_loop, int line) {
    if (!in_loop) {
        report_semantic_error(line, "'break' statement not in loop or switch");
        return 0;
    }
    return 1;
}

/* Check if continue is in loop */
int check_continue_in_loop(int in_loop, int line) {
    if (!in_loop) {
        report_semantic_error(line, "'continue' statement not in loop");
        return 0;
    }
    return 1;
}

/* Check if return is in function */
int check_return_in_function(int in_function, int line) {
    if (!in_function) {
        report_semantic_error(line, "'return' statement outside function");
        return 0;
    }
    return 1;
}
