#include "symbol_table.h"
#include "semantic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum {LOCALSCOPE, GLOBALSCOPE};

int global_offset=0;
int maincount;

prog_env* semantic_analysis(is_static_list* isl) //an‡ltyise sem‰ntica da lista de blocos, ou seja do nosso programa
{	
	is_static_list *aux;

	prog_env* pe=(prog_env*)malloc(sizeof(prog_env));		//criação do program_environment, que conter‡ todas os símbolos (globais, locais, procedimentos)

	//vamos fazer an‡lise sem‰ntica bloco a bloco
	for(aux=isl; aux; aux=aux->next)	
	{
	
		//Note-se que se envia o program environment existente. Para o bloco poder verificar, por exemplo, se um dado procedimento existe, ou uma vari‡vel global
		semantic_analysis_block(pe, aux->stat);
	}
	
	return pe;
}

void semantic_analysis_block(prog_env *pe, is_static* is)
{
	//faz a triagem do bloco a analisar
	switch(is->tipo)
	{
		//case d_atribuicao: semantic_analysis_atribuicao_dec(pe, pe->global, (is_atributo *)(is->conteudo.u_atributo));break;
		case d_declaracao: pe->global=semantic_analysis_declaration(GLOBALSCOPE, pe, pe->global,(is_declaracao *)(is->conteudo.u_declaracao));break;
		case d_metodo: semantic_analysis_method(pe, (is_metodo *)(is->conteudo.u_metodo));break;
	/*
	case d_procedure: semantic_analysis_procedure(pe, ip->data_block.u_procedure);  break;
	case d_globals: semantic_analysis_globals(pe, ip->data_block.u_globals);break;
	*/
	}	
}

void semantic_analysis_method(prog_env *pe, is_metodo* im)
{
	environment_list *aux;
	table_element *te;	
	environment_list *pl;

	if(lookup(pe->global, im->nome))
	{
		printf("Symbol %s already defined! Cannot create method!\n", im->nome);
		errors++;
	}
	else
	{
		pl=(environment_list*)malloc(sizeof(environment_list)); //cria um nodo para a lista de ambientes 
																//(que Ž mantida no program environment)
		
		te=pe->global; //Vai buscar tabela de simbolos globais
        
		//adiciona entrada para procedimento
		//na tabela de simbolos global. offset = -1 =>procedimento.
		//Serve apenas para facilitar na pesquisa (na realidade, Ž uma redundncia, pois
		//haver‡ tambŽm uma entrada na lista de ambientes)
		if(te==NULL)
			pe->global=create_symbol(-1, im->nome, im->tipo,is_METHOD);
		else
		{
			for(; te->next; te=te->next);					
			te->next=create_symbol(-1, im->nome, im->tipo,is_METHOD);
		}
		
		//preenche entrada para o procedimento na lista de ambientes
		pl->name=(char*)strdup(im->nome);	
		//pl->locals=(table_element*)malloc(sizeof(table_element));

		//faz an‡lise sem‰ntica do procedimento
		// Ž aqui que vai adicionando os s’mbolos encontrados dentro do procedimento ao ambiente (representado por pl->locals)
		pl->locals=semantic_analysis_argumento_list(pe, pl->locals, (is_argumento_list *)(im->arg_list), im->nome);
		pl->locals=semantic_analysis_statement_list(pe, pl->locals, (is_statement_list *)(im->list));
		semantic_analysis_return(pe, pl->locals, (is_return*)(im->return_val), im->tipo);
		
		/*
		semantic_analysis_vardeclist(LOCALSCOPE, pe, pl->locals, im->vlist);	
		semantic_analysis_statement_list(pe, pl->locals, im->slist);
		*/
	}

	//Adiciona ao program environment
	if(pe->procs==NULL)	//Caso seja o primeiro procedimento, fica na cabea
		pe->procs=pl;
	else			//sen‹o, fica na cauda
	{
		for(aux=pe->procs; aux->next; aux=aux->next);
			aux->next=pl;
	}
}

