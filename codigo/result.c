#include "frame.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
int _ra;
frame* fp=NULL;
frame* sp=NULL;
void* temp[64];
void* ret_val;

/*BLOCO DO metodo dec */
/*Prologo*/
goto decskip;
dec:
fp=sp;
sp=(frame*)malloc(sizeof(frame));
sp->parent=fp;
sp->return_address=_ra;
sp->locals[0]=(int*)malloc(sizeof(int));
(*((int*)sp->locals[0]))=(*((int*)sp->parent->outgoing[0]));
/*Corpo do metodo*/
sp->temp[0]=(int*)malloc(sizeof(int));
(*((int*)sp->temp[0]))=(*((int*)sp->locals[0]));
(*((int*)sp->locals[0]))=(*((int*)sp->locals[0]))+1;
(*((int*)sp->temp[0]));
sp->temp[1]=(int*)malloc(sizeof(int));
(*((int*)sp->temp[1]))=(*((int*)sp->locals[0]))<10;
if((*((int*)sp->temp[1]))) goto then0; 
else0:
goto endif0;
then0:
sp->outgoing[0]=(int*)malloc(sizeof(int));
(*((int*)sp->outgoing[0]))=(*((int*)sp->locals[0]));
_ra=0;
goto dec;
return0:
sp->temp[2]=(int*)malloc(sizeof(int));
(*((int*)sp->temp[2]))=(*((int*)ret_val));
*((int*)sp->locals[0])=(*((int*)sp->temp[2]));
endif0:
/*Epilogo*/
ret_val=(int*)malloc(sizeof(int));
(*((int*)ret_val))=(*((int*)sp->locals[0]));
_ra=sp->return_address;
sp=sp->parent;
fp=sp->parent;
goto redirector;
/*Epilogo*/
_ra=sp->return_address;
sp=sp->parent;
fp=sp->parent;
goto redirector;
decskip:

/*BLOCO MAIN */
sp=(frame*)malloc(sizeof(frame));

/*vardecs*/

/*statements*/
sp->locals[0]=(int*)malloc(sizeof(int));
*((int*)sp->locals[0])=0;
sp->outgoing[0]=(int*)malloc(sizeof(int));
(*((int*)sp->outgoing[0]))=(*((int*)sp->locals[0]));
_ra=1;
goto dec;
return1:
sp->temp[0]=(int*)malloc(sizeof(int));
(*((int*)sp->temp[0]))=(*((int*)ret_val));
printf("%d\n",(*((int*)sp->temp[0])));
/*Redirector*/
goto exit;
redirector:
if(_ra==0) goto return0;
if(_ra==1) goto return1;
exit:
;

}

