#include <stdio.h>
float suma (float, float);
float resta (float, float);
float multiplicacion (float, float);
float division (float, float);

int main(){
	float a, b, resultado;
	int c;
	float (*pointer)(float, float);
	printf("elija un numero del 1 al 4. siendo: \n 1 suma\n 2 resta\n 3 multiplicacion\n 4 division\n");
	scanf("%d", &c);
	printf("ingrese dos numeros separados por un espacio\n");
	scanf("%f %f", &a, &b);
	switch(c){
		case 1:
			pointer=suma;
		break;
		case 2:
			pointer=resta;
		break;
		case 3:
			pointer=multiplicacion;
		break;
		case 4:
			pointer=division;
			if (b==0){
				printf("no se puede dividir por cero.\n");
				return 0;
			}
		break;
		default:
			printf("la opción que eligió está fuera de rango");
	}
	resultado = pointer(a, b);
	printf("el resultado es: %.2f\n", resultado);
	return 0;
}
