#ifndef NODOEXPRESION_H
#define NODOEXPRESION_H

#include <cstring>
using namespace std;

/*
  La clase NodoExpresion representa un nodo del árbol de expresiones.
  Almacena un carácter (operador o dígito), una marca para indicar si es operando
  y apuntadores a sus nodos izquierdo y derecho.
*/
class NodoExpresion {
 protected:
    char dato;           // Almacena el símbolo (operador o dígito)
    bool operando;       // Indica si el símbolo es un dígito (true) o un operador (false)
    NodoExpresion* hijoIzq; 
    NodoExpresion* hijoDer;

 public:
    NodoExpresion();    // Constructor por defecto
    ~NodoExpresion();   // Destructor

    char getDato();                   // Retorna el carácter almacenado
    void setDato(char val);          // Asigna un carácter al nodo

    bool getOperando();              // Retorna el valor de la marca operando
    void setOperando(bool op);       // Modifica la marca operando

    NodoExpresion* getHijoIzq();     // Devuelve el hijo izquierdo
    NodoExpresion* getHijoDer();     // Devuelve el hijo derecho

    void setHijoIzq(NodoExpresion* izq);  // Asigna un nodo como hijo izquierdo
    void setHijoDer(NodoExpresion* der);  // Asigna un nodo como hijo derecho
};

#include "NodoExpresion.hxx"

#endif // NODOEXPRESION_H