void semantic_analysis_return(prog_env *pe, table_element* stable, is_return* return_val, is_tipo tipo)
{
    if(return_val->tipo==d_r_void && tipo!=is_VOID){
        errors++;
        printf("line %d: error: method return type is %s but found void!\n", return_val->codeline, typeToString(tipo));
    }
    else if(return_val->tipo==d_r_b_expression && tipo!=is_BOOLEAN){
        errors++;
        printf("line %d: error: method return type is %s but found boolean!\n", return_val->codeline, typeToString(tipo));
    }
    else if(return_val->tipo==d_r_expression && tipo==is_BOOLEAN){
        is_tipo temp=check_expression_type(pe, stable, return_val->conteudo.exp);
        if(temp==-1)
            return;
        printf("line %d: error: method return type is boolean but found %s!\n", return_val->codeline, typeToString(temp));
        errors++;
    }
    else if(return_val->tipo==d_r_expression && tipo!=is_BOOLEAN){
        is_tipo temp = check_expression_type(pe, stable, return_val->conteudo.exp);
        if(temp==-1)
            return;
        if(temp != tipo){
            printf("line %d: error: method return type is %s but found %s!\n", return_val->codeline, typeToString(tipo), typeToString(temp));            
            errors++;
        }
    }
}
//An‡lise das declara›es de vari‡veis globais
table_element* semantic_analysis_declaration(int scope, prog_env *pe, table_element* env, is_declaracao* id)
{
	table_element* aux = (table_element*) malloc(sizeof(table_element));
	aux=semantic_analysis_atribuicao_list(scope, pe, env, id->list, id->tipo);	//0 -> global
    return aux;
}


//An‡lise de declara›es de vari‡veis
//Ž necess‡rio saber o scope para saber onde calcular o offset das vari‡veis nos registos de activa‹o
table_element* semantic_analysis_atribuicao_list(int scope, prog_env *pe, table_element* stable, is_atribuicao_list* ial, is_tipo tipo)
{
	is_atribuicao_list* aux;
	int offset=0;
	table_element* stmp=stable;

	for(aux=ial; aux; aux=aux->next)
		stmp=semantic_analysis_atribuicao_dec((scope==LOCALSCOPE?offset++:global_offset++), pe, stmp, aux->attr, tipo);
	return stmp;
}

//Dependendo do scope, esta função verifica primeiro se j‡ existe a vari‡vel nas tabelas de símbolos. Não pode existir na tabela de símbolos "corrente". Apenas nas "superiores"
//Caso exista como vari‡vel ou até como procedimento (uma vari‡vel não pode nunca ser definida local, ou globalmente, se existir um procedimento com o seu nome), emite-se uma mensagem
//de erro
table_element* semantic_analysis_atribuicao_dec(int offset, prog_env* pe, table_element* stable, is_atributo* ia, is_tipo tipo)
{
	table_element *aux, *last, *stmp=stable;
    if(ia->tipo == d_a_expression && ia->conteudo.exp != NULL){
        is_tipo temp = check_expression_type(pe,stable,(is_expressao*)ia->conteudo.exp);
        if(temp==-1)
            return stmp;
        if(tipo!=temp){
            printf("line %d: error: trying to define %s (%s) as %s!\n", ia->codeline, ia->nome, typeToString(tipo), typeToString(temp));
            errors++;
            return stmp;
        }
    }
	aux=lookup(pe->global, ia->nome); 	//verifica na tabela global
    
	if(aux!=0 && aux->type==method)		//se existir e for um procedimento, temos um erro!
	{
		printf("line %d: error: Cannot define %s, already defined as method!\n", ia->codeline, ia->nome);
		errors++;
		return stmp;
	}
	
	//procura por uma vari‡vel com o mesmo nome
	for(aux=last=stmp; aux; last=aux, aux=aux->next)
		if(strcmp(ia->nome, aux->name)==0){
			printf("line %d: error: %s already defined!\n", ia->codeline, ia->nome);
			errors++;
			return stmp;
		}
	if(last==NULL)	//se n‹o existe e a tabela est‡ vazia
		stmp=create_symbol(offset, ia->nome, tipo,is_VAR);	//criar um símbolo na cabeça da lista de símbolos, stable
	else {
		last->next=create_symbol(offset, ia->nome, tipo,is_VAR);
	}
	
	return stmp;
}

void semantic_analysis_atribuicao(prog_env* pe, table_element* stable, is_atributo* ia)
{
	table_element *aux, *last, *stmp=stable;
    int found=0;
	
	for(aux=last=stmp; aux; last=aux, aux=aux->next)
		if(strcmp(ia->nome, aux->name)==0){
			found=1;
			break;
		}
	
	if(found==0){
	    aux=lookup(pe->global, ia->nome);
	    if(aux==0){
	        printf("line %d: error: %s is not defined!\n", ia->codeline, ia->nome);
            errors++;
            return;
        }
    }
    if(ia->tipo==d_a_expression){
        is_tipo temp = check_expression_type(pe, stable, (is_expressao*) ia->conteudo.exp);
	    if(temp==-1)
	        return;
	    if(aux->stype != is_METHOD && (aux->type==is_INT && temp!=is_INT)){		//se existir e nao for do mesmo tipo, temos um erro!
		    printf("line %d: error: %s is not defined as %s!\n", ia->codeline, ia->nome, typeToString(temp));
	        errors++;
	    }
	}
	//procura por uma vari‡vel com o mesmo nome
	
}

