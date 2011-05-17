%{
#include "structures.h"
#include "y.tab.h"
%}

%%

[0-9]+			{//	Recebe os numeros
					yylval.num=atoi(yytext);
					return NUMBER;
				}

[0-9]+\.[0-9]+		{yylval.fnum=atof(yytext);
						return FLOAT_NUM;}

"class"			{// Recebe a declaração da classe
					return CLASS;
				}

"public"		{;}

"static"		{//	Recebe a declaração de static
					return STATIC;
				}

"int"			{return INT;}
"String"		{return STRING;}
"void"			{return VOID;}
"float"			{return FLOAT;}
"double"		{return DOUBLE;}
"Boolean"		{return BOOLEAN;}
"char"			{return CHAR;}

"if"            {return IF;}
"while"         {return WHILE;}
"for"           {return FOR;}
"do"			{return DO;}
"switch"		{return SWITCH;}
"case"			{return CASE;}

"&&"            {return AND;}
"||"            {return OR;}

"=="            {return EQUALS;}
"!="            {return DIFERENT;}
">"             {return GREATER;}
"<"             {return LESSER;}
">="            {return GREATEQ;}
"<="            {return LESSEQ;}

"true"          {return TRUE;}
"false"         {return FALSE;}

"System.out.print"  	{return PRINT;}
"System.out.println"	{return PRINTLN;}

[A-z][A-z0-9_]* {//	Nomes de variáveis têm de começar com letra, podem ter letra, número e _
					yylval.var = (char*) strdup(yytext); 
              		return VAR;
                 }
		
[ \t]			{//	Os espaços, tabs e parágrafos servem para separar os elementos
					;
				}
				
\n              {line++;}

";"	|
.				{// Recebe o resto como texto normal
					return yytext[0];
				}

%%
int yywrap()
{return 1;}
