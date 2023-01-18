// NOMBRE Y APELLIDOS 
// Daniel Fernández Ortiz
// Juan Embid Sánchez
// Comentario general sobre la solucion,
// explicando como se resuelve el problema

// Definicion del espacio de soluciones y del arbol de exploracion

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// IMPLEMENTACION DEL ALGORITMO DE VUELTA ATRAS
// Explicaciones detalladas sobre la implementacion
// Indicacion de los marcadores utilizados
// k representa el nivel de la llamada
// m guarda el resultado deseado
// parcial lleva la suma desde 0 al k

// PODA UTILIZADA

// 2 ramas: suma y resta
// arbol de soluciones : 2 elevado al nº de elementos del vector
// coste(nlogn) donde n es tamaño del vector




bool operaNums(const vector<int>&v, const int &m, int &parcial, int k) {
        bool stop;
        if (k < (int)v.size() - 1) { // es valida
            if (parcial == m) // es solucion
                stop = true;
        } else {
                // marcaje
                parcial += v.at(k);
                stop = operaNums(v, m, parcial, k + 1);
                // desmarcaje
                parcial -= v.at(k);
                // marcaje
                parcial -= v.at(k);
                stop = operaNums(v, m, parcial, k + 1);
                // desmarcaje
                parcial += v.at(k);
        }
}




void resuelveCaso() {
	int numElems = 0; size_t n;int m;
	std::cin >> m >> numElems;
	std::vector<int> v(numElems);
	for (int& i : v) std::cin >> i; 
    int parcial = 0, k = 0;
    bool stop = false;
    bool b = false;
    
    //LLAMAR AQUI AL ALGORITMO DE VUELTA ATRAS
    if(v.empty())
        b = true;
    else b = operaNums(v, m, parcial, k);

	if (b)
	    std::cout << "SI" << "\n";
	else 		
		std::cout << "NO" <<"\n";
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



	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	
	return 0;
}