table_element* semantic_analysis_argumento_list(prog_env* pe, table_element* env, is_argumento_list* ial, char* metodo)
{
	is_argumento_list* aux;
	int offset=0;
	table_element* stmp=env;

	for(aux=ial; aux; aux=aux->next)
		stmp=semantic_analysis_argumento(offset++, pe, stmp, aux->arg, metodo);
		
	return stmp;
}

table_element* semantic_analysis_argumento(int offset, prog_env* pe, table_element* stmp, is_argumento* arg, char* metodo)
{
	table_element *aux, *last;
	for(aux=last=stmp; aux; last=aux, aux=aux->next)
		if(strcmp(arg->nome, aux->name)==0){
			printf("error in declaration of %s: %s already defined!\n", metodo, arg->nome);
			errors++;
			return stmp;
		}
	if(last==NULL)	//se n‹o existe e a tabela est‡ vazia
		stmp=create_symbol(offset, arg->nome, arg->tipo,is_ARGUMENT);	//criar um símbolo na cabeça da lista de símbolos, stable
	else
		last->next=create_symbol(offset, arg->nome, arg->tipo,is_ARGUMENT);	//nao existe mas tabela tem elementos - coloca no final da stable
	return stmp;
}

//An‡lise sem‰ntica de listas de statements
table_element* semantic_analysis_statement_list(prog_env *pe, table_element* env, is_statement_list* isl)
{
	is_statement_list* aux;
    table_element* stmp = env;
	for(aux=isl; aux; aux=aux->next){
		stmp=semantic_analysis_statement(pe, stmp, aux->stt);
	}
	return stmp;
}

//Triagem por tipo de statement
table_element* semantic_analysis_statement(prog_env *pe, table_element* env, is_statement* is)
{
	switch(is->tipo)
	{
		case d_s_atribuicao: semantic_analysis_atribuicao(pe, env, (is_atributo *)(is->conteudo.u_atributo));break;
		case d_s_declaracao: return semantic_analysis_declaration(LOCALSCOPE, pe, env,(is_declaracao *)(is->conteudo.u_declaracao));
		case d_print: semantic_analysis_print(pe, env, (is_print*)(is->conteudo.u_print)); break;
		case d_if: semantic_analysis_if(pe, env, (is_if*)(is->conteudo.u_if));break;
		case d_while: semantic_analysis_while(pe, env, (is_while*)(is->conteudo.u_while));break;
		case d_for: semantic_analysis_for(pe, env, (is_for*)(is->conteudo.u_for));break;
		case d_func_call: semantic_analysis_func_call(pe, env, (is_func_call*)(is->conteudo.u_func_call));break;
	}
	return env;
		
}

void semantic_analysis_expression(prog_env* pe, table_element* env, is_expressao* ie)
{
	switch(ie->tipo)
	{
		case d_infix_exp: semantic_analysis_infix_exp(pe, env, (is_infix_expression*)(ie->conteudo.u_infix_exp));break;
		case d_unary_exp: semantic_analysis_expression(pe,env, (is_expressao*)((is_unary_expression*)ie->conteudo.u_unary_exp)->exp);break;
		case d_number: semantic_analysis_number(pe, env, ie->conteudo.number);break;
		case d_float: semantic_analysis_float(pe, env, ie->conteudo.num_float);break;
		case d_var: semantic_analysis_var(pe, env, ie->conteudo.var, ie->codeline);break;
	}
}

void semantic_analysis_infix_exp(prog_env* pe, table_element* env, is_infix_expression* exp)
{
    semantic_analysis_expression(pe, env, exp->exp1);
    semantic_analysis_expression(pe, env, exp->exp2);
}

void semantic_analysis_number(prog_env* pe, table_element* env, int number)
{
}

void semantic_analysis_float(prog_env* pe, table_element* env, float num_float)
{
}

void semantic_analysis_var(prog_env* pe, table_element* env, char* var, int line)
{
    table_element* aux = (table_element*) malloc (sizeof(table_element));
    aux = lookup(env, var);
    if(aux==0){
        aux=lookup(pe->global, var);
        if(aux==0 || aux->stype==is_METHOD){
            printf("line %d: error: %s is not defined!\n", line, var);
            errors++;
            return;
        }
    }
}

