#include "orden.h"
int main(){
	int v[LARGO]={99, 2, 65, 33, 0};
	int i;
	myBurbujeo(v, LARGO);
	for (i = LARGO-1; i >= 0; i--)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}