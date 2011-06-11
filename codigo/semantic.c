#include "symbol_table.h"
#include "semantic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int global_offset=0;
int method_returns=0;
int method_scope=0;
int n_for=0;
int n_while=0;
int n_if=0;

/*
 *	chama, para cada is_static, a respectiva função de análise semantica. retorna um prog_env que contem todos os símbolos (globais, locais, methods)
 */
prog_env* semantic_analysis(is_static_list* isl)
{	
	is_static_list *aux;
	prog_env* pe=(prog_env*)malloc(sizeof(prog_env));

	for(aux=isl; aux; aux=aux->next)	
	{
		semantic_analysis_static(pe, aux->stat);
	}
	
	return pe;
}

/*
 *	chama, para cada is_declaration e is_method presente num is_static is a respectiva funcao de analise semantica, com o prog_env pe
 */
void semantic_analysis_static(prog_env *pe, is_static* is)
{
	switch(is->type)
	{
		case stat_declaration:
		    pe->global=semantic_analysis_declaration(GLOBALSCOPE, pe, pe->global,(is_declaration *)(is->content.dec));
		    break;
		case stat_method:
		    semantic_analysis_method(pe, (is_method *)(is->content.method));
		    break;
	}	
}

/*
 *	faz a analise semantica de um is_method a partir de um prog_env pe e de um is_method im
 */
void semantic_analysis_method(prog_env *pe, is_method* im)
{
	environment_list *aux, *pl;
	table_element *te;	
    
    //se ja houver um metodo ou variavel global com o mesmo name imprime um erro
	if(lookup(pe->global, im->name))
	{
		printf("line %d: error: symbol %s already defined! Cannot create method!\n", im->codeline,im->name);
		errors++;
	}
	else
	{
		//cria uma nova entrada para a environment_list que corresponde ao ambiente do proprio metodo
		pl=(environment_list*)malloc(sizeof(environment_list));
		if(pe->procs==NULL)
		    pe->procs=pl;
	    else
	    {
		    for(aux=pe->procs; aux->next; aux=aux->next);
		    aux->next=pl;
	    }
		//guarda o simbolo correspondente ao metodo verificando se a lista de simbolos esta ou nao vazia
		te=pe->global;
		if(te==NULL)
			pe->global=create_symbol(-1, im->name, im->type,is_METHOD);
		else
		{
			for(; te->next; te=te->next);					
			te->next=create_symbol(-1, im->name, im->type,is_METHOD);
		}
		pl->name=(char*)strdup(im->name);	
		//faz a analise semantica dos arguments e statements do metodo
		pl->locals=semantic_analysis_argument_list(pe, pl->locals, (is_argument_list *)(im->arg_list), im->name, im->codeline);
		pl->locals=semantic_analysis_statement_list(pe, pl->locals, (is_statement_list *)(im->stt_list), im->type);
		method_scope=0;
		if(method_returns==0 && im->type!=is_VOID){
		    printf("line %d: error: missing return statement!\n",im->codeline);
		    errors++;
		}
		method_returns=0;
		    
	}
    //guarda o novo ambiente na environment_list verificando se esta se encontra ou nao vazia
}

/*
 *  faz a analise semantica de um is_return a partir de um prog_env pe, um table_element env, um is_return return_val e um is_type type correspondente ao tipo que o respectivo metodo devolve
 */
void semantic_analysis_return(prog_env *pe, table_element* env, is_return* return_val, is_type type)
{
    if(method_scope==0)
        method_returns++;
    //se o tipo de return_val for void mas o respectivo metodo nao retornar void imprime o erro
    if(return_val->type==ret_void && type!=is_VOID){
        errors++;
        printf("line %d: error: method return type is %s but found void!\n", return_val->codeline, type_to_string(type));
    }
    //se o tipo do return_val for uma b_expression mas o respectivo metodo nao retornar um boolean imprime o erro
    else if(return_val->type==ret_b_expression){
        is_type temp = semantic_analysis_b_expression(pe, env, return_val->content.b_exp);
        if(temp==-1)
            return;
        if(temp!=type){
            errors++;
            printf("line %d: error: method return type is %s but found %s!\n", return_val->codeline, type_to_string(type), type_to_string(temp));
        }
    }
    //se o tipo do return_val for uma expression
    else if(return_val->type==ret_expression){
        //verifica o tipo da expression
        is_type temp = semantic_analysis_expression(pe, env, return_val->content.exp);
        if(temp==-1)
            return;
        if(temp != type){
            printf("line %d: error: method return type is %s but found %s!\n", return_val->codeline, type_to_string(type), type_to_string(temp));            
            errors++;
        }
    }
}
/*
 *  faz a analise semantica de um is_declaration a partir de um int scope, prog_env pe, um table_element env, e uma is_declaration id
 *  retorna um table_element ja que esta operacao altera a tabela de simbolos do ambiente
 */
