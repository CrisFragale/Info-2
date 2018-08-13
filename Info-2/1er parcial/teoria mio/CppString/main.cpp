#include "class_string.h"

using namespace std;

int main()
{
    String a("1234"), b, c(a), d;
    b = "5678";
    d = "abcd" + c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "b + d = " << b + d << endl;

    cout << endl;
    cout << "Presione enter para continuar" << endl;
    cin.get();  //equivalente a getchar
}
