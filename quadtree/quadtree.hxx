#include <bits/stdc++.h>
#include "quadtree.h"
using namespace std;

/**
 * @brief Constructor por defecto.
 * Inicializa la raíz del árbol a NULL.
 */
template<class T>
Arbol<T>::Arbol() {
    raiz = NULL;
}

/**
 * @brief Constructor que inicializa el árbol con un nodo raíz.
 * Crea un nuevo nodo con el valor recibido y lo asigna como raíz.
 * @param val Par de valores para el nodo raíz.
 */
template<class T>
Arbol<T>::Arbol(pair<T,T> val) {
    raiz = new Nodo<T>(val);
}

/**
 * @brief Verifica si el árbol está vacío.
 * @return true si la raíz es NULL, false en caso contrario.
 */
template<class T>
bool Arbol<T>::esVacio() {
    return (raiz == NULL);
}

/**
 * @brief Obtiene el dato almacenado en la raíz.
 * @return Par de valores del nodo raíz.
 */
template<class T>
pair<T,T> Arbol<T>::obtenerRaiz() {
    return raiz->obtenerDato();
}

/**
 * @brief Establece la raíz del árbol.
 * @param root Puntero al nuevo nodo raíz.
 */
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root) {
    this->raiz = root;
}

/**
 * @brief Calcula la altura del árbol.
 * Se utiliza el método altura() del nodo raíz.
 * @return Altura del árbol o 0 si está vacío.
 */
template<class T>
int Arbol<T>::altura() {
    if(raiz != NULL)
        return raiz->altura();
    return 0;
}

/**
 * @brief Calcula el tamaño (cantidad de nodos) del árbol.
 * Se utiliza el método tamano() del nodo raíz.
 * @return Número total de nodos o 0 si el árbol está vacío.
 */
template<class T>
int Arbol<T>::tamano() {
    if(raiz != NULL)
        return raiz->tamano();
    return 0;
}

/**
 * @brief Inserta un nuevo valor en el árbol.
 * Si el árbol está vacío, crea el nodo raíz; de lo contrario, inserta recursivamente.
 * @param val Par de valores a insertar.
 */
template<class T>
void Arbol<T>::insertar(pair<T,T> val) {
    if(raiz == NULL) {
        raiz = new Nodo<T>(val);
    } else {
        raiz->insertar(val);
    }
}

/**
 * @brief Sobrecarga del método insertar (no implementado).
 * @param val Valor a insertar.
 */
template<class T>
void Arbol<T>::insertar(T& val) {
    // Implementación opcional para otro tipo de inserción.
}

/**
 * @brief Método eliminar (no implementado).
 * @param val Valor a eliminar.
 * @return false, ya que no se ha implementado.
 */
template<class T>
bool Arbol<T>::eliminar(T& val) {
    return false;
}

/**
 * @brief Busca un nodo que contenga el valor especificado.
 * @param val Par de valores a buscar.
 * @return Puntero al nodo encontrado o NULL si el árbol está vacío o no se encuentra.
 */
template<class T>
Nodo<T>* Arbol<T>::buscar(pair<T,T> val) {
    if(raiz != NULL)
        return raiz->buscar(val);
    return NULL;
}

/**
 * @brief Realiza un recorrido en preorden del árbol.
 */
template<class T>
void Arbol<T>::preOrden() {
    if(raiz != NULL)
        raiz->preOrden();
}

/**
 * @brief Realiza un recorrido en postorden del árbol.
 */
template<class T>
void Arbol<T>::posOrden() {
    if(raiz != NULL)
        raiz->posOrden();
}
