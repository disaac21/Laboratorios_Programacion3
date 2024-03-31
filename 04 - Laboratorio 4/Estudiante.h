#pragma once
#include <string>
using namespace std;

class Estudiante {
	private:
		int e_ID;
		string e_nombre, e_apellido;

	public:
		Estudiante();
		Estudiante(string Nombre, string Apellido);
		~Estudiante();

		int getID() const;
		void setID(int);

		string getNombre() const;
		void setNombre(string);

		string getApellido() const;
		void setApellido(string);
};