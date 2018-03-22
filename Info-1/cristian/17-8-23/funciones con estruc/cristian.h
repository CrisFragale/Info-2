#include <stdio.h>
#include <stdlib.h>

typedef struct dato{

	int a;
	char info[15];
	}dato_t;

typedef struct nodo{

	dato_t dato;
	struct nodo* next;
	}nodo_t;

int insertarini (nodo_t ** inicio, dato_t d );
int insertarfin (nodo_t ** inicio, dato_t d);
void imprimir (nodo_t *i);
nodo_t* busqueda (nodo_t *i, dato_t d);
void liberartoda (nodo_t ** h);
int insetarorden (nodo_t **h, dato_t d);
int eliminar (nodo_t ** h,  dato_t d);