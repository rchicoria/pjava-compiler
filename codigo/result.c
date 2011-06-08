#include "frame.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
int _ra;
frame* fp=NULL;
frame* sp=NULL;
int g0=1;
int g1=1;
int g2=g1
+g0
;
char g3[100];

/*BLOCO DO metodo func */
/*Prologo*/
goto funcskip;
func:
fp=sp;
sp=(frame*)malloc(sizeof(frame));
sp->parent=fp;
sp->return_address=_ra;
/*Corpo do metodo*/
/*Epilogo*/
_ra=sp->return_address;
sp=sp->parent;
fp=sp->parent;
goto redirector;
funcskip:

/*BLOCO MAIN */
sp=(frame*)malloc(sizeof(frame));

/*vardecs*/

/*statements*/
sp->locals[1]=(int*)malloc(sizeof(int));
*((int*)sp->locals[1])=2+g2
;
sp->locals[2]=(int*)malloc(sizeof(int));
*((int*)sp->locals[2])=(*((int*)sp->locals[1]))+5;
sp->locals[3]=(double*)malloc(sizeof(double));
*((double*)sp->locals[3])=1.000000;
sp->locals[4]=(int*)malloc(sizeof(int));
*((int*)sp->locals[4])=!1;
sp->locals[5]=(char*)malloc(sizeof(char));
*((char*)sp->locals[5])='h';
sp->locals[6]=(int*)malloc(sizeof(int));
*((int*)sp->locals[6])=(*((int*)sp->locals[2]))-(-(((*((int*)sp->locals[1])))++));
sp->locals[7]=(int*)malloc(sizeof(int));
*((int*)sp->locals[7])=;
sp->locals[1]=(int*)malloc(sizeof(int));
*((int*)sp->locals[1])=(-(*((int*)sp->locals[2]))*(*((int*)sp->locals[1])))/(3%2);
sp->locals[7]=(int*)malloc(sizeof(int));
*((int*)sp->locals[7])=(*((int*)sp->locals[2]))>=(*((int*)sp->locals[1]));
sp->locals[2]=(int*)malloc(sizeof(int));
*((int*)sp->locals[2])=((*((int*)sp->locals[1])))++;
printf("%d\n",(*((int*)sp->locals[1])));
/*Redirector*/
goto exit;
redirector:
exit:
;

}

