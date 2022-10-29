// NOMBRE Y APELLIDOS:
// Daniel Fernández Ortiz
// Juan Embid Sánchez

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


/*
Invariante:
*
*/

// Función de cota: v.size() - i

// Coste: El coste del bucle es constante porque cada iteración del bucle es constante.
// Como el bucle se recorre (en el caso peor) N = v.size() veces, el coste del algoritmo es O(1) * (N) = O(N)


void minimo(const vector<int>& v, int c, int f, int& min) {
    int m;
    if (c == f + 1) { min = v[c - 1]; }
    else {
        m = (c + f) / 2;
        if (v[c] > v[m]) { minimo(v, m, f, min); }
        else if (v[c] < v[m]) { minimo(v, c, m, min); }
        else if (v[m] == v[c] && v[m] > v[f]) { min = v[f]; } // este soluciona el caso de prueba donde el minimo es el ultimo elemento
        //(sale v[v.size()-2], en el segundo caso de prueba sale 3 en vez de 2)^^
        else { min = v[m]; }
    }
    //return min;
}

bool resuelveCaso() {
    int size, temp, ini = 0, fin, min;
    vector<int> vals;
    cin >> size;
    if (!cin) return false;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }
    fin = (int)vals.size() - 1;
    //cout << minimo(vals, ini, fin);
    minimo(vals, ini, fin, min);
    cout << min << "\n";

    return true;
}



int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("out.txt");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
    //system("pause");
#endif
    return 0;
}
