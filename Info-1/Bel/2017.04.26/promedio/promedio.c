#include <stdio.h>
#define CANTIDAD 10
int main(){
	int i;
	int num;
	float promedio;
	int total=0;
	for (i = 0; i < CANTIDAD; i++){
		scanf("%d", &num);
		total+=num;
	}
	promedio=(float)total/CANTIDAD;
	printf("%f\n",promedio );
	return 0;
}