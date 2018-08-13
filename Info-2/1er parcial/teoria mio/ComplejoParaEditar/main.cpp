#include <iostream>
#include "complejo.h"

using namespace std;

int main()
{
    Complejo A(5,1);
    Complejo B;
    Complejo N(A);
    double modulo;


    A.mostrar();
    B.mostrar();
    N.mostrar();



    A.setReal(8);
    B.setImag(9);


    A.mostrar();
    B.mostrar();
    N.mostrar();

    modulo=N.modulo();
    cout<<modulo;
    A.modulo();
    B.modulo();

    A.fase();
    B.fase();
    N.fase();
    cout << endl;
    cout << "Presione enter para continuar" << endl;
    cin.get();  //equivalente a getchar

    return 0;
}
