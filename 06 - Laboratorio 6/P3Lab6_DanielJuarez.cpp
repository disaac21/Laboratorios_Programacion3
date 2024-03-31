#include <iostream>
#include <vector>
#include <string>
#include "Producto.h"
#include "Comida.h"
#include "Bebida.h"
#include "Compra.h"
using namespace std;

void Menu() {
	cout << endl << " ----- Menu Principal -----" << endl;
	cout << "1. Agregar Bebida\n2. Agregar Comida\n3. Modificar Producto\n4. Mostrar Productos\n5. Generar Compra\n6. Mostrar Compras\n7. Salir" << endl;
}

void generarcompras(vector<Producto*>& ListaProductos, vector<Compra*>& VectorCompras) {
	Compra* c;
	int CantidadProductos, IndexProducto, TotalPagar = 0;
	string NomEst;
	bool FinCompra = true;
	vector<Producto*> Comprando;

	Producto* PtrProducto;
	Comida* PtrComidaCase;
	Bebida* PtrBebidaCase;



	//Generar Compra
				//Total, Lista, Nombre
	cout << "Ingrese el Nombre del Estudiante: ";
	cin.ignore();
	getline(cin, NomEst);




	cout << "Ingrese la Cantidad de Productos a Comprar: ";
	cin >> CantidadProductos;
	cout << endl;
	//Imprimir
	for (int i = 0; i < ListaProductos.size(); i++) {
		if (ListaProductos.at(i)->ProductoType() == "Comida") {
			PtrProducto = ListaProductos.at(i);
			PtrComidaCase = dynamic_cast<Comida*>(PtrProducto);
			cout << i << ": " << PtrComidaCase->getNombre() << " L. " << PtrComidaCase->getPrecio();
			if (PtrComidaCase->getEstadoVencido()) {
				cout << " Estado: Comible";
			}
			else {
				cout << " Estado: Vencido";
			}
		}
		else if (ListaProductos.at(i)->ProductoType() == "Bebida") {
			PtrProducto = ListaProductos.at(i);
			PtrBebidaCase = dynamic_cast<Bebida*>(PtrProducto);

			cout << i << ": " << PtrBebidaCase->getNombre() << " L. " << PtrBebidaCase->getPrecio();
			cout << " Cantidad: " << PtrBebidaCase->getCantidadBebidas() << endl;

		}
	}

	for (int i = 0; i < CantidadProductos; i++) {

		do {

			cout << "Ingrese el Indice del Producto a Comprar: ";
			cin >> IndexProducto;

			//Diferenciando Tipo
			if (ListaProductos.at(IndexProducto)->ProductoType() == "Comida") {

				PtrProducto = ListaProductos.at(IndexProducto);
				PtrComidaCase = dynamic_cast<Comida*>(PtrProducto);

				if (PtrComidaCase->getEstadoVencido() == true) {
					Comprando.push_back(PtrComidaCase);
					TotalPagar += PtrComidaCase->getPrecio();
					FinCompra = true;
				}
				else {
					cout << "Este Producto Esta Vencido" << endl;
					FinCompra = false;
				}

			}
			else if (ListaProductos.at(IndexProducto)->ProductoType() == "Bebida") {

				PtrProducto = ListaProductos.at(IndexProducto);
				PtrBebidaCase = dynamic_cast<Bebida*>(PtrProducto);

				if (PtrBebidaCase->getCantidadBebidas() > 0) {
					Comprando.push_back(PtrBebidaCase);
					PtrBebidaCase->setCantidadBebidas(PtrBebidaCase->getCantidadBebidas() - 1);
					TotalPagar += PtrBebidaCase->getPrecio();
					FinCompra = true;
				}
				else {
					cout << "No Hay Mas Elementos Disponibles" << endl;
					FinCompra = false;
				}

			}

		} while (!FinCompra);

	}

	c = new Compra(TotalPagar, Comprando, NomEst);

	VectorCompras.push_back(c);
}

