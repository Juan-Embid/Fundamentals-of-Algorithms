// NOMBRE Y APELLIDOS 
// Daniel Fernández Ortiz
// Juan Embid Sánchez
// Comentario general sobre la solucion,
// explicando como se resuelve el problema
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// a) todosPares(v, p, q) = (forall i : p <= i < q : v[i] % 2 == 0)
// b) 
// c) 
// d)
// e) En el caso peor el coste es O(n) donde n es v.size()

//ESPECIFICA la funcion que resuelve el problema

//PRECONDICION: {0 < n <= v.size()}

    //INVARIANTE:
    //F. COTA: v.size() - i



int resolver(std::vector<int> const& v) { 
    int contPares = 0, pares = 0, paresTotal = 0;
    bool eqPar = false;
    for (int i = 0; i < (int)v.size(); i++) {
        eqPar = v[i] % 2 == 0;
        if (!eqPar) {contPares=0;} else {contPares++;}
        if (eqPar && (v[i + 1] % 2 != 0 || i == v.size() - 1)) {
            for(int j = 0; j <= contPares; j++) {
                pares += j;
            }
            paresTotal += pares;
            pares = 0;
        }
    }
    return paresTotal;
}
   
//POSTCONDICION: {#(todosPares(v, p , q))}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	int numElems = 0; size_t n;int k;
	std::cin >> numElems;
	std::vector<int> v(numElems);
	for (int& i : v) std::cin >> i;
	int sol = resolver(v);
	std::cout << sol <<"\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
	std::ifstream in("sample1.in");
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