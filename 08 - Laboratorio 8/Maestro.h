#pragma once
#include <iostream>
#include<string>
#include "Estudiante.h"
using namespace std;

class Maestro : public Persona {
    string identificador;

    public:
        Maestro();
        Maestro(string nombre, string apellido, int edad, string identificador);
        ~Maestro();

        string getidentificador() const;

        void setidentificador(string);
        virtual void imprimir()const override;
};