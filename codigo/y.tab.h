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
#define FLOAT_NUM 286
#define UMINUS 287
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
	float fnum;
	char* var;
	is_if* ii;
	is_for* isf;
} YYSTYPE;
extern YYSTYPE yylval;
