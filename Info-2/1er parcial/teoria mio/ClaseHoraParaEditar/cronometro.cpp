#include "cronometro.h"


using namespace std;

cronometro::cronometro(int h,int m ,int s, int _ms):Hora( h, m , s) //
{

    ms=_ms;

}

cronometro::cronometro(const &C):Hora(&H)
{
    ms=C.ms;
}

cronometro::operator +=(int _ms)
{
    int aux;
    ms=ms+_ms;
    if(ms>1000)
    {
        aux=ms/1000;
        ms=ms%1000;
    }
    Hora::operator+=(aux);
}


