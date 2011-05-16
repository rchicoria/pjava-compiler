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

void show_table(table_element*);

/*is_atribuicao_list* myprogram;*/
is_static_list* isl;
prog_env* prog_environment;
#line 16 "pjava.y"
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
#line 55 "y.tab.c"
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
    0,    1,    1,    2,    2,    5,    4,    4,    3,    3,
    6,    6,    6,    6,   12,   12,   11,    7,    7,    7,
    7,    7,    7,    7,   15,   15,   14,   14,   14,   14,
   14,   14,   13,   13,    8,    8,    8,    8,    9,    9,
    9,    9,    9,    9,   10,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   17,   17,   18,   18,
   19,   19,   20,   20,
};
static const short yylen[] = {                            2,
    5,    2,    1,    2,    1,    3,    3,    1,    1,    3,
    9,    8,    8,    7,    3,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    2,    1,    1,    2,    1,    1,
    1,    1,    5,    5,    1,    1,    1,    1,    3,    3,
    3,    3,    3,    3,    2,    3,    3,    2,    3,    3,
    3,    3,    3,    3,    1,    1,    7,    5,    7,    5,
   10,    8,    2,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    3,    5,   18,   19,
   20,   21,   22,   23,   24,    4,    0,    1,    2,    0,
    8,    0,    0,    0,    6,    0,   38,   37,    0,    0,
   35,   36,    0,    0,   16,    0,    0,    7,   45,    0,
    0,    0,    0,    0,   17,    0,    0,   43,   39,    0,
   40,   41,   42,    0,    0,    0,    0,    0,   14,    0,
   27,    0,   29,   26,    0,   30,   31,   32,   15,    0,
    0,    0,    0,    0,    0,   28,   13,   25,   12,    0,
   55,   56,    0,    0,    0,    0,    0,   64,    0,    0,
    0,   11,   48,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   63,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   46,   47,    0,   58,    0,   60,    0,
   33,   34,    0,    0,    0,   57,   59,    0,    0,   62,
    0,   61,
};
static const short yydgoto[] = {                          2,
    6,    7,   60,   22,   61,    8,   62,   84,   31,   32,
   35,   36,   63,   64,   65,   85,   66,   67,   68,   89,
};
static const short yysindex[] = {                      -248,
 -273,    0, -106, -223, -132,  -96,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -244,    0,    0,  -30,
    0,   -6,   -3,  -40,    0, -239,    0,    0,   -3,  190,
    0,    0,  -59, -213,    0,  -28,   11,    0,    0,  -41,
    2,   -3,   -3,   35,    0, -132,  -46,    0,    0, -270,
    0,    0,    0,   41,   42,   43,   45,   56,    0,   38,
    0, -239,    0,    0,   61,    0,    0,    0,    0,   76,
  -33,  -33, -172,   -3,   -3,    0,    0,    0,    0,   91,
    0,    0,  -33,   12,   -7,   -4,    7,    0,  -33,  116,
  146,    0,    0,   -3,   -3,   -3,   -3,   -3,   -3,  -33,
  -33, -117,  -90,    0,  -56,   39,   44,  190,  190,  190,
  190,  190,  190,    0,    0,  121,    0,  121,    0,   -3,
    0,    0,  106,  136,  155,    0,    0,  -55,  121,    0,
  179,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   25,
    0,    0,    0,    0,    0,    0,    8,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -36,  -34,  -15,
  -13,  -11,   -9,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
    0,   95,   48,   29,    3,    0,   34,   20,    0,    0,
   59,    0,    0,  -24,  -43,   37,    0,    0,    0,    0,
};
#define YYTABLESIZE 463
static const short yytable[] = {                         83,
   33,   48,  120,   29,   49,  116,   50,   16,    1,   24,
    3,   29,   47,   27,   28,   46,    4,   44,   44,   44,
   44,   44,   49,   44,   50,   51,   80,   52,   18,   53,
   23,   54,  118,  102,    5,   44,  103,   26,   17,   20,
   78,   29,   30,   51,   37,   52,   50,   53,   39,   54,
   26,    9,   25,   42,   40,   78,   41,   34,   43,   49,
   51,   52,   53,   44,   21,  104,    9,  129,   10,   39,
   45,   23,  123,   38,  124,   88,   70,  117,  119,   34,
   71,   72,   73,   10,   74,  131,    9,   10,   11,   12,
   13,   14,   15,   90,   91,   75,   76,  121,   78,   78,
   19,   87,  122,  130,   69,    0,   78,    0,   86,   21,
    0,   37,    0,  108,  109,  110,  111,  112,  113,   93,
   21,    0,    0,    0,    0,  105,    9,   10,   11,   12,
   13,   14,   15,    0,    0,    0,  114,  115,    0,  125,
    0,    9,   10,   11,   12,   13,   14,   15,   54,   55,
   56,    0,    0,    0,   57,   58,  106,   42,   40,   59,
   41,    5,   43,    0,    0,    0,   37,    0,    9,   10,
   11,   12,   13,   14,   15,   54,   55,   56,    0,    0,
    0,   57,   58,    0,    0,   77,  107,   42,   40,    0,
   41,    0,   43,   37,    0,  128,   42,   40,    0,   41,
   79,   43,    0,    9,   10,   11,   12,   13,   14,   15,
   54,   55,   56,    0,    0,   92,   57,   58,    9,   10,
   11,   12,   13,   14,   15,  100,  101,    0,   37,    0,
  126,   42,   40,    0,   41,    0,   43,    0,    0,    0,
   81,   82,   27,   28,    0,   49,   49,   50,   50,    0,
   27,   28,   44,   44,   44,   44,   44,   44,   44,   44,
  127,    0,    0,    0,    0,    0,   51,   51,   52,   52,
   53,   53,   54,   54,  100,  101,    0,  100,  101,    0,
   27,   28,    0,    0,    0,   27,   28,   94,   95,   96,
   97,   98,   99,    9,   10,   11,   12,   13,   14,   15,
   54,   55,   56,  132,    0,    0,   57,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   37,    9,
   10,   11,   12,   13,   14,   15,   54,   55,   56,    0,
    0,    0,   57,   58,    9,   10,   11,   12,   13,   14,
   15,   54,   55,   56,   37,    0,    0,   57,   58,    9,
   10,   11,   12,   13,   14,   15,   54,   55,   56,   37,
    0,    0,   57,   58,    9,   10,   11,   12,   13,   14,
   15,   54,   55,   56,   37,    0,    0,   57,   58,    9,
   10,   11,   12,   13,   14,   15,   54,   55,   56,   37,
    0,    0,   57,   58,    9,   10,   11,   12,   13,   14,
   15,   54,   55,   56,   37,    0,    0,   57,   58,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    9,   10,   11,
   12,   13,   14,   15,   54,   55,   56,    0,    0,    0,
   57,   58,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   37,
};
static const short yycheck[] = {                         33,
   41,   43,   59,   45,   41,  123,   41,    5,  257,   40,
  284,   45,   41,  284,  285,   44,  123,   41,   42,   43,
   44,   45,   59,   47,   59,   41,   70,   41,  125,   41,
   61,   41,  123,   41,  258,   59,   41,   44,    5,  284,
   65,   45,   23,   59,  284,   59,   45,   59,   29,   59,
   44,   44,   59,   42,   43,   80,   45,   24,   47,   40,
   41,   42,   43,  123,   17,   59,   59,  123,   44,   50,
  284,   61,  116,   26,  118,   73,  123,  102,  103,   46,
   40,   40,   40,   59,   40,  129,  259,  260,  261,  262,
  263,  264,  265,   74,   75,   40,   59,   59,  123,  124,
    6,   73,   59,  128,   46,   -1,  131,   -1,   72,   62,
   -1,  284,   -1,   94,   95,   96,   97,   98,   99,   83,
   73,   -1,   -1,   -1,   -1,   89,  259,  260,  261,  262,
  263,  264,  265,   -1,   -1,   -1,  100,  101,   -1,  120,
   -1,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,   -1,   -1,   -1,  272,  273,   41,   42,   43,  125,
   45,  258,   47,   -1,   -1,   -1,  284,   -1,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,   -1,   -1,
   -1,  272,  273,   -1,   -1,  125,   41,   42,   43,   -1,
   45,   -1,   47,  284,   -1,   41,   42,   43,   -1,   45,
  125,   47,   -1,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,   -1,   -1,  125,  272,  273,  259,  260,
  261,  262,  263,  264,  265,  282,  283,   -1,  284,   -1,
  125,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  274,  275,  284,  285,   -1,  282,  283,  282,  283,   -1,
  284,  285,  276,  277,  278,  279,  280,  281,  282,  283,
  125,   -1,   -1,   -1,   -1,   -1,  282,  283,  282,  283,
  282,  283,  282,  283,  282,  283,   -1,  282,  283,   -1,
  284,  285,   -1,   -1,   -1,  284,  285,  276,  277,  278,
  279,  280,  281,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  125,   -1,   -1,  272,  273,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,   -1,
   -1,   -1,  272,  273,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  284,   -1,   -1,  272,  273,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  284,
   -1,   -1,  272,  273,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  284,   -1,   -1,  272,  273,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  284,
   -1,   -1,  272,  273,  259,  260,  261,  262,  263,  264,
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
#line 202 "pjava.y"
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
	for(aux=table; aux; aux=aux->next)
		printf("symbol %s, type %s\n", aux->name, typeToString(aux->type));
}
#line 439 "y.tab.c"

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
#line 97 "pjava.y"
	{yyval.isl=insert_static_list(yystack.l_mark[-1].isl, yystack.l_mark[0].isl);}
