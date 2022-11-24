// NOMBRE Y APELLIDOS 
// Daniel Fern�ndez Ortiz
// Juan Embid S�nchez
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct extr {
    int sumaPares;
    int sumaImpares;
    int productoPares;
    int productoImpares;
};

// mitad izq: suma pares + producto impares
// mitad der: suma impares + producto pares
bool extrano(const vector<int> &vec, int ini, int fin, extr&ex) {
    int m;
    if(vec.empty()) // CB
        return true;
    else if(ini == fin) // CB
         if(vec.at(ini) % 2 == 0) {
            sumaPares = vec.at(ini);
            productoPares = vec.at(ini);
        }
        else {
            sumaImpares = vec.at(ini);
            productoImpares = vec.at(ini);
        }
        return true;
    else if(ini + 1 == fin) { // CB
        if(vec.at(ini) % 2 == 0) {
            sumaPares += vec.at(ini);
            productoPares *= vec.at(ini);
        }
        else {
            sumaImpares += vec.at(ini);
            productoImpares *= vec.at(ini);
        }
        if (vec.at(fin) % 2 == 0){
            sumaPares += vec.at(fin);
            productoPares *= vec.at(fin);
        }
        else {
            sumaImpares += vec.at(fin);
            productoImpares *= vec.at(fin);
        }
    }
    else { //CR
        m = (ini + fin) / 2;
        extrano(vec, ini, m, sumaPares, sumaImpares, productoPares, productoImpares); // izquierda
        if ((sumaPares + productoImpares < sumaImpares + productoPares))
            extrano(vec, m + 1, fin, sumaPares, sumaImpares, productoPares, productoImpares); // derecha
        return (sumaPares + productoImpares < sumaImpares + productoPares);
    }
}

void resuelveCaso() {
	vector<int> vals;
    extr ex;
	int size, temp, c, f, sumaPares = 0, sumaImpares = 0, productoPares = 1, productoImpares = 1;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> temp;
		vals.push_back(temp);
	}
    c = 0; f = (int)vals.size() - 1;
    if(extrano(vals, c, f, ex))
        cout << "SI" << "\n";
    else 
        cout << "NO" << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("in.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}