#pragma once
#include <iostream>
#include<string>
#include "PersonaLab.h"
#include "Estudiante.h"
#include "Maestro.h"
using namespace std;

class Producto {
    string nombre;
    double precio;

    public:
        Producto();
        Producto(string nombre, double precio);
        ~Producto();

        string getnombre() const;
        double getprecio() const;

        void setnombre(string);
        void setprecio(double);

};