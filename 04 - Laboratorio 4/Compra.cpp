#include "Compra.h"
#include "Estudiante.h"
#include "Negocio.h"
#include "Producto.h"
#include <iostream>

using namespace std;

Compra::Compra() {

}

Compra::Compra(Estudiante cEstudiante, Negocio cNegocio, vector<Producto>cProductos) {
	c_Estudiante = cEstudiante;
	c_Negocio = cNegocio;
	c_Producto = cProductos;
}

Compra::~Compra() {

}



Estudiante Compra::getcEstudiante() const {
	return c_Estudiante;
}

void Compra::setcEstudiante(Estudiante cEstudiante) {
	c_Estudiante = cEstudiante;
}



Negocio Compra::getcNegocio() const {
	return c_Negocio;
}

void Compra::setcNegocio(Negocio cNegocio) {
	c_Negocio = cNegocio;
}



vector<Producto> Compra::getcProducto() const {
	return c_Producto;
}

void Compra::setcProducto(vector<Producto> cProducto) {
	c_Producto = cProducto;
}