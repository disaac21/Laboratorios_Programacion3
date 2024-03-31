#pragma once
#include <string>
using namespace std;

class Negocio {
	private:
		int n_ID;
		string n_nombre;

	public:
		Negocio();
		Negocio(string Nombre);
		~Negocio();

		int getID() const;
		void setID(int);

		string getNombre() const;
		void setNombre(string);
};

