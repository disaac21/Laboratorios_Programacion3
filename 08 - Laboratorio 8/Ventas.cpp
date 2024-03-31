#include <iostream>
#include<string>
#include <vector>
#include "Ventas.h"
#include "Producto.h"
using namespace std;

Ventas::Ventas() {

}
Ventas::Ventas(vector<Producto*> Productos, double total) {
    this->Productos = Productos;
    this->total = total;
}
Ventas::~Ventas(){

}

vector<Producto*> Ventas::getProductos() const {
	return Productos;
}

void Ventas::setProductos(vector<Producto*> Productos) {
	this->Productos = Productos;
}

double Ventas::gettotal() const {
    return total;
}

void Ventas::settotal(double total){
    this->total = total;
}

void Ventas::imprimir() const {
    for (int i = 0; i < Productos.size(); i++){
        Productos.at(i)->imprimir();
    }
}