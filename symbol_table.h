#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Symbol table entry structure */
typedef struct {
    char name[256];          // Variable/function name
    char type[32];           // Type: "int", "float", "char", "void", etc.
    int scope_level;         // 0 = global, 1+ = nested blocks
    int line_declared;       // Source line number
    int initialized;         // 0 = uninitialized, 1 = initialized
    int is_function;         // 0 = variable, 1 = function
    int is_array;            // 0 = scalar, 1 = array
    int array_size;          // If is_array = 1
    int is_parameter;        // 0 = regular var, 1 = function parameter
    char param_types[1024];  // Function parameter types (comma-separated)
    int param_count;         // Number of parameters
} Symbol;

/* Symbol table structure */
typedef struct {
    Symbol symbols[1000];    // Max 1000 symbols per program
    int count;               // Current symbol count
    int scope_level;         // Current scope nesting level
} SymbolTable;

/* Semantic analyzer state */
typedef struct {
    SymbolTable *sym_table;
    int error_count;
    int warning_count;
    int in_function;         // 1 if currently in function body
    char current_function_return[32]; // Return type of current function
    int in_loop;             // Nesting level in loop (0 = not in loop)
    int in_switch;           // 1 if in switch statement
} SemanticAnalyzer;

/* Function declarations */

/* Symbol table management */
SymbolTable* create_symbol_table();
void destroy_symbol_table(SymbolTable *st);

/* Symbol operations */
int insert_symbol(SymbolTable *st, const char *name, const char *type, 
                  int line, int is_function);
Symbol* lookup_symbol(SymbolTable *st, const char *name);
Symbol* lookup_symbol_in_scope(SymbolTable *st, const char *name, int scope);

/* Scope management */
void enter_scope(SymbolTable *st);
void exit_scope(SymbolTable *st);
void print_symbol_table(SymbolTable *st);

/* Semantic analyzer */
SemanticAnalyzer* create_semantic_analyzer();
void destroy_semantic_analyzer(SemanticAnalyzer *sa);
void analyze_program(SemanticAnalyzer *sa);

/* Error and warning reporting */
void semantic_error(SemanticAnalyzer *sa, int line, const char *format, ...);
void semantic_warning(SemanticAnalyzer *sa, int line, const char *format, ...);
int get_error_count(SemanticAnalyzer *sa);
int get_warning_count(SemanticAnalyzer *sa);

#endif // SYMBOL_TABLE_H
