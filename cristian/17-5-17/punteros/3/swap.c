#include"swap.h"

int main (void)
{
    int a,b;
    printf("ingrese a y luego b luego se intercambiaran\n");
    scanf("%d,%d",&a,&b);
    printf("los valores son: %d y %d\n",a,b);
    swap(&a,&b);
    printf("los valores nuevos son: %d y %d\n",a,b);
    return(0);
}
