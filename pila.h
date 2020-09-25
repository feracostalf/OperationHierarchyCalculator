struct nodo{
	char operador;
	struct nodo*sig;
};

typedef struct nodo NODO;
typedef NODO* pila;
typedef enum m{NO_MEMORY,OK} mensaje;
typedef enum b{FALSE,TRUE} booleano;

void ini_pila(pila*);
void liberar_pila(pila*);
NODO pop(pila*);
mensaje push(pila*,NODO);
booleano empty(pila);
NODO top(pila);




