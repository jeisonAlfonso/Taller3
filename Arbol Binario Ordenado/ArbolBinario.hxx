#ifndef ARBOLBINARIO_HXX
#define ARBOLBINARIO_HXX

#include <iostream>
#include <queue>
#include <algorithm> // para std::max

/**
 * ArbolBinario.hxx
 * Implementación de los métodos de la clase plantilla ArbolBinario<T>.
 */

// =====================
//   Constructor / Destructor
// =====================
template <class T>
ArbolBinario<T>::ArbolBinario()
    : raiz(nullptr)
{}

template <class T>
ArbolBinario<T>::~ArbolBinario()
{
    destruirSubarbol(raiz);
}

// Liberación recursiva de nodos
template <class T>
void ArbolBinario<T>::destruirSubarbol(NodoBinario<T>* nodo)
{
    if (!nodo) return;
    destruirSubarbol(nodo->getHijoIzq());
    destruirSubarbol(nodo->getHijoDer());
    delete nodo;
}

// =====================
//   esVacio / datoRaiz
// =====================
template <class T>
bool ArbolBinario<T>::esVacio() {
    return (raiz == nullptr);
}

template <class T>
T& ArbolBinario<T>::datoRaiz() {
    return raiz->getDato(); // Se asume no vacío
}

// =====================
//   altura / tamano
// =====================
template <class T>
int ArbolBinario<T>::altura(NodoBinario<T>* inicio) {
    if (!inicio) return 0;
    int izq = altura(inicio->getHijoIzq());
    int der = altura(inicio->getHijoDer());
    return 1 + std::max(izq, der);
}

template <class T>
int ArbolBinario<T>::tamano(NodoBinario<T>* inicio) {
    if (!inicio) return 0;
    return 1 + tamano(inicio->getHijoIzq()) + tamano(inicio->getHijoDer());
}

// =====================
//   insertar
// =====================

/**
 * @brief insertarRec
 * Función recursiva que opera sobre una referencia al puntero 'nodo',
 * para poder modificarlo si está en nullptr.
 */
template <class T>
bool ArbolBinario<T>::insertarRec(NodoBinario<T>*& nodo, const T& val)
{
    if (!nodo) {
        // Crear nodo
        nodo = new NodoBinario<T>();
        nodo->setDato(val);
        return true;
    }
    // Comparar (BST)
    if (val < nodo->getDato()) {
        return insertarRec(nodo->getHijoIzq(), val);
    } else if (val > nodo->getDato()) {
        return insertarRec(nodo->getHijoDer(), val);
    }
    // Si val == nodo->getDato(), no lo insertamos (ya existe)
    return false;
}

/**
 * Versión pública pedida por el TAD: insertar(T& val, NodoBinario<T>* nodo).
 * Si nodo es nullptr y el árbol está vacío, crea la raíz. Si no, baja recursivamente.
 */
template <class T>
bool ArbolBinario<T>::insertar(T& val, NodoBinario<T>* nodo)
{
    // Caso especial: si el árbol entero está vacío
    if (!raiz) {
        raiz = new NodoBinario<T>();
        raiz->setDato(val);
        return true;
    }

    // Si 'nodo' es nulo, no podemos "crear" subárbol sin saber su padre,
    // interpretamos que la inserción debe comenzar en la raíz.
    if (!nodo) {
        nodo = raiz;
    }
    // Llamamos a la auxiliar recursiva que modifica punteros
    return insertarRec(nodo, val);
}

// =====================
//   buscar
// =====================
template <class T>
bool ArbolBinario<T>::buscarRec(NodoBinario<T>* nodo, const T& val)
{
    if (!nodo) return false;
    if (val == nodo->getDato()) return true;
    if (val < nodo->getDato()) return buscarRec(nodo->getHijoIzq(), val);
    else return buscarRec(nodo->getHijoDer(), val);
}

template <class T>
bool ArbolBinario<T>::buscar(T& val)
{
    return buscarRec(raiz, val);
}

// =====================
//   eliminar
// =====================
template <class T>
NodoBinario<T>* ArbolBinario<T>::minValueNode(NodoBinario<T>* nodo)
{
    // Mínimo de un subárbol es el más a la izquierda
    NodoBinario<T>* actual = nodo;
    while (actual && actual->getHijoIzq()) {
        actual = actual->getHijoIzq();
    }
    return actual;
}

/**
 * @brief eliminarRec
 * Elimina 'val' del subárbol BST que inicia en 'nodo', ajustando punteros.
 * Retorna true si se eliminó, false si no se encontró.
 */
template <class T>
bool ArbolBinario<T>::eliminarRec(NodoBinario<T>*& nodo, const T& val)
{
    if (!nodo) return false;

    if (val < nodo->getDato()) {
        return eliminarRec(nodo->getHijoIzq(), val);
    }
    else if (val > nodo->getDato()) {
        return eliminarRec(nodo->getHijoDer(), val);
    }
    else {
        // nodo encontrado
        // Caso 1: nodo hoja o con 1 hijo
        if (!nodo->getHijoIzq()) {
            NodoBinario<T>* temp = nodo->getHijoDer();
            delete nodo;
            nodo = temp;
        }
        else if (!nodo->getHijoDer()) {
            NodoBinario<T>* temp = nodo->getHijoIzq();
            delete nodo;
            nodo = temp;
        }
        else {
            // Caso 2: dos hijos
            // Tomamos el sucesor en el subárbol derecho (mínimo de la derecha)
            NodoBinario<T>* sucesor = minValueNode(nodo->getHijoDer());
            // Copiamos el dato
            nodo->setDato(sucesor->getDato());
            // Eliminamos el sucesor duplicado en el subárbol derecho
            eliminarRec(nodo->getHijoDer(), sucesor->getDato());
        }
        return true;
    }
}

template <class T>
bool ArbolBinario<T>::eliminar(T& val)
{
    return eliminarRec(raiz, val);
}

// =====================
//   preOrden / inOrden / posOrden / nivelOrden
// =====================
template <class T>
void ArbolBinario<T>::preOrden(NodoBinario<T>* inicio)
{
    if (!inicio) return;
    std::cout << inicio->getDato() << " ";
    preOrden(inicio->getHijoIzq());
    preOrden(inicio->getHijoDer());
}

template <class T>
void ArbolBinario<T>::inOrden(NodoBinario<T>* inicio)
{
    if (!inicio) return;
    inOrden(inicio->getHijoIzq());
    std::cout << inicio->getDato() << " ";
    inOrden(inicio->getHijoDer());
}

template <class T>
void ArbolBinario<T>::posOrden(NodoBinario<T>* inicio)
{
    if (!inicio) return;
    posOrden(inicio->getHijoIzq());
    posOrden(inicio->getHijoDer());
    std::cout << inicio->getDato() << " ";
}

template <class T>
void ArbolBinario<T>::nivelOrden(NodoBinario<T>* inicio)
{
    if (!inicio) return;
    std::queue<NodoBinario<T>*> cola;
    cola.push(inicio);

    while (!cola.empty()) {
        NodoBinario<T>* actual = cola.front();
        cola.pop();
        std::cout << actual->getDato() << " ";
        if (actual->getHijoIzq()) cola.push(actual->getHijoIzq());
        if (actual->getHijoDer()) cola.push(actual->getHijoDer());
    }
}

#endif // ARBOLBINARIO_HXX
