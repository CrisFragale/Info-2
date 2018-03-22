#include <stdio.h>
#include <stdlib.h>

typedef struct dato{

	int codigo;
	int cantidad;
   }dato_t;

typedef struct nodo{

	dato_t dato;
	struct nodo* next;
	}nodo_t;

int insert (nodo_t ** ptrH, dato_t dt);
int insertarfin (nodo_t ** inicio, dato_t dt); 
void imprimir (nodo_t *i);
