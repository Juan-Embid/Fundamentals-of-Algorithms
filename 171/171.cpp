// NOMBRE Y APELLIDOS: Juan Embid Sánchez y Daniel Fernández Ortiz Grupo 2ºE

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ALTURAS = 100000; 

int contarAbadias(const int alturas[], int avadias) { 
    int cont = 1, max = avadias - 1;

    for(int i = (avadias - 1); i >= 0; i--) {
        if(alturas[i - 1] > alturas[max]) {
            max = alturas[i - 1];
            cont++;
        }
    }
    
    return cont;
}

bool resuelveCaso() {
    int alturas[MAX_ALTURAS];
    int avadias;

    cin >> avadias;
    if (avadias == 0)
        return false;

    for (int i = 0; i < avadias; i++)
            cin >> alturas[i];

    cout << contarAbadias(alturas, avadias) << endl;

    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    //std::ifstream in("in.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("out.txt");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    //std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
    //system("pause");
#endif
    return 0;
}
