#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoBinario.h"

/**
 * ArbolBinario.h
 * Clase plantilla que administra un árbol binario de búsqueda a través de un puntero a su raíz.
 */

template <class T>
class ArbolBinario {
protected:
    NodoBinario<T>* raiz;  // Puntero a la raíz del árbol

    /**
     * @brief Función auxiliar para eliminar recursivamente todos los nodos (usado en el destructor).
     */
    void destruirSubarbol(NodoBinario<T>* nodo);

    /**
     * @brief Inserción recursiva estilo BST, usada internamente por insertar(T&, NodoBinario<T>*).
     * @param nodo Referencia al puntero del subárbol donde insertar
     * @param val Valor que se inserta
     * @return true si se insertó nuevo nodo, false si val ya existía
     */
    bool insertarRec(NodoBinario<T>*& nodo, const T& val);

    /**
     * @brief Busca recursivamente val en el subárbol que inicia en nodo.
     * @param nodo Raíz del subárbol
     * @param val Valor a buscar
     * @return true si se encuentra, false si no
     */
    bool buscarRec(NodoBinario<T>* nodo, const T& val);

    /**
     * @brief Elimina recursivamente val de un subárbol.
     * @param nodo referencia al puntero raíz del subárbol
     * @param val valor a eliminar
     * @return true si se eliminó, false si no se encontró
     */
    bool eliminarRec(NodoBinario<T>*& nodo, const T& val);

    /**
     * @brief Retorna el nodo con valor mínimo dentro del subárbol.
     *        Se usa para reorganizar en la eliminación cuando hay dos hijos.
     */
    NodoBinario<T>* minValueNode(NodoBinario<T>* nodo);

public:
    /**
     * @brief Constructor: pone raiz en nullptr.
     */
    ArbolBinario();

    /**
     * @brief Destructor, libera todos los nodos de forma recursiva.
     */
    ~ArbolBinario();

    /**
     * @brief Verifica si el árbol está vacío.
     */
    bool esVacio();

    /**
     * @brief Retorna el dato de la raíz.
     * @warning Asume que el árbol no está vacío.
     */
    T& datoRaiz();

    /**
     * @brief Calcula la altura de un subárbol.
     * @param inicio puntero al nodo raíz del subárbol.
     * @return altura del subárbol.
     */
    int altura(NodoBinario<T>* inicio);

    /**
     * @brief Calcula el número total de nodos del subárbol que inicia en 'inicio'.
     */
    int tamano(NodoBinario<T>* inicio);

    /**
     * @brief Inserta un valor en el subárbol apuntado por 'nodo' (BST).
     *        Si 'nodo' es nullptr y el árbol está vacío, crea la raíz.
     * @param val valor a insertar
     * @param nodo raíz del subárbol
     * @return true si se insertó, false si ya existía
     */
    bool insertar(T& val, NodoBinario<T>* nodo);

    /**
     * @brief Elimina un valor del árbol (lógica estilo BST).
     * @param val valor a eliminar
     * @return true si se encontró y eliminó, false si no existe
     */
    bool eliminar(T& val);

    /**
     * @brief Busca val en todo el árbol.
     * @param val valor a buscar
     * @return true si se encontró, false si no
     */
    bool buscar(T& val);

    /**
     * @brief Recorre en preorden el subárbol con raíz en 'inicio'.
     */
    void preOrden(NodoBinario<T>* inicio);

    /**
     * @brief Recorre en inorden el subárbol con raíz en 'inicio'.
     */
    void inOrden(NodoBinario<T>* inicio);

    /**
     * @brief Recorre en posorden el subárbol con raíz en 'inicio'.
     */
    void posOrden(NodoBinario<T>* inicio);

    /**
     * @brief Recorre en orden por niveles (BFS) el subárbol con raíz en 'inicio'.
     */
    void nivelOrden(NodoBinario<T>* inicio);
};

#include "ArbolBinario.hxx"

#endif // ARBOLBINARIO_H