table_element* semantic_analysis_declaration(int scope, prog_env *pe, table_element* env, is_declaration* id)
{
	table_element* aux = (table_element*) malloc(sizeof(table_element));
	//chama a funcao de analise semantica para a is_attribution_list da is_declaration id
	aux=semantic_analysis_attribution_list(scope, pe, env, id->list, id->type);
    return aux;
}

/*
 *  chama a funcao de analise semantica para cada is_attribution da is_attribution_list ial. o is_type type corresponde ao tipo declarado na declaracao
 *  retorna um table_element ja que esta operacao altera a tabela de simbolos do ambiente
 */
table_element* semantic_analysis_attribution_list(int scope, prog_env *pe, table_element* env, is_attribution_list* ial, is_type type)
{
	is_attribution_list* aux;
	table_element* aux1;
	int offset;
	if(env==NULL)
	    offset=0;
	else if(env->stype==is_ARGUMENT){
	    for(aux1=env; aux1->next; aux1=aux1->next);
	    offset=aux1->offset+1;
	}
	else
	    offset=env->offset+1;
	table_element* stmp=env;

	for(aux=ial; aux; aux=aux->next)
		stmp=semantic_analysis_attribution_dec((scope==LOCALSCOPE?offset++:global_offset++), pe, stmp, aux->attr, type);
	return stmp;
}

/*
 *  faz a analise semantica de uma atribuicao quando esta esta relacionada com uma declaracao. o is_type type corresponde ao tipo declarado na declaracao
 *  retorna um table_element ja que esta operacao altera a tabela de simbolos do ambiente
 */
table_element* semantic_analysis_attribution_dec(int offset, prog_env* pe, table_element* env, is_attribution* ia, is_type type)
{
	table_element *aux, *stmp=env;
	//se o tipo da is_attribution ia for uma is_expression e esta nao for nula
    if(ia->type == attr_expression && ia->content.exp != NULL){
        //verifica o tipo da expression e imprime o erro se forem diferentes
        is_type temp = semantic_analysis_expression(pe,env,(is_expression*)ia->content.exp);
        if(temp==-1)
            return stmp;
        if(type!=temp){
            printf("line %d: error: trying to define %s (%s) as %s!\n", ia->codeline, ia->name, type_to_string(type), type_to_string(temp));
            errors++;
            return stmp;
        }
    }
    //se o tipo da is_attribution ia for uma is_b_expression
    else if(ia->type == attr_b_expression){
        is_type temp = semantic_analysis_b_expression(pe, env, (is_b_expression*) ia->content.b_exp);
        //verifica o tipo da expression e imprime o erro se nao for um boolean
        if(type!=temp){
            printf("line %d: error: trying to define %s (%s) as %s!\n", ia->codeline, ia->name, type_to_string(type), type_to_string(temp));
            errors++;
            return stmp;
        }
    }
    //procura primeiro se ja existe um metodo com o mesmo nome, encontrando imprime o erro
	aux=lookup(pe->global, ia->name);
	if(aux!=0 && aux->stype==is_METHOD)
	{
		printf("line %d: error: Cannot define %s, already defined as method!\n", ia->codeline, ia->name);
		errors++;
		return stmp;
	}
	//procura tambem se ja existe uma variavel com o mesmo nome no ambiente do metodo
	aux=lookup(env, ia->name);
	if(aux!=0)
	{
		printf("line %d: error: %s already defined!\n", ia->codeline, ia->name);
		errors++;
		return stmp;
	}
	//nao havendo problemas adiciona a variavel à tabela de simbolos do metodo
	if(stmp==NULL)
		env=create_symbol(offset, ia->name, type,is_VAR);
	else {
	    env=create_symbol(offset, ia->name, type,is_VAR);
		env->next=stmp;
	}
	return env;
}

/*
 *  faz a analise semantica de uma atribuicao quando esta esta nao relacionada com uma declaracao
 */
