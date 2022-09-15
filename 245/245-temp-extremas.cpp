// NOMBRE y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_TEMPERATURAS = 10000;

int picos(const int temperaturas[], int tamano) {
    int cont_picos = 0; 
    for (int i = 1; i < tamano - 1; i++) { // Como los extremos no pueden ser picos, no se tienen en cuenta
        if ((temperaturas[i - 1] < temperaturas[i]) && (temperaturas[i + 1] < temperaturas[i])) { // Si se da la condición de que la temperatura en la posición i es un pico, se incrementa el contador de picos
            cont_picos++;
        }
    }
    return cont_picos;
}

int valles(const int temperaturas[], int tamano) {
    int cont_valles = 0; 
    for (int i = 1; i < tamano - 1; i++) { // Como los extremos no pueden ser valles, no se tienen en cuenta 
        if ((temperaturas[i - 1] > temperaturas[i]) && (temperaturas[i + 1] > temperaturas[i])) { // Si se da la condición de que la temperatura en la posición i es un valle, se incrementa el contador de valles
            cont_valles++;
        }
    }
    return cont_valles;
}

void resuelveCaso() {
    int temp;
    int num_temps = 0; // Variable que guarda el número de temperaturas
    int temperaturas[MAX_TEMPERATURAS];

    cin >> num_temps;
    for (int i = 0; i < num_temps; i++) {
        cin >> temp;
        temperaturas[i] = temp;
    }

    cout << picos(temperaturas, num_temps) << " " << valles(temperaturas, num_temps) << endl;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    ifstream in("in.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
    /*ofstream out("out.txt");
    auto coutbuf = cout.rdbuf(out.rdbuf());*/
#endif
    unsigned int numCasos;
    cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    //cout.rdbuf(coutbuf);
    //system("PAUSE");
#endif
    return 0;
}