#pragma once
#include <iostream>
#include<string>
#include "CHAR.h"
#include "STRING.h"
using namespace std;

class INTEGER {
    int entero;

    public:
        INTEGER();
        INTEGER(int entero);
        ~INTEGER();

        int getentero() const;

        void setentero(int);

// ----------------------------------------------

        void operator << (const int&);
        void operator << (const INTEGER&);

        void operator!();

        INTEGER operator+(const int&);
        INTEGER operator+(const INTEGER&);

        INTEGER operator-(const int&);
        INTEGER operator-(const INTEGER&);

        INTEGER operator*(const int&);
        INTEGER operator*(const INTEGER&);

        INTEGER operator/(const int&);
        INTEGER operator/(const INTEGER&);

        INTEGER operator%(const int&);
        INTEGER operator%(const INTEGER&);

        INTEGER operator^(const int&);
        INTEGER operator^(const INTEGER&);

        INTEGER& operator++();
        // INTEGER operator++();

        INTEGER& operator--();
        // INTEGER operator--();
};