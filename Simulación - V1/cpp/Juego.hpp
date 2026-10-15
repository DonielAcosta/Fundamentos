#pragma once
#include "Conejo.hpp"
#include "Fondo.hpp"
#include <cmath>
#include <cstdlib>
#include <vector>

class Juego {
    Fondo fondo;
    std::vector<Conejo*> conejo;
    int tiempo = 0;
    int nc = 0;
    int texW = 0, texH = 0;

public:
    Juego(SDL_Texture* fondoTex, int conejoW, int conejoH, int numC, int t)
        : fondo(20, 20, fondoTex), conejo(1000, nullptr), tiempo(t),
          texW(conejoW), texH(conejoH) {
        for (int i = 0; i < numC; ++i)
            setConejo();
    }

    ~Juego() {
        for (auto* c : conejo)
            delete c;
    }

    Juego(const Juego&) = delete;
    Juego& operator=(const Juego&) = delete;

    int getNC() const { return nc; }

    static double dist(float x1, float y1, float x2, float y2) {
        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    bool hayChoque(float px, float py) const {
        for (auto* c : conejo) {
            if (c && dist(px, py, c->getX(), c->getY()) < c->getAncho())
                return true;
        }
        return false;
    }

    void setConejo() {
        float px, py;
        do {
            int spanX = fondo.ancho - 200;
            int spanY = fondo.alto - 200;
            if (spanX < 1) spanX = 1;
            if (spanY < 1) spanY = 1;
            px = static_cast<float>(100 + std::rand() % spanX);
            py = static_cast<float>(100 + std::rand() % spanY);
        } while (hayChoque(px, py));

        for (size_t i = 0; i < conejo.size(); ++i) {
            if (!conejo[i]) {
                conejo[i] = new Conejo(px, py, texW, texH, fondo.ancho, fondo.alto);
                ++nc;
                return;
            }
        }
    }

    void setConejo(float ox, float oy) {
        float px = 0, py = 0;
        int cont = 0;
        bool ok = false;
        do {
            ++cont;
            px = static_cast<float>((std::rand() % 150) + ox - 75);
            py = static_cast<float>((std::rand() % 150) + oy - 75);
            if (cont > 150)
                return;
            ok = !hayChoque(px, py) && px >= 60 && py >= 60 &&
                 px <= fondo.ancho - 60 && py <= fondo.alto - 60;
        } while (!ok);

        for (size_t i = 0; i < conejo.size(); ++i) {
            if (!conejo[i]) {
                conejo[i] = new Conejo(px, py, texW, texH, fondo.ancho, fondo.alto);
                ++nc;
                return;
            }
        }
    }

    bool esPosible(float px, float py, float a) const {
        return px >= a && px < fondo.ancho - a && py >= a && py < fondo.alto - a;
    }

    void controlMortalidad() {
        for (size_t i = 0; i < conejo.size(); ++i) {
            if (conejo[i] && conejo[i]->getEdad() > 60) {
                delete conejo[i];
                conejo[i] = nullptr;
                --nc;
            }
        }
    }

    void reproducir() {
        controlMortalidad();
        for (size_t i = 0; i < conejo.size(); ++i) {
            if (!conejo[i])
                continue;
            for (size_t j = 0; j < conejo.size(); ++j) {
                if (!conejo[j] || i == j)
                    continue;
                if (conejo[i]->getEdad() > 18 && conejo[j]->getEdad() > 18) {
                    if (dist(conejo[i]->getX(), conejo[i]->getY(),
                             conejo[j]->getX(), conejo[j]->getY()) < 60) {
                        if (std::rand() % 100 < 20)
                            setConejo(conejo[i]->getX(), conejo[i]->getY());
                    }
                }
            }
        }
    }

    void mover() {
        reproducir();
        for (auto* c : conejo) {
            if (!c)
                continue;
            c->decidir();
            if (esPosible(c->getXFu() + c->getAncho() / 2.f,
                          c->getYFu() + c->getAlto() / 2.f,
                          c->getAncho())) {
                c->mover();
            }
        }
    }

    void dibujar(SDL_Renderer* ren, SDL_Texture* fondoTex, SDL_Texture* figConejo) {
        fondo.dibujar(ren, fondoTex);
        for (auto* c : conejo) {
            if (c)
                c->dibujar(ren, figConejo);
        }
    }
};
