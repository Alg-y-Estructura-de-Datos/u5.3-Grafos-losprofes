#ifndef GRAFO_H
#define GRAFO_H
/*Estructura de Datos Grafo no dirigido con aristas sin y con ponderar. Se sugiere revisar la ponderación antes de usarla.*/
#include <iostream>
#include <map>
#include "NodoGrafo.h"
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <stdexcept>
#include <utility>
using namespace std;

// Definición de Grafo
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
    bool buscarNodo(const T& nodo); // Declaración añadida
    void imprimir();

private:
    void eliminarAristas(NodoGrafo<T>* nodo);
    bool dfs(const T& origen, const T& destino, std::map<T, bool>& visitado);
};

// Implementación del Grafo

template <class T>
Grafo<T>::Grafo() {}

template <class T>
Grafo<T>::~Grafo() {
    for (auto& par : nodos) {
        delete par.second; // Liberar memoria de los nodos
    }
}

template <class T>
void Grafo<T>::agregarNodo(const T& nodo) {
    // Verificar si el nodo ya existe
    if (nodos.find(nodo) != nodos.end()) {
        throw std::invalid_argument("Nodo ya existe.");
    }
    nodos[nodo] = new NodoGrafo<T>(nodo); // Agregar el nuevo nodo
}

template <class T>
bool Grafo<T>::buscarNodo(const T& nodo) {
    return nodos.find(nodo) != nodos.end();
}

template <class T>
void Grafo<T>::agregarArista(const T& origen, const T& destino) {
    if (nodos.find(origen) == nodos.end() || nodos.find(destino) == nodos.end())
        throw std::invalid_argument("Uno o ambos nodos no existen.");

    // Usar un peso predeterminado, por ejemplo, 1
    nodos[origen]->vecinos.emplace_back(nodos[destino], 1);
    nodos[destino]->vecinos.emplace_back(nodos[origen], 1); // Grafo no dirigido
}

template <class T>
void Grafo<T>::agregarAristaConPeso(const T& origen, const T& destino, int peso) {
    if (nodos.find(origen) == nodos.end() || nodos.find(destino) == nodos.end())
        throw std::invalid_argument("Uno o ambos nodos no existen.");

    nodos[origen]->vecinos.emplace_back(nodos[destino], peso);
    nodos[destino]->vecinos.emplace_back(nodos[origen], peso); // Grafo no dirigido
}

template <class T>
void Grafo<T>::eliminarAristas(NodoGrafo<T>* nodo) {
    for (auto& par : nodos) {
        par.second->vecinos.remove_if([nodo](const std::pair<NodoGrafo<T>*, int>& vecino) {
            return vecino.first == nodo;
        });
    }
}

template <class T>
void Grafo<T>::eliminarNodo(const T& nodo) {
    auto it = nodos.find(nodo);
    if (it == nodos.end())
        throw std::invalid_argument("Nodo no encontrado.");

    eliminarAristas(it->second);
    delete it->second;
    nodos.erase(it);
}

template <class T>
void Grafo<T>::eliminarArista(const T& origen, const T& destino) {
    if (nodos.find(origen) == nodos.end() || nodos.find(destino) == nodos.end())
        throw std::invalid_argument("Uno o ambos nodos no existen.");

    // Eliminar arista en ambos nodos (grafo no dirigido)
    nodos[origen]->vecinos.remove_if([destino](const std::pair<NodoGrafo<T>*, int>& vecino) {
        return vecino.first->data == destino;
    });
    nodos[destino]->vecinos.remove_if([origen](const std::pair<NodoGrafo<T>*, int>& vecino) {
        return vecino.first->data == origen;
    });
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
    for (const auto& vecino : nodos[origen]->vecinos) {
        if (!visitado[vecino.first->data] && dfs(vecino.first->data, destino, visitado))
            return true;
    }
    return false;
}

template <class T>
void Grafo<T>::imprimir() {
    for (const auto& par : nodos) {
        std::cout << par.first << " -> ";
        for (const auto& vecino : par.second->vecinos) {
            std::cout << vecino.first->data << " ";// << "(" << vecino.second << ") ";
        }
        std::cout << std::endl;
    }
}
/*
void imprimir() {
    cout << "Red social actual:" << endl;
    for (auto const& par : nodos) {
        cout << par.first << " -> ";
        bool primero = true;
        for (auto const& adyacente : par.second) {
            if (!primero) {
                cout << " ";  // Espacio entre nodos
            }
            cout << adyacente.first;  // Solo imprime el nodo adyacente, sin el peso
            primero = false;
        }
        cout << endl;
    }
}*/

#endif // GRAFO_H
