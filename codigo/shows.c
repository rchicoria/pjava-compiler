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
	switch(is->type)
	{
		case stat_method:	printf("method(");
							show_method((is_method*)is->content.method);
							printf(")");
							break;
		case stat_declaration:	printf("declaration(");
						        show_declaration((is_declaration*)is->content.dec);
						        printf(")");
						        break;
	}
}

void show_attribution(is_attribution* ia)
{
	if(ia->op != '=')
	    printf("%s %c= ", ia->name,  ia->op);
	else
	    printf("%s = ", ia->name);
	
	if (ia->content.exp == NULL && ia->content.b_exp == NULL)
		printf("NULL");
	else if(ia->type==attr_expression)
		show_expression((is_expression*)ia->content.exp);
	else if(ia->type==attr_b_expression)
		show_b_expression((is_b_expression*)ia->content.b_exp);
}

void show_method(is_method* im)
{
	switch(im->type)
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
	
	printf("%s(", im->name);
	
	is_argument_list* aux;
	
	for(aux=(is_argument_list*)(im->arg_list); aux!=NULL; aux=aux->next)
	{
		printf("argument(");
		show_argument(aux->arg);
		printf(")\n");
	}
	
	is_statement_list* aux1;
	
	for(aux1=(is_statement_list*)(im->stt_list); aux1!=NULL; aux1=aux1->next)
	{
		show_statement(aux1->stt);
	}
}

void show_return(is_return* ir)
{
    switch(ir->type)
    {
        case ret_void: printf("void"); return;
        case ret_expression: show_expression(ir->content.exp); return;
        case ret_b_expression: show_b_expression(ir->content.b_exp); return;
    }
    return;
}

void show_expression(is_expression* ie)
{
	switch(ie->type)
	{
	    case exp_infix: 
	        printf("infix("); 
	        show_infix_expression((is_infix_expression*)ie->content.infix_exp); 
			printf(")");
	        break;
	    case exp_unary: printf("unary("); 
            show_unary_expression((is_unary_expression*)ie->content.unary_exp); 
            printf(")");
            break;
	    case exp_int:	
	        printf("INT(%d)", ie->content.num_int);
		    break;
	    case exp_double:	
	        printf("DOUBLE(%f)", ie->content.num_double);
		    break;
		case exp_char:	
	        printf("CHAR(%c)", ie->content.val_char);
		    break;
	}
}

void show_infix_expression(is_infix_expression* iie)
{
	show_s_expression(iie->exp1);
	printf(", ");
	show_operator(iie->op);
	printf(", ");
	show_s_expression(iie->exp2);
}

void show_s_expression(is_s_expression* ise)
{
    switch(ise->type){
        case s_exp_exp: show_expression((is_expression*)ise->content.exp);
                        break;
        case s_exp_var: printf("VAR(%s)",ise->content.var);
                        break;
        case s_exp_m_call:  
            printf("method_call("); 
            show_method_call((is_method_call*)ise->content.m_call); 
            printf(")\n");
            break;
        case s_exp_inc:
            printf("inc(");
            show_increment((is_increment*) ise->content.inc);
            printf(")\n");
            break;
    }
}

void show_unary_expression(is_unary_expression* iue)
{
	if(iue->type == u_exp_neg)
	    printf("-");
	show_s_expression(iue->exp);
}

void show_operator(is_operator op)
{
	if(op==is_PLUS)
		printf("+");
	else if(op==is_MINUS)
		printf("-");
	else if(op==is_MULT)
		printf("*");
	else if(op==is_MOD)
		printf("%c",'%');
	else
		printf("/");
}

void show_argument(is_argument* ia)
{
    switch(ia->type)
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
	
	printf("%s", ia->name);
}

void show_statement(is_statement* stt)
{
    switch(stt->type)
	{
		case stt_attribution:	printf("attribution(");
		                        show_attribution((is_attribution*)stt->content.attr);
		                        printf(")\n");break;
		
		case stt_print:		    printf("print("); 
		                        show_print((is_print*)stt->content._print); 
		                        printf(")\n");break;
		                        
		case stt_declaration:	printf("declaration("); 
		                        show_declaration((is_declaration*)stt->content.dec); 
		                        printf(")\n");break;

		case stt_if:            printf("if("); 
		                        show_if((is_if*)stt->content._if); 
		                        printf(")\n");break;
		
		case stt_while:	        printf("while("); 
		                        show_while((is_while*)stt->content._while); 
		                        printf(")\n");break;
		
		case stt_for:           printf("for("); 
		                        show_for((is_for*)stt->content._for); 
		                        printf(")\n");break;
		                        
		case stt_m_call:        printf("method_call("); 
		                        show_method_call((is_method_call*)stt->content.m_call); 
		                        printf(")\n");break;
		                        
		case stt_return:        printf("return("); 
		                        show_return((is_return*)stt->content._return); 
		                        printf(")\n");break;
		case stt_inc:
            printf("inc(");
            show_increment((is_increment*) stt->content.inc);
            printf(")\n");
            break;
	}
}

