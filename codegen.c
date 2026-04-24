#include "codegen.h"

/* Create code generator */
CodeGenerator* create_code_generator(SymbolTable *st) {
    CodeGenerator *cg = (CodeGenerator *)malloc(sizeof(CodeGenerator));
    if (cg == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for code generator\n");
        return NULL;
    }
    
    cg->instr_capacity = 1000;
    cg->instructions = (IRInstruction *)malloc(cg->instr_capacity * sizeof(IRInstruction));
    if (cg->instructions == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for instructions\n");
        free(cg);
        return NULL;
    }
    
    cg->instr_count = 0;
    cg->label_counter = 0;
    cg->sym_table = st;
    
    return cg;
}

/* Destroy code generator */
void destroy_code_generator(CodeGenerator *cg) {
    if (cg != NULL) {
        if (cg->instructions != NULL) {
            free(cg->instructions);
        }
        free(cg);
    }
}

/* Emit a generic instruction */
void emit_instruction(CodeGenerator *cg, IROpcode opcode, int arg, int line) {
    if (cg == NULL) return;
    
    /* Expand capacity if needed */
    if (cg->instr_count >= cg->instr_capacity) {
        cg->instr_capacity *= 2;
        IRInstruction *new_instrs = (IRInstruction *)realloc(cg->instructions, 
                                                             cg->instr_capacity * sizeof(IRInstruction));
        if (new_instrs == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed for instructions\n");
            return;
        }
        cg->instructions = new_instrs;
    }
    
    cg->instructions[cg->instr_count].opcode = opcode;
    cg->instructions[cg->instr_count].arg = arg;
    cg->instructions[cg->instr_count].line_num = line;
    cg->instr_count++;
}

/* Emit push constant instruction */
void emit_push_const(CodeGenerator *cg, int value, int line) {
    emit_instruction(cg, PUSH_CONST, value, line);
}

/* Emit push variable instruction */
void emit_push_var(CodeGenerator *cg, const char *var_name, int line) {
    if (cg == NULL || var_name == NULL) return;
    
    /* Look up variable in symbol table */
    Symbol *sym = lookup_symbol(cg->sym_table, var_name);
    if (sym != NULL) {
        /* Use symbol index as argument */
        int sym_index = 0;
        for (int i = 0; i < cg->sym_table->count; i++) {
            if (strcmp(cg->sym_table->symbols[i].name, var_name) == 0) {
                sym_index = i;
                break;
            }
        }
        emit_instruction(cg, PUSH_VAR, sym_index, line);
    }
}

/* Emit pop to variable instruction */
void emit_pop_var(CodeGenerator *cg, const char *var_name, int line) {
    if (cg == NULL || var_name == NULL) return;
    
    /* Look up variable in symbol table */
    Symbol *sym = lookup_symbol(cg->sym_table, var_name);
    if (sym != NULL) {
        /* Use symbol index as argument */
        int sym_index = 0;
        for (int i = 0; i < cg->sym_table->count; i++) {
            if (strcmp(cg->sym_table->symbols[i].name, var_name) == 0) {
                sym_index = i;
                break;
            }
        }
        emit_instruction(cg, POP_VAR, sym_index, line);
    }
}

/* Emit arithmetic operation */
void emit_arithmetic(CodeGenerator *cg, IROpcode op, int line) {
    emit_instruction(cg, op, 0, line);
}

/* Emit comparison operation */
void emit_comparison(CodeGenerator *cg, IROpcode op, int line) {
    emit_instruction(cg, op, 0, line);
}

/* Emit label instruction */
void emit_label(CodeGenerator *cg, int label_id, int line) {
    emit_instruction(cg, OP_LABEL, label_id, line);
}

/* Emit unconditional jump */
void emit_jump(CodeGenerator *cg, int label_id, int line) {
    emit_instruction(cg, OP_JMP, label_id, line);
}

