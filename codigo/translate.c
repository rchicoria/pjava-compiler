#include "translate.h"
#include "structures.h"
#include "semantic.h"
#include "symbol_table.h"
#include <stdio.h>
#include <string.h>

int returncounter=0;

char* type_to_string_trans(is_type type)
{
	switch(type)
	{
		case is_INT:		return "int";
		case is_STRING:		return "char";
		case is_VOID:		return "void";
		case is_FLOAT:		return "float";
		case is_DOUBLE:		return "double";
		case is_BOOLEAN:	return "int";
		case is_CHAR:		return "char";
		case is_NONE:       return "none";
	}
	return "unknown type";
}

void translate(is_static_list* list, prog_env* pe)
{
    FILE *dest;
    dest=fopen("result.c", "w");

    translate_header(dest);
    translate_static_list(dest, list, pe);
    translate_methods(dest, list, pe);
    translate_footer(dest);

    fclose(dest);
}

void translate_header(FILE* dest)
{
	fprintf(dest, "#include \"frame.h\"\n");
	fprintf(dest, "#include <stdlib.h>\n");
	fprintf(dest, "#include <stdio.h>\n\n");
	fprintf(dest, "int main()\n{\n");
	fprintf(dest, "int _ra;\n");
	fprintf(dest, "frame* fp=NULL;\n");
	fprintf(dest, "frame* sp=NULL;\n");
}

void translate_footer(FILE* dest)
{
	translate_redirector(dest);
	fprintf(dest, "\n}\n\n");
}

void translate_static_list(FILE* dest, is_static_list* list, prog_env* pe)
{
    is_static_list* aux;
	for(aux=list; aux; aux=aux->next)
		if(aux->stat->type==stat_declaration)
		    translate_declaration(GLOBALSCOPE, dest, (is_declaration*)aux->stat->content.dec, pe, pe->global);

}

void translate_attr_list(int scope, FILE* dest, is_attribution_list* attr, prog_env* pe, table_element* env)
{
    is_attribution_list* aux;
    for(aux=attr; aux; aux=aux->next)
        translate_attr(scope, dest, aux->attr, pe, env);
}

void translate_attr(int scope, FILE* dest, is_attribution* attr, prog_env* pe, table_element* env)
{
    table_element* aux = lookup(env, attr->name);
    if(scope==GLOBALSCOPE){
        fprintf(dest, "%s g%d",type_to_string_trans(aux->type) ,aux->offset);
        if(aux->type==is_STRING)
            fprintf(dest,"[100]");
        if(attr->type==attr_expression && attr->content.exp!=NULL){
            fprintf(dest,"=");
            translate_expression(scope, dest, (is_expression*)attr->content.exp, pe, env);
        }
        else if(attr->type==attr_b_expression){
            fprintf(dest,"=");
            translate_b_expression(scope, dest, (is_b_expression*)attr->content.b_exp, pe, env);
        }
        fprintf(dest,";\n");
    }
    else{
        fprintf(dest,"sp->locals[%d]=(%s*)malloc(sizeof(%s));\n",aux->offset,type_to_string_trans(aux->type),type_to_string_trans(aux->type));
        fprintf(dest,"*((%s*)sp->locals[%d])=",type_to_string_trans(aux->type),aux->offset);
        if(attr->type==attr_expression && attr->content.exp!=NULL){    
            translate_expression(scope, dest, (is_expression*)attr->content.exp, pe, env);
        }
        else
            translate_b_expression(scope, dest, (is_b_expression*)attr->content.b_exp, pe, env);
        fprintf(dest,";\n");
        //else if(attr->type==attr_expression && attr_expression==NULL){
    }
}

void translate_declaration(int scope, FILE* dest, is_declaration* dec, prog_env* pe, table_element* env)
{  
    translate_attr_list(scope, dest, dec->list, pe, env);
}

void translate_method(FILE* dest, is_method* im, prog_env* pe)
{

	environment_list* localenv=mlookup(pe->procs, im->name);	

	//PrÃ³logo
	fprintf(dest, "\n/*BLOCO DO metodo %s */\n", im->name); 
	fprintf(dest, "/*Prologo*/\n");
	fprintf(dest, "goto %sskip;\n", im->name);		 
	fprintf(dest, "%s:\n",im->name);
	fprintf(dest, "fp=sp;\n");	
	fprintf(dest, "sp=(frame*)malloc(sizeof(frame));\n");
	fprintf(dest, "sp->parent=fp;\n");
	fprintf(dest, "sp->return_address=_ra;\n");
	
	//Corpo do procedimento
	fprintf(dest, "/*Corpo do metodo*/\n");
	//translate_vardecs(dest, im->vlist, localenv, pe);			
	translate_statements(dest, (is_statement_list*)(im->stt_list), pe, localenv->locals);		

	//Epilogo
	fprintf(dest, "/*Epilogo*/\n");
	fprintf(dest, "_ra=sp->return_address;\n");	
	fprintf(dest, "sp=sp->parent;\n");
	fprintf(dest, "fp=sp->parent;\n");	
	fprintf(dest, "goto redirector;\n");		
	fprintf(dest, "%sskip:\n", im->name); 	
}

