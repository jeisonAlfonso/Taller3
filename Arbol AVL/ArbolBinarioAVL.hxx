#ifndef ARBOLBINARIOAVL_HXX
#define ARBOLBINARIOAVL_HXX

#include <iostream>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include <functional>

// =====================
//     CONSTRUCTOR
// =====================
template <class T>
ArbolBinarioAVL<T>::ArbolBinarioAVL()
    : raiz(nullptr)
{
}

// =====================
//     DESTRUCTOR
// =====================
template <class T>
ArbolBinarioAVL<T>::~ArbolBinarioAVL()
{
    // Opción sencilla: no eliminamos nodos recursivamente.
    // En un proyecto real se recomienda liberar todos los nodos (delete).
    // Por ahora lo dejamos así para fines de demostración.
}

// =====================
//     SETTERS & GETTERS
// =====================
template <class T>
void ArbolBinarioAVL<T>::setRaiz(NodoBinarioAVL<T>* r) {
    raiz = r;
}

template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::getRaiz() {
    return raiz;
}

template <class T>
bool ArbolBinarioAVL<T>::esVacio() {
    return (raiz == nullptr);
}

template <class T>
T& ArbolBinarioAVL<T>::datoRaiz() {
    if (!raiz) {
        throw std::runtime_error("Arbol vacio, no hay dato en la raiz.");
    }
    return raiz->dato;
}

// =====================
//     AUXILIARES
// =====================

// Calcula la altura de un subárbol
template <class T>
int ArbolBinarioAVL<T>::altura(NodoBinarioAVL<T>* inicio) {
    if (!inicio) {
        return 0;
    }
    int altIzq = altura(inicio->hijoIzq);
    int altDer = altura(inicio->hijoDer);
    return 1 + std::max(altIzq, altDer);
}

// Calcula el tamaño (# de nodos) de un subárbol
template <class T>
int ArbolBinarioAVL<T>::tamano(NodoBinarioAVL<T>* inicio) {
    if (!inicio) {
        return 0;
    }
    return 1 + tamano(inicio->hijoIzq) + tamano(inicio->hijoDer);
}

// Factor de equilibrio = altura(HijoIzq) - altura(HijoDer)
template <class T>
static int factorEquilibrio(NodoBinarioAVL<T>* nodo, ArbolBinarioAVL<T>* arbol) {
    if(!nodo) return 0;
    return arbol->altura(nodo->hijoIzq) - arbol->altura(nodo->hijoDer);
}

// =====================
//     ROTACIONES
// =====================
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerecha(NodoBinarioAVL<T>*& inicio) {
    NodoBinarioAVL<T>* temp = inicio->hijoIzq;
    inicio->hijoIzq = temp->hijoDer;
    temp->hijoDer = inicio;
    inicio = temp;
    return inicio;
}

template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierda(NodoBinarioAVL<T>*& inicio) {
    NodoBinarioAVL<T>* temp = inicio->hijoDer;
    inicio->hijoDer = temp->hijoIzq;
    temp->hijoIzq = inicio;
    inicio = temp;
    return inicio;
}

template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierdaDerecha(NodoBinarioAVL<T>*& padre) {
    padre->hijoIzq = giroIzquierda(padre->hijoIzq);
    return giroDerecha(padre);
}

template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerechaIzquierda(NodoBinarioAVL<T>*& padre) {
    padre->hijoDer = giroDerecha(padre->hijoDer);
    return giroIzquierda(padre);
}

// =====================
//     INSERTAR
// =====================
template <class T>
bool ArbolBinarioAVL<T>::insertar(T& val) {
    // Función recursiva de inserción + balance
    std::function<NodoBinarioAVL<T>*(NodoBinarioAVL<T>*, T&)> insertarRec;
    
    insertarRec = [&](NodoBinarioAVL<T>* nodo, T& v) -> NodoBinarioAVL<T>* {
        if (!nodo) {
            // Crear nodo nuevo
            NodoBinarioAVL<T>* nuevo = new NodoBinarioAVL<T>();
            nuevo->dato = v;
            return nuevo;
        }
        // Comparar y bajar a izq/der
        if (v < nodo->dato) {
            nodo->hijoIzq = insertarRec(nodo->hijoIzq, v);
        } else if (v > nodo->dato) {
            nodo->hijoDer = insertarRec(nodo->hijoDer, v);
        } else {
            // Si es igual, asumimos que no lo insertamos de nuevo
            return nodo;
        }

        // Verificamos factor de equilibrio y aplicamos rotaciones
        int fe = factorEquilibrio(nodo, this);

        // Desbalance izquierda
        if (fe > 1) {
            // Caso Izq-Izq
            if (v < nodo->hijoIzq->dato) {
                nodo = giroDerecha(nodo);
            }
            // Caso Izq-Der
            else {
                nodo = giroIzquierdaDerecha(nodo);
            }
        }
        // Desbalance derecha
        else if (fe < -1) {
            // Caso Der-Der
            if (v > nodo->hijoDer->dato) {
                nodo = giroIzquierda(nodo);
            }
            // Caso Der-Izq
            else {
                nodo = giroDerechaIzquierda(nodo);
            }
        }

        return nodo;
    };

    // Llamada a la recursiva
    raiz = insertarRec(raiz, val);
    return true;
}

