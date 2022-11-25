// NOMBRE Y APELLIDOS 
// Daniel Fern�ndez Ortiz
// Juan Embid S�nchez
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct strange {
    int sumaPares;
    int sumaImpares;
    int productoPares;
    int productoImpares;
};

// mitad izq: suma pares + producto impares
// mitad der: suma impares + producto pares
bool extrano(const vector<int>& v, int ini, int fin, strange& ex) {
    int m;
    if (v.empty()) // CB: 0 elementos
        return true;
    else if (ini == fin) { // CB: 1 elemento
        if (v.at(ini) % 2 == 0) { 
            ex.sumaPares = v.at(ini);
            ex.productoImpares = 1;
            ex.sumaImpares = 0;
            ex.productoPares = v.at(ini);
        }
        else {
            ex.sumaPares = 0;
            ex.productoImpares = v.at(ini);
            ex.sumaImpares = v.at(ini);
            ex.productoPares = 1;
        }
    return true;
    }
    else { // CR
        m = (ini + fin) / 2;
        strange ex2;
        extrano(v, ini, m, ex); // izquierda
        if (ex.sumaPares + ex.productoImpares <= ex.sumaImpares + ex.productoPares) {
            extrano(v, m + 1, fin, ex2); // derecha
        }
        return (ex.sumaPares + ex.productoImpares <= ex2.sumaImpares + ex2.productoPares);
    }
}

void resuelveCaso() {
    vector<int> vals;
    strange ex;
    int size, temp, c, f;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }
    c = 0; f = (int)vals.size() - 1;
    if (extrano(vals, c, f, ex))
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
