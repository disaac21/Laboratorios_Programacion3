#include "Compra.h"
#include <iostream>
#include <vector>
#include <string>
#include "Bebida.h";
#include "Comida.h";

using namespace std;

Compra::Compra() {

}

Compra::Compra(int Total, vector<Producto*>Lista, string Estudiante) {
	TotalCompra = Total;
	ListaCompra = Lista;
	NombreEstudiante = Estudiante;
}

Compra::~Compra() {

}

int Compra::getTotalCompra() const {
	return TotalCompra;
}

void Compra::setTotalCompra(int Total) {
	TotalCompra = Total;
}

vector<Producto*> Compra::getListaCompra() const {
	return ListaCompra;
}

void Compra::setListaCompra(vector<Producto*> Lista) {
	ListaCompra = Lista;
}

string Compra::getNombreEstudiante() const {
	return NombreEstudiante;
}

void Compra::setNombreEstudiante(string Estudiante) {
	NombreEstudiante = Estudiante;
}