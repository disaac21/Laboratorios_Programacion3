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

int main() {

	string dec1, dec2, cadN, cadM, operacion;
	cout << ">>N=";
	cin >> dec1;
	cout << ">>M=";
	cin >> dec2;

	string mod1 = "|";
	int total = 0;
	for (int i = 0; i < dec1.length(); i++)	{
		if (dec1.at(i) == ',' || dec1.at(i) == '[' || dec1.at(i) == ']') {
			total++;
		}
	}
	cout << "total: " << total << endl; //-1
	int raiz = sqrt(total - 1);     int cont = 0;     string number = "";
	for (int i = 1; i < dec1.length()-1; i++) {
		if (dec1.at(i) == ',') {
			mod1 += number;
			mod1 += " ";
			number = "";
			++cont;
		} else {
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
	cout << mod1;


	/*StringObj* StringN = new StringObj(dec1);
	Node* N = new Node(StringN);*/

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