#pragma once
#include <iostream>
#include<string>
using namespace std;

class StringObj {
    string cadena;

    public:
        StringObj();
        StringObj(string cadena);
        ~StringObj();

        string getcadena() const;

        void setcadena(string);

};