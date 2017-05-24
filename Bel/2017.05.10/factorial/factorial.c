int factorial (int a){
	int resultado=1;
	int i;
	if (a==0){
		resultado=1;
	}
	else{
		for (i=a; i > 0; i--){
			resultado=resultado*i;
		}
	}
	return resultado;
}