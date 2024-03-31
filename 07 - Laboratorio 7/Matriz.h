#pragma once
#include <iostream>
#include<string>
using namespace std;

class Matriz {
    vector<int> Lista;
    int Orden;

    public:
        Matriz();
        Matriz(vector<int> Lista, int Orden);
        ~Matriz();

        vector<int> getLista() const;
        int getOrden() const;

        void setLista(vector<int>);
        void setOrden(int);

};