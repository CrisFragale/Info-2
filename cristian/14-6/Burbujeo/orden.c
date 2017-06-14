#include"cristian.h"

void my_burbujeo (int* V, int TAM)
{
    char flag=0;
    int aux,cambio,vueltas;
    for (vueltas=0;vueltas<(TAM-1) && flag==0;vueltas++)
    {    
    	flag=1;
    	for (cambio=0;cambio<(TAM-1-vueltas);cambio++)
     	 {
    		if(V[cambio]>V[cambio+1])
    		{
    			aux=V[cambio];
    			V[cambio]=V[cambio+1];
    			V[cambio+1]=aux;
    			flag=0;
    		}
   		 }
    }
    return;

}
