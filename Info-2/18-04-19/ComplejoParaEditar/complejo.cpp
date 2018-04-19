#include "complejo.h"
#include <iostream>

using namespace std;

//Metodos de la clase Complejo

//Constructor parametrizado, los valores por default estan en la definicion de la clase
Complejo::Complejo(double r, double i)
{

        real=r;
        imag=i;

}

//Constructor de copia
Complejo::Complejo(const Complejo &c)
{
        real=c.real;
        imag=c.imag;
}

//Metodo para setear la parte real
void Complejo::setReal(double r)
{
   real=r;
}

//Metodo para leer la parte real
double Complejo::getReal()
{
   return real;
}

//Metodo para setear la parte imaginaria
void Complejo::setImag(double i)
{
    imag=i;
}

//Metodo para leer la parte imaginaria
double Complejo::getImag()
{
    return imag;
}

//Método para mostrar un complejo con formato REAL +/-j IMAG
void Complejo::mostrar()
{
    cout<<real<< endl<<"j"<<imag<< endl; //printf("%d j %d",real,imag);
}

//Método que devuelve el módulo del complejo
double Complejo::modulo()
{
    return sqrt((real*real)+(imag*imag));
}

//Método que devuelve la fase del complejo
double Complejo::fase()
{
    return atan(imag/real);
}
