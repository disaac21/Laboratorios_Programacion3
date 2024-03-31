#pragma once
#include <iostream>
#include "Producto.h";
using namespace std;

class Bebida : public Producto {

	private:
		int CantidadBebidas;

	public:
		Bebida();
		Bebida(double, string, int);
		~Bebida();

		int getCantidadBebidas() const;
		void setCantidadBebidas(int);

		virtual const string ProductoType();

};

