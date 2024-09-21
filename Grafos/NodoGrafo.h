#ifndef NODOGRAFO_H
#define NODOGRAFO_H

#include <iostream>
#include <list>

template <class T>
class NodoGrafo {
public:
    T data;
    std::list<NodoGrafo<T>*> vecinos;

    NodoGrafo(const T& d) : data(d) {}
};

#endif // NODOGRAFO_H