void translate_methods(FILE* dest, is_static_list* isl, prog_env* pe)
{
	is_static_list* aux;
	environment_list* etmp=pe->procs;

	for(aux=isl; aux; aux=aux->next)
	{
		if(aux->stat->type==stat_declaration)
			continue;
		if(strcmp(((is_method*)aux->stat->content.method)->name,"main")==0)
		    translate_main(dest, (is_method*)aux->stat->content.method, etmp, pe);
		else
		    translate_method(dest, (is_method*)aux->stat->content.method, pe);
		etmp=etmp->next;
	}
	
}	

void translate_main(FILE* dest, is_method* main, environment_list* local, prog_env* pe)
{
	fprintf(dest, "\n/*BLOCO MAIN */\n");
	fprintf(dest, "sp=(frame*)malloc(sizeof(frame));\n");
	fprintf(dest, "\n/*vardecs*/\n");
	//translate_vardecs(dest, main->vlist, local, pe);
	fprintf(dest, "\n/*statements*/\n");
	translate_statements(dest, (is_statement_list*) main->stt_list, pe, local->locals);	
}

void translate_redirector(FILE* dest)
{
	int i;
	fprintf(dest, "/*Redirector*/\n");
	fprintf(dest, "goto exit;\n");
	fprintf(dest, "redirector:\n");

	for(i=0; i<returncounter; i++)				//Para cada endereco de retorno, sua label associada
	{
		fprintf(dest, "if(_ra==%d) goto return%d;\n", i, i);
	}
	fprintf(dest, "exit:\n;\n");
}

void translate_statements(FILE* dest, is_statement_list* isl, prog_env* pe, table_element* env)
{
	is_statement_list* aux;

	for(aux=isl; aux; aux=aux->next)
		translate_statement(dest, aux->stt, pe, env);
	
}

void translate_statement(FILE* dest, is_statement* is, prog_env* pe, table_element* env)
{
	switch(is->type)
	{
	    case stt_declaration: translate_declaration(LOCALSCOPE, dest, (is_declaration*)is->content.dec, pe, env); break;
	    case stt_attribution: translate_attr(LOCALSCOPE, dest, (is_attribution*)is->content.attr, pe, env); break;
	    case stt_print: translate_print(LOCALSCOPE, dest, (is_print*)is->content._print, pe, env); break;
	}
}

void translate_expression(int scope, FILE* dest, is_expression* ie, prog_env* pe, table_element* env)
{
    switch(ie->type)
    {
        case exp_int:       fprintf(dest,"%d",ie->content.num_int);break;
        case exp_double:    fprintf(dest,"%f",ie->content.num_double);break;
        case exp_char:      fprintf(dest,"'%c'",ie->content.val_char);break;
        case exp_infix:     translate_infix_expression(scope, dest, (is_infix_expression*)ie->content.infix_exp,pe, env);break;
        case exp_unary:     translate_unary_expression(scope, dest, (is_unary_expression*)ie->content.unary_exp,pe, env);break;
    }
}

void translate_infix_expression(int scope, FILE* dest, is_infix_expression* iie, prog_env* pe, table_element* env)
{
    translate_simple_expression(scope, dest, iie->exp1, pe, env);
    translate_operator(scope, dest, iie->op);
    translate_simple_expression(scope, dest, iie->exp2, pe, env);
}

void translate_simple_expression(int scope, FILE* dest, is_s_expression* ise, prog_env* pe, table_element* env)
{
    switch(ise->type)
    {
        case s_exp_var: translate_var(scope, dest, ise->content.var, pe, env);break;
        case s_exp_exp: translate_expression(scope, dest, (is_expression*)ise->content.exp, pe, env); break;
        case s_exp_inc: translate_inc(scope, dest, (is_increment*)ise->content.inc, pe, env);break;
        case s_exp_m_call: break;
    }
}

void translate_var(int scope, FILE* dest, char* var, prog_env* pe, table_element* env)
{
    table_element* aux = lookup(env, var);
    if(scope==GLOBALSCOPE){
        aux=lookup(pe->global, var);
        fprintf(dest, "g%d\n",aux->offset);
    }
    else{
        aux = lookup(env, var);
        if(aux==0){
            aux=lookup(pe->global, var);
            fprintf(dest, "g%d\n",aux->offset);
        }
        else
            fprintf(dest, "(*((%s*)sp->locals[%d]))",type_to_string(aux->type),aux->offset);
    }
}

