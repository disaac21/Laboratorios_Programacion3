#pragma once
#include <iostream>
#include<string>
#include "Node.h"
using namespace std;

class Operator {
    char operacion;

    public:
        Operator();
        Operator(char operacion);
        ~Operator();

        char getoperacion() const;

        void setoperacion(char);

};