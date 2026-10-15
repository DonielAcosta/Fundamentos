#pragma once
#include <SDL.h>

class Fondo {
public:
    int x = 0, y = 0;
    int ancho = 0, alto = 0;

    Fondo() = default;
    Fondo(int px, int py, SDL_Texture* tex) {
        x = px;
        y = py;
        SDL_QueryTexture(tex, nullptr, nullptr, &ancho, &alto);
    }

    void dibujar(SDL_Renderer* ren, SDL_Texture* figura) const {
        SDL_Rect dst{x, y, ancho, alto};
        SDL_RenderCopy(ren, figura, nullptr, &dst);
    }
};
