#include "Comida.h"
#include "Producto.h"
#include <iostream>
using namespace std;

Comida::Comida() {

}

Comida::Comida(double Precio, string Nombre, bool Vencido) : Producto(Precio, Nombre) {
    EstadoVencido = Vencido;
}

Comida::~Comida() {

}

bool Comida::getEstadoVencido() const {
    return EstadoVencido;
}

void Comida::setEstadoVencido(bool EstadoVencido) {
    EstadoVencido = EstadoVencido;
}

const string Comida::ProductoType() {
    return "Comida";
}