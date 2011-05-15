#include "structures.h"
#include "symbol_table.h"
#include "semantic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum {LOCALSCOPE, GLOBALSCOPE};

int global_offset=0;
int maincount;

prog_env* semantic_analysis(is_block_list* ipl) //an�lise sem�ntica da lista de blocos, ou seja do nosso programa
{
	is_block_list *aux;

	prog_env* pe=(prog_env*)malloc(sizeof(prog_env));		//cria��o do program_environment, que conter� todas os s�mbolos (globais, locais, procedimentos)

	//vamos fazer an�lise sem�ntica bloco a bloco
	for(aux=ipl; aux; aux=aux->next)	
	{
	
		//Note-se que se envia o program environment existente. Para o bloco poder verificar, por exemplo, se um dado procedimento existe, ou uma vari�vel global
		semantic_analysis_block(pe, aux->p);
	}
	
	return pe;
}

void semantic_analysis_block(prog_env *pe, is_block* ip)
{
	//faz a triagem do bloco a analisar
	switch(ip->disc_d)
	{
	case d_procedure: semantic_analysis_procedure(pe, ip->data_block.u_procedure);  break;
	case d_globals: semantic_analysis_globals(pe, ip->data_block.u_globals);break;
	}
		
}

void semantic_analysis_procedure(prog_env *pe, is_procedure* ipr)
{
	environment_list *aux;
	table_element *te;	
	
	environment_list *pl;

	if(lookup(pe->global, ipr->name))
		printf("Symbol %s already defined! Cannot create procedure!\n", ipr->name);
	else
		{
		pl=(environment_list*)malloc(sizeof(environment_list)); //cria um nodo para a lista de ambientes 
																//(que � mantida no program environment)
		
		te=pe->global; //Vai buscar tabela de simbolos globais


		//adiciona entrada para procedimento
		//na tabela de simbolos global. offset = -1 =>procedimento.
		//Serve apenas para facilitar na pesquisa (na realidade, � uma redundncia, pois
		//haver� tamb�m uma entrada na lista de ambientes)
		if(te==NULL)
			pe->global=create_symbol(-1, ipr->name, procedure);
		else
			{
			for(; te->next; te=te->next);					
			te->next=create_symbol(-1, ipr->name, procedure);		
			}
		
		//preenche entrada para o procedimento na lista de ambientes
		pl->name=(char*)strdup(ipr->name);	
		pl->locals=(table_element*)malloc(sizeof(table_element));

		//faz an�lise sem�ntica do procedimento
		// � aqui que vai adicionando os s�mbolos encontrados dentro do procedimento ao ambiente (representado por pl->locals)
		semantic_analysis_vardeclist(LOCALSCOPE, pe, pl->locals, ipr->vlist);	
		semantic_analysis_statement_list(pe, pl->locals, ipr->slist);
		}

	//Adiciona ao program environment
	if(pe->procs==NULL)	//Caso seja o primeiro procedimento, fica na cabe�a
		pe->procs=pl;
	else			//sen�o, fica na cauda
		{
		for(aux=pe->procs; aux->next; aux=aux->next);
			aux->next=pl;
		}
}

//An�lise das declara��es de vari�veis globais
void semantic_analysis_globals(prog_env *pe, is_globals* ipg)
{
	pe->global=semantic_analysis_vardeclist(GLOBALSCOPE, pe, pe->global, ipg->vlist);	//0 -> global
}


//An�lise de declara��es de vari�veis
//� necess�rio saber o scope para saber onde calcular o offset das vari�veis nos registos de activa��o
table_element* semantic_analysis_vardeclist(int scope, prog_env *pe, table_element* stable, is_vardec_list* ivl)
{
	is_vardec_list* aux;
	int offset=0;
	table_element* stmp=stable;

	for(aux=ivl; aux; aux=aux->next)
		stmp=semantic_analysis_vardec((scope==LOCALSCOPE?offset++:global_offset++), pe, stmp, aux->v);

	return stmp;
}

