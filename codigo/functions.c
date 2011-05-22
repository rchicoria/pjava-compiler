#include "functions.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

/*
 *	insert_static_list
 *	adiciona à lista list o static stat
 */
is_static_list* insert_static_list( is_static_list* list, is_static_list* stat )
{
/*	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );	//Cria novo nó na lista*/
/*	isl->stat = stat;				//Preenche-o*/
	
	if(list==NULL)		//Se a lista estiver vazia
		return stat;		//Devolve o nó criado
	
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
	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );	//Cria novo nó na lista
	
	/*is_static* is = (is_static*) malloc( sizeof(is_static) );
	is->tipo = d_atribuicao;				//Coloca etiqueta a informar que é um "metodo"
	is->conteudo.u_atributo = (struct is_atributo*) atributo;	//Guarda o conteúdo
	
	isl->stat=is;*/
		
	return isl;		
}

/*
 *	insert_d_static
 *	cria um static a partir de uma declaracao
 */
is_static_list* insert_d_static( is_declaracao* dec )
{
	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );	//Cria novo nó na lista
	
	is_static* is = (is_static*) malloc( sizeof(is_static) );
	is->tipo = d_declaracao;				//Coloca etiqueta a informar que é um "metodo"
	is->conteudo.u_declaracao = (struct is_declaracao*) dec;	//Guarda o conteúdo
	
	isl->stat=is;
		
	return isl;		
}

/*
 *	insert_m_static
 *	cria um static a partir de um método
 */
is_static_list* insert_m_static( is_metodo* metodo )
{
	is_static_list* isl = (is_static_list*) malloc( sizeof(is_static_list) );	//Cria novo nó na lista
	
	is_static* is = (is_static*) malloc( sizeof(is_static) );
	is->tipo = d_metodo;				//Coloca etiqueta a informar que é um "metodo"
	is->conteudo.u_metodo = (struct is_metodo*) metodo;	//Guarda o conteúdo
	
	isl->stat=is;
		
	return isl;		
}

/*
 *	insert_atributo
 *	cria um atributo a partir de um nome e uma expressão
 */
is_atributo* insert_atributo( int line, char* nome, is_expressao *exp )
{
    is_atributo *ia = (is_atributo*) malloc( sizeof(is_atributo) );
    ia->nome = nome;		//Guarda nome
    ia->exp = (struct is_expressao*) exp;			//Guarda expressão
    ia->codeline = line;
    return ia;
}

/*
 *	insert_atributo_list
 *	adiciona à lista list o atributo att
 */
