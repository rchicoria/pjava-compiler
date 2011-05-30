#include "functions.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

/*
 *	adiciona à is_static_list list um is_static stat convertido em is_static_list
 */
is_static_list* insert_static_list( is_static_list* list, is_static_list* stat )
{
	
	if(list==NULL)		//Se a lista estiver vazia
		return stat;		//Devolve o nó criado
	
	is_static_list* aux;
	
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = stat;					//adiciona no final da lista
	
	return list;
}

/*
 *	cria um is_static a partir da is_declaration dec
 */
is_static_list* insert_d_static( is_declaration* dec )
{
	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );
	
	is_static* is = (is_static*) malloc( sizeof(is_static) );
	is->type = stat_declaration;
	is->content.dec = (struct is_declaration*) dec;
	
	isl->stat=is;
		
	return isl;		
}

/*
 *	cria um is_static a partir do is_method methodfunc
 */
is_static_list* insert_m_static( is_method* method )
{
	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );
	
	is_static* is = (is_static*) malloc( sizeof(is_static) );
	is->type = stat_method;
	is->content.method = (struct is_method*) method;
	
	isl->stat=is;
		
	return isl;		
}

/*
 *	cria um is_attribution a partir de um char name e uma expression exp
 */
is_attribution* insert_attribution_exp( int line, char* name, is_expression *exp )
{
    is_attribution *ia = (is_attribution*) malloc( sizeof(is_attribution) );
    ia->name = name;
    ia->type = attr_expression;
    ia->content.exp = (struct is_expression*) exp;
    ia->codeline = line;
    return ia;
}

/*
 *	cria um is_attribution a partir de um char name e uma is_b_expression exp
 */
is_attribution* insert_attribution_b_exp( int line, char* name, is_b_expression *exp )
{
    is_attribution *ia = (is_attribution*) malloc( sizeof(is_attribution) );
    ia->name = name;
    ia->type = attr_b_expression;
    ia->content.b_exp = (struct is_b_expression*) exp;
    ia->codeline = line;
    return ia;
}

/*
 *	adiciona à is_attribution_list list o is_attribution attr
 */
is_attribution_list* insert_attribution_list( is_attribution_list* list, is_attribution* attr )
{
	is_attribution_list* ial = (is_attribution_list*) malloc( sizeof(is_attribution_list) );
	ial->attr = attr;
	
	if(list==NULL)
		return ial;

	is_attribution_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);
	aux->next = ial;
	return list;
}

/*
 *	insert_as_statement
 *	cria um statement a partir de uma lista de atribuicoes
 */
is_statement_list* insert_as_statement( is_attribution_list* attr )
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo n� lista

	is_attribution_list* aux;
	is_statement_list* aux1;

	aux1 = istl;

	for(aux=attr; aux!=NULL; aux=aux->next){	//procura pelo final da lista
	    is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	    is->type = stt_attribution;				//Coloca etiqueta a informar que �ma "atribuicao"
	    is->content.attr = (struct is_attribution*) attr->attr;	//Guarda o conte�    
	    aux1->stt=is;
	    if(aux->next!=NULL){
	        aux1->next = (is_statement_list*) malloc( sizeof(is_statement_list) );
	        aux1=aux1->next;
	    }
	}
	return istl;		
}

/*
 *	cria um is_statement convertido em is_statement_list a partir de um is_attribution attr
 */
is_statement_list* insert_a_statement( is_attribution* attr )
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->type = stt_attribution;
	is->content.attr = (struct is_attribution*) attr;	//Guarda o conteúdo
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	cria um is_statement convertido em is_statement_list a partir de uma is_declaration dec
 */
is_statement_list* insert_d_statement( is_declaration* dec )
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->type = stt_declaration;
	is->content.dec = (struct is_declaration*) dec;
	
	istl->stt=is;
		
	return istl;	
}

/*
 *	cria um is_statement convertido em is_statement_list a partir de um is_print ip
 */
is_statement_list* insert_p_statement( is_print* ip)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->type = stt_print;
	is->content._print = (struct is_print*) ip;
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	cria um is_statement convertido em is_statement_list a partir de um is_if ii
 */
is_statement_list* insert_i_statement( is_if* ii)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->type = stt_if;
	is->content._if = (struct is_if*) ii;
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	cria um is_statement convertido em is_statement_list a partir de um is_while iw
 */
is_statement_list* insert_w_statement( is_while* iw)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->type = stt_while;	
	is->content._while = (struct is_while*) iw;
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	cria um is_statement convertido em is_statement_list a partir de um is_for isf
 */
