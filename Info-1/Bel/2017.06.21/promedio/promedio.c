#include <stdio.h>
#include <stdlib.h>
int main(int argc, char  **argv){
	int aux, contador=0, i;
	float numero=0;
	for (i = 0; i < argc; i++){
	 	aux=atoi(argv[i]);
	 	numero+=(float)aux;
	 	contador++;
	}
	numero/=(contador-1);
	printf("%.2f\n", numero ); 
	return 0;
}