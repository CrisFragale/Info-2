#include <stdio.h>
int main(){
	int num1;
	int num2;
	int i;
	scanf("%d", &num1);
	num2=num1;
	for(i=0; num1!=0; i++){
		scanf("%d", &num1);
		if (num1>num2)
		{
			num2=num1;
		}
		else if(num1==0){
			num2++;
			printf("es creciente\n");
		}
		else{
			printf("no es creciente\n");
		}
	}
	return 0;
}