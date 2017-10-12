#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct paciente {
	char nomApe[40];
	long dni;
	float horaTurno;
}paciente_t;


typedef struct nodo{

	paciente_t paciente;
	struct nodo* next;
	}nodo_t;


int lecturaPacientes (nodo_t **dir_h , char *archivo );

int insetarorden (nodo_t **h, paciente_t dato);

void imprimir (nodo_t *i);