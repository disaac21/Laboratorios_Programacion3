#pragma once
#include <iostream>
#include<string>
#include "Object.h"
using namespace std;

class StringObj : public Object {

    string cadena;

public:
    StringObj();
    StringObj(string cadena);
    ~StringObj();

    string getcadena() const;

    void setcadena(string);

};