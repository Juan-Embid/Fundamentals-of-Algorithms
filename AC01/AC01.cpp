// NOMBRE Y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// Invariante: -1 <= i <= v.size() - 1, ∧∀k : i < k < v.size() : sum(dese j = i + 1 hasta v.size() - 1) == v[i]
// Funcion de cota: i
// Justificacion del coste: en el caso peor O(N) donde N es v.size(), porque
// el bucle tiene coste constante y se recorre v.size() veces.

int pastoso(vector<int> v) {
    int suma = 0, i = v.size() - 1;
    while(i >= 0 && v[i] != suma) {
        suma += v[i];
        i--;
    }
    
    return i;
}

bool resuelveCaso() {
    int size, temp;
    vector<int> vals;

    cin >> size;
    for (int i = 0; i < size; i++) {
            cin >> temp;
            vals.push_back(temp);
    }

    if(pastoso(vals) == -1)
        cout << "NO" << endl;
    else
        cout << "SI " << pastoso(vals) << endl;

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