#include "str.h"
int main(){
	char v[LARGO];
	char aux[100];
	int a=1;
	int tamfrase;
	while(strcmp(aux, "fin")){
		scanf("%s", aux);
		tamfrase=strlen(v);
		if (LARGO-tamfrase>(strlen(aux)+1)){
			a=strcmp(aux, "fin");
			if(a!=0){
				strcat(v, aux);
				strcat(v, " ");
			}
		}
		else{
			strcat(aux, "fin");
		}
	}
	printf("%s\n", v);
	return 0;
}