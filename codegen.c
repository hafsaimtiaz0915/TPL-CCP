#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Create code generator */
CodeGenerator* create_code_generator(SymbolTable *st) {
    CodeGenerator *cg = (CodeGenerator *)malloc(sizeof(CodeGenerator));
    if (cg == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for code generator\n");
        return NULL;
    }
    
    cg->code_capacity = 1000;
    cg->code = (TACInstruction *)malloc(cg->code_capacity * sizeof(TACInstruction));
    if (cg->code == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for TAC code\n");
        free(cg);
        return NULL;
    }
    
    cg->code_size = 0;
    cg->temp_counter = 0;
    cg->label_counter = 0;
    cg->sym_table = st;
    
    /* Initialize label mapping */
    cg->label_map_capacity = 50;
    cg->label_names = (char **)malloc(cg->label_map_capacity * sizeof(char *));
    cg->label_indices = (int *)malloc(cg->label_map_capacity * sizeof(int));
    cg->label_map_count = 0;
    
    return cg;
}

/* Destroy code generator */
void destroy_code_generator(CodeGenerator *cg) {
    if (cg != NULL) {
        if (cg->code != NULL) {
            free(cg->code);
        }
        if (cg->label_names != NULL) {
            for (int i = 0; i < cg->label_map_count; i++) {
                if (cg->label_names[i] != NULL) {
                    free(cg->label_names[i]);
                }
            }
            free(cg->label_names);
        }
        if (cg->label_indices != NULL) {
            free(cg->label_indices);
        }
        free(cg);
    }
}

/* Emit generic TAC instruction */
void emit_tac(CodeGenerator *cg, TACOpcode op, 
              const char *result, const char *arg1, const char *arg2, 
              int arg1_is_const, int arg2_is_const, int line) {
    if (cg == NULL) return;
    
    /* Expand capacity if needed */
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        TACInstruction *new_code = (TACInstruction *)realloc(cg->code, 
                                                              cg->code_capacity * sizeof(TACInstruction));
        if (new_code == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed for TAC code\n");
            return;
        }
        cg->code = new_code;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = op;
    instr->line_num = line;
    instr->arg1_is_const = arg1_is_const;
    instr->arg2_is_const = arg2_is_const;
    instr->const_val1 = 0;
    instr->const_val2 = 0;
    
    if (result) strncpy(instr->result, result, 255);
    else instr->result[0] = '\0';
    
    if (arg1) strncpy(instr->arg1, arg1, 255);
    else instr->arg1[0] = '\0';
    
    if (arg2) strncpy(instr->arg2, arg2, 255);
    else instr->arg2[0] = '\0';
}

/* Emit TAC with constant value */
void emit_tac_const(CodeGenerator *cg, TACOpcode op,
                    const char *result, const char *arg1, int const_val,
                    int line) {
    if (cg == NULL) return;
    
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        TACInstruction *new_code = (TACInstruction *)realloc(cg->code, 
                                                              cg->code_capacity * sizeof(TACInstruction));
        if (new_code == NULL) return;
        cg->code = new_code;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = op;
    instr->line_num = line;
    instr->arg1_is_const = 1;
    instr->arg2_is_const = 0;
    instr->const_val1 = const_val;
    instr->const_val2 = 0;
    
    if (result) strncpy(instr->result, result, 255);
    else instr->result[0] = '\0';
    
    if (arg1) strncpy(instr->arg1, arg1, 255);
    else instr->arg1[0] = '\0';
    
    instr->arg2[0] = '\0';
}

/* Check if string is a numeric constant */
static int is_numeric_constant(const char *str) {
    if (!str || *str == '\0') return 0;
    
    int i = 0;
    if (str[0] == '-' || str[0] == '+') i = 1;
    
    int has_digits = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            has_digits = 1;
        } else if (str[i] == '.') {
            continue;  /* Allow decimal point */
        } else {
            return 0;
        }
    }
    return has_digits;
}

/* Emit binary operation */
void emit_tac_binary(CodeGenerator *cg, TACOpcode op, const char *result,
                     const char *left, const char *right, int line) {
    if (cg == NULL) return;
    
    int left_is_const = is_numeric_constant(left);
    int right_is_const = is_numeric_constant(right);
    
    int64_t left_val = 0, right_val = 0;
    
    if (left_is_const && left) {
        left_val = atoll(left);
    }
    if (right_is_const && right) {
        right_val = atoll(right);
    }
    
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        TACInstruction *new_code = (TACInstruction *)realloc(cg->code, 
                                                              cg->code_capacity * sizeof(TACInstruction));
        if (new_code == NULL) return;
        cg->code = new_code;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = op;
    instr->line_num = line;
    instr->arg1_is_const = left_is_const;
    instr->arg2_is_const = right_is_const;
    instr->const_val1 = left_val;
    instr->const_val2 = right_val;
    
    if (result) strncpy(instr->result, result, 255);
    else instr->result[0] = '\0';
    
    if (left) strncpy(instr->arg1, left, 255);
    else instr->arg1[0] = '\0';
    
    if (right) strncpy(instr->arg2, right, 255);
    else instr->arg2[0] = '\0';
}

