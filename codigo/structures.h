#ifndef _STRUCTURES_
#define _STRUCTURES_

#include "symbol_table.h"

int line;
int errors;

/*is_operador -> is_PLUS or is_MINUS or is_MULT or is_DIVIDE*/
typedef enum {is_PLUS, is_MINUS, is_MULT, is_DIVIDE} is_operador;

typedef enum {is_AND, is_OR, is_NOT} is_b_operator;

typedef enum {is_GREATER, is_LESSER, is_GREATEQ, is_LESSEQ, is_EQUALS, is_DIFERENT} is_comparator;

typedef enum {d_declaracao, d_metodo} tipo_static;

typedef enum {d_s_atribuicao, d_s_declaracao, d_print, d_if, d_while, d_for, d_func_call} tipo_statement;

typedef enum {d_expression} tipo_print;

typedef enum {d_f_expression, d_f_b_expression} tipo_func_arg;

/*is_ expression  -> is_infix_ expression  or is_unary_expression 
			   or is_NUMBER*/

typedef enum {d_infix_exp, d_unary_exp, d_number, d_float, d_var} tipo_expressao;

typedef enum {d_tf, d_comparison, d_infix_b_exp, d_not_b_exp} tipo_b_expressao;

typedef struct _a0 {
	tipo_static tipo;
	union {
		struct is_atributo* u_atributo;
		struct is_declaracao* u_declaracao;
		struct is_metodo* u_metodo;
	} conteudo;
} is_static;

typedef struct _a1 {
	is_tipo tipo;
	char* nome;
	struct is_expressao* exp;
	int codeline;
} is_atributo;

typedef struct _a3 {
	tipo_expressao tipo;
	union {
		struct is_infix_expression* u_infix_exp;
		struct is_unary_expression* u_unary_exp;
		int number;
		float num_float;
		char* var;
	} conteudo;
	int codeline;
} is_expressao;

/*is_infix_expression  -> 
	(<exp1: is_expressao><operador:is_operador><exp2:is_expressao>)*/
typedef struct _a4 {
	is_expressao  *exp1;
	is_operador operador;
	is_expressao  *exp2;
} is_infix_expression;

/*is_unary_expression  -> (<exp: is_expressao>)*/
typedef struct _a5 {
	is_expressao  *exp;
} is_unary_expression;

typedef struct _a6 {
	is_expressao* expr;
	struct _a6* next;
} is_expressao_list;

typedef struct _a7 {
	is_static* stat;
	struct _a7* next;
} is_static_list;

typedef struct _a8 {
    is_tipo tipo;
    char* nome;
} is_argumento;

typedef struct _a9 {
    is_argumento* arg;
    struct _a9* next;
} is_argumento_list;

typedef struct _a11 {
    is_atributo* attr;
    struct _a11* next;
} is_atribuicao_list;

typedef struct _a12 {
    tipo_statement tipo;
    union {
		struct is_atributo* u_atributo;
		struct is_declaracao* u_declaracao;
		struct is_print* u_print;
		struct is_if* u_if;
		struct is_while* u_while;
		struct is_for* u_for;
		struct is_func_call* u_func_call;
	} conteudo;
} is_statement;

typedef struct _a13 {
    is_statement* stt;
    struct _a13* next;
} is_statement_list;

typedef struct _a14 {
    tipo_print tipo;
    char fim;
    union {
        struct is_expressao* u_p_exp;
    } conteudo;
    int codeline;
} is_print;

typedef struct _a15 {
    is_tipo tipo;
    is_atribuicao_list* list;
    int codeline;
} is_declaracao;

typedef struct _a16 {
    tipo_b_expressao tipo;
    union {
        char boolean;
        struct is_b_infix_expressao* u_infix_b_exp;
        struct is_b_not_expressao* u_not_b_exp;
        struct is_comparison* u_comp;
    } conteudo;
    int codeline;
} is_b_expressao;

typedef struct _a17 {
    is_b_expressao* exp1;
    is_b_operator op;
    is_b_expressao* exp2;
} is_b_infix_expressao;

typedef struct _a18 {
    is_expressao* exp1;
    is_comparator op;
    is_expressao* exp2;
} is_comparison;

typedef struct _a19 {
    is_b_expressao* exp;
} is_b_not_expressao;

typedef struct _a27 {
    tipo_func_arg tipo;
    int codeline;
    union
    {   
        is_expressao* exp;
        is_b_expressao* b_exp;
    } conteudo;
} is_return;

typedef struct _a2 {
	is_tipo tipo;
	char* nome;
	struct is_argumento_list* arg_list;
	struct is_statement_list* list;
	int codeline;
	is_return* return_val;
} is_metodo;

typedef struct _a23 {
    is_statement_list* stt;
    int codeline;
} is_else;

typedef struct _a20 {
    is_b_expressao* exp;
    is_statement_list* stt;
    is_else* ifelse;
    int codeline;
} is_if;

typedef struct _a21 {
    is_b_expressao* exp;
    is_statement_list* stt;
    int codeline;
} is_while;

typedef struct _a22 {
    is_statement_list* attr;
    is_b_expressao* b_exp;
    is_expressao* exp;
    is_statement_list* stt;
    int codeline;
} is_for;

typedef struct _a24 {
    tipo_func_arg tipo;
    union
    {
        is_expressao* exp;
        is_b_expressao* b_exp;
    } conteudo;
    int codeline;
} is_func_arg;

typedef struct _a25 {
    is_func_arg* func_arg;
    struct _a25* next;
} is_func_arg_list;

typedef struct _a26 {
    char* nome;
    is_func_arg_list* func_arg;
    int  codeline;
} is_func_call;

#endif