is_statement_list* insert_f_statement( is_for* isf)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->type = stt_for;
	is->content._for = (struct is_for*) isf;
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	cria um is_statement convertido em is_statement_list a partir de um is_method_call imc
 */
is_statement_list* insert_mc_statement( is_method_call* imc)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->type = stt_m_call;
	is->content.m_call = (struct is_method_call*) imc;
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	cria um is_statement convertido em is_statement_list a partir de um is_return ir
 */
is_statement_list* insert_r_statement( is_return* ir)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->type = stt_return;
	is->content._return = (struct is_return*) ir;
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	adiciona à is_statement_list list os statements da is_statement_list stts
 */
is_statement_list* insert_statement_list( is_statement_list* list, is_statement_list* stts )
{
	if(list==NULL)
		return stts;

	is_statement_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);
	aux->next = stts;
	return list;
}

/*
 *  cria um is_declaration a partir de uma is_attribution_list list e de um is_type type
 */
is_declaration* insert_declaration(int line, is_attribution_list* list, is_type type)
{
    is_declaration* id = (is_declaration*) malloc(sizeof(is_declaration));
    id->type = type;
    id->list = list;
    id->codeline = line;

    return id;
}

/*
 *	cria um is_method a partir de um is_type type, um char name, uma is_argument_list arg_list e uma is_statement_list list
 */
is_method* insert_method( int line, is_type type, char* name, is_argument_list *arg_list, is_statement_list *stt_list)
{
    is_method *im = (is_method*) malloc( sizeof(is_method) );
    im->type = type;
    im->name = name;
    im->arg_list = (struct is_argument_list*) arg_list;
    im->stt_list = (struct is_statement_list*) stt_list;
    im->codeline = line;
    
    return im;
}

/*
 *	adiciona à is_expression_list list a is_expression exp
 */
is_expression_list* insert_expression_list( is_expression_list* list, is_expression* exp )
{
	is_expression_list* iel = (is_expression_list*) malloc( sizeof(is_expression_list) );
	iel->exp = exp;
	
	if(list==NULL)
		return iel;

	is_expression_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);
	aux->next = iel;
	
	return list;
}

/*
 *	cria uma is_expression a partir de uma is_infix_expression exp
 */
is_expression* insert_i_expression(int line,  is_infix_expression* exp )
{
	is_expression* ie = (is_expression*) malloc( sizeof(is_expression) );
	ie->type = exp_infix;
	ie->content.infix_exp = (struct is_infix_expression*) exp;
	ie->codeline = line;
	return ie;		
}

/*
 *	cria uma is_expression a partir de uma is_unary_expression exp
 */
is_expression* insert_u_expression(int line, is_unary_expression* exp )
{
	is_expression* ie = (is_expression*) malloc( sizeof(is_expression) );
	ie->type = exp_unary;
	ie->content.unary_exp = (struct is_unary_expression*) exp;
	ie->codeline = line;
	return ie;		
}

/*
 *	cria uma is_expression a partir de uma is_method_call imc
 */
is_expression* insert_mc_expression(int line, is_method_call* imc )
{
	is_expression* ie = (is_expression*) malloc( sizeof(is_expression) );
	ie->type = exp_m_call;
	ie->content.m_call = (struct is_method_call*) imc;
	ie->codeline = line;
	return ie;		
}

/*
 *	cria uma is_expression a partir de um int num_int
 */
is_expression* insert_INT(int line, int num_int )
{
	is_expression* ie = (is_expression*) malloc( sizeof(is_expression) );
	ie->type = exp_int;
	ie->content.num_int = num_int;
    ie->codeline = line;
	return ie;
}

/*
 *	cria uma is_expression a partir de um float num_float
 */
is_expression* insert_FLOAT(int line, float num_float )
{
	is_expression* ie = (is_expression*) malloc( sizeof(is_expression) );
	ie->type = exp_float;
	ie->content.num_float = num_float;
    ie->codeline = line;
	return ie;
}

/*
 *	cria uma is_expression a partir de um float num_float
 */
is_expression* insert_VAR(int line, char* var )
{
	is_expression* ie = (is_expression*) malloc( sizeof(is_expression) );
	ie->type = exp_var;
	ie->content.var = var;
    ie->codeline=line;
	return ie;		
}

/*
 *	cria uma is_infix_expression a partir de duas is_expression exp1 e exp2 e um is_operator op
 */
