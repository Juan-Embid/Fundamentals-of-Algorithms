// NOMBRE Y APELLIDOS 
// Daniel Fern�ndez Ortiz
// Juan Embid S�nchez
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void resolver(vector<int> const& v, int c, int f, int d, int& n) {
	if (c == f) { // CB 1 elemento
		n = v[c] + d;
	}
	else if (c + 1 == f) { // CB 2 elementos
		if (v[f] - v[c] != d) { // falta entre c y f
			n = v[c] + d;
		}
		else { // falta el �ltimo
			n = v[f] + d;
		}
	}
	else { // CR
		if (v[c + 1] - v[c] != d) { // se encuentra
			n = v[c] + d;
		}
		else { // se sigue buscando
			resolver(v, c + 1, f, d, n);
		}
	}
}

void resuelveCaso() {
	vector<int> vals;
	int size, temp, d, c, f, n;
	cin >> size >> d;
	for (int i = 0; i < size; i++) {
		cin >> temp;
		vals.push_back(temp);
	}
	c = 0, f = size - 1;
	resolver(vals, c, f, d, n);
	cout << n << "\n";
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