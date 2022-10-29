// NOMBRE Y APELLIDOS:
// Daniel Fernández Ortiz
// Juan Embid Sánchez

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

// Función de cota: (v.size() - 1) - i

/* Invariante:
* (i <= 0 < v.size()) &&
* consecutivos = ((v[i] == (v[i + 1] - 1)) || (v[i] == (v[i + 1] + 1))) &&
* seg = SUM(desde i = 0 hasta v.size() - 1 tq consecutivos) &&
* maxSeg = max(seg, maxSeg)
*/

// Coste: El coste del bucle es constante porque cada iteración del bucle es constante.
// Como el bucle se recorre (en el caso peor) N = (v.size() - 1) veces, el coste del algoritmo es O(1) * (N) = O(N)

int maxSegmento(vector<int> const& v) {
    int seg = 1, maxSeg = 0;
    bool consecutivos;
    if (v.size() == 1) {
        maxSeg = seg;
    }
    for (int i = 0; i < (int)v.size() - 1; i++) {
        consecutivos = ((v[i] == (v[i + 1] - 1)) || (v[i] == (v[i + 1] + 1)));
        if (consecutivos) {
            seg++;
        }
        else {
            seg = 1;
        }
        if (seg > maxSeg) {
            maxSeg = seg;
        }
    }
    return maxSeg;
}


bool resuelveCaso() {
    int size, temp;
    vector<int> vals;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }
    cout << maxSegmento(vals) << "\n";


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

    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
    //system("pause");
#endif
    return 0;
}