break;
case 3:
#line 98 "pjava.y"
	{yyval.isl=insert_static_list(NULL, yystack.l_mark[0].isl); isl=yyval.isl;}
break;
case 4:
#line 101 "pjava.y"
	{yyval.isl=insert_d_static(yystack.l_mark[0].id);}
break;
case 5:
#line 102 "pjava.y"
	{yyval.isl=insert_m_static(yystack.l_mark[0].im);}
break;
case 6:
#line 105 "pjava.y"
	{yyval.id=insert_declaracao(line, yystack.l_mark[-1].ial,yystack.l_mark[-2].it);}
break;
case 7:
#line 108 "pjava.y"
	{yyval.ial=insert_atribuicao_list(yystack.l_mark[-2].ial, yystack.l_mark[0].ia);}
break;
case 8:
#line 109 "pjava.y"
	{yyval.ial=insert_atribuicao_list(NULL, yystack.l_mark[0].ia);}
break;
case 9:
#line 112 "pjava.y"
	{yyval.ia=insert_atributo(line, yystack.l_mark[0].var, NULL);}
break;
case 10:
#line 113 "pjava.y"
	{yyval.ia=insert_atributo(line, yystack.l_mark[-2].var, yystack.l_mark[0].ie);}
break;
case 11:
#line 116 "pjava.y"
	{yyval.im=insert_metodo(line, yystack.l_mark[-7].it, yystack.l_mark[-6].var, yystack.l_mark[-4].iarl, yystack.l_mark[-1].istl);}
