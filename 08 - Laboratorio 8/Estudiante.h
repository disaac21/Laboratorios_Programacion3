#pragma once
#include <iostream>
#include<string>
#include "Persona.h"
using namespace std;

class Estudiante : public Persona {
    string identificador;

    public:
        Estudiante();
        Estudiante(string nombre, string apellido, int edad, string identificador);
        ~Estudiante();

        string getidentificador() const;

        void setidentificador(string);

        virtual void imprimir() const override;
};