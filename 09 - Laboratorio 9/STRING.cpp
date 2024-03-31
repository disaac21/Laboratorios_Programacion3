#include "STRING.h"

#include "CHAR.h"
#include <iostream>
#include<string>
using namespace std;

STRING::STRING() {

}
STRING::STRING(string cadena) {
    this->cadena = cadena;
}

STRING::~STRING(){

}

string STRING::getcadena() const {
    return cadena;
}

void STRING::setcadena(string cadena){
    this->cadena = cadena;
}

// --------------------------------------------

void STRING::operator << (const string&stringparam) {
    this->cadena = stringparam;
}

void STRING::operator << (const STRING&stringparam) {
    this->cadena = stringparam.getcadena();
}

void STRING::operator << (const char&stringparam) {
    this->cadena = ((char)stringparam);
}

void STRING::operator << (const CHAR&stringparam) {
    this->cadena = ((char)stringparam.getcaracter());
}

void STRING::operator!(){
    cout << this->getcadena();
}

STRING STRING::operator+(const string&stringparam){
    string mandar = (this->getcadena() + stringparam);
    return(STRING(mandar));
}

STRING STRING::operator+(const STRING&stringparam){
    string mandar = (this->getcadena() + stringparam.getcadena());
    return(STRING(mandar));
}

STRING STRING::operator+(const char&stringparam){
    string mandar = (this->getcadena() + stringparam);
    return(STRING(mandar));
}

STRING STRING::operator+(const CHAR&stringparam){
    string mandar = (this->getcadena() + stringparam.getcaracter());
    return(STRING(mandar));
}

STRING STRING::operator* (int charparam){
    string enviar = "";
    for (int i = 0; i < charparam; i++) {
        enviar += this->cadena;
    }
    return (STRING(enviar));
}

STRING STRING::operator* (INTEGER charparam){
    string enviar = "";
    for (int i = 0; i < charparam.getentero(); i++) {
        enviar += this->cadena;
    }
    return (STRING(enviar));
}

CHAR STRING::operator[](int stringparam){
    char carac = this->cadena.at(stringparam);
    return ((CHAR)carac);
}

CHAR STRING::operator[](INTEGER stringparam){
    char carac = this->cadena.at(stringparam.getentero());
    return ((CHAR)carac);
}

// ----------------------------------------------------------------------------

STRING STRING::operator()(int num){
    string mandar = "";
    int hastaelfinal = this->cadena.length();
    // -1 + cadena.length();
    if (num < 0) {
        int startingpoint = (-1 + cadena.length());
        int startsubstring = (num + cadena.length());
        mandar = this->cadena.substr(startsubstring, hastaelfinal);
    } else {
        mandar = this->cadena.substr(num, hastaelfinal);
    }
    return mandar;
}

STRING STRING::operator()(INTEGER num){
    string mandar = "";
    int hastaelfinal = this->cadena.length();
    // -1 + cadena.length();
    if (num.getentero() < 0) {
        int startingpoint = (-1 + cadena.length());
        int startsubstring = (num.getentero() + cadena.length());
        mandar = this->cadena.substr(startsubstring, hastaelfinal);
    } else {
        mandar = this->cadena.substr(num.getentero(), hastaelfinal);
    }
    return mandar;
}

STRING STRING::operator()(int num, int limit){
    string mandar = "";
    int hastaelfinal = this->cadena.length();
    // -1 + cadena.length();
    if (num < 0) {
        int startingpoint = (-1 + cadena.length());
        int startsubstring = (num + cadena.length());
        if(limit < 0) {
            int endsubstring = (limit + cadena.length());
            mandar = this->cadena.substr(startsubstring, endsubstring);
        } else {
            mandar = this->cadena.substr(startsubstring, hastaelfinal);
        }
    } else {
        mandar = this->cadena.substr(num, limit);
    }
    return mandar;
}
STRING STRING::operator()(INTEGER num, INTEGER limit){
    string mandar = "";
    int hastaelfinal = this->cadena.length();
    // -1 + cadena.length();
    if (num.getentero() < 0) {
        int startingpoint = (-1 + cadena.length());
        int startsubstring = (num.getentero() + cadena.length());
        if(limit.getentero() < 0) {
            int endsubstring = (limit.getentero() + cadena.length());
            mandar = this->cadena.substr(startsubstring, endsubstring);
        } else {
            mandar = this->cadena.substr(startsubstring, hastaelfinal);
        }
    } else {
        mandar = this->cadena.substr(num.getentero(), limit.getentero());
    }
    return mandar;
}

