// NOMBRE Y APELLIDOS
// DANIEL FERN�NDEZ ORTIZ
// JUAN EMBID S�NCHEZ

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

// Función de cota: (v.size() - 1) - i

/*Invariante: 
* (0 <= i < v.size()) 
* &&
* repetidos = nº de veces que se repiten los distintos valores de v
* PARA TODO j: (0 <= j < v.size() - 1) repetidos = #(v[j] == v[j + 1])
* &&
* PARA TODO k: (0 <= k < (v.size() - 1)) v es creciente por los pelos <=> (v[k] <= v[k + 1] && v[k + 1] - v[k] <= 1)
* &&
* v es divertido <=> PARA TODO l: (0 <= l < v.size() - 1) v[l] no se repite más de d veces
*/

// Coste: El coste del bucle es constante porque cada iteración del bucle es constante.
// Como el bucle se recorre (en el caso peor) N = (v.size() - 1) veces, el coste del algoritmo es O(1) * (N) = O(N)

bool crecienteYDivertido(const vector<int>& v, int d) {
    bool creciente = true, divertido = true;
    int repetidos = 1, i = 0;
    while (i < (v.size() - 1) && (creciente && divertido)) {
        if (v[i] > v[i + 1]) {
            creciente = false;
        }
        else if (v[i] == v[i + 1]) {
            repetidos++;
        }
        else {
            if ((v[i + 1] - v[i]) > 1) {
                creciente = false;
            }
            repetidos = 1;
        }
        //creciente = ((v[i] <= v[i + 1]) || ((v[i + 1] - v[i]) <= 1));
        divertido = (repetidos <= d);
        i++;
    }
    return creciente && divertido;
}


bool resuelveCaso() {
	int size, temp, d;
	vector<int> vals;
    cin >> d >> size;
	for (int i = 0; i < size; i++) {
		cin >> temp;
		vals.push_back(temp);
	}

    if (crecienteYDivertido(vals, d)) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

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
