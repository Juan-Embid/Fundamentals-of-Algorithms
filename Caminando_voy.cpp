// NOMBRE Y APELLIDOS
// DANIEL FERNÁNDEZ ORTIZ
// JUAN EMBID SÁNCHEZ

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

// Función de cota: (v.size() - 1) - i
/* Invariante: 
* (0 <= i < v.size() - 1)
* && 
* PARA TODO j: (0 <= j < v.size() - 1) inicio = j <=> (PARA TODO n: (j < n <= v.size() - 1) tq (v[j] < v[n]))
* &&
* v es apta <=> PARA TODO k: (0 <= k <= v.size() - 1) tq (v[k] > v[k + 1] && (v[k] - inicio) <= d)
*/
// Coste: El coste del bucle es constante porque cada iteración del bucle es constante
// Como el bucle se recorre (en el caso peor) N = (v.size() - 1) veces, el coste del algoritmo es de O(1) * N = O(N)

bool excursionApta(const vector<int>& v, int d) {
    bool apta = true;
    int i = 0, inicio = v[0];
    while ((i < v.size() - 1) && apta) {
        if (v[i] < v[i + 1]) {
            apta = ((v[i + 1] - inicio) <= d);
        }
        else if (v[i] == v[i + 1]) {
            //apta = ((v[i] - inicio) <= d);
            //if (apta) {
            //    inicio = v[i + 1];
            //}
            inicio = v[i + 1];
        }
        else { // v[i] > v[i + 1]
            apta = ((v[i] - inicio) <= d);
            if (apta) {
                inicio = v[i + 1];
            }
        }
        //apta = ((v[i] - inicio) <= d);
        i++;
    }
    return apta;
}

bool resuelveCaso() {
    int size, d, temp;
    vector<int> vals;
    cin >> d >> size;

    if (!cin)
        return false;

    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }

    if (excursionApta(vals, d)) {
        cout << "APTA\n";
    }
    else {
        cout << "NO APTA\n";
    }
    return true;

}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}