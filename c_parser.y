%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "codegen.h"
#include "token_logger.h"

extern int yylex();
extern int line_num;
extern char* yytext;
extern FILE* yyin;

extern SymbolTable* sym_table;
extern CodeGenerator* code_gen;
extern TokenLog* global_token_log;
extern int semantic_error_count;

int in_loop = 0;
int in_function = 0;
int temp_counter = 0;
int label_counter = 0;
int loop_start_stack[100];  /* Stack for loop start labels */
int loop_end_stack[100];    /* Stack for loop end labels */
int loop_label_top = -1;    /* Stack pointer */
int if_else_stack[100];     /* Stack for if/else labels */
int if_end_stack[100];      /* Stack for if/else end labels */
int if_label_top = -1;      /* Stack pointer for if/else */

void yyerror(const char *s);

char* new_temp(void) {
    static char temp_name[20];
    sprintf(temp_name, "t%d", temp_counter++);
    return strdup(temp_name);
}

int new_label(void) {
    return code_gen->label_counter++;
}

void push_loop_labels(int start, int end) {
    if (loop_label_top < 99) {
        loop_label_top++;
        loop_start_stack[loop_label_top] = start;
        loop_end_stack[loop_label_top] = end;
    }
}

void pop_loop_labels(int *start, int *end) {
    if (loop_label_top >= 0) {
        *start = loop_start_stack[loop_label_top];
        *end = loop_end_stack[loop_label_top];
        loop_label_top--;
    }
}

int peek_loop_end(void) {
    if (loop_label_top >= 0) {
        return loop_end_stack[loop_label_top];
    }
    return -1;
}

void push_if_labels(int else_label, int end_label) {
    if (if_label_top < 99) {
        if_label_top++;
        if_else_stack[if_label_top] = else_label;
        if_end_stack[if_label_top] = end_label;
    }
}

void pop_if_labels(int *else_label, int *end_label) {
    if (if_label_top >= 0) {
        *else_label = if_else_stack[if_label_top];
        *end_label = if_end_stack[if_label_top];
        if_label_top--;
    }
}

%}

%union {
    int int_val;
    char* str_val;
}

%token INT FLOAT CHAR VOID
%token IF ELSE WHILE FOR DO SWITCH CASE DEFAULT
%token BREAK CONTINUE RETURN
%token <str_val> IDENTIFIER
%token <int_val> NUMBER
%token '+' '-' '*' '/' '%' '=' '<' '>' '!' '&' '|' '^' '~'
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token ';' ',' '{' '}' '(' ')' '[' ']'

/* Additional tokens for full C lexer compatibility */
%token AUTO CONST DOUBLE ENUM EXTERN GOTO LONG REGISTER SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOLATILE
%token <str_val> STRING_LITERAL
%token LEFT_OP RIGHT_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN PTR_OP

%type <str_val> type_specifier expression

%start program

/* Operator precedence and associativity */
%left '+' '-'
%left '*' '/' '%'
%right UNARY_MINUS

/* Dangling-ELSE resolution: LOWER_THAN_ELSE has lower precedence than ELSE
   This makes the parser prefer to SHIFT an ELSE token rather than REDUCE
   an if-statement without else, binding ELSE to the nearest unmatched IF */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program
    : /* empty */
    | program declaration
    ;

declaration
    : var_declaration
    | function_declaration
    ;

