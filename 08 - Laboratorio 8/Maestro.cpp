#include "Maestro.h"
#include "Persona.h"
#include <iostream>
#include<string>
using namespace std;

Maestro::Maestro() {

}
Maestro::Maestro(string nombre, string apellido, int edad, string identificador) : Persona(nombre, apellido, edad) {
    this->identificador = identificador;
}
Maestro::~Maestro(){

}

string Maestro::getidentificador() const {
    return identificador;
}

void Maestro::setidentificador(string identificador){
    this->identificador = identificador;
}

void Maestro::imprimir() const {
    cout << " --- Maestro --- " << endl;
    cout << getnombre() << " " << getapellido() << " " << getedad();
    cout << " | No de Identidad: " << identificador << endl;
}