#include "Negocio.h"
#include <iostream>

using namespace std;

Negocio::Negocio() {

}

Negocio::Negocio(string Nombre) {
	n_nombre = Nombre;
}

Negocio::~Negocio() {

}

int Negocio::getID() const {
	return n_ID;
}

void Negocio::setID(int ID) {
	n_ID = ID;
}

string Negocio::getNombre() const {
	return n_nombre;
}

void Negocio::setNombre(string Nombre) {
	n_nombre = Nombre;
}