break;
case 12:
#line 117 "pjava.y"
	{yyval.im=insert_metodo(line, yystack.l_mark[-6].it, yystack.l_mark[-5].var, yystack.l_mark[-3].iarl, NULL);}
break;
case 13:
#line 118 "pjava.y"
	{yyval.im=insert_metodo(line, yystack.l_mark[-6].it, yystack.l_mark[-5].var, NULL, yystack.l_mark[-1].istl);}
break;
case 14:
#line 119 "pjava.y"
	{yyval.im=insert_metodo(line, yystack.l_mark[-5].it, yystack.l_mark[-4].var, NULL, NULL);}
break;
case 15:
#line 122 "pjava.y"
	{yyval.iarl=insert_argumento_list(yystack.l_mark[-2].iarl, yystack.l_mark[0].iar);}
break;
case 16:
#line 123 "pjava.y"
	{yyval.iarl=insert_argumento_list(NULL, yystack.l_mark[0].iar);}
break;
case 17:
#line 126 "pjava.y"
	{yyval.iar=insert_argumento(yystack.l_mark[-1].it, yystack.l_mark[0].var);}
break;
case 18:
#line 129 "pjava.y"
	{yyval.it=is_INT;}
break;
case 19:
#line 130 "pjava.y"
	{yyval.it=is_STRING;}
