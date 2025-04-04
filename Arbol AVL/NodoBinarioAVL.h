#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

// T es el tipo de dato que almacena el nodo.
template <class T>
class NodoBinarioAVL {
public:
    T dato;                           // Dato almacenado en el nodo
    NodoBinarioAVL<T>* hijoIzq;      // Puntero al hijo izquierdo
    NodoBinarioAVL<T>* hijoDer;      // Puntero al hijo derecho

public:
    // Constructor por defecto
    NodoBinarioAVL();

    // Destructor por defecto
    ~NodoBinarioAVL();

    // Obtiene el dato almacenado
    T& getDato();

    // Establece el dato en el nodo
    void setDato(T& val);

    // Obtiene el puntero del hijo izquierdo
    NodoBinarioAVL<T>* getHijoIzq();

    // Obtiene el puntero del hijo derecho
    NodoBinarioAVL<T>* getHijoDer();

    // Asigna el puntero del hijo izquierdo
    void setHijoIzq(NodoBinarioAVL<T>* izq);

    // Asigna el puntero del hijo derecho
    void setHijoDer(NodoBinarioAVL<T>* der);
};

#include "NodoBinarioAVL.hxx" // Aquí van las definiciones template

#endif // NODOBINARIOAVL_H

