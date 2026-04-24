
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

extern int yylex();
extern int line_num;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char* s);

// Uncomment for debugging
// #define YYDEBUG 1


/* Line 189 of yacc.c  */
#line 90 "c_parser.tab.c"

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
     AUTO = 258,
     BREAK = 259,
     CASE = 260,
     CHAR = 261,
     CONST = 262,
     CONTINUE = 263,
     DEFAULT = 264,
     DO = 265,
     DOUBLE = 266,
     ELSE = 267,
     ENUM = 268,
     EXTERN = 269,
     FLOAT = 270,
     FOR = 271,
     GOTO = 272,
     IF = 273,
     INT = 274,
     LONG = 275,
     REGISTER = 276,
     RETURN = 277,
     SHORT = 278,
     SIGNED = 279,
     SIZEOF = 280,
     STATIC = 281,
     STRUCT = 282,
     SWITCH = 283,
     TYPEDEF = 284,
     UNION = 285,
     UNSIGNED = 286,
     VOID = 287,
     VOLATILE = 288,
     WHILE = 289,
     IDENTIFIER = 290,
     CONSTANT = 291,
     STRING_LITERAL = 292,
     INC_OP = 293,
     DEC_OP = 294,
     LEFT_OP = 295,
     RIGHT_OP = 296,
     LE_OP = 297,
     GE_OP = 298,
     EQ_OP = 299,
     NE_OP = 300,
     AND_OP = 301,
     OR_OP = 302,
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
     IFX = 314
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "c_parser.y"

    int int_val;
    double num_val;
    char* str_val;



