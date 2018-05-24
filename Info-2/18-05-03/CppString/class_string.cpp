#include "class_string.h"

String::String()   //constructor x default
{
    len = 0;
    p = NULL;
}
//------------------------------------------------------------------------------
String::String(const char *s) //constructor parametrizado.
{
    len = strlen(s);
    p = new char[len+1];
    strcpy(p, s);
}
//------------------------------------------------------------------------------
String::String(const String &s) //constructor de copia
{
    len = s.len;
    p = new char[len+1];
    strcpy (p, s.p);
}
//------------------------------------------------------------------------------
String::~String()
{
    delete[] p;
}
//------------------------------------------------------------------------------
// operador de suma: concatena strings
String String::operator+(const String &s)
{
    String ret;
    ret.len = len + s.len;
    ret.p = new char[ret.len + 1];
    strcpy(ret.p, p);
    strcat(ret.p, s.p);
    return ret;

}
//------------------------------------------------------------------------------
// operador de asignación: asigna objetos iguales
String& String::operator=(const String& s)
{
    delete[] p;           //libero y pido memoria de nuevo
    len = s.len;
    p = new char[len+1];

    strcpy(p, s.p);
    return *this;  //devuelvo el propio objeto para permitir asignaciones múltiples
}
//------------------------------------------------------------------------------
// operador de asignación: Un objeto igual a una cadena
String& String::operator= (const char *s)
{
    delete[] p;             //libero y pido memoria de nuevo
    len = strlen(s);
    p = new char[len+1];

    strcpy(p, s);
    return *this;    //devuelvo el propio objeto para permitir asignaciones múltiples
}

//sobrecarga global de + para concatenar char * y String
String operator+(const char *s1, const String &s2)
{
    String ret(s1);
    return ret + s2;
}

//------------------------------------------------------------------------------
//sobrecarga global de << para el uso de cout
ostream& operator<< (ostream& o, const String& s)
{
    o << s.p;
    return o;
}
