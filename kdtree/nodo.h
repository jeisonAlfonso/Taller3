#ifndef __NODO_KD_H__
#define __NODO_KD_H__

/**
 * @file nodo.h
 * @brief Definición de la clase Nodo para el KD-Tree.
 *
 * Esta clase representa un nodo en el KD-Tree, el cual almacena un punto (por ejemplo, coordenadas)
 * y punteros a sus hijos (izquierdo y derecho). La estructura se utiliza para construir el árbol de forma
 * que en cada nivel se alterna la dimensión de comparación.
 */

#include <utility>
using namespace std;

template<class T>
class Nodo {
protected:
    pair<T, T> dato;       ///< Dato almacenado en el nodo (por ejemplo, coordenadas X e Y).
    Nodo<T>* izquierdo;    ///< Puntero al hijo izquierdo.
    Nodo<T>* derecho;      ///< Puntero al hijo derecho.

public:
    /**
     * @brief Constructor por defecto.
     * Inicializa los punteros izquierdo y derecho a NULL.
     */
    Nodo();

    /**
     * @brief Constructor que inicializa el nodo con un valor.
     * @param val Par de valores a almacenar.
     */
    Nodo(pair<T, T> val);

    /**
     * @brief Obtiene el dato almacenado en el nodo.
     * @return Par de valores.
     */
    pair<T, T> obtenerDato();

    /**
     * @brief Asigna un nuevo dato al nodo.
     * @param val Nuevo par de valores.
     */
    void fijarDato(pair<T, T> val);

    /**
     * @brief Calcula la altura del subárbol.
     * @return Altura del subárbol.
     */
    int altura();

    /**
     * @brief Calcula el tamaño (cantidad de nodos) del subárbol.
     * @return Número total de nodos.
     */
    int tamano();

    /**
     * @brief Inserta un nuevo valor en el subárbol, alternando la dimensión de comparación según la profundidad.
     * @param val Par de valores a insertar.
     * @param profundidad Nivel actual en el árbol.
     */
    void insertar(pair<T, T> val, unsigned profundidad);

    /**
     * @brief Busca un nodo que contenga el valor especificado, utilizando la alternancia de dimensiones.
     * @param val Par de valores a buscar.
     * @param profundidad Nivel actual en el árbol.
     * @return Puntero al nodo encontrado o NULL si no se encuentra.
     */
    Nodo<T>* buscar(pair<T, T> val, unsigned profundidad);

    /**
     * @brief Realiza un recorrido en preorden del subárbol.
     */
    void preOrden();

    /**
     * @brief Realiza un recorrido en postorden del subárbol.
     */
    void posOrden();
};

#include "Nodo.hxx"
#endif
