%{
#include "structures.h"
#include "functions.h"
#include "shows.h"
#include <stdio.h>
#include "symbol_table.h"
#include "semantic.h"

//is_atribuicao_list* myprogram;
is_static_list* isl;
prog_env* prog_environment;
%}

%union{
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
}

%token CLASS
%token STATIC
%token INT
%token STRING
%token VOID
%token FLOAT
%token DOUBLE
%token BOOLEAN
%token CHAR
%token IF
%token WHILE
%token FOR
%token DO
%token SWITCH
%token CASE
%token PRINT
%token PRINTLN
%token TRUE
%token FALSE
%token EQUALS
%token DIFERENT
%token GREATER
%token LESSER
%token GREATEQ
%token LESSEQ
%token AND
%token OR

%token<var>VAR
%token<num>NUMBER
%type<isl>statics
%type<isl>static
%type<ia>attribution
%type<ial>attributions
%type<id>declaration
%type<im>method
%type<it>type
%type<ie>expression
%type<iie>infix_expression
%type<iue>unary_expression
%type<iar>arg
%type<iarl>args
%type<ip>print
%type<istl>statement
%type<istl>statements
%type<ibe>b_expression
%type<ii>if
%type<iw>while
%type<isf>for
%type<istl>for_first_camp

%left '+' '-' '*' '/' AND OR
%nonassoc UMINUS
%%

initclass:	CLASS VAR '{' statics '}'
		;

statics:	statics static	{$$=insert_static_list($1, $2);}
		|	static			{$$=insert_static_list(NULL, $1); isl=$$;}
		;

static:		STATIC attribution ';'	{$$=insert_a_static($2);}
        |   STATIC declaration      {$$=insert_d_static($2);}
		|	method			        {$$=insert_m_static($1);}
		;
		
declaration: type attributions ';'  {$$=insert_declaracao($2,$1);}
        ;

attributions:   attributions ',' attribution        {$$=insert_atribuicao_list($1, $3);}
        |       attribution                         {$$=insert_atribuicao_list(NULL, $1);}
        ;

attribution:	VAR                                 {$$=insert_atributo($1, NULL);}
        |       VAR '=' expression                  {$$=insert_atributo($1, $3);}
		;

method:		STATIC type VAR '(' args ')' '{' statements '}'	{$$=insert_metodo($2, $3, $5, $8);}
		|	STATIC type VAR '(' args ')' '{' '}'			{$$=insert_metodo($2, $3, $5, NULL);}
		|	STATIC type VAR '(' ')' '{' statements '}'		{$$=insert_metodo($2, $3, NULL, $7);}
		|	STATIC type VAR '(' ')' '{' '}'	    			{$$=insert_metodo($2, $3, NULL, NULL);}
		;

args:		args ',' arg    {$$=insert_argumento_list($1, $3);}
		|	arg             {$$=insert_argumento_list(NULL, $1);}                                 
		;
		
arg:        type VAR        {$$=insert_argumento($1, $2);}
        ;

type:		INT		{$$=is_INT;}
		|	STRING	{$$=is_STRING;}
		|	VOID	{$$=is_VOID;}
		|	FLOAT	{$$=is_FLOAT;}
		|	DOUBLE	{$$=is_DOUBLE;}
		|	BOOLEAN	{$$=is_BOOLEAN;}
		|	CHAR	{$$=is_CHAR;}
		;

statements: statements statement    {insert_statement_list($1,$2);}
        |   statement               {insert_statement_list(NULL, $1);}
        ;

statement:	declaration     {$$=insert_d_statement($1);}
        |   attribution ';' {$$=insert_a_statement($1);}
        |   print           {$$=insert_p_statement($1);}
        |   if              {$$=insert_i_statement($1);}
        |   while           {$$=insert_w_statement($1);}
        |   for             {$$=insert_f_statement($1);}
        ;


print:      PRINT '(' expression ')' ';'    {$$=insert_print($3, '\0');}
		|	PRINTLN '(' expression ')' ';'	{$$=insert_print($3, '\n');}
        ;     

expression:	infix_expression	{$$=insert_i_expression($1);}
		|	unary_expression	{$$=insert_u_expression($1);}
		|	NUMBER				{$$=insert_NUMBER($1);}
		|   VAR                 {$$=insert_VAR($1);}
		;

infix_expression:	expression '+' expression	{$$=insert_infix_expression($1, is_PLUS, $3);}
		|			expression '-' expression	{$$=insert_infix_expression($1, is_MINUS, $3);}
		|			expression '*' expression	{$$=insert_infix_expression($1, is_MULT, $3);}
		|			expression '/' expression	{$$=insert_infix_expression($1, is_DIVIDE, $3);}
		|			expression '+''+'			{$$=insert_infix_expression($1, is_PLUS, insert_NUMBER(1));}
		|			expression '-''-'			{$$=insert_infix_expression($1, is_MINUS, insert_NUMBER(1));}
		;

unary_expression:	'-' expression	%prec UMINUS	{$$=insert_unary_expression($2);}
		;
	
b_expression:       b_expression AND b_expression       {$$=insert_b_i_expressao($1, is_AND, $3);}
        |           b_expression OR b_expression        {$$=insert_b_i_expressao($3, is_OR, $3);}
        |           '!' b_expression  %prec UMINUS      {$$=insert_b_n_expressao($2);}
        |           expression EQUALS expression        {$$=insert_comparacao($1, is_EQUALS, $3);}
        |           expression DIFERENT expression      {$$=insert_comparacao($1, is_DIFERENT, $3);}
        |           expression GREATER expression       {$$=insert_comparacao($1, is_GREATER, $3);}
        |           expression LESSER expression        {$$=insert_comparacao($1, is_LESSER, $3);}
        |           expression GREATEQ expression       {$$=insert_comparacao($1, is_GREATEQ, $3);}
        |           expression LESSEQ expression        {$$=insert_comparacao($1, is_LESSEQ, $3);}
        |           TRUE                                {$$=insert_b_tf_expressao('1');}
        |           FALSE                               {$$=insert_b_tf_expressao('0');}
        ;

if:     IF '(' b_expression ')' '{' statements '}'      {$$=insert_if($3, $6);}
    |   IF '(' b_expression ')' statement               {$$=insert_if($3, $5);}
    ;

while:  WHILE '(' b_expression ')' '{' statements '}'      {$$=insert_while($3, $6);}
    |   WHILE '(' b_expression ')' statement               {$$=insert_while($3, $5);}
    ;

for:    FOR '(' for_first_camp b_expression ';' expression ')' '{' statements '}' {$$=insert_for($3, $4, $6, $9);}
    |   FOR '(' for_first_camp b_expression ';' expression ')' statement          {$$=insert_for($3, $4, $6, $8);}
    ;
    
for_first_camp: attributions ';'    {$$=insert_as_statement($1);}
    |           declaration         {$$=insert_d_statement($1);}
    ;

%%
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
