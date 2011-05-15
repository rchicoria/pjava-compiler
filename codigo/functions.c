#include "functions.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

/*
 *	insert_static_list
 *	adiciona � lista list o static stat
 */
is_static_list* insert_static_list( is_static_list* list, is_static_list* stat )
{
/*	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );	//Cria novo n� na lista*/
/*	isl->stat = stat;				//Preenche-o*/
	
	if(list==NULL)		//Se a lista estiver vazia
		return stat;		//Devolve o n� criado
	
	is_static_list* aux;
	
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = stat;					//adiciona no final da lista
	
	
	return list;
}

/*
 *	insert_a_static
 *	cria um static a partir de um atributo
 */
is_static_list* insert_a_static( is_atributo* atributo )
{
	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );	//Cria novo n� na lista
	
	is_static* is = (is_static*) malloc( sizeof(is_static) );
	is->tipo = d_atribuicao;				//Coloca etiqueta a informar que � um "metodo"
	is->conteudo.u_atributo = (struct is_atributo*) atributo;	//Guarda o conte�do
	
	isl->stat=is;
		
	return isl;		
}

/*
 *	insert_d_static
 *	cria um static a partir de uma declaracao
 */
is_static_list* insert_d_static( is_declaracao* dec )
{
	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );	//Cria novo n� na lista
	
	is_static* is = (is_static*) malloc( sizeof(is_static) );
	is->tipo = d_declaracao;				//Coloca etiqueta a informar que � um "metodo"
	is->conteudo.u_declaracao = (struct is_declaracao*) dec;	//Guarda o conte�do
	
	isl->stat=is;
		
	return isl;		
}

/*
 *	insert_m_static
 *	cria um static a partir de um m�todo
 */
is_static_list* insert_m_static( is_metodo* metodo )
{
	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );	//Cria novo n� na lista
	
	is_static* is = (is_static*) malloc( sizeof(is_static) );
	is->tipo = d_metodo;				//Coloca etiqueta a informar que � um "metodo"
	is->conteudo.u_metodo = (struct is_metodo*) metodo;	//Guarda o conte�do
	
	isl->stat=is;
		
	return isl;		
}

/*
 *	insert_atributo
 *	cria um atributo a partir de um nome e uma express�o
 */
is_atributo* insert_atributo( char* nome, is_expressao *exp )
{
    is_atributo *ia = (is_atributo*) malloc( sizeof(is_atributo) );
    ia->nome = nome;		//Guarda nome
    ia->exp = (struct is_expressao*) exp;			//Guarda express�o
    ia->tipo = is_NONE;
    return ia;
}

/*
 *	insert_atributo_list
 *	adiciona � lista list o atributo att
 */
is_atribuicao_list* insert_atribuicao_list( is_atribuicao_list* list, is_atributo* attr )
{
	is_atribuicao_list* ial = (is_atribuicao_list*) malloc( sizeof(is_atribuicao_list) );	//Cria novo n� na lista
	ial->attr = attr;				//Preenche-o
	
	if(list==NULL)		//Se a lista estiver vazia
		return ial;		//Devolve o n� criado

	is_atribuicao_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = ial;					//adiciona no final da lista
	return list;
}

/*
 *	insert_a_statement
 *	cria um statement a partir de uma atribuicao
 */
is_statement_list* insert_a_statement( is_atributo* attr )
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo n� na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_s_atribuicao;				//Coloca etiqueta a informar que � uma "atribuicao"
	is->conteudo.u_atributo = (struct is_atributo*) attr;	//Guarda o conte�do
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_as_statement
 *	cria um statement a partir de uma lista de atribuicoes
 */
is_statement_list* insert_as_statement( is_atribuicao_list* attr )
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo n� na lista
	
	is_atribuicao_list* aux;
	is_statement_list* aux1;
	
	aux1 = istl;
	
	for(aux=attr; aux!=NULL; aux=aux->next){	//procura pelo final da lista
	    is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	    is->tipo = d_s_atribuicao;				//Coloca etiqueta a informar que � uma "atribuicao"
	    is->conteudo.u_atributo = (struct is_atributo*) attr->attr;	//Guarda o conte�do
	    
	    aux1->stt=is;
	    if(aux->next!=NULL){
	        aux1->next = (is_statement_list*) malloc( sizeof(is_statement_list) );
	        aux1=aux1->next;
	    }
	}
	return istl;		
}

/*
 *	insert_d_statement
 *	cria um statement a partir de uma declaracao
 */
is_statement_list* insert_d_statement( is_declaracao* dec )
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo n� na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_s_declaracao;				//Coloca etiqueta a informar que � uma "declaracao"
	is->conteudo.u_declaracao = (struct is_declaracao*) dec;	//Guarda o conte�do
	
	istl->stt=is;
		
	return istl;	
}

/*
 *	insert_p_statement
 *	cria um statement a partir de um print
 */
