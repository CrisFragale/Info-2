#define CANT_NUM 10
int main(){
	int numeros[CANT_NUM];
	cargaVector(numeros, CANT_NUM);
	return 0;
}





void cargaVector(int *v, int tam){
	int i;
	for(i=0; i<tam; i++){
		scanf(“%d”, &*(v+i));
	}
}