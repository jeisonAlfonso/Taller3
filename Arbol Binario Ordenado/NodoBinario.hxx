#ifndef NODOBINARIO_HXX
#define NODOBINARIO_HXX

#include <cstddef> // para NULL o nullptr

/**
 * NodoBinario.hxx
 * Aquí se implementan los métodos de la clase plantilla NodoBinario<T>.
 */

template <class T>
NodoBinario<T>::NodoBinario()
    : hijoIzq(nullptr), hijoDer(nullptr)
{
    // Sin más lógica en el constructor por defecto
}

template <class T>
NodoBinario<T>::~NodoBinario()
{
    // No hace eliminación recursiva, se maneja en el árbol
}

template <class T>
T& NodoBinario<T>::getDato() {
    return dato;
}

template <class T>
void NodoBinario<T>::setDato(const T& val) {
    dato = val;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::getHijoIzq() {
    return hijoIzq;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::getHijoDer() {
    return hijoDer;
}

template <class T>
void NodoBinario<T>::setHijoIzq(NodoBinario<T>* izq) {
    hijoIzq = izq;
}

template <class T>
void NodoBinario<T>::setHijoDer(NodoBinario<T>* der) {
    hijoDer = der;
}

#endif // NODOBINARIO_HXX
