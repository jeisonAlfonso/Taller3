/*
 * Archivo: prueba_arbol.cpp
 * Descripción: Programa de prueba para el árbol binario implementado en C++.
 *              Este programa demuestra la inserción, recorridos y búsqueda en el árbol.
 *              Se han corregido errores y documentado el código para facilitar su comprensión.
 */

#include <iostream>
#include "arbol.h"

using namespace std;

int main() {
    // Inicializar el árbol con un dato en la raíz.
    Arbol<int> arbol(50);
    
    // Inserción de datos en el árbol.
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);
    
    // Mostrar el dato de la raíz.
    cout << "Raíz del árbol: " << arbol.obtenerRaiz() << endl;
    
    // Recorrido en Preorden.
    cout << "Recorrido Preorden: ";
    arbol.preOrden();
    
    // Recorrido en Postorden.
    cout << "Recorrido Postorden: ";
    arbol.posOrden();
    
    // Búsqueda de un dato en el árbol.
    int clave = 40;
    Nodo<int>* nodoEncontrado = arbol.buscar(clave);
    if(nodoEncontrado != nullptr)
        cout << "Nodo encontrado: " << nodoEncontrado->obtenerDato() << endl;
    else
        cout << "Nodo no encontrado." << endl;
        
    // Mostrar la altura y el tamaño del árbol.
    cout << "Altura del árbol: " << arbol.altura() << endl;
    cout << "Tamaño del árbol: " << arbol.tamano() << endl;
    
    return 0;
}
