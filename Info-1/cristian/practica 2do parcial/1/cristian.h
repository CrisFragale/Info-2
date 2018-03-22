#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct dist {
	int minutos;
	int kilometro;
}distancia_t; 

typedef struct nodo{
	distancia_t D;
	struct nodo* next; 
}nodo_t; 



int lecturaArchivo (nodo_t **prt_h, char *archivos);
int insertarfin (nodo_t ** inicio, distancia_t d);
void imprimir (nodo_t *i);