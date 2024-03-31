#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Persona.h"
#include "Estudiante.h"
#include "Maestro.h"
#include "Producto.h"
#include "Ventas.h"
using namespace std;

void MainMenu(){
    cout << " ----- MENU -----\n1. Administrar Personas\n2. Administrar Productos\n3. Administrar Ventas\n4.Salir\nIngrese una Opcion: ";
}

template<typename t>
void Imprimir(vector<t> Arreglo) {
    for (int i = 0; i < Arreglo.size(); i++) {
        Arreglo.at(i).imprimir();
    }
}

template<typename t>
void Imprimir(vector<t*> Arreglo) {
    for (int i = 0; i < Arreglo.size(); i++) {
        Arreglo.at(i)->imprimir();
    }
}

void switchAdminPersonas(vector<Persona*> &Personas) {
    cout << " ----- ADMIN PERSONAS -----\n1. Agregar Estudiante\n2. Agregar Maestro\n3. Listar Personas\n4.Salir\nIngrese una Opcion: ";
    
    int PersonasOpcion, Edad;
    string Nombre, Apellido, Identidad, Cuenta;
    Estudiante* e;
    Maestro* m;
    cin >> PersonasOpcion;
    switch (PersonasOpcion) {
        case 1:
            cout << "Ingrese el Nombre: ";
            cin.ignore();
            getline(cin, Nombre);
            cout << "Ingrese el Apellido: ";
            getline(cin, Apellido);
            cout << "Ingrese el Numero de Cuenta: ";
            getline(cin, Cuenta);
            while (Cuenta.length() > 8) {
                cout << "Ingrese el Numero de Cuenta (Min. 8 caracteres): ";
                getline(cin, Cuenta);
            }
            cout << "Ingrese la Edad: ";
            cin >> Edad;
            while (Edad <= 0) {
                cout << "Ingrese una Edad Valida: ";
                cin >> Edad;
            }
            e = new Estudiante(Nombre, Apellido, Edad, Cuenta);
            Personas.push_back(e);
        break;
        case 2:
            cout << "Ingrese el Nombre: ";
            cin.ignore();
            getline(cin, Nombre);
            cout << "Ingrese el Apellido: ";
            getline(cin, Apellido);
            cout << "Ingrese el Numero de Identidad: ";
            getline(cin, Identidad);
            while (Identidad.length() > 13) {
                cout << "Ingrese el Numero de Identidad (Min. 13 caracteres): ";
                getline(cin, Identidad);
            }
            cout << "Ingrese la Edad: ";
            cin >> Edad;
            while (Edad <= 0) {
                cout << "Ingrese una Edad Valida: ";
                cin >> Edad;
            }
            m = new Maestro(Nombre, Apellido, Edad, Identidad);
            Personas.push_back(m);
        break;
        case 3:
            Imprimir(Personas);
        break;
        default:
            break;
    }
}

void switchAdminProductos(vector<Producto*> &Productos) {
    cout << " ----- ADMIN PRODUCTOS -----\n1. Agregar Producto\n2. Listar Productos\n3.Salir\nIngrese una Opcion: ";
    int ProductosOpcion;
    string Nombre;
    double Precio;
    Producto* p;
    cin >> ProductosOpcion;
    switch (ProductosOpcion) {
        case 1:
            cout << "Ingrese el Nombre: ";
            cin.ignore();
            getline(cin, Nombre);
            cout << "Ingrese el Precio: ";
            cin >> Precio;
            while (Precio < 0) {
                cout << "El Precio No Puede Ser Menor a 0, Ingrese el Precio: ";
                cin >> Precio;
            }
            
            p = new Producto(Nombre, Precio);
            Productos.push_back(p);
        break;
        case 2:
            Imprimir(Productos);
        break;
        default:
            break;
    }
}

void EscribirArchivo(vector<Ventas*> ListaVentas){
    // ofstream file;
    // file.open("ventas.bin", ios::binary);
    // file.write((reinterpret_cast<char*>(&ListaVentas)), sizeof(ListaVentas));
    // file.close();
    
    fstream file ("ventas.bin", ios::binary | ios::in | ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Error While Opening the File" << endl;
    } else {
        for (int i = 0; i < ListaVentas.size(); i++) {
            /* code */
        }
        
        file.write((char*)&ListaVentas, sizeof(Ventas));
        file.close();
    }
}

void LeerArchivo(vector<Ventas*> ListaVentas){

    //method one
    // int tam = 0;
    fstream file ("ventas.bin", ios::binary | ios::in | ios::out | ios::app);
    // ifstream file;
    // //file.open("ventas.bin", ios::binary);
    //  while (file.read(reinterpret_cast<char*>(&tam), sizeof(tam))) {
    //     string buff;
    //     buff.resize(tam);
    //     file.read(&buff[0], buff.size());

    // }
    
    //method dos
    if (!file.is_open()) {
        cout << "Error While Opening the File" << endl;
    } else {
        file.seekg(0);
        file.read((char*)&ListaVentas, sizeof(Ventas));
        file.close();
    Imprimir(ListaVentas);
    }
    file.close();

}

void switchAdminVentas(vector<Producto*> &Productos, vector<Ventas*>&ListaVentas, vector<Persona*>&Personas) {
    cout << " ----- ADMIN VENTAS -----\n1. Generar Venta\n2. Listar Ventas\n3.Salir\nIngrese una Opcion: ";
    int VentasOpcion, Buyer;
    Ventas* CurrentVenta;
    vector<Producto*>CurrentListaVenta;
    cin >> VentasOpcion;
    switch (VentasOpcion) {
        case 1:
            //Generar venta
            Imprimir(Productos);
            int ContinueVenta, Buying;
            CurrentVenta = new Ventas();
            do {
                cout << "Ingrese el Indice del Producto a Comprar: ";
                cin >> Buying;
                CurrentListaVenta.push_back(Productos.at(Buying));
                cout << "Desea Comprar Otro Item? Si = 1 | No = 0" << endl;
                cin >> ContinueVenta;
            } while (ContinueVenta != 0);
            Imprimir(Personas);
            cout << "Ingrese el Indice del Comprador: ";
            cin >> Buyer;
            int total;
            total = 0;
            for (int i = 0; i < CurrentListaVenta.size(); i++) {
                total += CurrentListaVenta.at(i)->getprecio();
            }
            cout << "Comprador: " << Personas.at(Buyer) << "\nCantidad: " << CurrentListaVenta.size() << "\nTotal: " << total << endl;
            
            //Imprimir(CurrentListaVenta);
        break;
        case 2:
            //Listar Ventas
            EscribirArchivo(ListaVentas);
        break;
        default:
            break;
    }
}

int main() {
    int MainOpcion;
    vector<Persona*>Personas;
    vector<Producto*> Productos;
    vector<Ventas*> ListaVentas;
    //ofstream archivo;
    Ventas VentaOut;

    LeerArchivo(ListaVentas);

    do {
        MainMenu();
        int MainOpcion;
        cin >> MainOpcion;
        switch (MainOpcion) {
            case 1:
                switchAdminPersonas(Personas);
            break;
            case 2:
                switchAdminProductos(Productos);
            break;
            case 3:
                switchAdminVentas(Productos, ListaVentas, Personas);
            break;
            default:
                return 0;
            break;
        } 
    } while (true);

    getchar();
}