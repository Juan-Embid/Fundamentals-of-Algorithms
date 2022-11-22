// NOMBRE Y APELLIDOS 
// Daniel Fernández Ortiz
// Juan Embid Sánchez
// Comentario general sobre la solucion,
// explicando como se resuelve el problema
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUCIÓN DE CLARA
// a) todosPares(v, p, q) = (forall i : p <= i < q : v[i] % 2 = 0)
// e) En el caso peor el coste es O(n) donde n es v.size(), siendo el coste del algoritmo el coste del bucle, cuya cada iteración es constante

// ESPECIFICA la funcion que resuelve el problema

//PRECONDICION: {0 <= v.size() && forall i: 0 <= i < v.size() : v[i] >= 0}

	/* INVARIANTE:
	* 0 <= i <= v.size() &&
	* s = #(p, q : 0 <= p < q <= i tq todosPares(v, p, q)) && 
	* z = min (j : 0 <= j <= i tq todosPares(v, j, i) : j) 
	*/
	//F. COTA: v.size() - i


/*
int resolver(vector<int> const& v) {
	int i = 0, s = 0, z = 0;
	while (i < v.size()) {
		if (v[i] % 2 == 0) {
			s = s + (i - z + 1);
		}
		else {
			z = i + 1;
		}
		i++;
	}
	return s;
}*/

//POSTCONDICION: {s = #(p,q : 0 <= p < q <= v.size() && todosPares(v, p, q))}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
