#include "token_logger.h"
#include <stdlib.h>
#include <string.h>

TokenLog *global_token_log = NULL;

TokenLog* create_token_log(void) {
    TokenLog *log = (TokenLog*)malloc(sizeof(TokenLog));
    log->tokens = (Token*)malloc(sizeof(Token) * 1000);
    log->token_count = 0;
    log->token_capacity = 1000;
    return log;
}

void destroy_token_log(TokenLog *log) {
    if (log) {
        free(log->tokens);
        free(log);
    }
}

void add_token(TokenLog *log, const char *type, const char *value, int line) {
    if (log->token_count >= log->token_capacity) {
        log->token_capacity *= 2;
        log->tokens = (Token*)realloc(log->tokens, sizeof(Token) * log->token_capacity);
    }
    
    Token *token = &log->tokens[log->token_count++];
    strncpy(token->token_type, type, 63);
    token->token_type[63] = '\0';
    strncpy(token->token_value, value, 255);
    token->token_value[255] = '\0';
    token->line_num = line;
}

void print_tokens(TokenLog *log) {
    printf("\n[Tokens - Lexical Analysis]\n");
    printf("==================================================\n");
    printf("%-15s %-35s %-10s\n", "Token Type", "Token Value", "Line");
    printf("==================================================\n");
    
    for (int i = 0; i < log->token_count; i++) {
        Token *t = &log->tokens[i];
        printf("%-15s %-35s %-10d\n", t->token_type, 
               strlen(t->token_value) > 32 ? "..." : t->token_value, 
               t->line_num);
    }
    printf("==================================================\n");
    printf("Total Tokens: %d\n", log->token_count);
}

void save_tokens(TokenLog *log, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) return;
    
    fprintf(file, "Token Analysis Output\n");
    fprintf(file, "=====================\n\n");
    fprintf(file, "%-15s %-35s %-10s\n", "Token Type", "Token Value", "Line");
    fprintf(file, "────────────────────────────────────────────────────────────────\n");
    
    for (int i = 0; i < log->token_count; i++) {
        Token *t = &log->tokens[i];
        fprintf(file, "%-15s %-35s %-10d\n", t->token_type, t->token_value, t->line_num);
    }
    
    fprintf(file, "\nTotal Tokens: %d\n", log->token_count);
    fclose(file);
}
