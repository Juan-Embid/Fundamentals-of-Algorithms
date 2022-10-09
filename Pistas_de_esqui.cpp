// NOMBRE Y APELLIDOS: 
// Daniel Fernández Ortiz
// Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


 // Invariante: (0 <= i < v.size() - 1) &&
 // aux_long = sumatorio(desde i = 0 hasta i = v.size() - 2 tq PARA TODO j : 0 <= j < i v[j] >= v[j + 1]) && 
 // longitud = max(aux_long, longitud)

 // Funcion de cota: (v.size() - 1) - i

 /* El coste del algoritmo es el coste del bucle. El bucle se recorre v.size() - 1 veces
 Cada vuelta del bucle es constante, entonces (v.size() - 1) * O(1) = O(N) donde N es v.size() - 1
  */

long long int mayorTramo(vector<long long int> v) { // O(N) donde N es v.size()
    long long int longitud = 1;
    long long int aux_long = 1;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] >= v[i + 1]) {
            aux_long++;
        }
        else {
            if (aux_long > longitud) {
                longitud = aux_long;
                aux_long = 1;
            }
        }
    }
    if (aux_long > longitud) {
        longitud = aux_long;
    }
    return longitud;
}

bool resuelveCaso() {
    int size;
    long long int temp;
    vector<long long int> vals;

    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }

    cout << mayorTramo(vals) << endl;

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