STRING STRING::operator()(int num, INTEGER limit) {
    string mandar = "";
    int hastaelfinal = this->cadena.length();
    // -1 + cadena.length();
    if (num < 0) {
        int startingpoint = (-1 + cadena.length());
        int startsubstring = (num + cadena.length());
        if(limit.getentero() < 0) {
            int endsubstring = (limit.getentero() + cadena.length());
            mandar = this->cadena.substr(startsubstring, endsubstring);
        } else {
            mandar = this->cadena.substr(startsubstring, hastaelfinal);
        }
    } else {
        mandar = this->cadena.substr(num, limit.getentero());
    }
    return mandar;
}

STRING STRING::operator()(INTEGER num, int limit) {
    string mandar = "";
    int hastaelfinal = this->cadena.length();
    // -1 + cadena.length();
    if (num.getentero() < 0) {
        int startingpoint = (-1 + cadena.length());
        int startsubstring = (num.getentero() + cadena.length());
        if(limit < 0) {
            int endsubstring = (limit + cadena.length());
            mandar = this->cadena.substr(startsubstring, endsubstring);
        } else {
            mandar = this->cadena.substr(startsubstring, hastaelfinal);
        }
    } else {
        mandar = this->cadena.substr(num.getentero(), limit);
    }
    return mandar;
}
// -----------------------------------------------------------------------------

bool STRING::operator==(string cadparam){
    // // int truefalse;
    // // bool igual = true;
    // // // if (this->cadena != cadparam) {
    // // //     igual = false;
    // // // }
    // // for (int i = 0; i < this->cadena.length(); i++) {
        
    // // }
    
    // // truefalse = this->cadena.compare(cadparam);
    // // if (truefalse == -1) {
        
    // // }
    // return igual;
    if (this->cadena == cadparam) {
        return true;
    } else {
        return false;
    }
    
}
bool STRING::operator==(char param) {
    string para2 = to_string(param);
    if (this->cadena == para2) {
        return true;
    } else {
        return false;
    }
}

bool STRING::operator==(STRING param) {
    if (this->cadena == param.getcadena()) {
        return true;
    } else {
        return false;
    }
}

bool STRING::operator==(CHAR param) {
    string para2 = to_string(param.getcaracter());
    if (this->cadena == para2) {
        return true;
    } else {
        return false;
    }
}

// -----------------------------------------------------------------------------

bool STRING::operator |(string stringparam) {
    int truefalse;
    bool esta = true;
    truefalse = this->cadena.find(stringparam);
    if (truefalse == -1) {
        esta = false;
    }
    
    return esta;
}

bool STRING::operator |(STRING stringparam) {
    int truefalse;
    bool esta = true;
    truefalse = this->cadena.find(stringparam.getcadena());
    if (truefalse == -1) {
        esta = false;
    }
    
    return esta;
}

bool STRING::operator |(char stringparam) {
    int truefalse;
    bool esta = true;
    truefalse = this->cadena.find(stringparam);
    if (truefalse == -1) {
        esta = false;
    }
    
    return esta;
}

bool STRING::operator |(CHAR stringparam) {
    int truefalse;
    bool esta = true;
    truefalse = this->cadena.find(stringparam.getcaracter());
    if (truefalse == -1) {
        esta = false;
    }
    
    return esta;
}