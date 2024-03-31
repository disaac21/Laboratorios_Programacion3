#pragma once
#include <iostream>
#include<string>
#include<vector>
#include "Producto.h"
using namespace std;

class Ventas{
    vector<Producto*> Productos;
    double total;

    public:
        Ventas();
        Ventas(vector<Producto*>, double);
        ~Ventas();

        double gettotal() const;
        vector<Producto*> getProductos() const;

		void setProductos(vector<Producto*>);
        void settotal(double);
        
        void imprimir()const;
};