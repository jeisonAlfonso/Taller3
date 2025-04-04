#include "rbtree.h"
#include <queue>
using namespace std;

template <typename T>
RBNode<T>::RBNode(T data) : data(data), color(RED), parent(nullptr), left(nullptr), right(nullptr) {
    // Constructor: inicializa el nodo con el dato dado y color rojo.
}

template <typename T>
RBTree<T>::RBTree() {
    // Se crea el nodo NIL (hoja centinela), de color BLACK.
    NIL = new RBNode<T>(T());
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = nullptr;
    root = NIL;
}

template <typename T>
RBTree<T>::~RBTree() {
    // Se debe liberar la memoria de los nodos.
    // Para simplificar, se omite una implementación completa de la eliminación recursiva.
    delete NIL;
}

template <typename T>
void RBTree<T>::leftRotate(RBNode<T>* x) {
    RBNode<T>* y = x->right;
    x->right = y->left;
    if(y->left != NIL)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == nullptr)
        root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

template <typename T>
void RBTree<T>::rightRotate(RBNode<T>* y) {
    RBNode<T>* x = y->left;
    y->left = x->right;
    if(x->right != NIL)
        x->right->parent = y;
    x->parent = y->parent;
    if(y->parent == nullptr)
        root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

template <typename T>
void RBTree<T>::insertFixup(RBNode<T>* z) {
    while(z->parent != nullptr && z->parent->color == RED) {
        if(z->parent == z->parent->parent->left) {
            RBNode<T>* y = z->parent->parent->right;
            if(y->color == RED) {
                // Caso 1: Tío rojo.
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if(z == z->parent->right) {
                    // Caso 2: z es hijo derecho.
                    z = z->parent;
                    leftRotate(z);
                }
                // Caso 3: z es hijo izquierdo.
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            RBNode<T>* y = z->parent->parent->left;
            if(y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if(z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

template <typename T>
void RBTree<T>::insert(T key) {
    RBNode<T>* z = new RBNode<T>(key);
    z->left = z->right = z->parent = NIL;
    RBNode<T>* y = nullptr;
    RBNode<T>* x = root;
    while(x != NIL) {
        y = x;
        if(z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(y == nullptr)
        root = z;
    else if(z->data < y->data)
        y->left = z;
    else
        y->right = z;
    z->left = NIL;
    z->right = NIL;
    z->color = RED;
    insertFixup(z);
}

template <typename T>
RBNode<T>* RBTree<T>::searchHelper(RBNode<T>* node, T key) const {
    if(node == NIL || key == node->data)
        return node;
    if(key < node->data)
        return searchHelper(node->left, key);
    else
        return searchHelper(node->right, key);
}

template <typename T>
RBNode<T>* RBTree<T>::search(T key) const {
    RBNode<T>* result = searchHelper(root, key);
    return (result == NIL ? nullptr : result);
}

template <typename T>
void RBTree<T>::inOrderHelper(RBNode<T>* node) const {
    if(node != NIL) {
        inOrderHelper(node->left);
        cout << node->data << " (" << (node->color == RED ? "R" : "B") << ") ";
        inOrderHelper(node->right);
    }
}

template <typename T>
void RBTree<T>::inOrder() const {
    inOrderHelper(root);
    cout << endl;
}
