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

void invNum(long int num, long int& inv) {
    int reminder;

    if(num == 0)
        return;
    else {
        reminder = num % 10;
        inv = inv * 10 + reminder;
        invNum(num / 10, inv);
    }
}

/*void complementario(long int num, int&n, long int& nCompl, long long int& nDigitos) {
    if (num == 0 && nDigitos == 1) {
        nCompl = 9;
    }
    if (num > 0) {
        n = num % 10;
        nCompl = nCompl + (9 - n) * nDigitos;
        nDigitos = nDigitos * 10;
        complementario(num / 10, n, nCompl, nDigitos);
    }
}*/

void complementario(long int num, long int& nCompl, bool ok) {
    int reminder;

    if(num == 0) {
        if(!ok) {
            reminder = num % 10;
            nCompl = nCompl * 10 + (9 - reminder); }
        return;
    } else {
        reminder = num % 10;
        nCompl = nCompl * 10 + (9 - reminder);
        complementario(num / 10, nCompl, true);
    }
}

bool resuelveCaso() {
    long int num, inv = 0, nCompl = 0, test = 0;

    cin >> num;
    complementario(num, nCompl, false);
    //opcion 1
    invNum(num, inv);
    complementario(inv, test, false);
/*     //opcion 2
    invNum(nCompl, inv); */
     /*if (num % 10 == 0 && num != 0) {
        cout << nCompl << " " << num << "\n";
    }
    else {
        cout << nCompl << " " << inv << "\n";
    }*/
    cout << inv << " " << nCompl << "\n";

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
