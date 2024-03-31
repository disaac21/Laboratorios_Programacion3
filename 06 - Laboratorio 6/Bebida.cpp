#include "Bebida.h"
#include "Producto.h"
#include <iostream>
using namespace std;

Bebida::Bebida() {

}

Bebida::Bebida(double Precio, string Nombre, int Cantidad) : Producto(Precio, Nombre) {
    CantidadBebidas = Cantidad;
}

Bebida::~Bebida() {

}

int Bebida::getCantidadBebidas() const {
    return CantidadBebidas;
}

void Bebida::setCantidadBebidas(int Cantidad) {
    CantidadBebidas = Cantidad;
}

const string Bebida::ProductoType() {
    return "Bebida";
}