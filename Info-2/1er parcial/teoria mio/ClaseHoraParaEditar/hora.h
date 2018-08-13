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
    Hora&operator+=(int d); //incrementa las variebales
    friend ostream& operator << (ostream& o,const Hora&H);
};

#endif // HORA_H
