#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"

/* IR Opcodes for Stack-Based VM */
typedef enum {
    /* Stack operations */
    PUSH_CONST,      /* Push constant value */
    PUSH_VAR,        /* Push variable value */
    POP_VAR,         /* Pop and store in variable */
    
    /* Arithmetic operations */
    OP_ADD,          /* Addition */
    OP_SUB,          /* Subtraction */
    OP_MUL,          /* Multiplication */
    OP_DIV,          /* Division */
    OP_MOD,          /* Modulo */
    OP_NEG,          /* Negation (unary minus) */
    
    /* Bitwise operations */
    OP_AND,          /* Bitwise AND */
    OP_OR,           /* Bitwise OR */
    OP_XOR,          /* Bitwise XOR */
    OP_NOT,          /* Bitwise NOT */
    OP_SHL,          /* Shift left */
    OP_SHR,          /* Shift right */
    
    /* Logical operations */
    OP_LOGIC_AND,    /* Logical AND */
    OP_LOGIC_OR,     /* Logical OR */
    OP_LOGIC_NOT,    /* Logical NOT */
    
    /* Comparison operations */
    OP_CMP_EQ,       /* Equal */
    OP_CMP_NE,       /* Not equal */
    OP_CMP_LT,       /* Less than */
    OP_CMP_LE,       /* Less than or equal */
    OP_CMP_GT,       /* Greater than */
    OP_CMP_GE,       /* Greater than or equal */
    
    /* Control flow */
    OP_JMP,          /* Unconditional jump */
    OP_JMP_FALSE,    /* Jump if false */
    OP_LABEL,        /* Label (no operation) */
    
    /* Functions */
    OP_CALL,         /* Function call */
    OP_RET,          /* Return from function */
    
    /* Memory operations */
    OP_LOAD_ARRAY,   /* Load array element */
    OP_STORE_ARRAY,  /* Store array element */
    
    /* Misc */
    OP_NOP,          /* No operation */
    OP_HALT,         /* Program halt */
    
    OP_INC,          /* Increment */
    OP_DEC,          /* Decrement */
} IROpcode;

/* IR Instruction */
typedef struct {
    IROpcode opcode;
    int arg;         /* Argument (value, symbol_id, label, etc.) */
    int line_num;    /* Source line for debugging */
} IRInstruction;

/* Code generator state */
typedef struct {
    IRInstruction *instructions;
    int instr_count;
    int instr_capacity;
    int label_counter;
    SymbolTable *sym_table;
} CodeGenerator;

/* Function declarations */

/* Code generator management */
CodeGenerator* create_code_generator(SymbolTable *st);
void destroy_code_generator(CodeGenerator *cg);

/* IR generation */
void emit_instruction(CodeGenerator *cg, IROpcode opcode, int arg, int line);
void emit_push_const(CodeGenerator *cg, int value, int line);
void emit_push_var(CodeGenerator *cg, const char *var_name, int line);
void emit_pop_var(CodeGenerator *cg, const char *var_name, int line);
void emit_arithmetic(CodeGenerator *cg, IROpcode op, int line);
void emit_comparison(CodeGenerator *cg, IROpcode op, int line);
void emit_label(CodeGenerator *cg, int label_id, int line);
void emit_jump(CodeGenerator *cg, int label_id, int line);
void emit_jump_false(CodeGenerator *cg, int label_id, int line);
int create_label(CodeGenerator *cg);

/* IR output */
void print_ir(CodeGenerator *cg);
void save_ir(CodeGenerator *cg, const char *filename);
const char* opcode_name(IROpcode opcode);

#endif // CODEGEN_H
