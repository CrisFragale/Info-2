#include "cristian.h"

double factorial (int a)
{
    double result;
    int i;
    if(a==0)return (1);
    result=a;
    for(i=(a-1);i>0;i--)
    {
        result=result*i;
    }
    return (result);
}
