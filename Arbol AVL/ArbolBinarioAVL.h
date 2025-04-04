#ifndef ARBOLBINARIOAVL_H
#define ARBOLBINARIOAVL_H

#include "NodoBinarioAVL.h"

// T es el tipo de dato que almacenará el árbol.
template <class T>
class ArbolBinarioAVL {
protected:
    NodoBinarioAVL<T>* raiz; // Puntero a la raíz del árbol

public:
    // Constructor por defecto
    ArbolBinarioAVL();

    // Destructor por defecto
    ~ArbolBinarioAVL();

    // Asigna el nodo raíz del árbol
    void setRaiz(NodoBinarioAVL<T>* raiz);

    // Retorna el puntero al nodo raíz del árbol
    NodoBinarioAVL<T>* getRaiz();

    // Verifica si el árbol está vacío
    bool esVacio();

    // Retorna el dato contenido en la raíz
    T& datoRaiz();

    // Calcula la altura de un subárbol
    int altura(NodoBinarioAVL<T>* inicio);

    // Calcula el número total de nodos de un subárbol
    int tamano(NodoBinarioAVL<T>* inicio);

    // Realiza una rotación simple a la derecha
    NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>*& inicio);

    // Realiza una rotación doble izquierda-derecha
    NodoBinarioAVL<T>* giroIzquierdaDerecha(NodoBinarioAVL<T>*& padre);

    // Realiza una rotación simple a la izquierda
    NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>*& inicio);

    // Realiza una rotación doble derecha-izquierda
    NodoBinarioAVL<T>* giroDerechaIzquierda(NodoBinarioAVL<T>*& padre);

    // Inserta un valor en el árbol
    bool insertar(T& val);

    // Elimina un valor del árbol
    bool eliminar(T& val);

    // Busca un valor en el árbol
    bool buscar(T& val);

    // Recorre el árbol en preorden
    void preOrden(NodoBinarioAVL<T>* inicio);

    // Recorre el árbol en inorden
    void inOrden(NodoBinarioAVL<T>* inicio);

    // Recorre el árbol en posorden
    void posOrden(NodoBinarioAVL<T>* inicio);

    // Recorre el árbol por niveles
    void nivelOrden(NodoBinarioAVL<T>* inicio);
};

#include "ArbolBinarioAVL.hxx" // Aquí van las definiciones de la plantilla

#endif // ARBOLBINARIOAVL_H