void semantic_analysis_attribution(prog_env* pe, table_element* env, is_attribution* ia)
{
	table_element *aux;
	//procura a variavel primeiro no ambiente do metodo e depois no ambiente global. se nao encontrar a variavel em nenhum imprime o erro
    aux=lookup(env, ia->name);
    if(aux==0){
        aux=lookup(pe->global, ia->name);
	    if(aux==0){
	        printf("line %d: error: %s is not defined!\n", ia->codeline, ia->name);
            errors++;
            return;
        }
        else if(aux!=0 && aux->stype==is_METHOD){
            printf("line %d: error: Cannot define %s, already defined as method!\n", ia->codeline, ia->name);
            errors++;
            return;
        }
    }
    //se o tipo da atribuicao for um expression
    if(ia->type==attr_expression){
        //verifica o tipo da is_expression e caso sejam de tipos diferentes imprime o erro
        is_type temp = semantic_analysis_expression(pe, env, (is_expression*) ia->content.exp);
	    if(temp==-1)
	        return;
	    if(aux->type!=temp){
		    printf("line %d: error: trying to define %s (%s) as %s!\n", ia->codeline, ia->name, type_to_string(aux->type), type_to_string(temp));
	        errors++;
	        return;
	    }
	}
	//se o tipo da atribuicao for uma b_expression e a variavel nao for um boolean imprime o erro
	else{
	    is_type temp = semantic_analysis_b_expression(pe, env, (is_b_expression*) ia->content.b_exp);
	    if(aux->type!=temp){
	        printf("line %d: error: trying to define %s (%s) as %s!\n", ia->codeline, ia->name, type_to_string(aux->type), type_to_string(temp));
	        errors++;
	        return;
	    }   
	}
}

/*
 *  faz a analise semantica de uma is_argument_list. o char method corresponde ao nome do respectivo metodo e o int line à linha da declaracao do metodo
 *  retorna um table_element ja que esta operacao altera a tabela de simbolos do ambiente
 */
table_element* semantic_analysis_argument_list(prog_env* pe, table_element* env, is_argument_list* ial, char* method, int line)
{
	is_argument_list* aux;
	int offset=0;
	table_element* stmp=env;
	for(aux=ial; aux; aux=aux->next){
		stmp=semantic_analysis_argument(offset++, pe, stmp, aux->arg, method, line);
	}
	return stmp;
}

/*
 *  faz a analise semantica de uma is_argument. o char method corresponde ao nome do respectivo metodo e o int line à linha da declaracao do metodo
 *  retorna um table_element ja que esta operacao altera a tabela de simbolos do ambiente
 */
table_element* semantic_analysis_argument(int offset, prog_env* pe, table_element* env, is_argument* arg, char* method, int line)
{
	table_element *aux, *stmp=env;
    aux=lookup(env, arg->name);
    if(aux!=0){
		printf("line %d: error: %s already defined!\n", line, arg->name);
		errors++;
		return stmp;
	}
	if(stmp==NULL)
		env=create_symbol(offset, arg->name, arg->type ,is_ARGUMENT);
	else {
	    for(stmp=env; stmp->next; stmp=stmp->next);
		stmp->next=create_symbol(offset, arg->name, arg->type,is_ARGUMENT);
	}
	return env;
}

/*
 *  faz a analise semantica de uma is_statement_list. o is_type type corresponde ao tipo do respectivo metodo
 *  retorna um table_element ja que esta operacao altera a tabela de simbolos do ambiente
 */
table_element* semantic_analysis_statement_list(prog_env *pe, table_element* env, is_statement_list* isl, is_type type)
{
	is_statement_list* aux;
    table_element* stmp = env;
	for(aux=isl; aux; aux=aux->next){
		stmp=semantic_analysis_statement(pe, stmp, aux->stt, type);
	}
	return stmp;
}

/*
 *  faz a analise semantica de uma is_statement. o is_type type corresponde ao tipo do respectivo metodo
 *  retorna um table_element ja que esta operacao altera a tabela de simbolos do ambiente
 */
