#include"cristian.h"

int main (void)
{
    float (*puntero) (float,float)=NULL;
    float a,b,result;
    int c;
    printf("ingrese \n1 para sumar \n2 para restar\n3 para multiplicar\n4 para dividir \n ");
    while (*puntero==NULL)
    {
      scanf("%d",&c);
      switch(c)
       {
        case 1:
            puntero=suma;
            break;
        case 2:
            puntero=resta;
            break;
        case 3:
            puntero=multiplicacion;
            break;
        case 4:
            puntero=division;
            break;
        default:
            printf("opcion erronea\n");
            

       }
    }
    printf ("ingrese los dos valores \n");
    scanf("%f",&a);
    scanf("%f",&b);
    if(c==4)
    {
        if(b==0)
        {
            printf("no es posible\n");
            return(0);
        }
    }
    result=puntero(a,b);
    printf("el resultado fue %.2f\n",result);
    return 0;
}

    
    
    
    
    