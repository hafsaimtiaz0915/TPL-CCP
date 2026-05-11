#ifndef TAC_EXECUTOR_H
#define TAC_EXECUTOR_H

#include "codegen.h"
#include <stdint.h>

typedef struct {
    char var_name[256];
    int64_t value;
    int is_set;
} Variable;

typedef struct {
    Variable *vars;
    int var_count;
    int var_capacity;
} ExecutionContext;

/* Create execution context */
ExecutionContext* create_exec_context(void);

/* Destroy execution context */
void destroy_exec_context(ExecutionContext *ctx);

/* Get or create variable */
Variable* get_variable(ExecutionContext *ctx, const char *name);

/* Set variable value */
void set_variable(ExecutionContext *ctx, const char *name, int64_t value);

/* Get variable value */
int64_t get_variable_value(ExecutionContext *ctx, const char *name);

/* Execute TAC code */
void execute_tac(CodeGenerator *code_gen, ExecutionContext *ctx);

/* Print execution output */
void print_execution_results(ExecutionContext *ctx);

#endif
