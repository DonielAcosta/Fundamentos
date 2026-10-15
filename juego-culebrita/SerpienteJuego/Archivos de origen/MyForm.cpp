#include "MyForm.h"
#include "recursos.h"

#include <gtk/gtk.h>

#include <iostream>
#include <string>

namespace {

std::string archivoRecurso(const char* nombre) {
    return std::string(RECURSOS) + "/" + nombre;
}

GdkPixbuf* cargarImagen(const char* nombre) {
    const std::string ruta = archivoRecurso(nombre);
    GError* error = nullptr;
    GdkPixbuf* imagen = gdk_pixbuf_new_from_file(ruta.c_str(), &error);
    if (imagen == nullptr) {
        std::cerr << "No se pudo cargar " << ruta << ": "
                  << (error ? error->message : "error desconocido") << "\n";
        if (error != nullptr) {
            g_error_free(error);
        }
    }
    return imagen;
}

void al_cerrar(GtkWidget*, gpointer) {
    gtk_main_quit();
}

}  // namespace

namespace Application {

void EnableVisualStyles() {
    gtk_init(nullptr, nullptr);
}

void SetCompatibleTextRenderingDefault(bool defaultValue) {
    (void)defaultValue;
}

void Run(SerpienteJuego::MyForm* formulario) {
    formulario->mostrar();
    gtk_main();
    delete formulario;
}

}  // namespace Application

SerpienteJuego::MyForm::MyForm() {
    iniciar = false;

    fondo = cargarImagen("fondo.png");
    imagenNodo = cargarImagen("nodo.png");

    anchoTablero = fondo ? gdk_pixbuf_get_width(fondo) : 600;
    altoTablero = fondo ? gdk_pixbuf_get_height(fondo) : 600;
    paso = imagenNodo ? gdk_pixbuf_get_width(imagenNodo) : 52;

    serpiente = new Serpiente(paso * 5, paso * 5, imagenNodo);

    ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventana), "SerpienteJuego");
    gtk_window_set_default_size(GTK_WINDOW(ventana), anchoTablero, altoTablero);
    gtk_window_set_resizable(GTK_WINDOW(ventana), FALSE);
    gtk_widget_add_events(ventana, GDK_KEY_PRESS_MASK);
    g_signal_connect(ventana, "destroy", G_CALLBACK(al_cerrar), nullptr);
    g_signal_connect(ventana, "key-press-event", G_CALLBACK(teclaPresionada), this);

    GtkWidget* contenedor = gtk_overlay_new();
    gtk_container_add(GTK_CONTAINER(ventana), contenedor);

    tablero = gtk_drawing_area_new();
    gtk_widget_set_size_request(tablero, anchoTablero, altoTablero);
    g_signal_connect(tablero, "draw", G_CALLBACK(dibujar), this);
    gtk_container_add(GTK_CONTAINER(contenedor), tablero);

    botonIniciar = gtk_button_new_with_label("Iniciar");
    gtk_widget_set_halign(botonIniciar, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(botonIniciar, GTK_ALIGN_CENTER);
    g_signal_connect(botonIniciar, "clicked", G_CALLBACK(botonIniciarClick), this);
    gtk_overlay_add_overlay(GTK_OVERLAY(contenedor), botonIniciar);
}

SerpienteJuego::MyForm::~MyForm() {
    if (idTemporizador != 0) {
        g_source_remove(idTemporizador);
        idTemporizador = 0;
    }
    delete serpiente;
    if (fondo != nullptr) {
        g_object_unref(fondo);
    }
    if (imagenNodo != nullptr) {
        g_object_unref(imagenNodo);
    }
}

gboolean SerpienteJuego::MyForm::dibujar(GtkWidget*, cairo_t* cr, gpointer datos) {
    auto* formulario = static_cast<MyForm*>(datos);
    if (formulario->fondo != nullptr) {
        gdk_cairo_set_source_pixbuf(cr, formulario->fondo, 0, 0);
        cairo_paint(cr);
    }
    if (formulario->iniciar && formulario->serpiente != nullptr) {
        formulario->serpiente->dibujar(cr);
    }
    return FALSE;
}

void SerpienteJuego::MyForm::botonIniciarClick(GtkButton* boton, gpointer datos) {
    auto* formulario = static_cast<MyForm*>(datos);
    formulario->iniciar = true;
    gtk_widget_hide(GTK_WIDGET(boton));

    if (formulario->idTemporizador == 0) {
        formulario->idTemporizador = g_timeout_add(150, tick, formulario);
    }

    gtk_widget_grab_focus(formulario->ventana);
    gtk_widget_queue_draw(formulario->tablero);
}

gboolean SerpienteJuego::MyForm::teclaPresionada(GtkWidget*, GdkEventKey* evento, gpointer datos) {
    auto* formulario = static_cast<MyForm*>(datos);
    if (!formulario->iniciar || formulario->serpiente == nullptr) {
        return FALSE;
    }

    const int paso = formulario->paso;
    switch (evento->keyval) {
        case GDK_KEY_Up:
        case GDK_KEY_w:
        case GDK_KEY_W:
            formulario->serpiente->cambiarDireccion(0, -paso);
            break;
        case GDK_KEY_Down:
        case GDK_KEY_s:
        case GDK_KEY_S:
            formulario->serpiente->cambiarDireccion(0, paso);
            break;
        case GDK_KEY_Left:
        case GDK_KEY_a:
        case GDK_KEY_A:
            formulario->serpiente->cambiarDireccion(-paso, 0);
            break;
        case GDK_KEY_Right:
        case GDK_KEY_d:
        case GDK_KEY_D:
            formulario->serpiente->cambiarDireccion(paso, 0);
            break;
        case GDK_KEY_space:
            // Temporal: crecer con espacio (luego será al comer manzana).
            formulario->serpiente->crecer();
            break;
        default:
            return FALSE;
    }
    return TRUE;
}

gboolean SerpienteJuego::MyForm::tick(gpointer datos) {
    auto* formulario = static_cast<MyForm*>(datos);
    if (!formulario->iniciar || formulario->serpiente == nullptr) {
        return TRUE;
    }

    formulario->serpiente->mover(formulario->anchoTablero, formulario->altoTablero);

    if (formulario->serpiente->chocaConCuerpo()) {
        formulario->iniciar = false;
        if (formulario->idTemporizador != 0) {
            g_source_remove(formulario->idTemporizador);
            formulario->idTemporizador = 0;
        }
        std::cerr << "Game Over: la serpiente chocó consigo misma.\n";
    }

    gtk_widget_queue_draw(formulario->tablero);
    return TRUE;
}

void SerpienteJuego::MyForm::mostrar() {
    gtk_widget_show_all(ventana);
}

int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(new SerpienteJuego::MyForm());
    return 0;
}
