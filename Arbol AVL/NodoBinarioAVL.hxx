#ifndef NODOBINARIOAVL_HXX
#define NODOBINARIOAVL_HXX

template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL()
    : dato(T()), hijoIzq(nullptr), hijoDer(nullptr)
{
}

template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL()
{
    // Por lo general no necesitas hacer nada especial aquí
}

template <class T>
T& NodoBinarioAVL<T>::getDato() {
    return dato;
}

template <class T>
void NodoBinarioAVL<T>::setDato(T& val) {
    dato = val;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq() {
    return hijoIzq;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer() {
    return hijoDer;
}

template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq) {
    hijoIzq = izq;
}

template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der) {
    hijoDer = der;
}

#endif // NODOBINARIOAVL_HXX


