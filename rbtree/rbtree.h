#ifndef RBTREE_H
#define RBTREE_H

/**
 * @file rbtree.h
 * @brief Definición de la clase RBTree para el árbol rojo-negro.
 *
 * Se define la estructura del nodo (RBNode) que almacena un dato de tipo T,
 * un color (RED o BLACK), y punteros al padre, hijo izquierdo y derecho.
 * La clase RBTree encapsula la estructura del árbol rojo-negro, implementando
 * la inserción con balanceo mediante rotaciones y fixups, así como búsquedas y recorridos.
 */

#include <iostream>
using namespace std;

// Definición de los posibles colores para los nodos.
enum Color { RED, BLACK };

template <typename T>
class RBNode {
public:
    T data;               ///< Dato almacenado en el nodo.
    Color color;          ///< Color del nodo (RED o BLACK).
    RBNode<T>* parent;    ///< Puntero al nodo padre.
    RBNode<T>* left;      ///< Puntero al hijo izquierdo.
    RBNode<T>* right;     ///< Puntero al hijo derecho.

    /**
     * @brief Constructor que inicializa un nodo con un dato.
     * @param data Dato a almacenar.
     *
     * Por defecto, el nodo se crea de color RED.
     */
    RBNode(T data);
};

template <typename T>
class RBTree {
private:
    RBNode<T>* root;   ///< Puntero a la raíz del árbol.
    RBNode<T>* NIL;    ///< Nodo centinela que representa las hojas (nodos NIL).

    // Funciones auxiliares para las rotaciones y balanceo.
    void leftRotate(RBNode<T>* x);
    void rightRotate(RBNode<T>* y);
    void insertFixup(RBNode<T>* z);
    void inOrderHelper(RBNode<T>* node) const;
    RBNode<T>* searchHelper(RBNode<T>* node, T key) const;

public:
    /**
     * @brief Constructor por defecto.
     * Inicializa el árbol creando el nodo centinela NIL y estableciendo la raíz en NIL.
     */
    RBTree();

    /**
     * @brief Destructor.
     * Libera la memoria utilizada por el árbol.
     */
    ~RBTree();

    /**
     * @brief Inserta un nuevo dato en el árbol.
     * @param key Dato a insertar.
     */
    void insert(T key);

    /**
     * @brief Busca un nodo con el dato especificado.
     * @param key Dato a buscar.
     * @return Puntero al nodo encontrado o nullptr si no se encuentra.
     */
    RBNode<T>* search(T key) const;

    /**
     * @brief Realiza un recorrido InOrder del árbol.
     * Muestra los datos y el color de cada nodo.
     */
    void inOrder() const;
};

#include "rbtree.hxx"
#endif
