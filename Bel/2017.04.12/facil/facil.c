#include <stdio.h>
int main(){
	int num = -1;
	int res;
	printf("ingrese un número positivo.\n");
	scanf("%d \n", &num );
	res = num%2;
	if(res==0){
		printf("es par\n");
	}
	else{
		printf("es impar\n");
	}
	return 0;
}