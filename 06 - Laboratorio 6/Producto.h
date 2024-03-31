#pragma once
#include <iostream>
using namespace std;

class Producto {
	private:
		double PrecioProducto;
		string NombreProducto;

	public:
		Producto();
		Producto(double, string);
		~Producto();

		double getPrecio() const;
		void setPrecio(double);

		string getNombre() const;
		void setNombre(string);

		virtual const string ProductoType();

};

