#include"punteros.h" 

int main (void)
{
    char * p;
    int a,i;
    p=(char*)&a;
    printf("ingrese a en hexa");
    scanf("%x",&a);
    for(i=0;i<4;i++)
    {
        printf("byte numero: %d, contenido:  %hhx\n",(i+1),*(p));
        p++;
    }
    return(0);
}