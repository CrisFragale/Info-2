#include <stdio.h>
void my_swap(int* p, int* q){
	int aux;
	aux=*p;
	*p=*q;
	*q=aux;
}