#include "Nodo.h"
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Constructor por defecto.
 * Inicializa todos los punteros hijos a NULL.
 */
template<class T>
Nodo<T>::Nodo() {
    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

/**
 * @brief Constructor que inicializa el nodo con un valor.
 * Asigna el valor recibido y establece los punteros hijos a NULL.
 */
template<class T>
Nodo<T>::Nodo(pair<T,T> val) {
    this->dato = val;
    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

/**
 * @brief Obtiene el dato almacenado en el nodo.
 * @return Par de valores almacenados.
 */
template<class T>
pair<T,T> Nodo<T>::obtenerDato() {
    return this->dato;
}

/**
 * @brief Establece el dato del nodo.
 * @param val Nuevo par de valores a asignar al nodo.
 */
template<class T>
void Nodo<T>::fijarDato(pair<T,T> val) {
    this->dato = val;
    return;
}

/**
 * @brief Calcula la altura del subárbol.
 *
 * Si el nodo es hoja (todos los hijos son NULL), retorna 1.
 * Caso contrario, calcula la altura máxima entre sus hijos y le suma 1.
 *
 * @return Altura del subárbol.
 */
template<class T>
int Nodo<T>::altura() {
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL)
        return 1;

    int mayor = 0, actual;
    if(NW != NULL) {
        actual = this->NW->altura() + 1;
        if(actual > mayor)
            mayor = actual;
    }
    if(NE != NULL) {
        actual = this->NE->altura() + 1;
        if(actual > mayor)
            mayor = actual;
    }
    if(SW != NULL) {
        actual = this->SW->altura() + 1;
        if(actual > mayor)
            mayor = actual;
    }
    if(SE != NULL) {
        actual = this->SE->altura() + 1;
        if(actual > mayor)
            mayor = actual;
    }
    return mayor;
}

/**
 * @brief Calcula el tamaño (cantidad de nodos) del subárbol.
 *
 * Cuenta el nodo actual (1) y suma recursivamente el tamaño de cada hijo existente.
 *
 * @return Número total de nodos en el subárbol.
 */
template<class T>
int Nodo<T>::tamano() {
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL)
        return 1;

    int cont = 1; // Cuenta el nodo actual.
    if(NW != NULL)
        cont += this->NW->tamano();
    if(NE != NULL)
        cont += this->NE->tamano();
    if(SW != NULL)
        cont += this->SW->tamano();
    if(SE != NULL)
        cont += this->SE->tamano();
    return cont;
}

/**
 * @brief Inserta un nuevo valor en el subárbol.
 *
 * Según la comparación de la primera y segunda componente del dato,
 * se decide en cuál de los cuadrantes (NE, SE, NW, SW) insertar el nuevo nodo.
 *
 * @param val Par de valores a insertar.
 */
template<class T>
void Nodo<T>::insertar(pair<T,T> val) {
    // Si la primera componente del dato actual es menor, se inserta en los cuadrantes del "Norte".
    if(this->dato.first < val.first) {
        if(this->dato.second < val.second) {
            if(this->NE != NULL)
                this->NE->insertar(val);
            else {
                Nodo<T>* nuevo = new Nodo<T>();
                nuevo->fijarDato(val);
                this->NE = nuevo;
            }
        } else {
            if(this->SE != NULL)
                this->SE->insertar(val);
            else {
                Nodo<T>* nuevo = new Nodo<T>();
                nuevo->fijarDato(val);
                this->SE = nuevo;
            }
        }
    }
    // Si la primera componente del dato actual es mayor, se inserta en los cuadrantes del "Sur".
    if(this->dato.first > val.first) {
        if(this->dato.second < val.second) {
            if(this->NW != NULL)
                this->NW->insertar(val);
            else {
                Nodo<T>* nuevo = new Nodo<T>();
                nuevo->fijarDato(val);
                this->NW = nuevo;
            }
        } else {
            if(this->SW != NULL)
                this->SW->insertar(val);
            else {
                Nodo<T>* nuevo = new Nodo<T>();
                nuevo->fijarDato(val);
                this->SW = nuevo;
            }
        }
    }
}

/**
 * @brief Busca un nodo que contenga el valor especificado.
 *
 * Compara el valor del nodo actual con el buscado y, en caso de no coincidir,
 * realiza la búsqueda de forma recursiva en el cuadrante correspondiente.
 *
 * @param val Par de valores a buscar.
 * @return Puntero al nodo encontrado o NULL si no se encuentra.
 */
template<class T>
Nodo<T>* Nodo<T>::buscar(pair<T,T> val) {
    if(this->dato == val)
        return this;
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL)
        return NULL;

    if(this->dato.first < val.first) {
        if(this->dato.second < val.second) {
            if(this->NE != NULL)
                return this->NE->buscar(val);
            else
                return NULL;
        } else {
            if(this->SE != NULL)
                return this->SE->buscar(val);
            else
                return NULL;
        }
    }
    if(this->dato.first > val.first) {
        if(this->dato.second < val.second) {
            if(this->NW != NULL)
                return this->NW->buscar(val);
            else
                return NULL;
        } else {
            if(this->SW != NULL)
                return this->SW->buscar(val);
            else
                return NULL;
        }
    }
    return NULL;
}

/**
 * @brief Realiza un recorrido en preorden del subárbol.
 *
 * Imprime el nodo actual y luego recorre recursivamente sus hijos en el orden:
 * NW, NE, SW, SE.
 */
template<class T>
void Nodo<T>::preOrden() {
    cout << "(" << this->dato.first << "," << this->dato.second << ")" << endl;
    if(this->NW != NULL)
        this->NW->preOrden();
    if(this->NE != NULL)
        this->NE->preOrden();
    if(this->SW != NULL)
        this->SW->preOrden();
    if(this->SE != NULL)
        this->SE->preOrden();
    return;
}

/**
 * @brief Realiza un recorrido en postorden del subárbol.
 *
 * Recorre recursivamente los hijos en el orden: NW, NE, SW, SE y al final imprime
 * el nodo actual.
 */
template<class T>
void Nodo<T>::posOrden() {
    if(this->NW != NULL)
        this->NW->posOrden();
    if(this->NE != NULL)
        this->NE->posOrden();
    if(this->SW != NULL)
        this->SW->posOrden();
    if(this->SE != NULL)
        this->SE->posOrden();
    cout << "(" << this->dato.first << "," << this->dato.second << ")" << endl;
    return;
}
