
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "c_parser.y"

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



/* Line 189 of yacc.c  */
#line 156 "c_parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     CHAR = 260,
     VOID = 261,
     IF = 262,
     ELSE = 263,
     WHILE = 264,
     FOR = 265,
     DO = 266,
     SWITCH = 267,
     CASE = 268,
     DEFAULT = 269,
     BREAK = 270,
     CONTINUE = 271,
     RETURN = 272,
     IDENTIFIER = 273,
     NUMBER = 274,
     INC_OP = 275,
     DEC_OP = 276,
     LE_OP = 277,
     GE_OP = 278,
     EQ_OP = 279,
     NE_OP = 280,
     AND_OP = 281,
     OR_OP = 282,
     AUTO = 283,
     CONST = 284,
     DOUBLE = 285,
     ENUM = 286,
     EXTERN = 287,
     GOTO = 288,
     LONG = 289,
     REGISTER = 290,
     SHORT = 291,
     SIGNED = 292,
     SIZEOF = 293,
     STATIC = 294,
     STRUCT = 295,
     TYPEDEF = 296,
     UNION = 297,
     UNSIGNED = 298,
     VOLATILE = 299,
     STRING_LITERAL = 300,
     LEFT_OP = 301,
     RIGHT_OP = 302,
     MUL_ASSIGN = 303,
     DIV_ASSIGN = 304,
     MOD_ASSIGN = 305,
     ADD_ASSIGN = 306,
     SUB_ASSIGN = 307,
     LEFT_ASSIGN = 308,
     RIGHT_ASSIGN = 309,
     AND_ASSIGN = 310,
     XOR_ASSIGN = 311,
     OR_ASSIGN = 312,
     PTR_OP = 313,
     UNARY_MINUS = 314,
     LOWER_THAN_ELSE = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 83 "c_parser.y"

    int int_val;
    char* str_val;



