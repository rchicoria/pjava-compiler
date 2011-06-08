
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
#include "translate.h"

void show_table(table_element* table);
void show_environments();

is_static_list* isl;
prog_env* prog_environment;


/* Line 189 of yacc.c  */
#line 91 "y.tab.c"

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
     RETURN = 286,
     ARRAY = 287,
     INC = 288,
     DEC = 289,
     VAR = 290,
     NUM_INT = 291,
     NUM_DOUBLE = 292,
     VAL_CHAR = 293,
     UMINUS = 294,
     IFX = 295,
     SIMPLE = 296
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
#define RETURN 286
#define ARRAY 287
#define INC 288
#define DEC 289
#define VAR 290
#define NUM_INT 291
#define NUM_DOUBLE 292
#define VAL_CHAR 293
#define UMINUS 294
#define IFX 295
#define SIMPLE 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 18 "pjava.y"

	is_static_list* isl;
	is_attribution_list* ial;
	is_attribution* ia;
	is_method* im;
	is_type it;
	is_expression_list* iel;
	is_expression* ie;
	is_s_expression* ise;
	is_infix_expression* iie;
	is_unary_expression* iue;
	is_argument* iar;
	is_argument_list* iarl;
	is_print* ip;
	is_statement_list* istl;
	is_declaration* id;
	is_b_expression* ibe;
	is_while* iw;
	int inum;
	double dnum;
	char vchar;
	char* var;
	is_if* ii;
	is_else* iiel;
	is_for* isf;
	is_method_call* imc;
	is_method_arg_list* imal;
	is_return* ir;
	is_increment* iinc;



