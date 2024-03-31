#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {

    vector<string> Atributos;

    // for (int i = 0; i < argc; i++) {
    //     cout << i << "-" << argv[i] << endl;
    // }
    
    for (int i = 1; i < argc; i++) {
        Atributos.clear();
        string NombreArchivo = argv[i];

        ifstream CurrentArchivo(NombreArchivo, ios::in);
        if ( !CurrentArchivo ) {
            cerr << "No Se Pudo Abrir El Archivo " << NombreArchivo.substr(2, NombreArchivo.length()) << endl;
            exit( EXIT_FAILURE );
        }

        string TipoVar, NombreVar, Titulo;
        CurrentArchivo >> Titulo;
        //cout << "Titulo del Archivo: " << Titulo << endl;
        
        // -------------------------------------------------------------------------------------------

        string NombreH = Titulo + ".h";
        //cout << "Nombre del .h : " << NombreH << endl;
        ofstream OutPuntoH (NombreH, ios::out);
        if ( !OutPuntoH ) {
            cerr << "No Se Pudo Abrir El Archivo." << endl;
            exit( EXIT_FAILURE );
        }
        OutPuntoH << "#pragma once\n#include <iostream>\n#include<string>\n";

        string nombreinclude = "";
        for (int j = 1; j < argc; j++) {
            if (j == i) {
                
            } else {
                nombreinclude = argv[j];
                OutPuntoH << "#include \"" << nombreinclude.substr(2, nombreinclude.length()-6) << ".h\"\n";
            }
            
        }

        OutPuntoH << "using namespace std;\n\nclass " << Titulo << " {\n";
        string line;
        while (getline(CurrentArchivo, line)) {
            Atributos.push_back(line);
        }
        for (int i = 1; i < Atributos.size(); i++) {
            OutPuntoH << "    " << Atributos[i] << ";\n";
        }
        
        OutPuntoH << "\n    public:\n" << "        " << Titulo << "();" << endl << "        " << Titulo << "(";
        for (int i = 1; i < Atributos.size()-1; i++) {
            OutPuntoH << Atributos[i] << ", ";
        }
        for (int i = Atributos.size()-1; i < Atributos.size(); i++) {
            OutPuntoH << Atributos[i];
        }

        OutPuntoH << ");\n";
        OutPuntoH << "        ~" << Titulo << "();\n" << endl;

        CurrentArchivo.clear();
        CurrentArchivo.seekg(0, ios::beg);
        string currentpalabra = "";
        while (getline(CurrentArchivo, line)) {
            if (CurrentArchivo.tellg() != -1) {
                for (int i = 0; i < line.length(); i++) {
                currentpalabra += line.at(i);
                    if (line.at(i) == ' '){
                        OutPuntoH << "        " << currentpalabra << "get" << line.substr(i+1, line.length()) << "() const;\n";
                        break;
                    }
                }
            }
        currentpalabra = "";
        }

        CurrentArchivo.clear();
        CurrentArchivo.seekg(0, ios::beg);
        OutPuntoH << "\n";
        while (getline(CurrentArchivo, line)) {
            if (CurrentArchivo.tellg() != -1) {
                for (int i = 0; i < line.length(); i++) {
                currentpalabra += line.at(i);
                    if (line.at(i) == ' '){
                        OutPuntoH << "        " << "void set" << line.substr(i+1, line.length()) << "(" << currentpalabra.substr(0, currentpalabra.length()-1) << ");\n";
                        break;
                    }
                }
            }
        currentpalabra = "";
        }

        OutPuntoH << "\n};";

        // --------------------------------------------------------------------------------------------------------------------------

        string NombreCPP = Titulo + ".cpp";
        //cout << "Nombre del .cpp : " << NombreCPP << endl;
        ofstream OutPuntoCPP (NombreCPP, ios::out);
        if ( !OutPuntoCPP ) {
            cerr << "No Se Pudo Abrir El Archivo." << endl;
            exit( EXIT_FAILURE );
        }

        OutPuntoCPP << "#include \"" << Titulo << ".h\"\n#include <iostream>\n#include<string>\nusing namespace std;\n\n";

        OutPuntoCPP << Titulo << "::" << Titulo << "() {\n\n}\n";
        
        OutPuntoCPP << Titulo << "::" << Titulo << "(";
        for (int i = 1; i < Atributos.size()-1; i++) {
            OutPuntoCPP << Atributos[i] << ", ";
        }
        for (int i = Atributos.size()-1; i < Atributos.size(); i++) {
            OutPuntoCPP << Atributos[i];
        }
        OutPuntoCPP << ") {\n";

        CurrentArchivo.clear();
        CurrentArchivo.seekg(0, ios::beg);
        currentpalabra = "";
        while (getline(CurrentArchivo, line)) {
            if (CurrentArchivo.tellg() != -1) {
                for (int i = 0; i < line.length(); i++) {
                currentpalabra += line.at(i);
                    if (line.at(i) == ' '){
                        OutPuntoCPP << "    " << "this->" << line.substr(i+1, line.length()) << " = " << line.substr(i+1, line.length()) << ";\n";
                        break;
                    }
                }
            }
        currentpalabra = "";
        }
        OutPuntoCPP << "}\n";

        OutPuntoCPP << Titulo << "::~" << Titulo << "(){\n\n}\n\n";

        CurrentArchivo.clear();
        CurrentArchivo.seekg(0, ios::beg);
        currentpalabra = "";
        while (getline(CurrentArchivo, line)) {
            if (CurrentArchivo.tellg() != -1) {
                for (int i = 0; i < line.length(); i++) {
                currentpalabra += line.at(i);
                    if (line.at(i) == ' '){
                        OutPuntoCPP << currentpalabra << Titulo << "::" << "get" << line.substr(i+1, line.length()) << "() const {\n    return " << line.substr(i+1, line.length()) << ";\n}\n";
                        break;
                    }
                }
            }
        currentpalabra = "";
        }

        CurrentArchivo.clear();
        CurrentArchivo.seekg(0, ios::beg);
        OutPuntoCPP << "\n";
        while (getline(CurrentArchivo, line)) {
            if (CurrentArchivo.tellg() != -1) {
                for (int i = 0; i < line.length(); i++) {
                currentpalabra += line.at(i);
                    if (line.at(i) == ' '){
                        OutPuntoCPP << "void " << Titulo << "::" <<"set" << line.substr(i+1, line.length()) << "(" << currentpalabra.substr(0, currentpalabra.length()-1) << " " << line.substr(i+1, line.length()) << "){";
                        OutPuntoCPP << "\n    " << "this->" << line.substr(i+1, line.length()) << " = " << line.substr(i+1, line.length()) << ";\n}\n";
                        break;
                    }
                }
            }
        currentpalabra = "";
        }

    }
    //getchar();
}