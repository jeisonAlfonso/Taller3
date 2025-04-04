#ifndef __ARBOLBINARIO__H__
#define __ARBOLBINARIO__H__

/*
 * ArbolBinario.h
 * Define la clase ArbolBinario, que tiene un puntero raíz y métodos para
 * manipular, buscar, y recorrer el árbol.
 */

#include "NodoBinario.h"

template<class T>
class ArbolBinario {
protected:
    NodoBinario<T>* raiz;  // Puntero a la raíz de todo el árbol

public:
    // Constructor por defecto: pone raiz en nullptr
    ArbolBinario();

    // Devuelve true si raíz es nullptr
    bool esVacio();

    // Devuelve una referencia al dato de la raíz (asume que no está vacío)
    T& datoRaiz();

    // Calcula la altura total del árbol
    int altura();

    // Retorna el número de nodos totales
    int tamano();

    // Inserta val en el árbol (estilo BST)
    void insertar(T& val);

    // Elimina val (versión incompleta para BST, se puede mejorar)
    bool eliminar(T& val);

    // Busca val y retorna el puntero al nodo, o nullptr si no existe
    NodoBinario<T>* buscar(T& val);

    // Muestra el árbol en preorden
    void preOrden();

    // Muestra el árbol en inorden
    void inOrden();

    // Muestra el árbol en posorden
    void posOrden();

    // Recorre el árbol por niveles
    void nivelOrden();
};

#include "ArbolBinario.hxx"
#endif // __ARBOLBINARIO__H__
