#pragma once

#include "Nodo.h"

// TDA Lista: administra los nodos de la serpiente.
class Lista {
public:
    Nodo* cabeza;

    Lista() : cabeza(nullptr) {}

    ~Lista() {
        vaciar();
    }

    void insertarAlInicio(Nodo* nodo) {
        if (nodo == nullptr) {
            return;
        }
        nodo->siguiente = cabeza;
        cabeza = nodo;
    }

    void eliminarAlFinal() {
        if (cabeza == nullptr) {
            return;
        }
        if (cabeza->siguiente == nullptr) {
            delete cabeza;
            cabeza = nullptr;
            return;
        }

        Nodo* actual = cabeza;
        while (actual->siguiente->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        delete actual->siguiente;
        actual->siguiente = nullptr;
    }

    void vaciar() {
        while (cabeza != nullptr) {
            Nodo* siguiente = cabeza->siguiente;
            delete cabeza;
            cabeza = siguiente;
        }
    }

    void dibujar(cairo_t* cr) const {
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            actual->dibujar(cr);
        }
    }

    int longitud() const {
        int n = 0;
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            ++n;
        }
        return n;
    }
};
