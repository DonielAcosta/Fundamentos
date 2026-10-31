#include "Juego.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <memory>
#include <string>

namespace {
constexpr int WIN_W = 861;
constexpr int WIN_H = 594;
constexpr int FPS = 30;

const SDL_Color COL_PANEL{28, 42, 48, 255};
const SDL_Color COL_PANEL_EDGE{55, 78, 88, 255};
const SDL_Color COL_BTN{236, 240, 241, 255};
const SDL_Color COL_BTN_HOVER{255, 255, 255, 255};
const SDL_Color COL_BTN_BORDER{180, 190, 195, 255};
const SDL_Color COL_VALUE{248, 250, 251, 255};
const SDL_Color COL_ACCENT{26, 120, 110, 255};
const SDL_Color COL_ACCENT_HOVER{32, 145, 132, 255};
const SDL_Color COL_DANGER{160, 55, 55, 255};
const SDL_Color COL_DANGER_HOVER{185, 70, 70, 255};
const SDL_Color COL_TEXT{30, 35, 40, 255};
const SDL_Color COL_TEXT_LIGHT{240, 245, 247, 255};
const SDL_Color COL_MUTED{160, 175, 185, 255};

struct Button {
    SDL_Rect rect{};
    std::string text;
    SDL_Color bg{};
    SDL_Color hoverBg{};
    SDL_Color fg{};
    SDL_Color border{0, 0, 0, 0};
    bool hasBorder = false;
    bool visible = true;
    bool enabled = true;
    bool hover = false;

    bool hit(int mx, int my) const {
        return visible && enabled &&
               mx >= rect.x && mx < rect.x + rect.w &&
               my >= rect.y && my < rect.y + rect.h;
    }

    void updateHover(int mx, int my) {
        hover = hit(mx, my);
    }
};

void fillRect(SDL_Renderer* ren, const SDL_Rect& r, SDL_Color c) {
    SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(ren, &r);
}

void drawRect(SDL_Renderer* ren, const SDL_Rect& r, SDL_Color c) {
    SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
    SDL_RenderDrawRect(ren, &r);
}

void drawText(SDL_Renderer* ren, TTF_Font* font, const std::string& text,
              int x, int y, SDL_Color color, bool center = false) {
    if (!font || text.empty())
        return;
    SDL_Surface* surf = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    if (!surf)
        return;
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surf);
    if (tex) {
        SDL_Rect dst{x, y, surf->w, surf->h};
        if (center) {
            dst.x = x - surf->w / 2;
            dst.y = y - surf->h / 2;
        }
        SDL_RenderCopy(ren, tex, nullptr, &dst);
        SDL_DestroyTexture(tex);
    }
    SDL_FreeSurface(surf);
}

void drawButton(SDL_Renderer* ren, TTF_Font* font, const Button& b) {
    if (!b.visible)
        return;
    SDL_Color fill = b.hover ? b.hoverBg : b.bg;
    fillRect(ren, b.rect, fill);
    if (b.hasBorder)
        drawRect(ren, b.rect, b.border);
    drawText(ren, font, b.text, b.rect.x + b.rect.w / 2, b.rect.y + b.rect.h / 2,
             b.fg, true);
}

SDL_Texture* loadTexture(SDL_Renderer* ren, const std::string& path, int* w = nullptr,
                         int* h = nullptr) {
    SDL_Surface* surf = IMG_Load(path.c_str());
    if (!surf) {
        std::fprintf(stderr, "No se pudo cargar %s: %s\n", path.c_str(), IMG_GetError());
        return nullptr;
    }
    if (w) *w = surf->w;
    if (h) *h = surf->h;
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surf);
    SDL_FreeSurface(surf);
    return tex;
}

std::string assetPath(const char* name) {
    // Assets viven en el directorio padre del binario (carpeta del proyecto)
    return std::string("../") + name;
}