void translate_inc(int scope, FILE* dest, is_increment* inc, prog_env* pe, table_element* env)
{
    fprintf(dest,"(");
    translate_var(scope, dest, inc->var, pe, env);
    fprintf(dest,")%c%c",inc->op,inc->op);
}

void translate_unary_expression(int scope, FILE* dest, is_unary_expression* iue, prog_env* pe, table_element* env)
{
    switch(iue->type){
        case u_exp_neg:
            fprintf(dest,"-");
            translate_simple_expression(scope, dest, (is_s_expression*)iue->exp, pe, env);
            break;
        
        case u_exp_par:
            fprintf(dest,"(");
            translate_simple_expression(scope, dest, (is_s_expression*)iue->exp, pe, env);
            fprintf(dest,")");
            break;
    }
}

void translate_operator(int scope, FILE* dest, is_operator op)
{
	if(op==is_PLUS)
		fprintf(dest,"+");
	else if(op==is_MINUS)
		fprintf(dest,"-");
	else if(op==is_MULT)
		fprintf(dest,"*");
	else if(op==is_MOD)
		fprintf(dest,"%c",'%');
	else
		fprintf(dest,"/");
}

void translate_b_expression(int scope, FILE* dest, is_b_expression* ie, prog_env* pe, table_element* env)
{
    switch(ie->type)
    {
        case b_exp_bool:    fprintf(dest,"%c",ie->content.boolean);break;
        case b_exp_infix:   translate_b_infix_expression(scope, dest, (is_b_infix_expression*)ie->content.infix_b_exp,pe, env);break;
        case b_exp_comp:    translate_comparison(scope, dest, (is_comparison*)ie->content.comp, pe, env);break;
        case b_exp_var:     translate_var(scope, dest, ie->content.var, pe, env);break;
        case b_exp_inc:     translate_inc(scope, dest, (is_increment*)ie->content.inc, pe, env);break;
        case b_exp_not:     translate_b_not_exp(scope, dest, (is_b_not_expression*)ie->content.not_b_exp, pe, env);break;
    }
}

void translate_b_not_exp(int scope, FILE* dest, is_b_not_expression* ibne, prog_env* pe, table_element* env)
{
    fprintf(dest,"!");
    translate_b_expression(scope, dest, (is_b_expression*)ibne->exp,pe,env);
}

void translate_b_infix_expression(int scope, FILE* dest, is_b_infix_expression* ibie, prog_env* pe, table_element* env)
{
    translate_b_expression(scope, dest, ibie->exp1, pe, env);
    translate_b_operator(scope, dest, ibie->op);
    translate_b_expression(scope, dest, ibie->exp2, pe, env);
}

void translate_b_operator(int scope, FILE* dest, is_b_operator op)
{
    if(op==is_AND)
		fprintf(dest,"&&");
	else if(op==is_OR)
		fprintf(dest,"||");
	else
		fprintf(dest,"!");
}

void translate_comparison(int scope, FILE* dest, is_comparison* comp, prog_env* pe, table_element* env)
{
    translate_simple_expression(scope, dest, comp->exp1, pe, env);
    translate_comparator(scope, dest, comp->op);
    translate_simple_expression(scope, dest, comp->exp2, pe, env);
}

void translate_comparator(int scope, FILE* dest, is_comparator op)
{
	if(op==is_EQUALS)
		fprintf(dest,"==");
	else if(op==is_DIFERENT)
		fprintf(dest,"!=");
	else if(op==is_GREATER)
		fprintf(dest,">");
	else if(op==is_DIFERENT)
		fprintf(dest,"!=");
	else if(op==is_LESSER)
		fprintf(dest,"<");
	else if(op==is_GREATEQ)
		fprintf(dest,">=");
	else if(op==is_LESSEQ)
		fprintf(dest,">=");
}

void translate_print(int scope, FILE* dest, is_print* ip, prog_env* pe, table_element* env)
{
    switch(ip->exp_type)
    {
        case is_INT: fprintf(dest,"printf(\"%%d\\n\","); break;
        case is_CHAR:fprintf(dest,"printf(\"%%c\\n\","); break;
        case is_BOOLEAN: fprintf(dest,"printf(\"%%d\\n\","); break;
        case is_DOUBLE: fprintf(dest,"printf(\"%%f\\n\","); break;
    }
    translate_simple_expression(scope, dest, (is_s_expression*)ip->content.exp, pe, env);
    fprintf(dest,");\n");
}
