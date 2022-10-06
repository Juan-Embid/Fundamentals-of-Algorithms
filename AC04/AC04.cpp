// NOMBRE Y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* {true}
proc equilibrio(vector <int > v) dev int p
{−1 ≤p < v.size() ∧numUnos(v, p + 1) = numCeros(v, p + 1)
∧∀k : p < k < v.size() : numUnos(v, k + 1) 6= numCeros(v, k + 1)}
donde numUnos(v, j) = #i : 0 ≤i < j : v[i] = 1 y numCeros(v, j) = #i : 0 ≤i < j : v[i] = 0.
 */

// Invariante: 0 <= i <= v.size(), ceros = numCeros(v, i), unos = numUnos(v, i), -1 <= pos < i && numCeros(v, pos + 1) == numUnos(v, pos + 1) && ∀k : p < k < v.size() : numUnos(v, k + 1) != numCeros(v, k + 1)
// Funcion de cota: v.size() - 1 

// Funcion de cota simpre decrece

/* El coste del algoritmo es el coste del bucle. El bucle se recorre v.size() veces
Cada vuelta del bucle es constante, entonces v.size() * O(1) = O(N) donde N es v.size()

 */

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