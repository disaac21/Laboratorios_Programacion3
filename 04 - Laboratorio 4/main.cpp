#include <iostream>
#include <vector>
#include "Estudiante.h"
#include "Negocio.h"
#include "Producto.h"
#include "Compra.h"
using namespace std;

void Menu() {
	cout << endl << "------ Menu Principal ------" << endl;
	cout << "1. Administrar Estudiantes\n2. Administrar Locales\n3. Administrar Productos\n4. Administrar Compras\n5. Salir\nIngrese una Opcion: ";
}

void MenuEstudiante() {
	cout << endl << "1. Agregar Estudiante\n2. Editar Estudiante\n3. Eliminar Estudiante\n4. Imprimir Estudiantes\nIngrese una Opcion: ";
}
void coutEstudiante(vector<Estudiante> VectorEstudiantes) {
	cout << endl << "Lista de Estudiantes" << endl;
	for (Estudiante e : VectorEstudiantes) {
		cout << e.getID() << ") Nombre: " << e.getNombre() << endl;
	}
}

void MenuNegocio() {
	cout << endl << "1. Agregar Negocio\n2. Editar Negocio\n3. Eliminar Negocio\n4. Imprimir Negocios\nIngrese una Opcion: ";
}
void coutNegocio(vector<Negocio> VectorNegocios) {
	cout << endl << "Lista de Negocio" << endl;
	for (Negocio n : VectorNegocios) {
		cout << n.getID() << ") Nombre: " << n.getNombre() << endl;
	}
}

void MenuProducto() {
	cout << endl << "1. Agregar Producto\n2. Editar Producto\n3. Eliminar Producto\n4. Imprimir Productos\nIngrese una Opcion: ";
}
void coutProducto(vector<Producto> VectorProducto) {
	cout << endl << "Lista de Producto" << endl;
	for (Producto p : VectorProducto) {
		cout << p.getID() << ") Nombre: " << p.getNombre() << endl;
	}
}

void MenuCompra() {
	cout << endl << "1. Generar Compra\n2. Imprimir Compras por Negocio\n3. Imprimir Compras por Estudiante\n4. Imprimir Todas las Compras\nIngrese una Opcion: ";
}



