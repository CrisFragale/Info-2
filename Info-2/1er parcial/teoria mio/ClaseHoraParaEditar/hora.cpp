#include "hora.h"


using namespace std;

//Implementar los métodos de Clase Hora
Hora::Hora(int h,int m, int s)
{
    h=h;
    m=m;
    s=s;
}

Hora::Hora(const Hora &H)
{
    h=H.h;
    m=H.m;
    s=H.s;
}

Hora::operator +=(int d)
{
    s=s+d;
    if(s>=60)
    {
        m++;
        s=0;
    }
    if(m>=60)
    {
        h++;
        m=0;
    }

}

ostream& operator << (ostream& o,const Hora& H)
{
    o<< H.h <<":"<< H.m <<":"<< H.s;
    return o;
}