/* Line 214 of yacc.c  */
#line 242 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 254 "y.tab.c"

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
#define YYLAST   641

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    43,     2,     2,
      52,    53,    41,    39,    50,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,    51,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    44,    45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    14,    17,    19,    23,    27,
      29,    31,    35,    39,    44,    49,    54,    59,    64,    69,
      74,    79,    89,    98,   107,   115,   118,   122,   126,   130,
     132,   135,   137,   139,   141,   143,   145,   147,   149,   152,
     155,   158,   161,   164,   167,   170,   172,   174,   177,   180,
     182,   184,   186,   189,   191,   194,   199,   204,   206,   208,
     210,   212,   214,   216,   218,   220,   222,   226,   230,   234,
     238,   242,   245,   249,   253,   257,   260,   264,   268,   272,
     276,   280,   284,   286,   288,   290,   292,   294,   297,   300,
     308,   314,   323,   330,   335,   338,   346,   352,   363,   372,
     375,   377,   379,   381,   383,   385,   390,   394,   398,   402,
     404
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,     3,    35,    47,    57,    48,    -1,    57,
      58,    -1,    58,    -1,     4,    59,    -1,    62,    -1,    66,
      60,    49,    -1,    60,    50,    61,    -1,    61,    -1,    35,
      -1,    35,    51,    70,    -1,    35,    51,    74,    -1,    35,
      39,    51,    70,    -1,    35,    39,    51,    74,    -1,    35,
      40,    51,    70,    -1,    35,    40,    51,    74,    -1,    35,
      42,    51,    70,    -1,    35,    42,    51,    74,    -1,    35,
      41,    51,    70,    -1,    35,    41,    51,    74,    -1,     4,
      66,    35,    52,    64,    53,    47,    67,    48,    -1,     4,
      66,    35,    52,    64,    53,    47,    48,    -1,     4,    66,
      35,    52,    53,    47,    67,    48,    -1,     4,    66,    35,
      52,    53,    47,    48,    -1,    31,    49,    -1,    31,    74,
      49,    -1,    31,    70,    49,    -1,    64,    50,    65,    -1,
      65,    -1,    66,    35,    -1,     5,    -1,     6,    -1,     7,
      -1,     8,    -1,     9,    -1,    11,    -1,    10,    -1,     5,
      32,    -1,     6,    32,    -1,     8,    32,    -1,     9,    32,
      -1,    11,    32,    -1,    10,    32,    -1,    67,    68,    -1,
      68,    -1,    59,    -1,    61,    49,    -1,    69,    49,    -1,
      76,    -1,    78,    -1,    79,    -1,    82,    49,    -1,    63,
      -1,    75,    49,    -1,    19,    52,    71,    53,    -1,    20,
      52,    71,    53,    -1,    72,    -1,    73,    -1,    36,    -1,
      37,    -1,    38,    -1,    70,    -1,    35,    -1,    82,    -1,
      75,    -1,    71,    39,    71,    -1,    71,    40,    71,    -1,
      71,    41,    71,    -1,    71,    42,    71,    -1,    71,    43,
      71,    -1,    40,    71,    -1,    52,    71,    53,    -1,    74,
      29,    74,    -1,    74,    30,    74,    -1,    54,    74,    -1,
      71,    23,    71,    -1,    71,    24,    71,    -1,    71,    25,
      71,    -1,    71,    26,    71,    -1,    71,    27,    71,    -1,
      71,    28,    71,    -1,    21,    -1,    22,    -1,    35,    -1,
      82,    -1,    75,    -1,    35,    33,    -1,    35,    34,    -1,
      12,    52,    74,    53,    47,    67,    48,    -1,    12,    52,
      74,    53,    68,    -1,    12,    52,    74,    53,    47,    67,
      48,    77,    -1,    12,    52,    74,    53,    68,    77,    -1,
      13,    47,    67,    48,    -1,    13,    68,    -1,    14,    52,
      74,    53,    47,    67,    48,    -1,    14,    52,    74,    53,
      68,    -1,    15,    52,    80,    74,    49,    81,    53,    47,
      67,    48,    -1,    15,    52,    80,    74,    49,    81,    53,
      68,    -1,    60,    49,    -1,    59,    -1,    60,    -1,    69,
      -1,    82,    -1,    75,    -1,    35,    52,    83,    53,    -1,
      35,    52,    53,    -1,    83,    50,    70,    -1,    83,    50,
      74,    -1,    70,    -1,    74,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   126,   127,   130,   131,   134,   137,   138,
     139,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   154,   155,   156,   157,   160,   161,   162,   165,   166,
     169,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   187,   188,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   203,   204,   207,   208,   209,
     210,   211,   214,   215,   216,   217,   220,   221,   222,   223,
     224,   227,   228,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   247,   248,   251,
     252,   253,   254,   257,   258,   261,   262,   265,   266,   269,
     270,   273,   274,   275,   276,   279,   280,   283,   284,   285,
     286
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
  "OR", "RETURN", "ARRAY", "INC", "DEC", "VAR", "NUM_INT", "NUM_DOUBLE",
  "VAL_CHAR", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "IFX", "SIMPLE",
  "'{'", "'}'", "';'", "','", "'='", "'('", "')'", "'!'", "$accept",
  "initclass", "statics", "static", "declaration", "attributions",
  "attribution", "method", "return_val", "args", "arg", "type",
  "statements", "statement", "print", "expression", "simple_expression",
  "infix_expression", "unary_expression", "b_expression", "increment",
  "if", "else", "while", "for", "for_first_camp", "for_last_camp",
  "method_call", "method_arg", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    43,
      45,    42,    47,    37,   294,   295,   296,   123,   125,    59,
      44,    61,    40,    41,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    63,    63,    63,    64,    64,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    81,    82,    82,    83,    83,    83,
      83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     1,     2,     1,     3,     3,     1,
       1,     3,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     9,     8,     8,     7,     2,     3,     3,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     2,     2,     1,
       1,     1,     2,     1,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     2,     2,     7,
       5,     8,     6,     4,     2,     7,     5,    10,     8,     2,
       1,     1,     1,     1,     1,     4,     3,     3,     3,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     4,     6,
      31,    32,    33,    34,    35,    37,    36,     5,     0,     2,
       3,    38,    39,    40,    41,    43,    42,    10,     0,     9,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,    82,    83,    63,    59,    60,    61,     0,     0,
       0,    62,     0,    57,    58,    12,    65,    64,     0,     0,
      29,     0,     0,     8,    62,    14,    62,    16,    62,    20,
      62,    18,    87,    88,     0,    63,    62,    71,    65,    64,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,   106,
      62,   110,     0,    72,    76,    77,    78,    79,    80,    81,
      66,    67,    68,    69,    70,    73,    74,     0,     0,     0,
       0,     0,     0,     0,    24,    46,     0,    53,     0,     0,
      45,     0,     0,    49,    50,    51,     0,    28,     0,     0,
     105,     0,     0,     0,     0,     0,    25,    62,     0,    47,
      10,    23,    44,    48,    54,    52,    22,     0,    62,   108,
       0,     0,   100,     0,     0,     0,     0,    27,    26,    21,
       0,     0,    99,     0,    55,    56,     0,    90,     0,    96,
       0,     0,     0,    92,     0,    10,   101,   102,   104,     0,
     103,    89,     0,    94,    95,     0,    91,     0,     0,    98,
      93,     0,    97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     8,   125,    28,   126,     9,   127,    59,
      60,   128,   129,   130,   131,    76,    52,    53,    54,    55,
     132,   133,   183,   134,   135,   164,   189,   136,   102
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -135
static const yytype_int16 yypact[] =
{
      11,   -15,    18,    -2,  -135,    25,   343,     0,  -135,  -135,
      15,    34,  -135,    43,    61,    83,    92,  -135,    97,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,   589,   -11,  -135,
     106,   110,   113,   131,   501,    16,  -135,    99,   501,   501,
     501,   501,  -135,  -135,    70,  -135,  -135,  -135,   543,   543,
     501,   122,   549,  -135,  -135,    72,   199,   228,   126,   -13,
    -135,   149,   261,  -135,   197,    72,   257,    72,   306,    72,
     348,    72,  -135,  -135,   475,   108,  -135,  -135,  -135,  -135,
     564,  -135,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   501,   501,   207,   343,   138,  -135,  -135,
      20,    72,    76,  -135,   150,   150,   150,   150,   150,   150,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,   134,   135,   145,
     146,   147,   495,   560,  -135,  -135,   171,  -135,   188,   225,
    -135,   175,   176,  -135,  -135,  -135,   192,  -135,   260,   501,
    -135,   501,   501,   144,   543,   543,  -135,   194,   -19,  -135,
     261,  -135,  -135,  -135,  -135,  -135,  -135,   278,    95,    72,
     -17,    84,  -135,   127,   501,   579,   584,  -135,  -135,  -135,
     407,   425,  -135,    42,  -135,  -135,   551,   238,   551,  -135,
     124,   309,   456,  -135,   327,   560,   203,  -135,  -135,   201,
    -135,   238,   551,  -135,  -135,   474,  -135,   358,   551,  -135,
    -135,   376,  -135
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   252,    -3,  -134,   -18,  -135,  -135,  -135,
     165,    -4,   -71,    -1,    82,    56,   119,  -135,  -135,    24,
     -33,  -135,    85,  -135,  -135,  -135,  -135,    -6,  -135
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -110
static const yytype_int16 yytable[] =
{
      29,    56,    18,    17,     6,    56,    56,    56,    56,   163,
      93,    94,    93,    94,     1,    78,    78,    56,     4,    63,
       3,    10,    11,    12,    13,    14,    15,    16,    57,     6,
     168,    61,    57,    57,    57,    57,   170,    96,    36,    37,
      97,    56,    79,    79,    57,     5,   186,    21,    19,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      56,    56,    65,    67,    69,    71,    22,   157,    57,    58,
    -109,    93,    94,  -109,    81,    23,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    57,    57,    56,
      51,   180,    61,    24,    64,    66,    68,    70,   101,   -84,
     -84,    93,    94,    72,    73,   181,    56,   184,    56,    56,
      29,    78,    78,    93,    94,    25,    57,   115,   116,   -84,
     -84,   197,    74,   -84,    26,    29,   139,   201,   152,   140,
     100,    56,    27,    57,    62,    57,    57,   171,    79,    79,
     162,    72,    73,   120,   121,  -107,   148,   188,  -107,    10,
      11,    12,    13,    14,    15,    16,   152,    38,    57,   185,
      74,    39,    29,   159,    40,   160,   161,    77,    80,   177,
     179,   -11,   -11,    95,   190,   -11,   172,    37,   147,   150,
     152,   193,    41,   152,    98,   138,   141,   142,   173,    88,
      89,    90,    91,    92,   199,   158,   152,   143,   144,   145,
     152,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    10,    11,    12,    13,    14,    15,    16,   117,
     149,   118,   119,   150,   153,   154,   120,   121,   -86,   -86,
      10,    11,    12,    13,    14,    15,    16,   117,   122,   118,
     119,   155,   123,   167,   120,   121,   -13,   -13,   -86,   -86,
     -13,   182,   -86,    37,   195,   124,   122,   -85,   -85,    20,
     123,   137,   187,   165,   166,    10,    11,    12,    13,    14,
      15,    16,   117,   151,   118,   119,   196,   -85,   -85,   120,
     121,   -85,     0,    10,    11,    12,    13,    14,    15,    16,
     117,   122,   118,   119,     0,   123,     0,   120,   121,     0,
      30,    31,    32,    33,     0,     0,   -15,   -15,   156,   122,
     -15,     0,    34,   123,    10,    11,    12,    13,    14,    15,
      16,   117,     0,   118,   119,     0,   169,     0,   120,   121,
       0,     0,    10,    11,    12,    13,    14,    15,    16,   117,
     122,   118,   119,     0,   123,     0,   120,   121,    10,    11,
      12,    13,    14,    15,    16,   -19,   -19,   191,   122,   -19,
       0,     0,   123,    10,    11,    12,    13,    14,    15,    16,
     117,     0,   118,   119,     0,   194,     0,   120,   121,     0,
       0,    10,    11,    12,    13,    14,    15,    16,   117,   122,
     118,   119,     0,   123,     0,   120,   121,   -17,   -17,     0,
       0,   -17,     0,     0,     0,     0,   200,   122,     0,     0,
       0,   123,    10,    11,    12,    13,    14,    15,    16,   117,
       0,   118,   119,     0,   202,     0,   120,   121,     0,     0,
      10,    11,    12,    13,    14,    15,    16,   117,   122,   118,
     119,     0,   123,     0,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,   122,     0,     0,     0,
     123,    10,    11,    12,    13,    14,    15,    16,   117,     0,
     118,   119,   178,     0,     0,   120,   121,     0,     0,    10,
      11,    12,    13,    14,    15,    16,   117,   122,   118,   119,
       0,   123,     0,   120,   121,     0,    42,    43,     0,     0,
       0,     0,     0,   192,     0,   122,     0,     0,     0,   123,
      44,    45,    46,    47,     0,    48,    42,    43,     0,     0,
       0,   198,    42,    43,     0,     0,     0,    49,    99,    50,
      44,    45,    46,    47,     0,    48,    44,    45,    46,    47,
       0,    48,     0,     0,   146,     0,     0,    49,     0,    50,
       0,     0,     0,    49,     0,    50,    10,    11,    12,    13,
      14,    15,    16,   117,     0,   118,   119,     0,     0,     0,
     120,   121,    82,    83,    84,    85,    86,    87,    75,    45,
      46,    47,   122,    48,     0,     0,   123,     0,    88,    89,
      90,    91,    92,    72,    73,    49,     0,     0,     0,    30,
      31,    32,    33,    88,    89,    90,    91,    92,     0,     0,
       0,    34,    74,     0,     0,     0,     0,   103,    88,    89,
      90,    91,    92,    88,    89,    90,    91,    92,    30,    31,
      32,    33,   174,     0,     0,     0,     0,   175,     0,     0,
      34,    35
};

static const yytype_int16 yycheck[] =
{
      18,    34,     6,     6,     4,    38,    39,    40,    41,   143,
      29,    30,    29,    30,     3,    48,    49,    50,     0,    37,
      35,     5,     6,     7,     8,     9,    10,    11,    34,     4,
      49,    35,    38,    39,    40,    41,    53,    50,    49,    50,
      53,    74,    48,    49,    50,    47,   180,    32,    48,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    38,    39,    40,    41,    32,   138,    74,    53,
      50,    29,    30,    53,    50,    32,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   122,
      34,    49,    96,    32,    38,    39,    40,    41,    74,    29,
      30,    29,    30,    33,    34,   176,   139,   178,   141,   142,
     128,   144,   145,    29,    30,    32,   122,    93,    94,    49,
      50,   192,    52,    53,    32,   143,    50,   198,   129,    53,
      74,   164,    35,   139,    35,   141,   142,    53,   144,   145,
     143,    33,    34,    19,    20,    50,   122,   180,    53,     5,
       6,     7,     8,     9,    10,    11,   157,    51,   164,    35,
      52,    51,   180,   139,    51,   141,   142,    48,    49,   170,
     171,    49,    50,    47,   180,    53,    49,    50,   122,    35,
     181,   182,    51,   184,    35,    47,    52,    52,   164,    39,
      40,    41,    42,    43,   195,   139,   197,    52,    52,    52,
     201,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     5,     6,     7,     8,     9,    10,    11,    12,
      49,    14,    15,    35,    49,    49,    19,    20,    29,    30,
       5,     6,     7,     8,     9,    10,    11,    12,    31,    14,
      15,    49,    35,    49,    19,    20,    49,    50,    49,    50,
      53,    13,    53,    50,    53,    48,    31,    29,    30,     7,
      35,    96,   180,   144,   145,     5,     6,     7,     8,     9,
      10,    11,    12,    48,    14,    15,   191,    49,    50,    19,
      20,    53,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    31,    14,    15,    -1,    35,    -1,    19,    20,    -1,
      39,    40,    41,    42,    -1,    -1,    49,    50,    48,    31,
      53,    -1,    51,    35,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    -1,    48,    -1,    19,    20,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      31,    14,    15,    -1,    35,    -1,    19,    20,     5,     6,
       7,     8,     9,    10,    11,    49,    50,    48,    31,    53,
      -1,    -1,    35,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    -1,    48,    -1,    19,    20,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    31,
      14,    15,    -1,    35,    -1,    19,    20,    49,    50,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    48,    31,    -1,    -1,
      -1,    35,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    -1,    48,    -1,    19,    20,    -1,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    31,    14,
      15,    -1,    35,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    31,    -1,    -1,    -1,
      35,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    47,    -1,    -1,    19,    20,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    31,    14,    15,
      -1,    35,    -1,    19,    20,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    31,    -1,    -1,    -1,    35,
      35,    36,    37,    38,    -1,    40,    21,    22,    -1,    -1,
      -1,    47,    21,    22,    -1,    -1,    -1,    52,    53,    54,
      35,    36,    37,    38,    -1,    40,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    49,    -1,    -1,    52,    -1,    54,
      -1,    -1,    -1,    52,    -1,    54,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,
      19,    20,    23,    24,    25,    26,    27,    28,    35,    36,
      37,    38,    31,    40,    -1,    -1,    35,    -1,    39,    40,
      41,    42,    43,    33,    34,    52,    -1,    -1,    -1,    39,
      40,    41,    42,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    53,    39,    40,
      41,    42,    43,    39,    40,    41,    42,    43,    39,    40,
      41,    42,    53,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    56,    35,     0,    47,     4,    57,    58,    62,
       5,     6,     7,     8,     9,    10,    11,    59,    66,    48,
      58,    32,    32,    32,    32,    32,    32,    35,    60,    61,
      39,    40,    41,    42,    51,    52,    49,    50,    51,    51,
      51,    51,    21,    22,    35,    36,    37,    38,    40,    52,
      54,    70,    71,    72,    73,    74,    75,    82,    53,    64,
      65,    66,    35,    61,    70,    74,    70,    74,    70,    74,
      70,    74,    33,    34,    52,    35,    70,    71,    75,    82,
      71,    74,    23,    24,    25,    26,    27,    28,    39,    40,
      41,    42,    43,    29,    30,    47,    50,    53,    35,    53,
      70,    74,    83,    53,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    74,    74,    12,    14,    15,
      19,    20,    31,    35,    48,    59,    61,    63,    66,    67,
      68,    69,    75,    76,    78,    79,    82,    65,    47,    50,
      53,    52,    52,    52,    52,    52,    49,    70,    74,    49,
      35,    48,    68,    49,    49,    49,    48,    67,    70,    74,
      74,    74,    59,    60,    80,    71,    71,    49,    49,    48,
      53,    53,    49,    74,    53,    53,    47,    68,    47,    68,
      49,    67,    13,    77,    67,    35,    60,    69,    75,    81,
      82,    48,    47,    68,    48,    53,    77,    67,    47,    68,
      48,    67,    48
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
#line 126 "pjava.y"
    {(yyval.isl)=insert_static_list((yyvsp[(1) - (2)].isl), (yyvsp[(2) - (2)].isl));}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 127 "pjava.y"
    {(yyval.isl)=insert_static_list(NULL, (yyvsp[(1) - (1)].isl)); isl=(yyval.isl);}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 130 "pjava.y"
    {(yyval.isl)=insert_d_static((yyvsp[(2) - (2)].id));}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 131 "pjava.y"
    {(yyval.isl)=insert_m_static((yyvsp[(1) - (1)].im));}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 134 "pjava.y"
    {(yyval.id)=insert_declaration(line, (yyvsp[(2) - (3)].ial),(yyvsp[(1) - (3)].it));}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 137 "pjava.y"
    {(yyval.ial)=insert_attribution_list((yyvsp[(1) - (3)].ial), (yyvsp[(3) - (3)].ia));}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 138 "pjava.y"
    {(yyval.ial)=insert_attribution_list(NULL, (yyvsp[(1) - (1)].ia));}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 139 "pjava.y"
    {(yyval.ial)=insert_attribution_list(NULL, insert_attribution_exp(line, (yyvsp[(1) - (1)].var), NULL, '='));}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 142 "pjava.y"
    {(yyval.ia)=insert_attribution_exp(line, (yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].ie), '=');}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 143 "pjava.y"
    {(yyval.ia)=insert_attribution_b_exp(line, (yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].ibe), '=');}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 144 "pjava.y"
    {(yyval.ia)=insert_attribution_exp(line, (yyvsp[(1) - (4)].var), (yyvsp[(4) - (4)].ie), '+');}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 145 "pjava.y"
    {(yyval.ia)=insert_attribution_b_exp(line, (yyvsp[(1) - (4)].var), (yyvsp[(4) - (4)].ibe), '+');}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 146 "pjava.y"
    {(yyval.ia)=insert_attribution_exp(line, (yyvsp[(1) - (4)].var), (yyvsp[(4) - (4)].ie), '-');}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 147 "pjava.y"
    {(yyval.ia)=insert_attribution_b_exp(line, (yyvsp[(1) - (4)].var), (yyvsp[(4) - (4)].ibe), '-');}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 148 "pjava.y"
    {(yyval.ia)=insert_attribution_exp(line, (yyvsp[(1) - (4)].var), (yyvsp[(4) - (4)].ie), '/');}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 149 "pjava.y"
    {(yyval.ia)=insert_attribution_b_exp(line, (yyvsp[(1) - (4)].var), (yyvsp[(4) - (4)].ibe), '/');}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 150 "pjava.y"
    {(yyval.ia)=insert_attribution_exp(line, (yyvsp[(1) - (4)].var), (yyvsp[(4) - (4)].ie), '*');}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 151 "pjava.y"
    {(yyval.ia)=insert_attribution_b_exp(line, (yyvsp[(1) - (4)].var), (yyvsp[(4) - (4)].ibe), '*');}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 154 "pjava.y"
    {(yyval.im)=insert_method(line, (yyvsp[(2) - (9)].it), (yyvsp[(3) - (9)].var), (yyvsp[(5) - (9)].iarl), (yyvsp[(8) - (9)].istl));}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 155 "pjava.y"
    {(yyval.im)=insert_method(line, (yyvsp[(2) - (8)].it), (yyvsp[(3) - (8)].var), (yyvsp[(5) - (8)].iarl), NULL);}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 156 "pjava.y"
    {(yyval.im)=insert_method(line, (yyvsp[(2) - (8)].it), (yyvsp[(3) - (8)].var), NULL, (yyvsp[(7) - (8)].istl));}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 157 "pjava.y"
    {(yyval.im)=insert_method(line, (yyvsp[(2) - (7)].it), (yyvsp[(3) - (7)].var), NULL, NULL);}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 160 "pjava.y"
    {(yyval.ir)=insert_return_void(line);}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 161 "pjava.y"
    {(yyval.ir)=insert_return_b_exp((yyvsp[(2) - (3)].ibe), line);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 162 "pjava.y"
    {(yyval.ir)=insert_return_exp((yyvsp[(2) - (3)].ie), line);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 165 "pjava.y"
    {(yyval.iarl)=insert_argument_list((yyvsp[(1) - (3)].iarl), (yyvsp[(3) - (3)].iar));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 166 "pjava.y"
    {(yyval.iarl)=insert_argument_list(NULL, (yyvsp[(1) - (1)].iar));}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 169 "pjava.y"
    {(yyval.iar)=insert_argument((yyvsp[(1) - (2)].it), (yyvsp[(2) - (2)].var));}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 172 "pjava.y"
    {(yyval.it)=is_INT;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 173 "pjava.y"
    {(yyval.it)=is_STRING;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 174 "pjava.y"
    {(yyval.it)=is_VOID;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 175 "pjava.y"
    {(yyval.it)=is_FLOAT;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 176 "pjava.y"
    {(yyval.it)=is_DOUBLE;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 177 "pjava.y"
    {(yyval.it)=is_CHAR;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 178 "pjava.y"
    {(yyval.it)=is_BOOLEAN;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 179 "pjava.y"
    {(yyval.it)=is_INT;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 180 "pjava.y"
    {(yyval.it)=is_STRING;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 181 "pjava.y"
    {(yyval.it)=is_FLOAT;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 182 "pjava.y"
    {(yyval.it)=is_DOUBLE;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 183 "pjava.y"
    {(yyval.it)=is_CHAR;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 184 "pjava.y"
    {(yyval.it)=is_BOOLEAN;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 187 "pjava.y"
    {insert_statement_list((yyvsp[(1) - (2)].istl),(yyvsp[(2) - (2)].istl));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 188 "pjava.y"
    {insert_statement_list(NULL, (yyvsp[(1) - (1)].istl));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 191 "pjava.y"
    {(yyval.istl)=insert_d_statement((yyvsp[(1) - (1)].id));}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 192 "pjava.y"
    {(yyval.istl)=insert_a_statement((yyvsp[(1) - (2)].ia));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 193 "pjava.y"
    {(yyval.istl)=insert_p_statement((yyvsp[(1) - (2)].ip));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 194 "pjava.y"
    {(yyval.istl)=insert_i_statement((yyvsp[(1) - (1)].ii));}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 195 "pjava.y"
    {(yyval.istl)=insert_w_statement((yyvsp[(1) - (1)].iw));}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 196 "pjava.y"
    {(yyval.istl)=insert_f_statement((yyvsp[(1) - (1)].isf));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 197 "pjava.y"
    {(yyval.istl)=insert_mc_statement((yyvsp[(1) - (2)].imc));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 198 "pjava.y"
    {(yyval.istl)=insert_r_statement((yyvsp[(1) - (1)].ir));}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 199 "pjava.y"
    {(yyval.istl)=insert_inc_statement((yyvsp[(1) - (2)].iinc));}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 203 "pjava.y"
    {(yyval.ip)=insert_print(line, (yyvsp[(3) - (4)].ise), '\0');}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 204 "pjava.y"
    {(yyval.ip)=insert_print(line, (yyvsp[(3) - (4)].ise), '\n');}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 207 "pjava.y"
    {(yyval.ie)=insert_i_expression(line, (yyvsp[(1) - (1)].iie));}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 208 "pjava.y"
    {(yyval.ie)=insert_u_expression(line, (yyvsp[(1) - (1)].iue));}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 209 "pjava.y"
    {(yyval.ie)=insert_INT(line, (yyvsp[(1) - (1)].inum));}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 210 "pjava.y"
    {(yyval.ie)=insert_DOUBLE(line, (yyvsp[(1) - (1)].dnum));}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 211 "pjava.y"
    {(yyval.ie)=insert_CHAR(line,(yyvsp[(1) - (1)].vchar));}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 214 "pjava.y"
    {(yyval.ise)=insert_s_expression_exp((yyvsp[(1) - (1)].ie));}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 215 "pjava.y"
    {(yyval.ise)=insert_s_expression_var((yyvsp[(1) - (1)].var));}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 216 "pjava.y"
    {(yyval.ise)=insert_s_expression_mc((yyvsp[(1) - (1)].imc));}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 217 "pjava.y"
    {(yyval.ise)=insert_s_expression_inc((yyvsp[(1) - (1)].iinc));}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 220 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ise), is_PLUS, (yyvsp[(3) - (3)].ise));}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 221 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ise), is_MINUS, (yyvsp[(3) - (3)].ise));}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 222 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ise), is_MULT, (yyvsp[(3) - (3)].ise));}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 223 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ise), is_DIVIDE, (yyvsp[(3) - (3)].ise));}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 224 "pjava.y"
    {(yyval.iie)=insert_infix_expression((yyvsp[(1) - (3)].ise), is_MOD, (yyvsp[(3) - (3)].ise));}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 227 "pjava.y"
    {(yyval.iue)=insert_unary_expression_neg((yyvsp[(2) - (2)].ise));}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 228 "pjava.y"
    {(yyval.iue)=insert_unary_expression_par((yyvsp[(2) - (3)].ise));}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 231 "pjava.y"
    {(yyval.ibe)=insert_b_infix_expression(line, (yyvsp[(1) - (3)].ibe), is_AND, (yyvsp[(3) - (3)].ibe));}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 232 "pjava.y"
    {(yyval.ibe)=insert_b_infix_expression(line, (yyvsp[(1) - (3)].ibe), is_OR, (yyvsp[(3) - (3)].ibe));}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 233 "pjava.y"
    {(yyval.ibe)=insert_b_not_expression(line, (yyvsp[(2) - (2)].ibe));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 234 "pjava.y"
    {(yyval.ibe)=insert_comparison(line, (yyvsp[(1) - (3)].ise), is_EQUALS, (yyvsp[(3) - (3)].ise));}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 235 "pjava.y"
    {(yyval.ibe)=insert_comparison(line, (yyvsp[(1) - (3)].ise), is_DIFERENT, (yyvsp[(3) - (3)].ise));}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 236 "pjava.y"
    {(yyval.ibe)=insert_comparison(line, (yyvsp[(1) - (3)].ise), is_GREATER, (yyvsp[(3) - (3)].ise));}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 237 "pjava.y"
    {(yyval.ibe)=insert_comparison(line, (yyvsp[(1) - (3)].ise), is_LESSER, (yyvsp[(3) - (3)].ise));}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 238 "pjava.y"
    {(yyval.ibe)=insert_comparison(line, (yyvsp[(1) - (3)].ise), is_GREATEQ, (yyvsp[(3) - (3)].ise));}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 239 "pjava.y"
    {(yyval.ibe)=insert_comparison(line, (yyvsp[(1) - (3)].ise), is_LESSEQ, (yyvsp[(3) - (3)].ise));}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 240 "pjava.y"
    {(yyval.ibe)=insert_b_bool_expression(line, '1');}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 241 "pjava.y"
    {(yyval.ibe)=insert_b_bool_expression(line, '0');}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 242 "pjava.y"
    {(yyval.ibe)=insert_b_expression_var(line, (yyvsp[(1) - (1)].var));}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 243 "pjava.y"
    {(yyval.ibe)=insert_b_mc_expression(line,(yyvsp[(1) - (1)].imc));}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 244 "pjava.y"
    {(yyval.ibe)=insert_b_expression_inc((yyvsp[(1) - (1)].iinc));}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 247 "pjava.y"
    {(yyval.iinc)=insert_increment(line, (yyvsp[(1) - (2)].var), '+');}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 248 "pjava.y"
    {(yyval.iinc)=insert_increment(line, (yyvsp[(1) - (2)].var), '-');}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 251 "pjava.y"
    {(yyval.ii)=insert_if(line, (yyvsp[(3) - (7)].ibe), (yyvsp[(6) - (7)].istl), NULL);}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 252 "pjava.y"
    {(yyval.ii)=insert_if(line, (yyvsp[(3) - (5)].ibe), (yyvsp[(5) - (5)].istl), NULL);}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 253 "pjava.y"
    {(yyval.ii)=insert_if(line, (yyvsp[(3) - (8)].ibe), (yyvsp[(6) - (8)].istl), (yyvsp[(8) - (8)].iiel));}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 254 "pjava.y"
    {(yyval.ii)=insert_if(line, (yyvsp[(3) - (6)].ibe), (yyvsp[(5) - (6)].istl), (yyvsp[(6) - (6)].iiel));}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 257 "pjava.y"
    {(yyval.iiel)=insert_else(line, (yyvsp[(3) - (4)].istl));}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 258 "pjava.y"
    {(yyval.iiel)=insert_else(line, (yyvsp[(2) - (2)].istl));}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 261 "pjava.y"
    {(yyval.iw)=insert_while(line, (yyvsp[(3) - (7)].ibe), (yyvsp[(6) - (7)].istl));}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 262 "pjava.y"
    {(yyval.iw)=insert_while(line, (yyvsp[(3) - (5)].ibe), (yyvsp[(5) - (5)].istl));}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 265 "pjava.y"
    {(yyval.isf)=insert_for(line, (yyvsp[(3) - (10)].istl), (yyvsp[(4) - (10)].ibe), (yyvsp[(6) - (10)].istl), (yyvsp[(9) - (10)].istl));}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 266 "pjava.y"
    {(yyval.isf)=insert_for(line, (yyvsp[(3) - (8)].istl), (yyvsp[(4) - (8)].ibe), (yyvsp[(6) - (8)].istl), (yyvsp[(8) - (8)].istl));}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 269 "pjava.y"
    {(yyval.istl)=insert_as_statement((yyvsp[(1) - (2)].ial));}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 270 "pjava.y"
    {(yyval.istl)=insert_d_statement((yyvsp[(1) - (1)].id));}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 273 "pjava.y"
    {(yyval.istl)=insert_as_statement((yyvsp[(1) - (1)].ial));}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 274 "pjava.y"
    {(yyval.istl)=insert_p_statement((yyvsp[(1) - (1)].ip));}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 275 "pjava.y"
    {(yyval.istl)=insert_mc_statement((yyvsp[(1) - (1)].imc));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 276 "pjava.y"
    {(yyval.istl)=insert_inc_statement((yyvsp[(1) - (1)].iinc));}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 279 "pjava.y"
    {(yyval.imc)=insert_method_call(line, (yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].imal));}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 280 "pjava.y"
    {(yyval.imc)=insert_method_call(line, (yyvsp[(1) - (3)].var), NULL);}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 283 "pjava.y"
    {(yyval.imal)=insert_method_arg_list((yyvsp[(1) - (3)].imal), insert_method_arg_exp(line, (yyvsp[(3) - (3)].ie)));}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 284 "pjava.y"
    {(yyval.imal)=insert_method_arg_list((yyvsp[(1) - (3)].imal), insert_method_arg_b_exp(line, (yyvsp[(3) - (3)].ibe)));}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 285 "pjava.y"
    {(yyval.imal)=insert_method_arg_exp(line, (yyvsp[(1) - (1)].ie));}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 286 "pjava.y"
    {(yyval.imal)=insert_method_arg_b_exp(line, (yyvsp[(1) - (1)].ibe));}
    break;



/* Line 1455 of yacc.c  */
#line 2483 "y.tab.c"
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
#line 289 "pjava.y"

int main(int argc, char **argv)
{
	line = 1;
	errors = 0;
	int parsing = yyparse();
	if(!parsing){
		prog_environment=semantic_analysis(isl);
	    if(errors)
		    printf("This program could not compile because there are %d errors.\n", errors);
	    else
	    {
	        translate(isl, prog_environment);
	        show_program(isl);	//mostra a árvore que acabou de ser construida
	        show_environments();
	    }
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
	for(aux=table; aux; aux=aux->next)
		printf("symbol %s, type %s %s (offset %d)\n", aux->name, type_to_string(aux->type), sym_type_to_string(aux->stype), aux->offset); 
}

void show_environments(){
    environment_list* aux1;
    printf("global\n");
    printf("------------\n");
    show_table(prog_environment->global);
    printf("------------\n");
    for(aux1 = prog_environment->procs; aux1; aux1=aux1->next){
        printf("%s\n",aux1->name);
        printf("------------\n");
        show_table(aux1->locals);
        printf("------------\n");
    }
}


