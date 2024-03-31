#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Bebida.h";
#include "Comida.h";

using namespace std;

class Compra {

	private:
		int TotalCompra;
		vector<Producto*> ListaCompra;
		string NombreEstudiante;

	public:
		Compra();
		Compra(int, vector<Producto*>, string);
		~Compra();

		int getTotalCompra() const;
		void setTotalCompra(int);

		vector<Producto*> getListaCompra() const;
		void setListaCompra(vector<Producto*>);

		string getNombreEstudiante() const;
		void setNombreEstudiante(string);

};