/* Line 214 of yacc.c  */
#line 259 "c_parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 271 "c_parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,     2,     2,    24,    29,     2,
      45,    46,    22,    20,    42,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      26,    25,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    30,    44,    32,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    33,    34,    35,    36,    37,
      38,    39,    40,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    15,    21,    28,
      30,    32,    34,    36,    39,    44,    45,    54,    55,    65,
      66,    69,    72,    74,    75,    80,    82,    84,    86,    89,
      92,    95,    99,   104,   107,   108,   114,   115,   116,   124,
     125,   126,   127,   140,   142,   144,   148,   152,   156,   160,
     164,   168,   172,   176,   180,   184,   188,   192,   196,   199,
     202,   206
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      83,     0,    -1,    -1,    83,    84,    -1,    85,    -1,    88,
      -1,    86,    18,    41,    -1,    86,    18,    25,   104,    41,
      -1,    86,    18,    47,    19,    48,    41,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,    86,    18,    -1,    87,
      42,    86,    18,    -1,    -1,    86,    18,    45,    46,    43,
      89,    91,    44,    -1,    -1,    86,    18,    45,    87,    46,
      43,    90,    91,    44,    -1,    -1,    91,    92,    -1,   104,
      41,    -1,    85,    -1,    -1,    43,    93,    91,    44,    -1,
      95,    -1,    97,    -1,   100,    -1,    15,    41,    -1,    16,
      41,    -1,    17,    41,    -1,    17,   104,    41,    -1,     7,
      45,   104,    46,    -1,    94,    92,    -1,    -1,    94,    92,
       8,    96,    92,    -1,    -1,    -1,     9,    45,    98,   104,
      46,    99,    92,    -1,    -1,    -1,    -1,    10,    45,   104,
      41,   101,   104,    41,   102,   104,    46,   103,    92,    -1,
      18,    -1,    19,    -1,   104,    20,   104,    -1,   104,    21,
     104,    -1,   104,    22,   104,    -1,   104,    23,   104,    -1,
     104,    24,   104,    -1,   104,    37,   104,    -1,   104,    38,
     104,    -1,   104,    26,   104,    -1,   104,    27,   104,    -1,
     104,    35,   104,    -1,   104,    36,   104,    -1,   104,    39,
     104,    -1,   104,    40,   104,    -1,    21,   104,    -1,    28,
     104,    -1,    45,   104,    46,    -1,    18,    25,   104,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   122,   126,   127,   131,   139,   156,   167,
     168,   169,   170,   174,   180,   189,   189,   203,   203,   219,
     221,   225,   228,   229,   229,   235,   236,   237,   238,   244,
     250,   256,   287,   298,   306,   305,   326,   334,   325,   354,
     362,   371,   353,   385,   393,   397,   403,   409,   415,   421,
     427,   433,   439,   445,   451,   457,   463,   469,   475,   480,
     485,   488
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "VOID", "IF",
  "ELSE", "WHILE", "FOR", "DO", "SWITCH", "CASE", "DEFAULT", "BREAK",
  "CONTINUE", "RETURN", "IDENTIFIER", "NUMBER", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'='", "'<'", "'>'", "'!'", "'&'", "'|'", "'^'", "'~'", "INC_OP",
  "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "';'",
  "','", "'{'", "'}'", "'('", "')'", "'['", "']'", "AUTO", "CONST",
  "DOUBLE", "ENUM", "EXTERN", "GOTO", "LONG", "REGISTER", "SHORT",
  "SIGNED", "SIZEOF", "STATIC", "STRUCT", "TYPEDEF", "UNION", "UNSIGNED",
  "VOLATILE", "STRING_LITERAL", "LEFT_OP", "RIGHT_OP", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "PTR_OP",
  "UNARY_MINUS", "LOWER_THAN_ELSE", "$accept", "program", "declaration",
  "var_declaration", "type_specifier", "parameter_list",
  "function_declaration", "$@1", "$@2", "statement_list", "statement",
  "$@3", "if_prefix", "if_statement", "$@4", "while_statement", "$@5",
  "$@6", "for_statement", "$@7", "$@8", "$@9", "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      43,    45,    42,    47,    37,    61,    60,    62,    33,    38,
     124,    94,   126,   275,   276,   277,   278,   279,   280,   281,
     282,    59,    44,   123,   125,    40,    41,    91,    93,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    83,    84,    84,    85,    85,    85,    86,
      86,    86,    86,    87,    87,    89,    88,    90,    88,    91,
      91,    92,    92,    93,    92,    92,    92,    92,    92,    92,
      92,    92,    94,    95,    96,    95,    98,    99,    97,   101,
     102,   103,   100,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     3,     5,     6,     1,
       1,     1,     1,     2,     4,     0,     8,     0,     9,     0,
       2,     2,     1,     0,     4,     1,     1,     1,     2,     2,
       2,     3,     4,     2,     0,     5,     0,     0,     7,     0,
       0,     0,    12,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     9,    10,    11,    12,     3,     4,     0,
       5,     0,     0,     6,     0,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,    15,    13,     0,     0,     0,    61,
      60,    45,    46,    47,    48,    49,    52,    53,    54,    55,
      50,    51,    56,    57,    19,     0,    17,     8,     0,    14,
      19,     0,     0,     0,     0,     0,     0,    23,    16,    22,
       0,    20,     0,    25,    26,    27,     0,     0,     0,    36,
       0,    28,    29,    30,     0,    19,     0,    33,    21,    18,
       0,     0,     0,    31,     0,    34,    32,     0,    39,    24,
       0,    37,     0,    35,     0,     0,    38,    40,     0,     0,
      41,     0,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     7,    79,    80,    24,    10,    64,    70,    68,
      81,    95,    82,    83,   110,    84,   101,   114,    85,   112,
     118,   121,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
     -58,   179,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -15,
     -58,    -8,   123,   -58,     6,    -3,   -21,   -58,   123,   123,
     123,   238,   -11,    16,   -41,   -13,   123,   369,   348,   154,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   -58,   -58,   -58,    68,    -7,    -1,   348,
     -58,   354,   354,   369,   369,   369,   348,   348,   348,   348,
     348,   348,   348,   348,   -58,    23,   -58,   -58,    39,   -58,
     -58,     5,     8,    17,    10,    20,    47,   -58,   -58,   -58,
      59,   -58,   143,   -58,   -58,   -58,   260,    92,   123,   -58,
     123,   -58,   -58,   -58,   282,   -58,    44,    71,   -58,   -58,
     175,   123,   304,   -58,   112,   -58,   -58,   196,   -58,   -58,
     143,   -58,   123,   -58,   143,   326,   -58,   -58,   123,   217,
     -58,   143,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,    79,     1,   -58,   -58,   -58,   -58,   -57,
     -51,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      21,    46,     9,    11,    26,    47,    27,    28,    29,     3,
       4,     5,     6,    87,    49,    23,    25,    12,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    97,    44,    13,    45,    48,    66,    14,   104,    15,
      67,    69,     3,     4,     5,     6,    71,    65,    72,    73,
      88,    91,    22,    89,    74,    75,    76,    16,    17,   113,
      18,    92,    90,   116,    94,    16,    17,    19,    18,    12,
     122,     3,     4,     5,     6,    19,   100,    96,   102,   105,
       8,     0,    77,    78,    20,    13,     0,     0,    93,   107,
       0,    15,    20,     0,     0,     3,     4,     5,     6,    71,
     115,    72,    73,     0,     0,     0,   119,    74,    75,    76,
      16,    17,     0,    18,     0,     3,     4,     5,     6,    71,
      19,    72,    73,     0,     0,     0,     0,    74,    75,    76,
      16,    17,     0,    18,     0,    77,    99,    20,     0,     0,
      19,    16,    17,     0,    18,     0,     3,     4,     5,     6,
      71,    19,    72,    73,     0,    77,   109,    20,    74,    75,
      76,    16,    17,     0,    18,     0,     0,     0,    20,     0,
       0,    19,     0,     0,    30,    31,    32,    33,    34,     2,
      35,    36,     3,     4,     5,     6,    77,     0,    20,    37,
      38,    39,    40,    41,    42,    30,    31,    32,    33,    34,
      50,    35,    36,     0,     0,     0,     0,     0,     0,     0,
      37,    38,    39,    40,    41,    42,    30,    31,    32,    33,
      34,   106,    35,    36,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,    40,    41,    42,    30,    31,    32,
      33,    34,   111,    35,    36,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    39,    40,    41,    42,    30,    31,
      32,    33,    34,   120,    35,    36,     0,     0,     0,     0,
       0,     0,     0,    37,    38,    39,    40,    41,    42,    43,
      30,    31,    32,    33,    34,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,    37,    38,    39,    40,    41,
      42,    98,    30,    31,    32,    33,    34,     0,    35,    36,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    39,
      40,    41,    42,   103,    30,    31,    32,    33,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,    42,   108,    30,    31,    32,    33,
      34,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,    40,    41,    42,   117,    30,    31,
      32,    33,    34,     0,    35,    36,    32,    33,    34,     0,
      35,    36,     0,    37,    38,    39,    40,    41,    42,    37,
      38,    39,    40,    41,    42,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,    40,    41,    42
};

