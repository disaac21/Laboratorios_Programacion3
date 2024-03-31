#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int menu();

int* fillArray(int *PunteroArreglo, int TamanoArreglo, int MaxNumero) {
    srand(time(0));
    PunteroArreglo = new int[TamanoArreglo];
    for (int i = 0; i < TamanoArreglo; i++) {
        PunteroArreglo[i] = (rand() % 99);
    }
    return PunteroArreglo;
}

int* sort(int *PunteroArreglo, int TamanoArreglo, int NumVueltas){

    if (NumVueltas >= TamanoArreglo)
        return PunteroArreglo;

    int PosMenor = NumVueltas;
    int Ayuda = 0;
    int NumMenor = PunteroArreglo[NumVueltas];

        //Encuentra el Menor
        for (int i = NumVueltas; i < TamanoArreglo; i++) {
            if (NumMenor > PunteroArreglo[i]) {
                NumMenor = PunteroArreglo[i];
                PosMenor = i;
            }
        }

        //Intercambia Posiciones
        Ayuda = PunteroArreglo[PosMenor];
        PunteroArreglo[PosMenor] = PunteroArreglo[NumVueltas];
        PunteroArreglo[NumVueltas] = Ayuda;

        //Print
        cout << "\nIteracion: " << NumVueltas << endl;
        for (int i = 0; i < TamanoArreglo; i++) {
            cout << "[" << PunteroArreglo[i] << "] ";
        }
        
        sort(PunteroArreglo, TamanoArreglo, ++NumVueltas);
        
    
}

void OrdenamientoSimple() {
    cout << "Ingrese el Tamano del Arreglo: ";
    int TamanoArreglo;
    cin >> TamanoArreglo;
    int* ArregloPuntero = NULL;

    ArregloPuntero = fillArray(ArregloPuntero, TamanoArreglo, 99);

    int NumeroVueltas = 0;
    ArregloPuntero = sort(ArregloPuntero, TamanoArreglo, NumeroVueltas);

}
 // ------------------------------------------------------------------------------------------------------------------------------------

int* randoms(int* ListaNums, vector<string>ListaParticipantes, int NumDados) {
    srand(time(0));
    for (int i = 0; i < ListaParticipantes.size(); i++) {
        ListaNums[i] = (NumDados + (rand() % (NumDados * 6 - NumDados)));
    }
    return ListaNums;
}

void JuegoAzar() {
    int NumParticipantes, NumEliminar, NumDados;
    string NombreJugador;
    cout << "Ingrese el Numero de Participantes: ";
    cin >> NumParticipantes;
    cout << "Ingrese el Numero de Participantes a Eliminar Por Ronda: ";
    cin >> NumEliminar;
    cout << "Ingrese el Numero de Dados: ";
    cin >> NumDados;

    
    vector<string> ListaParticipantes;

    for (int i = 1; i <= NumParticipantes; i++) {
        cout << "Ingrese el Participante " << i << ": ";
        cin >> NombreJugador;
        ListaParticipantes.push_back(NombreJugador);
    }

    int NumeroRonda = 0;
    while (ListaParticipantes.size() > 1) {
        NumeroRonda++;
        //Reserva Memoria
        int* ListaNums = new int[ListaParticipantes.size()];
        /*ListaNums = new int[ListaParticipantes.size()];*/
        //Generar Randoms
        ListaNums = randoms(ListaNums, ListaParticipantes, NumDados);
        //cout por Rondas
        while (NumEliminar >= ListaParticipantes.size()) {
            NumEliminar--;
        }
        cout << endl << "Ronda: " << NumeroRonda << endl;
        for (int i = 0; i < ListaParticipantes.size(); i++) {
            cout << ListaParticipantes[i] << ": " << ListaNums[i] << endl;
        }

        //Eliminar
        int NumMenor = ListaNums[0];
        int PosMenor = 0;
        int enelaire = 0;
        for (int i = 0; i < NumEliminar; i++) {
            for (int j = 0; j < ListaParticipantes.size(); j++) {
                if (NumMenor > ListaNums[j]) {
                    NumMenor = ListaNums[j];
                    PosMenor = j;
                }
            }
            ListaNums[PosMenor] = 999;
            for (int i = PosMenor; i < ListaParticipantes.size(); i++) {
                enelaire = ListaNums[i];
                ListaNums[i] = ListaNums[i+1];
                ListaNums[i + 1] = ListaNums[i];
            }
            //Eliminar Jugador
            //auto remove = ListaParticipantes.begin() + PosMenor;
            cout << "Jugador Eliminado: " << ListaParticipantes[PosMenor] << endl;
            ListaParticipantes.erase(ListaParticipantes.begin() + PosMenor);
            NumMenor = ListaNums[0];
            PosMenor = 0;
        }
        cout << endl;
        //Liberar La Memoria
        delete ListaNums;
    }

    if (ListaParticipantes.size() == 1) {
        cout << "El Jugador Que Gano Fue: " << ListaParticipantes[0];
    }

}
// -------------------------------------------------------------------------------------------------------------------------------------
void ParkourExtremo() {
    vector<int> Parkour;
    int Input = 0;
    do
    {
        cout << "Ingrese un Numero: ";
        cin >> Input;
        while (Input < -1) {
            cout << "Solo Numeros Enteros No Negativos" << endl;
            cout << "Ingrese un Numero: ";
            cin >> Input;
        }
        if (Input >= 0) {
            Parkour.push_back(Input);
        }
    } while (Input != -1);

    cout << "vector: ";
    for (int i = 0; i < Parkour.size(); i++) {
        cout << "[" << Parkour[i] << "]";
    }

    cout << endl;
    vector<int> saltos;
    int posicion, num;
    posicion = 0;
    num = Parkour[posicion];
    bool llego = true;
    while (posicion < Parkour.size()) {
        num = Parkour[posicion];
        cout << "Pos: " << posicion << " Num: " << num << endl;
        if (posicion + num < Parkour.size()) {
            cout << "Jump\n";
            saltos.push_back(num);
        } else {
            cout << "No Mas Jumping\n";
            llego = false;
        }
        posicion = posicion + num;
        /*srand(time(0));
        int brinco = (1 + (rand() % (posicion * 1 - 1)));
        cout << brinco;
        saltos.push_back(brinco);
        posicion = posicion + 1;*/
    }
    if (llego) {
        cout << "saltos: ";
        for (int i = 0; i < saltos.size(); i++) {
            cout << "[" << saltos[i] << "]";
        }
    }
    else {
        cout << "No Llego, Lo Siento";
    }
}


int main() {

    int Continue = 0;
    int Ejercicio;

    menu();
    cin >> Ejercicio;

    while (Continue == 0) {

        switch (Ejercicio) {
        case 0:
            Continue = 1;
            break;

        case 1:
            cout << "\n";
            OrdenamientoSimple();
            cout << "\n\nDesea Continuar? 0-Si 1-No\n";
            cin >> Continue;
            break;

        case 2:
            cout << "\n";
            ParkourExtremo();
            cout << "\n\nDesea Continuar? 0-Si 1-No\n";
            cin >> Continue;
            break;

        case 3:
            cout << "\n";
            JuegoAzar();
            cout << "\n\nDesea Continuar? 0-Si 1-No\n";
            cin >> Continue;
            break;
        }
    }
}

int menu() {
        cout << "0. Salir" << endl;
        cout << "1. Ordenamiento" << endl;
        cout << "2. Parkour Extremo" << endl;
        cout << "3. Juego de azar" << endl;
        cout << "Ingrese una opcion: ";
        return 0;
}