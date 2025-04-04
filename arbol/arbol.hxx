#include "arbol.h"
#include <iostream>
using namespace std;

template <class T>
Arbol<T>::Arbol() {
    raiz = nullptr;
}

template <class T>
Arbol<T>::Arbol(T dato) {
    raiz = new Nodo<T>(dato);
}

template <class T>
bool Arbol<T>::esVacio() {
    return (raiz == nullptr);
}

template <class T>
T Arbol<T>::obtenerRaiz() {
    if (raiz != nullptr)
        return raiz->obtenerDato();
    throw std::runtime_error("El árbol está vacío");
}

template <class T>
void Arbol<T>::insertar(T dato) {
    if (raiz == nullptr)
        raiz = new Nodo<T>(dato);
    else
        raiz->insertar(dato);
}

template <class T>
void Arbol<T>::preOrden() {
    if (raiz != nullptr)
        raiz->preOrden();
    cout << endl;
}

template <class T>
void Arbol<T>::posOrden() {
    if (raiz != nullptr)
        raiz->posOrden();
    cout << endl;
}

template <class T>
int Arbol<T>::altura() {
    if (raiz != nullptr)
        return raiz->altura();
    return 0;
}

template <class T>
int Arbol<T>::tamano() {
    if (raiz != nullptr)
        return raiz->tamano();
    return 0;
}

template <class T>
Nodo<T>* Arbol<T>::buscar(T dato) {
    if (raiz != nullptr)
        return raiz->buscar(dato);
    return nullptr;
}
