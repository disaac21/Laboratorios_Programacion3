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
	string number = "";			string mod1 = "|";

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
			mod1 += "|";
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

	string UserInputN, UserInputM;
	cout << ">>N="; cin >> UserInputN;
	cout << ">>M="; cin >> UserInputM;

	//Matriz N
		//Find Total
		int TotalNumbers = EncontrarTotal(UserInputN) - 1;
		//Formatear
		string mod1 = FormatMatriz(TotalNumbers, UserInputN);
		cout << mod1;


	StringObj* StringN = new StringObj(mod1);
	Node* N = new Node(StringN);

	cout << endl << N->getData();

	/*Matriz MatN(Vector, Orden);
	Node* N = new Node();*/

	//for (int i = 0; i < dec1.length(); i++) {
	//	/*if (dec1.at(i) == ',' || dec1.at(i) == '[' || dec1.at(i) == ']') {
	//		dec1.at(i) = ' ';
	//	}*/
	//	if (dec1.at(i) == '[') {

	//	}
	//}
	
	//Node* N = new Node((Object * (MatrizN));


	/*cout << ">>" << dec1.at(0) << " operator " << dec2.at(0) << endl;
	cout << "  =" << endl << "  MATRIZ" << endl << endl;*/

};