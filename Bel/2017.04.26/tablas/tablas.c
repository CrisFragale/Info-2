#include <stdio.h>
#define TABLA 11
int main (){
	int num;
	int i;
	int result;
	scanf("%d", &num);
	for (i = 1; i < TABLA; i++){
		result = num*i;
		printf("%d*%d = %d \n", num, i, result);
	}
	return 0;
}