/* Line 214 of yacc.c  */
#line 193 "c_parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 205 "c_parser.tab.c"

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNRULES -- Number of states.  */
#define YYNSTATES  349

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,     2,     2,    73,    66,     2,
      60,    61,    67,    68,    65,    69,    64,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    81,
      74,    80,    75,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,    77,    83,    70,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   173,   175,   179,   181,
     187,   189,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   221,   223,   226,   230,   232,
     235,   237,   240,   242,   245,   247,   251,   253,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   295,   300,   303,   305,   307,
     309,   312,   316,   319,   321,   324,   326,   328,   332,   334,
     337,   341,   346,   352,   355,   357,   361,   363,   367,   369,
     371,   374,   376,   378,   382,   387,   391,   396,   401,   405,
     407,   410,   413,   417,   419,   422,   424,   428,   430,   434,
     437,   440,   442,   444,   448,   450,   453,   455,   457,   460,
     464,   467,   471,   475,   480,   483,   487,   491,   496,   498,
     502,   507,   509,   513,   515,   517,   519,   521,   523,   525,
     529,   534,   538,   541,   545,   549,   554,   556,   559,   561,
     564,   566,   569,   575,   583,   589,   595,   603,   610,   618,
     622,   625,   628,   631,   635,   637,   640,   642,   644,   649,
     653,   657
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     145,     0,    -1,    35,    -1,    36,    -1,    37,    -1,    60,
     104,    61,    -1,    85,    -1,    86,    62,   104,    63,    -1,
      86,    60,    61,    -1,    86,    60,    87,    61,    -1,    86,
      64,    35,    -1,    86,    58,    35,    -1,    86,    38,    -1,
      86,    39,    -1,   102,    -1,    87,    65,   102,    -1,    86,
      -1,    38,    88,    -1,    39,    88,    -1,    89,    90,    -1,
      25,    88,    -1,    25,    60,   131,    61,    -1,    66,    -1,
      67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,
      88,    -1,    60,   131,    61,    90,    -1,    90,    -1,    91,
      67,    90,    -1,    91,    72,    90,    -1,    91,    73,    90,
      -1,    91,    -1,    92,    68,    91,    -1,    92,    69,    91,
      -1,    92,    -1,    93,    40,    92,    -1,    93,    41,    92,
      -1,    93,    -1,    94,    74,    93,    -1,    94,    75,    93,
      -1,    94,    42,    93,    -1,    94,    43,    93,    -1,    94,
      -1,    95,    44,    94,    -1,    95,    45,    94,    -1,    95,
      -1,    96,    66,    95,    -1,    96,    -1,    97,    76,    96,
      -1,    97,    -1,    98,    77,    97,    -1,    98,    -1,    99,
      46,    98,    -1,    99,    -1,   100,    47,    99,    -1,   100,
      -1,   100,    78,   104,    79,   101,    -1,   101,    -1,    88,
     103,   102,    -1,    80,    -1,    48,    -1,    49,    -1,    50,
      -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,   102,    -1,   104,    65,   102,
      -1,   101,    -1,   107,    81,    -1,   107,   108,    81,    -1,
     110,    -1,   110,   107,    -1,   111,    -1,   111,   107,    -1,
     122,    -1,   122,   107,    -1,   109,    -1,   108,    65,   109,
      -1,   123,    -1,   123,    80,   134,    -1,     3,    -1,    21,
      -1,    26,    -1,    14,    -1,    29,    -1,    32,    -1,     6,
      -1,    23,    -1,    19,    -1,    20,    -1,    15,    -1,    11,
      -1,    24,    -1,    31,    -1,   112,    -1,   119,    -1,   113,
      35,    82,   114,    83,    -1,   113,    82,   114,    83,    -1,
     113,    35,    -1,    27,    -1,    30,    -1,   115,    -1,   114,
     115,    -1,   116,   117,    81,    -1,   111,   116,    -1,   111,
      -1,   122,   116,    -1,   122,    -1,   118,    -1,   117,    65,
     118,    -1,   123,    -1,    79,   105,    -1,   123,    79,   105,
      -1,    13,    82,   120,    83,    -1,    13,    35,    82,   120,
      83,    -1,    13,    35,    -1,   121,    -1,   120,    65,   121,
      -1,    35,    -1,    35,    80,   105,    -1,     7,    -1,    33,
      -1,   125,   124,    -1,   124,    -1,    35,    -1,    60,   123,
      61,    -1,   124,    62,   105,    63,    -1,   124,    62,    63,
      -1,   124,    60,   127,    61,    -1,   124,    60,   130,    61,
      -1,   124,    60,    61,    -1,    67,    -1,    67,   126,    -1,
      67,   125,    -1,    67,   126,   125,    -1,   122,    -1,   126,
     122,    -1,   128,    -1,   128,    65,    64,    -1,   129,    -1,
     128,    65,   129,    -1,   107,   123,    -1,   107,   132,    -1,
     107,    -1,    35,    -1,   130,    65,    35,    -1,   116,    -1,
     116,   132,    -1,   125,    -1,   133,    -1,   125,   133,    -1,
      60,   132,    61,    -1,    62,    63,    -1,    62,   105,    63,
      -1,   133,    62,    63,    -1,   133,    62,   105,    63,    -1,
      60,    61,    -1,    60,   127,    61,    -1,   133,    60,    61,
      -1,   133,    60,   127,    61,    -1,   102,    -1,    82,   135,
      83,    -1,    82,   135,    65,    83,    -1,   134,    -1,   135,
      65,   134,    -1,   137,    -1,   138,    -1,   141,    -1,   142,
      -1,   143,    -1,   144,    -1,    35,    79,   136,    -1,     5,
     105,    79,   136,    -1,     9,    79,   136,    -1,    82,    83,
      -1,    82,   140,    83,    -1,    82,   139,    83,    -1,    82,
     139,   140,    83,    -1,   106,    -1,   139,   106,    -1,   136,
      -1,   140,   136,    -1,    81,    -1,   104,    81,    -1,    18,
      60,   104,    61,   136,    -1,    18,    60,   104,    61,   136,
      12,   136,    -1,    28,    60,   104,    61,   136,    -1,    34,
      60,   104,    61,   136,    -1,    10,   136,    34,    60,   104,
      61,    81,    -1,    16,    60,   141,   141,    61,   136,    -1,
      16,    60,   141,   141,   104,    61,   136,    -1,    17,    35,
      81,    -1,     8,    81,    -1,     4,    81,    -1,    22,    81,
      -1,    22,   104,    81,    -1,   146,    -1,   145,   146,    -1,
     147,    -1,   106,    -1,   107,   123,   139,   138,    -1,   107,
     123,   138,    -1,   123,   139,   138,    -1,   123,   138,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    48,    49,    50,    54,    55,    56,    57,
      58,    59,    60,    61,    65,    66,    70,    71,    72,    73,
      74,    75,    79,    80,    81,    82,    83,    84,    88,    89,
      93,    94,    95,    96,   100,   101,   102,   106,   107,   108,
     112,   113,   114,   115,   116,   120,   121,   122,   126,   127,
     131,   132,   136,   137,   141,   142,   146,   147,   151,   152,
     156,   157,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   175,   176,   180,   184,   185,   189,   190,
     191,   192,   193,   194,   198,   199,   203,   204,   208,   209,
     210,   211,   212,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   230,   231,   232,   236,   237,   241,
     242,   246,   250,   251,   252,   253,   257,   258,   262,   263,
     264,   268,   269,   270,   274,   275,   279,   280,   284,   285,
     289,   290,   294,   295,   296,   297,   298,   299,   300,   304,
     305,   306,   307,   311,   312,   316,   317,   321,   322,   326,
     327,   328,   332,   333,   337,   338,   342,   343,   344,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   360,   361,
     362,   366,   367,   371,   372,   373,   374,   375,   376,   380,
     381,   382,   386,   387,   388,   389,   393,   394,   398,   399,
     403,   404,   408,   409,   410,   414,   415,   416,   417,   421,
     422,   423,   424,   425,   429,   430,   434,   435,   439,   440,
     441,   442
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN", "SHORT",
  "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION",
  "UNSIGNED", "VOID", "VOLATILE", "WHILE", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "PTR_OP", "IFX", "'('", "')'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      40,    41,    91,    93,    46,    44,    38,    42,    43,    45,
     126,    33,    47,    37,    60,    62,    94,   124,    63,    58,
      61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    85,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    91,    91,    92,    92,    92,    93,    93,    93,
      94,    94,    94,    94,    94,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   112,   113,   113,   114,
     114,   115,   116,   116,   116,   116,   117,   117,   118,   118,
     118,   119,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   129,   130,   130,   131,   131,   132,   132,   132,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   134,   134,
     134,   135,   135,   136,   136,   136,   136,   136,   136,   137,
     137,   137,   138,   138,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   142,   143,   143,   143,   143,   144,
     144,   144,   144,   144,   145,   145,   146,   146,   147,   147,
     147,   147
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       2,     3,     2,     1,     2,     1,     1,     3,     1,     2,
       3,     4,     5,     2,     1,     3,     1,     3,     1,     1,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     5,     7,     5,     5,     7,     6,     7,     3,
       2,     2,     2,     3,     1,     2,     1,     1,     4,     3,
       3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    88,    94,   128,    99,     0,    91,    98,    96,    97,
      89,    95,   100,    90,   107,    92,   108,   101,    93,   129,
     132,     0,   139,   207,     0,    78,    80,   102,     0,   103,
      82,     0,   131,     0,     0,   204,   206,   123,     0,     0,
     143,   141,   140,    76,     0,    84,    86,    79,    81,   106,
       0,    83,     0,   186,     0,   211,     0,     0,     0,   130,
       1,   205,     0,   126,     0,   124,   133,   144,   142,     0,
      77,     0,   209,     0,     0,   113,     0,   109,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     0,     0,     0,    22,    23,
      24,    25,    26,    27,   190,   182,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      58,    60,    73,     0,   188,   173,   174,     0,     0,   175,
     176,   177,   178,    86,   187,   210,   152,   138,   151,     0,
     145,   147,     0,     2,   135,    28,    75,     0,     0,     0,
       0,   121,    85,     0,   168,    87,   208,     0,   112,   105,
     110,     0,     0,   116,   118,   114,   201,     0,   200,     0,
       0,     0,     0,     0,   202,     0,     0,    20,     0,     0,
       0,     0,    17,    18,     0,   154,     0,    12,    13,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    62,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   184,     0,   183,
     189,     0,     0,   149,   156,   150,   157,   136,     0,   137,
       0,   134,   122,   127,   125,   171,     0,   104,   119,     0,
     111,     0,     0,   181,     0,     0,   199,     0,   203,     0,
       0,     0,   179,     5,     0,   156,   155,     0,    11,     8,
       0,    14,     0,    10,    61,    31,    32,    33,    35,    36,
      38,    39,    43,    44,    41,    42,    46,    47,    49,    51,
      53,    55,    57,     0,    74,   185,   164,     0,     0,   160,
       0,   158,     0,     0,   146,   148,   153,     0,   169,   117,
     120,   180,     0,     0,     0,    21,     0,     0,    29,     9,
       0,     7,     0,   165,   159,   161,   166,     0,   162,     0,
     170,   172,     0,     0,     0,   192,   194,   195,    15,    59,
     167,   163,     0,   197,     0,     0,   196,   198,   193
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,   107,   270,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   204,
     123,   147,    53,    54,    44,    45,    25,    26,    27,    28,
      76,    77,    78,   162,   163,    29,    64,    65,    30,    31,
      32,    33,    42,   297,   140,   141,   142,   186,   298,   236,
     155,   246,   124,   125,   126,    56,   128,   129,   130,   131,
     132,    34,    35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -215
