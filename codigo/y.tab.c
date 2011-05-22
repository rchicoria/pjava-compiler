
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
#line 1 "pjava.y"

#include "structures.h"
#include "functions.h"
#include "shows.h"
#include <stdio.h>
#include "symbol_table.h"
#include "semantic.h"
#include <string.h>

void show_table(table_element*);

//is_atribuicao_list* myprogram;
is_static_list* isl;
prog_env* prog_environment;


/* Line 189 of yacc.c  */
#line 90 "y.tab.c"

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
     CLASS = 258,
     STATIC = 259,
     INT = 260,
     STRING = 261,
     VOID = 262,
     FLOAT = 263,
     DOUBLE = 264,
     BOOLEAN = 265,
     CHAR = 266,
     IF = 267,
     ELSE = 268,
     WHILE = 269,
     FOR = 270,
     DO = 271,
     SWITCH = 272,
     CASE = 273,
     PRINT = 274,
     PRINTLN = 275,
     TRUE = 276,
     FALSE = 277,
     EQUALS = 278,
     DIFERENT = 279,
     GREATER = 280,
     LESSER = 281,
     GREATEQ = 282,
     LESSEQ = 283,
     AND = 284,
     OR = 285,
     VAR = 286,
     NUMBER = 287,
     FLOAT_NUM = 288,
     UMINUS = 289,
     IFX = 290
   };
#endif
/* Tokens.  */
#define CLASS 258
#define STATIC 259
#define INT 260
#define STRING 261
#define VOID 262
#define FLOAT 263
#define DOUBLE 264
#define BOOLEAN 265
#define CHAR 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define FOR 270
#define DO 271
#define SWITCH 272
#define CASE 273
#define PRINT 274
#define PRINTLN 275
#define TRUE 276
#define FALSE 277
#define EQUALS 278
#define DIFERENT 279
#define GREATER 280
#define LESSER 281
#define GREATEQ 282
#define LESSEQ 283
#define AND 284
#define OR 285
#define VAR 286
#define NUMBER 287
#define FLOAT_NUM 288
#define UMINUS 289
#define IFX 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "pjava.y"

	is_static_list* isl;
	is_atribuicao_list* ial;
	is_atributo* ia;
	is_metodo* im;
	is_tipo it;
	is_expressao_list* iel;
	is_expressao* ie;
	is_infix_expression* iie;
	is_unary_expression* iue;
	is_argumento* iar;
	is_argumento_list* iarl;
	is_print* ip;
	is_statement_list* istl;
	is_declaracao* id;
	is_b_expressao* ibe;
	is_while* iw;
	int num;
	float fnum;
	char* var;
	is_if* ii;
	is_else* iiel;
	is_for* isf;
	is_func_call* ifc;
	is_func_arg_list* ifal;



