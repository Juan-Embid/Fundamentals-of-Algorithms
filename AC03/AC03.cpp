// NOMBRE Y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Invariante:  (0 <= i <= v.size()) && (min PERTENECE A v) && (sum >= 0) && (contMin >= 0) con
// min = EXISTE j tq PARA TODO k : 0 <= k < v.size() v[j] <= v[k]
// sum = sumatorio(desde i = 0 hasta i = v.size() - 1) de v[i]
// contMin = sum(v[i]) <=> v[i] = min(v) PARA TODO i : 0 <= i < v.size()

// Funcion de cota: v.size() - 1 

/* El coste del algoritmo es el coste del bucle. El bucle se recorre v.size() veces
Cada vuelta del bucle es constante, entonces v.size() * O(1) = O(N) donde N es v.size()
*/

pair<long long int, long long int> equilibrio(vector<long long int> v) { // O(N) donde N es v.size()
    long long int min = v[0], sum = 0;
    int contMin = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < min) {
            min = v[i];
            contMin = 1;
        } else if (v[i] == min)
            contMin++;
        sum += v[i];
    }
    
    return { sum - (min * contMin) , v.size() - contMin };
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
    cout << equilibrio(vals).first << " " << equilibrio(vals).second << endl;

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
