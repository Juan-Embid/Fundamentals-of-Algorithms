// NOMBRE Y APELLIDOS: 
// Daniel Fern�ndez Ortiz
// Juan Embid S�nchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


 // Invariante: (0 <= i < v.size() - 1) &&
 // aux_long = sumatorio(desde i = 0 hasta i = v.size() - 2 tq PARA TODO j : 0 <= j < i v[j] >= v[j + 1]) && 
 // longitud = max(aux_long, longitud)

 // Funcion de cota: (v.size() - 1) - i

 /* El coste del algoritmo es el coste del bucle. El bucle se recorre v.size() - 1 veces
 Cada vuelta del bucle es constante, entonces (v.size() - 1) * O(1) = O(N) donde N es v.size() - 1
  */

vector<int> mayorTramo(const vector<int> &v, int minSize) { // O(N) donde N es v.size()
    vector<int> sol, temp;
    int max = v.back(), contEq = 1, llanosCont = 0, llanosMax = 0;
    bool eqVal = false;

    for(int i = v.size() - 1; i > 0; i--) {
        eqVal = (v[i] == v[i - 1]);
        if (!eqVal || v[i-1]<max) {contEq=1;} else {contEq++;}
        if(contEq > llanosMax && contEq >= minSize)
            llanosMax = contEq;
        if(contEq == minSize) {llanosCont++; temp.push_back(i + contEq -2);}
        if(v[i - 1] > max)
            max = v[i - 1];
    }
    
    sol.push_back(llanosMax);
    sol.push_back(llanosCont);
    for(int i = 0; i < temp.size(); i++)
        sol.push_back(temp[i]);

    return sol;
}

bool resuelveCaso() {
    int size, temp, minSize;
    vector<int> vals, vTemp;


    cin >> size;
    cin >> minSize;

    if(!cin)
        return false;

    for (int i = 0; i < size; i++) {
        cin >> temp;
        vals.push_back(temp);
    }

    vTemp = mayorTramo(vals, minSize);
    for(int i = 0; i < vTemp.size(); i++) {
        cout << vTemp[i] << " ";
    }
    cout << "\n";

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