void semantic_analysis_b_expression(prog_env* pe, table_element* env, is_b_expressao* ibe)
{
    
}

void semantic_analysis_print(prog_env* pe, table_element* env, is_print* ip)
{
	switch(ip->tipo)
	{
		case d_expression: semantic_analysis_expression(pe, env, (is_expressao*)(ip->conteudo.u_p_exp));break;
	}
}

void semantic_analysis_if(prog_env* pe, table_element* env, is_if* ii)
{
    table_element* aux;
    for(aux=env; aux->next; aux=aux->next);
	semantic_analysis_statement_list(pe, env, ii->stt);
	semantic_analysis_else(pe, env, ii->ifelse);
	aux->next=NULL;
}

void semantic_analysis_else(prog_env* pe, table_element* env, is_else* iiel)
{
	semantic_analysis_statement_list(pe, env, iiel->stt);
}

void semantic_analysis_while(prog_env* pe, table_element* env, is_while* iw)
{
	table_element* aux;
    for(aux=env; aux->next; aux=aux->next);
	semantic_analysis_statement_list(pe, env, iw->stt);
	aux->next=NULL;
}

void semantic_analysis_for(prog_env* pe, table_element* env, is_for* isf)
{
	table_element* aux;
    for(aux=env; aux->next; aux=aux->next);
	semantic_analysis_statement_list(pe, env, (is_statement_list*)(isf->attr));
	semantic_analysis_expression(pe, env, (is_expressao*)(isf->exp));
	semantic_analysis_statement_list(pe, env, (is_statement_list*)(isf->stt));
	aux->next=NULL;
}

void semantic_analysis_func_call(prog_env* pe, table_element* env, is_func_call* ifc)
{
    table_element* aux = lookup(pe->global, ifc->nome);
    if(aux==0 || aux->stype != is_METHOD){
        printf("line %d: error: %s is not defined!\n", ifc->codeline, ifc->nome);
        errors++;
        return;
    }
    semantic_analysis_func_arg_list(pe, env, ifc->func_arg, ifc->nome, ifc->codeline);
}

void semantic_analysis_func_arg_list(prog_env* pe, table_element* env, is_func_arg_list* ifal, char* nome, int line)
{
    is_func_arg_list* aux = (is_func_arg_list*) malloc (sizeof(is_func_arg_list));
    table_element* aux2 = searchMethod(pe, nome);
    int count=1;
    int err_count_sup=0;
    int err_count_inf=0;
    for(aux=ifal; aux; aux=aux->next)
    {
        if(aux2==NULL || aux2->stype!=is_ARGUMENT){
            err_count_sup++;
            continue;
        }
        semantic_analysis_func_arg(pe, env, aux->func_arg, aux2, count);
        aux2=aux2->next;
        count++;
    }
    for(;aux2; aux2=aux2->next)
        if(aux2->stype==is_ARGUMENT)
            err_count_inf++;
        else
            break;
    if(err_count_sup!=0){
        printf("line %d: error: expected %d arguments but found %d!\n", line, count-1, count+err_count_sup-1);
        errors++;
    }
    else if(err_count_inf!=0){
        printf("line %d: error: expected %d arguments but found %d!\n", line, count+err_count_inf-1, count-1);
        errors++;
    }
}

table_element* searchMethod(prog_env* pe, char* nome)
{
    environment_list* el;
    for(el=pe->procs; el; el=el->next)
        if(strcmp(el->name, nome)==0)
            return el->locals;
    return NULL;
}

void semantic_analysis_func_arg(prog_env* pe, table_element* env, is_func_arg* ifa, table_element* arg, int arg_num)
{
    is_tipo var;
    switch(ifa->tipo)
    {
    case d_f_expression: 
        var = check_expression_type(pe, env, ifa->conteudo.exp);
        if(var==-1)
            return;
        if(arg->type!=var){
            printf("line %d: error: (argument %d) expected %s but found %s!\n", ifa->codeline, arg_num, typeToString(arg->type), typeToString(var));
            errors++;
        }
        break;
    case d_f_b_expression: 
        semantic_analysis_b_expression(pe, env, ifa->conteudo.b_exp);
        if(arg->type != is_BOOLEAN){
            printf("line %d: error: (argument %d) expected %s but found %s!\n", ifa->codeline, arg_num, typeToString(arg->type), "boolean");
            errors++;
        }
        break;
    }
}

