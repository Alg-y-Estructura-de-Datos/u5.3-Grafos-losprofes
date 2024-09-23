#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <map>
#include "NodoGrafo.h"

template <class T>
class Grafo {
private:
    std::map<T, NodoGrafo<T>*> nodos;

public:
    Grafo();                       // Constructor
    ~Grafo();                      // Destructor
    void agregarNodo(const T& nodo);
    void agregarArista(const T& origen, const T& destino);
    bool buscarNodo(const T& nodo);
    void eliminarNodo(const T& nodo);
    void imprimir();

private:
    void eliminarAristas(NodoGrafo<T>* nodo);
};

template <class T>
Grafo<T>::Grafo() {}

template <class T>
Grafo<T>::~Grafo() {
    for (auto& par : nodos) {
        delete par.second; // Liberar memoria de los nodos
    }
}

/*template <class T>
void Grafo<T>::agregarNodo(const T& nodo) {
    nodos[nodo] = new NodoGrafo<T>(nodo);
}*/

template <class T>
void Grafo<T>::agregarNodo(const T& nodo) {
    // Verificar si el nodo ya existe
    if (nodos.find(nodo) != nodos.end()) {
        throw 404;
    }
    nodos[nodo] = new NodoGrafo<T>(nodo); // Agregar el nuevo nodo
}

template <class T>
void Grafo<T>::agregarArista(const T& origen, const T& destino) {
    if (nodos.find(origen) == nodos.end() || nodos.find(destino) == nodos.end())
        return;

    nodos[origen]->vecinos.push_back(nodos[destino]);
    nodos[destino]->vecinos.push_back(nodos[origen]); // Grafo no dirigido
}

template <class T>
bool Grafo<T>::buscarNodo(const T& nodo) {
    return nodos.find(nodo) != nodos.end();
}

template <class T>
void Grafo<T>::eliminarAristas(NodoGrafo<T>* nodo) {
    for (auto& par : nodos) {
        par.second->vecinos.remove(nodo);
    }
}

template <class T>
void Grafo<T>::eliminarNodo(const T& nodo) {
    if (nodos.find(nodo) == nodos.end())
        return;

    eliminarAristas(nodos[nodo]);
    delete nodos[nodo];
    nodos.erase(nodo);
}

template <class T>
void Grafo<T>::imprimir() {
    for (const auto& par : nodos) {
        std::cout << par.first << " -> ";
        for (const auto& vecino : par.second->vecinos) {
            std::cout << vecino->data << " ";
        }
        std::cout << std::endl;
    }
}

#endif // GRAFO_H
