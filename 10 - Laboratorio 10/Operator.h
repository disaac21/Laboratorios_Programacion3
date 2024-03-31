#pragma once
#include "Object.h"
#include <iostream>

class Operator : public Object {

	char operacion;

	public:
		Operator();
		Operator(char);
		~Operator();

		char getTipo();

		void Print();
};