table_element* semantic_analysis_statement(prog_env *pe, table_element* env, is_statement* is, is_type type)
{
	switch(is->type)
	{
		case stt_attribution: 
		    semantic_analysis_attribution(pe, env, (is_attribution *)(is->content.attr));
		    break;
		case stt_declaration: 
		    return semantic_analysis_declaration(LOCALSCOPE, pe, env,(is_declaration *)(is->content.dec));
		case stt_print: 
		    semantic_analysis_print(pe, env, (is_print*)(is->content._print)); 
		    break;
		case stt_if:
		    semantic_analysis_if(pe, env, (is_if*)(is->content._if), type);
		    break;
		case stt_while: 
		    semantic_analysis_while(pe, env, (is_while*)(is->content._while), type);
		    break;
		case stt_for: 
		    semantic_analysis_for(pe, env, (is_for*)(is->content._for), type);
		    break;
		case stt_m_call: 
		    semantic_analysis_method_call(pe, env, (is_method_call*)(is->content.m_call));
		    break;
		case stt_return: 
		    semantic_analysis_return(pe, env, (is_return*)(is->content._return), type);
		    break;
		case stt_inc:
		    semantic_analysis_increment(pe, env, (is_increment*)(is->content.inc));
		    break;
	}
	return env;
		
}

/*
 *  faz a analise semantica de uma is_expression
 */
is_type semantic_analysis_expression(prog_env* pe, table_element* env, is_expression* ie)
{
	is_type temp=-1;
	switch(ie->type)
	{
		case exp_infix: 
		    temp= semantic_analysis_infix_exp(pe, env, (is_infix_expression*)(ie->content.infix_exp), ie->codeline);
		    break;
		case exp_unary: 
		    temp= semantic_analysis_s_expression(pe,env, (is_s_expression*)(((is_unary_expression*)(ie->content.unary_exp))->exp), ie->codeline);
		    break;
		case exp_int: 
		    temp= is_INT;
		    break;
		case exp_double: 
		    temp= is_DOUBLE;
		    break;
		case exp_char:
		    temp= is_CHAR;
		    break; 
	}
	ie->val_type=temp;
	return temp;
}

/*
 *  faz a analise semantica de uma is_infix_expression
 */
is_type semantic_analysis_infix_exp(prog_env* pe, table_element* env, is_infix_expression* exp, int line)
{
    is_type type1 = semantic_analysis_s_expression(pe, env, exp->exp1, line);
    is_type type2 = semantic_analysis_s_expression(pe, env, exp->exp2, line);
    is_type temp = -1;
    
    if(type1==-1 || type2==-1)
        temp=-1;
        
    if((type1==is_BOOLEAN && type2!=is_BOOLEAN) || (type1!=is_BOOLEAN && type2==is_BOOLEAN)){
        printf("line %d: error: invalid operation for boolean\n", line);
        errors++;
        temp=-1;
    }
    if(type1==is_DOUBLE || type2==is_DOUBLE )
        temp=is_DOUBLE;
        
    else if(type1==is_INT || type2==is_INT )
        temp=is_INT;
    else
        temp=is_CHAR;
    exp->val_type=temp;
    return temp;
}

is_type semantic_analysis_s_expression(prog_env* pe, table_element* env, is_s_expression* exp, int line)
{
    is_type temp = -1;
    switch(exp->type){
        case s_exp_var: 
            temp= semantic_analysis_var(pe, env, exp->content.var, line);
            break;
        case s_exp_exp: 
            temp= semantic_analysis_expression(pe, env, (is_expression*)exp->content.exp);
            break;
        case s_exp_m_call: 
            temp= semantic_analysis_method_call(pe, env, (is_method_call*) (exp->content.m_call));
            break;
        case s_exp_inc: 
            temp= semantic_analysis_increment(pe, env, (is_increment*)(exp->content.inc));
            break;
    }
    return temp;
}

/*
 *  faz a analise semantica de uma variavel. o int line corresponde à linha da expressao correspondente
 */
is_type semantic_analysis_var(prog_env* pe, table_element* env, char* var, int line)
{
    table_element *aux;
    is_type temp = -1;
	aux=lookup(env, var);
	if(aux==0){
	    aux=lookup(pe->global, var);
		if(aux==0 || aux->stype==is_METHOD){
		    printf("line %d: error: %s is not defined!\n", line, var);
            errors++;
            return -1;
        }
	    else if(aux!=0 && aux->stype!=is_METHOD){
	         temp = aux->type;
        }
    }
    temp = aux->type;
    return temp;
}

/*
 *  faz a analise semantica de uma b_expression
 */
