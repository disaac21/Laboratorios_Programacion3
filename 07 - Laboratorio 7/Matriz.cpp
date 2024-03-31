#include "Matriz.h"
#include <iostream>
#include<string>
using namespace std;

Matriz::Matriz() {

}
Matriz::Matriz(vector<int> Lista, int Orden) {
    this->Lista = Lista;
    this->Orden = Orden;
}
Matriz::~Matriz(){

}

vector<int> Matriz::getLista() const {
    return Lista;
}
int Matriz::getOrden() const {
    return Orden;
}

void Matriz::setLista(vector<int> Lista){
    this->Lista = Lista;
}
void Matriz::setOrden(int Orden){
    this->Orden = Orden;
}
