#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"

/* TAC (Three Address Code) - Complete replacement for stack IR */
typedef enum {
    /* Arithmetic */
    TAC_ADD,        /* a := b + c */
    TAC_SUB,        /* a := b - c */
    TAC_MUL,        /* a := b * c */
    TAC_DIV,        /* a := b / c */
    TAC_MOD,        /* a := b % c */
    
    /* Unary */
    TAC_NEG,        /* a := -b */
    TAC_NOT,        /* a := !b */
    
    /* Assignment */
    TAC_ASSIGN,     /* a := b */
    TAC_ASSIGN_CONST, /* a := constant */
    
    /* Comparison */
    TAC_EQ,         /* a := (b == c) */
    TAC_NE,         /* a := (b != c) */
    TAC_LT,         /* a := (b < c) */
    TAC_LE,         /* a := (b <= c) */
    TAC_GT,         /* a := (b > c) */
    TAC_GE,         /* a := (b >= c) */
    
    /* Logical */
    TAC_AND,        /* a := b && c */
    TAC_OR,         /* a := b || c */
    
    /* Array */
    TAC_ARRAY_LOAD, /* a := b[c] */
    TAC_ARRAY_STORE,/* a[b] := c */
    
    /* Jump & Control Flow */
    TAC_LABEL,      /* label: */
    TAC_GOTO,       /* goto label */
    TAC_IF_FALSE,   /* if (!cond) goto label */
    TAC_IF_TRUE,    /* if (cond) goto label */
    TAC_IFGOTO,     /* if (a) goto label (deprecated, use IF_TRUE) */
    TAC_IFNOT_GOTO, /* if (!a) goto label (deprecated, use IF_FALSE) */
    
    /* Function */
    TAC_PARAM,      /* param a */
    TAC_CALL,       /* a := call func */
    TAC_RETURN,     /* return a */
    TAC_FUNC_START, /* function_start func */
    TAC_FUNC_END,   /* function_end func */
    
    /* Control */
    TAC_NOP,
    TAC_HALT,
} TACOpcode;

/* TAC Instruction */
typedef struct {
    TACOpcode op;
    char result[256];       /* Result variable (a := ...) */
    char arg1[256];         /* First argument */
    char arg2[256];         /* Second argument */
    int arg1_is_const;      /* Is arg1 a constant? */
    int arg2_is_const;      /* Is arg2 a constant? */
    int const_val1;         /* Constant value if arg1_is_const */
    int const_val2;         /* Constant value if arg2_is_const */
    int line_num;           /* Source line for debugging */
} TACInstruction;

/* Code generator */
typedef struct {
    TACInstruction *code;
    int code_size;
    int code_capacity;
    int temp_counter;       /* For generating temporary variables */
    int label_counter;      /* For generating unique labels */
    SymbolTable *sym_table;
    /* Label mapping for VM execution */
    char **label_names;     /* Array of label names */
    int *label_indices;     /* Array of instruction indices for each label */
    int label_map_count;    /* Number of labels */
    int label_map_capacity; /* Capacity of label mapping arrays */
} CodeGenerator;

/* Function declarations */
CodeGenerator* create_code_generator(SymbolTable *st);
void destroy_code_generator(CodeGenerator *cg);

/* TAC generation */
void emit_tac(CodeGenerator *cg, TACOpcode op, 
              const char *result, const char *arg1, const char *arg2, 
              int arg1_is_const, int arg2_is_const, int line);
void emit_tac_const(CodeGenerator *cg, TACOpcode op,
                    const char *result, const char *arg1, int const_val,
                    int line);
void emit_tac_binary(CodeGenerator *cg, TACOpcode op, const char *result,
                     const char *left, const char *right, int line);
void emit_tac_unary(CodeGenerator *cg, TACOpcode op, const char *result,
                    const char *operand, int line);
void emit_tac_label(CodeGenerator *cg, int label_id, int line);
void emit_tac_goto(CodeGenerator *cg, int label_id, int line);
void emit_tac_ifgoto(CodeGenerator *cg, const char *cond, int label_id, int line);
void emit_tac_ifnot_goto(CodeGenerator *cg, const char *cond, int label_id, int line);

/* Emit if-false and if-true conditional jumps */
void emit_tac_if_false(CodeGenerator *cg, const char *cond, int label_id, int line);
void emit_tac_if_true(CodeGenerator *cg, const char *cond, int label_id, int line);

char* get_temp_var(CodeGenerator *cg);
int create_label(CodeGenerator *cg);

/* Output */
void print_tac(CodeGenerator *cg);
void save_tac(CodeGenerator *cg, const char *filename);
const char* tac_opcode_name(TACOpcode op);

#endif // CODEGEN_H
