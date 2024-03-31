#pragma once
#include <iostream>
#include <vector>
#include "Paquete.h";

using namespace std;

class Cliente {
	private:
		string NombreCliente;
		vector<Paquete*> Paquetes;
	public:
		Cliente();
		Cliente(string Clientenombre, vector<Paquete*>ListaPaquetes);
		~Cliente();

		string getNombreCliente() const;
		void setNombreCliente(string);

		vector<Paquete*> &getPaquetes();
		void setPaquetes(vector<Paquete*>);
};