/* Line 214 of yacc.c  */
#line 225 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 237 "y.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   427

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,     2,     2,     2,
      45,    46,    36,    34,    43,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    38,
      39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    14,    17,    19,    23,    27,
      29,    31,    35,    45,    54,    63,    71,    75,    77,    80,
      82,    84,    86,    88,    90,    92,    94,    97,    99,   101,
     104,   106,   108,   110,   112,   114,   120,   126,   128,   130,
     132,   134,   136,   140,   144,   148,   152,   156,   160,   163,
     167,   171,   174,   178,   182,   186,   190,   194,   198,   200,
     202,   210,   216,   225,   232,   237,   240,   248,   254,   265,
     274,   277,   279,   285,   290,   294,   298,   300
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,     3,    31,    40,    50,    41,    -1,    50,
      51,    -1,    51,    -1,     4,    52,    -1,    55,    -1,    58,
      53,    42,    -1,    53,    43,    54,    -1,    54,    -1,    31,
      -1,    31,    44,    62,    -1,     4,    58,    31,    45,    56,
      46,    40,    59,    41,    -1,     4,    58,    31,    45,    56,
      46,    40,    41,    -1,     4,    58,    31,    45,    46,    40,
      59,    41,    -1,     4,    58,    31,    45,    46,    40,    41,
      -1,    56,    43,    57,    -1,    57,    -1,    58,    31,    -1,
       5,    -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,
      10,    -1,    11,    -1,    59,    60,    -1,    60,    -1,    52,
      -1,    54,    42,    -1,    61,    -1,    66,    -1,    68,    -1,
      69,    -1,    71,    -1,    19,    45,    62,    46,    42,    -1,
      20,    45,    62,    46,    42,    -1,    63,    -1,    64,    -1,
      32,    -1,    31,    -1,    33,    -1,    62,    34,    62,    -1,
      62,    35,    62,    -1,    62,    36,    62,    -1,    62,    37,
      62,    -1,    62,    34,    34,    -1,    62,    35,    35,    -1,
      35,    62,    -1,    65,    29,    65,    -1,    65,    30,    65,
      -1,    47,    65,    -1,    62,    23,    62,    -1,    62,    24,
      62,    -1,    62,    25,    62,    -1,    62,    26,    62,    -1,
      62,    27,    62,    -1,    62,    28,    62,    -1,    21,    -1,
      22,    -1,    12,    45,    65,    46,    40,    59,    41,    -1,
      12,    45,    65,    46,    60,    -1,    12,    45,    65,    46,
      40,    59,    41,    67,    -1,    12,    45,    65,    46,    60,
      67,    -1,    13,    40,    59,    41,    -1,    13,    60,    -1,
      14,    45,    65,    46,    40,    59,    41,    -1,    14,    45,
      65,    46,    60,    -1,    15,    45,    70,    65,    42,    62,
      46,    40,    59,    41,    -1,    15,    45,    70,    65,    42,
      62,    46,    60,    -1,    53,    42,    -1,    52,    -1,    31,
      45,    72,    46,    42,    -1,    31,    45,    46,    42,    -1,
      72,    43,    62,    -1,    72,    43,    65,    -1,    62,    -1,
      65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   106,   106,   109,   110,   113,   114,   117,   120,   121,
     124,   125,   128,   129,   130,   131,   134,   135,   138,   141,
     142,   143,   144,   145,   146,   147,   150,   151,   154,   155,
     156,   157,   158,   159,   160,   164,   165,   168,   169,   170,
     171,   172,   175,   176,   177,   178,   179,   180,   183,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     199,   200,   201,   202,   205,   206,   209,   210,   213,   214,
     217,   218,   221,   222,   225,   226,   227,   228
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "STATIC", "INT", "STRING",
  "VOID", "FLOAT", "DOUBLE", "BOOLEAN", "CHAR", "IF", "ELSE", "WHILE",
  "FOR", "DO", "SWITCH", "CASE", "PRINT", "PRINTLN", "TRUE", "FALSE",
  "EQUALS", "DIFERENT", "GREATER", "LESSER", "GREATEQ", "LESSEQ", "AND",
  "OR", "VAR", "NUMBER", "FLOAT_NUM", "'+'", "'-'", "'*'", "'/'", "UMINUS",
  "IFX", "'{'", "'}'", "';'", "','", "'='", "'('", "')'", "'!'", "$accept",
  "initclass", "statics", "static", "declaration", "attributions",
  "attribution", "method", "args", "arg", "type", "statements",
  "statement", "print", "expression", "infix_expression",
  "unary_expression", "b_expression", "if", "else", "while", "for",
  "for_first_camp", "func_call", "func_arg", 0
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
     285,   286,   287,   288,    43,    45,    42,    47,   289,   290,
     123,   125,    59,    44,    61,    40,    41,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    63,    63,    63,    63,    63,    63,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     1,     2,     1,     3,     3,     1,
       1,     3,     9,     8,     8,     7,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     5,     5,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     1,     1,
       7,     5,     8,     6,     4,     2,     7,     5,    10,     8,
       2,     1,     5,     4,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     4,     6,
      19,    20,    21,    22,    23,    24,    25,     5,     0,     2,
       3,    10,     0,     9,     0,     0,     7,     0,    40,    39,
      41,     0,    11,    37,    38,     0,     0,    17,     0,    10,
       8,    48,     0,     0,     0,     0,     0,     0,     0,    18,
      46,    42,    47,    43,    44,    45,     0,     0,     0,     0,
       0,    10,    15,    28,     0,     0,     0,    27,    30,    31,
      32,    33,    34,    16,     0,     0,     0,     0,     0,     0,
       0,    29,    14,    26,    13,     0,    58,    59,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,    76,    77,
       0,    12,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,    73,     0,     0,
      52,    53,    54,    55,    56,    57,    49,    50,     0,    61,
       0,    67,     0,    35,    36,    74,    75,    72,     0,     0,
      63,     0,     0,    60,     0,    65,    66,     0,    62,     0,
       0,    69,    64,     0,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     8,    63,    22,    64,     9,    36,    37,
      65,    66,    67,    68,    89,    33,    34,    90,    69,   140,
      70,    71,    94,    72,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
       2,   -14,    27,     4,   -73,    26,   187,    -1,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     8,   -73,
     -73,   -10,    63,   -73,    67,    57,   -73,    17,   -73,   -73,
     -73,    67,    16,   -73,   -73,    18,    47,   -73,    39,    34,
     -73,   -73,    42,   207,    67,    67,   104,   187,    48,   -73,
     -73,   -73,    89,   -73,   -73,   -73,    51,    72,    95,   109,
     121,    81,   -73,   -73,    50,    17,   122,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   150,    10,    10,   141,    67,    67,
     355,   -73,   -73,   -73,   -73,   168,   -73,   -73,    10,   369,
     -20,   -17,   -73,    96,    10,   373,   377,   125,   369,   114,
      61,   -73,   -73,    67,    67,    67,    67,    67,    67,    10,
      10,   288,   306,   -73,    -6,   126,   129,   -73,    10,   142,
      16,    16,    16,    16,    16,    16,   -73,   -73,   360,   172,
     360,   -73,    67,   -73,   -73,   369,   114,   -73,   196,   324,
     -73,   214,   381,   172,   360,   -73,   -73,   342,   -73,   242,
     360,   -73,   -73,   260,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   179,    -5,   112,   -16,   -73,   -73,   143,
       0,   -59,   -52,   -73,   -24,   -73,   -73,   -72,   -73,    69,
     -73,   -73,   -73,   -73,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      32,    17,    23,     6,    91,     1,    18,    41,    99,   109,
     110,    40,   109,   110,    83,    85,   102,     3,    51,    53,
      54,    55,   114,   109,   110,    38,   111,     4,    41,   112,
       6,    86,    87,    83,    24,    25,   132,   126,   127,    21,
      19,    28,    29,    30,     5,    31,   136,    38,    39,    23,
      42,    43,    44,    45,    95,    96,    98,    88,    46,   129,
     131,    23,    10,    11,    12,    13,    14,    15,    16,   138,
      49,   141,    92,    28,    29,    30,    50,    31,    24,   120,
     121,   122,   123,   124,   125,   149,    83,   145,    74,    83,
      47,   153,    81,    48,   135,   151,    75,    83,    28,    29,
      30,    83,    31,    35,   118,    26,    27,   119,   142,    10,
      11,    12,    13,    14,    15,    16,    56,    76,    57,    58,
      28,    29,    30,    59,    60,    24,    80,    10,    11,    12,
      13,    14,    15,    16,    56,    61,    57,    58,   113,    27,
      77,    59,    60,   109,   110,    62,    10,    11,    12,    13,
      14,    15,    16,    61,    78,    10,    11,    12,    13,    14,
      15,    16,    56,    82,    57,    58,    79,   117,   133,    59,
      60,   134,    39,    10,    11,    12,    13,    14,    15,    16,
      56,    61,    57,    58,   137,   139,    20,    59,    60,    93,
      73,    84,    10,    11,    12,    13,    14,    15,    16,    61,
       0,    10,    11,    12,    13,    14,    15,    16,    56,   101,
      57,    58,   148,     0,     0,    59,    60,     0,     0,    10,
      11,    12,    13,    14,    15,    16,    56,    61,    57,    58,
       0,     0,     0,    59,    60,     0,     0,   143,    28,    29,
      30,     0,    52,     0,     0,    61,     0,    10,    11,    12,
      13,    14,    15,    16,    56,   146,    57,    58,     0,     0,
       0,    59,    60,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    56,    61,    57,    58,     0,     0,     0,    59,
      60,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,    61,     0,    10,    11,    12,    13,    14,    15,    16,
      56,   154,    57,    58,     0,     0,     0,    59,    60,     0,
       0,    10,    11,    12,    13,    14,    15,    16,    56,    61,
      57,    58,     0,     0,     0,    59,    60,     0,   128,    10,
      11,    12,    13,    14,    15,    16,    56,    61,    57,    58,
       0,     0,     0,    59,    60,     0,   130,    10,    11,    12,
      13,    14,    15,    16,    56,    61,    57,    58,     0,     0,
       0,    59,    60,     0,   144,    10,    11,    12,    13,    14,
      15,    16,    56,    61,    57,    58,    86,    87,     0,    59,
      60,     0,   150,     0,     0,     0,    28,    29,    30,     0,
      31,    61,   103,   104,   105,   106,   107,   108,     0,     0,
       0,    97,    88,    42,    43,    44,    45,    42,    43,    44,
      45,    42,    43,    44,    45,    42,    43,    44,    45,   115,
       0,     0,     0,   116,     0,     0,     0,   147
};

