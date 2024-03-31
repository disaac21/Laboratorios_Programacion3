#include "Cliente.h"
#include <iostream>
#include <vector>
#include "Paquete.h";
using namespace std;

Cliente::Cliente() {

}

Cliente::Cliente(string Clientenombre, vector<Paquete*>ListaPaquetes) {
	NombreCliente = Clientenombre;
	Paquetes = ListaPaquetes;
}

Cliente::~Cliente() {
	/*for (int i = 0; i < Paquetes.size(); i++) {
		delete Paquetes.at(i);
	}*/
}

string Cliente::getNombreCliente() const {
	return NombreCliente;
}
void Cliente::setNombreCliente(string Clientenombre) {
	NombreCliente = Clientenombre;
}

vector<Paquete*> &Cliente::getPaquetes() {
	return Paquetes;
}
void Cliente::setPaquetes(vector<Paquete*> ListaPaquetes) {
	Paquetes = ListaPaquetes;
}