static const yytype_int8 yycheck[] =
{
      12,    42,     1,    18,    25,    46,    18,    19,    20,     3,
       4,     5,     6,    70,    26,    14,    19,    25,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    82,    43,    41,    18,    48,    43,    45,    95,    47,
      41,    18,     3,     4,     5,     6,     7,    46,     9,    10,
      45,    41,    46,    45,    15,    16,    17,    18,    19,   110,
      21,    41,    45,   114,    76,    18,    19,    28,    21,    25,
     121,     3,     4,     5,     6,    28,    88,    18,    90,     8,
       1,    -1,    43,    44,    45,    41,    -1,    -1,    41,   101,
      -1,    47,    45,    -1,    -1,     3,     4,     5,     6,     7,
     112,     9,    10,    -1,    -1,    -1,   118,    15,    16,    17,
      18,    19,    -1,    21,    -1,     3,     4,     5,     6,     7,
      28,     9,    10,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    -1,    21,    -1,    43,    44,    45,    -1,    -1,
      28,    18,    19,    -1,    21,    -1,     3,     4,     5,     6,
       7,    28,     9,    10,    -1,    43,    44,    45,    15,    16,
      17,    18,    19,    -1,    21,    -1,    -1,    -1,    45,    -1,
      -1,    28,    -1,    -1,    20,    21,    22,    23,    24,     0,
      26,    27,     3,     4,     5,     6,    43,    -1,    45,    35,
      36,    37,    38,    39,    40,    20,    21,    22,    23,    24,
      46,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    20,    21,    22,    23,
      24,    46,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    20,    21,    22,
      23,    24,    46,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    20,    21,
      22,    23,    24,    46,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    20,    21,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    20,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    20,    21,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    20,    21,
      22,    23,    24,    -1,    26,    27,    22,    23,    24,    -1,
      26,    27,    -1,    35,    36,    37,    38,    39,    40,    35,
      36,    37,    38,    39,    40,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    83,     0,     3,     4,     5,     6,    84,    85,    86,
      88,    18,    25,    41,    45,    47,    18,    19,    21,    28,
      45,   104,    46,    86,    87,    19,    25,   104,   104,   104,
      20,    21,    22,    23,    24,    26,    27,    35,    36,    37,
      38,    39,    40,    41,    43,    18,    42,    46,    48,   104,
      46,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,    89,    86,    43,    41,    91,    18,
      90,     7,     9,    10,    15,    16,    17,    43,    44,    85,
      86,    92,    94,    95,    97,   100,   104,    91,    45,    45,
      45,    41,    41,    41,   104,    93,    18,    92,    41,    44,
     104,    98,   104,    41,    91,     8,    46,   104,    41,    44,
      96,    46,   101,    92,    99,   104,    92,    41,   102,   104,
      46,   103,    92
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 131 "c_parser.y"
    {
        if (insert_symbol(sym_table, (yyvsp[(2) - (3)].str_val), (yyvsp[(1) - (3)].str_val), line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Variable '%s' already declared\n", line_num, (yyvsp[(2) - (3)].str_val));
            semantic_error_count++;
        }
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(2) - (3)].str_val));
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 139 "c_parser.y"
    {
        Symbol *sym;
        if (insert_symbol(sym_table, (yyvsp[(2) - (5)].str_val), (yyvsp[(1) - (5)].str_val), line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Variable '%s' already declared\n", line_num, (yyvsp[(2) - (5)].str_val));
            semantic_error_count++;
        } else {
            sym = lookup_symbol_in_scope(sym_table, (yyvsp[(2) - (5)].str_val), sym_table->scope_level);
            if (sym) {
                sym->initialized = 1;
            }
        }
        /* Emit TAC for declaration-time initialization, e.g., int x = 5; */
        emit_tac_binary(code_gen, TAC_ASSIGN, (yyvsp[(2) - (5)].str_val), (yyvsp[(4) - (5)].str_val), NULL, line_num);
        free((yyvsp[(1) - (5)].str_val));
        free((yyvsp[(2) - (5)].str_val));
        free((yyvsp[(4) - (5)].str_val));
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 156 "c_parser.y"
    {
        if (insert_symbol(sym_table, (yyvsp[(2) - (6)].str_val), (yyvsp[(1) - (6)].str_val), line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Array '%s' already declared\n", line_num, (yyvsp[(2) - (6)].str_val));
            semantic_error_count++;
        }
        free((yyvsp[(1) - (6)].str_val));
        free((yyvsp[(2) - (6)].str_val));
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 167 "c_parser.y"
    { (yyval.str_val) = strdup("int"); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 168 "c_parser.y"
    { (yyval.str_val) = strdup("float"); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 169 "c_parser.y"
    { (yyval.str_val) = strdup("char"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 170 "c_parser.y"
    { (yyval.str_val) = strdup("void"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 174 "c_parser.y"
    {
        /* Add parameter to symbol table */
        insert_symbol(sym_table, (yyvsp[(2) - (2)].str_val), (yyvsp[(1) - (2)].str_val), line_num, 0);
        free((yyvsp[(1) - (2)].str_val));
        free((yyvsp[(2) - (2)].str_val));
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 180 "c_parser.y"
    {
        /* Add parameter to symbol table */
        insert_symbol(sym_table, (yyvsp[(4) - (4)].str_val), (yyvsp[(3) - (4)].str_val), line_num, 0);
        free((yyvsp[(3) - (4)].str_val));
        free((yyvsp[(4) - (4)].str_val));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 189 "c_parser.y"
    {
        if (insert_symbol(sym_table, (yyvsp[(2) - (5)].str_val), (yyvsp[(1) - (5)].str_val), line_num, 1) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Function '%s' already declared\n", line_num, (yyvsp[(2) - (5)].str_val));
            semantic_error_count++;
        }
        in_function = 1;
        enter_scope(sym_table);
        free((yyvsp[(1) - (5)].str_val));
        free((yyvsp[(2) - (5)].str_val));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 199 "c_parser.y"
    {
        exit_scope(sym_table);
        in_function = 0;
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 203 "c_parser.y"
    {
        if (insert_symbol(sym_table, (yyvsp[(2) - (6)].str_val), (yyvsp[(1) - (6)].str_val), line_num, 1) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Function '%s' already declared\n", line_num, (yyvsp[(2) - (6)].str_val));
            semantic_error_count++;
        }
        in_function = 1;
        enter_scope(sym_table);
        free((yyvsp[(1) - (6)].str_val));
        free((yyvsp[(2) - (6)].str_val));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 213 "c_parser.y"
    {
        exit_scope(sym_table);
        in_function = 0;
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 225 "c_parser.y"
    {
        if ((yyvsp[(1) - (2)].str_val)) free((yyvsp[(1) - (2)].str_val));
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 229 "c_parser.y"
    {
        enter_scope(sym_table);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 232 "c_parser.y"
    {
        exit_scope(sym_table);
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 238 "c_parser.y"
    {
        if (!in_loop) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'break' statement not within a loop\n", line_num);
            semantic_error_count++;
        }
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 244 "c_parser.y"
    {
        if (!in_loop) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'continue' statement not within a loop\n", line_num);
            semantic_error_count++;
        }
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 250 "c_parser.y"
    {
        if (!in_function) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'return' statement outside function\n", line_num);
            semantic_error_count++;
        }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 256 "c_parser.y"
    {
        if (!in_function) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'return' statement outside function\n", line_num);
            semantic_error_count++;
        }
        if ((yyvsp[(2) - (3)].str_val)) free((yyvsp[(2) - (3)].str_val));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 288 "c_parser.y"
    {
        /* Emit condition check once; branch target is either else label or end label */
        int else_or_end_label = create_label(code_gen);
        emit_tac_if_false(code_gen, (yyvsp[(3) - (4)].str_val), else_or_end_label, line_num);
        push_if_labels(else_or_end_label, -1);
        free((yyvsp[(3) - (4)].str_val));
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 299 "c_parser.y"
    {
        /* if (...) then_stmt;  -> place end label */
        int else_or_end_label, dummy;
        pop_if_labels(&else_or_end_label, &dummy);
        emit_tac_label(code_gen, else_or_end_label, line_num);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 306 "c_parser.y"
    {
        /* if (...) then_stmt else ... -> jump over else, then place else label */
        int else_label, unused_end;
        int end_label = create_label(code_gen);
        pop_if_labels(&else_label, &unused_end);
        emit_tac_goto(code_gen, end_label, line_num);
        emit_tac_label(code_gen, else_label, line_num);
        push_if_labels(else_label, end_label);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 316 "c_parser.y"
    {
        /* End of else branch */
        int unused_else, end_label;
        pop_if_labels(&unused_else, &end_label);
        emit_tac_label(code_gen, end_label, line_num);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 326 "c_parser.y"
    {
        in_loop++;
        int start_label = create_label(code_gen);
        int end_label = create_label(code_gen);
        emit_tac_label(code_gen, start_label, line_num);
        push_loop_labels(start_label, end_label);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 334 "c_parser.y"
    {
        /* After condition: emit IF_FALSE */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_if_false(code_gen, (yyvsp[(4) - (5)].str_val), end_label, line_num);
        push_loop_labels(start_label, end_label);
        free((yyvsp[(4) - (5)].str_val));
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 342 "c_parser.y"
    {
        /* After body: emit GOTO start and LABEL end */
        in_loop--;
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_goto(code_gen, start_label, line_num);
        emit_tac_label(code_gen, end_label, line_num);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 354 "c_parser.y"
    {
        int start_label = create_label(code_gen);
        int end_label = create_label(code_gen);
        emit_tac_label(code_gen, start_label, line_num);
        push_loop_labels(start_label, end_label);
        if ((yyvsp[(3) - (4)].str_val)) free((yyvsp[(3) - (4)].str_val));
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 362 "c_parser.y"
    {
        /* After condition: emit IF_FALSE */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_if_false(code_gen, (yyvsp[(6) - (7)].str_val), end_label, line_num);
        push_loop_labels(start_label, end_label);
        free((yyvsp[(6) - (7)].str_val));
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 371 "c_parser.y"
    {
        /* Store update expression for later */
        if ((yyvsp[(9) - (10)].str_val)) free((yyvsp[(9) - (10)].str_val));
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 375 "c_parser.y"
    {
        /* After body: emit GOTO start and LABEL end */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_goto(code_gen, start_label, line_num);
        emit_tac_label(code_gen, end_label, line_num);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 385 "c_parser.y"
    {
        if (!lookup_symbol(sym_table, (yyvsp[(1) - (1)].str_val))) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Undeclared variable '%s'\n", line_num, (yyvsp[(1) - (1)].str_val));
            semantic_error_count++;
        }
        (yyval.str_val) = strdup((yyvsp[(1) - (1)].str_val));
        free((yyvsp[(1) - (1)].str_val));
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 393 "c_parser.y"
    {
        (yyval.str_val) = (char*)malloc(20);
        sprintf((yyval.str_val), "%d", (yyvsp[(1) - (1)].int_val));
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 397 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_ADD, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 403 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_SUB, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 409 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_MUL, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 415 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_DIV, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 421 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_MOD, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 427 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_EQ, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 433 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_NE, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 439 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_LT, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 445 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_GT, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 451 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_LE, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 457 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_GE, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 463 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_AND, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 469 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_OR, (yyval.str_val), (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), line_num);
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 475 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_unary(code_gen, TAC_NEG, (yyval.str_val), (yyvsp[(2) - (2)].str_val), line_num);
        free((yyvsp[(2) - (2)].str_val));
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 480 "c_parser.y"
    {
        (yyval.str_val) = new_temp();
        emit_tac_unary(code_gen, TAC_NOT, (yyval.str_val), (yyvsp[(2) - (2)].str_val), line_num);
        free((yyvsp[(2) - (2)].str_val));
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 485 "c_parser.y"
    {
        (yyval.str_val) = (yyvsp[(2) - (3)].str_val);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 488 "c_parser.y"
    {
        Symbol *sym = lookup_symbol(sym_table, (yyvsp[(1) - (3)].str_val));
        if (!sym) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Undeclared variable '%s'\n", line_num, (yyvsp[(1) - (3)].str_val));
            semantic_error_count++;
        } else {
            sym->initialized = 1;
        }
        emit_tac_binary(code_gen, TAC_ASSIGN, (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val), NULL, line_num);
        (yyval.str_val) = strdup((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(1) - (3)].str_val));
        free((yyvsp[(3) - (3)].str_val));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2244 "c_parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 503 "c_parser.y"



