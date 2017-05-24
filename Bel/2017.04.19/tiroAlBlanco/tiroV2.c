#include <stdio.h>
#include <math.h>
#define RADIO_ADENTRO 1
#define RADIO_MEDIO 5
#define RADIO_AFUERA 10
#define PUNTAJE_ADENTRO 10
#define PUNTAJE_MEDIO 5
#define PUNTAJE_AFUERA 1
int main(){
	float x;
	float y;
	float radio;
	int puntaje=0;
	int n;
	int puntajeFin =0;
	for(n=0; n<5; n++){
		puntaje = 0;
		printf("ingrese un valor para la coordenada x\n");
		scanf("%f", &x);
		printf("ingrese un valor para la coordenada y\n");
		scanf("%f", &y);
		radio = sqrt( pow(x, 2) + pow(y, 2));
		if (radio <= RADIO_ADENTRO){
			puntaje = PUNTAJE_ADENTRO;
		}
		else if(radio <= RADIO_MEDIO){
			puntaje = PUNTAJE_MEDIO;
		}
		else if(radio <= RADIO_AFUERA){
			puntaje = PUNTAJE_AFUERA;
		}
		else{
			puntaje = 0;
		}
		puntajeFin += puntaje;
		printf("su puntaje en esta partida es: %d\n", puntaje);
	}
	printf("su puntaje total es: %d\n", puntajeFin);
	return 0;
}