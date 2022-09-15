// NOMBRE Y APELLIDOS: Daniel Fernández Ortiz Grupo 2ºE

#include <iostream>
#include <fstream>
using namespace std;

const int MIN_DALTON = 2; // Constante que delimita el número mínimo de hermanos Dalton que existen
const int MAX_HERMANOS = 100; // Constante que delimita el número máximo de hermanos

typedef int tArray[MAX_HERMANOS]; // Array de hermanos Dalton
struct tLista { // Estructura que contiene la lista de hermanos Dalton
    tArray hermanos;
    int cont = 0;
};

bool comprobarHermanos(const tLista& lista) {
    int i = 0;
    bool hermanos = true;
    while ((i < lista.cont - 1) && hermanos) {
        hermanos = (lista.hermanos[i] < lista.hermanos[i + 1]);
        if (hermanos) {
            i++;
        }
    }
    return hermanos;
}

bool resuelveCaso() {
    int n_hermanos;
    tLista lista;
    bool hermanos;
    //Leer caso de prueba: cin>>...
    cin >> n_hermanos;
    if (n_hermanos == 0)
        return false;
    else if ((n_hermanos >= MIN_DALTON) && (n_hermanos <= MAX_HERMANOS)) {
        for (lista.cont = 0; lista.cont < n_hermanos; lista.cont++) {
            cin >> lista.hermanos[lista.cont];
        }
    }
    //Resolver problema
    hermanos = comprobarHermanos(lista);
    //Escribir resultado
    if (hermanos) {
        cout << "DALTON" << endl;
    }
    else {
        cout << "DESCONOCIDOS" << endl;
    }
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