#include "Producto.h"
#include <iostream>
using namespace std;

Producto::Producto() {

}

Producto::Producto(double Precio, string Nombre) {
    PrecioProducto = Precio;
    NombreProducto = Nombre;
}

Producto::~Producto() {

}

double Producto::getPrecio() const {
    return PrecioProducto;
}

void Producto::setPrecio(double Precio) {
    PrecioProducto = Precio;
}

string Producto::getNombre() const {
    return NombreProducto;
}

void Producto::setNombre(string Nombre) {
    NombreProducto = Nombre;
}

const string Producto::ProductoType() {
    return "Producto";
}

