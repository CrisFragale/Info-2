#include "cristian.h"

double potencia (int x, int y)
{
    double result;
    int i;
    result=x;
    if(y==0)return (1);
    for (i=0;i<(y-1);i++)
    {
        result=result*x;
    }
    return (result);
}
