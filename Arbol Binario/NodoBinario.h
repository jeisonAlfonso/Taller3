#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

/*
 * NodoBinario.h
 * Este archivo declara la clase NodoBinario, que sirve como nodo para
 * un árbol binario. Guarda un dato de tipo T y punteros a los hijos izquierdo y derecho.
 */

template<class T>
class NodoBinario
{
protected:
    T dato;                     // Valor que guarda este nodo
    NodoBinario<T>* hijoIzq;   // Puntero al hijo izquierdo
    NodoBinario<T>* hijoDer;   // Puntero al hijo derecho

public:
    // Constructor por defecto: deja los punteros en nullptr.
    NodoBinario();

    // Devuelve una referencia al dato almacenado en este nodo.
    T& obtenerDato();

    // Asigna un valor al dato de este nodo.
    void fijarDato(T& val);

    // Retorna el puntero al hijo izquierdo.
    NodoBinario<T>* obtenerHijoIzq();

    // Retorna el puntero al hijo derecho.
    NodoBinario<T>* obtenerHijoDer();

    // Ajusta el puntero al hijo izquierdo.
    void fijarHijoIzq(NodoBinario<T>* izq);

    // Ajusta el puntero al hijo derecho.
    void fijarHijoDer(NodoBinario<T>* der);

    // Calcula la altura del subárbol con raíz en este nodo.
    int altura();

    // Retorna cuántos nodos hay en el subárbol que inicia en este nodo.
    int tamano();

    // Inserta val en el subárbol según tu criterio (e.g., BST).
    void insertar(T& val);

    // Busca val en el subárbol y retorna el nodo que lo contenga; nullptr si no está.
    NodoBinario<T>* buscar(T& val);

    // Recorridos de impresión
    void preOrden();   // imprime: nodo, subárbol izq, subárbol der
    void inOrden();    // imprime: subárbol izq, nodo, subárbol der
    void posOrden();   // imprime: subárbol izq, subárbol der, nodo
    void nivelOrden(); // recorrido por niveles con ayuda de una cola

    // Devuelve el nodo más a la izquierda (extremo).
    NodoBinario<T>* extremo_izq();

    // Devuelve el nodo más a la derecha (extremo).
    NodoBinario<T>* extremo_der();
};

#include "NodoBinario.hxx"

#endif // __NODOBINARIO__H__