break;
case 20:
#line 131 "pjava.y"
	{yyval.it=is_VOID;}
break;
case 21:
#line 132 "pjava.y"
	{yyval.it=is_FLOAT;}
break;
case 22:
#line 133 "pjava.y"
	{yyval.it=is_DOUBLE;}
break;
case 23:
#line 134 "pjava.y"
	{yyval.it=is_BOOLEAN;}
break;
case 24:
#line 135 "pjava.y"
	{yyval.it=is_CHAR;}
break;
case 25:
#line 138 "pjava.y"
	{insert_statement_list(yystack.l_mark[-1].istl,yystack.l_mark[0].istl);}
break;
case 26:
#line 139 "pjava.y"
	{insert_statement_list(NULL, yystack.l_mark[0].istl);}
break;
case 27:
#line 142 "pjava.y"
	{yyval.istl=insert_d_statement(yystack.l_mark[0].id);}
break;
case 28:
#line 143 "pjava.y"
	{yyval.istl=insert_a_statement(yystack.l_mark[-1].ia);}
break;
case 29:
#line 144 "pjava.y"
	{yyval.istl=insert_p_statement(yystack.l_mark[0].ip);}
break;
case 30:
#line 145 "pjava.y"
	{yyval.istl=insert_i_statement(yystack.l_mark[0].ii);}
break;
case 31:
#line 146 "pjava.y"
	{yyval.istl=insert_w_statement(yystack.l_mark[0].iw);}
break;
case 32:
#line 147 "pjava.y"
	{yyval.istl=insert_f_statement(yystack.l_mark[0].isf);}
break;
case 33:
#line 151 "pjava.y"
	{yyval.ip=insert_print(line, yystack.l_mark[-2].ie, '\0');}
break;
case 34:
#line 152 "pjava.y"
	{yyval.ip=insert_print(line, yystack.l_mark[-2].ie, '\n');}
break;
case 35:
#line 155 "pjava.y"
	{yyval.ie=insert_i_expression(line, yystack.l_mark[0].iie);}
break;
case 36:
#line 156 "pjava.y"
	{yyval.ie=insert_u_expression(line, yystack.l_mark[0].iue);}
break;
case 37:
#line 157 "pjava.y"
	{yyval.ie=insert_NUMBER(line, yystack.l_mark[0].num);}
break;
case 38:
#line 158 "pjava.y"
	{yyval.ie=insert_VAR(line, yystack.l_mark[0].var);}
break;
case 39:
#line 161 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_PLUS, yystack.l_mark[0].ie);}
break;
case 40:
#line 162 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_MINUS, yystack.l_mark[0].ie);}
break;
case 41:
#line 163 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_MULT, yystack.l_mark[0].ie);}
break;
case 42:
#line 164 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_DIVIDE, yystack.l_mark[0].ie);}
break;
case 43:
#line 165 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_PLUS, insert_NUMBER(line, 1));}
break;
case 44:
#line 166 "pjava.y"
	{yyval.iie=insert_infix_expression(yystack.l_mark[-2].ie, is_MINUS, insert_NUMBER(line, 1));}
