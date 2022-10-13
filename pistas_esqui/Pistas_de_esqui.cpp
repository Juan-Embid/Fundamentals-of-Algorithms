// NOMBRE Y APELLIDOS: 
// Daniel Fern�ndez Ortiz
// Juan Embid S�nchez

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

int mayorTramo(vector<int> v) { // O(N) donde N es v.size()
    int maxLength = 1;
    int length = 1;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] >= v[i + 1])
            length++;
        else
            length = 1;
        if (length > maxLength)// importante llevar el maximo hasta el momento
            maxLength = length;
    }

    return maxLength;
}

bool resuelveCaso() {
    int size;
    int temp;
    vector<int> vals;

    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }

    if(!vals.empty())
        cout << mayorTramo(vals) << endl;
    else 
        cout << 0 << endl;

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