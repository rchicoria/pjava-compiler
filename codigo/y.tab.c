#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20100610

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "pjava.y"
#include "structures.h"
#include "functions.h"
#include "shows.h"
#include <stdio.h>
#include "symbol_table.h"
#include "semantic.h"

/*is_atribuicao_list* myprogram;*/
is_static_list* isl;
prog_env* prog_environment;
#line 14 "pjava.y"
typedef union{
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
	char* var;
	is_if* ii;
	is_for* isf;
} YYSTYPE;
#line 53 "y.tab.c"
/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

extern int YYPARSE_DECL();
extern int YYLEX_DECL();

#define CLASS 257
#define STATIC 258
#define INT 259
#define STRING 260
#define VOID 261
#define FLOAT 262
#define DOUBLE 263
#define BOOLEAN 264
#define CHAR 265
#define IF 266
#define WHILE 267
#define FOR 268
#define DO 269
#define SWITCH 270
#define CASE 271
#define PRINT 272
#define PRINTLN 273
#define TRUE 274
#define FALSE 275
#define EQUALS 276
#define DIFERENT 277
#define GREATER 278
#define LESSER 279
#define GREATEQ 280
#define LESSEQ 281
#define AND 282
#define OR 283
#define VAR 284
#define NUMBER 285
#define UMINUS 286
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    5,    4,    4,    3,
    3,    6,    6,    6,    6,   12,   12,   11,    7,    7,
    7,    7,    7,    7,    7,   15,   15,   14,   14,   14,
   14,   14,   14,   13,   13,    8,    8,    8,    8,    9,
    9,    9,    9,    9,    9,   10,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   17,   17,   18,
   18,   19,   19,   20,   20,
};
static const short yylen[] = {                            2,
    5,    2,    1,    3,    2,    1,    3,    3,    1,    1,
    3,    9,    8,    8,    7,    3,    1,    2,    1,    1,
    1,    1,    1,    1,    1,    2,    1,    1,    2,    1,
    1,    1,    1,    5,    5,    1,    1,    1,    1,    3,
    3,    3,    3,    3,    3,    2,    3,    3,    2,    3,
    3,    3,    3,    3,    3,    1,    1,    7,    5,    7,
    5,   10,    8,    2,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    3,    6,   19,   20,
   21,   22,   23,   24,   25,    0,    0,    5,    0,    1,
    2,    0,    4,    0,    9,    0,   39,   38,    0,    0,
   36,   37,    0,    7,    0,   46,    0,    0,    0,    0,
    0,    0,   17,    0,    8,   44,   40,    0,   41,   42,
   43,    0,   18,    0,    0,    0,    0,    0,    0,    0,
   15,    0,   28,    0,   30,   27,    0,   31,   32,   33,
   16,    0,    0,    0,    0,    0,    0,   29,   14,   26,
   13,    0,   56,   57,    0,    0,    0,    0,    0,   65,
    0,    0,    0,   12,   49,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   64,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   47,   48,    0,   59,    0,
   61,    0,   34,   35,    0,    0,    0,   58,   60,    0,
    0,   63,    0,   62,
};
static const short yydgoto[] = {                          2,
    6,    7,   62,   26,   63,    8,   64,   86,   31,   32,
   43,   44,   65,   66,   67,   87,   68,   69,   70,   91,
};
static const short yysindex[] = {                      -248,
 -268,    0, -106, -223,  121,  -96,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -21,  -18,    0, -228,    0,
    0,   -3,    0,  -30,    0,   -6,    0,    0,   -3,  267,
    0,    0,  -40,    0, -214,    0,  -41,    2,   -3,   -3,
  -62, -213,    0,   46,    0,    0,    0, -270,    0,    0,
    0,   35,    0, -139,  -44,   45,   52,   65,   66,   71,
    0,   27,    0, -214,    0,    0,   61,    0,    0,    0,
    0,   76,  -33,  -33,  121,   -3,   -3,    0,    0,    0,
    0,   91,    0,    0,  -33,   12,   -7,   -4,    5,    0,
  -33,  146,  155,    0,    0,   -3,   -3,   -3,   -3,   -3,
   -3,  -33,  -33, -117,  -90,    0,  -56,   56,   57,  267,
  267,  267,  267,  267,  267,    0,    0, -165,    0, -165,
    0,   -3,    0,    0,  106,  136,  191,    0,    0,  -55,
 -165,    0,  179,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   18,    0,    0,    0,    0,
    0,    0,    0,   18,    0,    0,    0,    0,    0,   23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -23,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -36,
  -34,  -15,  -13,  -11,   -9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  112,    8,   53,    3,    0,    6,   36,    0,    0,
   73,    0,    0,  -16,  -27,  -22,    0,    0,    0,    0,
};
#define YYTABLESIZE 463
static const short yytable[] = {                         85,
   41,   46,  122,   29,   50,  118,   51,   18,    1,   33,
   19,   29,   17,   27,   28,    3,    4,   45,   45,   45,
   45,   45,   50,   45,   51,   52,   25,   53,   20,   54,
   22,   55,  120,  104,    5,   45,  105,   35,   42,   22,
   23,   29,   45,   52,   82,   53,   48,   54,   35,   55,
   80,   88,   34,   39,   37,   24,   38,   30,   40,   42,
   52,   10,   95,  106,   36,   80,   11,  131,  107,   16,
   53,   25,   47,   49,   50,   51,   10,   90,   72,  116,
  117,   11,   25,   36,   73,   78,   55,  119,  121,   54,
  125,   74,  126,    9,   10,   11,   12,   13,   14,   15,
   56,   57,   58,  133,   75,   76,   59,   60,   80,   80,
   77,   92,   93,  132,  123,  124,   80,   21,   16,    9,
   10,   11,   12,   13,   14,   15,   71,   89,    0,    0,
    0,  110,  111,  112,  113,  114,  115,    0,    0,    0,
    0,    9,   10,   11,   12,   13,   14,   15,   56,   57,
   58,    0,    0,    0,   59,   60,    0,  127,    0,   61,
    0,    5,    0,    0,    0,    0,   16,    0,    9,   10,
   11,   12,   13,   14,   15,   56,   57,   58,    0,    0,
    0,   59,   60,    0,    0,   79,  108,   39,   37,    0,
   38,    0,   40,   16,    0,  109,   39,   37,    0,   38,
   81,   40,    0,    9,   10,   11,   12,   13,   14,   15,
   56,   57,   58,    0,    0,   94,   59,   60,    9,   10,
   11,   12,   13,   14,   15,  102,  103,    0,   16,    0,
  128,  130,   39,   37,    0,   38,    0,   40,    0,    0,
   83,   84,   27,   28,    0,   50,   50,   51,   51,    0,
   27,   28,   45,   45,   45,   45,   45,   45,   45,   45,
  129,    0,    0,    0,    0,    0,   52,   52,   53,   53,
   54,   54,   55,   55,  102,  103,    0,  102,  103,    0,
   27,   28,    0,    0,    0,   27,   28,   96,   97,   98,
   99,  100,  101,    9,   10,   11,   12,   13,   14,   15,
   56,   57,   58,  134,    0,    0,   59,   60,   39,   37,
    0,   38,    0,   40,    0,    0,    0,    0,   16,    9,
   10,   11,   12,   13,   14,   15,   56,   57,   58,    0,
    0,    0,   59,   60,    9,   10,   11,   12,   13,   14,
   15,   56,   57,   58,   16,    0,    0,   59,   60,    9,
   10,   11,   12,   13,   14,   15,   56,   57,   58,   16,
    0,    0,   59,   60,    9,   10,   11,   12,   13,   14,
   15,   56,   57,   58,   16,    0,    0,   59,   60,    9,
   10,   11,   12,   13,   14,   15,    0,    0,    0,   16,
    0,    0,    0,    0,    9,   10,   11,   12,   13,   14,
   15,   56,   57,   58,   16,    0,    0,   59,   60,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   16,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    9,   10,   11,
   12,   13,   14,   15,   56,   57,   58,    0,    0,    0,
   59,   60,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   16,
};
static const short yycheck[] = {                         33,
   41,   43,   59,   45,   41,  123,   41,    5,  257,   40,
    5,   45,    5,  284,  285,  284,  123,   41,   42,   43,
   44,   45,   59,   47,   59,   41,   19,   41,  125,   41,
   61,   41,  123,   41,  258,   59,   41,   44,   33,   61,
   59,   45,   35,   59,   72,   59,   45,   59,   44,   59,
   67,   74,   59,   42,   43,  284,   45,   22,   47,   54,
  123,   44,   85,   59,   29,   82,   44,  123,   91,  284,
  284,   64,   37,   38,   39,   40,   59,   75,  123,  102,
  103,   59,   75,   48,   40,   59,   41,  104,  105,   44,
  118,   40,  120,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  131,   40,   40,  272,  273,  125,  126,
   40,   76,   77,  130,   59,   59,  133,    6,  284,  259,
  260,  261,  262,  263,  264,  265,   54,   75,   -1,   -1,
   -1,   96,   97,   98,   99,  100,  101,   -1,   -1,   -1,
   -1,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,   -1,   -1,   -1,  272,  273,   -1,  122,   -1,  125,
   -1,  258,   -1,   -1,   -1,   -1,  284,   -1,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,   -1,   -1,
   -1,  272,  273,   -1,   -1,  125,   41,   42,   43,   -1,
   45,   -1,   47,  284,   -1,   41,   42,   43,   -1,   45,
  125,   47,   -1,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,   -1,   -1,  125,  272,  273,  259,  260,
  261,  262,  263,  264,  265,  282,  283,   -1,  284,   -1,
  125,   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
  274,  275,  284,  285,   -1,  282,  283,  282,  283,   -1,
  284,  285,  276,  277,  278,  279,  280,  281,  282,  283,
  125,   -1,   -1,   -1,   -1,   -1,  282,  283,  282,  283,
  282,  283,  282,  283,  282,  283,   -1,  282,  283,   -1,
  284,  285,   -1,   -1,   -1,  284,  285,  276,  277,  278,
  279,  280,  281,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  125,   -1,   -1,  272,  273,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,  284,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,   -1,
   -1,   -1,  272,  273,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  284,   -1,   -1,  272,  273,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  284,
   -1,   -1,  272,  273,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  284,   -1,   -1,  272,  273,  259,
  260,  261,  262,  263,  264,  265,   -1,   -1,   -1,  284,
   -1,   -1,   -1,   -1,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  284,   -1,   -1,  272,  273,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,   -1,   -1,   -1,
  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  284,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"CLASS","STATIC","INT","STRING","VOID","FLOAT","DOUBLE",
"BOOLEAN","CHAR","IF","WHILE","FOR","DO","SWITCH","CASE","PRINT","PRINTLN",
"TRUE","FALSE","EQUALS","DIFERENT","GREATER","LESSER","GREATEQ","LESSEQ","AND",
"OR","VAR","NUMBER","UMINUS",
};
static const char *yyrule[] = {
"$accept : initclass",
"initclass : CLASS VAR '{' statics '}'",
"statics : statics static",
"statics : static",
"static : STATIC attribution ';'",
"static : STATIC declaration",
"static : method",
"declaration : type attributions ';'",
"attributions : attributions ',' attribution",
"attributions : attribution",
"attribution : VAR",
"attribution : VAR '=' expression",
"method : STATIC type VAR '(' args ')' '{' statements '}'",
"method : STATIC type VAR '(' args ')' '{' '}'",
"method : STATIC type VAR '(' ')' '{' statements '}'",
"method : STATIC type VAR '(' ')' '{' '}'",
"args : args ',' arg",
"args : arg",
"arg : type VAR",
"type : INT",
"type : STRING",
"type : VOID",
"type : FLOAT",
"type : DOUBLE",
"type : BOOLEAN",
"type : CHAR",
"statements : statements statement",
"statements : statement",
"statement : declaration",
"statement : attribution ';'",
"statement : print",
"statement : if",
"statement : while",
"statement : for",
"print : PRINT '(' expression ')' ';'",
"print : PRINTLN '(' expression ')' ';'",
"expression : infix_expression",
"expression : unary_expression",
"expression : NUMBER",
"expression : VAR",
"infix_expression : expression '+' expression",
"infix_expression : expression '-' expression",
"infix_expression : expression '*' expression",
"infix_expression : expression '/' expression",
"infix_expression : expression '+' '+'",
"infix_expression : expression '-' '-'",
"unary_expression : '-' expression",
"b_expression : b_expression AND b_expression",
"b_expression : b_expression OR b_expression",
"b_expression : '!' b_expression",
"b_expression : expression EQUALS expression",
"b_expression : expression DIFERENT expression",
"b_expression : expression GREATER expression",
"b_expression : expression LESSER expression",
"b_expression : expression GREATEQ expression",
"b_expression : expression LESSEQ expression",
"b_expression : TRUE",
"b_expression : FALSE",
"if : IF '(' b_expression ')' '{' statements '}'",
"if : IF '(' b_expression ')' statement",
"while : WHILE '(' b_expression ')' '{' statements '}'",
"while : WHILE '(' b_expression ')' statement",
"for : FOR '(' for_first_camp b_expression ';' expression ')' '{' statements '}'",
"for : FOR '(' for_first_camp b_expression ';' expression ')' statement",
"for_first_camp : attributions ';'",
"for_first_camp : declaration",

};
#endif
/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 201 "pjava.y"
int main()
{
	yyparse();
	show_program(isl);	//mostra a árvore que acabou de ser construida
	show_table(prog_environment->global);
    return 0;
}

