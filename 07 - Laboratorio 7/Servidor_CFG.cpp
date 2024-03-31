#include "Servidor_CFG.h"
#include <iostream>
#include<string>
using namespace std;

Servidor_CFG::Servidor_CFG() {

}
Servidor_CFG::Servidor_CFG(char Nombre, int Memoria_GB, int Disco_GB, int Red_Mb) {
    this->Nombre = Nombre;
    this->Memoria_GB = Memoria_GB;
    this->Disco_GB = Disco_GB;
    this->Red_Mb = Red_Mb;
}
Servidor_CFG::~Servidor_CFG(){

}

char Servidor_CFG::getNombre() const {
    return Nombre;
}
int Servidor_CFG::getMemoria_GB() const {
    return Memoria_GB;
}
int Servidor_CFG::getDisco_GB() const {
    return Disco_GB;
}
int Servidor_CFG::getRed_Mb() const {
    return Red_Mb;
}

void Servidor_CFG::setNombre(char Nombre){
    this->Nombre = Nombre;
}
void Servidor_CFG::setMemoria_GB(int Memoria_GB){
    this->Memoria_GB = Memoria_GB;
}
void Servidor_CFG::setDisco_GB(int Disco_GB){
    this->Disco_GB = Disco_GB;
}
void Servidor_CFG::setRed_Mb(int Red_Mb){
    this->Red_Mb = Red_Mb;
}
