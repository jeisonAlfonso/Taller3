#include <bits/stdc++.h>
#include "kdtree.h"
using namespace std;

/**
 * @brief Constructor por defecto.
 * Inicializa el KD-Tree sin nodo raíz.
 */
template<class T>
KDTree<T>::KDTree() {
    raiz = NULL;
}

/**
 * @brief Constructor que inicializa el KD-Tree con un nodo raíz.
 * @param val Par de valores para el nodo raíz.
 */
template<class T>
KDTree<T>::KDTree(pair<T, T> val) {
    raiz = new Nodo<T>(val);
}

/**
 * @brief Verifica si el KD-Tree está vacío.
 * @return true si la raíz es NULL, false en caso contrario.
 */
template<class T>
bool KDTree<T>::esVacio() {
    return (raiz == NULL);
}

/**
 * @brief Obtiene el dato almacenado en la raíz.
 * @return Par de valores del nodo raíz.
 */
template<class T>
pair<T, T> KDTree<T>::obtenerRaiz() {
    return raiz->obtenerDato();
}

/**
 * @brief Inserta un nuevo valor en el KD-Tree.
 * Si el árbol está vacío, crea el nodo raíz; de lo contrario, inserta recursivamente comenzando en la raíz con profundidad 0.
 * @param val Par de valores a insertar.
 */
template<class T>
void KDTree<T>::insertar(pair<T, T> val) {
    if (raiz == NULL) {
        raiz = new Nodo<T>(val);
    } else {
        raiz->insertar(val, 0);
    }
}

/**
 * @brief Busca un nodo que contenga el valor especificado.
 * @param val Par de valores a buscar.
 * @return Puntero al nodo encontrado o NULL si no se encuentra.
 */
template<class T>
Nodo<T>* KDTree<T>::buscar(pair<T, T> val) {
    if (raiz != NULL)
        return raiz->buscar(val, 0);
    return NULL;
}

/**
 * @brief Realiza un recorrido en preorden del KD-Tree.
 */
template<class T>
void KDTree<T>::preOrden() {
    if (raiz != NULL)
        raiz->preOrden();
}

/**
 * @brief Realiza un recorrido en postorden del KD-Tree.
 */
template<class T>
void KDTree<T>::posOrden() {
    if (raiz != NULL)
        raiz->posOrden();
}

/**
 * @brief Calcula la altura del KD-Tree.
 * @return Altura del árbol o 0 si está vacío.
 */
template<class T>
int KDTree<T>::altura() {
    if (raiz != NULL)
        return raiz->altura();
    return 0;
}

/**
 * @brief Calcula el tamaño (cantidad de nodos) del KD-Tree.
 * @return Número total de nodos o 0 si el árbol está vacío.
 */
template<class T>
int KDTree<T>::tamano() {
    if (raiz != NULL)
        return raiz->tamano();
    return 0;
}