int yyerror(char* s)
{
	printf("%s\n", s);
	return 0;
}

void show_table(table_element* table)
{
	table_element *aux;
	printf("\n");
	for(aux=table; aux; aux=aux->next)
		printf("symbol %s, type %s\n", aux->name, typeToString(aux->type));
}
#line 427 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (data->s_base != 0)
          ? (short *)realloc(data->s_base, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (data->l_base != 0)
          ? (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 95 "pjava.y"
	{yyval.isl=insert_static_list(yystack.l_mark[-1].isl, yystack.l_mark[0].isl);}
break;
case 3:
#line 96 "pjava.y"
	{yyval.isl=insert_static_list(NULL, yystack.l_mark[0].isl); isl=yyval.isl;}
break;
case 4:
#line 99 "pjava.y"
	{yyval.isl=insert_a_static(yystack.l_mark[-1].ia);}
break;
case 5:
#line 100 "pjava.y"
	{yyval.isl=insert_d_static(yystack.l_mark[0].id);}
break;
case 6:
#line 101 "pjava.y"
	{yyval.isl=insert_m_static(yystack.l_mark[0].im);}
break;
case 7:
#line 104 "pjava.y"
	{yyval.id=insert_declaracao(yystack.l_mark[-1].ial,yystack.l_mark[-2].it);}
break;
case 8:
#line 107 "pjava.y"
	{yyval.ial=insert_atribuicao_list(yystack.l_mark[-2].ial, yystack.l_mark[0].ia);}
break;
case 9:
#line 108 "pjava.y"
	{yyval.ial=insert_atribuicao_list(NULL, yystack.l_mark[0].ia);}
break;
case 10:
#line 111 "pjava.y"
	{yyval.ia=insert_atributo(yystack.l_mark[0].var, NULL);}
break;
case 11:
#line 112 "pjava.y"
	{yyval.ia=insert_atributo(yystack.l_mark[-2].var, yystack.l_mark[0].ie);}
break;
case 12:
#line 115 "pjava.y"
	{yyval.im=insert_metodo(yystack.l_mark[-7].it, yystack.l_mark[-6].var, yystack.l_mark[-4].iarl, yystack.l_mark[-1].istl);}
break;
case 13:
#line 116 "pjava.y"
	{yyval.im=insert_metodo(yystack.l_mark[-6].it, yystack.l_mark[-5].var, yystack.l_mark[-3].iarl, NULL);}
break;
case 14:
#line 117 "pjava.y"
	{yyval.im=insert_metodo(yystack.l_mark[-6].it, yystack.l_mark[-5].var, NULL, yystack.l_mark[-1].istl);}
break;
case 15:
#line 118 "pjava.y"
	{yyval.im=insert_metodo(yystack.l_mark[-5].it, yystack.l_mark[-4].var, NULL, NULL);}
break;
case 16:
#line 121 "pjava.y"
	{yyval.iarl=insert_argumento_list(yystack.l_mark[-2].iarl, yystack.l_mark[0].iar);}
break;
case 17:
#line 122 "pjava.y"
	{yyval.iarl=insert_argumento_list(NULL, yystack.l_mark[0].iar);}
break;
case 18:
#line 125 "pjava.y"
	{yyval.iar=insert_argumento(yystack.l_mark[-1].it, yystack.l_mark[0].var);}
break;
case 19:
#line 128 "pjava.y"
	{yyval.it=is_INT;}
break;
case 20:
#line 129 "pjava.y"
	{yyval.it=is_STRING;}
break;
case 21:
#line 130 "pjava.y"
	{yyval.it=is_VOID;}
break;
case 22:
#line 131 "pjava.y"
	{yyval.it=is_FLOAT;}
break;
case 23:
#line 132 "pjava.y"
	{yyval.it=is_DOUBLE;}
break;
case 24:
#line 133 "pjava.y"
	{yyval.it=is_BOOLEAN;}
break;
case 25:
#line 134 "pjava.y"
	{yyval.it=is_CHAR;}
break;
case 26:
#line 137 "pjava.y"
	{insert_statement_list(yystack.l_mark[-1].istl,yystack.l_mark[0].istl);}
break;
case 27:
#line 138 "pjava.y"
	{insert_statement_list(NULL, yystack.l_mark[0].istl);}
break;
case 28:
#line 141 "pjava.y"
	{yyval.istl=insert_d_statement(yystack.l_mark[0].id);}
break;
case 29:
#line 142 "pjava.y"
	{yyval.istl=insert_a_statement(yystack.l_mark[-1].ia);}
break;
case 30:
#line 143 "pjava.y"
	{yyval.istl=insert_p_statement(yystack.l_mark[0].ip);}
break;
case 31:
#line 144 "pjava.y"
	{yyval.istl=insert_i_statement(yystack.l_mark[0].ii);}
break;
case 32:
#line 145 "pjava.y"
	{yyval.istl=insert_w_statement(yystack.l_mark[0].iw);}
break;
case 33:
#line 146 "pjava.y"
	{yyval.istl=insert_f_statement(yystack.l_mark[0].isf);}
break;
case 34:
#line 150 "pjava.y"
	{yyval.ip=insert_print(yystack.l_mark[-2].ie, '\0');}
break;
case 35:
#line 151 "pjava.y"
	{yyval.ip=insert_print(yystack.l_mark[-2].ie, '\n');}
break;
case 36:
#line 154 "pjava.y"
	{yyval.ie=insert_i_expression(yystack.l_mark[0].iie);}
break;
case 37:
#line 155 "pjava.y"
	{yyval.ie=insert_u_expression(yystack.l_mark[0].iue);}
break;
case 38:
#line 156 "pjava.y"
	{yyval.ie=insert_NUMBER(yystack.l_mark[0].num);}
break;
case 39:
#line 157 "pjava.y"
	{yyval.ie=insert_VAR(yystack.l_mark[0].var);}
break;
case 40:
#line 160 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_PLUS, yystack.l_mark[0].ie);}
break;
case 41:
#line 161 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_MINUS, yystack.l_mark[0].ie);}
break;
case 42:
#line 162 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_MULT, yystack.l_mark[0].ie);}
break;
case 43:
#line 163 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_DIVIDE, yystack.l_mark[0].ie);}
break;
case 44:
#line 164 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_PLUS, insert_NUMBER(1));}
break;
case 45:
#line 165 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_MINUS, insert_NUMBER(1));}
break;
case 46:
#line 168 "pjava.y"
	{yyval.iue=insert_unary_expression(yystack.l_mark[0].ie);}
break;
case 47:
#line 171 "pjava.y"
	{yyval.ibe=insert_b_i_expressao(yystack.l_mark[-2].ibe, is_AND, yystack.l_mark[0].ibe);}
break;
case 48:
#line 172 "pjava.y"
	{yyval.ibe=insert_b_i_expressao(yystack.l_mark[0].ibe, is_OR, yystack.l_mark[0].ibe);}
break;
case 49:
#line 173 "pjava.y"
	{yyval.ibe=insert_b_n_expressao(yystack.l_mark[0].ibe);}
break;
case 50:
#line 174 "pjava.y"
	{yyval.ibe=insert_comparacao(yystack.l_mark[-2].ie, is_EQUALS, yystack.l_mark[0].ie);}
break;
case 51:
#line 175 "pjava.y"
	{yyval.ibe=insert_comparacao(yystack.l_mark[-2].ie, is_DIFERENT, yystack.l_mark[0].ie);}
break;
case 52:
#line 176 "pjava.y"
	{yyval.ibe=insert_comparacao(yystack.l_mark[-2].ie, is_GREATER, yystack.l_mark[0].ie);}
break;
case 53:
#line 177 "pjava.y"
	{yyval.ibe=insert_comparacao(yystack.l_mark[-2].ie, is_LESSER, yystack.l_mark[0].ie);}
break;
case 54:
#line 178 "pjava.y"
	{yyval.ibe=insert_comparacao(yystack.l_mark[-2].ie, is_GREATEQ, yystack.l_mark[0].ie);}
break;
case 55:
#line 179 "pjava.y"
	{yyval.ibe=insert_comparacao(yystack.l_mark[-2].ie, is_LESSEQ, yystack.l_mark[0].ie);}
break;
case 56:
#line 180 "pjava.y"
	{yyval.ibe=insert_b_tf_expressao('1');}
break;
case 57:
#line 181 "pjava.y"
	{yyval.ibe=insert_b_tf_expressao('0');}
break;
case 58:
#line 184 "pjava.y"
	{yyval.ii=insert_if(yystack.l_mark[-4].ibe, yystack.l_mark[-1].istl);}
break;
case 59:
#line 185 "pjava.y"
	{yyval.ii=insert_if(yystack.l_mark[-2].ibe, yystack.l_mark[0].istl);}
break;
case 60:
#line 188 "pjava.y"
	{yyval.iw=insert_while(yystack.l_mark[-4].ibe, yystack.l_mark[-1].istl);}
break;
case 61:
#line 189 "pjava.y"
	{yyval.iw=insert_while(yystack.l_mark[-2].ibe, yystack.l_mark[0].istl);}
break;
case 62:
#line 192 "pjava.y"
	{yyval.isf=insert_for(yystack.l_mark[-7].istl, yystack.l_mark[-6].ibe, yystack.l_mark[-4].ie, yystack.l_mark[-1].istl);}
break;
case 63:
#line 193 "pjava.y"
	{yyval.isf=insert_for(yystack.l_mark[-5].istl, yystack.l_mark[-4].ibe, yystack.l_mark[-2].ie, yystack.l_mark[0].istl);}
break;
case 64:
#line 196 "pjava.y"
	{yyval.istl=insert_as_statement(yystack.l_mark[-1].ial);}
break;
case 65:
#line 197 "pjava.y"
	{yyval.istl=insert_d_statement(yystack.l_mark[0].id);}
break;
#line 893 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
