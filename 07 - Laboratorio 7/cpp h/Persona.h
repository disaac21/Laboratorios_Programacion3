#pragma once
#include <iostream>
#include<string>
#include "Estudiante.h"
#include "Maestro.h"
#include "Producto.h"
using namespace std;

class Persona {
    string nombre;
    string apellido;
    int edad;

    public:
        Persona();
        Persona(string nombre, string apellido, int edad);
        ~Persona();

        string getnombre() const;
        string getapellido() const;
        int getedad() const;

        void setnombre(string);
        void setapellido(string);
        void setedad(int);

};