is_statement_list* insert_p_statement( is_print* print)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo n� na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_print;				//Coloca etiqueta a informar que � uma "atribuicao"
	is->conteudo.u_print = (struct is_print*) print;	//Guarda o conte�do
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_i_statement
 *	cria um statement a partir de um if
 */
is_statement_list* insert_i_statement( is_if* ii)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo n� na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_if;				//Coloca etiqueta a informar que � uma "atribuicao"
	is->conteudo.u_if = (struct is_if*) ii;	//Guarda o conte�do
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_w_statement
 *	cria um statement a partir de um while
 */
is_statement_list* insert_w_statement( is_while* iw)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo n� na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_while;				//Coloca etiqueta a informar que � uma "atribuicao"
	is->conteudo.u_while = (struct is_while*) iw;	//Guarda o conte�do
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_f_statement
 *	cria um statement a partir de um for
 */
is_statement_list* insert_f_statement( is_for* isf)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo n� na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_for;				//Coloca etiqueta a informar que � uma "atribuicao"
	is->conteudo.u_for = (struct is_for*) isf;	//Guarda o conte�do
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_statement_list
 *	adiciona � lista list os statements da lista stts
 */
is_statement_list* insert_statement_list( is_statement_list* list, is_statement_list* stts )
{
	
	if(list==NULL)		//Se a lista estiver vazia
		return stts;		//Devolve o n� criado

	is_statement_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = stts;					//adiciona no final da lista
	return list;
}

/*
 *  insert_declaracao
 *  adiciona o tipo de atributo a uma lista de atributos
 */
is_declaracao* insert_declaracao( is_atribuicao_list* list, is_tipo tipo)
{
    is_declaracao* id = (is_declaracao*) malloc(sizeof(is_declaracao));
    id->tipo = tipo;
    id->list = list;

    return id;
}

/*
 *	insert_metodo
 *	cria um m�todo a partir de um tipo, um nome e uma express�o
 */
is_metodo* insert_metodo( is_tipo tipo, char* nome, is_argumento_list *arg_list, is_statement_list *list )
{
    is_metodo *im = (is_metodo*) malloc( sizeof(is_metodo) );
    im->tipo = tipo;		//Guarda tipo
    im->nome = nome;		//Guarda nome
    im->arg_list = (struct is_argumento_list*) arg_list;
    im->list = (struct is_statement_list*) list;			//Guarda express�o
    
    return im;
}

/*
 *	insert_expression_list
 *	adiciona � lista list a express�o exp
 */
is_expressao_list* insert_expression_list( is_expressao_list* list, is_expressao* exp )
{
	is_expressao_list* iel = (is_expressao_list*) malloc( sizeof(is_expressao_list) );	//Cria novo n� na lista
	iel->expr = exp;				//Preenche-o
	
	if(list==NULL)		//Se a lista estiver vazia
		return iel;		//Devolve o n� criado

	is_expressao_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = iel;					//adiciona no final da lista
	
	return list;
}

/*
 *	insert_i_expression
 *	cria uma expression a partir de uma infix_expression
 */
is_expressao* insert_i_expression( is_infix_expression* expression )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_infix_exp;				//Coloca etiqueta a informar que � um "infix expression"
	ie->conteudo.u_infix_exp = (struct is_infix_expression*) expression;	//Guarda o conte�do
		
	return ie;		
}

/*
 *	insert_u_expression
 *	cria uma expression a partir de uma unary_expression
 */
is_expressao* insert_u_expression( is_unary_expression* expression )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_unary_exp;				//Coloca etiqueta a informar que � um "unary expression"
	ie->conteudo.u_unary_exp = (struct is_unary_expression*) expression;	//Guarda o conte�do
		
	return ie;		
}

/*
 *	insert_NUMBER
 *	cria uma express�o a partir de um n�mero
 */
is_expressao* insert_NUMBER( int number )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_number;				//Coloca etiqueta a informar que � um numero
	ie->conteudo.number = number;	//Guarda o conte�do

	return ie;
}

/*
 *	insert_VAR
 *	cria uma express�o a partir de uma var
 */
is_expressao* insert_VAR( char* var )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_var;				//Coloca etiqueta a informar que � um numero
	ie->conteudo.var = var;	//Guarda o conte�do

	return ie;		
}

/*
 *	insert_infix_expression
 *	cria uma infix_expression a partir de duas express�es e um operador
 */
is_infix_expression* insert_infix_expression( is_expressao *op1, is_operador operador, is_expressao *op2 )
{
        is_infix_expression *iie = (is_infix_expression*) malloc( sizeof(is_infix_expression) );
        iie->exp1 = op1;			//Guarda operando 1
        iie->operador = operador;	//Guarda operador
        iie->exp2 = op2;			//Guarda operando 2

        return iie;
}

/*
 *	insert_unary_expression
 *	cria uma unary_expression a partir de uma express�o
 */
is_unary_expression* insert_unary_expression( is_expressao* expression )
{
        is_unary_expression *iue = (is_unary_expression*) malloc( sizeof(is_unary_expression) );
        iue->exp = expression;			//Guarda operando

        return iue;
}

