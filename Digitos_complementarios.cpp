// NOMBRE Y APELLIDOS: 
// Daniel Fern�ndez Ortiz
// Juan Embid S�nchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// Invariante: 
// aux_long = 
// longitud = 

// Funcion de cota: 

/* El coste del algoritmo es ... */

// función que devuelve el complementario de un nº
void complementario(long long int num, long long int& nCompl, long long int& nDigitos) {
    int n;
    if (num == 0 && nDigitos == 1) {
        nCompl = 9;
    }
    if (num > 0) {
        n = num % 10;
        nCompl = nCompl + (9 - n) * nDigitos;
        nDigitos = nDigitos * 10;
        complementario(num / 10, nCompl, nDigitos);
    }
}

// función que devuelve el inverso del complementario de un nº
void invNumCompl(long long int num, long long int& nComplInv) {
    int n;

    if (num < 10) {
        nComplInv = nComplInv * 10 + (9 - num);
    }
    else {
        n = num % 10;
        nComplInv = nComplInv * 10 + (9 - n);
        invNumCompl(num / 10, nComplInv);
    }
}
bool resuelveCaso() {
    long long int num, nComplInv = 0, nCompl = 0, nDigitos = 1;
    cin >> num;
    complementario(num, nCompl, nDigitos);
    invNumCompl(num, nComplInv);
    cout << nCompl << " " << nComplInv << "\n";
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