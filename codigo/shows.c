#include "shows.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

void show_program(is_static_list* isl)
{
	is_static_list* aux;
	
	for(aux=isl; aux!=NULL; aux=aux->next)
	{
		printf("static(");
		show_static(aux->stat);
		printf(")\n");
	}
}

void show_static(is_static* is)
{
	switch(is->tipo)
	{
		/*case d_atribuicao:	printf("atributo(");
							show_attribute((is_atributo*)is->conteudo.u_atributo);
							printf(")");
							break;*/
		case d_metodo:		printf("metodo(");
							show_method((is_metodo*)is->conteudo.u_metodo);
							printf(")");
							break;
		case d_declaracao:	printf("declaracao(");
							show_declaracao((is_declaracao*)is->conteudo.u_declaracao);
							printf(")");
							break;
	}
}

void show_attribute(is_atributo* ia)
{
	printf("%s = ", ia->nome);
	
	if (ia->exp == NULL)
		printf("NULL");
	else
		show_expression((is_expressao*)ia->exp);
}

void show_method(is_metodo* im)
{
	switch(im->tipo)
	{
		case is_INT:		printf("int ");break;
		case is_STRING:		printf("String ");break;
		case is_VOID:		printf("void ");break;
		case is_FLOAT:		printf("float ");break;
		case is_DOUBLE:		printf("double ");break;
		case is_BOOLEAN:	printf("Boolean ");break;
		case is_CHAR:		printf("char ");break;
		case is_NONE:       break;
	}
	
	printf("%s(", im->nome);
	
	is_argumento_list* aux;
	
	for(aux=(is_argumento_list*)(im->arg_list); aux!=NULL; aux=aux->next)
	{
		printf("argument(");
		show_argument(aux->arg);
		printf(")\n");
	}
	
	is_statement_list* aux1;
	
	for(aux1=(is_statement_list*)(im->list); aux1!=NULL; aux1=aux1->next)
	{
		show_statement(aux1->stt);
	}
}

void show_expression(is_expressao* ie)
{
	switch(ie->tipo)
	{
	case d_infix_exp: printf("infix("); 
			  show_infix_expression((is_infix_expression*)ie->conteudo.u_infix_exp); 
			  printf(")");
			  break;
	case d_unary_exp: printf("unary("); 
			  show_unary_expression((is_unary_expression*)ie->conteudo.u_unary_exp); 
			  printf(")");
			  break;
	case d_number:	printf("NUMBER(%d)", ie->conteudo.number);
			break;
	case d_var:	printf("VAR(%s)", ie->conteudo.var);
			break;
	}
}

void show_infix_expression(is_infix_expression* iie)
{
	show_expression(iie->exp1);
	printf(", ");
	show_operator(iie->operador);
	printf(", ");
	show_expression(iie->exp2);
}

void show_unary_expression(is_unary_expression* iue)
{
	show_expression(iue->exp);
}

void show_operator(is_operador operador)
{
	if(operador==is_PLUS)
		printf("+");
	else if(operador==is_MINUS)
		printf("-");
	else if(operador==is_MULT)
		printf("*");
	else
		printf("/");
}

void show_argument(is_argumento* ia)
{
    switch(ia->tipo)
	{
		case is_INT:		printf("int ");break;
		case is_STRING:		printf("String ");break;
		case is_VOID:		printf("void ");break;
		case is_FLOAT:		printf("float ");break;
		case is_DOUBLE:		printf("double ");break;
		case is_BOOLEAN:	printf("Boolean ");break;
		case is_CHAR:		printf("char ");break;
		case is_NONE:       break;
	}
	
	printf("%s", ia->nome);
}

void show_statement(is_statement* stt)
{
    switch(stt->tipo)
	{
		case d_s_atribuicao:	printf("atributo(");
		                        show_attribute((is_atributo*)stt->conteudo.u_atributo);
		                        printf(")\n");break;
		
		case d_print:		    printf("print("); 
		                        show_print((is_print*)stt->conteudo.u_print); 
		                        printf(")\n");break;
		                        
		case d_s_declaracao:	printf("declaracao("); 
		                        show_declaracao((is_declaracao*)stt->conteudo.u_declaracao); 
		                        printf(")\n");break;

		case d_if:	            printf("if("); 
		                        show_if((is_if*)stt->conteudo.u_if); 
		                        printf(")\n");break;
		
		case d_while:	        printf("while("); 
		                        show_while((is_while*)stt->conteudo.u_while); 
		                        printf(")\n");break;
		
		case d_for:	            printf("for("); 
		                        show_for((is_for*)stt->conteudo.u_for); 
		                        printf(")\n");break;
	}
}