is_infix_expression* insert_infix_expression( is_expression *exp1, is_operator op, is_expression *exp2 )
{
    is_infix_expression *iie = (is_infix_expression*) malloc( sizeof(is_infix_expression) );
    iie->exp1 = exp1;
    iie->op = op;
    iie->exp2 = exp2;

    return iie;
}

/*
 *	cria uma is_unary_expression a partir de uma is_infix_expression exp
 */
is_unary_expression* insert_unary_expression( is_expression* exp )
{
    is_unary_expression *iue = (is_unary_expression*) malloc( sizeof(is_unary_expression) );
    iue->exp = exp;

    return iue;
}

/*
 *	cria um is_argument a partir de um is_type type e de um char name
 */
is_argument* insert_argument( is_type type, char* name )
{
    is_argument *ia = (is_argument*) malloc( sizeof(is_argument) );
    ia->type = type;
    ia->name = name;

    return ia;
}

/*
 *	adiciona à is_argument_list list o is_argument arg
 */
is_argument_list* insert_argument_list( is_argument_list* list, is_argument* arg )
{
	is_argument_list* ial = (is_argument_list*) malloc( sizeof(is_argument_list) );
	ial->arg = arg;
	
	if(list==NULL)
		return ial;

	is_argument_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);
	aux->next = ial;
	
	return list;
}

/*
 *   cria um is_print a partir de uma is_expression exp e de um char end que corresponde a fazer ou não quebra de linha
 */
is_print* insert_print(int line, is_expression* exp, char end)
{
    is_print* print = (is_print*) malloc (sizeof (is_print));
    print->type = print_expression;
    print->end = end;
    print->content.exp = (struct is_expression*)exp;
    print->codeline=line;
    return print;
}

/*
 *   cria uma is_b_expression a partir de um char boolean
 */
is_b_expression* insert_b_bool_expression(int line, char boolean  )
{
    is_b_expression* ibe = (is_b_expression*) malloc(sizeof(is_b_expression));
    ibe->type = b_exp_bool;
    ibe->content.boolean = boolean;
    ibe->codeline = line;
    return ibe;
}

/*
 *   cria uma is_b_expression a partir de duas is_expression exp1 e exp2 e de um is_comparator op
 */
is_b_expression* insert_comparison(int line, is_expression* exp1, is_comparator op, is_expression* exp2)
{
    is_b_expression* ibe = (is_b_expression*) malloc(sizeof(is_b_expression));
    ibe->type = b_exp_comp;
    
    is_comparison* ic = (is_comparison*) malloc(sizeof(is_comparison));
    ic->exp1 = (is_expression*) exp1;
    ic->op = op;
    ic->exp2 = (is_expression*) exp2;
    
    ibe->content.comp = (struct is_comparison*)ic;
    ibe->codeline = line;
    return ibe;
}

/*
 *   cria uma is_b_expression a partir de uma is_b_expression exp
 */
is_b_expression* insert_b_not_expression(int line, is_b_expression* exp)
{
    is_b_expression* ibe = (is_b_expression*) malloc(sizeof(is_b_expression));
    ibe->type = b_exp_not;
    
    is_b_not_expression* ibne = (is_b_not_expression*) malloc(sizeof(is_b_not_expression));
    ibne->exp = (is_b_expression*) exp;
    
    ibe->content.not_b_exp = (struct is_b_not_expression*)ibne;
    ibe->codeline = line;
    return ibe;
}

/*
 *   cria uma is_b_expression a partir de duas is_b_expression exp1 e exp2 e de um is_b_operator op
 */
is_b_expression* insert_b_infix_expression(int line, is_b_expression* exp1, is_b_operator op, is_b_expression* exp2)
{
    is_b_expression* ibe = (is_b_expression*) malloc(sizeof(is_b_expression));
    ibe->type = b_exp_infix;
    
    is_b_infix_expression* ibie = (is_b_infix_expression*) malloc(sizeof(is_b_infix_expression));
    ibie->exp1 = (is_b_expression*) exp1;
    ibie->op = op;
    ibie->exp2 = (is_b_expression*) exp2;
    
    ibe->content.infix_b_exp = (struct is_b_infix_expression*)ibie;
    ibe->codeline = line;
    return ibe;
}

/*
 *   cria um is_if a partir de uma is_expression exp, uma is_statement_list stt e um is_else ifelse
 */
