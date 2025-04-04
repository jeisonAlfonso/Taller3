/*
 * Archivo: prueba_rb.cpp
 * Descripción: Programa de prueba para el árbol rojo-negro (Red-Black Tree) implementado en C++.
 *              Este programa demuestra la inserción, recorridos y búsqueda en el árbol rojo-negro.
 *              Se ha generado el código con las correcciones y documentación necesaria para su correcto funcionamiento.
 * Autor: [Tu Nombre]
 * Fecha: [Fecha Actual]
 */

#include <iostream>
#include "rbtree.h"

using namespace std;

int main() {
    RBTree<int> arbol;
    
    // Inserción de nodos en el árbol rojo-negro.
    arbol.insert(10);
    arbol.insert(20);
    arbol.insert(30);
    arbol.insert(15);
    arbol.insert(25);
    arbol.insert(5);
    arbol.insert(1);
    
    // Recorrido InOrder para verificar el orden.
    cout << "Recorrido InOrder del Árbol Rojo-Negro:" << endl;
    arbol.inOrder();
    
    // Búsqueda de un nodo en el árbol.
    int key = 15;
    RBNode<int>* nodo = arbol.search(key);
    if(nodo != nullptr)
        cout << "Nodo encontrado: " << nodo->data << " (Color: " << (nodo->color == RED ? "Rojo" : "Negro") << ")" << endl;
    else
        cout << "Nodo con clave " << key << " no encontrado." << endl;
        
    return 0;
}
