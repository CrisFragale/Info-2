#ifndef HORA_H
#define HORA_H

#include <iostream>

using namespace std;

class Hora
{
private:
    int h, m, s;

public:
    Hora(int hora = 0,int min = 0,int seg = 0);
    Hora(const Hora &H);
    void Mostrar(); //Muestra Hora en formato hh:mm:ss
    void incHora(); //Incrementa la hora en un segundo
    void decHora(); //Decrementa la hora en un segundo
    void setHora(int hora, int min, int seg);
    int getHora();
    int getMin();
    int getSeg();
};

#endif // HORA_H
