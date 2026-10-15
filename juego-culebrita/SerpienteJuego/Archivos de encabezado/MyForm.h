#pragma once

#include "Serpiente.h"

#include <gtk/gtk.h>

namespace SerpienteJuego {

class MyForm {
public:
    bool iniciar;

    MyForm();
    ~MyForm();
    void mostrar();

private:
    static gboolean dibujar(GtkWidget* area, cairo_t* cr, gpointer datos);
    static void botonIniciarClick(GtkButton* boton, gpointer datos);
    static gboolean teclaPresionada(GtkWidget* widget, GdkEventKey* evento, gpointer datos);
    static gboolean tick(gpointer datos);

    GtkWidget* ventana = nullptr;
    GtkWidget* tablero = nullptr;
    GtkWidget* botonIniciar = nullptr;
    GdkPixbuf* fondo = nullptr;
    GdkPixbuf* imagenNodo = nullptr;
    Serpiente* serpiente = nullptr;

    int paso = 52;
    int anchoTablero = 600;
    int altoTablero = 600;
    guint idTemporizador = 0;
};

}  // namespace SerpienteJuego

namespace Application {

void EnableVisualStyles();
void SetCompatibleTextRenderingDefault(bool defaultValue);
void Run(SerpienteJuego::MyForm* formulario);

}  // namespace Application
