#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct coord{
	int x;
	int y;
}coord_t;

void llenoVector (coord_t*, int);
float sumatoria (coord_t*, int);