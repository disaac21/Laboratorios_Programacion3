#pragma once
#include <iostream>
using namespace std;

class Paquete {
	private:
		int IDPaq;
		string DescPaq;
		string DirPaq;
		int diasBodegaPaq;
		double DistanciaPaq;
		bool EntregadoPaq;

	public:
		Paquete();
		Paquete(int ID, string Descripcion, string Direccion, int DiasBodega, double Distancia, bool Entregado);
		~Paquete();

		int getID() const;
		void setID(int);

		string getDescripcion() const;
		void setDescripcion(string);

		string getDireccion() const;
		void setDireccion(string);

		int getDiasBodega() const;
		void setDiasBodega(int);

		double getDistancia() const;
		void setDistancia(double);

		bool getEntregado() const;
		void setEntregado(bool);

};