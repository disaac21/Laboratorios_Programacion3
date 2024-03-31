#include "CHAR.h"
#include <iostream>
#include<string>
using namespace std;



CHAR::CHAR() {

}
CHAR::CHAR(char caracter) {
    this->caracter = caracter;
}
CHAR::~CHAR(){

}

char CHAR::getcaracter() const {
    return caracter;
}

void CHAR::setcaracter(char caracter){
    this->caracter = caracter;
}

// --------------------------------------------

void CHAR::operator << (const char&charparam) {
    this->caracter = charparam;
}

void CHAR::operator << (const CHAR&charparam) {
    this->caracter = charparam.getcaracter();
}

void CHAR::operator!(){
    cout << this->getcaracter() << endl;
}

STRING CHAR::operator + (const char& charparam){
    string diferente = "";
    diferente.push_back(this->getcaracter());
    diferente.push_back(charparam);
    return ((STRING)diferente);
}

STRING CHAR::operator + (const CHAR& charparam){
    string diferente = "";
    diferente.push_back(this->getcaracter());
    diferente.push_back(charparam.getcaracter());
    return ((STRING)diferente);
}

STRING CHAR::operator* (int charparam){
    string enviar = "";
    for (int i = 0; i < charparam; i++) {
        enviar.push_back(this->getcaracter());
    }
    
    return (STRING(enviar));
}

STRING CHAR::operator * (INTEGER charparam){
    string enviar = "";
    for (int i = 0; i < charparam.getentero(); i++) {
        enviar.push_back(this->getcaracter());
    }
    return (STRING(enviar));
}