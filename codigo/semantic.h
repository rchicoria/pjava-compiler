#include "structures.h"
#include "symbol_table.h"

prog_env* semantic_analysis(is_static_list*);
void semantic_analysis_block(prog_env*, is_static*);
void semantic_analysis_method(prog_env*, is_metodo*);
void semantic_analysis_declaration(prog_env*, is_declaracao*);
table_element* semantic_analysis_atribuicao_list(int, prog_env*, table_element*, is_atribuicao_list*);
table_element* semantic_analysis_atribuicao_dec(int, prog_env*, table_element*, is_atributo*);
table_element* semantic_analysis_atribuicao(prog_env*, table_element*, is_atributo*);
void semantic_analysis_argumento_list(int, prog_env*, table_element*, is_argumento_list*);
void semantic_analysis_statement_list(prog_env*, table_element*, is_statement_list*);
void semantic_analysis_statement(prog_env*, table_element*, is_statement*);

/*prog_env* semantic_analysis(is_block_list* ipl);
void semantic_analysis_block(prog_env *pe, is_block* ip);
void semantic_analysis_procedure(prog_env *pe, is_procedure* ipr);
void semantic_analysis_globals(prog_env *pe, is_globals* ipg);
table_element* semantic_analysis_vardeclist(int scope, prog_env *pe, table_element* stable, is_vardec_list* ivl);
table_element* semantic_analysis_vardec(int offset, prog_env* pe, table_element* stable, is_vardec* iv);
void semantic_analysis_statement_list(prog_env *pe, table_element* env, is_statement_list* isl);
void semantic_analysis_statement(prog_env *pe, table_element* env, is_statement* is);
void semantic_analysis_write_stat(prog_env *pe, table_element* env, is_write_stat* iws);
void semantic_analysis_assgn_stat(prog_env *pe, table_element* stable, is_assgn_stat* ias);
void semantic_analysis_call_stat(prog_env *pe, table_element* env, is_call_stat* ics);
*/
char* typeToString(int type);
table_element* create_symbol(int offset, char* name, basic_type type);
table_element *lookup(table_element* table, char *str);
