// NOMBRE Y APELLIDOS: Juan Embid Sánchez y Daniel Fernández Ortiz Grupo 2ºE

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_HUEVOS = 10000; // Constante que delimita el número máximo de huevos que se quieren cocer
const int MAX_CAPACIDAD = 1000; // Constante que delimita el número máximo de huevos que se pueden cocer a la vez

bool resuelveCaso() {
    int huevos = 0, capacidad = 0, tiempo = 1;
    //Leer caso de prueba: cin>>...
    cin >> huevos >> capacidad;
    if ((huevos == 0) && (capacidad == 0))
        return false;
    if ((huevos <= MAX_HUEVOS) && (capacidad <= MAX_CAPACIDAD)) {
        if (huevos <= capacidad) {
            cout << 10 << endl;
        }
        else {
            while (huevos > capacidad) {
                huevos -= capacidad;
                tiempo++;
            }
            //int tiempo = (huevos / capacidad) * 10;
            cout << tiempo * 10 << endl;
            //cout << (huevos / capacidad) * 10 << endl;
        }
    }

    //Resolver problema
    //Escribir resultado
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
