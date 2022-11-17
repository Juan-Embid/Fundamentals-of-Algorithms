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



void busqueda(const vector<char>& v, int c, int f, char ini, char fin, char& found) {
    int m;
    if (v[0] != ini) {
        found = ini;
    }
    else if (v[(int)v.size() - 1] != fin) {
        found = fin;
    }
    else {
        if (f == c + 1) {
            found = v[c] + 1;
            //found = - v[c] + v[f];
        }
        else {
            m = (c + f) / 2;
            if (v[m] - v[c] == m - c) { // no falta ninguno en el lado izq
                busqueda(v, m, f, ini, fin, found);
            }
            else if (v[f] - v[m] == f - m) { // no falta ninguno en el lado dcho
                busqueda(v, c, m, ini, fin, found);
            }
        }
    }


bool resuelveCaso() {
    int size, ini = 0, fin;
    char found = '-', c, f, temp;
    //vector<char> vals(128, 0);
    vector<char> vals;
    cin >> c >> f;
    size = f - c;
    fin = size - 1;
    //if (!cin) return false;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        //vals[temp] = temp;
        vals.push_back(temp);
    }
    //found = sol2(vals, c, f);
    busqueda(vals, ini, fin, c, f, found);
    cout << found << "\n";

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
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
    //system("pause");
#endif
    return 0;
}