static const yytype_int16 yycheck[] =
{
      24,     6,    18,     4,    76,     3,     6,    31,    80,    29,
      30,    27,    29,    30,    66,    74,    88,    31,    42,    43,
      44,    45,    94,    29,    30,    25,    46,     0,    52,    46,
       4,    21,    22,    85,    44,    45,    42,   109,   110,    31,
      41,    31,    32,    33,    40,    35,   118,    47,    31,    65,
      34,    35,    36,    37,    78,    79,    80,    47,    40,   111,
     112,    77,     5,     6,     7,     8,     9,    10,    11,   128,
      31,   130,    77,    31,    32,    33,    34,    35,    44,   103,
     104,   105,   106,   107,   108,   144,   138,   139,    40,   141,
      43,   150,    42,    46,   118,   147,    45,   149,    31,    32,
      33,   153,    35,    46,    43,    42,    43,    46,   132,     5,
       6,     7,     8,     9,    10,    11,    12,    45,    14,    15,
      31,    32,    33,    19,    20,    44,    45,     5,     6,     7,
       8,     9,    10,    11,    12,    31,    14,    15,    42,    43,
      45,    19,    20,    29,    30,    41,     5,     6,     7,     8,
       9,    10,    11,    31,    45,     5,     6,     7,     8,     9,
      10,    11,    12,    41,    14,    15,    45,    42,    42,    19,
      20,    42,    31,     5,     6,     7,     8,     9,    10,    11,
      12,    31,    14,    15,    42,    13,     7,    19,    20,    77,
      47,    41,     5,     6,     7,     8,     9,    10,    11,    31,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    41,
      14,    15,   143,    -1,    -1,    19,    20,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    31,    14,    15,
      -1,    -1,    -1,    19,    20,    -1,    -1,    41,    31,    32,
      33,    -1,    35,    -1,    -1,    31,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    41,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    31,    14,    15,    -1,    -1,    -1,    19,
      20,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    41,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    31,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    40,     5,
       6,     7,     8,     9,    10,    11,    12,    31,    14,    15,
      -1,    -1,    -1,    19,    20,    -1,    40,     5,     6,     7,
       8,     9,    10,    11,    12,    31,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    40,     5,     6,     7,     8,     9,
      10,    11,    12,    31,    14,    15,    21,    22,    -1,    19,
      20,    -1,    40,    -1,    -1,    -1,    31,    32,    33,    -1,
      35,    31,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    46,    47,    34,    35,    36,    37,    34,    35,    36,
      37,    34,    35,    36,    37,    34,    35,    36,    37,    46,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    49,    31,     0,    40,     4,    50,    51,    55,
       5,     6,     7,     8,     9,    10,    11,    52,    58,    41,
      51,    31,    53,    54,    44,    45,    42,    43,    31,    32,
      33,    35,    62,    63,    64,    46,    56,    57,    58,    31,
      54,    62,    34,    35,    36,    37,    40,    43,    46,    31,
      34,    62,    35,    62,    62,    62,    12,    14,    15,    19,
      20,    31,    41,    52,    54,    58,    59,    60,    61,    66,
      68,    69,    71,    57,    40,    45,    45,    45,    45,    45,
      45,    42,    41,    60,    41,    59,    21,    22,    47,    62,
      65,    65,    52,    53,    70,    62,    62,    46,    62,    65,
      72,    41,    65,    23,    24,    25,    26,    27,    28,    29,
      30,    46,    46,    42,    65,    46,    46,    42,    43,    46,
      62,    62,    62,    62,    62,    62,    65,    65,    40,    60,
      40,    60,    42,    42,    42,    62,    65,    42,    59,    13,
      67,    59,    62,    41,    40,    60,    41,    46,    67,    59,
      40,    60,    41,    59,    41
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
        case 3:

/* Line 1455 of yacc.c  */
#line 109 "pjava.y"
    {(yyval.isl)=insert_static_list((yyvsp[(1) - (2)].isl), (yyvsp[(2) - (2)].isl));}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 110 "pjava.y"
    {(yyval.isl)=insert_static_list(NULL, (yyvsp[(1) - (1)].isl)); isl=(yyval.isl);}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 113 "pjava.y"
    {(yyval.isl)=insert_d_static((yyvsp[(2) - (2)].id));}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 114 "pjava.y"
    {(yyval.isl)=insert_m_static((yyvsp[(1) - (1)].im));}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 117 "pjava.y"
    {(yyval.id)=insert_declaracao(line, (yyvsp[(2) - (3)].ial),(yyvsp[(1) - (3)].it));}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 120 "pjava.y"
    {(yyval.ial)=insert_atribuicao_list((yyvsp[(1) - (3)].ial), (yyvsp[(3) - (3)].ia));}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 121 "pjava.y"
    {(yyval.ial)=insert_atribuicao_list(NULL, (yyvsp[(1) - (1)].ia));}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 124 "pjava.y"
    {(yyval.ia)=insert_atributo(line, (yyvsp[(1) - (1)].var), NULL);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 125 "pjava.y"
    {(yyval.ia)=insert_atributo(line, (yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].ie));}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 128 "pjava.y"
    {(yyval.im)=insert_metodo(line, (yyvsp[(2) - (9)].it), (yyvsp[(3) - (9)].var), (yyvsp[(5) - (9)].iarl), (yyvsp[(8) - (9)].istl));}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 129 "pjava.y"
    {(yyval.im)=insert_metodo(line, (yyvsp[(2) - (8)].it), (yyvsp[(3) - (8)].var), (yyvsp[(5) - (8)].iarl), NULL);}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 130 "pjava.y"
    {(yyval.im)=insert_metodo(line, (yyvsp[(2) - (8)].it), (yyvsp[(3) - (8)].var), NULL, (yyvsp[(7) - (8)].istl));}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 131 "pjava.y"
    {(yyval.im)=insert_metodo(line, (yyvsp[(2) - (7)].it), (yyvsp[(3) - (7)].var), NULL, NULL);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 134 "pjava.y"
    {(yyval.iarl)=insert_argumento_list((yyvsp[(1) - (3)].iarl), (yyvsp[(3) - (3)].iar));}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 135 "pjava.y"
    {(yyval.iarl)=insert_argumento_list(NULL, (yyvsp[(1) - (1)].iar));}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 138 "pjava.y"
    {(yyval.iar)=insert_argumento((yyvsp[(1) - (2)].it), (yyvsp[(2) - (2)].var));}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 141 "pjava.y"
    {(yyval.it)=is_INT;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 142 "pjava.y"
    {(yyval.it)=is_STRING;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 143 "pjava.y"
    {(yyval.it)=is_VOID;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 144 "pjava.y"
    {(yyval.it)=is_FLOAT;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 145 "pjava.y"
    {(yyval.it)=is_DOUBLE;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 146 "pjava.y"
    {(yyval.it)=is_BOOLEAN;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 147 "pjava.y"
    {(yyval.it)=is_CHAR;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 150 "pjava.y"
    {insert_statement_list((yyvsp[(1) - (2)].istl),(yyvsp[(2) - (2)].istl));}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 151 "pjava.y"
    {insert_statement_list(NULL, (yyvsp[(1) - (1)].istl));}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 154 "pjava.y"
    {(yyval.istl)=insert_d_statement((yyvsp[(1) - (1)].id));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 155 "pjava.y"
    {(yyval.istl)=insert_a_statement((yyvsp[(1) - (2)].ia));}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 156 "pjava.y"
    {(yyval.istl)=insert_p_statement((yyvsp[(1) - (1)].ip));}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 157 "pjava.y"
    {(yyval.istl)=insert_i_statement((yyvsp[(1) - (1)].ii));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 158 "pjava.y"
    {(yyval.istl)=insert_w_statement((yyvsp[(1) - (1)].iw));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 159 "pjava.y"
    {(yyval.istl)=insert_f_statement((yyvsp[(1) - (1)].isf));}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 160 "pjava.y"
    {(yyval.istl)=insert_fc_statement((yyvsp[(1) - (1)].ifc));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 164 "pjava.y"
    {(yyval.ip)=insert_print(line, (yyvsp[(3) - (5)].ie), '\0');}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 165 "pjava.y"
    {(yyval.ip)=insert_print(line, (yyvsp[(3) - (5)].ie), '\n');}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 168 "pjava.y"
    {(yyval.ie)=insert_i_expression(line, (yyvsp[(1) - (1)].iie));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 169 "pjava.y"
    {(yyval.ie)=insert_u_expression(line, (yyvsp[(1) - (1)].iue));}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 170 "pjava.y"
    {(yyval.ie)=insert_NUMBER(line, (yyvsp[(1) - (1)].num));}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 171 "pjava.y"
    {(yyval.ie)=insert_VAR(line, (yyvsp[(1) - (1)].var));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 172 "pjava.y"
    {(yyval.ie)=insert_FLOAT_NUM(line, (yyvsp[(1) - (1)].fnum));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 175 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ie), is_PLUS, (yyvsp[(3) - (3)].ie));}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 176 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ie), is_MINUS, (yyvsp[(3) - (3)].ie));}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 177 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ie), is_MULT, (yyvsp[(3) - (3)].ie));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 178 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ie), is_DIVIDE, (yyvsp[(3) - (3)].ie));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 179 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ie), is_PLUS, insert_NUMBER(line, 1));}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 180 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ie), is_MINUS, insert_NUMBER(line, 1));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 183 "pjava.y"
    {(yyval.iue)=insert_unary_expression((yyvsp[(2) - (2)].ie));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 186 "pjava.y"
    {(yyval.ibe)=insert_b_i_expressao(line, (yyvsp[(1) - (3)].ibe), is_AND, (yyvsp[(3) - (3)].ibe));}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 187 "pjava.y"
    {(yyval.ibe)=insert_b_i_expressao(line, (yyvsp[(3) - (3)].ibe), is_OR, (yyvsp[(3) - (3)].ibe));}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 188 "pjava.y"
    {(yyval.ibe)=insert_b_n_expressao(line, (yyvsp[(2) - (2)].ibe));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 189 "pjava.y"
    {(yyval.ibe)=insert_comparacao(line, (yyvsp[(1) - (3)].ie), is_EQUALS, (yyvsp[(3) - (3)].ie));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 190 "pjava.y"
    {(yyval.ibe)=insert_comparacao(line, (yyvsp[(1) - (3)].ie), is_DIFERENT, (yyvsp[(3) - (3)].ie));}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 191 "pjava.y"
    {(yyval.ibe)=insert_comparacao(line, (yyvsp[(1) - (3)].ie), is_GREATER, (yyvsp[(3) - (3)].ie));}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 192 "pjava.y"
    {(yyval.ibe)=insert_comparacao(line, (yyvsp[(1) - (3)].ie), is_LESSER, (yyvsp[(3) - (3)].ie));}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 193 "pjava.y"
    {(yyval.ibe)=insert_comparacao(line, (yyvsp[(1) - (3)].ie), is_GREATEQ, (yyvsp[(3) - (3)].ie));}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 194 "pjava.y"
    {(yyval.ibe)=insert_comparacao(line, (yyvsp[(1) - (3)].ie), is_LESSEQ, (yyvsp[(3) - (3)].ie));}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 195 "pjava.y"
    {(yyval.ibe)=insert_b_tf_expressao(line, '1');}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 196 "pjava.y"
    {(yyval.ibe)=insert_b_tf_expressao(line, '0');}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 199 "pjava.y"
    {(yyval.ii)=insert_if(line, (yyvsp[(3) - (7)].ibe), (yyvsp[(6) - (7)].istl), NULL);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 200 "pjava.y"
    {(yyval.ii)=insert_if(line, (yyvsp[(3) - (5)].ibe), (yyvsp[(5) - (5)].istl), NULL);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 201 "pjava.y"
    {(yyval.ii)=insert_if(line, (yyvsp[(3) - (8)].ibe), (yyvsp[(6) - (8)].istl), (yyvsp[(8) - (8)].iiel));}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 202 "pjava.y"
    {(yyval.ii)=insert_if(line, (yyvsp[(3) - (6)].ibe), (yyvsp[(5) - (6)].istl), (yyvsp[(6) - (6)].iiel));}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 205 "pjava.y"
    {(yyval.iiel)=insert_else(line, (yyvsp[(3) - (4)].istl));}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 206 "pjava.y"
    {(yyval.iiel)=insert_else(line, (yyvsp[(2) - (2)].istl));}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 209 "pjava.y"
    {(yyval.iw)=insert_while(line, (yyvsp[(3) - (7)].ibe), (yyvsp[(6) - (7)].istl));}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 210 "pjava.y"
    {(yyval.iw)=insert_while(line, (yyvsp[(3) - (5)].ibe), (yyvsp[(5) - (5)].istl));}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 213 "pjava.y"
    {(yyval.isf)=insert_for(line, (yyvsp[(3) - (10)].istl), (yyvsp[(4) - (10)].ibe), (yyvsp[(6) - (10)].ie), (yyvsp[(9) - (10)].istl));}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 214 "pjava.y"
    {(yyval.isf)=insert_for(line, (yyvsp[(3) - (8)].istl), (yyvsp[(4) - (8)].ibe), (yyvsp[(6) - (8)].ie), (yyvsp[(8) - (8)].istl));}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 217 "pjava.y"
    {(yyval.istl)=insert_as_statement((yyvsp[(1) - (2)].ial));}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 218 "pjava.y"
    {(yyval.istl)=insert_d_statement((yyvsp[(1) - (1)].id));}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 221 "pjava.y"
    {(yyval.ifc)=insert_func_call(line, (yyvsp[(1) - (5)].var), (yyvsp[(3) - (5)].ifal));}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 222 "pjava.y"
    {(yyval.ifc)=insert_func_call(line, (yyvsp[(1) - (4)].var), NULL);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 225 "pjava.y"
    {(yyval.ifal)=insert_func_arg_list((yyvsp[(1) - (3)].ifal), insert_func_arg_exp(line, (yyvsp[(3) - (3)].ie)));}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 226 "pjava.y"
    {(yyval.ifal)=insert_func_arg_list((yyvsp[(1) - (3)].ifal), insert_func_arg_b_exp(line, (yyvsp[(3) - (3)].ibe)));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 227 "pjava.y"
    {(yyval.ifal)=insert_func_arg_exp(line, (yyvsp[(1) - (1)].ie));}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 228 "pjava.y"
    {(yyval.ifal)=insert_func_arg_b_exp(line, (yyvsp[(1) - (1)].ibe));}
    break;



/* Line 1455 of yacc.c  */
#line 2147 "y.tab.c"
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
#line 231 "pjava.y"

int main()
{
	line = 1;
	errors = 0;
	int parsing = yyparse();

	if(!parsing)
		prog_environment=semantic_analysis(isl);
	if(errors)
		printf("This program could not compile because there are %d errors.\n", errors);
	else
	{
	    show_program(isl);	//mostra a árvore que acabou de ser construida
	    show_table(prog_environment->global);
	}
    return 0;
}

int yyerror(char* s)
{
	printf("line %d: %s\n", line, s);
	return 0;
}

void show_table(table_element* table)
{
	table_element *aux;
	printf("\n");
	environment_list* aux1 = (environment_list*) malloc(sizeof(environment_list));
	aux1=prog_environment->procs;
	for(aux=table; aux; aux=aux->next){
		printf("symbol %s, type %s %s", aux->name, typeToString(aux->type), printSymType(aux->stype)); 
		if(aux->stype==is_METHOD){
		    printf(":\n---------");
		    show_table(aux1->locals);
		    aux1=aux1->next;
		    printf("---------\n");
		}
		else
		    printf("\n");
	}
}


