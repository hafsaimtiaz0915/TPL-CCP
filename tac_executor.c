#include "tac_executor.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

ExecutionContext* create_exec_context(void) {
    ExecutionContext *ctx = (ExecutionContext*)malloc(sizeof(ExecutionContext));
    ctx->vars = (Variable*)malloc(sizeof(Variable) * 100);
    ctx->var_count = 0;
    ctx->var_capacity = 100;
    return ctx;
}

void destroy_exec_context(ExecutionContext *ctx) {
    if (ctx) {
        free(ctx->vars);
        free(ctx);
    }
}

Variable* get_variable(ExecutionContext *ctx, const char *name) {
    for (int i = 0; i < ctx->var_count; i++) {
        if (strcmp(ctx->vars[i].var_name, name) == 0) {
            return &ctx->vars[i];
        }
    }
    
    /* Create new variable */
    if (ctx->var_count >= ctx->var_capacity) {
        ctx->var_capacity *= 2;
        ctx->vars = (Variable*)realloc(ctx->vars, sizeof(Variable) * ctx->var_capacity);
    }
    
    Variable *new_var = &ctx->vars[ctx->var_count++];
    strcpy(new_var->var_name, name);
    new_var->value = 0;
    new_var->is_set = 0;
    return new_var;
}

void set_variable(ExecutionContext *ctx, const char *name, int64_t value) {
    Variable *var = get_variable(ctx, name);
    var->value = value;
    var->is_set = 1;
}

int64_t get_variable_value(ExecutionContext *ctx, const char *name) {
    Variable *var = get_variable(ctx, name);
    return var->value;
}

static int64_t evaluate_operand(ExecutionContext *ctx, const char *operand, 
                                int is_const, int64_t const_val) {
    if (operand == NULL || operand[0] == '\0') {
        return 0;
    }

    if (is_const) {
        return const_val;
    }

    /* Fallback: interpret numeric literal operands even if const flag is missing. */
    {
        const char *p = operand;
        if (*p == '+' || *p == '-') p++;
        if (*p != '\0') {
            int all_digits = 1;
            const char *q = p;
            while (*q) {
                if (!isdigit((unsigned char)*q)) {
                    all_digits = 0;
                    break;
                }
                q++;
            }
            if (all_digits) {
                return strtoll(operand, NULL, 10);
            }
        }
    }

    return get_variable_value(ctx, operand);
}

