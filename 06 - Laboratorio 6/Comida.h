#pragma once
#include <iostream>
#include "Producto.h";
using namespace std;

class Comida : public Producto {

	private:
		bool EstadoVencido;

	public:
		Comida();
		Comida(double, string, bool);
		~Comida();

		bool getEstadoVencido() const;
		void setEstadoVencido(bool);

		virtual const string ProductoType();

};

