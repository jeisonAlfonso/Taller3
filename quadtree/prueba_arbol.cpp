/*
 * Archivo: prueba_arbol.cpp
 * Descripción: Programa de prueba para el QuadTree implementado en C++.
 *              Este programa demuestra la inserción, recorridos y búsqueda en el QuadTree.
 *              Se han corregido errores detectados en las funciones de cálculo de altura y tamaño.
 *              Además, se agregaron comentarios para facilitar la comprensión del código.
 * 
 *
 */

#include <iostream>
#include "quadtree.h" // Incluye la definición de la clase Arbol y Nodo

using namespace std;

int main() {
    // Inicialización del QuadTree con un nodo raíz
    // Se recomienda iniciar el árbol con un primer punto para evitar errores en las inserciones posteriores.
    Arbol<int> arbol({10, 20});
    
    // Inserción de puntos en el QuadTree.
    // Cada par representa (coordenadaX, coordenadaY)
    arbol.insertar({15, 25});
    arbol.insertar({5, 10});
    arbol.insertar({30, 40});
    arbol.insertar({25, 35});
    arbol.insertar({12, 22});
    arbol.insertar({8, 18});
    
    // Mostrar la raíz del QuadTree
    pair<int, int> raiz = arbol.obtenerRaiz();
    cout << "Raíz del QuadTree: (" << raiz.first << ", " << raiz.second << ")" << endl;
    
    // Recorrido Preorden: Se visita primero el nodo actual, luego sus subárboles.
    cout << "\nRecorrido Preorden:" << endl;
    arbol.preOrden();
    
    // Recorrido Postorden: Se visitan primero los subárboles y al final el nodo actual.
    cout << "\nRecorrido Postorden:" << endl;
    arbol.posOrden();
    
    // Búsqueda de un punto específico en el QuadTree.
    pair<int, int> punto_a_buscar = {15, 25};
    Nodo<int>* nodo_encontrado = arbol.buscar(punto_a_buscar);
    if (nodo_encontrado != NULL) {
        cout << "\nNodo encontrado: (" 
             << nodo_encontrado->obtenerDato().first << ", " 
             << nodo_encontrado->obtenerDato().second << ")" << endl;
    } else {
        cout << "\nNodo no encontrado" << endl;
    }
    
    // Cálculo y muestra de la altura del QuadTree.
    // La altura se determina mediante el método 'altura()' de la clase Nodo.
    cout << "\nAltura del QuadTree: " << arbol.altura() << endl;
    
    // Cálculo y muestra del tamaño (cantidad de nodos) del QuadTree.
    // Se utiliza el método 'tamano()' que debe contar correctamente cada nodo.
    cout << "Tamaño del QuadTree: " << arbol.tamano() << endl;
    
    return 0;
}