is_if* insert_if(int line, is_b_expression* exp, is_statement_list* stt, is_else* ifelse)
{
    is_if* ii = (is_if*) malloc (sizeof(is_if));
    ii->exp = (is_b_expression*)exp;
    ii->stt = (is_statement_list*)stt;
    ii->codeline = line;
    ii->ifelse = (is_else*)ifelse;
    return ii;
}

/*
 *   cria um is_else a partir de uma is_statement_list stt
 */
is_else* insert_else(int line, is_statement_list* stt)
{
    is_else* iiel = (is_else*) malloc (sizeof(is_else));
    iiel->stt = (is_statement_list*)stt;
    iiel->codeline = line;
    return iiel;
}

/*
 *   cria um is_while a partir de uma is_b_expression exp e uma is_statement_list stt
 */
is_while* insert_while(int line, is_b_expression* exp, is_statement_list* stt)
{
    is_while* iw = (is_while*) malloc (sizeof(is_while));
    iw->exp = (is_b_expression*)exp;
    iw->stt = (is_statement_list*)stt;
    iw->codeline = line;
    return iw;
}

/*
 *   cria um is_for a partir de uma is_statement_list attr, is_b_expression b_exp, is_expression exp e uma is_statement_list stt
 */
is_for* insert_for(int line, is_statement_list* attr, is_b_expression* b_exp, is_expression* exp, is_statement_list* stt)
{
    is_for* isf = (is_for*) malloc (sizeof(is_for));
    isf->attr = (is_statement_list*)attr;
    isf->b_exp = (is_b_expression*)b_exp;
    isf->exp = (is_expression*)exp;
    isf->stt = (is_statement_list*) stt;
    isf->codeline = line;
    return isf;
}

/*
 *   adiciona à is_method_arg_list list a is_expression ou is_b_expression arg convertido em is_method_arg_list
 */
is_method_arg_list* insert_method_arg_list( is_method_arg_list* list, is_method_arg_list* arg )
{
	
	if(list==NULL)
		return arg;

	is_method_arg_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);
	aux->next = arg;
	return list;
}

/*
 *  cria um is_method_arg_list a partir de uma is_expression exp
 */
is_method_arg_list* insert_method_arg_exp(int line, is_expression* exp)
{
    is_method_arg_list* imal = (is_method_arg_list*) malloc (sizeof(is_method_arg_list)); 
    
    is_method_arg* ima = (is_method_arg*) malloc (sizeof(is_method_arg));
    ima->type = arg_expression;
    ima->content.exp = (is_expression*) exp;
    ima->codeline=line;
    
    imal->m_arg = ima;
    
    return imal;
}

/*
 *  cria um is_method_arg_list a partir de uma is_b_expression b_exp
 */
is_method_arg_list* insert_method_arg_b_exp(int line, is_b_expression* b_exp)
{
    is_method_arg_list* imal = (is_method_arg_list*) malloc (sizeof(is_method_arg_list)); 
    
    is_method_arg* ima = (is_method_arg*) malloc (sizeof(is_method_arg));
    ima->type = arg_b_expression;
    ima->content.b_exp = (is_b_expression*) b_exp;
    ima->codeline=line;
    
    imal->m_arg = ima;
    
    return imal;
}

/*
 *  cria um is_method_call a partir de uma char name e de uma is_method_arg_list args
 */
is_method_call* insert_method_call(int line, char* name, is_method_arg_list* args)
{
    is_method_call* imc = (is_method_call*) malloc (sizeof(is_method_call));
    imc->name = name;
    imc->m_arg_list = (is_method_arg_list*) args;
    imc->codeline = line;
    return imc;
}

/*
 *  cria um is_return vazio
 */
is_return* insert_return_void(int line)
{
    is_return* ir = (is_return*) malloc (sizeof(is_return));
    ir->type=ret_void;
    ir->codeline=line;
    return ir;
}

/*
 *  cria um is_return a partir de uma is_expression exp
 */
is_return* insert_return_exp(is_expression* exp, int line)
{
    is_return* ir = (is_return*) malloc (sizeof(is_return));
    ir->type=ret_expression;
    ir->content.exp = (is_expression*) exp;
    ir->codeline=line;
    return ir;
}

/*
 *  cria um is_return a partir de uma is_b_expression exp
 */
is_return* insert_return_b_exp(is_b_expression* exp, int line)
{
    is_return* ir = (is_return*) malloc (sizeof(is_return));
    ir->type = ret_b_expression;
    ir->content.b_exp = (is_b_expression*) exp;
    ir->codeline=line;
    return ir;
}
