#include <stdio.h>
int potencia(int x, int y){
	int i;
	int res=1;
	if(y==0){
		res=1;
	}
	else{
		for(i=0; i<y; i++){
			res=res*x;
		}
	}
	return res;
}