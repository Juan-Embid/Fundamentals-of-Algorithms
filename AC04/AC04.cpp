// NOMBRE Y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* {true}
proc equilibrio(vector <int > v) dev int p
{−1 ≤p < v.size() ∧numUnos(v, p + 1) = numCeros(v, p + 1)
∧∀k : p < k < v.size() : numUnos(v, k + 1) 6= numCeros(v, k + 1)}
donde numUnos(v, j) = #i : 0 ≤i < j : v[i] = 1 y numCeros(v, j) = #i : 0 ≤i < j : v[i] = 0.
 */
int equilibrio(vector<int> v) {
    
    return 0;
}

bool resuelveCaso() {
    int size, temp;
    vector<int> vals;

    cin >> size;
    for (int i = 0; i < size; i++) {
            cin >> temp;
            vals.push_back(temp);
    }

    cout << equilibrio(vals) << endl;

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