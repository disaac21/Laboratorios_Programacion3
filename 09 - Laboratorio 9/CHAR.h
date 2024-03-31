#pragma once
#include <iostream>
#include<string>
#include "INTEGER.h"
#include "STRING.h"
using namespace std;

class STRING;
class INTEGER;

class CHAR {
    char caracter;

    public:
        CHAR();
        CHAR(char caracter);
        ~CHAR();

        char getcaracter() const;

        void setcaracter(char);

// -------------------------------------------

        void operator << (const char&);
        void operator << (const CHAR&);

        void operator!();

        STRING operator + (const char&);
        STRING operator + (const CHAR&);

        STRING operator * (int);
        STRING operator * (INTEGER);

};