TTF_Font* openFont(int size) {
    const char* candidates[] = {
        "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf",
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
        "/usr/share/fonts/truetype/liberation/LiberationSans-Bold.ttf",
        "/usr/share/fonts/truetype/freefont/FreeSansBold.ttf",
    };
    for (const char* path : candidates) {
        TTF_Font* f = TTF_OpenFont(path, size);
        if (f)
            return f;
    }
    return nullptr;
}
}  // namespace

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        std::fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
        return 1;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::fprintf(stderr, "IMG_Init: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }
    if (TTF_Init() != 0) {
        std::fprintf(stderr, "TTF_Init: %s\n", TTF_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow(
        "Modelo Predador - Presa",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIN_W, WIN_H, SDL_WINDOW_SHOWN);
    if (!win) {
        std::fprintf(stderr, "Window: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!ren)
        ren = SDL_CreateRenderer(win, -1, 0);

    int conejoW = 0, conejoH = 0;
    SDL_Texture* texPista = loadTexture(ren, assetPath("Pista.png"));
    SDL_Texture* texConejo = loadTexture(ren, assetPath("Fig_Conejo.png"), &conejoW, &conejoH);
    SDL_Texture* texFondo = loadTexture(ren, assetPath("FONDO1.png"));
    if (!texPista || !texConejo || !texFondo) {
        std::fprintf(stderr, "Faltan PNG. Ejecuta desde cpp/ o con ./run.sh\n");
        return 1;
    }

    TTF_Font* fontLabel = openFont(16);
    TTF_Font* fontHint = openFont(13);
    TTF_Font* fontHud = openFont(15);
    TTF_Font* fontTitle = openFont(14);
    TTF_Font* fontBtn = openFont(18);
    TTF_Font* fontBig = openFont(20);

    int numC = 15;
    int tiempo = 100;
    bool iniciar = false;
    std::unique_ptr<Juego> juego;

    const int panelH = 148;
    const int panelMargin = 18;
    SDL_Rect panelRect{panelMargin, WIN_H - panelH - panelMargin,
                       WIN_W - panelMargin * 2, panelH};
    int row1Y = panelRect.y + 42;
    int row2Y = panelRect.y + 92;
    int leftX = panelRect.x + 28;
    const int stepW = 44, valW = 72, btnH = 36, gap = 8;
    int stepX = leftX + 110;

    auto makeStepper = [&](int x, int y, Button& menos, Button& valor, Button& mas) {
        menos = Button{{x, y, stepW, btnH}, "-", COL_BTN, COL_BTN_HOVER, COL_TEXT, COL_BTN_BORDER, true};
        valor = Button{{x + stepW + gap, y, valW, btnH}, "", COL_VALUE, COL_VALUE, COL_TEXT, COL_BTN_BORDER, true};
        valor.enabled = false;
        mas = Button{{x + stepW + gap + valW + gap, y, stepW, btnH}, "+", COL_BTN, COL_BTN_HOVER, COL_TEXT, COL_BTN_BORDER, true};
    };

    Button btnMenosC, btnConejos, btnMasC;
    Button btnMenosTs, btnTs, btnMasTs;
    makeStepper(stepX, row1Y, btnMenosC, btnConejos, btnMasC);
    makeStepper(stepX, row2Y, btnMenosTs, btnTs, btnMasTs);
    btnConejos.text = std::to_string(numC);
    btnTs.text = std::to_string(tiempo);

    Button btnInicio{{panelRect.x + panelRect.w - 170, panelRect.y + panelRect.h / 2 - 24, 140, 48},
                     "Iniciar", COL_ACCENT, COL_ACCENT_HOVER, COL_TEXT_LIGHT};
    Button btnFin{{WIN_W - 150, WIN_H - 52, 130, 40},
                  "Finalizar", COL_DANGER, COL_DANGER_HOVER, COL_TEXT_LIGHT};
    btnFin.visible = false;

    Button* uiPre[] = {&btnInicio, &btnMenosC, &btnConejos, &btnMasC,
                       &btnMenosTs, &btnTs, &btnMasTs};

    bool running = true;
    Uint32 frameDelay = 1000 / FPS;

    while (running) {
        Uint32 frameStart = SDL_GetTicks();
        int mx = 0, my = 0;
        SDL_GetMouseState(&mx, &my);
        for (auto* b : uiPre)
            b->updateHover(mx, my);
        btnFin.updateHover(mx, my);

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                running = false;
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                else if (e.key.keysym.sym == SDLK_o && iniciar)
                    btnFin.visible = true;
                else if (e.key.keysym.sym == SDLK_i && iniciar)
                    btnFin.visible = false;
            } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                int x = e.button.x, y = e.button.y;
                if (btnInicio.hit(x, y) && !iniciar) {
                    juego = std::make_unique<Juego>(texPista, conejoW, conejoH, numC, tiempo);
                    iniciar = true;
                    for (auto* b : uiPre)
                        b->visible = false;
                    btnFin.visible = true;
                } else if (btnMasC.hit(x, y) && !iniciar) {
                    ++numC;
                    btnConejos.text = std::to_string(numC);
                } else if (btnMenosC.hit(x, y) && !iniciar) {
                    if (numC >= 2) {
                        --numC;
                        btnConejos.text = std::to_string(numC);
                    }
                } else if (btnMasTs.hit(x, y) && !iniciar) {
                    tiempo += 50;
                    btnTs.text = std::to_string(tiempo);
                } else if (btnMenosTs.hit(x, y) && !iniciar) {
                    if (tiempo > 100) {
                        tiempo -= 10;
                        btnTs.text = std::to_string(tiempo);
                    }
                } else if (btnFin.hit(x, y)) {
                    iniciar = false;
                    juego.reset();
                    btnFin.visible = false;
                    for (auto* b : uiPre)
                        b->visible = true;
                }
            }
        }

        if (iniciar && juego) {
            juego->mover();
            SDL_SetRenderDrawColor(ren, 230, 240, 235, 255);
            SDL_RenderClear(ren);
            juego->dibujar(ren, texPista, texConejo);

            SDL_Rect hud{0, WIN_H - 56, WIN_W, 56};
            fillRect(ren, hud, COL_PANEL);
            SDL_SetRenderDrawColor(ren, COL_PANEL_EDGE.r, COL_PANEL_EDGE.g, COL_PANEL_EDGE.b, 255);
            SDL_RenderDrawLine(ren, 0, WIN_H - 56, WIN_W, WIN_H - 56);

            drawText(ren, fontHud, "Conejos vivos:  " + std::to_string(juego->getNC()),
                     24, WIN_H - 38, COL_TEXT_LIGHT);
            drawText(ren, fontHint, "Esc salir   ·   O / I mostrar u ocultar Finalizar",
                     260, WIN_H - 36, COL_MUTED);
            drawButton(ren, fontBtn, btnFin);
        } else {
            // Fondo blanco como en FONDO1 (el PNG tiene transparencia en bordes)
            SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
            SDL_RenderClear(ren);

            // Ilustración centrada en el área sobre el panel, sin tintar ni deformar
            int artAreaH = panelRect.y - 8;
            int texFW = 0, texFH = 0;
            SDL_QueryTexture(texFondo, nullptr, nullptr, &texFW, &texFH);
            float scale = std::min(static_cast<float>(WIN_W) / texFW,
                                   static_cast<float>(artAreaH) / texFH);
            int dw = static_cast<int>(texFW * scale);
            int dh = static_cast<int>(texFH * scale);
            SDL_Rect artDst{(WIN_W - dw) / 2, (artAreaH - dh) / 2, dw, dh};
            SDL_SetTextureBlendMode(texFondo, SDL_BLENDMODE_BLEND);
            SDL_RenderCopy(ren, texFondo, nullptr, &artDst);

            fillRect(ren, panelRect, COL_PANEL);
            drawRect(ren, panelRect, COL_PANEL_EDGE);

            drawText(ren, fontTitle, "Configuracion de la simulacion",
                     panelRect.x + 28, panelRect.y + 14, COL_TEXT_LIGHT);
            drawText(ren, fontLabel, "Conejos", leftX, row1Y + 8, COL_MUTED);
            drawText(ren, fontLabel, "Tiempo", leftX, row2Y + 8, COL_MUTED);

            for (auto* b : uiPre)
                drawButton(ren, b == &btnInicio ? fontBig : fontBtn, *b);
        }

        SDL_RenderPresent(ren);

        Uint32 elapsed = SDL_GetTicks() - frameStart;
        if (elapsed < frameDelay)
            SDL_Delay(frameDelay - elapsed);
    }

    if (fontLabel) TTF_CloseFont(fontLabel);
    if (fontHint) TTF_CloseFont(fontHint);
    if (fontHud) TTF_CloseFont(fontHud);
    if (fontTitle) TTF_CloseFont(fontTitle);
    if (fontBtn) TTF_CloseFont(fontBtn);
    if (fontBig) TTF_CloseFont(fontBig);
    SDL_DestroyTexture(texPista);
    SDL_DestroyTexture(texConejo);
    SDL_DestroyTexture(texFondo);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
