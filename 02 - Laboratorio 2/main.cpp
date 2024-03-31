#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

#define PupusasSize 6
#define PaliSize 7

using namespace std;

void ordenamientoPupusa(int ListaPupusas[], int VueltasSize) {
	int VueltasSize2;
	int BigPupusa;
	int PosLista;
	int Aid;
	BigPupusa = 0;
	PosLista = 0;
	Aid = 0;
	for (int i = 0; i <= VueltasSize; i++) {
		if (ListaPupusas[i] > BigPupusa) {
			BigPupusa = ListaPupusas[i];
			PosLista = i;
		}
	}
	for (int i = PosLista; i >= 0; i--) {
		ListaPupusas[i] = ListaPupusas[i - 1];
	}
	ListaPupusas[0] = BigPupusa;
}

void darVueltaAPupusa(int ListaPupusas[], int InicioPupusas, int LastPupusa) {
	int PupusaEnElAire;
	while (InicioPupusas <= LastPupusa) {
		PupusaEnElAire = ListaPupusas[InicioPupusas];
		ListaPupusas[InicioPupusas] = ListaPupusas[LastPupusa];
		ListaPupusas[LastPupusa] = PupusaEnElAire;
		InicioPupusas++;
		LastPupusa--;
	}
}

void palindromidad(int ListaNumeros[], int InicioNumeros, int FinalNumeros) {

	cout << "Es palindromo ";
	if (ListaNumeros[InicioNumeros] == ListaNumeros[FinalNumeros]) {
		palindromidad(ListaNumeros, InicioNumeros + 1, FinalNumeros - 1);
	} else {
		cout << "No es palindromo ";
	}
}

int main() {

	int Continue = 0;
	int Ejercicio = 0;

	while (Continue == 0) {

		cout << "Menu\n1. Ejercicio 1\n2. Ejercicio 2\n3. Salir\n";
		cin >> Ejercicio;

		switch (Ejercicio) {

		case 1:

			int PupusasList[PupusasSize];
			srand(time(0));
			bool esPrimo;
			esPrimo = false;
			bool MainWhile;
			MainWhile = false;

			for (int i = 0; i < PupusasSize; i++) {
				MainWhile = false;
				esPrimo = false;
				while (!MainWhile) {

					int NumPrimo = (rand() % 25);

					if (NumPrimo == 0 || NumPrimo == 1 || NumPrimo == 2 || NumPrimo == 3) {
						esPrimo = true;
						PupusasList[i] = NumPrimo;
					}

					if (!esPrimo) {
						for (int j = 2; j <= NumPrimo / 2; j++) {
							if (NumPrimo % j == 0) {
								esPrimo = false;
								break;
							}
							else {
								esPrimo = true;
							}
						}
					}

					if (esPrimo) {
						PupusasList[i] = NumPrimo;
						MainWhile = true;
					}

				}

			}



			int VueltasSize;
			VueltasSize = PupusasSize;
			for (int i = 0; i < PupusasSize; i++) {

				/*cout << "\nLista Antes\n";
				for (int i = 0; i < PupusasSize; i++) {
					cout << PupusasList[i] << " ";
				}*/

				ordenamientoPupusa(PupusasList, VueltasSize - (i + 1));

				/*cout << "\nLista Ordenamiento\n";
				for (int i = 0; i < PupusasSize; i++) {
					cout << PupusasList[i] << " ";
				}*/

				darVueltaAPupusa(PupusasList, 0, VueltasSize - (i + 1));
			}

			/*cout << "\nLista Despues\n";*/
			for (int i = 0; i < PupusasSize; i++) {
				cout << PupusasList[i] << " ";
			}



			cout << "\nDesea Continuar? 0-Si 1-No\n";
			cin >> Continue;
			break;

		case 2:
			int ListaPali[PaliSize];
			int NumPali;

			for (int i = 0; i < PaliSize; i++) {
				cout << "Ingrese el Num: ";
				cin >> NumPali;
				ListaPali[i] = NumPali;
			}

			/*for (int i = 0; i < PaliSize; i++) {
				cout << ListaPali[i] << " ";
			}*/

			palindromidad(ListaPali, 0, PaliSize - 1);

			cout << "\nDesea Continuar? 0-Si 1-No\n";
			cin >> Continue;
			break;

		case 3:
			cout << "Salir\n";
			Continue = 1;
			break;

		}

	}

}