/*
 *	insert_argumento
 *	cria um argumento a partir de um tipo e um nome
 */
is_argumento* insert_argumento( is_tipo tipo, char* nome )
{
    is_argumento *ia = (is_argumento*) malloc( sizeof(is_argumento) );
    ia->tipo = tipo;		//Guarda tipo
    ia->nome = nome;		//Guarda nome

    return ia;
}

/*
 *	insert_argumento_list
 *	adiciona � lista list a express�o arg
 */
is_argumento_list* insert_argumento_list( is_argumento_list* list, is_argumento* arg )
{
	is_argumento_list* ial = (is_argumento_list*) malloc( sizeof(is_argumento_list) );	//Cria novo n� na lista
	ial->arg = arg;				//Preenche-o
	
	if(list==NULL)		//Se a lista estiver vazia
		return ial;		//Devolve o n� criado

	is_argumento_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = ial;					//adiciona no final da lista
	
	return list;
}

/*
 *  insert_print
 *  adiciona um print
 */
is_print* insert_print( is_expressao* exp, char fim)
{
    is_print* print = (is_print*) malloc (sizeof (is_print));
    print->tipo = d_expression;
    print->fim = fim;
    print->conteudo.u_p_exp = (struct is_expressao*)exp;
    
    return print;
}

/*
 *  insert_b_tf_expressao
 *  adiciona uma b_tf_expressao
 */
is_b_expressao* insert_b_tf_expressao( char boolean  )
{
    is_b_expressao* ibe = (is_b_expressao*) malloc(sizeof(is_b_expressao));
    ibe->tipo = d_tf;
    ibe->conteudo.boolean = boolean;
    
    return ibe;
}

/*
 *  insert_comparacao
 *  adiciona uma comparacao a partir de duas expressoes 
 */
is_b_expressao* insert_comparacao(is_expressao* exp1, is_comparator comp, is_expressao* exp2)
{
    is_b_expressao* ibe = (is_b_expressao*) malloc(sizeof(is_b_expressao));
    ibe->tipo = d_comparison;
    
    is_comparison* ic = (is_comparison*) malloc(sizeof(is_comparison));
    ic->exp1 = (is_expressao*) exp1;
    ic->op = comp;
    ic->exp2 = (is_expressao*) exp2;
    
    ibe->conteudo.u_comp = (struct is_comparison*)ic;
    
    return ibe;
}

/*
 *  insert_b_n_expressao
 *  adiciona uma b_not_expressao
 */
is_b_expressao* insert_b_n_expressao(is_b_expressao* exp)
{
    is_b_expressao* ibe = (is_b_expressao*) malloc(sizeof(is_b_expressao));
    ibe->tipo = d_not_b_exp;
    
    is_b_not_expressao* ibne = (is_b_not_expressao*) malloc(sizeof(is_b_not_expressao));
    ibne->exp = (is_b_expressao*) exp;
    
    ibe->conteudo.u_not_b_exp = (struct is_b_not_expressao*)ibne;
    
    return ibe;
}

/*
 *  insert_b_i_expressao
 *  adiciona uma b_infix_expressao a partir de duas b_expressoes 
 */
is_b_expressao* insert_b_i_expressao(is_b_expressao* exp1, is_b_operator op, is_b_expressao* exp2)
{
    is_b_expressao* ibe = (is_b_expressao*) malloc(sizeof(is_b_expressao));
    ibe->tipo = d_infix_b_exp;
    
    is_b_infix_expressao* ibie = (is_b_infix_expressao*) malloc(sizeof(is_b_infix_expressao));
    ibie->exp1 = (is_b_expressao*) exp1;
    ibie->op = op;
    ibie->exp2 = (is_b_expressao*) exp2;
    
    ibe->conteudo.u_infix_b_exp = (struct is_b_infix_expressao*)ibie;
    
    return ibe;
}

/*
 *  insert_if
 *  adiciona um is_if
 */
is_if* insert_if(is_b_expressao* exp, is_statement_list* stt)
{
    is_if* ii = (is_if*) malloc (sizeof(is_if));
    ii->exp = (is_b_expressao*)exp;
    ii->stt = (is_statement_list*)stt;
    
    return ii;
}

/*
 *  insert_while
 *  adiciona um is_while
 */
is_while* insert_while(is_b_expressao* exp, is_statement_list* stt)
{
    is_while* iw = (is_while*) malloc (sizeof(is_while));
    iw->exp = (is_b_expressao*)exp;
    iw->stt = (is_statement_list*)stt;
    
    return iw;
}

/*
 *  insert_for
 *  adiciona um is_for
 */
is_for* insert_for(is_statement_list* att, is_b_expressao* ibe, is_expressao* ie, is_statement_list* stt)
{
    is_for* isf = (is_for*) malloc (sizeof(is_for));
    isf->attr = (is_statement_list*)att;
    isf->b_exp = (is_b_expressao*)ibe;
    isf->exp = (is_expressao*)ie;
    isf->stt = (is_statement_list*) stt;
    
    return isf;
}