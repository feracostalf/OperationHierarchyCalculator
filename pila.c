#include"pila.h"
#include <stdlib.h>

NODO pop(pila*s){
	NODO w;
	w=**s;
	free(*s);
	*s=w.sig;
	w.sig=NULL;
	return w;
}

void ini_pila(pila*s){
	*s=NULL;
}
void liberar_pila(pila*s){
	while(!empty(*s))
		pop(s);
}

booleano empty(pila s){
	if (s==NULL){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

NODO top(pila s){
	NODO copia;
	copia=*s;
	copia.sig=NULL;
	return copia;
}
	
mensaje push(pila*s, NODO D){
	pila temp=NULL;
	temp=(pila)malloc(sizeof(NODO));
	if(temp==NULL){
		return NO_MEMORY;
	}
	else
	{
		*temp=D;
		if(empty(*s)){
			temp->sig=NULL;
		}
		else{
			temp->sig=*s;
		}
			*s=temp;
			return OK;	
	}
}
