#pragma once
#include <string>
#include <vector>
#include "Estudiante.h";
#include "Negocio.h";
#include "Producto.h";

using namespace std;

class Compra {

	private:
		Estudiante c_Estudiante;
		Negocio c_Negocio;
		vector<Producto> c_Producto;

	public:
		Compra();
		Compra(Estudiante cEstudiante, Negocio cNegocio, vector<Producto>cProductos);
		~Compra();

		Estudiante getcEstudiante() const;
		void setcEstudiante(Estudiante);

		Negocio getcNegocio() const;
		void setcNegocio(Negocio);

		vector<Producto> getcProducto() const;
		void setcProducto(vector<Producto>);

};