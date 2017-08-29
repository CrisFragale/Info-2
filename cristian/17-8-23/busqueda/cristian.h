#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{

	int a;
	struct nodo* next;
	}nodo_t;

int insertarini (nodo_t ** inicio, int d );
int insertarfin (nodo_t ** inicio, int d);
void imprimir (nodo_t *i);
nodo_t* busqueda (nodo_t *i, int d);
void liberartoda (nodo_t ** h);