int main() {

	//Inicio
	int MainMenu;
	vector<Producto*> ListaProductos;
	vector<Compra*> VectorCompras;
	//Agregar Bebida
	double PrecioBebida;
	string NombreBebida;
	int CantidadBebidas;
	Bebida* PtrBebida;
	//Agregar Comida;
	double PrecioComida;
	string NombreComida;
	bool ComidaVencido;
	Comida* PtrComida;
	//Modificar Producto
	int SeleccionMod = 0, SwitchComida, SwitchBebida, EstadoComida;
	Producto* PtrProducto;
	Comida* PtrComidaCase;
	Bebida* PtrBebidaCase;
	//Generar Compra
	

	do {
		Menu();
		cout << "Ingrese una Opcion: ";
		cin >> MainMenu;

		switch (MainMenu) {
			
			case 1:
				//Agregar Bebida
				cout << "Ingrese el Precio de la Bebida: ";
				cin >> PrecioBebida;
				cout << "Ingrese la Cantidad de Bebidas a Registrar: ";
				cin >> CantidadBebidas;
				cout << "Ingrese el Nombre de la Bebida: ";
				cin.ignore();
				getline(cin, NombreBebida);
				PtrBebida = new Bebida(PrecioBebida, NombreBebida, CantidadBebidas);
				ListaProductos.push_back(PtrBebida);
				break;

			case 2:
				//Agregar Comida
				cout << "Ingrese el Precio de la Comida: ";
				cin >> PrecioComida;
				cout << "Ingrese el Nombre de la Comida: ";
				cin.ignore();
				getline(cin, NombreComida);
				PtrComida = new Comida(PrecioComida, NombreComida, true);
				ListaProductos.push_back(PtrComida);
				break;

			case 3:
				//Modificar Producto

				for (int i = 0; i < ListaProductos.size(); i++) {
					if (ListaProductos.at(i)->ProductoType() == "Comida") {
						PtrProducto = ListaProductos.at(i);
						PtrComidaCase = dynamic_cast<Comida*>(PtrProducto);
						cout << i << ": " << PtrComidaCase->getNombre() << " L. " << PtrComidaCase->getPrecio();
						if (PtrComidaCase->getEstadoVencido()) {
							cout << " Estado: Comible";
						}
						else {
							cout << " Estado: Vencido";
						}
					}
					else if (ListaProductos.at(i)->ProductoType() == "Bebida") {
						PtrProducto = ListaProductos.at(i);
						PtrBebidaCase = dynamic_cast<Bebida*>(PtrProducto);

						cout << i << ": " << PtrBebidaCase->getNombre() << " L. " << PtrBebidaCase->getPrecio();
						cout << " Cantidad: " << PtrBebidaCase->getCantidadBebidas() << endl;

					}
				}
				cout << "\nIngrese el Indice del Producto a Modificar: ";
				cin >> SeleccionMod;				
				
				if (ListaProductos.at(SeleccionMod)->ProductoType() == "Comida") {

					//Cast
					PtrProducto = ListaProductos.at(SeleccionMod);
					PtrComidaCase = dynamic_cast<Comida*>(PtrProducto);
					//could try
					//PtrComidaCase = dynamic_cast<Comida*>(ListaProductos.at(SeleccionMod));

					cout << "--- Comida ----\n1. Precio\n2. Estado\n3. Nombre" << endl;
					cout << "Ingrese el Atributo a Modificar: ";
					cin >> SwitchComida;

					switch (SwitchComida) {

						case 1:
							cout << "Ingrese el Precio de la Comida: ";
							cin >> PrecioComida;
							PtrComidaCase->setPrecio(PrecioComida);
							break;
						case 2:
							cout << "Ingrese el Estado de la Comida -> 0. Vencido | 1. No Vencido";
							cin >> EstadoComida;
							if (EstadoComida == 0) {
								//Set False
								PtrComidaCase->setEstadoVencido(false);
							}
							else if (EstadoComida == 1) {
								//Set True
								PtrComidaCase->setEstadoVencido(true);
							}
							break;
						case 3:
							cout << "Ingrese el Nombre de la Comida: ";
							cin.ignore();
							getline(cin, NombreComida);
							PtrComidaCase->setNombre(NombreComida);
							break;
					}


				} else if (ListaProductos.at(SeleccionMod)->ProductoType() == "Bebida") {

					//Cast
					PtrProducto = ListaProductos.at(SeleccionMod);
					PtrBebidaCase = dynamic_cast<Bebida*>(PtrProducto);
					//could try
					//PtrBebidaCase = dynamic_cast<Bebida*>(ListaProductos.at(SeleccionMod));

					cout << "--- Bebida ----\n1. Precio\n2. Cantidad\n3. Nombre" << endl;
					cout << "Ingrese el Atributo a Modificar: ";
					cin >> SwitchBebida;

					switch (SwitchBebida) {

					case 1:
						cout << "Ingrese el Precio de la Bebida: ";
						cin >> PrecioBebida;
						PtrBebidaCase->setPrecio(PrecioBebida);
						break;
					case 2:
						cout << "Ingrese la Cantidad de Bebidas a Registrar: ";
						cin >> CantidadBebidas;
						PtrBebidaCase->setCantidadBebidas(CantidadBebidas);
						break;
					case 3:
						cout << "Ingrese el Nombre de la Bebida: ";
						cin.ignore();
						getline(cin, NombreBebida);
						PtrBebidaCase->setNombre(NombreBebida);
						break;
					}

				}
				break;

			case 4:
				//Mostrar Producto
				for (int i = 0; i < ListaProductos.size(); i++) {
					if (ListaProductos.at(i)->ProductoType() == "Comida") {
						PtrProducto = ListaProductos.at(i);
						PtrComidaCase = dynamic_cast<Comida*>(PtrProducto);
						cout << i << ": " << PtrComidaCase->getNombre() << " L. " << PtrComidaCase->getPrecio();
						if (PtrComidaCase->getEstadoVencido()) {
							cout << " Estado: Comible";
						}
						else {
							cout << " Estado: Vencido";
						}
					}
					else if (ListaProductos.at(i)->ProductoType() == "Bebida") {
						PtrProducto = ListaProductos.at(i);
						PtrBebidaCase = dynamic_cast<Bebida*>(PtrProducto);

						cout << i << ": " << PtrBebidaCase->getNombre() << " L. " << PtrBebidaCase->getPrecio();
						cout << " Cantidad: " << PtrBebidaCase->getCantidadBebidas() << endl;

					}
				}
				//1 : bebidauno L. 20 Cantidad : 2
				//2 : comidauno L. 29 Estado : Comible
				//en todos los prints
				break;

			case 5:
				generarcompras(ListaProductos, VectorCompras);
				break;

			case 6:
				//Mostrar Compras
				cout << VectorCompras.size();
				for (int i = 0; i < VectorCompras.size(); i++) {
					cout << i << ":" << endl;
					
					for (int j = 0; j < VectorCompras.at(i)->getListaCompra().size(); j++) {
						cout << VectorCompras.at(i)->getListaCompra().at(j)->getNombre() << " L. " << VectorCompras.at(i)->getListaCompra().at(j)->getPrecio() << endl;
					}
					cout << "Nombre: " << VectorCompras.at(i)->getNombreEstudiante() << " - Total: " << VectorCompras.at(i)->getTotalCompra() << endl;
					cout << "----------------------------------" << endl;


				}

				/*
				1:
				bebidauno L. 20
				bebidauno L. 20
				Nombre:daniel Total: 40
				*/
				break;

			case 7:
				//Salir
				break;

		}

	} while (MainMenu != 7);

}

/*
Compras que cuentan
con un total (la suma de los precios de los productos en la compra), una lista
de productos y un nombre del estudiante.

5. Generar compra
a. Opción para poder generar una compra dada una serie de
productos, y un nombre.

6. Mostrar compras
a. Opción para mostrar e imprimir todas las compras de manera
ordenada, mostrando en cada compra su lista de productos.

Al generar una compra, deberá de restar la cantidad de bebidas agregadas
a la compra del inventario, así mismo, si no hay una cantidad suficiente de
bebidas no se podrá generar esa compra. Por último, si la comida esta en
un estado de vencido, esta misma no podrá ser agregada a ninguna orden.

*/