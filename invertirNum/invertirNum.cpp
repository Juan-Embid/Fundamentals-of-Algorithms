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

void invNum(int num, int& inv) {
    int reminder;

    if(num == 0)
        return;
    else {
        reminder = num % 10;
        inv = inv * 10 + reminder;
        invNum(num / 10, inv);
    }
}

bool resuelveCaso() {
    int num, inv = 0;

    cin >> num;
    if(num == 0)
        return false;
    invNum(num, inv);
    cout << inv << "\n";

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

    while(resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
    //system("pause");
#endif
    return 0;
}