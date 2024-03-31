#include "Estudiante.h"
#include <iostream>
#include<string>
using namespace std;

Estudiante::Estudiante() {

}
Estudiante::Estudiante(string identificador) {
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
