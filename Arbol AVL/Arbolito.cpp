/*

· Autor: Jeison Alfonso y Douglas Diaz
· Asignatura: Estructuras de datos
· Tema: ArbolAVL
· Archivo principal que permite probar un el funcionamiento de un Arbol AVL
· Este programa permite al usuario insertar y eliminar datos en el arbol AVL. 

*/


#include<iostream>
#include "ArbolBinarioAVL.h"

using namespace std;

int main(int argc, char* argv[])
{

	// Crear un árbol AVL que almacena enteros
    ArbolBinarioAVL<int> arbolito;

	/* Lee las operaciones del usuario indefinidamente. 
		'A' para insertar y 'E' para eliminar datos en el arbol.
		Si ingresa otro valor se detiene la ejecución del programa
	*/ 
	while(true)
	{
		int dato;
		char op;
		cin>>op>>dato;
		
		if(op == 'A')
			arbolito.insertar(dato);
		else if(op == 'E')
			arbolito.eliminar(dato);
		else
			break;
	}
	
	// Imprime el recorrido del arbol InOrden
	cout << endl << "Inorden: " << endl;
	arbolito.inOrden(arbolito.getRaiz());

	// Imprime el recorrido del arbol en PreOrden
	cout << endl << "Preorden: " << endl;
	arbolito.preOrden(arbolito.getRaiz());

	// Imprime el recorrido del arbol en PosOrden
	cout << endl <<"Posorden: " << endl;
	arbolito.posOrden(arbolito.getRaiz());
}