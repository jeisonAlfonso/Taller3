#ifndef __NODO__H__
#define __NODO__H__

/**
 * @file nodo.h
 * @brief Definición de la clase Nodo para el QuadTree.
 *
 * Esta clase representa un nodo en el QuadTree, que almacena un par de valores 
 * (por ejemplo, coordenadas) y punteros a sus hijos en las direcciones:
 * NW (noroeste), NE (noreste), SW (suroeste) y SE (sureste).
 */

#include <utility>
using namespace std;

template<class T>
class Nodo {
protected:
    pair<T,T> dato; ///< Dato almacenado en el nodo (por ejemplo, coordenadas X e Y).
    Nodo<T>* NW;    ///< Puntero al hijo en el cuadrante noroeste.
    Nodo<T>* NE;    ///< Puntero al hijo en el cuadrante noreste.
    Nodo<T>* SW;    ///< Puntero al hijo en el cuadrante suroeste.
    Nodo<T>* SE;    ///< Puntero al hijo en el cuadrante sureste.

public:
    /**
     * @brief Constructor por defecto.
     * Inicializa los punteros hijos a NULL.
     */
    Nodo();

    /**
     * @brief Constructor que inicializa el nodo con un valor.
     * @param val Par de valores que representa los datos del nodo.
     */
    Nodo(pair<T,T> val);

    /**
     * @brief Calcula la altura del subárbol con raíz en este nodo.
     * @return Altura del subárbol.
     */
    int altura();

    /**
     * @brief Calcula el tamaño (número de nodos) del subárbol con raíz en este nodo.
     * @return Tamaño del subárbol.
     */
    int tamano();

    /**
     * @brief Obtiene el dato almacenado en el nodo.
     * @return Par de valores almacenados.
     */
    pair<T,T> obtenerDato();

    /**
     * @brief Inserta un nuevo valor en el subárbol.
     * @param val Par de valores a insertar.
     */
    void insertar(pair<T,T> val);

    /**
     * @brief Establece el dato del nodo.
     * @param val Nuevo par de valores a asignar al nodo.
     */
    void fijarDato(pair<T,T> val);

    /**
     * @brief Realiza un recorrido en preorden del subárbol.
     */
    void preOrden();

    /**
     * @brief Realiza un recorrido en postorden del subárbol.
     */
    void posOrden();

    /**
     * @brief Busca un nodo que contenga el valor especificado.
     * @param val Par de valores a buscar.
     * @return Puntero al nodo encontrado o NULL si no se encuentra.
     */
    Nodo* buscar(pair<T,T> val);
};

#include "Nodo.hxx"
#endif
