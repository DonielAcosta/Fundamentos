#pragma once
#include "Animal.hpp"
#include <cstdlib>

class Conejo : public Animal {
    int contador = 0;

public:
    Conejo(float px, float py, int texW, int texH, int lx, int ly)
        : Animal(px, py, texW, texH) {
        limx = lx;
        limy = ly;
        dx = 10;
        dy = 10;
    }

    void mover() {
        x = xFu;
        y = yFu;
    }

    char decidirDireccion() {
        switch (std::rand() % 4) {
            case 0: return 'N';
            case 1: return 'S';
            case 2: return 'E';
            default: return 'O';
        }
    }

    void decidir() {
        contador++;
        indiceX = (indiceX + 1) % 4;
        if (contador % 10 == 0) {
            direccion = decidirDireccion();
            contador = 0;
        }

        xFu = x;
        yFu = y;
        switch (direccion) {
            case 'N':
                indiceY = 3;
                yFu = y - dy;
                break;
            case 'S':
                indiceY = 0;
                yFu = y + dy;
                break;
            case 'E':
                indiceY = 2;
                xFu = x + dx;
                break;
            case 'O':
                indiceY = 1;
                xFu = x - dx;
                break;
        }
    }
};
