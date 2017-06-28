#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main( int argc, char *argv[])
{
	int 	current_opt;
	
	int 	flag1;
	int 	imprime;
	int 	variable1;
	float 	variable2;
	char  	string[25];

	//~ Primero cargamos la configuracion por defecto que queremos 
	//~ que tenga el programa en las variables necesarias
	
	flag1 = 0;
	imprime = 1;
	variable1 = 42;
	variable2 = 19.5;
	
	strcpy(string,"String por defecto\n");
	
	//~ Despues analizamos todos los argumentos que llegaron por
	//~ linea de comando, uno por uno.
	
	//~  buscando aquellos que nos interesen:
	//~  -f -i -v X  -V X.X -s xxxx
	
	
	
	while ( (current_opt = getopt(argc, argv, "hfiv:V:s:")) != -1) 
	{
		//~ getopt devuelve el argumento encontrado, la primer coincidencia de
		//~ una de las letras que le pasamos en el string "hfiv:V:s:"
		//~ 
		//~ También deja asignada la variable char *optarg apuntando al siguiente argumento
		
		switch (current_opt) 
		{
			case 'i':
				imprime=0;
				break;
				
			case 'f':
				flag1=1;
				break;
			
			case 'v':
				variable1=atoi(optarg);
				break;
			
			case 'V':
				variable2=atof(optarg);
				break;
			
			case 's':
				strcpy(string,optarg);
				break;
			
			case 'h':  
			default: /* '?' */
				printf("Uso del programa: %s \n", argv[0]);
				printf("	-h 	imprime esta ayuda \n\n");
				printf("	-f  pone en 1 el flag1\n");
				printf("	-i  cambia el mensaje de salida\n");
				printf("	-v XX      asinga el valor XX a la variable1 tipo int\n");
				printf("	-V X.X     asigna el valor ZZ.ZZ a la variable2 tipo float \n");
				printf("	-s CADENA  asigna la cadena (sin espacios) al string\n");
				exit(0);
		}
	}

//~ Termino la configuracion del programa, ahora empieza la ejecucion

	if( imprime == 1 )
	{
		printf("\n Los argumentos recibidos por consola fueron: \n");
		printf("\t variable1 = %d \n",variable1);
		printf("\t variable2 = %f \n",variable2);
		printf("\t string = %s \n",string);
		if (flag1 == 1)
			printf("\t flag1 habilitado \n");
		if (flag1 == 0)
			printf("\t flag1 deshabilitado \n");
	}
	else 
		printf(" %d %f %s flag1=%d \n", variable1,variable2, string, flag1);
	
	
	return 0;
}
 
