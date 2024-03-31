#include "Maestro.h"
#include <iostream>
#include<string>
using namespace std;

Maestro::Maestro() {

}
Maestro::Maestro(string identificador) {
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
