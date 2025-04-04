#include <iostream>
#include "ArbolBinario.h"
#include "NodoBinario.h"

/*
 * PruebaArbolBinario.cpp
 * Programa que pide 7 números al usuario y los inserta en un árbol binario de enteros.
 * Luego muestra el recorrido en nivelOrden() para comprobar.
 */

int main(int argc, char* argv[])
{
    ArbolBinario<int> arbolito;

    // Insertamos 7 valores
    for(int i = 0; i < 7; i++) {
        int dato;
        std::cin >> dato;
        arbolito.insertar(dato);
    }

    // Mostramos el árbol en recorrido por niveles
    std::cout << "Recorrido por niveles: ";
    arbolito.nivelOrden();

    return 0;
}

