CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -g
LDFLAGS = -lm

# Targets
TARGETS = compiler

# Source files
PARSER_SOURCES = c_parser.y
LEXER_SOURCES = c_lexer.l
C_SOURCES = symbol_table.c codegen.c tac_executor.c token_logger.c main.c
GENERATED_SOURCES = lex.yy.c c_parser.tab.c

# Object files
OBJECTS = lex.yy.o c_parser.tab.o symbol_table.o codegen.o tac_executor.o token_logger.o main.o

# Default target
all: $(TARGETS)

# Build compiler
compiler: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✓ Compiler built successfully: $@"

# Generate parser from Bison definition (MUST RUN FIRST)
c_parser.tab.c c_parser.tab.h: $(PARSER_SOURCES)
	bison -d -o c_parser.tab.c $<
	@echo "✓ Parser generated: $@"

# Generate lexer from Flex definition (DEPENDS ON PARSER TOKENS)
lex.yy.c: $(LEXER_SOURCES) c_parser.tab.h
	flex -o $@ $(LEXER_SOURCES)
	@echo "✓ Lexer generated: $@"

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean generated files
clean:
	rm -f $(OBJECTS) lex.yy.c c_parser.tab.c c_parser.tab.h compiler
	@echo "✓ Clean complete"

# Run compiler on a test file
test: compiler
	@if [ -f test_valid_simple.c ]; then \
		echo "Running compiler on test_valid_simple.c..."; \
		./compiler test_valid_simple.c; \
	else \
		echo "Test file not found"; \
	fi

.PHONY: all clean test
