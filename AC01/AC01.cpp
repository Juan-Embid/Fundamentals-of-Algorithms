// NOMBRE Y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// Invariante:
// Funcion de cota:


int equilibrio(vector<int> v) { // O(N) donde N es v.size()
    int ceros = 0, unos = 0, pos = -1;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 0)
            ceros++;
        else if(v[i] == 1)
            unos++;
        if(unos == ceros)
            pos = i;
    }
    
    return pos;
}

bool resuelveCaso() {
    int size, temp;
    vector<int> vals;

    cin >> size;
    for (int i = 0; i < size; i++) {
            cin >> temp;
            vals.push_back(temp);
    }

    cout << equilibrio(vals) << endl;

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