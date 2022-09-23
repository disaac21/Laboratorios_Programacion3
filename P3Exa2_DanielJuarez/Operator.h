#pragma once
#include "Object.h"

class Operator : public Object {

	char operacion;

	public:
		Operator();
		Operator(char);
		~Operator();

		char getTipo();

};