#include "Operator.h"
#include <iostream>
#include<string>
using namespace std;

Operator::Operator() {

}
Operator::Operator(char operacion) {
    this->operacion = operacion;
}
Operator::~Operator(){

}

char Operator::getoperacion() const {
    return operacion;
}

void Operator::setoperacion(char operacion){
    this->operacion = operacion;
}
