#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <map>
#include "NodoGrafo.h"

/*template <class T>
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
};*/

template <class T>
class Grafo {
private:
    std::map<T, NodoGrafo<T>*> nodos;

public:
    Grafo();
    ~Grafo();
    void agregarNodo(const T& nodo);
    void agregarArista(const T& origen, const T& destino);
    void agregarAristaConPeso(const T& origen, const T& destino, int peso);
    void eliminarNodo(const T& nodo);
    void eliminarArista(const T& origen, const T& destino);
    bool estanConectados(const T& origen, const T& destino);
    std::list<T> obtenerVecinos(const T& nodo);
    void imprimir();

private:
    void eliminarAristas(NodoGrafo<T>* nodo);
    bool dfs(const T& origen, const T& destino, std::map<T, bool>& visitado);

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
void Grafo<T>::eliminarArista(const T& origen, const T& destino) {
    if (nodos.find(origen) == nodos.end() || nodos.find(destino) == nodos.end())
        return;

    // Eliminar arista en ambos nodos (grafo no dirigido)
    nodos[origen]->vecinos.remove_if([destino](const std::pair<NodoGrafo<T>*, int>& vecino) {
        return vecino.first->data == destino;
    });
    nodos[destino]->vecinos.remove_if([origen](const std::pair<NodoGrafo<T>*, int>& vecino) {
        return vecino.first->data == origen;
    });
}

template <class T>
std::list<T> Grafo<T>::obtenerVecinos(const T& nodo) {
    std::list<T> listaVecinos;

    if (nodos.find(nodo) != nodos.end()) {
        for (const auto& vecino : nodos[nodo]->vecinos) {
            listaVecinos.push_back(vecino.first->data); // Guardamos los datos de los vecinos
        }
    }

    return listaVecinos;
}


template <class T>
void Grafo<T>::agregarAristaConPeso(const T& origen, const T& destino, int peso) {
    if (nodos.find(origen) == nodos.end() || nodos.find(destino) == nodos.end())
        return; // Si alguno de los nodos no existe

    // Agregar el vecino con el peso a ambos nodos (grafo no dirigido)
    nodos[origen]->vecinos.push_back({nodos[destino], peso});
    nodos[destino]->vecinos.push_back({nodos[origen], peso});
}


template <class T>
bool Grafo<T>::estanConectados(const T& origen, const T& destino) {
    if (nodos.find(origen) == nodos.end() || nodos.find(destino) == nodos.end())
        return false; // Si alguno de los nodos no existe en el grafo

    std::map<T, bool> visitado; // Para marcar los nodos visitados
    return dfs(origen, destino, visitado);
}

template <class T>
bool Grafo<T>::dfs(const T& origen, const T& destino, std::map<T, bool>& visitado) {
    if (origen == destino) return true; // Si encontramos el destino

    visitado[origen] = true; // Marcamos el nodo como visitado

    // Recorremos los vecinos del nodo
    for (NodoGrafo<T>* vecino : nodos[origen]->vecinos) {
        if (!visitado[vecino->data] && dfs(vecino->data, destino, visitado))
            return true;
    }
    return false;
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