is_type semantic_analysis_b_expression(prog_env* pe, table_element* env, is_b_expression* ibe)
{
    is_type temp = -1;
    switch(ibe->type)
	{
		case b_exp_infix: 
		    temp= semantic_analysis_b_infix_exp(pe, env, (is_b_infix_expression*)(ibe->content.infix_b_exp));
		    break;
		case b_exp_not: 
		    temp= semantic_analysis_b_expression(pe, env, (is_b_expression*)((is_b_not_expression*)ibe->content.not_b_exp)->exp);
		    break;
		case b_exp_bool:
		    temp= is_BOOLEAN;
		    break;
		case b_exp_comp: 
		    temp= semantic_analysis_comparison(pe, env, (is_comparison*)(ibe->content.comp), ibe->codeline);
		    break;
		case b_exp_var: 
		    temp= semantic_analysis_var(pe, env, ibe->content.var, ibe->codeline);
		    break;
		case b_exp_m_call:
		    temp= semantic_analysis_method_call(pe, env, (is_method_call*) (ibe->content.m_call));
		    break;
		case b_exp_inc:
		    temp= semantic_analysis_increment(pe, env, (is_increment*)(ibe->content.inc));
	        break;
	}
	ibe->val_type = temp;
	return temp;
}

/*
 *  faz a analise semantica de uma b_infix_expression
 */
is_type semantic_analysis_b_infix_exp(prog_env* pe, table_element* env, is_b_infix_expression* ibe)
{
    is_type temp=-1;
    is_type a = semantic_analysis_b_expression(pe, env, ibe->exp1);
    is_type b = semantic_analysis_b_expression(pe, env, ibe->exp2);
    if(a!=is_BOOLEAN){
        printf("line %d: error: invalid operation for %s!\n",line, type_to_string(a));
        errors++;
        return -1;
    }
    if(b!=is_BOOLEAN){
        printf("line %d: error: invalid operation for %s!\n",line, type_to_string(b));
        errors++;
        return -1;
    }
    if(a == -1 || b == -1)
        return -1;
    temp = is_BOOLEAN;
    ibe->val_type = temp;
    return temp;
}

/*
 *  faz a analise semantica de uma comparison
 */
is_type semantic_analysis_comparison(prog_env* pe, table_element* env, is_comparison* comp, int line)
{
    is_type temp=-1;
    is_type a = semantic_analysis_s_expression(pe, env, comp->exp1, line);
    is_type b = semantic_analysis_s_expression(pe, env, comp->exp2, line);
    if((a==is_BOOLEAN && b!=is_BOOLEAN) || (a!=is_BOOLEAN && b==is_BOOLEAN)){
        printf("line %d: error: trying to compare %s with %s!\n",line, type_to_string(a), type_to_string(b));
        errors++;
        return -1;
    }
    if(a == -1 || b == -1)
        return -1;
    temp=is_BOOLEAN;
    comp->val_type=temp;
    return temp;
}

/*
 *  faz a analise semantica de um is_print
 */
void semantic_analysis_print(prog_env* pe, table_element* env, is_print* ip)
{
	switch(ip->type)
	{
		case print_expression: ip->exp_type = semantic_analysis_s_expression(pe, env, (is_s_expression*)(ip->content.exp), ip->codeline);break;
	}
}

/*
 *  faz a analise semantica de um is_if. o is_type type corresponde ao tipo do metodo respectivo
 */
void semantic_analysis_if(prog_env* pe, table_element* env, is_if* ii, is_type type)
{
    method_scope++;
    environment_list* aux;
    is_type temp = semantic_analysis_b_expression(pe, env, (is_b_expression*)(ii->exp));
    if(temp!=is_BOOLEAN){
        errors++;
        printf("line %d: error: not a boolean!\n",ii->exp->codeline);
    }
	//cria uma nova entrada para a environment_list que corresponde ao ambiente do if
	environment_list* pl=(environment_list*)malloc(sizeof(environment_list));
	if(pe->procs==NULL)
		pe->procs=pl;
	else
	{
		for(aux=pe->procs; aux->next; aux=aux->next);
		aux->next=pl;
	}
	pl->name=(char*)strdup("if");
	char temp_n[20];
	sprintf(temp_n, "%d", n_if);
	strcat(pl->name, temp_n);
	n_if++;
	//faz a analise semantica dos arguments e statements do if
	pl->locals = semantic_analysis_statement_list(pe, env, ii->stt, type);
	if(ii->ifelse)
	    semantic_analysis_else(pe, env, ii->ifelse, type, temp_n);
	method_scope--;
}