/* Emit unary operation */
void emit_tac_unary(CodeGenerator *cg, TACOpcode op, const char *result,
                    const char *operand, int line) {
    if (cg == NULL) return;

    int operand_is_const = is_numeric_constant(operand);
    int64_t operand_val = 0;
    if (operand_is_const && operand) {
        operand_val = atoll(operand);
    }

    emit_tac(cg, op, result, operand, NULL, operand_is_const, 0, line);
    if (operand_is_const && cg->code_size > 0) {
        cg->code[cg->code_size - 1].const_val1 = operand_val;
    }
}

/* Emit label */
void emit_tac_label(CodeGenerator *cg, int label_id, int line) {
    if (cg == NULL) return;
    
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        cg->code = (TACInstruction *)realloc(cg->code, cg->code_capacity * sizeof(TACInstruction));
        if (cg->code == NULL) return;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = TAC_LABEL;
    instr->line_num = line;
    sprintf(instr->result, "L%d", label_id);
    instr->arg1[0] = '\0';
    instr->arg2[0] = '\0';
}

/* Emit unconditional jump */
void emit_tac_goto(CodeGenerator *cg, int label_id, int line) {
    if (cg == NULL) return;
    
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        cg->code = (TACInstruction *)realloc(cg->code, cg->code_capacity * sizeof(TACInstruction));
        if (cg->code == NULL) return;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = TAC_GOTO;
    instr->line_num = line;
    instr->result[0] = '\0';
    sprintf(instr->arg1, "L%d", label_id);
    instr->arg2[0] = '\0';
}

/* Emit conditional jump */
void emit_tac_ifgoto(CodeGenerator *cg, const char *cond, int label_id, int line) {
    if (cg == NULL) return;
    
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        cg->code = (TACInstruction *)realloc(cg->code, cg->code_capacity * sizeof(TACInstruction));
        if (cg->code == NULL) return;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = TAC_IFGOTO;
    instr->line_num = line;
    if (cond) strncpy(instr->result, cond, 255);
    else instr->result[0] = '\0';
    sprintf(instr->arg1, "L%d", label_id);
    instr->arg2[0] = '\0';
}

/* Emit conditional jump (if not) */
void emit_tac_ifnot_goto(CodeGenerator *cg, const char *cond, int label_id, int line) {
    if (cg == NULL) return;
    
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        cg->code = (TACInstruction *)realloc(cg->code, cg->code_capacity * sizeof(TACInstruction));
        if (cg->code == NULL) return;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = TAC_IFNOT_GOTO;
    instr->line_num = line;
    if (cond) strncpy(instr->result, cond, 255);
    else instr->result[0] = '\0';
    sprintf(instr->arg1, "L%d", label_id);
    instr->arg2[0] = '\0';
}

/* Emit if-false conditional jump: if (!cond) goto label */
void emit_tac_if_false(CodeGenerator *cg, const char *cond, int label_id, int line) {
    if (cg == NULL) return;
    
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        cg->code = (TACInstruction *)realloc(cg->code, cg->code_capacity * sizeof(TACInstruction));
        if (cg->code == NULL) return;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = TAC_IF_FALSE;
    instr->line_num = line;
    instr->result[0] = '\0';
    if (cond) strncpy(instr->arg1, cond, 255);
    else instr->arg1[0] = '\0';
    sprintf(instr->arg2, "L%d", label_id);
}

/* Emit if-true conditional jump: if (cond) goto label */
void emit_tac_if_true(CodeGenerator *cg, const char *cond, int label_id, int line) {
    if (cg == NULL) return;
    
    if (cg->code_size >= cg->code_capacity) {
        cg->code_capacity *= 2;
        cg->code = (TACInstruction *)realloc(cg->code, cg->code_capacity * sizeof(TACInstruction));
        if (cg->code == NULL) return;
    }
    
    TACInstruction *instr = &cg->code[cg->code_size++];
    instr->op = TAC_IF_TRUE;
    instr->line_num = line;
    instr->result[0] = '\0';
    if (cond) strncpy(instr->arg1, cond, 255);
    else instr->arg1[0] = '\0';
    sprintf(instr->arg2, "L%d", label_id);
}

/* Generate temporary variable */
char* get_temp_var(CodeGenerator *cg) {
    static char temp_name[256];
    if (cg == NULL) return NULL;
    sprintf(temp_name, "t%d", cg->temp_counter++);
    return temp_name;
}

