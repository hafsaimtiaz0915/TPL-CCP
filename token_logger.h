#ifndef TOKEN_LOGGER_H
#define TOKEN_LOGGER_H

#include <stdio.h>

typedef struct {
    char token_type[64];
    char token_value[256];
    int line_num;
} Token;

typedef struct {
    Token *tokens;
    int token_count;
    int token_capacity;
} TokenLog;

/* Create token log */
TokenLog* create_token_log(void);

/* Destroy token log */
void destroy_token_log(TokenLog *log);

/* Add token to log */
void add_token(TokenLog *log, const char *type, const char *value, int line);

/* Print tokens */
void print_tokens(TokenLog *log);

/* Save tokens to file */
void save_tokens(TokenLog *log, const char *filename);

/* Global token log for lexer access */
extern TokenLog *global_token_log;

#endif