is_atribuicao_list* insert_atribuicao_list( is_atribuicao_list* list, is_atributo* attr )
{
	is_atribuicao_list* ial = (is_atribuicao_list*) malloc( sizeof(is_atribuicao_list) );	//Cria novo nó na lista
	ial->attr = attr;				//Preenche-o
	
	if(list==NULL)		//Se a lista estiver vazia
		return ial;		//Devolve o nó criado

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
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo nó na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_s_atribuicao;				//Coloca etiqueta a informar que é uma "atribuicao"
	is->conteudo.u_atributo = (struct is_atributo*) attr;	//Guarda o conteúdo
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_as_statement
 *	cria um statement a partir de uma lista de atribuicoes
 */
is_statement_list* insert_as_statement( is_atribuicao_list* attr )
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo nó na lista
	
	is_atribuicao_list* aux;
	is_statement_list* aux1;
	
	aux1 = istl;
	
	for(aux=attr; aux!=NULL; aux=aux->next){	//procura pelo final da lista
	    is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	    is->tipo = d_s_atribuicao;				//Coloca etiqueta a informar que é uma "atribuicao"
	    is->conteudo.u_atributo = (struct is_atributo*) attr->attr;	//Guarda o conteúdo
	    
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
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo nó na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_s_declaracao;				//Coloca etiqueta a informar que é uma "declaracao"
	is->conteudo.u_declaracao = (struct is_declaracao*) dec;	//Guarda o conteúdo
	
	istl->stt=is;
		
	return istl;	
}

/*
 *	insert_p_statement
 *	cria um statement a partir de um print
 */
is_statement_list* insert_p_statement( is_print* print)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo nó na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_print;				//Coloca etiqueta a informar que é uma "atribuicao"
	is->conteudo.u_print = (struct is_print*) print;	//Guarda o conteúdo
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_i_statement
 *	cria um statement a partir de um if
 */
is_statement_list* insert_i_statement( is_if* ii)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo nó na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_if;				//Coloca etiqueta a informar que é uma "atribuicao"
	is->conteudo.u_if = (struct is_if*) ii;	//Guarda o conteúdo
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_w_statement
 *	cria um statement a partir de um while
 */
is_statement_list* insert_w_statement( is_while* iw)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo nó na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_while;				//Coloca etiqueta a informar que é uma "atribuicao"
	is->conteudo.u_while = (struct is_while*) iw;	//Guarda o conteúdo
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_f_statement
 *	cria um statement a partir de um for
 */
is_statement_list* insert_f_statement( is_for* isf)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo nó na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_for;				//Coloca etiqueta a informar que é uma "atribuicao"
	is->conteudo.u_for = (struct is_for*) isf;	//Guarda o conteúdo
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_fc_statement
 *	cria um statement a partir de uma func_call
 */
is_statement_list* insert_fc_statement( is_func_call* ifc)
{
	is_statement_list* istl = (is_statement_list*) malloc( sizeof(is_statement_list) );	//Cria novo nó na lista
	
	is_statement* is = (is_statement*) malloc( sizeof(is_statement) );
	is->tipo = d_func_call;				//Coloca etiqueta a informar que é uma "atribuicao"
	is->conteudo.u_func_call = (struct is_func_call*) ifc;	//Guarda o conteúdo
	
	istl->stt=is;
		
	return istl;		
}

/*
 *	insert_statement_list
 *	adiciona à lista list os statements da lista stts
 */
is_statement_list* insert_statement_list( is_statement_list* list, is_statement_list* stts )
{
	
	if(list==NULL)		//Se a lista estiver vazia
		return stts;		//Devolve o nó criado

	is_statement_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = stts;					//adiciona no final da lista
	return list;
}

/*
 *  insert_declaracao
 *  adiciona o tipo de atributo a uma lista de atributos
 */
is_declaracao* insert_declaracao(int line, is_atribuicao_list* list, is_tipo tipo)
{
    is_declaracao* id = (is_declaracao*) malloc(sizeof(is_declaracao));
    id->tipo = tipo;
    id->list = list;
    id->codeline = line;

    return id;
}

/*
 *	insert_metodo
 *	cria um método a partir de um tipo, um nome e uma expressão
 */
is_metodo* insert_metodo( int line, is_tipo tipo, char* nome, is_argumento_list *arg_list, is_statement_list *list )
{
    is_metodo *im = (is_metodo*) malloc( sizeof(is_metodo) );
    im->tipo = tipo;		//Guarda tipo
    im->nome = nome;		//Guarda nome
    im->arg_list = (struct is_argumento_list*) arg_list;
    im->list = (struct is_statement_list*) list;			//Guarda expressão
    im->codeline = line;
    
    return im;
}

/*
 *	insert_expression_list
 *	adiciona à lista list a expressão exp
 */
is_expressao_list* insert_expression_list( is_expressao_list* list, is_expressao* exp )
{
	is_expressao_list* iel = (is_expressao_list*) malloc( sizeof(is_expressao_list) );	//Cria novo nó na lista
	iel->expr = exp;				//Preenche-o
	
	if(list==NULL)		//Se a lista estiver vazia
		return iel;		//Devolve o nó criado

	is_expressao_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = iel;					//adiciona no final da lista
	
	return list;
}

/*
 *	insert_i_expression
 *	cria uma expression a partir de uma infix_expression
 */
is_expressao* insert_i_expression(int line,  is_infix_expression* expression )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_infix_exp;				//Coloca etiqueta a informar que é um "infix expression"
	ie->conteudo.u_infix_exp = (struct is_infix_expression*) expression;	//Guarda o conteúdo
	ie->codeline = line;
	return ie;		
}

/*
 *	insert_u_expression
 *	cria uma expression a partir de uma unary_expression
 */
is_expressao* insert_u_expression(int line, is_unary_expression* expression )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_unary_exp;				//Coloca etiqueta a informar que é um "unary expression"
	ie->conteudo.u_unary_exp = (struct is_unary_expression*) expression;	//Guarda o conteúdo
	ie->codeline = line;
	return ie;		
}

/*
 *	insert_NUMBER
 *	cria uma expressão a partir de um número
 */
