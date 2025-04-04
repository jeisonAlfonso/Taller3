#ifndef __QUADTREE__H__
#define __QUADTREE__H__

/**
 * @file quadtree.h
 * @brief Definición de la clase Arbol para el QuadTree.
 *
 * La clase Arbol encapsula la estructura del QuadTree, gestionando la raíz y
 * delegando las operaciones (inserción, búsqueda, recorridos, etc.) a la clase Nodo.
 */

#include "Nodo.h"
using namespace std;

template<class T>
class Arbol {
protected:
    Nodo<T> *raiz; ///< Puntero a la raíz del QuadTree.
public:
    /**
     * @brief Constructor por defecto.
     * Inicializa el árbol sin nodo raíz (NULL).
     */
    Arbol();

    /**
     * @brief Constructor que inicializa el árbol con un nodo raíz.
     * @param val Valor inicial (par de datos) para el nodo raíz.
     */
    Arbol(pair<T,T> val);

    /**
     * @brief Verifica si el árbol está vacío.
     * @return true si la raíz es NULL, false en caso contrario.
     */
    bool esVacio();

    /**
     * @brief Obtiene el dato almacenado en la raíz.
     * @return Par de valores del nodo raíz.
     */
    pair<T,T> obtenerRaiz();

    /**
     * @brief Establece la raíz del árbol.
     * @param root Puntero al nuevo nodo raíz.
     */
    void fijarRaiz(Nodo<T>* root);

    /**
     * @brief Inserta un nuevo valor en el árbol.
     * @param val Par de valores a insertar.
     */
    void insertar(pair<T,T> val);

    /**
     * @brief Calcula la altura del árbol.
     * @return Altura del árbol.
     */
    int altura();

    /**
     * @brief Calcula el tamaño (número de nodos) del árbol.
     * @return Número total de nodos o 0 si el árbol está vacío.
     */
    int tamano();

    /**
     * @brief Inserta un valor (sobrecarga, no implementada).
     * @param val Valor a insertar.
     */
    void insertar(T& val);

    /**
     * @brief Elimina un nodo con el valor especificado (funcionalidad no implementada).
     * @param val Valor a eliminar.
     * @return true si la eliminación fue exitosa, false en caso contrario.
     */
    bool eliminar(T& val);

    /**
     * @brief Busca un nodo que contenga el valor especificado.
     * @param val Par de valores a buscar.
     * @return Puntero al nodo encontrado o NULL si no se encuentra.
     */
    Nodo<T>* buscar(pair<T,T> val);

    /**
     * @brief Realiza un recorrido en preorden del árbol.
     */
    void preOrden();

    /**
     * @brief Realiza un recorrido en postorden del árbol.
     */
    void posOrden();
};

#include "quadtree.hxx"
#endif
