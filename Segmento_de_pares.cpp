// NOMBRE Y APELLIDOS:
// Daniel Fernández Ortiz
// Juan Embid Sánchez

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


// a) todosPares(v, p, q) <=> (forall j : p <= j <= q : v[j] % 2 == 0)
// b) noMas(v, p, q, k) <=> ((todosPares(v, p, q) && (p - q) <= k)

/*
Invariante:
* (0 <= i <= v.size) &&
* seg = forall j : i <= j < v.size() : #(contPares <= k) (nº de posiciones tq contPares <= j)
* maxSeg = max(seg, maxSeg)
* contPares = #(forall j : i <= p <= j <= q < v.size() : v[j] % 2 == 0) (nº de pares consecutivos) &&
* par = (v[i] % 2 == 0)
*/

// Función de cota: v.size() - i

// Coste: El coste del bucle es constante porque cada iteración del bucle es constante.
// Como el bucle se recorre (en el caso peor) N = v.size() veces, el coste del algoritmo es O(1) * (N) = O(N)



int noMas(const vector<int>& v, int k) {
    int seg = 0, maxSeg = 0, contPares = 0;
    bool par;
    for (int i = 0; i < v.size(); i++) {
        par = (v[i] % 2 == 0);
        if (par) {
            contPares++;
        }
        else {
            contPares = 0;
        }
        if (contPares <= k) {
            seg++;
        }
        if (seg > maxSeg) {
            maxSeg = seg;
        }
        if (contPares > k) {
            seg = k;
        }
    }
    return maxSeg;
}



bool resuelveCaso() {
    int size, temp, k;
    vector<int> vals;
    cin >> size >> k;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }
    cout << noMas(vals, k) << "\n";


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