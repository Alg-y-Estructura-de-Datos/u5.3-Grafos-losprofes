#ifndef NODOGRAFO_H
#define NODOGRAFO_H

#include <iostream>
#include <list>

// Definición de NodoGrafo
template <class T>
class NodoGrafo {
public:
    T data;
    std::list<std::pair<NodoGrafo<T>*, int>> vecinos;

    NodoGrafo(const T& dato) : data(dato) {}
};

#endif // NODOGRAFO_H

