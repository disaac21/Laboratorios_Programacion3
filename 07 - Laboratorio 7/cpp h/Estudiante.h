#pragma once
#include <iostream>
#include<string>
#include "PersonaLab.h"
#include "Maestro.h"
#include "Producto.h"
using namespace std;

class Estudiante {
    string identificador;

    public:
        Estudiante();
        Estudiante(string identificador);
        ~Estudiante();

        string getidentificador() const;

        void setidentificador(string);

};