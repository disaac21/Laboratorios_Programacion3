#include "Estudiante.h"
#include "Persona.h"
#include <iostream>
#include<string>
using namespace std;

Estudiante::Estudiante() {

}
Estudiante::Estudiante(string nombre, string apellido, int edad, string identificador) : Persona(nombre, apellido, edad) {
    this->identificador = identificador;
}
Estudiante::~Estudiante(){

}

string Estudiante::getidentificador() const {
    return identificador;
}

void Estudiante::setidentificador(string identificador){
    this->identificador = identificador;
}

void Estudiante::imprimir() const {
    cout << " --- Estudiante --- " << endl;
    Persona::imprimir();
    cout << " | No de Cuenta: " << identificador << endl;
}