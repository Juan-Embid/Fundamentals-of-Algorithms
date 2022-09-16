// NOMBRE Y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_HERMANOS = 100000;

bool compruebaHermanos(const int hermanos[], int cantidad) {
    int i = 0;
    bool dalton = (hermanos[i] < hermanos[i + 1]);

    // Asciende
    if (dalton) {
        while ((i < cantidad) && dalton) {
            if(i + 1 < cantidad)
                dalton = (hermanos[i] < hermanos[i + 1]);
            i++;
        }
        if(i == cantidad)
            return true;
    }

    // Desciende
    else {
        while ((i < cantidad) && !dalton) {
            if(i + 1 < cantidad)
                dalton = (hermanos[i] <= hermanos[i + 1]);
            i++;
        }
        if(i == cantidad)
            return true;
    }

    return false;
}

bool resuelveCaso() {
    int cantidad;
    int hermanos[MAX_HERMANOS];
    cin >> cantidad;
    if (cantidad == 0)
        return false;

    for (int i = 0; i < cantidad; i++)
            cin >> hermanos[i];

    if (compruebaHermanos(hermanos, cantidad))
        cout << "DALTON" << endl;
    else 
        cout << "DESCONOCIDOS" << endl;

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

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
    //system("pause");
#endif
    return 0;
}