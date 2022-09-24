#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Node.h"
#include "Object.h"
#include "Operator.h"
#include "Matriz.h"
#include "StringObj.h"
using namespace std;

int EncontrarTotal(string input) {
	int total = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) == ',' || input.at(i) == '[' || input.at(i) == ']') {
			total++;
		}
	}
	return total;
}

string FormatMatriz(int total, string dec1) {

	int raiz = sqrt(total);		int cont = 0;
	string number = "";			string mod1 = "| ";

	for (int i = 1; i < dec1.length() - 1; i++) {
		if (dec1.at(i) == ',') {
			mod1 += number;
			mod1 += " ";
			number = "";
			++cont;
		}
		else {
			number += dec1.at(i);
		}

		if (cont == raiz) {
			mod1 += "|";
			mod1 += "\n";
			mod1 += "| ";
			cont = 0;
		}
	}
	mod1 += number;
	mod1 += " ";
	number = "";
	mod1 += "|";

	return mod1;
}

int main() {

	string UserInputN, UserInputM, Third; char OperaChar;
	cout << ">>N="; cin >> UserInputN;
	cout << ">>M="; cin >> UserInputM;
	cout << ">>"; cin >> Third;


	//Matriz N
		//Find Total
		int TotalNumbersN = EncontrarTotal(UserInputN) - 1;
		//Formatear
		string MatrizN = FormatMatriz(TotalNumbersN, UserInputN);
		cout << MatrizN << endl; cout << "-------" << endl;
		//Creo Nodo
		StringObj* StringN = new StringObj(MatrizN);
		Node* N = new Node(StringN);

	//Operador Aritmetico
		OperaChar = Third.at(1);
		Operator* Opera = new Operator(OperaChar);
		Node* O = new Node(Opera);
		N->setNext(O);
	//Matriz M
		//Find Total
		int TotalNumbersM = EncontrarTotal(UserInputM) - 1;
		//Formatear
		string MatrizM = FormatMatriz(TotalNumbersM, UserInputM);
		cout << MatrizM << endl;
		//Creo Nodo
		StringObj* StringM = new StringObj(MatrizM);
		Node* M = new Node(StringM);
		N->getNext()->setNext(M);

		N->getData()->Print(); //N
		N->getNext()->getData()->Print(); //O
		N->getNext()->getNext()->getData()->Print(); //M

};