void show_print(is_print* print)
{
    show_s_expression((is_s_expression*)print->content.exp);
}

void show_declaration(is_declaration* id)
{
	switch(id->type)
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
	
	is_attribution_list* aux;
	
	for(aux=(is_attribution_list*)(id->list); aux!=NULL; aux=aux->next)
	{
		printf("attribution(");
		show_attribution(aux->attr);
		printf(")\n");
	}
}

void show_b_expression(is_b_expression* ibe)
{
	switch(ibe->type)
	{
	    case b_exp_infix: 
	        printf("infix_b("); 
            show_infix_b_expression((is_b_infix_expression*)ibe->content.infix_b_exp); 
            printf(")");
            break;
	    case b_exp_not: 
	        printf("NOT("); 
		    show_b_not_expression((is_b_not_expression*)ibe->content.not_b_exp); 
		    printf(")");
		    break;
	    case b_exp_comp: 
	        printf("comparison("); 	
            show_comparison((is_comparison*)ibe->content.comp); 
		    printf(")");
		    break;
	    case b_exp_bool:	
            printf("BOOLEAN("); 	
            if(ibe->content.boolean == '1')
                printf("True");
            else
                printf("False"); 
            printf(")");
            break;
        case b_exp_var:	
	        printf("VAR(%s)", ibe->content.var);
	        break;
        case b_exp_m_call:  
            printf("method_call("); 
            show_method_call((is_method_call*)ibe->content.m_call); 
            printf(")\n");
            break;
        case b_exp_inc:
            printf("inc(");
            show_increment((is_increment*) ibe->content.inc);
            printf(")\n");
            break;
	}
}

void show_infix_b_expression(is_b_infix_expression* ibie)
{
	show_b_expression(ibie->exp1);
	printf(", ");
	show_b_operator(ibie->op);
	printf(", ");
	show_b_expression(ibie->exp2);
}

void show_b_not_expression(is_b_not_expression* inbe)
{
	show_b_expression(inbe->exp);
}

void show_comparator(is_comparator op)
{
	if(op==is_EQUALS)
		printf("==");
	else if(op==is_DIFERENT)
		printf("!=");
	else if(op==is_GREATER)
		printf(">");
	else if(op==is_DIFERENT)
		printf("!=");
	else if(op==is_LESSER)
		printf("<");
	else if(op==is_GREATEQ)
		printf(">=");
	else if(op==is_LESSEQ)
		printf(">=");
}

void show_comparison(is_comparison* ic)
{
	show_s_expression(ic->exp1);
	printf(", ");
	show_comparator(ic->op);
	printf(", ");
	show_s_expression(ic->exp2);
}

void show_b_operator(is_b_operator op)
{
	if(op==is_AND)
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
	if(ii->ifelse != NULL){
	    printf("else( ");
	    show_else(ii->ifelse);
	    printf(")");
	}
}

void show_else(is_else* iiel)
{
	is_statement_list* aux1;
	
	for(aux1=(is_statement_list*)(iiel->stt); aux1!=NULL; aux1=aux1->next)
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
	
	printf("first_camp(");
	for(aux=(is_statement_list*)(isf->attr); aux!=NULL; aux=aux->next)
	{
		show_statement(aux->stt);
	}
	printf(")\n");
	
	printf("b_expression(");
	show_b_expression(isf->b_exp);
	printf(")\n");
	
	printf("last_camp(");
	for(aux=(is_statement_list*)(isf->last); aux!=NULL; aux=aux->next)
	{
		show_statement(aux->stt);
	}
	printf(")\n");
	
	is_statement_list* aux1;
	
	for(aux1=(is_statement_list*)(isf->stt); aux1!=NULL; aux1=aux1->next)
	{
		show_statement(aux1->stt);
	}
}

void show_method_call(is_method_call* imc)
{
    printf("name(%s)\n",imc->name);
    is_method_arg_list* imal = (is_method_arg_list*) malloc (sizeof(is_method_arg_list));
    printf("args(");
    for(imal=imc->m_arg_list; imal; imal=imal->next)
    {
        show_method_arg(imal->m_arg);
    }
    printf(")");
}

void show_method_arg(is_method_arg* ima)
{
    switch(ima->type)
	{
	    case arg_expression: 
            printf("expression("); 
            show_expression(ima->content.exp);
            printf(")\n");
            break;
	    case arg_b_expression: printf("b_expression("); 
		    show_b_expression(ima->content.b_exp) ;
		    printf(")");
		    break;
	}
}
void show_increment(is_increment* iinc)
{
    printf("VAR(%s)%c%c",iinc->var, iinc->op, iinc->op);
}