static const yytype_int16 yypact[] =
{
     995,  -215,  -215,  -215,  -215,   -27,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,    42,     3,  -215,    15,  1432,  1432,  -215,   -21,  -215,
    1432,   627,    -4,   -19,   763,  -215,  -215,   -59,    -7,   -26,
    -215,  -215,     3,  -215,   -44,  -215,   596,  -215,  -215,    66,
    1460,  -215,   306,  -215,    15,  -215,   627,  1073,  1189,    -4,
    -215,  -215,    -7,    51,     7,  -215,  -215,  -215,  -215,    42,
    -215,  1133,  -215,   627,  1460,  1460,   263,  -215,    46,  1460,
     -22,  1311,    47,    97,   657,   133,   150,   140,  1152,  1348,
     152,   155,   104,  -215,  -215,  1363,  1363,   802,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,   141,   299,  1311,
    -215,    67,   157,   196,    25,   203,   161,   142,   153,   187,
     -25,  -215,  -215,    -1,  -215,  -215,  -215,   387,   455,  -215,
    -215,  -215,  -215,   165,  -215,  -215,  -215,  -215,   154,   191,
     201,  -215,   112,  -215,  -215,  -215,  -215,   193,    36,  1311,
      -7,  -215,  -215,  1133,  -215,  -215,  -215,   729,  -215,  -215,
    -215,  1311,     8,  -215,   182,  -215,  -215,   188,  -215,   657,
     239,  1170,   194,  1311,  -215,    13,   802,  -215,  1311,  1311,
     657,  1311,  -215,  -215,   123,    75,   216,  -215,  -215,   244,
    1207,  1311,   245,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  1311,  -215,  1311,  1311,  1311,  1311,
    1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,
    1311,  1311,  1311,  1311,  1311,  1311,  -215,  -215,   523,  -215,
    -215,   871,  1244,  -215,    14,  -215,    24,  -215,  1037,  -215,
     246,  -215,  -215,  -215,  -215,  -215,    49,  -215,  -215,    46,
    -215,  1311,   657,  -215,   225,  1170,  -215,   125,  -215,   227,
     130,   131,  -215,  -215,   933,    83,  -215,  1311,  -215,  -215,
     148,  -215,    40,  -215,  -215,  -215,  -215,  -215,    67,    67,
     157,   157,   196,   196,   196,   196,    25,    25,   203,   161,
     142,   153,   187,    43,  -215,  -215,  -215,   230,   231,  -215,
     235,    24,  1106,  1259,  -215,  -215,  -215,  1115,  -215,  -215,
    -215,  -215,  1311,  1296,   657,  -215,   657,   657,  -215,  -215,
    1311,  -215,  1311,  -215,  -215,  -215,  -215,   238,  -215,   237,
    -215,  -215,   158,   657,   163,   289,  -215,  -215,  -215,  -215,
    -215,  -215,   222,  -215,   657,   657,  -215,  -215,  -215
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,  -215,  -215,   -57,  -215,   -96,    45,    48,    28,
      54,    85,    86,    84,    96,   134,  -215,   -54,   -23,  -215,
     -55,   -64,     6,     0,  -215,   290,  -215,   132,  -215,  -215,
     233,   -69,   -32,  -215,   109,  -215,   298,   211,    41,    -9,
     -30,   -11,  -215,   -52,  -215,   124,  -215,   189,  -119,  -214,
    -135,  -215,   -82,  -215,    -2,    95,   236,  -162,  -215,  -215,
    -215,  -215,   330,  -215
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      24,   145,   170,    59,   146,   139,    23,   160,    37,   255,
       3,    41,    39,   205,    49,    46,    20,   167,   245,   235,
     301,    69,   223,    62,   145,    47,    48,   146,    63,    55,
      51,    68,   177,   175,    24,    66,    19,    70,   182,   183,
      23,    21,   184,   158,    72,   133,   230,   165,   154,    20,
      20,   301,   145,   224,   135,    38,    57,   138,    58,   166,
     133,    50,   134,    40,   225,   185,   266,   213,   214,   164,
      22,   156,   150,   249,   231,    21,   232,    20,   225,   134,
     226,    20,    22,    67,   302,   243,   303,   253,   160,   250,
     151,    79,   145,   313,   258,   146,    43,   248,   262,   215,
     216,   150,    21,   321,   145,   225,    21,   146,   225,    22,
     275,   276,   277,    22,   307,    79,    79,    79,   257,   242,
      79,   184,   322,   260,   261,   161,   184,   234,   168,   233,
     154,   149,   308,   134,   206,   264,   272,   232,    79,   207,
     208,    73,    22,   264,   185,   232,   230,   127,    74,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   271,   300,   293,
     311,   318,   331,   239,   265,   145,   169,   240,   146,   187,
     188,   274,    75,   180,   263,   172,   314,   310,   225,    20,
     225,   316,   317,   171,   145,   225,   225,   146,    79,   189,
     173,   190,   294,   191,    59,   192,    75,    75,    75,   319,
     145,    75,   178,   320,   231,   179,   232,    79,   220,   342,
     234,    22,    39,   225,   344,   209,   210,   219,   225,    75,
     221,   138,   335,   222,   336,   337,   211,   212,   138,   329,
     164,   282,   283,   284,   285,    71,   145,   217,   218,   146,
     327,   343,   237,   265,   278,   279,   241,   332,   334,   280,
     281,   251,   347,   348,   138,   145,   238,   252,   339,     2,
       3,   286,   287,   254,     4,   256,     5,   267,     7,   268,
     273,   306,     8,     9,   154,   312,    11,    12,   315,    75,
      14,   323,   324,    16,    17,    18,    19,   338,   325,   340,
     341,   345,   138,   346,   288,   290,   289,   157,    75,     1,
      80,    81,     2,     3,    82,    83,    84,     4,   291,     5,
       6,     7,    85,    86,    87,     8,     9,    10,    88,    11,
      12,    89,    13,    14,    90,    15,    16,    17,    18,    19,
      91,    92,    93,    94,    95,    96,   159,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   292,   309,   152,
     148,   244,   305,   228,    61,   259,    97,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   203,
       0,     0,     0,     0,     0,     0,     0,   104,    52,   105,
       1,    80,    81,     2,     3,    82,    83,    84,     4,     0,
       5,     6,     7,    85,    86,    87,     8,     9,    10,    88,
      11,    12,    89,    13,    14,    90,    15,    16,    17,    18,
      19,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,    80,
      81,     0,     0,    82,    83,    84,     0,     0,   104,    52,
     227,    85,    86,    87,     0,     0,     0,    88,     0,     0,
      89,     0,     0,    90,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,    80,    81,     0,
       0,    82,    83,    84,     0,     0,   104,    52,   229,    85,
      86,    87,     0,     0,     0,    88,     0,     0,    89,     0,
       0,    90,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     1,
       0,     0,     2,     3,   104,    52,   295,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,     0,    11,
      12,     0,    13,    14,     0,    15,    16,    17,    18,    19,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,     0,
      11,    12,     0,    13,    14,     0,    15,    16,    17,    18,
      19,    80,    81,     0,     0,    82,    83,    84,     0,     0,
       0,     0,     0,    85,    86,    87,    71,     0,    52,    88,
       0,     0,    89,     0,     0,    90,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     2,     3,     0,   104,    52,
       4,     0,     5,     0,     7,     0,     0,     0,     8,     9,
       0,     0,    11,    12,     0,     0,    14,     0,     0,    16,
      17,    18,    19,    60,     0,     0,     1,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,     0,    11,    12,     0,    13,
      14,     0,    15,    16,    17,    18,    19,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,   247,     4,     0,     5,     0,     7,     0,     0,
       0,     8,     9,    21,     0,    11,    12,    89,     0,    14,
      22,     0,    16,    17,    18,    19,     0,   143,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,     0,    11,    12,     0,    13,    14,     0,
      15,    16,    17,    18,    19,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   231,   296,   232,     0,     0,     1,     0,    22,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,     0,    11,    12,     0,    13,
      14,     0,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   296,   232,     0,     0,     1,     0,
      22,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,     0,    11,    12,
       0,    13,    14,     0,    15,    16,    17,    18,    19,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,    21,     8,     9,    10,     0,
      11,    12,    22,    13,    14,     0,    15,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     1,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,     0,    11,    12,     0,    13,
      14,   304,    15,    16,    17,    18,    19,     0,   136,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,     0,    11,
      12,     0,    13,    14,   137,    15,    16,    17,    18,    19,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,    93,    94,    95,    96,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,   326,   143,    93,
      94,    95,    96,     0,     0,    97,     0,    89,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   143,    93,    94,
      95,    96,     0,    97,     0,    89,     0,   153,   330,    98,
      99,   100,   101,   102,   103,   143,    93,    94,    95,    96,
       0,     0,    97,     0,    89,   153,     0,     0,    98,    99,
     100,   101,   102,   103,   143,    93,    94,    95,    96,     0,
      97,     0,    89,   174,     0,     0,    98,    99,   100,   101,
     102,   103,   143,    93,    94,    95,    96,     0,     0,    97,
       0,   104,   144,     0,     0,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,    97,   269,    89,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   143,
      93,    94,    95,    96,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,    93,    94,    95,    96,     0,
       0,     0,     0,     0,    97,     0,     0,   299,     0,     0,
      98,    99,   100,   101,   102,   103,     0,     0,     0,    97,
       0,    89,   328,     0,     0,    98,    99,   100,   101,   102,
     103,   143,    93,    94,    95,    96,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,    93,    94,    95,
      96,     0,     0,     0,     0,     0,    97,   333,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,     0,
       0,    97,     0,    89,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   143,    93,    94,    95,    96,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,    93,
      94,    95,    96,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   181,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     1,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,     0,    11,    12,     0,    13,    14,
       0,    15,    16,    17,    18,    19,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     8,
       9,     0,     0,    11,    12,     0,     0,    14,     0,     0,
      16,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
       0,    58,    84,    33,    58,    57,     0,    76,    35,   171,
       7,    22,    21,   109,    35,    24,    35,    81,   153,   138,
     234,    65,    47,    82,    81,    25,    26,    81,    35,    31,
      30,    42,    89,    88,    34,    61,    33,    81,    95,    96,
      34,    60,    97,    75,    46,    54,   128,    79,    71,    35,
      35,   265,   109,    78,    56,    82,    60,    57,    62,    81,
      69,    82,    56,    22,    65,    97,   185,    42,    43,    78,
      67,    73,    65,    65,    60,    60,    62,    35,    65,    73,
      81,    35,    67,    42,    60,   149,    62,   169,   157,    81,
      83,    50,   149,   255,    81,   149,    81,   161,   180,    74,
      75,    65,    60,    63,   161,    65,    60,   161,    65,    67,
     206,   207,   208,    67,    65,    74,    75,    76,   173,    83,
      79,   176,    79,   178,   179,    79,   181,   138,    81,   138,
     153,    80,    83,   127,    67,    60,   191,    62,    97,    72,
      73,    46,    67,    60,   176,    62,   228,    52,    82,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   190,   232,   224,
     252,   267,   307,    61,   185,   232,    79,    65,   232,    38,
      39,   204,    50,    79,    61,    35,    61,   251,    65,    35,
      65,    61,    61,    60,   251,    65,    65,   251,   157,    58,
      60,    60,   225,    62,   234,    64,    74,    75,    76,    61,
     267,    79,    60,    65,    60,    60,    62,   176,    76,    61,
     231,    67,   231,    65,    61,    68,    69,    66,    65,    97,
      77,   231,   314,    46,   316,   317,    40,    41,   238,   303,
     249,   213,   214,   215,   216,    80,   303,    44,    45,   303,
     302,   333,    61,   264,   209,   210,    63,   312,   313,   211,
     212,    79,   344,   345,   264,   322,    65,    79,   322,     6,
       7,   217,   218,    34,    11,    81,    13,    61,    15,    35,
      35,    35,    19,    20,   307,    60,    23,    24,    61,   157,
      27,    61,    61,    30,    31,    32,    33,   320,    63,    61,
      63,    12,   302,    81,   219,   221,   220,    74,   176,     3,
       4,     5,     6,     7,     8,     9,    10,    11,   222,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    83,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   223,   249,    69,
      62,   150,   238,   127,    34,   176,    60,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,     4,
       5,    -1,    -1,     8,     9,    10,    -1,    -1,    81,    82,
      83,    16,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,     4,     5,    -1,
      -1,     8,     9,    10,    -1,    -1,    81,    82,    83,    16,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,     3,
      -1,    -1,     6,     7,    81,    82,    83,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,    23,
      24,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,
      23,    24,    -1,    26,    27,    -1,    29,    30,    31,    32,
      33,     4,     5,    -1,    -1,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    80,    -1,    82,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    81,    82,
      11,    -1,    13,    -1,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    33,     0,    -1,    -1,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    -1,    23,    24,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    -1,    83,    11,    -1,    13,    -1,    15,    -1,    -1,
      -1,    19,    20,    60,    -1,    23,    24,    25,    -1,    27,
      67,    -1,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    -1,    23,    24,    -1,    26,    27,    -1,
      29,    30,    31,    32,    33,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,    -1,    67,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    -1,    23,    24,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,    -1,
      67,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    -1,    23,    24,
      -1,    26,    27,    -1,    29,    30,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    60,    19,    20,    21,    -1,
      23,    24,    67,    26,    27,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    -1,    23,    24,    -1,    26,
      27,    64,    29,    30,    31,    32,    33,    -1,    35,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,    23,
      24,    -1,    26,    27,    61,    29,    30,    31,    32,    33,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    35,    36,
      37,    38,    39,    -1,    -1,    60,    -1,    25,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    35,    36,    37,
      38,    39,    -1,    60,    -1,    25,    -1,    82,    83,    66,
      67,    68,    69,    70,    71,    35,    36,    37,    38,    39,
      -1,    -1,    60,    -1,    25,    82,    -1,    -1,    66,    67,
      68,    69,    70,    71,    35,    36,    37,    38,    39,    -1,
      60,    -1,    25,    81,    -1,    -1,    66,    67,    68,    69,
      70,    71,    35,    36,    37,    38,    39,    -1,    -1,    60,
      -1,    81,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    25,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    35,
      36,    37,    38,    39,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    60,
      -1,    25,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    35,    36,    37,    38,    39,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    60,    -1,    25,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    35,    36,    37,    38,    39,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,     3,    -1,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    -1,    23,    24,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,
      30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    23,    24,    26,    27,    29,    30,    31,    32,    33,
      35,    60,    67,   106,   107,   110,   111,   112,   113,   119,
     122,   123,   124,   125,   145,   146,   147,    35,    82,   123,
     122,   125,   126,    81,   108,   109,   123,   107,   107,    35,
      82,   107,    82,   106,   107,   138,   139,    60,    62,   124,
       0,   146,    82,    35,   120,   121,    61,   122,   125,    65,
      81,    80,   138,   139,    82,   111,   114,   115,   116,   122,
       4,     5,     8,     9,    10,    16,    17,    18,    22,    25,
      28,    34,    35,    36,    37,    38,    39,    60,    66,    67,
      68,    69,    70,    71,    81,    83,    85,    86,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   104,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   123,   106,   138,    35,    61,   107,   127,
     128,   129,   130,    35,    63,    88,   101,   105,   120,    80,
      65,    83,   109,    82,   102,   134,   138,   114,   116,    83,
     115,    79,   117,   118,   123,   116,    81,   105,    81,    79,
     136,    60,    35,    60,    81,   104,    60,    88,    60,    60,
      79,    60,    88,    88,   104,   116,   131,    38,    39,    58,
      60,    62,    64,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    80,   103,    90,    67,    72,    73,    68,
      69,    40,    41,    42,    43,    74,    75,    44,    45,    66,
      76,    77,    46,    47,    78,    65,    81,    83,   140,    83,
     136,    60,    62,   123,   125,   132,   133,    61,    65,    61,
      65,    63,    83,   105,   121,   134,   135,    83,   105,    65,
      81,    79,    79,   136,    34,   141,    81,   104,    81,   131,
     104,   104,   136,    61,    60,   125,   132,    61,    35,    61,
      87,   102,   104,    35,   102,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    93,    93,    94,    94,    95,    96,
      97,    98,    99,   104,   102,    83,    61,   127,   132,    63,
     105,   133,    60,    62,    64,   129,    35,    65,    83,   118,
     105,   136,    60,   141,    61,    61,    61,    61,    90,    61,
      65,    63,    79,    61,    61,    63,    61,   127,    63,   105,
      83,   134,   104,    61,   104,   136,   136,   136,   102,   101,
      61,    63,    61,   136,    61,    12,    81,   136,   136
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
        case 2:

/* Line 1455 of yacc.c  */
#line 47 "c_parser.y"
    { printf("Identifier: %s\n", (yyvsp[(1) - (1)].str_val)); free((yyvsp[(1) - (1)].str_val)); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 48 "c_parser.y"
    { printf("Constant: %f\n", (yyvsp[(1) - (1)].num_val)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 49 "c_parser.y"
    { printf("String: %s\n", (yyvsp[(1) - (1)].str_val)); free((yyvsp[(1) - (1)].str_val)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2009 "c_parser.tab.c"
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
#line 445 "c_parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at line %d\n", s, line_num);
}

int main(int argc, char* argv[]) {
    // Uncomment for debugging
    // yydebug = 1;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        return 1;
    }

    yyin = input_file;
    printf("Parsing file: %s\n", argv[1]);
    
    int parse_result = yyparse();
    
    fclose(input_file);
    
    if (parse_result == 0) {
        printf("Parsing completed successfully.\n");
        return 0;
    } else {
        printf("Parsing failed.\n");
        return 1;
    }
}
