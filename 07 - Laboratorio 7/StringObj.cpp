#include "StringObj.h"
#include <iostream>
#include<string>
using namespace std;

StringObj::StringObj() {

}
StringObj::StringObj(string cadena) {
    this->cadena = cadena;
}
StringObj::~StringObj(){

}

string StringObj::getcadena() const {
    return cadena;
}

void StringObj::setcadena(string cadena){
    this->cadena = cadena;
}