is_expressao* insert_NUMBER(int line, int number )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_number;				//Coloca etiqueta a informar que é um numero
	ie->conteudo.number = number;	//Guarda o conteúdo
    ie->codeline = line;
	return ie;
}

/*
 *	insert_FLOAT_NUM
 *	cria uma expressão a partir de um número
 */
is_expressao* insert_FLOAT_NUM(int line, float number )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_float;				//Coloca etiqueta a informar que é um numero
	ie->conteudo.num_float = number;	//Guarda o conteúdo
    ie->codeline = line;
	return ie;
}

/*
 *	insert_VAR
 *	cria uma expressão a partir de uma var
 */
is_expressao* insert_VAR(int line, char* var )
{
	is_expressao* ie = (is_expressao*) malloc( sizeof(is_expressao) );
	ie->tipo = d_var;				//Coloca etiqueta a informar que é um numero
	ie->conteudo.var = var;	//Guarda o conteúdo
    ie->codeline=line;
	return ie;		
}

/*
 *	insert_infix_expression
 *	cria uma infix_expression a partir de duas expressões e um operador
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
 *	cria uma unary_expression a partir de uma expressão
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
 *	adiciona à lista list a expressão arg
 */
is_argumento_list* insert_argumento_list( is_argumento_list* list, is_argumento* arg )
{
	is_argumento_list* ial = (is_argumento_list*) malloc( sizeof(is_argumento_list) );	//Cria novo nó na lista
	ial->arg = arg;				//Preenche-o
	
	if(list==NULL)		//Se a lista estiver vazia
		return ial;		//Devolve o nó criado

	is_argumento_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = ial;					//adiciona no final da lista
	
	return list;
}

/*
 *  insert_print
 *  adiciona um print
 */
is_print* insert_print(int line, is_expressao* exp, char fim)
{
    is_print* print = (is_print*) malloc (sizeof (is_print));
    print->tipo = d_expression;
    print->fim = fim;
    print->conteudo.u_p_exp = (struct is_expressao*)exp;
    print->codeline=line;
    return print;
}

/*
 *  insert_b_tf_expressao
 *  adiciona uma b_tf_expressao
 */
is_b_expressao* insert_b_tf_expressao(int line, char boolean  )
{
    is_b_expressao* ibe = (is_b_expressao*) malloc(sizeof(is_b_expressao));
    ibe->tipo = d_tf;
    ibe->conteudo.boolean = boolean;
    ibe->codeline = line;
    return ibe;
}

/*
 *  insert_comparacao
 *  adiciona uma comparacao a partir de duas expressoes 
 */
is_b_expressao* insert_comparacao(int line, is_expressao* exp1, is_comparator comp, is_expressao* exp2)
{
    is_b_expressao* ibe = (is_b_expressao*) malloc(sizeof(is_b_expressao));
    ibe->tipo = d_comparison;
    
    is_comparison* ic = (is_comparison*) malloc(sizeof(is_comparison));
    ic->exp1 = (is_expressao*) exp1;
    ic->op = comp;
    ic->exp2 = (is_expressao*) exp2;
    
    ibe->conteudo.u_comp = (struct is_comparison*)ic;
    ibe->codeline = line;
    return ibe;
}

/*
 *  insert_b_n_expressao
 *  adiciona uma b_not_expressao
 */
is_b_expressao* insert_b_n_expressao(int line, is_b_expressao* exp)
{
    is_b_expressao* ibe = (is_b_expressao*) malloc(sizeof(is_b_expressao));
    ibe->tipo = d_not_b_exp;
    
    is_b_not_expressao* ibne = (is_b_not_expressao*) malloc(sizeof(is_b_not_expressao));
    ibne->exp = (is_b_expressao*) exp;
    
    ibe->conteudo.u_not_b_exp = (struct is_b_not_expressao*)ibne;
    ibe->codeline = line;
    return ibe;
}

/*
 *  insert_b_i_expressao
 *  adiciona uma b_infix_expressao a partir de duas b_expressoes 
 */
