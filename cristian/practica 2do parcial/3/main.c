#include "cristian.h"

int main (int argc, char* argv[])
{
	int i,minin,minfin,y=1;
	nodo_t *prt_h=NULL;
	if(argc!=2) exit(1);
	i = lecturaArchivo (&prt_h,argv[1]);
	imprimir(prt_h);
	while(y)
	{
	printf("ingrese losminutos de intervalos\n");
	scanf("%d",&minin);
	scanf("%d",&minfin);
	i=velocidadMedia(prt_h,minin,minfin);
	printf("%d",i);
	printf("ingrese 0 para salir 1 para continuar\n");
	scanf("%d",&y);
 	}

	return 0;
}