/*
 *  faz a analise semantica de um is_else. o is_type type corresponde ao tipo do metodo respectivo
 */
void semantic_analysis_else(prog_env* pe, table_element* env, is_else* iiel, is_type type, char* n)
{
	environment_list* aux;
	//cria uma nova entrada para a environment_list que corresponde ao ambiente do else
	environment_list* pl=(environment_list*)malloc(sizeof(environment_list));
	//guarda o novo ambiente na environment_list verificando se esta se encontra ou nao vazia
	if(pe->procs==NULL)
		pe->procs=pl;
	else
	{
		for(aux=pe->procs; aux->next; aux=aux->next);
		aux->next=pl;
	}
	pl->name=(char*)strdup("else");
	strcat(pl->name, n);
	//faz a analise semantica dos arguments e statements do else
	pl->locals=semantic_analysis_statement_list(pe, env, iiel->stt, type);
}

/*
 *  faz a analise semantica de um is_while. o is_type type corresponde ao tipo do metodo respectivo
 */
void semantic_analysis_while(prog_env* pe, table_element* env, is_while* iw, is_type type)
{
	method_scope++;
	environment_list* aux;
    //cria uma nova entrada para a environment_list que corresponde ao ambiente do while
	environment_list* pl=(environment_list*)malloc(sizeof(environment_list));
	//guarda o novo ambiente na environment_list verificando se esta se encontra ou nao vazia
	if(pe->procs==NULL)
		pe->procs=pl;
	else
	{
		for(aux=pe->procs; aux->next; aux=aux->next);
		aux->next=pl;
	}
	pl->name=(char*)strdup("while");
	char temp_n[20];
	sprintf(temp_n, "%d", n_while);
	strcat(pl->name, temp_n);
	printf("%s\n",pl->name);
	n_while++;
    semantic_analysis_b_expression(pe, env, (is_b_expression*)(iw->exp));
	pl->locals=semantic_analysis_statement_list(pe, env, iw->stt, type);
	method_scope--;
}

/*
 *  faz a analise semantica de um for. o is_type type corresponde ao tipo do metodo respectivo
 */
void semantic_analysis_for(prog_env* pe, table_element* env, is_for* isf, is_type type)
{
	method_scope++;
	environment_list* aux;
    //cria uma nova entrada para a environment_list que corresponde ao ambiente do for
	environment_list* pl=(environment_list*)malloc(sizeof(environment_list));
	//guarda o novo ambiente na environment_list verificando se esta se encontra ou nao vazia
	if(pe->procs==NULL)
		pe->procs=pl;
	else
	{
		for(aux=pe->procs; aux->next; aux=aux->next);
		aux->next=pl;
	}
	pl->name=(char*)strdup("for");
	char temp_n[20];
	sprintf(temp_n, "%d", n_for);
	strcat(pl->name, temp_n);
	n_for++;
	//faz a analise semantica dos arguments e statements do for
	pl->locals=semantic_analysis_statement_list(pe, env, (is_statement_list*)(isf->attr), type);
	semantic_analysis_b_expression(pe, env, (is_b_expression*)(isf->b_exp));
	semantic_analysis_statement_list(pe, env, (is_statement_list*)(isf->last), type);
	pl->locals=semantic_analysis_statement_list(pe, pl->locals, (is_statement_list*)(isf->stt), type);
	method_scope--;
}

/*
 *  faz a analise semantica de um method_call
 */
is_type semantic_analysis_method_call(prog_env* pe, table_element* env, is_method_call* imc)
{
    table_element* aux = lookup(pe->global, imc->name);
    if(aux==0 || aux->stype != is_METHOD){
        printf("line %d: error: %s is not defined!\n", imc->codeline, imc->name);
        errors++;
        return -1;
    }
    if(semantic_analysis_method_arg_list(pe, env, imc->m_arg_list, imc->name, imc->codeline)==-1)
        return -1;
    return aux->type;
}

/*
 *  faz a analise semantica de uma lista de argumentos de um metodo. o char name corresponde ao nome do metodo e o int line corresponde à linha da chamada do metodo
 */
