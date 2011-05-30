#include "structures.h"

void show_program(is_static_list* isl);
void show_static(is_static* is);
void show_attribution(is_attribution* ia);
void show_method(is_method* im);
void show_return(is_return* ir);
void show_expression(is_expression* ie);
void show_infix_expression(is_infix_expression* iie);
void show_unary_expression(is_unary_expression* iue);
void show_operator(is_operator op);
void show_argument(is_argument* ia);
void show_statement(is_statement* stt);
void show_print(is_print* print);
void show_declaration(is_declaration* id);
void show_b_expression(is_b_expression* ibe);
void show_infix_b_expression(is_b_infix_expression* ibie);
void show_b_not_expression(is_b_not_expression* inbe);
void show_comparator(is_comparator op);
void show_comparison(is_comparison* ic);
void show_b_operator(is_b_operator op);
void show_if(is_if* ii);
void show_else(is_else* iiel);
void show_while(is_while* iw);
void show_for(is_for* isf);
void show_method_call(is_method_call* imc);
void show_method_arg(is_method_arg* ima);
