#pragma once
#include <SDL.h>

enum class Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno };

class Animal {
protected:
    int edad = 0;
    int indiceX = 0;
    int indiceY = 0;
    float x = 0, y = 0;
    float xFu = 0, yFu = 0;
    float ancho = 0, alto = 0;
    float dx = 0, dy = 0;
    int limx = 0, limy = 0;
    char direccion = 'S';

public:
    Animal() = default;
    Animal(float px, float py, int texW, int texH)
        : edad(0), x(px), y(py), xFu(px), yFu(py),
          ancho(texW / 4.f), alto(texH / 4.f) {}

    virtual ~Animal() = default;

    float getX() const { return x; }
    float getY() const { return y; }
    float getAncho() const { return ancho; }
    float getAlto() const { return alto; }
    float getXFu() const { return xFu; }
    float getYFu() const { return yFu; }
    int getEdad() const { return edad; }

    void dibujar(SDL_Renderer* ren, SDL_Texture* fig, int drawSize = 60) {
        edad++;
        SDL_Rect src{
            static_cast<int>(indiceX * ancho),
            static_cast<int>(indiceY * alto),
            static_cast<int>(ancho > 1 ? ancho : 1),
            static_cast<int>(alto > 1 ? alto : 1)};
        SDL_Rect dst{static_cast<int>(x), static_cast<int>(y), drawSize, drawSize};
        SDL_RenderCopy(ren, fig, &src, &dst);
    }
};
