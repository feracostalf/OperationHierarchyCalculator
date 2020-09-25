#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int aposfijo(char*,char*);
int menorpre(char, char);
int resultado(char*);

int main(int argc, char *argv[]) {
	char infijo[50];
	char posfijo[50];
	printf("Operacion: ");
	scanf("%s",infijo);
	aposfijo(infijo, posfijo);
	return 0;
}

int aposfijo(char*inf,char*pos){
	int i=0,j=0;
	pila ptr;
	NODO D;
	ini_pila(&ptr);
	
	while(inf[i]!='\0'){
		if(inf[i]>='0'&&inf[i]<='9'){
			pos[j++]=inf[i++];
		}
		if(inf[i]=='('){
			D.operador=inf[i++];
			push(&ptr,D);	
		}
		if(inf[i]==')'){
			while(top(ptr).operador!='('){
				pos[j++]=pop(&ptr).operador;
			}
			pop(&ptr);
			i++;
		}
		if(inf[i]=='+'||inf[i]=='-'||inf[i]=='/'||inf[i]=='*'){
			if(empty(ptr)||top(ptr).operador=='('){
				D.operador=inf[i++];
				push(&ptr,D);
			}
			else{
				if(menorpre(top(ptr).operador,inf[i])){
					D.operador=inf[i++];
					push(&ptr,D);
				} 
				else{
					while(!empty(ptr)&&top(ptr).operador!='('){
						pos[j++]=pop(&ptr).operador;		
					}
					D.operador=inf[i++];
					push(&ptr,D);
				}
			}
		}
	
	}
	while(!empty(ptr)){
		pos[j++]=pop(&ptr).operador;
		}	
		pos[j]='\0';
			
	printf("%s",pos);
	liberar_pila(&ptr);
	resultado(pos);
}

int menorpre(char operador, char inf){
	if(operador=='('){
		return TRUE;
	}
	if(operador=='-'||operador=='+'&&inf=='*'||inf=='/'||inf==')'){
		return TRUE;
	}
	return FALSE;
}

int resultado(char*pos){
	NODO D;
	pila ptr;
	ini_pila(&ptr);
	int i=0, cont=0;
	char num1,num2;
	
	while(pos[i]!='\0'){
		if(pos[i]>='0'&&pos[i]<='9'){
			D.operador=pos[i++]-48;
			push(&ptr,D);
		}
		else{
			if(pos[i]=='+'||pos[i]=='-'||pos[i]=='/'||pos[i]=='*'){
				num2=pop(&ptr).operador;
				num1=pop(&ptr).operador;

				switch (pos[i++]){
					case '+':
						D.operador=(num1+num2);
						push(&ptr,D);
					break;
					case '-':
						D.operador=(num1-num2);
						push(&ptr,D);
					break;
					case '*':
						D.operador=(num1*num2);
						push(&ptr,D);
					break;
					case '/':
						if(num2==0){
							printf("\nMath error");
							return 0;
						}
						D.operador=(num1/num2);
						push(&ptr,D);
					break;
				}	
			}
		}
	}
	printf("\nResultado= %d",top(ptr).operador);
	liberar_pila(&ptr);
}


