#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

//Implementa aqui tu funcion recursiva

int resolver(const vector<int>&v)


//Analiza el coste: escribe la recurrencia y el orden de complejidad al que pertenece la solucion a la misma



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // lectura de los datos
	int numElem;
	std::cin >> numElem;
    if (numElem == 0) return false;
	std::vector<int> v(numElem);
	for (int i = 0 ; i < numElem; ++i)
        std::cin >> v[i];
    int impar;
    // Aqui la llamada a la funcion resolver
    
    //...
    // Aqui escribir los resultados
    std::cout << impar <<endl;
    
    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());
    ;
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
	return 0;
}