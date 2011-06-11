#include "translate.h"
#include "structures.h"
#include "semantic.h"
#include "symbol_table.h"
#include <stdio.h>
#include <string.h>

int returncounter=0;
int ifcounter=0;
int forcounter=0;
int whilecounter=0;
int tempcounter=0;
int argcounter=0;
char ret[100];

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
	fprintf(dest, "void* temp[64];\n");
	fprintf(dest, "void* ret_val;\n");
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
        translate_attr(scope, dest, aux->attr, pe, env, 1);
}

void translate_attr(int scope, FILE* dest, is_attribution* attr, prog_env* pe, table_element* env, int dec)
{
    table_element* aux = lookup(env, attr->name);
    char temp2[100];
    if(scope==GLOBALSCOPE){
        char temp[100];
        if(attr->type==attr_expression && attr->content.exp!=NULL){
            strcpy(temp,translate_expression(scope, dest, (is_expression*)attr->content.exp, pe, env));
        }
        else if(attr->type==attr_b_expression){
            strcpy(temp,translate_b_expression(scope, dest, (is_b_expression*)attr->content.b_exp, pe, env));
        }
        fprintf(dest, "%s g%d",type_to_string_trans(aux->type) ,aux->offset);
        if(attr->op!='='){
            char temp3[1];
            sprintf(temp2, "%s g%d", type_to_string_trans(aux->type) ,aux->offset);
            sprintf(temp3, "%c", attr->op);
            strcat(temp2, temp3);
            strcat(temp2, temp);
        }
        else
            sprintf(temp2,"%s",temp);
        if(aux->type==is_STRING)
            fprintf(dest,"[100]");
        if(attr->content.exp!=NULL)
            fprintf(dest,"=%s;\n",temp2);
        else
            fprintf(dest,";\n");
    }
    else{
        if(dec==1)
            fprintf(dest,"sp->locals[%d]=(%s*)malloc(sizeof(%s));\n",aux->offset,type_to_string_trans(aux->type),type_to_string_trans(aux->type));
        if(attr->op!='='){
            char temp3[1];
            sprintf(temp2, "*((%s*)sp->locals[%d])", type_to_string_trans(aux->type),aux->offset);
            sprintf(temp3, "%c", attr->op);
            strcat(temp2, temp3);
        }
        else
            strcpy(temp2,"");
        if(attr->type==attr_expression && attr->content.exp!=NULL)
            fprintf(dest,"*((%s*)sp->locals[%d])=%s%s;\n",type_to_string_trans(aux->type),aux->offset, temp2, translate_expression(scope, dest, (is_expression*)attr->content.exp, pe, env));
        else if(attr->type==attr_b_expression)
            fprintf(dest,"*((%s*)sp->locals[%d])=%s%s;\n",type_to_string_trans(aux->type),aux->offset, temp2, translate_b_expression(scope, dest, (is_b_expression*)attr->content.b_exp, pe, env));
    }
    tempcounter=0;
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
	
	is_argument_list* args = (is_argument_list*)im->arg_list;
	int i;
	for(i=0; args; args=args->next){
	    fprintf(dest,"sp->locals[%d]=(%s*)malloc(sizeof(%s));\n",i, type_to_string_trans(args->arg->type), type_to_string_trans(args->arg->type));
	    fprintf(dest,"(*((%s*)sp->locals[%d]))=(*((%s*)sp->parent->outgoing[%d]));\n",type_to_string_trans(args->arg->type),i,type_to_string_trans(args->arg->type),i);
	    i++;
	}
	
	//Corpo do procedimento
	fprintf(dest, "/*Corpo do metodo*/\n");
	translate_statements(dest, (is_statement_list*)(im->stt_list), pe, localenv->locals, im->name);		
    
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
	fprintf(dest, "\n/*statements*/\n");
	char temp[100];
	strcpy(temp, "main");
	translate_statements(dest, (is_statement_list*) main->stt_list, pe, local->locals, temp);	
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

void translate_statements(FILE* dest, is_statement_list* isl, prog_env* pe, table_element* env, char* name)
{
	is_statement_list* aux;

	for(aux=isl; aux; aux=aux->next)
		translate_statement(dest, aux->stt, pe, env, name);
	
}

void translate_statement(FILE* dest, is_statement* is, prog_env* pe, table_element* env, char* name)
{
	switch(is->type)
	{
	    case stt_declaration: translate_declaration(LOCALSCOPE, dest, (is_declaration*)is->content.dec, pe, env); break;
	    case stt_attribution: translate_attr(LOCALSCOPE, dest, (is_attribution*)is->content.attr, pe, env, 0); break;
	    case stt_print: translate_print(LOCALSCOPE, dest, (is_print*)is->content._print, pe, env); break;
	    case stt_if: translate_if(LOCALSCOPE, dest, (is_if*)is->content._if, pe, name); break;
	    case stt_while: translate_while(LOCALSCOPE, dest, (is_while*)is->content._while, pe, name); break;
	    case stt_for: translate_for(LOCALSCOPE, dest, (is_for*)is->content._for, pe, name); break;
	    case stt_inc: fprintf(dest,"%s;\n",translate_inc(LOCALSCOPE, dest, (is_increment*)is->content.inc, pe, env)); break;
	    case stt_return: translate_return(LOCALSCOPE, dest, (is_return*)is->content._return, pe, env, name); break;
	    case stt_m_call: translate_method_call(LOCALSCOPE, dest, (is_method_call*)is->content.m_call, pe, env); break;
	}
}

char* translate_expression(int scope, FILE* dest, is_expression* ie, prog_env* pe, table_element* env)
{
    switch(ie->type)
    {
        case exp_int:       sprintf(ret,"%d",ie->content.num_int); return ret;
        case exp_double:    sprintf(ret,"%f",ie->content.num_double); return ret;
        case exp_char:      sprintf(ret,"'%c'",ie->content.val_char); return ret;
        case exp_infix:     return translate_infix_expression(scope, dest, (is_infix_expression*)ie->content.infix_exp,pe, env);
        case exp_unary:     return translate_unary_expression(scope, dest, (is_unary_expression*)ie->content.unary_exp,pe, env);
    }
    return NULL;
}

char* translate_infix_expression(int scope, FILE* dest, is_infix_expression* iie, prog_env* pe, table_element* env)
{
    char aux1[100], op[5], aux2[100], temp[20];
    strcpy(aux1,translate_simple_expression(scope, dest, iie->exp1, pe, env));
    strcpy(op,translate_operator(scope, dest, iie->op));
    strcpy(aux2,translate_simple_expression(scope, dest, iie->exp2, pe, env));
    if(scope==GLOBALSCOPE)
        strcpy(temp,"");
    else
        strcpy(temp,"sp->");
    fprintf(dest, "%stemp[%d]=(%s*)malloc(sizeof(%s));\n",temp, tempcounter, type_to_string_trans(iie->val_type), type_to_string_trans(iie->val_type));
    fprintf(dest,"(*((%s*)%stemp[%d]))=%s%s%s;\n",type_to_string_trans(iie->val_type),temp, tempcounter, aux1,op,aux2);
    sprintf(ret, "(*((%s*)%stemp[%d]))",type_to_string_trans(iie->val_type),temp, tempcounter);
    tempcounter++;
    return ret;
}

char* translate_simple_expression(int scope, FILE* dest, is_s_expression* ise, prog_env* pe, table_element* env)
{
    switch(ise->type)
    {
        case s_exp_var: return translate_var(scope, dest, ise->content.var, pe, env);
        case s_exp_exp: return translate_expression(scope, dest, (is_expression*)ise->content.exp, pe, env);
        case s_exp_inc: return translate_inc(scope, dest, (is_increment*)ise->content.inc, pe, env);
        case s_exp_m_call: return translate_method_call(scope, dest, (is_method_call*)ise->content.m_call, pe, env);
    }
    return NULL;
}

char* translate_var(int scope, FILE* dest, char* var, prog_env* pe, table_element* env)
{
    table_element* aux = lookup(env, var);
    if(scope==GLOBALSCOPE){
        aux=lookup(pe->global, var);
        sprintf(ret, "g%d",aux->offset);
    }
    else{
        aux = lookup(env, var);
        if(aux==0){
            aux=lookup(pe->global, var);
            sprintf(ret, "g%d",aux->offset);
        }
        else{
            sprintf(ret, "(*((%s*)sp->locals[%d]))",type_to_string_trans(aux->type),aux->offset);
        }
    }
    return ret;
}

char* translate_inc(int scope, FILE* dest, is_increment* inc, prog_env* pe, table_element* env)
{
    char temp[20], temp2[100];
    table_element* aux;
    if(scope==GLOBALSCOPE){
        strcpy(temp,"");
        aux = lookup(pe->global, inc->var);
    }
    else{
        strcpy(temp,"sp->");
        aux = lookup(env, inc->var);
    }
    fprintf(dest, "%stemp[%d]=(%s*)malloc(sizeof(%s));\n",temp, tempcounter, type_to_string_trans(aux->type), type_to_string_trans(aux->type));
    strcpy(temp2, translate_var(scope, dest, inc->var, pe, env));
    fprintf(dest, "(*((%s*)%stemp[%d]))=%s;\n",type_to_string_trans(aux->type),temp, tempcounter, temp2);
    if(scope==GLOBALSCOPE)
        fprintf(dest, "g%d=g%d%c1;\n",aux->offset, aux->offset,inc->op); 
    else
        fprintf(dest, "(*((%s*)sp->locals[%d]))=(*((%s*)sp->locals[%d]))%c1;\n",type_to_string_trans(aux->type), aux->offset, type_to_string_trans(aux->type), aux->offset,inc->op); 
    sprintf(ret, "(*((%s*)%stemp[%d]))",type_to_string_trans(aux->type),temp, tempcounter);
    tempcounter++;
    return ret;
}

char* translate_unary_expression(int scope, FILE* dest, is_unary_expression* iue, prog_env* pe, table_element* env)
{
    char aux[100];
    strcpy(aux,translate_simple_expression(scope, dest, (is_s_expression*)iue->exp, pe, env));
    switch(iue->type){
        case u_exp_neg:
            strcpy(ret, "-");
            strcpy(ret, aux);
            break;
        
        case u_exp_par:
            strcpy(ret,"(");
            strcat(ret, aux);
            strcat(ret,")");
            break;
    }
    
    return ret;
}

char* translate_operator(int scope, FILE* dest, is_operator op)
{
	if(op==is_PLUS)
		strcpy(ret,"+");
	else if(op==is_MINUS)
		strcpy(ret,"-");
	else if(op==is_MULT)
		strcpy(ret,"*");
	else if(op==is_MOD)
		sprintf(ret,"%c",'%');
	else
		strcpy(ret,"/");
	return ret;
}

char* translate_b_expression(int scope, FILE* dest, is_b_expression* ie, prog_env* pe, table_element* env)
{
    switch(ie->type)
    {
        case b_exp_bool:    sprintf(ret,"%c",ie->content.boolean); return ret;
        case b_exp_infix:   return translate_b_infix_expression(scope, dest, (is_b_infix_expression*)ie->content.infix_b_exp,pe, env);
        case b_exp_comp:    return translate_comparison(scope, dest, (is_comparison*)ie->content.comp, pe, env);
        case b_exp_var:     return translate_var(scope, dest, ie->content.var, pe, env);
        case b_exp_inc:     return translate_inc(scope, dest, (is_increment*)ie->content.inc, pe, env);
        case b_exp_not:     return translate_b_not_exp(scope, dest, (is_b_not_expression*)ie->content.not_b_exp, pe, env);
        case b_exp_m_call:  return translate_method_call(scope, dest, (is_method_call*)ie->content.m_call, pe, env);
    }
    return NULL;
}

char* translate_b_not_exp(int scope, FILE* dest, is_b_not_expression* ibne, prog_env* pe, table_element* env)
{
    char aux[100];
    strcpy(aux,translate_b_expression(scope, dest, (is_b_expression*)ibne->exp,pe,env));
    strcpy(ret,"!");
    strcpy(ret,aux);
    return ret;
}

char* translate_b_infix_expression(int scope, FILE* dest, is_b_infix_expression* ibie, prog_env* pe, table_element* env)
{
    char aux1[100], op[5], aux2[100], temp[20];
    strcpy(aux1,translate_b_expression(scope, dest, ibie->exp1, pe, env));
    strcpy(op,translate_b_operator(scope, dest, ibie->op));
    strcpy(aux2,translate_b_expression(scope, dest, ibie->exp2, pe, env));
    if(scope==GLOBALSCOPE)
        strcpy(temp,"");
    else
        strcpy(temp,"sp->");
    fprintf(dest, "%stemp[%d]=(%s*)malloc(sizeof(%s));\n",temp, tempcounter, type_to_string_trans(ibie->val_type), type_to_string_trans(ibie->val_type));
    fprintf(dest,"(*((%s*)%stemp[%d]))=%s%s%s;\n",type_to_string_trans(ibie->val_type),temp, tempcounter, aux1,op,aux2);
    sprintf(ret, "(*((%s*)%stemp[%d]))",type_to_string_trans(ibie->val_type),temp, tempcounter);
    tempcounter++;
    return ret;
}

char* translate_b_operator(int scope, FILE* dest, is_b_operator op)
{
    if(op==is_AND)
		sprintf(ret,"&&");
	else if(op==is_OR)
		sprintf(ret,"||");
	else
		sprintf(ret,"!");
    return ret;
}

char* translate_comparison(int scope, FILE* dest, is_comparison* comp, prog_env* pe, table_element* env)
{
    char aux1[100], op[5], aux2[100], temp[20];
    strcpy(aux1,translate_simple_expression(scope, dest, comp->exp1, pe, env));
    strcpy(op,translate_comparator(scope, dest, comp->op));
    strcpy(aux2,translate_simple_expression(scope, dest, comp->exp2, pe, env));
    if(scope==GLOBALSCOPE)
        strcpy(temp,"");
    else
        strcpy(temp,"sp->");
    fprintf(dest, "%stemp[%d]=(%s*)malloc(sizeof(%s));\n",temp, tempcounter, type_to_string_trans(comp->val_type), type_to_string_trans(comp->val_type));
    fprintf(dest,"(*((%s*)%stemp[%d]))=%s%s%s;\n",type_to_string_trans(comp->val_type),temp, tempcounter, aux1,op,aux2);
    sprintf(ret, "(*((%s*)%stemp[%d]))",type_to_string_trans(comp->val_type),temp, tempcounter);
    tempcounter++;
    return ret;
}

char* translate_comparator(int scope, FILE* dest, is_comparator op)
{
	if(op==is_EQUALS)
		strcpy(ret,"==");
	else if(op==is_DIFERENT)
		strcpy(ret,"!=");
	else if(op==is_GREATER)
        strcpy(ret,">");
	else if(op==is_LESSER)
		strcpy(ret,"<");
	else if(op==is_GREATEQ)
		strcpy(ret,">=");
	else if(op==is_LESSEQ)
		strcpy(ret,"<=");
	return ret;
}

void translate_print(int scope, FILE* dest, is_print* ip, prog_env* pe, table_element* env)
{
    char aux[100];
    strcpy(aux, translate_simple_expression(scope, dest, (is_s_expression*)ip->content.exp, pe, env));
    if(ip->end == '\n')
        switch(ip->exp_type)
        {
            case is_INT: fprintf(dest,"printf(\"%%d\\n\",%s);\n",aux); break;
            case is_CHAR:fprintf(dest,"printf(\"%%c\\n\",%s);\n",aux); break;
            case is_BOOLEAN: fprintf(dest,"printf(\"%%d\\n\",%s);\n",aux); break;
            case is_DOUBLE: fprintf(dest,"printf(\"%%f\\n\",%s);\n",aux); break;
            case is_VOID: break;
            case is_FLOAT: break;
            case is_NONE: break;
            case is_STRING: break;
        }
    else
        switch(ip->exp_type)
        {
            case is_INT: fprintf(dest,"printf(\"%%d\",%s);\n",aux); break;
            case is_CHAR:fprintf(dest,"printf(\"%%c\",%s);\n",aux); break;
            case is_BOOLEAN: fprintf(dest,"printf(\"%%d\",%s);\n",aux); break;
            case is_DOUBLE: fprintf(dest,"printf(\"%%f\",%s);\n",aux); break;
            case is_VOID: break;
            case is_FLOAT: break;
            case is_NONE: break;
            case is_STRING: break;
        }
}

void translate_if(int scope, FILE* dest, is_if* ii, prog_env* pe, char* name)
{
    char temp[10], nameif[10], nameelse[10], namethen[10], endif[10], aux[100];
    strcpy(nameif, "if");
    strcpy(nameelse, "else");
    strcpy(namethen, "then");
    strcpy(endif, "endif");
    sprintf(temp, "%d", ifcounter);
    ifcounter++;
    strcat(nameif, temp);
    strcat(nameelse, temp);
    strcat(namethen, temp);
    strcat(endif, temp);
    table_element* env=(mlookup(pe->procs, nameif))->locals;
    strcpy(aux,translate_b_expression(scope, dest, ii->exp, pe, env));
    fprintf(dest,"if(%s) goto %s; \n%s:\n",aux,namethen,nameelse);
    if(ii->ifelse!=NULL)
        translate_else(scope, dest, ii->ifelse, pe, nameelse, name);
    fprintf(dest,"goto %s;\n%s:\n",endif,namethen);
    translate_statements(dest, ii->stt, pe, env, name);
    fprintf(dest,"%s:\n",endif); 
}

void translate_else(int scope, FILE* dest, is_else* ie, prog_env* pe, char* n, char* name)
{
    table_element* env=(mlookup(pe->procs, n))->locals;
    translate_statements(dest, ie->stt, pe, env, name);
}

void translate_while(int scope, FILE* dest, is_while* iw, prog_env* pe, char* name)
{
    char temp[10], namewhile[10], endwhile[10], aux[100];
    strcpy(namewhile, "while");
    strcpy(endwhile, "endwhile");
    sprintf(temp, "%d", whilecounter);
    whilecounter++;
    strcat(namewhile, temp);
    strcat(endwhile, temp);
    table_element* env=(mlookup(pe->procs, namewhile))->locals;
    fprintf(dest,"%s:\n",namewhile);
    strcpy(aux, translate_b_expression(scope, dest, iw->exp, pe, env));
    fprintf(dest,"if(!(%s)) goto %s;\n",aux,endwhile);
    translate_statements(dest, iw->stt, pe, env, name);
    fprintf(dest,"goto %s;\n",namewhile);
    fprintf(dest,"%s:\n",endwhile); 
}

void translate_for(int scope, FILE* dest, is_for* isf, prog_env* pe, char* name)
{
    char temp[10], namefor[10], endfor[10], aux[100];
    strcpy(namefor, "for");
    strcpy(endfor, "endfor");
    sprintf(temp, "%d", forcounter);
    forcounter++;
    strcat(namefor, temp);
    strcat(endfor, temp);
    table_element* env=(mlookup(pe->procs, namefor))->locals;
    translate_statements(dest, isf->attr, pe, env, name);
    fprintf(dest,"%s:\n",namefor);
    strcpy(aux,translate_b_expression(scope, dest, isf->b_exp, pe, env));
    fprintf(dest,"if(!(%s)) goto %s;\n",aux,endfor);
    translate_statements(dest, isf->stt, pe, env, name);
    translate_statements(dest, isf->last, pe, env, name);
    fprintf(dest,"goto %s;\n",namefor);
    fprintf(dest,"%s:\n",endfor); 
}

char* translate_method_call(int scope, FILE* dest, is_method_call* imc, prog_env* pe, table_element* env)
{
    char temp[100];
    table_element* aux = lookup(pe->global, imc->name);
    translate_arguments(scope, dest, imc->m_arg_list, pe, env);
    argcounter=0;
    fprintf(dest, "_ra=%d;\n",returncounter);		//guarda de endereco de retorno
	fprintf(dest, "goto %s;\n", imc->name);			//Salto para codigo do procedimento
	fprintf(dest, "return%d:\n", returncounter);		//label de retorno
	fprintf(dest, "sp->temp[%d]=(%s*)malloc(sizeof(%s));\n",tempcounter, type_to_string_trans(aux->type), type_to_string_trans(aux->type));
    fprintf(dest,"(*((%s*)sp->temp[%d]))=(*((%s*)ret_val));\n",type_to_string_trans(aux->type),tempcounter,type_to_string_trans(aux->type));
    sprintf(temp,"(*((%s*)sp->temp[%d]))",type_to_string_trans(aux->type), tempcounter);
	returncounter++;
	tempcounter++;
	strcpy(ret, temp);
	return ret;
}

void translate_arguments(int scope, FILE* dest, is_method_arg_list* imal, prog_env* pe, table_element* env)
{
    is_method_arg_list* aux = (is_method_arg_list*)imal;
    for(; aux; aux=aux->next)
        translate_argument(scope, dest, (is_method_arg*)aux->m_arg, pe, env);
}

void translate_argument(int scope, FILE* dest, is_method_arg* ima, prog_env* pe, table_element* env)
{
    char temp[100];
    is_type temp_type;
    if(ima->type==arg_expression){
        strcpy(temp,translate_expression(scope, dest, ima->content.exp, pe, env));
        temp_type=ima->content.exp->val_type;
    }
    else{
        strcpy(temp,translate_b_expression(scope, dest, ima->content.b_exp, pe, env));
        temp_type=ima->content.b_exp->val_type;
    }
    fprintf(dest, "sp->outgoing[%d]=(%s*)malloc(sizeof(%s));\n",argcounter,type_to_string_trans(temp_type),type_to_string_trans(temp_type));
    fprintf(dest, "(*((%s*)sp->outgoing[%d]))=%s;\n",type_to_string_trans(temp_type), argcounter, temp);
    argcounter++;
}

void translate_return(int scope, FILE* dest, is_return* ir, prog_env* pe, table_element* env, char* name)
{
    char temp[100];
    is_type temp_type;
    if(ir->type==ret_expression){
        strcpy(temp,translate_expression(scope, dest, ir->content.exp, pe, env));
        temp_type=(ir->content.exp)->val_type;
    }
    else{
        strcpy(temp,translate_b_expression(scope, dest, ir->content.b_exp, pe, env));
        temp_type=(ir->content.b_exp)->val_type;   
    }
    if(strcmp(name,"main")!=0){
        fprintf(dest, "/*Epilogo*/\n");
        fprintf(dest, "ret_val=(%s*)malloc(sizeof(%s));\n",type_to_string_trans(temp_type),type_to_string_trans(temp_type));
	    fprintf(dest, "(*((%s*)ret_val))=%s;\n",type_to_string_trans(temp_type), temp);
	    fprintf(dest, "_ra=sp->return_address;\n");
	    fprintf(dest, "sp=sp->parent;\n");
	    fprintf(dest, "fp=sp->parent;\n");
	    fprintf(dest, "goto redirector;\n");	
	}
}