int semantic_analysis_method_arg_list(prog_env* pe, table_element* env, is_method_arg_list* imal, char* name, int line)
{
    is_method_arg_list* aux = (is_method_arg_list*) malloc (sizeof(is_method_arg_list));
    //procura o ambiente do metodo respectivo
    table_element* aux2 = mlookup(pe->procs, name)->locals;
    int count=1;
    int err_count_sup=0;
    int err_count_inf=0;
    for(aux=imal; aux; aux=aux->next)
    {
        //vai-se contabilizando o numero de argumentos colocados na chamada do metodo
        if(aux2->stype!=is_ARGUMENT)
            continue;
        if(aux2==NULL){
            err_count_sup++;
            continue;
        }
        if(semantic_analysis_method_arg(pe, env, aux->m_arg, aux2, count)==-1)
            return -1;
        //avança-se tambem nos argumentos da declaracao do metodo
        aux2=aux2->next;
        count++;
    }
    //no final verifica-se se foram colocados argumentos a mais ou a menos e imprime os erros
    for(;aux2; aux2=aux2->next)
        if(aux2->stype==is_ARGUMENT)
            err_count_inf++;
        else
            break;
    if(err_count_sup!=0){
        printf("line %d: error: expected %d arguments but found %d!\n", line, count-1, count+err_count_sup-1);
        errors++;
        return -1;
    }
    else if(err_count_inf!=0){
        printf("line %d: error: expected %d arguments but found %d!\n", line, count+err_count_inf-1, count-1);
        errors++;
        return -1;
    }
    return 0;
}

/*
 *  procura um determinado metodo
 */
environment_list* mlookup(environment_list* env, char* name)
{
    environment_list* el;
    for(el=env; el; el=el->next)
        if(strcmp(el->name, name)==0)
            return el;
    return NULL;
}

/*
 *  faz a analise semantica do argumento de uma chamada de metodo, verificando se o tipo do argumento corresponde
 */
int semantic_analysis_method_arg(prog_env* pe, table_element* env, is_method_arg* ima, table_element* arg, int arg_num)
{
    is_type temp;
    switch(ima->type)
    {
        case arg_expression: 
            temp = semantic_analysis_expression(pe, env, ima->content.exp);
            if(temp==-1)
                return -1;
            if(arg->type!=temp){
                printf("line %d: error: (argument %d) expected %s but found %s!\n", ima->codeline, arg_num, type_to_string(arg->type), type_to_string(temp));
                errors++;
                return -1;
            }
            break;
        case arg_b_expression: 
            temp = semantic_analysis_b_expression(pe, env, ima->content.b_exp);
            if(temp == -1)
                return -1;
            if(arg->type != temp){
                printf("line %d: error: (argument %d) expected %s but found %s!\n", ima->codeline, arg_num, type_to_string(arg->type), type_to_string(temp));
                errors++;
                return -1;
            }
            break;
    }
    return 0;
}

is_type semantic_analysis_increment(prog_env* pe, table_element* env, is_increment* inc)
{
    is_type temp = semantic_analysis_var(pe, env, inc->var, inc->codeline);
    if(temp==is_BOOLEAN){
        printf("line %d: error: invalid operation for boolean!\n",inc->codeline);
        errors++;
        return -1;
    }
    return temp;
}

/*
 *  converte um tipo para uma string
 */
char* type_to_string(is_type type)
{
	switch(type)
	{
		case is_INT:		return "int";
		case is_STRING:		return "String";
		case is_VOID:		return "void";
		case is_FLOAT:		return "float";
		case is_DOUBLE:		return "double";
		case is_BOOLEAN:	return "Boolean";
		case is_CHAR:		return "char";
		case is_NONE:       return "none";
	}
	return "unknown type";
}

char* sym_type_to_string(sym_type type){
    switch(type)
	{
		case is_METHOD:		return "method";
		case is_ARGUMENT:	return "arg";
		case is_VAR:		return "";
	}
	return "unknown type";
}

/*
 *  converte um tipo de simbolo para uma string
 */
table_element* create_symbol(int offset, char* name, is_type type, sym_type stype)
{
	table_element* el=(table_element*)malloc(sizeof(table_element));
	strcpy(el->name,name);
	el->type=type;
	el->next=NULL;
	el->offset=offset;
	el->stype=stype;
	return el;
}

/*
 *  procura um simbolo pelo char str num ambiente table
 */
table_element *lookup(table_element* table, char *str)
{
	table_element *aux;

	for(aux=table; aux; aux=aux->next)
		if(strcmp(aux->name, str)==0)
			return aux;

	return 0;
}
