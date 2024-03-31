#pragma once
#include <string>
using namespace std;

class Producto {
	private:
		int p_ID;
		string p_nombre;
		double p_precio;

	public:
		Producto();
		Producto(string Nombre, double Precio);
		~Producto();

		int getID() const;
		void setID(int);

		double getPrecio() const;
		void setPrecio(double);
		
		string getNombre() const;
		void setNombre(string);
};

