#ifndef ARBOLEXPRESION_HXX
#define ARBOLEXPRESION_HXX

#include "ArbolExpresion.h"
#include <iostream>
#include <stack>
#include <cctype>

/*
  Implementaciones de los métodos de ArbolExpresion.
  Se aprovecha la clase NodoExpresion para representar cada nodo.
  Cada método gestiona la forma en que se construye y recorre el árbol.
*/

ArbolExpresion::ArbolExpresion() {
    raiz = nullptr;
}

ArbolExpresion::~ArbolExpresion() {
    // Se omite la eliminación recursiva en este ejemplo.
    // Se podría implementar un recorrido postorden para liberar cada nodo.
}

NodoExpresion* ArbolExpresion::getRaiz() {
    return raiz;
}

void ArbolExpresion::setRaiz(NodoExpresion* nod) {
    raiz = nod;
}

bool ArbolExpresion::siOperando(char car) {
    // Retorna true si car es un dígito (0-9).
    return (isdigit(static_cast<unsigned char>(car)) != 0);
}

void ArbolExpresion::llenarDesdePrefija(string &expresion) {
    /*
      Construye el árbol leyendo la expresión de derecha a izquierda.
      Cuando encuentra un dígito, lo apila como nodo hoja.
      Cuando encuentra un operador, extrae dos nodos para formar un subárbol.
    */
    stack<NodoExpresion*> pila;

    for (int i = expresion.size() - 1; i >= 0; i--) {
        char c = expresion[i];

        if (siOperando(c)) {
            NodoExpresion* nodo = new NodoExpresion();
            nodo->setDato(c);
            nodo->setOperando(true);
            pila.push(nodo);
        } else {
            NodoExpresion* nodo = new NodoExpresion();
            nodo->setDato(c);
            nodo->setOperando(false);

            if (!pila.empty()) {
                nodo->setHijoIzq(pila.top());
                pila.pop();
            }
            if (!pila.empty()) {
                nodo->setHijoDer(pila.top());
                pila.pop();
            }
            pila.push(nodo);
        }
    }

    if (!pila.empty()) {
        raiz = pila.top();
        pila.pop();
    }
}

void ArbolExpresion::llenarDesdePosfija(string &expresion) {
    /*
      Construye el árbol leyendo la expresión de izquierda a derecha.
      Cuando encuentra un dígito, lo apila como nodo.
      Cuando encuentra un operador, extrae dos nodos y arma un subárbol,
      donde el primer pop será el hijo derecho y el segundo pop el izquierdo.
    */
    stack<NodoExpresion*> pila;

    for (size_t i = 0; i < expresion.size(); i++) {
        char c = expresion[i];

        if (siOperando(c)) {
            NodoExpresion* nodo = new NodoExpresion();
            nodo->setDato(c);
            nodo->setOperando(true);
            pila.push(nodo);
        } else {
            NodoExpresion* nodo = new NodoExpresion();
            nodo->setDato(c);
            nodo->setOperando(false);

            if (!pila.empty()) {
                NodoExpresion* right = pila.top();
                pila.pop();
                nodo->setHijoDer(right);
            }
            if (!pila.empty()) {
                NodoExpresion* left = pila.top();
                pila.pop();
                nodo->setHijoIzq(left);
            }
            pila.push(nodo);
        }
    }

    if (!pila.empty()) {
        raiz = pila.top();
        pila.pop();
    }
}

void ArbolExpresion::obtenerPrefija(NodoExpresion* inicio) {
    // Muestra primero la raíz, luego el subárbol izquierdo y finalmente el derecho.
    if (inicio == nullptr) return;
    cout << inicio->getDato();
    obtenerPrefija(inicio->getHijoIzq());
    obtenerPrefija(inicio->getHijoDer());
}

void ArbolExpresion::obtenerInfija(NodoExpresion* inicio) {
    // Muestra el subárbol izquierdo, la raíz y luego el subárbol derecho.
    if (inicio == nullptr) return;
    obtenerInfija(inicio->getHijoIzq());
    cout << inicio->getDato();
    obtenerInfija(inicio->getHijoDer());
}

void ArbolExpresion::obtenerPosfija(NodoExpresion* inicio) {
    // Muestra el subárbol izquierdo, el derecho y por último la raíz.
    if (inicio == nullptr) return;
    obtenerPosfija(inicio->getHijoIzq());
    obtenerPosfija(inicio->getHijoDer());
    cout << inicio->getDato();
}

int ArbolExpresion::evaluar(NodoExpresion* nodi) {
    /*
      Evalúa el subárbol: si el nodo es un operando (dígito),
      se devuelve su valor como entero. De lo contrario, evalúa
      recursivamente a sus hijos y aplica la operación correspondiente.
    */
    if (nodi == nullptr) {
        return 0;
    }

    if (nodi->getOperando()) {
        return (nodi->getDato() - '0'); // Convierte el dígito a un entero
    } else {
        int valIzq = evaluar(nodi->getHijoIzq());
        int valDer = evaluar(nodi->getHijoDer());
        char op = nodi->getDato();

        switch (op) {
            case '+': return valIzq + valDer;
            case '-': return valIzq - valDer;
            case '*': return valIzq * valDer;
            case '/':
                if (valDer == 0) {
                    cerr << "Error: división entre cero" << endl;
                    return 0;
                }
                return valIzq / valDer;
        }
    }
    return 0;
}

#endif // ARBOLEXPRESION_HXX
