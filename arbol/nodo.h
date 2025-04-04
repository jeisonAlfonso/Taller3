#ifndef NODO_H
#define NODO_H

/**
 * @file nodo.h
 * @brief Definición de la clase Nodo para el árbol binario.
 *
 * Este archivo define la clase Nodo, la cual representa un nodo en un árbol binario.
 * Cada nodo almacena un dato de tipo T y punteros a sus hijos (izquierdo y derecho).
 */

#include <iostream>
using namespace std;

template <class T>
class Nodo {
protected:
    T dato;           ///< Dato almacenado en el nodo.
    Nodo<T>* izq;     ///< Puntero al hijo izquierdo.
    Nodo<T>* der;     ///< Puntero al hijo derecho.
public:
    /**
     * @brief Constructor por defecto.
     * Inicializa el nodo sin dato y con punteros a NULL.
     */
    Nodo();

    /**
     * @brief Constructor que inicializa el nodo con un dato.
     * @param dato Dato a almacenar en el nodo.
     */
    Nodo(T dato);

    /**
     * @brief Obtiene el dato almacenado en el nodo.
     * @return Dato almacenado.
     */
    T obtenerDato();

    /**
     * @brief Establece el dato del nodo.
     * @param dato Nuevo dato a asignar.
     */
    void fijarDato(T dato);

    /**
     * @brief Inserta un nuevo dato en el subárbol.
     * @param dato Dato a insertar.
     */
    void insertar(T dato);

    /**
     * @brief Realiza un recorrido en preorden del subárbol.
     */
    void preOrden();

    /**
     * @brief Realiza un recorrido en postorden del subárbol.
     */
    void posOrden();

    /**
     * @brief Calcula la altura del subárbol.
     * @return Altura del subárbol.
     */
    int altura();

    /**
     * @brief Calcula el tamaño (cantidad de nodos) del subárbol.
     * @return Número total de nodos en el subárbol.
     */
    int tamano();

    /**
     * @brief Busca un nodo con el dato especificado.
     * @param dato Dato a buscar.
     * @return Puntero al nodo encontrado o NULL si no se encuentra.
     */
    Nodo<T>* buscar(T dato);
};

#include "nodo.hxx"
#endif
