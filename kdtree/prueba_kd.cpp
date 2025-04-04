/*
 * Archivo: prueba_kd.cpp
 * Descripción: Programa de prueba para el KD-Tree implementado en C++.
 *              Este programa demuestra la inserción, recorridos y búsqueda en el KD-Tree.
 *              Se han corregido errores y documentado el código para facilitar su comprensión.
 * Autor: [Tu Nombre]
 * Fecha: [Fecha Actual]
 */

#include <iostream>
#include "kdtree.h"

using namespace std;

int main() {
    // Inicialización del KD-Tree con un nodo raíz.
    KDTree<int> arbol({10, 20});
    
    // Inserción de puntos en el KD-Tree.
    arbol.insertar({15, 25});
    arbol.insertar({5, 10});
    arbol.insertar({30, 40});
    arbol.insertar({25, 35});
    arbol.insertar({12, 22});
    arbol.insertar({8, 18});
    
    // Mostrar la raíz del KD-Tree.
    pair<int, int> raiz = arbol.obtenerRaiz();
    cout << "Raíz del KD-Tree: (" << raiz.first << ", " << raiz.second << ")" << endl;
    
    // Recorrido Preorden.
    cout << "\nRecorrido Preorden:" << endl;
    arbol.preOrden();
    
    // Recorrido Postorden.
    cout << "\nRecorrido Postorden:" << endl;
    arbol.posOrden();
    
    // Búsqueda de un punto en el KD-Tree.
    pair<int, int> punto_a_buscar = {15, 25};
    Nodo<int>* nodo_encontrado = arbol.buscar(punto_a_buscar);
    if (nodo_encontrado != NULL) {
        cout << "\nNodo encontrado: (" 
             << nodo_encontrado->obtenerDato().first << ", " 
             << nodo_encontrado->obtenerDato().second << ")" << endl;
    } else {
        cout << "\nNodo no encontrado" << endl;
    }
    
    // Calcular y mostrar la altura y el tamaño del KD-Tree.
    cout << "\nAltura del KD-Tree: " << arbol.altura() << endl;
    cout << "Tamaño del KD-Tree: " << arbol.tamano() << endl;
    
    return 0;
}
