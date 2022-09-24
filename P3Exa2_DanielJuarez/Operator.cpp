#include "Operator.h"
#include <iostream>
using namespace std;

Operator::Operator()
{
}

Operator::Operator(char operacion) {
	this->operacion = operacion;
}

char Operator::getTipo() {
	return 'O';
}

Operator::~Operator()
{
}

void Operator::Print() {
	cout << this->operacion;
}