//Dependendo do scope, esta fun��o verifica primeiro se j� existe a vari�vel nas tabelas de s�mbolos. N�o pode existir na tabela de s�mbolos "corrente". Apenas nas "superiores"
//Caso exista como vari�vel ou at� como procedimento (uma vari�vel n�o pode nunca ser definida local, ou globalmente, se existir um procedimento com o seu nome), emite-se uma mensagem
//de erro
table_element* semantic_analysis_vardec(int offset, prog_env* pe, table_element* stable, is_vardec* iv)
{
	table_element *aux, *last, *stmp=stable;

	aux=lookup(pe->global, iv->name); 	//verifica na tabela global

	if(aux!=0 && aux->type==procedure)		//se existir e for um procedimento, temos um erro!
		{
		printf("line %d: error: Cannot define %s, already defined as procedure!\n", iv->codeline, iv->name);
		return stmp;
		}
	
	//procura por uma vari�vel com o mesmo nome
	for(aux=last=stmp; aux; last=aux, aux=aux->next)
		if(strcmp(iv->name, aux->name)==0)
			break;
	
	if(last==NULL)	//se n�o existe e a tabela est� vazia
		stmp=create_symbol(offset, iv->name, iv->disc_d);	//criar um s�mbolo na cabe�a da lista de s�mbolos, stable
	else
		if(last->next==NULL)		//se n�o existe 
			last->next=create_symbol(offset, iv->name, iv->disc_d);	//coloca no final da stable
		else				//EXISTE! J� est� definida!!!
			printf("line %d: error: %s already defined!\n", iv->codeline, iv->name);
	
	return stmp;
}


//An�lise sem�ntica de listas de statements
void semantic_analysis_statement_list(prog_env *pe, table_element* env, is_statement_list* isl)
{
	is_statement_list* aux;
	
	for(aux=isl; aux; aux=aux->next)
		semantic_analysis_statement(pe, env, aux->s);
}

//Triagem por tipo de statement
void semantic_analysis_statement(prog_env *pe, table_element* env, is_statement* is)
{
	switch(is->disc_d)
	{
	case d_write_stat:	semantic_analysis_write_stat(pe, env, is->data_statement.u_write_stat);break;
	case d_assgn_stat:	semantic_analysis_assgn_stat(pe, env, is->data_statement.u_assgn_stat);break;
	case d_call_stat:	semantic_analysis_call_stat(pe, env, is->data_statement.u_call_stat);break;
	}
		
}

//S� se faz um write se a vari�vel existir e se n�o for um procedimento
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

//S� se faz um assignment se a vari�vel que receber o valor for do mesmo tipo que o valor
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

//S� se faz um call se existir o procedimento com o nome dado
void semantic_analysis_call_stat(prog_env *pe, table_element* env, is_call_stat* ics)
{
	table_element *e=lookup(pe->global, ics->proc);

	if(!e || e->type!=procedure)
		printf("line %d: Unknown procedure: %s\n", ics->codeline, ics->proc);
}


//Convers�o enum-> string para ajudar no output de erros
char* typeToString(int type)
{
	switch(type)
	{
	case integer: return "integer";
	case character: return "char";
	case doub: return "double";
	case procedure: return "procedure";
	}
	return "unknown type";
}

//Cria��o de uma estrutura table_element
table_element* create_symbol(int offset, char* name, basic_type type)
{
	table_element* el=(table_element*)malloc(sizeof(table_element));
	strcpy(el->name,name);
	el->type=type;
	el->next=NULL;
	el->offset=offset;
	return el;
}

//Procura um identificador, devolve 0 caso n�o exista
table_element *lookup(table_element* table, char *str)
{
table_element *aux;

for(aux=table; aux; aux=aux->next)
	if(strcmp(aux->name, str)==0)
		return aux;

return 0;
}
