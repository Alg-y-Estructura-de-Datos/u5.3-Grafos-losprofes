#ifndef NODOGRAFO_H
#define NODOGRAFO_H

#include <iostream>
#include <list>

/*template <class T>
class NodoGrafo {
public:
    T data;
    std::list<NodoGrafo<T>*> vecinos;

    NodoGrafo(const T& d) : data(d) {}
};*/


template <class T>
class NodoGrafo {
public:
    T data;
    std::list<std::pair<NodoGrafo<T>*, int>> vecinos; // Cada vecino incluye un peso

    NodoGrafo(const T& d) : data(d) {}
};


#endif // NODOGRAFO_H