void execute_tac(CodeGenerator *code_gen, ExecutionContext *ctx) {
    /* Step 1: Build label map */
    int label_map_size = 0;
    for (int i = 0; i < code_gen->code_size; i++) {
        if (code_gen->code[i].op == TAC_LABEL) {
            label_map_size++;
        }
    }
    
    /* Create label to index mapping */
    char **label_to_name = (char **)malloc(label_map_size * sizeof(char *));
    int *label_to_index = (int *)malloc(label_map_size * sizeof(int));
    int label_count = 0;
    
    for (int i = 0; i < code_gen->code_size; i++) {
        if (code_gen->code[i].op == TAC_LABEL) {
            label_to_name[label_count] = code_gen->code[i].result;
            label_to_index[label_count] = i;
            label_count++;
        }
    }
    
    /* Step 2: Execute with instruction pointer */
    int ip = 0;  /* Instruction pointer */
    
    while (ip < code_gen->code_size) {
        TACInstruction *instr = &code_gen->code[ip];
        
        switch (instr->op) {
            case TAC_ASSIGN: {
                int64_t val = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                set_variable(ctx, instr->result, val);
                ip++;
                break;
            }
            
            case TAC_ASSIGN_CONST: {
                set_variable(ctx, instr->result, instr->const_val1);
                ip++;
                break;
            }
            
            case TAC_ADD: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 + v2);
                ip++;
                break;
            }
            
            case TAC_SUB: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 - v2);
                ip++;
                break;
            }
            
            case TAC_MUL: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 * v2);
                ip++;
                break;
            }
            
            case TAC_DIV: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                if (v2 != 0) {
                    set_variable(ctx, instr->result, v1 / v2);
                }
                ip++;
                break;
            }
            
            case TAC_MOD: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                if (v2 != 0) {
                    set_variable(ctx, instr->result, v1 % v2);
                }
                ip++;
                break;
            }
            
            case TAC_NEG: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                set_variable(ctx, instr->result, -v1);
                ip++;
                break;
            }
            
            case TAC_NOT: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                set_variable(ctx, instr->result, v1 == 0 ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_LABEL:
                /* Labels are no-ops at runtime; they're just markers */
                ip++;
                break;
            
            case TAC_GOTO: {
                /* Jump unconditionally to label */
                int target_ip = -1;
                for (int i = 0; i < label_count; i++) {
                    if (strcmp(label_to_name[i], instr->arg1) == 0) {
                        target_ip = label_to_index[i];
                        break;
                    }
                }
                if (target_ip >= 0) {
                    ip = target_ip;
                } else {
                    ip++;
                }
                break;
            }
            
            case TAC_IF_FALSE: {
                /* if (!cond) goto label */
                int64_t cond = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int target_ip = -1;
                for (int i = 0; i < label_count; i++) {
                    if (strcmp(label_to_name[i], instr->arg2) == 0) {
                        target_ip = label_to_index[i];
                        break;
                    }
                }
                if (cond == 0 && target_ip >= 0) {
                    ip = target_ip;
                } else {
                    ip++;
                }
                break;
            }
            
            case TAC_IF_TRUE: {
                /* if (cond) goto label */
                int64_t cond = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int target_ip = -1;
                for (int i = 0; i < label_count; i++) {
                    if (strcmp(label_to_name[i], instr->arg2) == 0) {
                        target_ip = label_to_index[i];
                        break;
                    }
                }
                if (cond != 0 && target_ip >= 0) {
                    ip = target_ip;
                } else {
                    ip++;
                }
                break;
            }
            
            case TAC_IFGOTO: {
                int64_t cond = evaluate_operand(ctx, instr->result, instr->arg1_is_const, instr->const_val1);
                int target_ip = -1;
                for (int i = 0; i < label_count; i++) {
                    if (strcmp(label_to_name[i], instr->arg1) == 0) {
                        target_ip = label_to_index[i];
                        break;
                    }
                }
                if (cond != 0 && target_ip >= 0) {
                    ip = target_ip;
                } else {
                    ip++;
                }
                break;
            }
            
            case TAC_IFNOT_GOTO: {
                int64_t cond = evaluate_operand(ctx, instr->result, instr->arg1_is_const, instr->const_val1);
                int target_ip = -1;
                for (int i = 0; i < label_count; i++) {
                    if (strcmp(label_to_name[i], instr->arg1) == 0) {
                        target_ip = label_to_index[i];
                        break;
                    }
                }
                if (cond == 0 && target_ip >= 0) {
                    ip = target_ip;
                } else {
                    ip++;
                }
                break;
            }
            
            case TAC_EQ: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 == v2 ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_NE: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 != v2 ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_LT: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 < v2 ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_LE: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 <= v2 ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_GT: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 > v2 ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_GE: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, v1 >= v2 ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_AND: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, (v1 != 0) && (v2 != 0) ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_OR: {
                int64_t v1 = evaluate_operand(ctx, instr->arg1, instr->arg1_is_const, instr->const_val1);
                int64_t v2 = evaluate_operand(ctx, instr->arg2, instr->arg2_is_const, instr->const_val2);
                set_variable(ctx, instr->result, (v1 != 0) || (v2 != 0) ? 1 : 0);
                ip++;
                break;
            }
            
            case TAC_RETURN:
            case TAC_HALT:
                ip = code_gen->code_size;  /* Exit loop */
                break;
            
            default:
                ip++;
                break;
        }
    }
    
    /* Cleanup */
    free(label_to_name);
    free(label_to_index);
}

void print_execution_results(ExecutionContext *ctx) {
    printf("\n[Variable States After Execution]\n");
    printf("==================================\n");
    printf("%-20s %-20s\n", "Variable", "Value");
    printf("==================================\n");
    
    for (int i = 0; i < ctx->var_count; i++) {
        if (ctx->vars[i].is_set) {
            printf("%-20s %-20lld\n", ctx->vars[i].var_name, ctx->vars[i].value);
        }
    }
    printf("==================================\n");
}
