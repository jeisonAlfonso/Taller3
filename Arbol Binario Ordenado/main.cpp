#include <iostream>
#include "ArbolBinario.h"

int main() {
    ArbolBinario<int> arbol;

    int x = 10;
    arbol.insertar(x, nullptr);  // Inserta 10 como raíz (o subárbol)
    x = 5;
    arbol.insertar(x, arbol.datoRaiz() /* o arbol.raiz, pero es protected */); // O solo arbol.insertar(x, nullptr);

    // etc...
    arbol.nivelOrden(arbol.raiz); // Recorre por niveles
    std::cout << std::endl;

    return 0;
}
