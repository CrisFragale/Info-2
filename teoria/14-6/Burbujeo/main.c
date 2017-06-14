#include"cristian.h"

int main (void)
{   int cambio;
	int V[LARGO]={3333,4444,1111,-1,-675};
    my_burbujeo(V,LARGO);
    for (cambio=0;cambio<(LARGO);cambio++)
    {
    	printf("%d \n",V[cambio]);
    }
    return(0);
}
