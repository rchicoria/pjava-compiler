#include "structures.h"
#include "symbol_table.h"
#include <stdio.h>

void translate(is_static_list* list, prog_env* pe);
void translate_header(FILE* dest);
void translate_footer(FILE* dest);
void translate_static_list(FILE* dest, is_static_list* list, prog_env* pe);
void translate_attr_list(int scope, FILE* dest, is_attribution_list* attr, prog_env* pe, table_element* env);
void translate_attr(int scope, FILE* dest, is_attribution* attr, prog_env* pe, table_element* env, int dec);
void translate_declaration(int scope, FILE* dest, is_declaration* dec, prog_env* pe, table_element* env);
void translate_method(FILE* dest, is_method* im, prog_env* pe);
void translate_methods(FILE* dest, is_static_list* isl, prog_env* pe);
void translate_main(FILE* dest, is_method* main, environment_list* local, prog_env* pe);
void translate_redirector(FILE* dest);
void translate_statements(FILE* dest, is_statement_list* isl, prog_env* pe, table_element* env, char* name);
void translate_statement(FILE* dest, is_statement* is, prog_env* pe, table_element* env, char* name);
char* translate_expression(int scope, FILE* dest, is_expression* ie, prog_env* pe, table_element* env);
char* translate_infix_expression(int scope, FILE* dest, is_infix_expression* iie, prog_env* pe, table_element* env);
char* translate_simple_expression(int scope, FILE* dest, is_s_expression* ise, prog_env* pe, table_element* env);
char* translate_operator(int scope, FILE* dest, is_operator op);
char* translate_var(int scope, FILE* dest, char* var, prog_env* pe, table_element* env);
char* translate_inc(int scope, FILE* dest, is_increment* inc, prog_env* pe, table_element* env);
char* translate_unary_expression(int scope, FILE* dest, is_unary_expression* iue, prog_env* pe, table_element* env);
char* translate_b_expression(int scope, FILE* dest, is_b_expression* ie, prog_env* pe, table_element* env);
char* translate_b_infix_expression(int scope, FILE* dest, is_b_infix_expression* ibie, prog_env* pe, table_element* env);
char* translate_b_operator(int scope, FILE* dest, is_b_operator);
char* translate_comparison(int scope, FILE* dest, is_comparison* comp, prog_env* pe, table_element* env);
char* translate_comparator(int scope, FILE* dest, is_comparator op);
char* translate_b_not_exp(int scope, FILE* dest, is_b_not_expression* ibne, prog_env* pe, table_element* env);
void translate_print(int scope, FILE* dest, is_print* ip, prog_env* pe, table_element* env);
void translate_if(int scope, FILE* dest, is_if* ii, prog_env* pe, char* name);
void translate_else(int scope, FILE* dest, is_else* ie, prog_env* pe, char* n, char* name);
void translate_while(int scope, FILE* dest, is_while* iw, prog_env* pe, char* name);
void translate_for(int scope, FILE* dest, is_for* isf, prog_env* pe, char* name);
void translate_arguments(int scope, FILE* dest, is_method_arg_list* imal, prog_env* pe, table_element* env);
void translate_argument(int scope, FILE* dest, is_method_arg* ima, prog_env* pe, table_element* env);
void translate_return(int scope, FILE* dest, is_return* ir, prog_env* pe, table_element* env, char* name);
char* translate_method_call(int scope, FILE* dest, is_method_call* imc, prog_env* pe, table_element* env);
