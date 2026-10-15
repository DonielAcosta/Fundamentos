#pragma once

#include "Lista.h"

#include <gtk/gtk.h>

// Serpiente = lista de nodos + movimiento.
class Serpiente {
public:
    Lista cuerpo;
    GdkPixbuf* imagen;
    int paso;
    int dx;
    int dy;
    bool crecerEnSiguiente;

    Serpiente(int x, int y, GdkPixbuf* sprite)
        : imagen(sprite),
          paso(sprite ? gdk_pixbuf_get_width(sprite) : 52),
          dx(0),
          dy(0),
          crecerEnSiguiente(false) {
        dx = paso;
        dy = 0;
        // Cola → medio → cabeza (la cabeza queda al inicio de la lista).
        cuerpo.insertarAlInicio(new Nodo(x - 2 * paso, y, imagen));
        cuerpo.insertarAlInicio(new Nodo(x - paso, y, imagen));
        cuerpo.insertarAlInicio(new Nodo(x, y, imagen));
    }

    void cambiarDireccion(int nuevoDx, int nuevoDy) {
        // No permitir giro de 180°.
        if (nuevoDx == -dx && nuevoDy == -dy) {
            return;
        }
        if (nuevoDx == 0 && nuevoDy == 0) {
            return;
        }
        dx = nuevoDx;
        dy = nuevoDy;
    }

    // Método Mover() del curso: nueva cabeza + quitar cola (salvo si crece).
    void mover(int anchoTablero, int altoTablero) {
        if (cuerpo.cabeza == nullptr) {
            return;
        }

        int nuevaX = cuerpo.cabeza->x + dx;
        int nuevaY = cuerpo.cabeza->y + dy;

        // Controles en bordes: reaparece por el lado contrario (alineado a la grilla).
        const int maxX = (anchoTablero / paso) * paso;
        const int maxY = (altoTablero / paso) * paso;
        if (nuevaX >= maxX) {
            nuevaX = 0;
        } else if (nuevaX < 0) {
            nuevaX = maxX - paso;
        }
        if (nuevaY >= maxY) {
            nuevaY = 0;
        } else if (nuevaY < 0) {
            nuevaY = maxY - paso;
        }

        cuerpo.insertarAlInicio(new Nodo(nuevaX, nuevaY, imagen));

        if (crecerEnSiguiente) {
            crecerEnSiguiente = false;
        } else {
            cuerpo.eliminarAlFinal();
        }
    }

    void crecer() {
        crecerEnSiguiente = true;
    }

    void dibujar(cairo_t* cr) const {
        cuerpo.dibujar(cr);
    }

    bool chocaConCuerpo() const {
        if (cuerpo.cabeza == nullptr) {
            return false;
        }
        const int hx = cuerpo.cabeza->x;
        const int hy = cuerpo.cabeza->y;
        for (Nodo* actual = cuerpo.cabeza->siguiente; actual != nullptr; actual = actual->siguiente) {
            if (actual->x == hx && actual->y == hy) {
                return true;
            }
        }
        return false;
    }
};
