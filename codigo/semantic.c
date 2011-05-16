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
			pe->global=create_symbol(-1, im->nome, is_VOID,is_METHOD);
		else
		{
			for(; te->next; te=te->next);					
			te->next=create_symbol(-1, im->nome, is_VOID,is_METHOD);		
		}
		
		//preenche entrada para o procedimento na lista de ambientes
		pl->name=(char*)strdup(im->nome);	
		//pl->locals=(table_element*)malloc(sizeof(table_element));

		//faz an‡lise sem‰ntica do procedimento
		// Ž aqui que vai adicionando os s’mbolos encontrados dentro do procedimento ao ambiente (representado por pl->locals)
		pl->locals=semantic_analysis_argumento_list(pe, pl->locals, (is_argumento_list *)(im->arg_list), im->nome);
		pl->locals=semantic_analysis_statement_list(pe, pl->locals, (is_statement_list *)(im->list));
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
	else
		last->next=create_symbol(offset, ia->nome, tipo,is_VAR);	//nao existe mas tabela tem elementos - coloca no final da stable
	
	return stmp;
}

void semantic_analysis_atribuicao(prog_env* pe, table_element* stable, is_atributo* ia)
{
	table_element *aux, *last, *stmp=stable;
    int found=1;
	aux=lookup(pe->global, ia->nome); 	//verifica na tabela global

	if(aux!=0 && aux->type!=ia->tipo){		//se existir e nao for do mesmo tipo, temos um erro!
		printf("line %d: error: %s is not defined as a %s!\n", ia->codeline, ia->nome, typeToString(ia->tipo));
	    errors++;
	}
	else if (aux==0)
	    found=0;
	//procura por uma vari‡vel com o mesmo nome
	for(aux=last=stmp; aux; last=aux, aux=aux->next)
		if(strcmp(ia->nome, aux->name)==0)
			return;
	if(found==0){
	    printf("line %d: error: %s is not defined!\n", ia->codeline, ia->nome);
        errors++;
    }
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
	
	for(aux=isl; aux; aux=aux->next)
		stmp=semantic_analysis_statement(pe, stmp, aux->stt);
	
	return stmp;
}

//Triagem por tipo de statement
table_element* semantic_analysis_statement(prog_env *pe, table_element* env, is_statement* is)
{
	switch(is->tipo)
	{
		case d_s_atribuicao: semantic_analysis_atribuicao(pe, env, (is_atributo *)(is->conteudo.u_atributo));break;
		case d_s_declaracao: return semantic_analysis_declaration(LOCALSCOPE, pe, env,(is_declaracao *)(is->conteudo.u_declaracao));
		case d_print: break;
		case d_if: break;
		case d_while: break;
		case d_for: break;
	/*case d_write_stat:	semantic_analysis_write_stat(pe, env, is->data_statement.u_write_stat);break;
	case d_assgn_stat:	semantic_analysis_assgn_stat(pe, env, is->data_statement.u_assgn_stat);break;
	case d_call_stat:	semantic_analysis_call_stat(pe, env, is->data_statement.u_call_stat);break;
	*/
	}
	return env;
		
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

