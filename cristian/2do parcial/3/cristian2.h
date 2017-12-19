#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct tema {
	int  codigo;
	char Nombre[20];
	char Autor[20];
}tema_t;

typedef struct dato {
	tema_t infoTema;
	int cantidad;
}dato_t;


typedef struct nodo{

	dato_t datos;
	struct nodo* next;
	}nodo_t; 

int lecturaTemas (nodo_t **ptr_h, char *archivo);
void imprimir (nodo_t *i);
int corroborar(nodo_t ** inicio, dato_t d );
nodo_t* busqueda (nodo_t *i, dato_t d);
int insertarini (nodo_t ** inicio, dato_t d );
int almacenar(nodo_t *ptr_h, char *archivoSalida);
int fun3(nodo_t* ptr_h);

