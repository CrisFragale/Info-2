#ifndef CLASS_STRING_H
#define CLASS_STRING_H

#include <iostream>
#include <cstring>

using namespace std;

class String
{
    char *p;
    int len;
public:
    String();
    String(const char *);
    String(const String&);
    ~String();

    String operator+(const String &s);
    String operator+(const char *s);
    String& operator=(const String &s);
    String& operator=(const char *s);

    friend String operator+(const char *s1, const String &s2);
    friend ostream& operator<< (ostream& , const String& );
};

String operator+(const char *s1, const String &s2);
ostream& operator<< (ostream &o, const String &s);

#endif // CLASS_STRING_H
