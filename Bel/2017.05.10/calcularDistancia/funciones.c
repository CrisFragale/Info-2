#include "distancia.h"
float distancia(int x1, int y1, int x2, int y2){
	float res;
	res=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return res;
}
