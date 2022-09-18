// NOMBRE Y APELLIDOS: Juan Embid Sánchez y Daniel Fernández Ortiz Grupo 2ºE

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PAISES = 100000;
const int MAX_ESTUDIANTES = 1000000000;

struct tLista {
    int estudiantes[MAX_PAISES];
    int cont = 0; // paises
};

bool resuelveCaso() {
    //int n_paises = 0;
    int parejas = 0;
    tLista lista;
    //Leer caso de prueba: cin>>...
    cin >> lista.cont;
    if (lista.cont == 0)
        return false;
    else if (lista.cont <= MAX_PAISES) {
        for (int i = 0; i < lista.cont; i++) {
            cin >> lista.estudiantes[i];
        }
    }

    //Resolver problema
    for (int i = 0; i < lista.cont; i++) {
        for (int j = i + 1; j < lista.cont; j++) {
            parejas += (lista.estudiantes[i] * lista.estudiantes[j]);
        }
    }
    //Escribir resultado
    cout << parejas << endl;
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("out.txt");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("pause");
#endif
    return 0;
}
