// NOMBRE y APELLIDOS
// Daniel Fernández Ortiz
// Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Análisis del coste: en el caso peor el coste del algoritmo es O(N), donde N = v.size() - 1, porque cada llamada recursiva tiene coste lineal

void buscar(const vector<int>& v, int pos, int cantado, bool&tachado, int&n) {
    if (pos == (int)v.size() - 1) { // CB: ya se han comprobado todos los números
        tachado = ((pos + cantado) == v[pos]);
        if (tachado) {
            n = v[pos];
        }
    }
    else {
        tachado = ((pos + cantado) == v[pos]);
        if (!tachado) {
            pos++;
            buscar(v, pos, cantado, tachado, n);
        }
        else {
            n = v[pos];
        }
    }
}


bool resuelveCaso() {
    int size, temp, cantado, pos = 0, n;
    bool tachado = false;
    vector<int> vals;
    cin >> size >> cantado;
    //if (!cin) return false;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }
    buscar(vals, pos, cantado, tachado, n);
    if (tachado) {
        cout << n << "\n";
    }
    else {
        cout << "NO\n";
    }
    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}