break;
case 45:
#line 169 "pjava.y"
	{yyval.iue=insert_unary_expression(yystack.l_mark[0].ie);}
break;
case 46:
#line 172 "pjava.y"
	{yyval.ibe=insert_b_i_expressao(line, yystack.l_mark[-2].ibe, is_AND, yystack.l_mark[0].ibe);}
break;
case 47:
#line 173 "pjava.y"
	{yyval.ibe=insert_b_i_expressao(line, yystack.l_mark[0].ibe, is_OR, yystack.l_mark[0].ibe);}
break;
case 48:
#line 174 "pjava.y"
	{yyval.ibe=insert_b_n_expressao(line, yystack.l_mark[0].ibe);}
break;
case 49:
#line 175 "pjava.y"
	{yyval.ibe=insert_comparacao(line, yystack.l_mark[-2].ie, is_EQUALS, yystack.l_mark[0].ie);}
break;
case 50:
#line 176 "pjava.y"
	{yyval.ibe=insert_comparacao(line, yystack.l_mark[-2].ie, is_DIFERENT, yystack.l_mark[0].ie);}
break;
case 51:
#line 177 "pjava.y"
	{yyval.ibe=insert_comparacao(line, yystack.l_mark[-2].ie, is_GREATER, yystack.l_mark[0].ie);}
break;
case 52:
#line 178 "pjava.y"
	{yyval.ibe=insert_comparacao(line, yystack.l_mark[-2].ie, is_LESSER, yystack.l_mark[0].ie);}
break;
case 53:
#line 179 "pjava.y"
	{yyval.ibe=insert_comparacao(line, yystack.l_mark[-2].ie, is_GREATEQ, yystack.l_mark[0].ie);}
break;
case 54:
#line 180 "pjava.y"
	{yyval.ibe=insert_comparacao(line, yystack.l_mark[-2].ie, is_LESSEQ, yystack.l_mark[0].ie);}
break;
case 55:
#line 181 "pjava.y"
	{yyval.ibe=insert_b_tf_expressao(line, '1');}
break;
case 56:
#line 182 "pjava.y"
	{yyval.ibe=insert_b_tf_expressao(line, '0');}
break;
case 57:
#line 185 "pjava.y"
	{yyval.ii=insert_if(line, yystack.l_mark[-4].ibe, yystack.l_mark[-1].istl);}
break;
case 58:
#line 186 "pjava.y"
	{yyval.ii=insert_if(line, yystack.l_mark[-2].ibe, yystack.l_mark[0].istl);}
break;
case 59:
#line 189 "pjava.y"
	{yyval.iw=insert_while(line, yystack.l_mark[-4].ibe, yystack.l_mark[-1].istl);}
break;
case 60:
#line 190 "pjava.y"
	{yyval.iw=insert_while(line, yystack.l_mark[-2].ibe, yystack.l_mark[0].istl);}
break;
case 61:
#line 193 "pjava.y"
	{yyval.isf=insert_for(line, yystack.l_mark[-7].istl, yystack.l_mark[-6].ibe, yystack.l_mark[-4].ie, yystack.l_mark[-1].istl);}
break;
case 62:
#line 194 "pjava.y"
	{yyval.isf=insert_for(line, yystack.l_mark[-5].istl, yystack.l_mark[-4].ibe, yystack.l_mark[-2].ie, yystack.l_mark[0].istl);}
break;
case 63:
#line 197 "pjava.y"
	{yyval.istl=insert_as_statement(yystack.l_mark[-1].ial);}
break;
case 64:
#line 198 "pjava.y"
	{yyval.istl=insert_d_statement(yystack.l_mark[0].id);}
break;
#line 901 "y.tab.c"
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
