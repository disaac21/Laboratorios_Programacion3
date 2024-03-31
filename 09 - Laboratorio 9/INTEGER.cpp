#include "INTEGER.h"
#include <iostream>
#include<string>
using namespace std;

INTEGER::INTEGER() {
    this->entero=0;
}
INTEGER::INTEGER(int entero) {
    this->entero = entero;
}
INTEGER::~INTEGER(){

}

int INTEGER::getentero() const {
    return entero;
}

void INTEGER::setentero(int entero){
    this->entero = entero;
}

// ----------------------------------------------

void INTEGER::operator << (const int&enteroparam) {
    this->entero = enteroparam;
}

void INTEGER::operator << (const INTEGER&enteroparam) {
    this->entero = enteroparam.getentero();

}

void INTEGER::operator!(){
    cout << this->getentero() << endl;
}

INTEGER INTEGER::operator+(const int&enteroparam){
    INTEGER send = (this->getentero() + enteroparam);
    return send;
}

INTEGER INTEGER::operator+(const INTEGER&enteroparam){
    INTEGER send = (this->getentero() + enteroparam.getentero());
    return send;
}

INTEGER INTEGER::operator-(const int&enteroparam){
    INTEGER send = (this->getentero() - enteroparam);
    return send;
}

INTEGER INTEGER::operator-(const INTEGER&enteroparam){
    INTEGER send = (this->getentero() - enteroparam.getentero());
    return send;
}

INTEGER INTEGER::operator*(const int&enteroparam){
    INTEGER send = (this->getentero() * enteroparam);
    return send;
}

INTEGER INTEGER::operator*(const INTEGER&enteroparam){
    INTEGER send = (this->getentero() * enteroparam.getentero());
    return send;
}

INTEGER INTEGER::operator/(const int&enteroparam){
    INTEGER send = (this->getentero() / enteroparam);
    return send;
}

INTEGER INTEGER::operator/(const INTEGER&enteroparam){
    INTEGER send = (this->getentero() / enteroparam.getentero());
    return send;
}

INTEGER INTEGER::operator%(const int&enteroparam){
    INTEGER send = (this->getentero() % enteroparam);
    return send;
}

INTEGER INTEGER::operator%(const INTEGER&enteroparam){
    INTEGER send = (this->getentero() % enteroparam.getentero());
    return send;
}

INTEGER INTEGER::operator^(const int&enteroparam){
    INTEGER acum = this->getentero();
    for (int i = 1; i < enteroparam; i++) {
        // !acum;
        acum = acum * this->getentero();
    }
    return acum;
}
    
INTEGER INTEGER::operator^(const INTEGER&enteroparam){
    INTEGER acum = this->getentero();
    for (int i = 1; i < enteroparam.getentero(); i++) {
        // !acum;
        acum = acum * this->getentero();
    }
    return acum;
}

INTEGER& INTEGER::operator++(){
    // INTEGER send = (1 + this->getentero());
    this->entero = this->entero + 1;
    return *this;
}

INTEGER& INTEGER::operator--(){
    this->entero = this->entero -1;
    // INTEGER send = (1 - this->getentero());
    return *this;
}