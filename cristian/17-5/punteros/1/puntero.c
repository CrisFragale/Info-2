#include"punteros.h"

int main (void)
{
    int a=0;
    char b=0;
    int *p=NULL;
    char *q=NULL;
    p=&a;
    q=&b;
    printf("la direccionde a es %p\n",p);
    printf("la direccionde b es %p\n",q);
    printf("el tamaño de p es %ld\n",(sizeof(p)));
    printf("el tamaño de q es %ld\n",(sizeof(q)));
    
    return(0);
}