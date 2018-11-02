// Grupo 22 - Belén Solla, Dorian Sanz

// Se usa el esquema de la búsqueda binaria, puesto que el vector que nos dan está ordenado

#include <iostream>
#include <vector>

using namespace std;

/*          n = (fin - ini)
 *
 *          | c1                n = 0, 1;
 *      T = |
 *          | T(n/2) + c2       n > 1;
 *
 *      T € O(log n)
 */
bool  elementoSituado(const  vector <int >& v, int ini , int  fin) {
    bool bienSituado = false;
    int mit = (ini + fin) / 2;

    // casos base
    if (ini == fin) { // impares
        bienSituado = (v[ini] == ini);
    }
    else if (fin - ini == 1) {
        bienSituado = (v[ini] == ini) || (v[fin] == fin);
    }

    // proceso recursivo
    else if (mit < v[mit]) {
        bienSituado = elementoSituado(v, ini, mit);
    }
    else {
        bienSituado = elementoSituado(v, mit, fin);
    }

    return bienSituado;
}

void resuelveCaso() {
    int ini = 0, fin, elem;
    bool ordenado = false;
    vector<int> vect;

    // lee entrada
    cin >> fin;
    for (unsigned int i = 0; i < fin; ++i) {
        cin >> elem;
        vect.push_back(elem);
    }

    // llama a la funcion que resuelve cada caso
    if (vect.size() == 0) {
        ordenado = false;
    }
    else {
        ordenado = elementoSituado(vect, ini, fin - 1);
    }

    // escribe
    if (ordenado) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}