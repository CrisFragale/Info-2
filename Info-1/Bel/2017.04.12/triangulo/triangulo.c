/*
programa que ingrese los lados de un triángulo y que determine si es isoceles, escaleno ó equilátero.
*/

#include <stdio.h>

int main(){
	int a;
	int b;
	int c;
	printf("ingrese un lado, presione enter. repita. dos veces mas\n");
	scanf("%d %d %d", &a, &b, &c);
	if (a!=0 && b!=0 && c!=0){
		if(a+b>=c && b+c>=a && c+a>=b){
			if(a==b && b==c){
				printf("es equilátero.\n");
			}
			else if ((a==b && b!=c) || (a==c && c!=b) || (b==c && b!=a)){
				printf("es isoceles.\n");
			}
			else{
				printf("es escaleno\n");
			}
		}
	}
	return 0;
}