var_declaration
    : type_specifier IDENTIFIER ';' {
        if (insert_symbol(sym_table, $2, $1, line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Variable '%s' already declared\n", line_num, $2);
            semantic_error_count++;
        }
        free($1);
        free($2);
    }
    | type_specifier IDENTIFIER '=' expression ';' {
        Symbol *sym;
        if (insert_symbol(sym_table, $2, $1, line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Variable '%s' already declared\n", line_num, $2);
            semantic_error_count++;
        } else {
            sym = lookup_symbol_in_scope(sym_table, $2, sym_table->scope_level);
            if (sym) {
                sym->initialized = 1;
            }
        }
        /* Emit TAC for declaration-time initialization, e.g., int x = 5; */
        emit_tac_binary(code_gen, TAC_ASSIGN, $2, $4, NULL, line_num);
        free($1);
        free($2);
        free($4);
    }
    | type_specifier IDENTIFIER '[' NUMBER ']' ';' {
        if (insert_symbol(sym_table, $2, $1, line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Array '%s' already declared\n", line_num, $2);
            semantic_error_count++;
        }
        free($1);
        free($2);
    }
    ;

type_specifier
    : INT { $$ = strdup("int"); }
    | FLOAT { $$ = strdup("float"); }
    | CHAR { $$ = strdup("char"); }
    | VOID { $$ = strdup("void"); }
    ;

parameter_list
    : type_specifier IDENTIFIER {
        /* Add parameter to symbol table */
        insert_symbol(sym_table, $2, $1, line_num, 0);
        free($1);
        free($2);
    }
    | parameter_list ',' type_specifier IDENTIFIER {
        /* Add parameter to symbol table */
        insert_symbol(sym_table, $4, $3, line_num, 0);
        free($3);
        free($4);
    }
    ;

function_declaration
    : type_specifier IDENTIFIER '(' ')' '{' {
        if (insert_symbol(sym_table, $2, $1, line_num, 1) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Function '%s' already declared\n", line_num, $2);
            semantic_error_count++;
        }
        in_function = 1;
        enter_scope(sym_table);
        free($1);
        free($2);
    }
    statement_list '}' {
        exit_scope(sym_table);
        in_function = 0;
    }
    | type_specifier IDENTIFIER '(' parameter_list ')' '{' {
        if (insert_symbol(sym_table, $2, $1, line_num, 1) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Function '%s' already declared\n", line_num, $2);
            semantic_error_count++;
        }
        in_function = 1;
        enter_scope(sym_table);
        free($1);
        free($2);
    }
    statement_list '}' {
        exit_scope(sym_table);
        in_function = 0;
    }
    ;

statement_list
    : /* empty */
    | statement_list statement
    ;

statement
    : expression ';' {
        if ($1) free($1);
    }
    | var_declaration
    | '{' {
        enter_scope(sym_table);
    }
    statement_list '}' {
        exit_scope(sym_table);
    }
    | if_statement
    | while_statement
    | for_statement
    | BREAK ';' {
        if (!in_loop) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'break' statement not within a loop\n", line_num);
            semantic_error_count++;
        }
    }
    | CONTINUE ';' {
        if (!in_loop) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'continue' statement not within a loop\n", line_num);
            semantic_error_count++;
        }
    }
    | RETURN ';' {
        if (!in_function) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'return' statement outside function\n", line_num);
            semantic_error_count++;
        }
    }
    | RETURN expression ';' {
        if (!in_function) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'return' statement outside function\n", line_num);
            semantic_error_count++;
        }
        if ($2) free($2);
    }
    ;

/*
 * DANGLING-ELSE FIX (Standard Precedence Method)
 * 
 * The grammar has two productions for if statements:
 * 1. if_statement: IF '(' expr ')' statement
 * 2. if_statement: IF '(' expr ')' statement ELSE statement
 * 
 * Ambiguity: When parsing "if (c1) if (c2) s; else s2;"
 * Parser sees: [if (c1)] [if (c2) s] [else s2]
 * 
 * Decision: Reduce the inner if (production 1) or shift ELSE to bind it
 * to inner if?
 * 
 * Solution: Use %prec LOWER_THAN_ELSE on production 1.
 * This tells Bison: "When you see ELSE and can reduce using production 1,
 * SHIFT the ELSE instead because ELSE has higher precedence than
 * LOWER_THAN_ELSE."
 * 
 * Result: ELSE always binds to nearest IF, which is correct C semantics.
 */

if_prefix
    : IF '(' expression ')'
    {
        /* Emit condition check once; branch target is either else label or end label */
        int else_or_end_label = create_label(code_gen);
        emit_tac_if_false(code_gen, $3, else_or_end_label, line_num);
        push_if_labels(else_or_end_label, -1);
        free($3);
    }
    ;

