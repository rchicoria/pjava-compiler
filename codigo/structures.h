#ifndef _STRUCTURES_
#define _STRUCTURES_

#include "symbol_table.h"

int line; //guarda a linha de cada instrucao
int errors; //guarda o numero de erros detectados

typedef enum {is_PLUS, is_MINUS, is_MULT, is_DIVIDE, is_MOD} is_operator;

typedef enum {is_AND, is_OR, is_NOT} is_b_operator;

typedef enum {is_GREATER, is_LESSER, is_GREATEQ, is_LESSEQ, is_EQUALS, is_DIFERENT} is_comparator;

typedef enum {stat_declaration, stat_method} type_static;

typedef enum {stt_attribution, stt_declaration, stt_print, stt_if, stt_while, stt_for, stt_m_call, stt_return, stt_inc} type_statement;

typedef enum {print_expression} type_print;

typedef enum {arg_expression, arg_b_expression} type_m_arg;

typedef enum {ret_expression, ret_b_expression, ret_void} type_return;

typedef enum {attr_expression, attr_b_expression} type_attribution;

typedef enum {exp_infix, exp_unary, exp_int, exp_double, exp_char} type_expression;

typedef enum {b_exp_bool, b_exp_comp, b_exp_infix, b_exp_not, b_exp_var, b_exp_m_call, b_exp_inc} type_b_expression;

typedef enum {s_exp_var, s_exp_exp, s_exp_m_call, s_exp_inc} type_s_expression;

typedef enum {u_exp_neg, u_exp_par} type_u_expression;

typedef struct _a0 {
	type_static type;
	union {
		struct is_attribution* attr;
		struct is_declaration* dec;
		struct is_method* method;
	} content;
} is_static;

typedef struct _a1 {
	type_attribution type;
	char* name;
	char op;
	union{
	    struct is_expression* exp;
	    struct is_b_expression* b_exp;
	} content;
	int codeline;
} is_attribution;

typedef struct _a3 {
	type_expression type;
	union {
		struct is_infix_expression* infix_exp;
		struct is_unary_expression* unary_exp;
		int num_int;
		double num_double;
		char val_char;
	} content;
	int codeline;
} is_expression;

typedef struct _a28 {
    type_s_expression type;
    union {
        char* var;
        struct is_expression* exp;
        struct is_method_call* m_call;
        struct is_increment* inc;
    } content;
} is_s_expression;

typedef struct _a4 {
	is_s_expression* exp1;
	is_operator op;
	is_s_expression* exp2;
} is_infix_expression;

typedef struct _a5 {
	type_u_expression type;
	is_s_expression* exp;
} is_unary_expression;

typedef struct _a6 {
	is_expression* exp;
	struct _a6* next;
} is_expression_list;

typedef struct _a7 {
	is_static* stat;
	struct _a7* next;
} is_static_list;

typedef struct _a8 {
    is_type type;
    char* name;
} is_argument;

typedef struct _a9 {
    is_argument* arg;
    struct _a9* next;
} is_argument_list;

typedef struct _a11 {
    is_attribution* attr;
    struct _a11* next;
} is_attribution_list;

typedef struct _a12 {
    type_statement type;
    union {
		struct is_attribution* attr;
		struct is_declaration* dec;
		struct is_print* _print;
		struct is_if* _if;
		struct is_while* _while;
		struct is_for* _for;
		struct is_method_call* m_call;
		struct is_return* _return;
		struct is_increment* inc;
	} content;
} is_statement;

typedef struct _a13 {
    is_statement* stt;
    struct _a13* next;
} is_statement_list;

typedef struct _a14 {
    type_print type;
    is_type exp_type;
    char end;
    union {
        struct is_simple_expression* exp;
    } content;
    int codeline;
} is_print;

typedef struct _a15 {
    is_type type;
    is_attribution_list* list;
    int codeline;
} is_declaration;

typedef struct _a16 {
    type_b_expression type;
    union {
        char boolean;
        struct is_b_infix_expression* infix_b_exp;
        struct is_b_not_expression* not_b_exp;
        struct is_comparison* comp;
        struct is_method_call* m_call;
        char* var;
        struct is_increment* inc;
    } content;
    int codeline;
} is_b_expression;

typedef struct _a17 {
    is_b_expression* exp1;
    is_b_operator op;
    is_b_expression* exp2;
} is_b_infix_expression;

typedef struct _a18 {
    is_s_expression* exp1;
    is_comparator op;
    is_s_expression* exp2;
} is_comparison;

typedef struct _a19 {
    is_b_expression* exp;
} is_b_not_expression;

typedef struct _a29 {
    char* var;
    char op;
    int codeline;
} is_increment;

typedef struct _a27 {
    type_return type;
    int codeline;
    union
    {   
        is_expression* exp;
        is_b_expression* b_exp;
    } content;
} is_return;

typedef struct _a2 {
	is_type type;
	char* name;
	struct is_argument_list* arg_list;
	struct is_statement_list* stt_list;
	int codeline;
} is_method;

typedef struct _a23 {
    is_statement_list* stt;
    int codeline;
} is_else;

typedef struct _a20 {
    is_b_expression* exp;
    is_statement_list* stt;
    is_else* ifelse;
    int codeline;
} is_if;

typedef struct _a21 {
    is_b_expression* exp;
    is_statement_list* stt;
    int codeline;
} is_while;

typedef struct _a22 {
    is_statement_list* attr;
    is_b_expression* b_exp;
    is_statement_list* last;
    is_statement_list* stt;
    int codeline;
} is_for;

typedef struct _a24 {
    type_m_arg type;
    union {
        is_expression* exp;
        is_b_expression* b_exp;
    } content;
    int codeline;
} is_method_arg;

typedef struct _a25 {
    is_method_arg* m_arg;
    struct _a25* next;
} is_method_arg_list;

typedef struct _a26 {
    char* name;
    is_method_arg_list* m_arg_list;
    int  codeline;
} is_method_call;

#endif
