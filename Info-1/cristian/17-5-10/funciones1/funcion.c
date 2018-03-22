#include "cristian.h"
float distancia (int x1, int x2, int y1, int y2) 
{
    float result;
    result=sqrt(((x2-x1)*(x2-x1)+((y2-y1)*(y2-y1))));
    return (result);
}