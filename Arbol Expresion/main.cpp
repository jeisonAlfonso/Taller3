#include <iostream>
#include <string>
#include "ArbolExpresion.h"
#include "NodoExpresion.h"

using namespace std;

/*
  El programa principal crea instancias de ArbolExpresion, llena sus nodos
  con expresiones en notación prefija y posfija, las imprime y finalmente las evalúa.
*/
int main(int argc, char* argv[]) {
    cout << "EJERCICIO 1" << endl;
    cout << endl;
    cout << "1. Construir Arbol Expresion (prefija):" << endl;
    cout << "-*/5-7+113-+2+1*43*2-68" << endl;

    ArbolExpresion* arbexp = new ArbolExpresion();
    string exp = "-*/5-7+113-+2+1*43*2-68";
    arbexp->llenarDesdePrefija(exp);

    cout << "2. Imprimir Version Posfija = ";
    arbexp->obtenerPosfija(arbexp->getRaiz());
    cout << endl;

    cout << "3. Imprimir Resultado = ";
    cout << arbexp->evaluar(arbexp->getRaiz()) << endl;
    cout << endl;

    cout << "EJERCICIO 2" << endl;
    cout << endl;
    cout << "1. Construir Arbol Expresion (posfija):" << endl;
    cout << "45+23+*6+87+/12+3*6+23+/*" << endl;

    ArbolExpresion* arbexp2 = new ArbolExpresion();
    string exp2 = "45+23+*6+87+/12+3*6+23+/*";
    arbexp2->llenarDesdePosfija(exp2);

    cout << "2. Imprimir Version Prefija = ";
    arbexp2->obtenerPrefija(arbexp2->getRaiz());
    cout << endl;

    cout << "3. Imprimir Resultado = ";
    cout << arbexp2->evaluar(arbexp2->getRaiz()) << endl;

    // Se liberan los árboles para evitar fugas de memoria (opcional si se sigue otro esquema de gestión)
    delete arbexp;
    delete arbexp2;

    return 0;
}