/*******************************************************
********************************************************
*******************************************************

//S— se faz um write se a vari‡vel existir e se n‹o for um procedimento
void semantic_analysis_write_stat(prog_env *pe, table_element* env, is_write_stat* iws)
{
	table_element	*e;

	e=lookup(pe->global, iws->var);
	if(e && e->type==procedure)
		printf("line %d: %s is a procedure! It cannot be printed...\n", iws->codeline, iws->var);
	else
		if(!lookup(env, iws->var)&& !e)
			printf("line %d: Unknown variable: %s\n", iws->codeline, iws->var);
}

//S— se faz um assignment se a vari‡vel que receber o valor for do mesmo tipo que o valor
void semantic_analysis_assgn_stat(prog_env *pe, table_element* stable, is_assgn_stat* ias)
{
	table_element *e=lookup(stable, ias->var);

	if(!e)
		e=lookup(pe->global, ias->var);

	if(!e)
		printf("line %d: Unknown variable: %s\n", ias->codeline, ias->var);
	else
		if(e->type==procedure)
			printf("line %d: Cannot make assignment to a procedure: %s\n", ias->codeline, ias->var);
		else
			if(e->type!=ias->disc_d)
				printf("line %d: Type mismatch! %s<>%s\n", ias->codeline, typeToString(e->type), typeToString(ias->disc_d));

}

//S— se faz um call se existir o procedimento com o nome dado
void semantic_analysis_call_stat(prog_env *pe, table_element* env, is_call_stat* ics)
{
	table_element *e=lookup(pe->global, ics->proc);

	if(!e || e->type!=procedure)
		printf("line %d: Unknown procedure: %s\n", ics->codeline, ics->proc);
}

*/


//Convers‹o enum-> string para ajudar no output de erros
char* typeToString(is_tipo type)
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

char* printSymType(sym_type type){
    switch(type)
	{
		case is_METHOD:		return "method";
		case is_ARGUMENT:	return "arg";
		case is_VAR:		return "";
	}
	return "unknown type";
}

//Criação de uma estrutura table_element
table_element* create_symbol(int offset, char* name, is_tipo type, sym_type stype)
{
	table_element* el=(table_element*)malloc(sizeof(table_element));
	strcpy(el->name,name);
	el->type=type;
	el->next=NULL;
	el->offset=offset;
	el->stype=stype;
	return el;
}

//Procura um identificador, devolve 0 caso n‹o exista
table_element *lookup(table_element* table, char *str)
{
	table_element *aux;

	for(aux=table; aux; aux=aux->next)
		if(strcmp(aux->name, str)==0)
			return aux;

	return 0;
}


is_tipo check_expression_type(prog_env* pe, table_element* stable, is_expressao* exp)
{
    switch(exp->tipo)
    {
        case d_infix_exp:   return check_infix_exp_type(pe, stable, (is_infix_expression*)exp->conteudo.u_infix_exp, line);
        case d_unary_exp:   return check_expression_type(pe,stable, (is_expressao*)((is_unary_expression*)exp->conteudo.u_unary_exp)->exp);
        case d_number:      return is_INT;
        case d_float:       return is_FLOAT;
        case d_var:         return check_var_type(pe, stable, exp);
    }
    return 0;
}

is_tipo check_infix_exp_type(prog_env* pe, table_element* stable, is_infix_expression* exp, int line)
{
    is_tipo tipo1 = check_expression_type(pe, stable, exp->exp1);
    is_tipo tipo2 = check_expression_type(pe, stable, exp->exp2); 
    
    if(tipo1==-1 || tipo2==-1)
        return -1;
    
    if(tipo1==is_FLOAT || tipo2==is_FLOAT )
        return is_FLOAT;
    return is_INT;
}

is_tipo check_var_type(prog_env* pe, table_element* stable, is_expressao* exp)
{
    table_element *aux, *last, *stmp=stable;
    int found=1;
	aux=lookup(pe->global, exp->conteudo.var); 	//verifica na tabela global
    
    is_tipo tipo=is_INT;
    
	if(aux!=0 && aux->stype!= is_METHOD){
		tipo = aux->type;
	}
	else if (aux==0)
	    found=0;
	//procura por uma vari‡vel com o mesmo nome
	for(aux=last=stmp; aux; last=aux, aux=aux->next)
		if(strcmp(exp->conteudo.var, aux->name)==0)
			return aux->type;
	if(found==0){
	    printf("line %d: error: %s is not defined!\n", exp->codeline, exp->conteudo.var);
        errors++;
        return -1;
    }
    return tipo;
}

