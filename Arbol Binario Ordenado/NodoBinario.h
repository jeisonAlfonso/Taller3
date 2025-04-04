#ifndef NODOBINARIO_H
#define NODOBINARIO_H

/**
 * NodoBinario.h
 * Clase plantilla que define un nodo para un árbol binario.
 * Guarda un dato de tipo T y punteros a sus hijos izquierdo y derecho.
 */

template <class T>
class NodoBinario {
protected:
    T dato;                      // Valor que guarda el nodo
    NodoBinario<T>* hijoIzq;    // Puntero al hijo izquierdo
    NodoBinario<T>* hijoDer;    // Puntero al hijo derecho

public:
    /**
     * @brief Constructor por defecto. Inicializa punteros en nullptr.
     */
    NodoBinario();

    /**
     * @brief Destructor por defecto (no hace liberación recursiva).
     */
    ~NodoBinario();

    /**
     * @brief Retorna referencia al dato almacenado en el nodo.
     */
    T& getDato();

    /**
     * @brief Asigna un nuevo valor al nodo.
     * @param val Referencia al valor que se va a fijar.
     */
    void setDato(const T& val);

    /**
     * @brief Obtiene el hijo izquierdo.
     */
    NodoBinario<T>* getHijoIzq();

    /**
     * @brief Obtiene el hijo derecho.
     */
    NodoBinario<T>* getHijoDer();

    /**
     * @brief Ajusta el puntero al hijo izquierdo.
     */
    void setHijoIzq(NodoBinario<T>* izq);

    /**
     * @brief Ajusta el puntero al hijo derecho.
     */
    void setHijoDer(NodoBinario<T>* der);
};

#include "NodoBinario.hxx"

#endif // NODOBINARIO_H

