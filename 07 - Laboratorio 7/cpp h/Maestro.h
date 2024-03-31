#pragma once
#include <iostream>
#include<string>
#include "PersonaLab.h"
#include "Estudiante.h"
#include "Producto.h"
using namespace std;

class Maestro {
    string identificador;

    public:
        Maestro();
        Maestro(string identificador);
        ~Maestro();

        string getidentificador() const;

        void setidentificador(string);

};