if_statement
    : if_prefix statement %prec LOWER_THAN_ELSE
    {
        /* if (...) then_stmt;  -> place end label */
        int else_or_end_label, dummy;
        pop_if_labels(&else_or_end_label, &dummy);
        emit_tac_label(code_gen, else_or_end_label, line_num);
    }
    | if_prefix statement ELSE
    {
        /* if (...) then_stmt else ... -> jump over else, then place else label */
        int else_label, unused_end;
        int end_label = create_label(code_gen);
        pop_if_labels(&else_label, &unused_end);
        emit_tac_goto(code_gen, end_label, line_num);
        emit_tac_label(code_gen, else_label, line_num);
        push_if_labels(else_label, end_label);
    }
    statement
    {
        /* End of else branch */
        int unused_else, end_label;
        pop_if_labels(&unused_else, &end_label);
        emit_tac_label(code_gen, end_label, line_num);
    }
    ;

while_statement
    : WHILE '('
    {
        in_loop++;
        int start_label = create_label(code_gen);
        int end_label = create_label(code_gen);
        emit_tac_label(code_gen, start_label, line_num);
        push_loop_labels(start_label, end_label);
    }
    expression ')' 
    {
        /* After condition: emit IF_FALSE */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_if_false(code_gen, $4, end_label, line_num);
        push_loop_labels(start_label, end_label);
        free($4);
    }
    statement {
        /* After body: emit GOTO start and LABEL end */
        in_loop--;
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_goto(code_gen, start_label, line_num);
        emit_tac_label(code_gen, end_label, line_num);
    }
    ;

for_statement
    : FOR '(' expression ';'
    {
        int start_label = create_label(code_gen);
        int end_label = create_label(code_gen);
        emit_tac_label(code_gen, start_label, line_num);
        push_loop_labels(start_label, end_label);
        if ($3) free($3);
    }
    expression ';'
    {
        /* After condition: emit IF_FALSE */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_if_false(code_gen, $6, end_label, line_num);
        push_loop_labels(start_label, end_label);
        free($6);
    }
    expression ')'
    {
        /* Store update expression for later */
        if ($9) free($9);
    }
    statement {
        /* After body: emit GOTO start and LABEL end */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_goto(code_gen, start_label, line_num);
        emit_tac_label(code_gen, end_label, line_num);
    }
    ;

expression
    : IDENTIFIER {
        if (!lookup_symbol(sym_table, $1)) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Undeclared variable '%s'\n", line_num, $1);
            semantic_error_count++;
        }
        $$ = strdup($1);
        free($1);
    }
    | NUMBER {
        $$ = (char*)malloc(20);
        sprintf($$, "%d", $1);
    }
    | expression '+' expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_ADD, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression '-' expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_SUB, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression '*' expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_MUL, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression '/' expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_DIV, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression '%' expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_MOD, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression EQ_OP expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_EQ, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression NE_OP expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_NE, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression '<' expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_LT, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression '>' expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_GT, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression LE_OP expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_LE, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression GE_OP expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_GE, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression AND_OP expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_AND, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | expression OR_OP expression {
        $$ = new_temp();
        emit_tac_binary(code_gen, TAC_OR, $$, $1, $3, line_num);
        free($1);
        free($3);
    }
    | '-' expression %prec '*' {
        $$ = new_temp();
        emit_tac_unary(code_gen, TAC_NEG, $$, $2, line_num);
        free($2);
    }
    | '!' expression {
        $$ = new_temp();
        emit_tac_unary(code_gen, TAC_NOT, $$, $2, line_num);
        free($2);
    }
    | '(' expression ')' {
        $$ = $2;
    }
    | IDENTIFIER '=' expression {
        Symbol *sym = lookup_symbol(sym_table, $1);
        if (!sym) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Undeclared variable '%s'\n", line_num, $1);
            semantic_error_count++;
        } else {
            sym->initialized = 1;
        }
        emit_tac_binary(code_gen, TAC_ASSIGN, $1, $3, NULL, line_num);
        $$ = strdup($1);
        free($1);
        free($3);
    }
    ;

%%

