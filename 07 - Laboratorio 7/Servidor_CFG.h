#pragma once
#include <iostream>
#include<string>
using namespace std;

class Servidor_CFG {
    char Nombre;
    int Memoria_GB;
    int Disco_GB;
    int Red_Mb;

    public:
        Servidor_CFG();
        Servidor_CFG(char Nombre, int Memoria_GB, int Disco_GB, int Red_Mb);
        ~Servidor_CFG();

        char getNombre() const;
        int getMemoria_GB() const;
        int getDisco_GB() const;
        int getRed_Mb() const;

        void setNombre(char);
        void setMemoria_GB(int);
        void setDisco_GB(int);
        void setRed_Mb(int);

};