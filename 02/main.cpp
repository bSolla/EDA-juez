// Grupo 22, Fulano y Mengano

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void merge(vector<T> &v, int p, int q, int r) {
    int elemsL = q - p;
    int elemsR = r - q;
    T vL[elemsL];
    T vR[elemsR];

    // copiar v en los vectores auxiliares
    for (unsigned int i = 0; i < elemsL; ++i) {
        vL[i] = v[p + i];
    }
    for (unsigned int i = 0; i < elemsR; ++i) {
        vR[i] = v[q + i];
    }

    int i = 0, j = 0;
    for (int k = p; p < r; ++k) {
        // vR está agotado, o vR y vL no agotados y vL[i] <= vR[j]
        if ((j >= elemsR) || (i < elemsL && vL[i] <= vR[j]) ) {
            v[k] = vL[i];
            ++i;
        }
        else {
            v[k] = vR[j];
            ++j;
        }
    }
}

template <typename T>
void mergeSort(vector<T> &v, int ini, int fin) {
    int mid = (ini + fin) / 2;

    if (ini < fin - 1) {
        mergeSort(v, ini, mid);
        mergeSort(v, mid, fin);
        merge(v, ini, mid, fin);
    }
    // si la longitud del vector es <= 1, no hay que hacer nada porque ya está ordenado
}

// Resuelve un caso de prueba, leyendo de la entrada y escribiendo la respuesta
void resuelveCaso() {
//    [leer los datos de la entrada]
//    Solucion sol = resolver(datos);
//    [escribir sol]
}


int main() {
    int numCasos;

    cin >> numCasos;

    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}