#include "symbol_table.h"
#include <stdarg.h>

/* Create a new symbol table */
SymbolTable* create_symbol_table() {
    SymbolTable *st = (SymbolTable *)malloc(sizeof(SymbolTable));
    if (st == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for symbol table\n");
        return NULL;
    }
    st->count = 0;
    st->scope_level = 0;
    return st;
}

/* Destroy symbol table */
void destroy_symbol_table(SymbolTable *st) {
    if (st != NULL) {
        free(st);
    }
}

/* Insert a new symbol into the table */
int insert_symbol(SymbolTable *st, const char *name, const char *type, 
                  int line, int is_function) {
    if (st == NULL || name == NULL || type == NULL) {
        return 0;
    }
    
    /* Check for redeclaration in current scope */
    for (int i = 0; i < st->count; i++) {
        if (st->symbols[i].scope_level == st->scope_level && 
            strcmp(st->symbols[i].name, name) == 0) {
            /* Redeclaration in same scope */
            return 0;
        }
    }
    
    /* Check array bounds */
    if (st->count >= 1000) {
        fprintf(stderr, "Error: Symbol table overflow\n");
        return 0;
    }
    
    /* Insert new symbol */
    Symbol *sym = &st->symbols[st->count++];
    strncpy(sym->name, name, 255);
    sym->name[255] = '\0';
    strncpy(sym->type, type, 31);
    sym->type[31] = '\0';
    sym->scope_level = st->scope_level;
    sym->line_declared = line;
    sym->initialized = 0;
    sym->is_function = is_function;
    sym->is_array = 0;
    sym->array_size = 0;
    sym->is_parameter = 0;
    sym->param_types[0] = '\0';
    sym->param_count = 0;
    
    return 1;
}

/* Lookup symbol by name (searches current and parent scopes) */
Symbol* lookup_symbol(SymbolTable *st, const char *name) {
    if (st == NULL || name == NULL) {
        return NULL;
    }
    
    /* Search from current scope to global scope */
    for (int scope = st->scope_level; scope >= 0; scope--) {
        for (int i = 0; i < st->count; i++) {
            if (st->symbols[i].scope_level == scope && 
                strcmp(st->symbols[i].name, name) == 0) {
                return &st->symbols[i];
            }
        }
    }
    
    return NULL;
}

/* Lookup symbol in specific scope only */
Symbol* lookup_symbol_in_scope(SymbolTable *st, const char *name, int scope) {
    if (st == NULL || name == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < st->count; i++) {
        if (st->symbols[i].scope_level == scope && 
            strcmp(st->symbols[i].name, name) == 0) {
            return &st->symbols[i];
        }
    }
    
    return NULL;
}

/* Enter a new scope (increase nesting level) */
void enter_scope(SymbolTable *st) {
    if (st != NULL) {
        st->scope_level++;
    }
}

/* Exit current scope (keep symbols for reporting, just decrease nesting) */
void exit_scope(SymbolTable *st) {
    if (st == NULL || st->scope_level == 0) {
        return;
    }
    
    /* Don't remove symbols - keep them for symbol table reporting */
    /* Just decrement scope level */
    st->scope_level--;
}

/* Print symbol table (for debugging) */
void print_symbol_table(SymbolTable *st) {
    if (st == NULL) return;
    
    printf("\n=== SYMBOL TABLE (Scope Level: %d) ===\n", st->scope_level);
    printf("%-20s %-15s %-10s %-8s %-12s\n", "Name", "Type", "Scope", "Line", "Initialized");
    printf("--------------------------------------------------------------------------\n");
    
    for (int i = 0; i < st->count; i++) {
        Symbol *sym = &st->symbols[i];
        printf("%-20s %-15s %-10d %-8d %-12s\n", 
               sym->name, 
               sym->type, 
               sym->scope_level, 
               sym->line_declared,
               sym->initialized ? "Yes" : "No");
        
        if (sym->is_function) {
            printf("  --> Function with %d parameter(s)\n", sym->param_count);
        }
        if (sym->is_array) {
            printf("  └─ Array[%d]\n", sym->array_size);
        }
    }
    printf("===========================================\n\n");
}

/* Create semantic analyzer */
SemanticAnalyzer* create_semantic_analyzer() {
    SemanticAnalyzer *sa = (SemanticAnalyzer *)malloc(sizeof(SemanticAnalyzer));
    if (sa == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for semantic analyzer\n");
        return NULL;
    }
    
    sa->sym_table = create_symbol_table();
    sa->error_count = 0;
    sa->warning_count = 0;
    sa->in_function = 0;
    sa->current_function_return[0] = '\0';
    sa->in_loop = 0;
    sa->in_switch = 0;
    
    return sa;
}

/* Destroy semantic analyzer */
void destroy_semantic_analyzer(SemanticAnalyzer *sa) {
    if (sa != NULL) {
        destroy_symbol_table(sa->sym_table);
        free(sa);
    }
}

/* Report semantic error */
void semantic_error(SemanticAnalyzer *sa, int line, const char *format, ...) {
    if (sa == NULL || format == NULL) return;
    
    va_list args;
    va_start(args, format);
    
    fprintf(stderr, "SEMANTIC ERROR at line %d: ", line);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    
    va_end(args);
    
    sa->error_count++;
}

/* Report semantic warning */
void semantic_warning(SemanticAnalyzer *sa, int line, const char *format, ...) {
    if (sa == NULL || format == NULL) return;
    
    va_list args;
    va_start(args, format);
    
    fprintf(stderr, "WARNING at line %d: ", line);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    
    va_end(args);
    
    sa->warning_count++;
}

/* Get error count */
int get_error_count(SemanticAnalyzer *sa) {
    return sa != NULL ? sa->error_count : 0;
}

/* Get warning count */
int get_warning_count(SemanticAnalyzer *sa) {
    return sa != NULL ? sa->warning_count : 0;
}

/* Stub for program analysis (to be expanded) */
void analyze_program(SemanticAnalyzer *sa) {
    if (sa == NULL) return;
    /* Analysis logic would be integrated during parsing */
}
