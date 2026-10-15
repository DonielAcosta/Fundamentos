#pragma once

#include <gtk/gtk.h>

// Pedazo de serpiente: posición, imagen y enlace al siguiente (lista).
class Nodo {
public:
    int x;
    int y;
    int ancho;
    int alto;
    GdkPixbuf* imagen;
    Nodo* siguiente;

    Nodo(int posX, int posY, GdkPixbuf* sprite)
        : x(posX), y(posY), imagen(sprite), siguiente(nullptr) {
        if (imagen != nullptr) {
            ancho = gdk_pixbuf_get_width(imagen);
            alto = gdk_pixbuf_get_height(imagen);
        } else {
            ancho = 52;
            alto = 52;
        }
    }

    void dibujar(cairo_t* cr) const {
        if (imagen == nullptr) {
            return;
        }
        gdk_cairo_set_source_pixbuf(cr, imagen, x, y);
        cairo_paint(cr);
    }
};
