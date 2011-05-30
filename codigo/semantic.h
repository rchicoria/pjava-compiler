#include "structures.h"
#include "symbol_table.h"

prog_env* semantic_analysis(is_static_list* isl);
void semantic_analysis_static(prog_env *pe, is_static* is);
void semantic_analysis_method(prog_env *pe, is_method* im);
void semantic_analysis_return(prog_env *pe, table_element* env, is_return* return_val, is_type type);
table_element* semantic_analysis_declaration(int scope, prog_env *pe, table_element* env, is_declaration* id);
table_element* semantic_analysis_attribution_list(int scope, prog_env *pe, table_element* env, is_attribution_list* ial, is_type type);
table_element* semantic_analysis_attribution_dec(int offset, prog_env* pe, table_element* env, is_attribution* ia, is_type type);
void semantic_analysis_attribution(prog_env* pe, table_element* env, is_attribution* ia);
table_element* semantic_analysis_argument_list(prog_env* pe, table_element* env, is_argument_list* ial, char* method, int line);
table_element* semantic_analysis_argument(int offset, prog_env* pe, table_element* env, is_argument* arg, char* method, int line);
table_element* semantic_analysis_statement_list(prog_env *pe, table_element* env, is_statement_list* isl, is_type type);
table_element* semantic_analysis_statement(prog_env *pe, table_element* env, is_statement* is, is_type type);
is_type semantic_analysis_expression(prog_env* pe, table_element* env, is_expression* ie);
is_type semantic_analysis_infix_exp(prog_env* pe, table_element* env, is_infix_expression* exp);
is_type semantic_analysis_var(prog_env* pe, table_element* env, is_expression* exp);
int semantic_analysis_b_expression(prog_env* pe, table_element* env, is_b_expression* ibe);
int semantic_analysis_b_infix_exp(prog_env* pe, table_element* env, is_b_infix_expression* ibe);
int semantic_analysis_comparison(prog_env* pe, table_element* env, is_comparison* comp);
void semantic_analysis_print(prog_env* pe, table_element* env, is_print* ip);
void semantic_analysis_if(prog_env* pe, table_element* env, is_if* ii, is_type type);
void semantic_analysis_else(prog_env* pe, table_element* env, is_else* iiel, is_type type);
void semantic_analysis_while(prog_env* pe, table_element* env, is_while* iw, is_type type);
void semantic_analysis_for(prog_env* pe, table_element* env, is_for* isf, is_type type);
is_type semantic_analysis_method_call(prog_env* pe, table_element* env, is_method_call* imc);
int semantic_analysis_method_arg_list(prog_env* pe, table_element* env, is_method_arg_list* imal, char* name, int line);
table_element* search_method(prog_env* pe, char* name);
int semantic_analysis_method_arg(prog_env* pe, table_element* env, is_method_arg* ima, table_element* arg, int arg_num);
char* type_to_string(is_type type);
char* sym_type_to_string(sym_type type);
table_element* create_symbol(int offset, char* name, is_type type, sym_type stype);
table_element *lookup(table_element* table, char *str);
