// NOMBRE Y APELLIDOS 
// Daniel Fern�ndez Ortiz
// Juan Embid S�nchez
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Solucion {
    bool strange;
    int sumaPares;
    int sumaImpares;
    int productoPares;
    int productoImpares;
};
// RECURRENCIA: Sea n el tamaño del vector
// T(n) = k ,si n = {0,1}
// T(n) = 2T(n/2) + cn, si n > 1
// T(n) en el caso peor pertenece a O(nlogn) por tener dos llamadas recursivas de tamaño la mitad + algo lineal
// INTERVALO CERRADO: llamada inicial con c = 0 y f = v.size() - 1
Solucion extrano(const vector<int>& v, int c, int f) {
    Solucion sol; int m;
    if (c == f + 1) { // CB: vector vacío
        sol.strange = true;
        sol.sumaImpares = 0;
        sol.sumaPares = 0;
        sol.productoImpares = 1;
        sol.productoPares = 1;
    }
    else if (c == f) { // CB: 1 elemento
        sol.strange = true;
        if (v.at(c) % 2 == 0) {
            sol.sumaImpares = 0;
            sol.sumaPares = v.at(c);
            sol.productoImpares = 1;
            sol.productoPares = v.at(c);
        }
        else {
            sol.sumaImpares = v.at(c);
            sol.sumaPares = 0;
            sol.productoImpares = v.at(c);
            sol.productoPares = 1;
        }
    }
    else { // CR
        Solucion aux1, aux2;
        m = (c + f) / 2;
        aux1 = extrano(v, c, m);
        aux2 = extrano(v, m + 1, f);
        sol.strange = ((aux1.strange || aux2.strange) && (aux1.sumaPares + aux1.productoImpares <= aux2.productoPares + aux2.sumaImpares));
        sol.sumaImpares = aux1.sumaImpares + aux2.sumaImpares;
        sol.productoImpares = aux1.productoImpares + aux2.productoImpares;
        sol.sumaPares = aux1.sumaPares + aux2.sumaPares;
        sol.productoPares = aux1.productoPares + aux2.productoPares;
    }
    return sol;
}

void resuelveCaso() {
    vector<int> vals;
    int size, temp, c, f;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }
    c = 0; f = (int)vals.size() - 1;
    Solucion sol = extrano(vals, c, f);
    if (sol.strange) cout << "SI\n";
    else cout << "NO\n";
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