void show_print(is_print* print)
{
    show_expression((is_expressao*)print->conteudo.u_p_exp);
}

void show_declaracao(is_declaracao* id)
{
	switch(id->tipo)
	{
		case is_INT:		printf("int ");break;
		case is_STRING:		printf("String ");break;
		case is_VOID:		printf("void ");break;
		case is_FLOAT:		printf("float ");break;
		case is_DOUBLE:		printf("double ");break;
		case is_BOOLEAN:	printf("Boolean ");break;
		case is_CHAR:		printf("char ");break;
		case is_NONE:       break;
	}
	
	is_atribuicao_list* aux;
	
	for(aux=(is_atribuicao_list*)(id->list); aux!=NULL; aux=aux->next)
	{
		printf("atributo(");
		show_attribute(aux->attr);
		printf(")\n");
	}
}

void show_b_expression(is_b_expressao* ibe)
{
	switch(ibe->tipo)
	{
	case d_infix_b_exp: printf("infix_b("); 
          show_infix_b_expression((is_b_infix_expressao*)ibe->conteudo.u_infix_b_exp); 
          printf(")");
          break;
	case d_not_b_exp: printf("NOT("); 
		  show_not_b_expression((is_b_not_expressao*)ibe->conteudo.u_not_b_exp); 
		  printf(")");
		  break;
	case d_comparison: printf("comparison("); 	
          show_comparison((is_comparison*)ibe->conteudo.u_comp); 
		  printf(")");
		  break;
	case d_tf:	printf("BOOLEAN("); 	
          if(ibe->conteudo.boolean == '1')
            printf("True");
          else
            printf("False"); 
		  printf(")");
		  break;
	}
}

void show_infix_b_expression(is_b_infix_expressao* ibie)
{
	show_b_expression(ibie->exp1);
	printf(", ");
	show_b_operator(ibie->op);
	printf(", ");
	show_b_expression(ibie->exp2);
}

void show_not_b_expression(is_b_not_expressao* inbe)
{
	show_b_expression(inbe->exp);
}

void show_comparator(is_comparator operador)
{
	if(operador==is_EQUALS)
		printf("==");
	else if(operador==is_DIFERENT)
		printf("!=");
	else if(operador==is_GREATER)
		printf(">");
	else if(operador==is_DIFERENT)
		printf("!=");
	else if(operador==is_LESSER)
		printf("<");
	else if(operador==is_GREATEQ)
		printf(">=");
	else if(operador==is_LESSEQ)
		printf(">=");
}

void show_comparison(is_comparison* ic)
{
	show_expression(ic->exp1);
	printf(", ");
	show_comparator(ic->op);
	printf(", ");
	show_expression(ic->exp2);
}

void show_b_operator(is_b_operator operador)
{
	if(operador==is_AND)
		printf("AND");
	else
		printf("OR");
}

void show_if(is_if* ii)
{
	printf("b_expression(");
	show_b_expression(ii->exp);
	printf(")\n");
	
	is_statement_list* aux1;
	
	for(aux1=(is_statement_list*)(ii->stt); aux1!=NULL; aux1=aux1->next)
	{
		show_statement(aux1->stt);
	}
}

void show_while(is_while* iw)
{
	printf("b_expression(");
	show_b_expression(iw->exp);
	printf(")\n");
	
	is_statement_list* aux1;
	
	for(aux1=(is_statement_list*)(iw->stt); aux1!=NULL; aux1=aux1->next)
	{
		show_statement(aux1->stt);
	}
}

void show_for(is_for* isf)
{
	
	is_statement_list* aux;
	
	printf("dec_and_attr(");
	for(aux=(is_statement_list*)(isf->attr); aux!=NULL; aux=aux->next)
	{
		show_statement(aux->stt);
	}
	printf(")\n");
	
	printf("b_expression(");
	show_b_expression(isf->b_exp);
	printf(")\n");
	
	printf("expression(");
	show_expression(isf->exp);
	printf(")\n");
	
	is_statement_list* aux1;
	
	for(aux1=(is_statement_list*)(isf->stt); aux1!=NULL; aux1=aux1->next)
	{
		show_statement(aux1->stt);
	}
}
