#include "cristian2.h"

int promediar (FILE *fd1, FILE *fd2) 
{
	char *aux1=NULL , *aux2=NULL;
	int i=0,X=0,Y=0,k=0;
	float promx=0,promy=0;
	char cadena1[40],cadena2[40];
	char x1[5], x2[5];
	char y1[5], y2[5];


	while(!feof(fd1))
	{
		fgets(cadena1,sizeof(cadena1),fd1);
		fgets(cadena2,sizeof(cadena2),fd2);
		for(aux1=cadena1;(*aux1)!=',';aux1++);
		for(aux2=cadena2;(*aux2)!=',';aux2++);
		for(i=0, aux1++;((*aux1)!=',' && (*aux1)!='\0')	|| i==0;aux1++,i++)
		{
			x1[i]=*aux1;
		}
		x1[i+1]='\0';
		for(i=0, aux2++;((*aux2)!=',' && (*aux2)!='\0')	|| i==0;aux2++,i++)
		{
			x2[i]=*aux2;
		}
		x2[i+1]='\0';
		for(i=0,aux1++;((*aux1)!=',' && (*aux1)!='\0')	|| i==0;aux1++,i++)
		{
			y1[i]=*aux1;
		}
		y1[i+1]='\0';
		for(i=0, aux2++;((*aux2)!=',' && (*aux2)!='\0')	|| i==0;aux2++,i++)
		{
			y2[i]=*aux2;
		}
		y2[i+1]='\0';

	
		X=(atoi(x2)-atoi(x1));
	
		Y=(atoi(y2)-atoi(y1));
	
		k++;
		promx=promx+X;
		promy=promy+Y;
		
	}
	

	promx=promx/k;
	promy=promy/k;
	printf("El error cometido en X fue de %f \n",promx);
	printf("El error cometido en y fue de %f \n",promy);
	fclose(fd1);
	fclose(fd2);
	return 0;

}
