#pragma once
#include <iostream>
#include<string>
#include "INTEGER.h"
#include "STRING.h"
#include "CHAR.h"
using namespace std;

class CHAR;
class INTEGER;

class STRING {
    string cadena;

    public:
        STRING();
        STRING(string cadena);
        ~STRING();

        string getcadena() const;

        void setcadena(string);

        // -------------------------------------------

        void operator << (const string&);
        void operator << (const STRING&);
        void operator << (const char&);
        void operator << (const CHAR&);

        void operator!();

        STRING operator+(const string&);
        STRING operator+(const STRING&);
        STRING operator+(const char&);
        STRING operator+(const CHAR&);

        STRING operator*(int);
        STRING operator*(INTEGER);

        CHAR operator[](int);
        CHAR operator[](INTEGER);

        STRING operator()(int);
        STRING operator()(INTEGER);
        STRING operator()(int, int);
        STRING operator()(INTEGER, INTEGER);
        STRING operator()(int, INTEGER);
        STRING operator()(INTEGER, int);

        bool operator==(string);
        bool operator==(char);
        bool operator==(STRING);
        bool operator==(CHAR);

        bool operator |(string);
        bool operator |(STRING);
        bool operator |(char);
        bool operator |(CHAR);

};