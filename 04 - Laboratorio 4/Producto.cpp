#include "Producto.h"
#include <iostream>

using namespace std;

Producto::Producto() {

}

Producto::Producto(string Nombre, double Precio) {
	p_nombre = Nombre;
	p_precio = Precio;
}

Producto::~Producto() {

}

int Producto::getID() const {
	return p_ID;
}

void Producto::setID(int ID) {
	p_ID = ID;
}

string Producto::getNombre() const {
	return p_nombre;
}

void Producto::setNombre(string Nombre) {
	p_nombre = Nombre;
}

double Producto::getPrecio() const {
	return p_precio;
}

void Producto::setPrecio(double Precio) {
	p_precio = Precio;
}