/* Emit conditional jump (jump if false) */
void emit_jump_false(CodeGenerator *cg, int label_id, int line) {
    emit_instruction(cg, OP_JMP_FALSE, label_id, line);
}

/* Create a new label */
int create_label(CodeGenerator *cg) {
    if (cg == NULL) return -1;
    return cg->label_counter++;
}

/* Get opcode name for printing */
const char* opcode_name(IROpcode opcode) {
    switch (opcode) {
        case PUSH_CONST:     return "PUSH_CONST";
        case PUSH_VAR:       return "PUSH_VAR";
        case POP_VAR:        return "POP_VAR";
        case OP_ADD:         return "ADD";
        case OP_SUB:         return "SUB";
        case OP_MUL:         return "MUL";
        case OP_DIV:         return "DIV";
        case OP_MOD:         return "MOD";
        case OP_NEG:         return "NEG";
        case OP_AND:         return "AND";
        case OP_OR:          return "OR";
        case OP_XOR:         return "XOR";
        case OP_NOT:         return "NOT";
        case OP_SHL:         return "SHL";
        case OP_SHR:         return "SHR";
        case OP_LOGIC_AND:   return "LOGIC_AND";
        case OP_LOGIC_OR:    return "LOGIC_OR";
        case OP_LOGIC_NOT:   return "LOGIC_NOT";
        case OP_CMP_EQ:      return "CMP_EQ";
        case OP_CMP_NE:      return "CMP_NE";
        case OP_CMP_LT:      return "CMP_LT";
        case OP_CMP_LE:      return "CMP_LE";
        case OP_CMP_GT:      return "CMP_GT";
        case OP_CMP_GE:      return "CMP_GE";
        case OP_JMP:         return "JMP";
        case OP_JMP_FALSE:   return "JMP_FALSE";
        case OP_LABEL:       return "LABEL";
        case OP_CALL:        return "CALL";
        case OP_RET:         return "RET";
        case OP_LOAD_ARRAY:  return "LOAD_ARRAY";
        case OP_STORE_ARRAY: return "STORE_ARRAY";
        case OP_NOP:         return "NOP";
        case OP_HALT:        return "HALT";
        case OP_INC:         return "INC";
        case OP_DEC:         return "DEC";
        default:             return "UNKNOWN";
    }
}

/* Print IR to stdout */
void print_ir(CodeGenerator *cg) {
    if (cg == NULL) return;
    
    printf("\n=== GENERATED IR CODE (Stack-Based VM) ===\n");
    printf("%-6s %-15s %-10s %-8s\n", "Addr", "Opcode", "Arg", "Line");
    printf("-------------------------------------------\n");
    
    for (int i = 0; i < cg->instr_count; i++) {
        IRInstruction *instr = &cg->instructions[i];
        printf("%-6d %-15s %-10d %-8d\n", 
               i, 
               opcode_name(instr->opcode), 
               instr->arg, 
               instr->line_num);
    }
    
    printf("-------------------------------------------\n");
    printf("Total Instructions: %d\n\n", cg->instr_count);
}

/* Save IR to file */
void save_ir(CodeGenerator *cg, const char *filename) {
    if (cg == NULL || filename == NULL) return;
    
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        fprintf(stderr, "Error: Cannot open file %s for writing\n", filename);
        return;
    }
    
    fprintf(f, "=== GENERATED IR CODE (Stack-Based VM) ===\n");
    fprintf(f, "%-6s %-15s %-10s %-8s\n", "Addr", "Opcode", "Arg", "Line");
    fprintf(f, "-------------------------------------------\n");
    
    for (int i = 0; i < cg->instr_count; i++) {
        IRInstruction *instr = &cg->instructions[i];
        fprintf(f, "%-6d %-15s %-10d %-8d\n", 
                i, 
                opcode_name(instr->opcode), 
                instr->arg, 
                instr->line_num);
    }
    
    fprintf(f, "-------------------------------------------\n");
    fprintf(f, "Total Instructions: %d\n", cg->instr_count);
    
    fclose(f);
}
