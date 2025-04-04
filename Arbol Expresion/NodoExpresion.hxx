#ifndef NODOEXPRESION_HXX
#define NODOEXPRESION_HXX

#include "NodoExpresion.h"

/*
  Implementaciones de los métodos de la clase NodoExpresion.
  No se realizan eliminaciones recursivas en el destructor,
  pues se asume que la clase ArbolExpresion se encargará de ello si es necesario.
*/

NodoExpresion::NodoExpresion() {
    dato = '\0';
    operando = false;
    hijoIzq = nullptr;
    hijoDer = nullptr;
}

NodoExpresion::~NodoExpresion() {
    // Se deja la eliminación de nodos hijos al ArbolExpresion, si así se requiere.
}

char NodoExpresion::getDato() {
    return dato;
}

void NodoExpresion::setDato(char val) {
    dato = val;
}

bool NodoExpresion::getOperando() {
    return operando;
}

void NodoExpresion::setOperando(bool op) {
    operando = op;
}

NodoExpresion* NodoExpresion::getHijoIzq() {
    return hijoIzq;
}

NodoExpresion* NodoExpresion::getHijoDer() {
    return hijoDer;
}

void NodoExpresion::setHijoIzq(NodoExpresion* izq) {
    hijoIzq = izq;
}

void NodoExpresion::setHijoDer(NodoExpresion* der) {
    hijoDer = der;
}

#endif // NODOEXPRESION_HXX