// =====================
//     ELIMINAR
// =====================
template <class T>
bool ArbolBinarioAVL<T>::eliminar(T& val) {
    // Función recursiva de eliminación + balance
    std::function<NodoBinarioAVL<T>*(NodoBinarioAVL<T>*, T&)> eliminarRec;
    eliminarRec = [&](NodoBinarioAVL<T>* nodo, T& v) -> NodoBinarioAVL<T>* {
        if (!nodo) {
            return nullptr; // no se encuentra, no hay nada que eliminar
        }
        if (v < nodo->dato) {
            nodo->hijoIzq = eliminarRec(nodo->hijoIzq, v);
        } else if (v > nodo->dato) {
            nodo->hijoDer = eliminarRec(nodo->hijoDer, v);
        } else {
            // Nodo encontrado
            if (!nodo->hijoIzq || !nodo->hijoDer) {
                // Caso de 0 o 1 hijo
                NodoBinarioAVL<T>* temp = (nodo->hijoIzq) ? nodo->hijoIzq : nodo->hijoDer;
                delete nodo;
                return temp;
            } else {
                // Caso de 2 hijos: buscamos sucesor (mínimo de subárbol derecho)
                NodoBinarioAVL<T>* temp = nodo->hijoDer;
                while (temp->hijoIzq) {
                    temp = temp->hijoIzq;
                }
                // Copiamos el dato del sucesor
                nodo->dato = temp->dato;
                // Eliminamos el sucesor
                nodo->hijoDer = eliminarRec(nodo->hijoDer, temp->dato);
            }
        }

        // Re-balancear
        if (!nodo) return nodo; // si se eliminó y quedó en null
        int fe = factorEquilibrio(nodo, this);

        // Desbalance izquierda
        if (fe > 1) {
            if (factorEquilibrio(nodo->hijoIzq, this) >= 0) {
                nodo = giroDerecha(nodo);
            } else {
                nodo = giroIzquierdaDerecha(nodo);
            }
        }
        // Desbalance derecha
        else if (fe < -1) {
            if (factorEquilibrio(nodo->hijoDer, this) <= 0) {
                nodo = giroIzquierda(nodo);
            } else {
                nodo = giroDerechaIzquierda(nodo);
            }
        }

        return nodo;
    };

    raiz = eliminarRec(raiz, val);
    return true;
}

// =====================
//     BUSCAR
// =====================
template <class T>
bool ArbolBinarioAVL<T>::buscar(T& val) {
    NodoBinarioAVL<T>* actual = raiz;
    while (actual) {
        if (val == actual->dato) {
            return true;
        } else if (val < actual->dato) {
            actual = actual->hijoIzq;
        } else {
            actual = actual->hijoDer;
        }
    }
    return false;
}

// =====================
//     RECORRIDOS
// =====================

// Preorden
template <class T>
void ArbolBinarioAVL<T>::preOrden(NodoBinarioAVL<T>* inicio) {
    if (!inicio) return;
    std::cout << inicio->dato << " ";
    preOrden(inicio->hijoIzq);
    preOrden(inicio->hijoDer);
}

// Inorden
template <class T>
void ArbolBinarioAVL<T>::inOrden(NodoBinarioAVL<T>* inicio) {
    if (!inicio) return;
    inOrden(inicio->hijoIzq);
    std::cout << inicio->dato << " ";
    inOrden(inicio->hijoDer);
}

// Posorden
template <class T>
void ArbolBinarioAVL<T>::posOrden(NodoBinarioAVL<T>* inicio) {
    if (!inicio) return;
    posOrden(inicio->hijoIzq);
    posOrden(inicio->hijoDer);
    std::cout << inicio->dato << " ";
}

// Nivel-orden (BFS)
template <class T>
void ArbolBinarioAVL<T>::nivelOrden(NodoBinarioAVL<T>* inicio) {
    if (!inicio) return;
    std::queue<NodoBinarioAVL<T>*> cola;
    cola.push(inicio);

    while(!cola.empty()) {
        NodoBinarioAVL<T>* actual = cola.front();
        cola.pop();
        std::cout << actual->dato << " ";
        if(actual->hijoIzq) cola.push(actual->hijoIzq);
        if(actual->hijoDer) cola.push(actual->hijoDer);
    }
}

#endif // ARBOLBINARIOAVL_HXX



