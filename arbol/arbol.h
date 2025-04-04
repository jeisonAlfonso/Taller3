#ifndef ARBOL_H
#define ARBOL_H

/**
 * @file arbol.h
 * @brief Definición de la clase Arbol para un árbol binario.
 *
 * La clase Arbol encapsula la estructura de un árbol binario, administrando la raíz
 * y delegando las operaciones de inserción, búsqueda y recorridos en la clase Nodo.
 */

#include "nodo.h"
using namespace std;

template <class T>
class Arbol {
protected:
    Nodo<T>* raiz; ///< Puntero a la raíz del árbol.
public:
    /**
     * @brief Constructor por defecto.
     * Inicializa el árbol con la raíz en nullptr.
     */
    Arbol();

    /**
     * @brief Constructor que inicializa el árbol con un dato en la raíz.
     * @param dato Dato para el nodo raíz.
     */
    Arbol(T dato);

    /**
     * @brief Verifica si el árbol está vacío.
     * @return true si la raíz es nullptr, false en caso contrario.
     */
    bool esVacio();

    /**
     * @brief Obtiene el dato almacenado en la raíz.
     * @return Dato de la raíz.
     */
    T obtenerRaiz();

    /**
     * @brief Inserta un nuevo dato en el árbol.
     * @param dato Dato a insertar.
     */
    void insertar(T dato);

    /**
     * @brief Realiza un recorrido en preorden del árbol.
     */
    void preOrden();

    /**
     * @brief Realiza un recorrido en postorden del árbol.
     */
    void posOrden();

    /**
     * @brief Calcula la altura del árbol.
     * @return Altura del árbol.
     */
    int altura();

    /**
     * @brief Calcula el tamaño (cantidad de nodos) del árbol.
     * @return Número total de nodos.
     */
    int tamano();

    /**
     * @brief Busca un nodo con el dato especificado.
     * @param dato Dato a buscar.
     * @return Puntero al nodo encontrado o nullptr si no se encuentra.
     */
    Nodo<T>* buscar(T dato);
};

#include "arbol.hxx"
#endif