/* Create unique label */
int create_label(CodeGenerator *cg) {
    if (cg == NULL) return -1;
    return cg->label_counter++;
}

/* Get TAC opcode name */
const char* tac_opcode_name(TACOpcode op) {
    switch (op) {
        case TAC_ADD:        return "ADD";
        case TAC_SUB:        return "SUB";
        case TAC_MUL:        return "MUL";
        case TAC_DIV:        return "DIV";
        case TAC_MOD:        return "MOD";
        case TAC_NEG:        return "NEG";
        case TAC_NOT:        return "NOT";
        case TAC_ASSIGN:     return "ASSIGN";
        case TAC_ASSIGN_CONST: return "ASSIGN_CONST";
        case TAC_EQ:         return "EQ";
        case TAC_NE:         return "NE";
        case TAC_LT:         return "LT";
        case TAC_LE:         return "LE";
        case TAC_GT:         return "GT";
        case TAC_GE:         return "GE";
        case TAC_AND:        return "AND";
        case TAC_OR:         return "OR";
        case TAC_ARRAY_LOAD: return "ARRAY_LOAD";
        case TAC_ARRAY_STORE: return "ARRAY_STORE";
        case TAC_LABEL:      return "LABEL";
        case TAC_GOTO:       return "GOTO";
        case TAC_IF_FALSE:   return "IF_FALSE";
        case TAC_IF_TRUE:    return "IF_TRUE";
        case TAC_IFGOTO:     return "IFGOTO";
        case TAC_IFNOT_GOTO: return "IFNOT_GOTO";
        case TAC_PARAM:      return "PARAM";
        case TAC_CALL:       return "CALL";
        case TAC_RETURN:     return "RETURN";
        case TAC_FUNC_START: return "FUNC_START";
        case TAC_FUNC_END:   return "FUNC_END";
        case TAC_NOP:        return "NOP";
        case TAC_HALT:       return "HALT";
        default:             return "UNKNOWN";
    }
}

/* Print TAC to stdout */
void print_tac(CodeGenerator *cg) {
    if (cg == NULL) return;
    
    printf("\n=== GENERATED THREE ADDRESS CODE (TAC) ===\n");
    printf("%-4s %-15s %-15s %-15s %-15s %-8s\n", 
           "Seq", "Op", "Result", "Arg1", "Arg2", "Line");
    printf("================================================================================\n");
    
    for (int i = 0; i < cg->code_size; i++) {
        TACInstruction *instr = &cg->code[i];
        char arg1[30], arg2[30];
        
        if (instr->arg1_is_const) {
            sprintf(arg1, "%d", instr->const_val1);
        } else {
            strncpy(arg1, instr->arg1, 29);
        }
        
        if (instr->arg2_is_const) {
            sprintf(arg2, "%d", instr->const_val2);
        } else {
            strncpy(arg2, instr->arg2, 29);
        }
        
        printf("%-4d %-15s %-15s %-15s %-15s %-8d\n",
               i,
               tac_opcode_name(instr->op),
               instr->result,
               arg1,
               arg2,
               instr->line_num);
    }
    printf("================================================================================\n");
    printf("Total Instructions: %d\n\n", cg->code_size);
}

/* Save TAC to file */
void save_tac(CodeGenerator *cg, const char *filename) {
    if (cg == NULL || filename == NULL) return;
    
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        fprintf(stderr, "Error: Cannot open file %s for writing\n", filename);
        return;
    }
    
    fprintf(f, "=== GENERATED THREE ADDRESS CODE (TAC) ===\n");
    fprintf(f, "%-4s %-15s %-15s %-15s %-15s %-8s\n", 
            "Seq", "Op", "Result", "Arg1", "Arg2", "Line");
    fprintf(f, "================================================================================\n");
    
    for (int i = 0; i < cg->code_size; i++) {
        TACInstruction *instr = &cg->code[i];
        char arg1[30], arg2[30];
        
        if (instr->arg1_is_const) {
            sprintf(arg1, "%d", instr->const_val1);
        } else {
            strncpy(arg1, instr->arg1, 29);
        }
        
        if (instr->arg2_is_const) {
            sprintf(arg2, "%d", instr->const_val2);
        } else {
            strncpy(arg2, instr->arg2, 29);
        }
        
        fprintf(f, "%-4d %-15s %-15s %-15s %-15s %-8d\n",
                i,
                tac_opcode_name(instr->op),
                instr->result,
                arg1,
                arg2,
                instr->line_num);
    }
    fprintf(f, "================================================================================\n");
    fprintf(f, "Total Instructions: %d\n", cg->code_size);
    
    fclose(f);
    printf("[OK] TAC code saved to %s\n", filename);
}
