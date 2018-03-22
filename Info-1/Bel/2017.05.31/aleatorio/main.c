#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int a=0, b=0, c=0;
	srand(time(0));
	a= rand() % 6 + 1;
	b= rand() % 6 + 1;
	c= rand() % 6 + 1;
	printf("%d, %d, %d\n", a, b, c);
	return 0;
}