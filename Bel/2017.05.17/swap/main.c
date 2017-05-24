#include <stdio.h>
void my_swap (int *, int *);
int main(){
	int a;
	int b;
	//int *p;
	//int *q;
	printf("ingrese dos numeros separados por coma\n");
	scanf("%d,%d", &a, &b);
	//*p=a;
	//*q=b;
	printf("los valores de a y b son: %d y %d respectivamente.\n", a, b);
	my_swap(&a, &b);
	printf("los valores actuales de a y b son: %d y %d respectivamente.\n", a, b);
}