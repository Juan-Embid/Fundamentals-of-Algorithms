#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

//Implementa aqui tu funcion recursiva
// Llamada inicial con c = 0 y f = v.size() - 1 (intervalo cerrado) donde c es el comienzo y f el final del segmento
int resolver(const vector<int>& v, int c, int f){
    int m;
    if (c == f) { // CB: un elemento
        return v.at(f);
    } else if(f - c == 1) { // CB: dos elementos
        if (v.at(c) % 2 != 0) return v.at(c);
        return v.at(f);
    } else { // CR
        m = (c + f) / 2;
        if ((v.at(m) - v.at(c)) / 2 != m - c) { // elemento impar en izquierda
            resolver(v, c, m);
        } else if ((v.at(f) - v.at(m + 1)) / 2 != f - m + 1) { // elemento impar en derecha
            resolver(v, m + 1, f);
        }
    }
}


//Analiza el coste: escribe la recurrencia y el orden de complejidad al que pertenece la solucion a la misma
/* RECURRENCIA: Sea n el tamaño del vector: n = f - c + 1
    T(n) = c si n = 1
    T(n) = 2T(n/2) + c1 si n >= 2
    T(n) pertence a O(n)
    COSTE: En el caso peor es O(n) donde n es v.size()
*/


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
    int c = 0, f = numElem - 1;
    impar = resolver(v, c, f);
    
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