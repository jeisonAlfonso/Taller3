#ifndef __ARBOLBINARIO__HXX__
#define __ARBOLBINARIO__HXX__

#include <iostream>
#include <queue>

/*
 * ArbolBinario.hxx
 * Aquí se implementan los métodos de la clase ArbolBinario<T>.
 */

template<class T>
ArbolBinario<T>::ArbolBinario()
    : raiz(nullptr)
{
}

template<class T>
bool ArbolBinario<T>::esVacio() {
    return (raiz == nullptr);
}

template<class T>
T& ArbolBinario<T>::datoRaiz() {
    return raiz->obtenerDato(); // Asume no vacío
}

template<class T>
int ArbolBinario<T>::altura() {
    if (!raiz) return 0;
    return raiz->altura();
}

template<class T>
int ArbolBinario<T>::tamano() {
    if (!raiz) return 0;
    return raiz->tamano();
}

template<class T>
void ArbolBinario<T>::insertar(T& val) {
    if (!raiz) {
        raiz = new NodoBinario<T>();
        raiz->fijarDato(val);
    } else {
        raiz->insertar(val);
    }
}

template<class T>
bool ArbolBinario<T>::eliminar(T& val) {
    // Búsqueda del nodo a eliminar
    NodoBinario<T>* nodoEliminar = buscar(val);
    if (!nodoEliminar) {
        // no se encuentra
        return false;
    }

    // Si fuera hoja, lo borramos.
    // Nota: En un BST completo, habría que hacer reemplazos
    // con el sucesor o predecesor si tiene dos hijos, etc.

    std::cout << "[Advertencia] El método eliminar aún no maneja todos los casos.\n";
    return false;
}

template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val) {
    if (!raiz) return nullptr;
    return raiz->buscar(val);
}

template<class T>
void ArbolBinario<T>::preOrden() {
    if (raiz) {
        raiz->preOrden();
        std::cout << std::endl;
    }
}

template<class T>
void ArbolBinario<T>::inOrden() {
    if (raiz) {
        raiz->inOrden();
        std::cout << std::endl;
    }
}

template<class T>
void ArbolBinario<T>::posOrden() {
    if (raiz) {
        raiz->posOrden();
        std::cout << std::endl;
    }
}

template<class T>
void ArbolBinario<T>::nivelOrden() {
    if (!raiz) return;
    std::queue<NodoBinario<T>*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        NodoBinario<T>* actual = cola.front();
        cola.pop();
        std::cout << actual->obtenerDato() << " ";
        if (actual->obtenerHijoIzq()) cola.push(actual->obtenerHijoIzq());
        if (actual->obtenerHijoDer()) cola.push(actual->obtenerHijoDer());
    }
    std::cout << std::endl;
}

#endif // __ARBOLBINARIO__HXX__

