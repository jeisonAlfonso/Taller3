#ifndef __NODOBINARIO__HXX__
#define __NODOBINARIO__HXX__

#include <iostream>
#include <queue>
#include <algorithm>

/*
 * NodoBinario.hxx
 * Implementación de los métodos de NodoBinario<T>.
 */

template<class T>
NodoBinario<T>::NodoBinario()
    : hijoIzq(nullptr), hijoDer(nullptr)
{
    // Constructor: no se hace nada especial, sólo punteros en nullptr.
}

template<class T>
T& NodoBinario<T>::obtenerDato() {
    return dato;
}

template<class T>
void NodoBinario<T>::fijarDato(T& val) {
    dato = val;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq() {
    return hijoIzq;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer() {
    return hijoDer;
}

template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq) {
    hijoIzq = izq;
}

template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der) {
    hijoDer = der;
}

template<class T>
int NodoBinario<T>::altura() {
    // Altura = 1 + max(altura izq, altura der)
    // Si no hay hijo, esa rama mide 0.
    int altIzq = (hijoIzq) ? hijoIzq->altura() : 0;
    int altDer = (hijoDer) ? hijoDer->altura() : 0;
    return 1 + std::max(altIzq, altDer);
}

template<class T>
int NodoBinario<T>::tamano() {
    // tamano = 1 (este nodo) + tamano(hijoIzq) + tamano(hijoDer)
    int total = 1;
    if (hijoIzq) total += hijoIzq->tamano();
    if (hijoDer) total += hijoDer->tamano();
    return total;
}

template<class T>
void NodoBinario<T>::insertar(T& val) {
    // Ejemplo típico de inserción en un árbol binario de búsqueda:
    if (val < dato) {
        // Va a la izquierda
        if (!hijoIzq) {
            hijoIzq = new NodoBinario<T>();
            hijoIzq->fijarDato(val);
        } else {
            hijoIzq->insertar(val);
        }
    } else {
        // Va a la derecha
        if (!hijoDer) {
            hijoDer = new NodoBinario<T>();
            hijoDer->fijarDato(val);
        } else {
            hijoDer->insertar(val);
        }
    }
}

template<class T>
NodoBinario<T>* NodoBinario<T>::buscar(T& val) {
    // Búsqueda estilo BST
    if (val == dato) return this;
    if (val < dato && hijoIzq) return hijoIzq->buscar(val);
    if (val > dato && hijoDer) return hijoDer->buscar(val);
    return nullptr;
}

template<class T>
void NodoBinario<T>::preOrden() {
    std::cout << dato << " ";
    if (hijoIzq) hijoIzq->preOrden();
    if (hijoDer) hijoDer->preOrden();
}

template<class T>
void NodoBinario<T>::inOrden() {
    if (hijoIzq) hijoIzq->inOrden();
    std::cout << dato << " ";
    if (hijoDer) hijoDer->inOrden();
}

template<class T>
void NodoBinario<T>::posOrden() {
    if (hijoIzq) hijoIzq->posOrden();
    if (hijoDer) hijoDer->posOrden();
    std::cout << dato << " ";
}

template<class T>
void NodoBinario<T>::nivelOrden() {
    // Se encola este nodo y se van encolando sus hijos
    std::queue<NodoBinario<T>*> cola;
    cola.push(this);
    while (!cola.empty()) {
        NodoBinario<T>* actual = cola.front();
        cola.pop();
        std::cout << actual->dato << " ";
        if (actual->hijoIzq) cola.push(actual->hijoIzq);
        if (actual->hijoDer) cola.push(actual->hijoDer);
    }
}

template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_izq() {
    NodoBinario<T>* temp = this;
    while (temp->hijoIzq) {
        temp = temp->hijoIzq;
    }
    return temp;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_der() {
    NodoBinario<T>* temp = this;
    while (temp->hijoDer) {
        temp = temp->hijoDer;
    }
    return temp;
}

#endif // __NODOBINARIO__HXX__





