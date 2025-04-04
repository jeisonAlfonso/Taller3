#ifndef __KDTREE__H__
#define __KDTREE__H__

/**
 * @file kdtree.h
 * @brief Definición de la clase KDTree para el KD-Tree.
 *
 * Esta clase implementa un KD-Tree para almacenar puntos en 2D (o k dimensiones) utilizando nodos de tipo Nodo.
 * Permite realizar inserciones, búsquedas y recorridos (preorden y postorden) de forma eficiente.
 */

#include "nodo.h"
using namespace std;

template<class T>
class KDTree {
protected:
    Nodo<T>* raiz; ///< Puntero a la raíz del KD-Tree.
public:
    /**
     * @brief Constructor por defecto.
     * Inicializa el KD-Tree sin nodo raíz.
     */
    KDTree();

    /**
     * @brief Constructor que inicializa el KD-Tree con un nodo raíz.
     * @param val Par de valores para el nodo raíz.
     */
    KDTree(pair<T, T> val);

    /**
     * @brief Verifica si el árbol está vacío.
     * @return true si la raíz es NULL, false en caso contrario.
     */
    bool esVacio();

    /**
     * @brief Obtiene el dato almacenado en la raíz.
     * @return Par de valores del nodo raíz.
     */
    pair<T, T> obtenerRaiz();

    /**
     * @brief Inserta un nuevo valor en el KD-Tree.
     * Si el árbol está vacío, se crea el nodo raíz; de lo contrario, se inserta recursivamente comenzando en la raíz con profundidad 0.
     * @param val Par de valores a insertar.
     */
    void insertar(pair<T, T> val);

    /**
     * @brief Busca un nodo que contenga el valor especificado.
     * @param val Par de valores a buscar.
     * @return Puntero al nodo encontrado o NULL si no se encuentra.
     */
    Nodo<T>* buscar(pair<T, T> val);

    /**
     * @brief Realiza un recorrido en preorden del KD-Tree.
     */
    void preOrden();

    /**
     * @brief Realiza un recorrido en postorden del KD-Tree.
     */
    void posOrden();

    /**
     * @brief Calcula la altura del KD-Tree.
     * @return Altura del árbol o 0 si está vacío.
     */
    int altura();

    /**
     * @brief Calcula el tamaño (cantidad de nodos) del KD-Tree.
     * @return Número total de nodos o 0 si el árbol está vacío.
     */
    int tamano();
};

#include "kdtree.hxx"
#endif
