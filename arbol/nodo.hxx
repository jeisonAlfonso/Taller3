#include "nodo.h"
#include <iostream>
using namespace std;

template <class T>
Nodo<T>::Nodo() {
    izq = nullptr;
    der = nullptr;
}

template <class T>
Nodo<T>::Nodo(T dato) {
    this->dato = dato;
    izq = nullptr;
    der = nullptr;
}

template <class T>
T Nodo<T>::obtenerDato() {
    return dato;
}

template <class T>
void Nodo<T>::fijarDato(T dato) {
    this->dato = dato;
}

template <class T>
void Nodo<T>::insertar(T dato) {
    // Se mantiene el árbol ordenado: si el dato es menor se inserta a la izquierda; si es mayor, a la derecha.
    if (dato < this->dato) {
        if (izq != nullptr)
            izq->insertar(dato);
        else
            izq = new Nodo<T>(dato);
    } else {
        if (der != nullptr)
            der->insertar(dato);
        else
            der = new Nodo<T>(dato);
    }
}

template <class T>
void Nodo<T>::preOrden() {
    cout << dato << " ";
    if (izq != nullptr)
        izq->preOrden();
    if (der != nullptr)
        der->preOrden();
}

template <class T>
void Nodo<T>::posOrden() {
    if (izq != nullptr)
        izq->posOrden();
    if (der != nullptr)
        der->posOrden();
    cout << dato << " ";
}

template <class T>
int Nodo<T>::altura() {
    int altIzq = (izq != nullptr) ? izq->altura() : 0;
    int altDer = (der != nullptr) ? der->altura() : 0;
    return max(altIzq, altDer) + 1;
}

template <class T>
int Nodo<T>::tamano() {
    int tam = 1;
    if (izq != nullptr)
        tam += izq->tamano();
    if (der != nullptr)
        tam += der->tamano();
    return tam;
}

template <class T>
Nodo<T>* Nodo<T>::buscar(T dato) {
    if (this->dato == dato)
        return this;
    else if (dato < this->dato && izq != nullptr)
        return izq->buscar(dato);
    else if (dato > this->dato && der != nullptr)
        return der->buscar(dato);
    return nullptr;
}
