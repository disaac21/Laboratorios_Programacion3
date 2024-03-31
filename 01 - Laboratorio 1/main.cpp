#include <iostream>
using namespace std;

int main() {
    //no cambiar numeracion ni opciones del menu
    //con los otros dos menus no incluidos aqui, favor mantener la numeracion que sale en las instrucciones
    cout << "0. Salir" << endl;
    cout << "1. Calculo de areas" << endl;
    cout << "2. Calculo de volumenes" << endl;
    //continuar con el desarollo

    cout << "Ingrese una Opcion: ";
    int MainMenu;
    cin >> MainMenu;

    switch (MainMenu) {

    case 1:
        cout << endl << "1. Area de un Triangulo" << endl << "2. Area de un Rectangulo" << endl;
        cout << "3. Area de un Circulo" << endl << "4. Area de un Trapecio" << endl;
        cout << "Ingrese una Opcion: ";
        int MenuAreas;
        cin >> MenuAreas;
        cout << endl;

        switch (MenuAreas) {

            double Base, Height, Radio;
        case 1: //Triangulo
            double AreaTriangulo;
            cout << "Ingrese la Base: ";
            cin >> Base;
            cout << "Ingrese el Altura: ";
            cin >> Height;
            AreaTriangulo = (Base * Height) / 2;
            cout << endl << "El Area del Triangulo es " << AreaTriangulo << endl;
            break;

        case 2: //Rectangulo
            double AreaRectangulo;
            cout << "Ingrese la Base: ";
            cin >> Base;
            cout << "Ingrese el Altura: ";
            cin >> Height;
            AreaRectangulo = Base * Height;
            cout << endl << "El Area del Rectangulo es " << AreaRectangulo << endl;
            break;

        case 3: //Circulo
            double AreaCirculo;
            cout << "Ingrese el Radio: ";
            cin >> Radio;
            AreaCirculo = 3.1416 * (Radio * Radio);
            cout << endl << "El Area del Circulo es " << AreaCirculo << endl;
            break;

        case 4:
            double AreaTrapecio, BaseM;
            cout << "Ingrese la Primera Base: ";
            cin >> Base;
            cout << "Ingrese la Segunda Base: ";
            cin >> BaseM;
            cout << "Ingrese el Altura: ";
            cin >> Height;
            AreaTrapecio = ((Base + BaseM) * Height) / 2;
            cout << endl << "El Area del Trapecio es " << AreaTrapecio << endl;
            break;
        }
        break;

    case 2:
        cout << endl << "1. Volumen de un Cubo" << endl << "2. Volumen de un Cono" << endl;
        cout << "3. Volumen de un Cilindro" << endl << "4. Volumen de una Esfera" << endl;
        cout << "Ingrese una Opcion: ";
        int MenuVols;
        cin >> MenuVols;
        cout << endl;

        switch (MenuVols) {

        case 1:
            double VolCubo, Area;
            cout << "Ingrese el Area del Cubo: ";
            cin >> Area;
            VolCubo = Area * Area * Area;
            cout << endl << "El Volumen del Cubo es " << VolCubo << endl;
            break;

        case 2:
            double VolCono, RadioCono, HeightCono;
            cout << "Ingrese el Valor del Radio: ";
            cin >> RadioCono;
            cout << "Ingrese el Altura: ";
            cin >> HeightCono;
            VolCono = ((3.1416 * (RadioCono * RadioCono)) / 3) * HeightCono;
            cout << endl << "El Volumen del Cono es " << VolCono << endl;
            break;

        case 3:
            double VolCil, RadioCil, HeightCil;
            cout << "Ingrese el Valor del Radio: ";
            cin >> RadioCil;
            cout << "Ingrese el Altura: ";
            cin >> HeightCil;
            VolCil = (3.1416 * (RadioCil * RadioCil)) * HeightCil;
            cout << "El Volumen del Cilindro es " << VolCil << endl;
            break;

        case 4:
            double VolEsfera, RadioEsfera;
            cout << "Ingres el valor del Radio: ";
            cin >> RadioEsfera;
            VolEsfera = (4.00 / 3.00) * 3.1416 * (RadioEsfera * RadioEsfera * RadioEsfera);
            cout << "El VOlumen de la Esfera es " << VolEsfera << endl;
            break;
        }
        break;
    }

}