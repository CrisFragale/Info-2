#include<stdio.h>
#include<math.h>
#define RADIO1 1 
#define RADIO2 5
#define RADIO3 10
#define PUNTAJE1 10
#define PUNTAJE2 5
#define PUNTAJE3 1

int main ()
{   
    float radio=0,x=0,y=0;
    int puntaje=0, tiros=1;
    printf("ingrese las coordenadas X e Y respiectivamente \n");
    printf("ested vas a tener 3 tiros para ejecutar\n");
    while(tiros!=4)
    {
        printf("tiro %d\n",tiros);      
        scanf("%f",&x);
        scanf("%f",&y);
        radio=sqrt(((x*x)+(y*y)));
        if(radio<=RADIO3)
    {
            if(radio<=RADIO2)
        {
                if(radio<=RADIO1)
            {
                    puntaje=puntaje+PUNTAJE1;
            }else{
                    puntaje=puntaje+PUNTAJE2;
            }
        }else{
                puntaje=puntaje+PUNTAJE3;
        } 
    }else{
        puntaje=puntaje+0;
    }               
    tiros++;
    }
    printf("su puntuacion es de: %d\n",puntaje);
    return 0;
}