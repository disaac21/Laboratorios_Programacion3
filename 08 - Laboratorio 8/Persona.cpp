#include "Persona.h"
#include <iostream>
#include<string>
using namespace std;

Persona::Persona() {

}
Persona::Persona(string nombre, string apellido, int edad) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
}
Persona::~Persona(){

}

string Persona::getnombre() const {
    return nombre;
}
string Persona::getapellido() const {
    return apellido;
}
int Persona::getedad() const {
    return edad;
}

void Persona::setnombre(string nombre){
    this->nombre = nombre;
}
void Persona::setapellido(string apellido){
    this->apellido = apellido;
}
void Persona::setedad(int edad){
    this->edad = edad;
}

void Persona::imprimir() const {
    cout << nombre << " " << apellido << " " << edad;
}
