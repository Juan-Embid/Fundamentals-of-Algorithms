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
// Funcion de cota: v.size() - i


/* 

 */


void rescateAereo(const vector<int> edificios, int t, int & inicio, int & fin) {
    int maxIni = 0, maxFin = 0;
    bool mayor = false;
    for(int i = 0; i < edificios.size(); i++) {
        mayor = ((inicio - fin) == 0);
        if(edificios[i] > t && !mayor) {
            inicio = i;
            fin = i;
            mayor = true;
        } else if (edificios[i] < t){
            mayor = false;
            maxIni = inicio;
            maxFin = fin;
        }
    }
}

bool resuelveCaso() {
    int n, t, temp, inicio, fin;
    vector<int> edificios;

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
            cin >> temp;
            edificios.push_back(temp);
    }

    cout << inicio << fin << "\n";

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