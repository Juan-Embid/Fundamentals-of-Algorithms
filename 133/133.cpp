// NOMBRE Y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* 
proc rescateAereo(vector <int> v, int N, in out int inicio, in out final)

 */

// Invariante: 
// Funcion de cota:
// Coste:


pair<int, int> rescateAereo(const vector<int> edificios, int t) {
    pair<int, int> segMax = { 0, -1 };
    pair<int, int> seg = { 0, 0 };
    bool mayor = false;

    for (int i = 0; i < edificios.size(); i++) {
        if (edificios[i] > t) {
            if (!mayor) {
                seg = { i, i };
                mayor = true;
                if (seg.second - seg.first > segMax.second - segMax.first)
                    segMax = seg;
            }
            else {
                seg.second++;
                if (seg.second - seg.first > segMax.second - segMax.first)
                    segMax = seg;
            }
        }
        else {
            mayor = false;
        }
    }
    return segMax;
}

bool resuelveCaso() {
    int n, t, temp;
    vector<int> edificios;

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
            cin >> temp;
            edificios.push_back(temp);
    }

    cout << rescateAereo(edificios, t).first << " " << rescateAereo(edificios, t).second << "\n";

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
