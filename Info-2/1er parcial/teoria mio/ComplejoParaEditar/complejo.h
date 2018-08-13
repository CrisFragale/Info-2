#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <cmath>

using namespace std;

class Complejo
{
    double real, imag;

public:
    //Constructores
    Complejo(double r = 0, double i = 0);
    Complejo(const Complejo &c);

    //Metodo de acceso
    void setReal(double r);
    double getReal();
    void setImag(double i);
    double getImag();

   //Metodos
    void mostrar();
    double modulo();
    double fase();
};

#endif // COMPLEJO_H
