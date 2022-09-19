// NOMBRE Y APELLIDOS: Juan Embid Sánchez y Daniel Fernández Ortiz Grupo 2ºE

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ALTURAS = 100000; 

int contarAbadias(const int alturas[], int abadias) { 
    int cont = 1, max = abadias - 1;

    for(int i = (abadias - 1); i > 0; i--) { // Al haber un >= 0 en vez de un > 0, se accedía a la posición alturas[-1]
        if(alturas[i - 1] > alturas[max]) {
            max = i - 1; // En max se guardaba la altura de la montaña en vez de la posición de la montaña más alta
            cont++;
        }
    }

    return cont;
}

bool resuelveCaso() {
    int alturas[MAX_ALTURAS];
    int abadias;

    cin >> abadias;
    if (abadias == 0)
        return false;

    for (int i = 0; i < abadias; i++)
            cin >> alturas[i];

    cout << contarAbadias(alturas, abadias) << endl;

    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}
