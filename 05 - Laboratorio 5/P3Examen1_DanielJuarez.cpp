#include <iostream>
#include <vector>
#include <string>
#include "Paquete.h";
#include "Cliente.h";
using namespace std;

void Menu() {
	cout << endl << "------ Menu Principal ------" << endl;
	cout << "1. Salir\n2. Agregar cliente\n3. Registrar paquete\n4. Listar clientes\n5. Listar paquetes\n6. Listar paquetes de un cliente\n7. Avanzar dia" << endl;
}
void ListarClientes(vector<Cliente> clientes) {
	cout << endl << "----- Lista de Usuarios -----" << endl;
	for (int i = 0; i < clientes.size(); i++) {
		cout << i << ": " << clientes.at(i).getNombreCliente() << endl << "Paquetes: " << clientes.at(i).getPaquetes().size() << endl;
	}
}

int main() {

	//Inicio
	vector<Paquete*> paquetes, paquetesplaceholder;
	vector<Cliente> clientes;
	int MainMenu;
	double kilometros;
	//Agregar
	string nombre;
	Cliente c;
	//Registrar Paquetes
	int clientindex, id, diasbodega;
	int dia = 1;
	int diasss, kmsss;
	string descripcion, direccion;
	double distancia;
	bool entregado;
	Paquete* ptrpaquete;

	cout << "Bienvenido Al Sistema de Envios de Paquetes\nIngrese Cuantos KM se Moveran Los Paquetes Cada Dia: ";
	cin >> kilometros;
	while (kilometros < 1) {
		cout << "No Puede Ingresar Datos Menores a 1.\nIngrese Cuantos KM se Moveran Los Paquetes Cada Dia: ";
		cin >> kilometros;
	}

	do {
		cout << endl << "DIA: " << dia;
		Menu();
		cout << "Ingrese una Opcion: ";
		cin >> MainMenu;

		switch (MainMenu) {

			case 1:
				break;

			case 2:
				//Agregar Cliente
				cout << "Ingrese el Nombre del Cliente: ";
				cin.ignore();
				getline(cin, nombre);
				c = Cliente(nombre, paquetesplaceholder);
				clientes.push_back(c);
				break;

			case 3:
				ptrpaquete = new Paquete();
				//Registrar Paquete
				ListarClientes(clientes);
				cout << "Ingrese el Cliente: ";
				cin >> clientindex;
				while (clientindex < 0 || clientindex > clientes.size()) {
					cout << "Out of Range.\nIngrese el Cliente: ";
					cin >> clientindex;
				}

				clientes.at(clientindex).getPaquetes().push_back(ptrpaquete);
				paquetes.push_back(ptrpaquete);
				//Setting
				ptrpaquete->setID(paquetes.size());
				cin.ignore();
				cout << "Ingrese la Descripcion del Paquete: ";
				getline(cin, descripcion);
				ptrpaquete->setDescripcion(descripcion);
				cout << "Ingrese la Direccion del Paquete: ";
				getline(cin, direccion);
				ptrpaquete->setDireccion(direccion);
				cout << "Ingrese la Cantidad de Dias del Paquete en Bodega: ";
				cin >> diasbodega;
				while (diasbodega < 0) {
					cout << "No Puede Ser Negativo.\nIngrese la Cantidad de Dias del Paquete en Bodega: ";
					cin >> diasbodega;
				}
				ptrpaquete->setDiasBodega(diasbodega);
				cout << "Ingrese la Distancia a Entregar el Paquete: ";
				cin >> distancia;
				while (distancia < 0) {
					cout << "No Puede Ser Negativo.\nIngrese la Distancia a Entregar el Paquete: ";
					cin >> distancia;
				}
				ptrpaquete->setDistancia(distancia);
				ptrpaquete->setEntregado(false);
				break;

			case 4:
				//Listar Clientes
				for (int i = 0; i < clientes.size(); i++) {
					cout << i << " - " << clientes.at(i).getNombreCliente() << ": Paqs. " << clientes.at(i).getPaquetes().size() << endl;
				}
				break;
				
			case 5:
				//Listar Paquetes
				cout << "Paquetes Entregados ----------------" << endl;
				for (int i = 0; i < paquetes.size(); i++) {
					if (paquetes.at(i)->getEntregado()) {
						cout << "ID: " << paquetes.at(i)->getID() << endl;
						cout << "Desc.: " << paquetes.at(i)->getDescripcion() << endl;
						cout << "Direccion: " << paquetes.at(i)->getDireccion() << endl;
						cout << "Estado: Entregado" << endl;
						cout << "Dias " << paquetes.at(i)->getDiasBodega() << endl;
						cout << "Distancia " << paquetes.at(i)->getDistancia() << endl;
					}
				}
				cout << "Paquetes No Entregados ----------------" << endl;
				for (int i = 0; i < paquetes.size(); i++) {
					if (!paquetes.at(i)->getEntregado()) {
						cout << "ID: " << paquetes.at(i)->getID() << endl;
						cout << "Desc.: " << paquetes.at(i)->getDescripcion() << endl;
						cout << "Direccion: " << paquetes.at(i)->getDireccion() << endl;
						cout << "Estado: No Entregado" << endl;
						cout << "Dias " << paquetes.at(i)->getDiasBodega() << endl;
						cout << "Distancia " << paquetes.at(i)->getDistancia() << endl;
					}
				}
				break;

			case 6:
				//Listar Paquetes de un Cliente
				ListarClientes(clientes);
				cout << "Ingrese el Cliente: ";
				cin >> clientindex;
				while (clientindex < 0 || clientindex > clientes.size()) {
					cout << "Out of Range.\nIngrese el Cliente: ";
					cin >> clientindex;
				}

				cout << "Paquetes Entregados ----------------" << endl;
				for (int i = 0; i < paquetes.size(); i++) {
					if (paquetes.at(i)->getEntregado()) {
						cout << "ID: " << paquetes.at(i)->getID() << endl;
						cout << "Desc.: " << paquetes.at(i)->getDescripcion() << endl;
						cout << "Direccion: " << paquetes.at(i)->getDireccion() << endl;
						cout << "Estado: Entregado" << endl;
						cout << "Dias: " << 0 << endl;
						cout << "Distancia: " << 0 << endl;
					}
				}
				cout << "Paquetes No Entregados ----------------" << endl;
				for (int i = 0; i < paquetes.size(); i++) {
					if (!paquetes.at(i)->getEntregado()) {
						cout << "ID: " << paquetes.at(i)->getID() << endl;
						cout << "Desc.: " << paquetes.at(i)->getDescripcion() << endl;
						cout << "Direccion: " << paquetes.at(i)->getDireccion() << endl;
						cout << "Estado: No Entregado" << endl;
						cout << "Dias: " << paquetes.at(i)->getDiasBodega() << endl;
						cout << "Distancia: " << paquetes.at(i)->getDistancia() << endl;
					}
				}
				break;

			case 7:
				//Avanzar Dia
				dia++;
				for (int i = 0; i < clientes.size(); i++) {
					for (int j = 0; j < clientes.at(i).getPaquetes().size(); j++) {


						if (clientes.at(i).getPaquetes().at(j)->getDiasBodega() <= 0) {
							clientes.at(i).getPaquetes().at(j)->setDiasBodega(0);
							if (clientes.at(i).getPaquetes().at(j)->getDistancia() > 0) {
								kmsss = clientes.at(i).getPaquetes().at(j)->getDistancia();
								clientes.at(i).getPaquetes().at(j)->setDistancia(kmsss - kilometros);
							} else {
								clientes.at(i).getPaquetes().at(j)->setEntregado(true);
								clientes.at(i).getPaquetes().at(j)->setDistancia(0);
							}
						} else {
							diasss = clientes.at(i).getPaquetes().at(i)->getDiasBodega();
							clientes.at(i).getPaquetes().at(i)->setDiasBodega(diasss - 1);
						}
					}
				}

		}


	} while (MainMenu != 1);

	
	cout << "Adios Vaquero….Gracias por todo Edmodo, ya no te podemos usar ni modo";
	
}