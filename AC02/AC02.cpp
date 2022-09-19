// NOMBRE Y APELLIDOS: 
//Daniel Fernández Ortiz
//Juan Embid Sánchez

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// O(n) donde n es vector.size()
bool IzdaDcha(const vector<int> temperaturas, int position) {
    int i = 0, max = temperaturas.at(i);

    while (i <= position) {
        if(temperaturas.at(i) > max)
            max = temperaturas.at(i);
        i++;
    }

    while (i < temperaturas.size()) {
        if(temperaturas.at(i) <= max)
            return false;
        i++;
    }

    return true;
}

bool resuelveCaso() {
    int numElems = 0;int p; size_t n;
    std::cin >> numElems >> p;
    std::vector<int> v(numElems);

    for (int& i : v) std::cin >> i;

    if (IzdaDcha(v, p))
        std::cout  <<"SI\n";
    else
        std::cout << "NO\n";
    
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("out.txt");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    unsigned int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
    //system("pause");
#endif
    return 0;
}