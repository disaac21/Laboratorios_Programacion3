#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

class Matriz : public Object {
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

