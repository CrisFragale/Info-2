#include "parcial.h"
int strInvertir( char * str ){
	char aux [TAM];
	int i;
	int j;
	int count=0;
	if (str==NULL){
		return -1;
	}
	else{
		for (i = 0, j=strlen(str)-1; i < TAM; i++, j--){
			aux[i]=str[j];
			if(aux[i]==str[j]){
				count++;
			}
		}
		for (i = 0; i < TAM; i++){
				str[i]=aux[i];
		}
		if (count == TAM){
			return 1;
		}
		else{
			return 0;
		}
	}
}