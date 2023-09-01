/*
Autores: Juan Jose Álvarez y  Daniel Sandoval
Fecha: 08-2023
Tema: Manejo de Estructuras Lineales
Objetivo:  El diseño del programa debe considerar el uso de al menos dos tipos diferentes de estructuras lineales (listas, pilas o colas).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " archivo.txt" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    inputFile.ignore();  // Ignorar el salto de línea

    string subcadena;
    getline(inputFile, subcadena);

    string alrevez = subcadena;
    reverse(alrevez.begin(), alrevez.end());

    int numero_linea = 1;
    string line;


    vector<pair<int, string>> comienzan_con;
    vector<pair<int, string>> contienen;
    vector<pair<int, string>> contienen_invertida;


    while (getline(inputFile, line)) {
        vector<string> words;
        string word;

        for (char c : line) {
            if (isalnum(c)) {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        for (const string& w : words) {
            if (w.find(subcadena) == 0) {
                comienzan_con.push_back(make_pair(numero_linea, w));
                // cout << "Comienza con subcadena: " << w << " (línea " << numero_linea << ")" << endl;
            }

            if (w.find(subcadena) != string::npos) {
                contienen.push_back(std::make_pair(numero_linea, w));

                // cout << "Contiene subcadena: " << w << " (línea " << numero_linea << ")" << endl;
            }

            
            if (w.find(alrevez) != string::npos) {
                contienen_invertida.push_back(std::make_pair(numero_linea, w));

                // cout << "Contiene subcadena invertida: " << w << " (línea " << numero_linea << ")" << endl;
            }
        }

        numero_linea++;
    }

    cout << endl<< "Hay "<< comienzan_con.size()<< " palabras que comienzan por "<< subcadena <<  endl;
    for (const auto& elemento : comienzan_con) {
        cout << "Linea " << elemento.first << ": " << elemento.second << std::endl;
    }

    cout << endl<< "Hay "<< contienen.size()<< " palabras que contienen: "<< subcadena <<  endl;
    for (const auto& elemento : contienen) {
        cout << "Linea " << elemento.first << ": " << elemento.second << std::endl;
    }

    cout << endl<< "Hay "<< contienen_invertida.size()<< " palabras que comienzan por: "<< alrevez <<  endl;
    for (const auto& elemento : contienen_invertida) {
        cout << "Linea " << elemento.first << ": " << elemento.second << std::endl;
    }

    inputFile.close();

    return 0;
}