is_b_expressao* insert_b_i_expressao(int line, is_b_expressao* exp1, is_b_operator op, is_b_expressao* exp2)
{
    is_b_expressao* ibe = (is_b_expressao*) malloc(sizeof(is_b_expressao));
    ibe->tipo = d_infix_b_exp;
    
    is_b_infix_expressao* ibie = (is_b_infix_expressao*) malloc(sizeof(is_b_infix_expressao));
    ibie->exp1 = (is_b_expressao*) exp1;
    ibie->op = op;
    ibie->exp2 = (is_b_expressao*) exp2;
    
    ibe->conteudo.u_infix_b_exp = (struct is_b_infix_expressao*)ibie;
    ibe->codeline = line;
    return ibe;
}

/*
 *  insert_if
 *  adiciona um is_if
 */
is_if* insert_if(int line, is_b_expressao* exp, is_statement_list* stt, is_else* ifelse)
{
    is_if* ii = (is_if*) malloc (sizeof(is_if));
    ii->exp = (is_b_expressao*)exp;
    ii->stt = (is_statement_list*)stt;
    ii->codeline = line;
    ii->ifelse = (is_else*)ifelse;
    return ii;
}

/*
 *  insert_if
 *  adiciona um is_else
 */
is_else* insert_else(int line, is_statement_list* stt)
{
    is_else* iiel = (is_else*) malloc (sizeof(is_else));
    iiel->stt = (is_statement_list*)stt;
    iiel->codeline = line;
    return iiel;
}

/*
 *  insert_while
 *  adiciona um is_while
 */
is_while* insert_while(int line, is_b_expressao* exp, is_statement_list* stt)
{
    is_while* iw = (is_while*) malloc (sizeof(is_while));
    iw->exp = (is_b_expressao*)exp;
    iw->stt = (is_statement_list*)stt;
    iw->codeline = line;
    return iw;
}

/*
 *  insert_for
 *  adiciona um is_for
 */
is_for* insert_for(int line, is_statement_list* att, is_b_expressao* ibe, is_expressao* ie, is_statement_list* stt)
{
    is_for* isf = (is_for*) malloc (sizeof(is_for));
    isf->attr = (is_statement_list*)att;
    isf->b_exp = (is_b_expressao*)ibe;
    isf->exp = (is_expressao*)ie;
    isf->stt = (is_statement_list*) stt;
    isf->codeline = line;
    return isf;
}

/*
 *	insert_func_arg_list
 *	adiciona à lista list o argumento arg
 */
is_func_arg_list* insert_func_arg_list( is_func_arg_list* list, is_func_arg_list* arg )
{
	
	if(list==NULL)		//Se a lista estiver vazia
		return arg;		//Devolve o nó criado

	is_func_arg_list* aux;
			
	for(aux=list; aux->next!=NULL; aux=aux->next);	//procura pelo final da lista
	aux->next = arg;					//adiciona no final da lista
	return list;
}

/*
 *  insert_func_arg_exp
 *  adiciona um func_arg que é uma expressao
 */
is_func_arg_list* insert_func_arg_exp(int line, is_expressao* exp)
{
    is_func_arg_list* ifal = (is_func_arg_list*) malloc (sizeof(is_func_arg_list)); 
    
    is_func_arg* ifa = (is_func_arg*) malloc (sizeof(is_func_arg));
    ifa->tipo = d_f_expression;
    ifa->conteudo.exp = (is_expressao*) exp;
    ifa->codeline=line;
    
    ifal->func_arg = ifa;
    
    return ifal;
}

/*
 *  insert_func_arg_b_exp
 *  adiciona um func_arg que é uma b_expressao
 */
is_func_arg_list* insert_func_arg_b_exp(int line, is_b_expressao* b_exp)
{
    is_func_arg_list* ifal = (is_func_arg_list*) malloc (sizeof(is_func_arg_list)); 
    
    is_func_arg* ifa = (is_func_arg*) malloc (sizeof(is_func_arg));
    ifa->tipo = d_f_b_expression;
    ifa->conteudo.b_exp = (is_b_expressao*) b_exp;
    ifa->codeline=line;
    
    ifal->func_arg = ifa;
    
    return ifal;
}

/*
 *  insert func_call
 *  adiciona uma func_call a partir de um nome e lista de argumentos
 */
is_func_call* insert_func_call(int line, char* nome, is_func_arg_list* args)
{
    is_func_call* ifc = (is_func_call*) malloc (sizeof(is_func_call));
    ifc->nome = nome;
    ifc->func_arg = (is_func_arg_list*) args;
    ifc->codeline = line;
    return ifc;
}
