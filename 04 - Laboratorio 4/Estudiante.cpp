#include <iostream>
#include "Estudiante.h"
using namespace std;

Estudiante::Estudiante() {

}

Estudiante::Estudiante(string Nombre, string Apellido) {
	e_nombre = Nombre;
	e_apellido = Apellido;
}

Estudiante::~Estudiante() {

}

int Estudiante::getID() const {
	return e_ID;
}

void Estudiante::setID(int ID) {
	e_ID = ID;
}

string Estudiante::getNombre() const {
	return e_nombre;
}

void Estudiante::setNombre(string Nombre) {
	e_nombre = Nombre;
}

string Estudiante::getApellido() const {
	return e_apellido;
}

void Estudiante::setApellido(string Apellido) {
	e_apellido = Apellido;
}
