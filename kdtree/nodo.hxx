#include "nodo.h"
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Constructor por defecto.
 * Inicializa los punteros izquierdo y derecho a NULL.
 */
template<class T>
Nodo<T>::Nodo() {
    izquierdo = NULL;
    derecho = NULL;
}

/**
 * @brief Constructor que inicializa el nodo con un valor.
 * @param val Par de valores a almacenar.
 */
template<class T>
Nodo<T>::Nodo(pair<T, T> val) {
    dato = val;
    izquierdo = NULL;
    derecho = NULL;
}

/**
 * @brief Obtiene el dato almacenado en el nodo.
 * @return Par de valores.
 */
template<class T>
pair<T, T> Nodo<T>::obtenerDato() {
    return dato;
}

/**
 * @brief Asigna un nuevo dato al nodo.
 * @param val Nuevo par de valores.
 */
template<class T>
void Nodo<T>::fijarDato(pair<T, T> val) {
    dato = val;
}

/**
 * @brief Calcula la altura del subárbol.
 * @return Altura del subárbol.
 */
template<class T>
int Nodo<T>::altura() {
    if (izquierdo == NULL && derecho == NULL)
        return 1;
    int altIzq = (izquierdo != NULL) ? izquierdo->altura() : 0;
    int altDer = (derecho != NULL) ? derecho->altura() : 0;
    return max(altIzq, altDer) + 1;
}

/**
 * @brief Calcula el tamaño (cantidad de nodos) del subárbol.
 * @return Número total de nodos.
 */
template<class T>
int Nodo<T>::tamano() {
    int total = 1;
    if (izquierdo != NULL)
        total += izquierdo->tamano();
    if (derecho != NULL)
        total += derecho->tamano();
    return total;
}

/**
 * @brief Inserta un nuevo valor en el subárbol, alternando la dimensión de comparación según la profundidad.
 * @param val Par de valores a insertar.
 * @param profundidad Nivel actual en el árbol.
 */
template<class T>
void Nodo<T>::insertar(pair<T, T> val, unsigned profundidad) {
    bool compararPrimera = (profundidad % 2 == 0);
    if (compararPrimera) {
        if (val.first < dato.first) {
            if (izquierdo != NULL)
                izquierdo->insertar(val, profundidad + 1);
            else {
                Nodo<T>* nuevo = new Nodo<T>(val);
                izquierdo = nuevo;
            }
        } else {
            if (derecho != NULL)
                derecho->insertar(val, profundidad + 1);
            else {
                Nodo<T>* nuevo = new Nodo<T>(val);
                derecho = nuevo;
            }
        }
    } else {
        if (val.second < dato.second) {
            if (izquierdo != NULL)
                izquierdo->insertar(val, profundidad + 1);
            else {
                Nodo<T>* nuevo = new Nodo<T>(val);
                izquierdo = nuevo;
            }
        } else {
            if (derecho != NULL)
                derecho->insertar(val, profundidad + 1);
            else {
                Nodo<T>* nuevo = new Nodo<T>(val);
                derecho = nuevo;
            }
        }
    }
}

/**
 * @brief Busca un nodo que contenga el valor especificado, utilizando la alternancia de dimensiones.
 * @param val Par de valores a buscar.
 * @param profundidad Nivel actual en el árbol.
 * @return Puntero al nodo encontrado o NULL si no se encuentra.
 */
template<class T>
Nodo<T>* Nodo<T>::buscar(pair<T, T> val, unsigned profundidad) {
    if (dato == val)
        return this;
    bool compararPrimera = (profundidad % 2 == 0);
    if (compararPrimera) {
        if (val.first < dato.first) {
            if (izquierdo != NULL)
                return izquierdo->buscar(val, profundidad + 1);
        } else {
            if (derecho != NULL)
                return derecho->buscar(val, profundidad + 1);
        }
    } else {
        if (val.second < dato.second) {
            if (izquierdo != NULL)
                return izquierdo->buscar(val, profundidad + 1);
        } else {
            if (derecho != NULL)
                return derecho->buscar(val, profundidad + 1);
        }
    }
    return NULL;
}

/**
 * @brief Realiza un recorrido en preorden del subárbol.
 */
template<class T>
void Nodo<T>::preOrden() {
    cout << "(" << dato.first << ", " << dato.second << ")" << endl;
    if (izquierdo != NULL)
        izquierdo->preOrden();
    if (derecho != NULL)
        derecho->preOrden();
}

/**
 * @brief Realiza un recorrido en postorden del subárbol.
 */
template<class T>
void Nodo<T>::posOrden() {
    if (izquierdo != NULL)
        izquierdo->posOrden();
    if (derecho != NULL)
        derecho->posOrden();
    cout << "(" << dato.first << ", " << dato.second << ")" << endl;
}
