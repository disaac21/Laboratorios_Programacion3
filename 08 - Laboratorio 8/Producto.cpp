#include "Producto.h"
#include <iostream>
#include<string>
using namespace std;

Producto::Producto() {

}
Producto::Producto(string nombre, double precio) {
    this->nombre = nombre;
    this->precio = precio;
}
Producto::~Producto(){

}

string Producto::getnombre() const {
    return nombre;
}
double Producto::getprecio() const {
    return precio;
}

void Producto::setnombre(string nombre){
    this->nombre = nombre;
}
void Producto::setprecio(double precio){
    this->precio = precio;
}

void Producto::imprimir() const {
    cout << nombre << " " << precio;
}