int main() {
	
	vector<Estudiante> VectorEstudiantes;
	vector<Negocio> VectorNegocios;
	vector<Producto> VectorProducto;
	vector<Compra> VectorCompras;

	int MenuPrincipal, ModEstudiante, lastindex, ModNegocio, ModProducto;
	string Nombre, Apellido;
	double Precio;
	bool editfound;
	Estudiante printestudiante = Estudiante();
	Negocio printnegocio = Negocio();
	Producto printproducto = Producto();
	Estudiante e, CurrentEstudiante, LastEstudiante;
	Negocio n, CurrentNegocio, LastNegocio;
	Producto p, CurrentProducto, LastProducto;
	Compra c;

	//Compras
	Estudiante EstCompra;
	Negocio NegCompra;
	int IDEstudiante, IDNegocio;


	
	do {
		Menu();
		cin >> MenuPrincipal;
		switch (MenuPrincipal) {

			//Menu Estudiantes
			case 1:
				MenuEstudiante();
				int OpcionEstudiante;
				cin >> OpcionEstudiante;
				switch (OpcionEstudiante) {
					//CRUD Estudiantes
					case 1:
						cout << endl << "Ingrese el Nombre del Estudiante: ";
						cin >> Nombre;
						cout << "Ingrese el Apellido del Estudiante: ";
						cin >> Apellido;

						e = Estudiante(Nombre, Apellido);
						if (VectorEstudiantes.empty() == 1) {
							e.setID(VectorEstudiantes.size());
							VectorEstudiantes.push_back(e);
						} else {
							lastindex = VectorEstudiantes.size() - 1;
							e.setID(VectorEstudiantes.at(lastindex).getID() + 1);
							VectorEstudiantes.push_back(e);
						}
						cout << "ID: " << e.getID() << endl;
					break;
					case 2:
						editfound = false;
						coutEstudiante(VectorEstudiantes);
						cout << "Ingrese el ID del Estudiante a Modificar: ";
						cin >> ModEstudiante;
						for (int i = 0; i < VectorEstudiantes.size(); i++) {
							if (VectorEstudiantes.at(i).getID() == ModEstudiante) {
								editfound = true;
							}
							if (editfound) {
								cout << endl << "1. Modificar Nombre\n2. Modificar Apellido\nIngrese una Opcion: ";
								int ModAlumno;
								cin >> ModAlumno;
								switch (ModAlumno) {
									case 1:
										cout << "Ingrese el Nombre: ";
										cin >> Nombre;
										VectorEstudiantes.at(i).setNombre(Nombre);
									break;
									case 2:
										cout << "Ingrese el Apellido: ";
										cin >> Nombre;
										VectorEstudiantes.at(i).setApellido(Apellido);
									break;
								}
							}
						}
					break;
					case 3:
						editfound = false;
						coutEstudiante(VectorEstudiantes);
						cout << "Ingrese el ID del Estudiante a Eliminar: ";
						cin >> ModEstudiante;
						for (int i = 0; i < VectorEstudiantes.size(); i++) {
							if (ModEstudiante == VectorEstudiantes.at(i).getID()) {
								editfound = true;
							}
							if (editfound) {
								VectorEstudiantes.erase(VectorEstudiantes.begin()+i);
							}
						}
					break;
					case 4:
						coutEstudiante(VectorEstudiantes);
					break;
				}
			break;

			//Menu Negocios
			case 2:
				MenuNegocio();
				int OpcionNegocio;
				cin >> OpcionNegocio;
				switch (OpcionNegocio) {
					//CRUD Negocios
					case 1:
						cout << endl << "Ingrese el Nombre del Negocio: ";
						cin >> Nombre;

						n = Negocio(Nombre);
						if (VectorNegocios.empty() == 1) {
							n.setID(VectorNegocios.size());
							VectorNegocios.push_back(n);
						}
						else {
							lastindex = VectorNegocios.size() - 1;
							n.setID(VectorNegocios.at(lastindex).getID() + 1);
							VectorNegocios.push_back(n);
						}
						cout << "ID: " << n.getID() << endl;
					break;
					case 2:
						editfound = false;
						coutNegocio(VectorNegocios);
						cout << "Ingrese el ID del Negocio a Modificar: ";
						cin >> ModNegocio;
						for (int i = 0; i < VectorNegocios.size(); i++) {
							if (VectorNegocios.at(i).getID() == ModNegocio) {
								editfound = true;
							}
							if (editfound) {
								cout << endl << "1. Modificar Nombre\nIngrese una Opcion: ";
								int ModNegocio;
								cin >> ModNegocio;
								switch (ModNegocio) {
									case 1:
										cout << "Ingrese el Nombre: ";
										cin >> Nombre;
										VectorNegocios.at(i).setNombre(Nombre);
										break;
								}
							}
						}
					break;
					case 3:
						editfound = false;
						coutNegocio(VectorNegocios);
						cout << "Ingrese el ID del Estudiante a Eliminar: ";
						cin >> ModNegocio;
						for (int i = 0; i < VectorNegocios.size(); i++) {
							if (ModNegocio == VectorNegocios.at(i).getID()) {
								editfound = true;
							}
							if (editfound) {
								VectorNegocios.erase(VectorNegocios.begin() + i);
							}
						}
					break;
					case 4:
						coutNegocio(VectorNegocios);
					break;
				}
			break;

			//Menu Productos
			case 3:
				MenuProducto();
				int OpcionProducto;
				cin >> OpcionProducto;
				switch (OpcionProducto) {
					//CRUD Productos
					case 1:
						cout << endl << "Ingrese el Nombre del Producto: ";
						cin >> Nombre;
						cout << "Ingrese el Precio del Producto: ";
						cin >> Precio;

						p = Producto(Nombre, Precio);
						if (VectorProducto.empty() == 1) {
							p.setID(VectorProducto.size());
							VectorProducto.push_back(p);
						}
						else {
							lastindex = VectorProducto.size() - 1;
							p.setID(VectorProducto.at(lastindex).getID() + 1);
							VectorProducto.push_back(p);
						}
						cout << "ID: " << p.getID() << endl;
					break;
					case 2:
						editfound = false;
						coutProducto(VectorProducto);
						cout << "Ingrese el ID del Producto a Modificar: ";
						cin >> ModProducto;
						for (int i = 0; i < VectorProducto.size(); i++) {
							if (VectorProducto.at(i).getID() == ModProducto) {
								editfound = true;
							}
							if (editfound) {
								cout << endl << "1. Modificar Nombre\n2. Modificar Precio\nIngrese una Opcion: ";
								int ModProducto;
								cin >> ModProducto;
								switch (ModProducto) {
								case 1:
									cout << "Ingrese el Nombre: ";
									cin >> Nombre;
									VectorProducto.at(i).setNombre(Nombre);
									break;
								case 2:
									cout << "Ingrese el Precio: ";
									cin >> Precio;
									VectorProducto.at(i).setPrecio(Precio);
									break;
								}
							}
						}
					break;
					case 3:
						editfound = false;
						coutProducto(VectorProducto);
						cout << "Ingrese el ID del Producto a Eliminar: ";
						cin >> ModProducto;
						for (int i = 0; i < VectorProducto.size(); i++) {
							if (ModProducto == VectorProducto.at(i).getID()) {
								editfound = true;
							}
							if (editfound) {
								VectorProducto.erase(VectorProducto.begin() + i);
							}
						}
					break;
					case 4:
						coutProducto(VectorProducto);
					break;
				}
			break;

			//Menu Compras
			case 4:
				MenuCompra();
				int OpcionCompra, CuantasCompras, BuyingNow;
				vector<Producto> Comprando;
				cin >> OpcionCompra;
				switch (OpcionCompra) {
					//Productos
					case 1:
						//Estudiante cEstudiante, Negocio cNegocio, vector<Producto>cProductos
						coutEstudiante(VectorEstudiantes);
						cout << "Ingrese el ID del Estudiante Comprando: ";
						cin >> IDEstudiante;
						coutNegocio(VectorNegocios);
						cout << "Ingrese el ID del Negocio Comprando:";
						cin >> IDNegocio;
						for (int i = 0; i < VectorEstudiantes.size(); i++) {
							if (IDEstudiante == VectorEstudiantes.at(i).getID()) {
								editfound = true;
							}
							if (editfound) {
								EstCompra = VectorEstudiantes.at(i);
							}
						}
						for (int i = 0; i < VectorNegocios.size(); i++) {
							if (IDNegocio == VectorNegocios.at(i).getID()) {
								editfound = true;
							}
							if (editfound) {
								NegCompra = VectorNegocios.at(i);
							}
						}

						cout << "Ingrese Cuantos Productos Desea Comprar: ";
						cin >> CuantasCompras;
						coutProducto(VectorProducto);
						for (int i = 0; i < CuantasCompras; i++) {
							cout << "Ingrese el ID del Producto a Comprar: ";
							cin >> BuyingNow;
							for (int j = 0; j < VectorProducto.size(); j++) {
								if (BuyingNow == VectorProducto.at(i).getID()) {
									Comprando.push_back(VectorProducto.at(i));
									cout << "Agregado!" << endl;
								}
							}
						}
						c = Compra(EstCompra, NegCompra, Comprando);
						VectorCompras.push_back(c);

					break;
					case 2:
						//Por Negocio
						coutNegocio(VectorNegocios);
						cout << "Ingrese el ID del Negocio Comprando:";
						cin >> IDNegocio;
						for (int i = 0; i < VectorNegocios.size(); i++) {
							if (IDNegocio == VectorNegocios.at(i).getID()) {
								editfound = true;
							}
							if (editfound) {
								NegCompra = VectorNegocios.at(i);
							}
						}
						for (int i = 0; i < VectorCompras.size(); i++) {
							if (NegCompra.getID() == VectorCompras.at(i).getcNegocio().getID()) {
								for (int j = 0; j < VectorCompras.at(i).getcProducto().size(); j++) {
									cout << VectorCompras.at(i).getcProducto().at(j).getID() << ") " << VectorCompras.at(i).getcProducto().at(j).getNombre();
								}
							}
						}
					break;
					case 3:
						//Por Estudiante
						coutEstudiante(VectorEstudiantes);
						cout << "Ingrese el ID del Estudiante Comprando:";
						cin >> IDEstudiante;
						for (int i = 0; i < VectorEstudiantes.size(); i++) {
							if (IDEstudiante == VectorEstudiantes.at(i).getID()) {
								editfound = true;
							}
							if (editfound) {
								EstCompra = VectorEstudiantes.at(i);
							}
						}
						for (int i = 0; i < VectorEstudiantes.size(); i++) {
							if (EstCompra.getID() == VectorEstudiantes.at(i).getID()) {
								for (int j = 0; j < VectorCompras.at(i).getcProducto().size(); j++) {
									cout << VectorCompras.at(i).getcProducto().at(j).getID() << ") " << VectorCompras.at(i).getcProducto().at(j).getNombre();
								}
							}
						}
					break;
					case 4:
						for (int i = 0; i < VectorCompras.size(); i++) {
							cout << "Compra " << i << endl;
							for (int j = 0; j < VectorCompras.at(i).getcProducto().size(); j++) {
								cout << VectorCompras.at(i).getcProducto().at(j).getID() << ") " << VectorCompras.at(i).getcProducto().at(j).getNombre();
							}
							cout << endl;
						}
					break;
				}
			break;
		}
	} while (MenuPrincipal != 5);
}