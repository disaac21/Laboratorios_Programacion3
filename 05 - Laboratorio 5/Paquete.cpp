#include "Paquete.h"
#include <iostream>

using namespace std;

Paquete::Paquete() {

}

Paquete::Paquete(int ID, string Descripcion, string Direccion, int DiasBodega, double Distancia, bool Entregado) {
	IDPaq = ID;
	DescPaq = Descripcion;
	DirPaq = Direccion;
	diasBodegaPaq = DiasBodega;
	DistanciaPaq = Distancia;
	EntregadoPaq = Entregado;
}

Paquete::~Paquete() {

}

int Paquete::getID() const {
	return IDPaq;
}
void Paquete::setID(int ID) {
	this->IDPaq = ID;
}

string Paquete::getDescripcion() const {
	return DescPaq;
}
void Paquete::setDescripcion(string Descripcion) {
	DescPaq = Descripcion;
}

string Paquete::getDireccion() const {
	return DirPaq;
}
void Paquete::setDireccion(string Direccion) {
	DirPaq = Direccion;
}

int Paquete::getDiasBodega() const {
	return diasBodegaPaq;
}
void Paquete::setDiasBodega(int DiasBodega) {
	diasBodegaPaq = DiasBodega;
}

double Paquete::getDistancia() const {
	return DistanciaPaq;
}
void Paquete::setDistancia(double Distancia) {
	DistanciaPaq = Distancia;
}

bool Paquete::getEntregado() const {
	return EntregadoPaq;
}
void Paquete::setEntregado(bool Entregado) {
	EntregadoPaq = Entregado;
}