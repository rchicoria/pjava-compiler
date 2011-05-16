#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_

typedef enum {integer, character, doub, method} basic_type;

typedef enum {is_INT, is_STRING, is_VOID, is_FLOAT, is_DOUBLE, is_BOOLEAN, is_CHAR, is_NONE} is_tipo;
typedef enum {is_METHOD, is_ARGUMENT, is_VAR} sym_type;

//lista ligada de simbolos - um ambiente/registo de activação
typedef struct _t1{	
	char name[32];
	is_tipo type;
	sym_type stype;
	int offset;		//futura posição na frame, caso seja uma variavel -1, se for uma procedure.
	struct _t1 *next;
} table_element;


//lista de procedimentos definidos no programa
typedef struct _t4{
	char* name;
	struct _t4 *next;
	table_element *locals;
}environment_list;

//Estrutura que guarda TODOS os simbolos de um programa: o ambiente "global" e a lista de ambientes
typedef struct _t5{
	table_element* global;
	environment_list* procs;
}prog_env;
#endif
