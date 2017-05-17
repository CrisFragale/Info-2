#include"cristian.h"


int main (void)
{ 
    int x1,x2,y2,y1;
    float result;
    printf("ingrese los puntos x2 x1 y2 y1 respectivamente\n");
    scanf("%d %d %d %d",&x2,&x1,&y2,&y1);
    result= distancia (x2,x1,y2,y1);
    printf("la distancia dio %f",result);
    return (0);
}