#ifndef ARBOLEXPRESION_H
#define ARBOLEXPRESION_H

#include "NodoExpresion.h"
#include <string>
using namespace std;

/*
  La clase ArbolExpresion define la estructura principal de un árbol
  para evaluar e imprimir expresiones en notaciones prefija, posfija o infija.
  Se encarga de crear, destruir y operar con los nodos de este tipo de árbol.
*/
class ArbolExpresion {
 protected:
    NodoExpresion* raiz;  // Apuntador a la raíz del árbol

 public:
    ArbolExpresion();         // Constructor
    ~ArbolExpresion();        // Destructor

    NodoExpresion* getRaiz();         // Retorna la raíz
    void setRaiz(NodoExpresion* nod); // Asigna la raíz

    void llenarDesdePrefija(string &expresion);  // Construye el árbol desde una expresión en notación prefija
    void llenarDesdePosfija(string &expresion);  // Construye el árbol desde una expresión en notación posfija

    void obtenerPrefija(NodoExpresion* inicio);  // Muestra la notación prefija de un subárbol
    void obtenerInfija(NodoExpresion* inicio);   // Muestra la notación infija de un subárbol
    void obtenerPosfija(NodoExpresion* inicio);  // Muestra la notación posfija de un subárbol

    int evaluar(NodoExpresion* nodi);            // Evalúa el subárbol que cuelga de nodi
    bool siOperando(char car);                   // Determina si el carácter es un dígito
};

#include "ArbolExpresion.hxx"

#endif // ARBOLEXPRESION_H
