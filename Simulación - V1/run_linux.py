#!/usr/bin/env python3
"""
Puerto Linux de Modelo Predador-Presa (original: C++/CLI WinForms).
Misma lógica de movimiento, reproducción y mortalidad de conejos.
"""
from __future__ import annotations

import math
import os
import random
import sys

import pygame

BASE = os.path.dirname(os.path.abspath(__file__))
WIN_W, WIN_H = 861, 594
FPS = 30
DRAW_SIZE = 60


class Fondo:
    def __init__(self, x: int, y: int, surface: pygame.Surface):
        self.x = x
        self.y = y
        self.ancho = surface.get_width()
        self.alto = surface.get_height()

    def dibujar(self, screen: pygame.Surface, figura: pygame.Surface):
        screen.blit(figura, (self.x, self.y))


class Conejo:
    def __init__(self, x: float, y: float, fig: pygame.Surface, limx: int, limy: int):
        self.edad = 0
        self.x = float(x)
        self.y = float(y)
        self.x_fu = self.x
        self.y_fu = self.y
        self.ancho = fig.get_width() / 4
        self.alto = fig.get_height() / 4
        self.dx = 10.0
        self.dy = 10.0
        self.indice_x = 0
        self.indice_y = 0
        self.limx = limx
        self.limy = limy
        self.contador = 0
        self.direccion = "S"

    def decidir_direccion(self) -> str:
        return random.choice(["N", "S", "E", "O"])

    def decidir(self):
        self.contador += 1
        self.indice_x = (self.indice_x + 1) % 4
        if self.contador % 10 == 0:
            self.direccion = self.decidir_direccion()
            self.contador = 0

        # Mantener el eje no usado (bug fix respecto al original)
        self.x_fu = self.x
        self.y_fu = self.y
        if self.direccion == "N":
            self.indice_y = 3
            self.y_fu = self.y - self.dy
        elif self.direccion == "S":
            self.indice_y = 0
            self.y_fu = self.y + self.dy
        elif self.direccion == "E":
            self.indice_y = 2
            self.x_fu = self.x + self.dx
        elif self.direccion == "O":
            self.indice_y = 1
            self.x_fu = self.x - self.dx

    def mover(self):
        self.x = self.x_fu
        self.y = self.y_fu

    def dibujar(self, screen: pygame.Surface, fig: pygame.Surface):
        self.edad += 1
        rx = int(self.indice_x * self.ancho)
        ry = int(self.indice_y * self.alto)
        rw = max(1, int(self.ancho))
        rh = max(1, int(self.alto))
        frame = fig.subsurface(pygame.Rect(rx, ry, rw, rh))
        frame = pygame.transform.scale(frame, (DRAW_SIZE, DRAW_SIZE))
        screen.blit(frame, (int(self.x), int(self.y)))


class Juego:
    def __init__(self, fondo_img: pygame.Surface, fig_conejo: pygame.Surface, num_c: int, tiempo: int):
        self.fondo = Fondo(20, 20, fondo_img)
        self.conejo: list[Conejo | None] = [None] * 1000
        self.nc = 0
        self.tiempo = tiempo
        self.fig_conejo = fig_conejo
        for _ in range(num_c):
            self.set_conejo()

    def dist(self, x1, y1, x2, y2) -> float:
        return math.hypot(x1 - x2, y1 - y2)

    def hay_choque(self, x: float, y: float) -> bool:
        for c in self.conejo:
            if c is not None and self.dist(x, y, c.x, c.y) < c.ancho:
                return True
        return False

    def set_conejo(self, px: float | None = None, py: float | None = None):
        if px is None:
            while True:
                x = random.randint(100, max(101, self.fondo.ancho - 200))
                y = random.randint(100, max(101, self.fondo.alto - 200))
                if not self.hay_choque(x, y):
                    break
            for i in range(len(self.conejo)):
                if self.conejo[i] is None:
                    self.conejo[i] = Conejo(x, y, self.fig_conejo, self.fondo.ancho, self.fondo.alto)
                    self.nc += 1
                    return
        else:
            cont = 0
            while True:
                cont += 1
                x = random.randint(0, 149) + px - 75
                y = random.randint(0, 149) + py - 75
                if cont > 150:
                    return
                if (
                    not self.hay_choque(x, y)
                    and 60 <= x <= self.fondo.ancho - 60
                    and 60 <= y <= self.fondo.alto - 60
                ):
                    break
            for i in range(len(self.conejo)):
                if self.conejo[i] is None:
                    self.conejo[i] = Conejo(x, y, self.fig_conejo, self.fondo.ancho, self.fondo.alto)
                    self.nc += 1
                    return

    def es_posible(self, x: float, y: float, a: float) -> bool:
        return a <= x < self.fondo.ancho - a and a <= y < self.fondo.alto - a

    def control_mortalidad(self):
        for i, c in enumerate(self.conejo):
            if c is not None and c.edad > 60:
                self.conejo[i] = None
                self.nc -= 1

    def reproducir(self):
        self.control_mortalidad()
        vivos = [(i, c) for i, c in enumerate(self.conejo) if c is not None]
        for i, ci in vivos:
            for j, cj in vivos:
                if i == j:
                    continue
                if ci.edad > 18 and cj.edad > 18:
                    if self.dist(ci.x, ci.y, cj.x, cj.y) < 60:
                        if random.randint(0, 99) < 20:
                            self.set_conejo(ci.x, ci.y)

    def mover(self):
        self.reproducir()
        for c in self.conejo:
            if c is None:
                continue
            c.decidir()
            if self.es_posible(
                c.x_fu + c.ancho / 2,
                c.y_fu + c.alto / 2,
                c.ancho,
            ):
                c.mover()

    def dibujar(self, screen: pygame.Surface, fondo_img: pygame.Surface, fig_conejo: pygame.Surface):
        self.fondo.dibujar(screen, fondo_img)
        for c in self.conejo:
            if c is not None:
                c.dibujar(screen, fig_conejo)


# Paleta
COL_PANEL = (28, 42, 48)
COL_PANEL_EDGE = (55, 78, 88)
COL_BTN = (236, 240, 241)
COL_BTN_HOVER = (255, 255, 255)
COL_BTN_BORDER = (180, 190, 195)
COL_VALUE = (248, 250, 251)
COL_ACCENT = (26, 120, 110)
COL_ACCENT_HOVER = (32, 145, 132)
COL_DANGER = (160, 55, 55)
COL_DANGER_HOVER = (185, 70, 70)
COL_TEXT = (30, 35, 40)
COL_TEXT_LIGHT = (240, 245, 247)
COL_MUTED = (160, 175, 185)


class Button:
    def __init__(
        self,
        rect,
        text,
        bg,
        fg=COL_TEXT,
        font_size=18,
        hover_bg=None,
        border=None,
        radius=8,
    ):
        self.rect = pygame.Rect(rect)
        self.text = text
        self.bg = bg
        self.fg = fg
        self.hover_bg = hover_bg or bg
        self.border = border
        self.radius = radius
        self.font = pygame.font.SysFont("dejavusans", font_size, bold=True)
        self.visible = True
        self.enabled = True
        self._hover = False

    def update_hover(self, mouse_pos):
        self._hover = self.visible and self.enabled and self.rect.collidepoint(mouse_pos)

    def draw(self, screen):
        if not self.visible:
            return
        color = self.hover_bg if self._hover else self.bg
        pygame.draw.rect(screen, color, self.rect, border_radius=self.radius)
        if self.border:
            pygame.draw.rect(screen, self.border, self.rect, width=2, border_radius=self.radius)
        label = self.font.render(self.text, True, self.fg)
        screen.blit(label, label.get_rect(center=self.rect.center))

    def hit(self, pos) -> bool:
        return self.visible and self.enabled and self.rect.collidepoint(pos)


def load_image(name: str) -> pygame.Surface:
    path = os.path.join(BASE, name)
    if not os.path.exists(path):
        raise FileNotFoundError(f"No se encontró {path}")
    return pygame.image.load(path).convert_alpha()


def draw_rounded_panel(screen, rect, fill, edge, radius=14):
    pygame.draw.rect(screen, fill, rect, border_radius=radius)
    pygame.draw.rect(screen, edge, rect, width=2, border_radius=radius)


def main():
    os.chdir(BASE)
    pygame.init()
    screen = pygame.display.set_mode((WIN_W, WIN_H))
    pygame.display.set_caption("Modelo Predador - Presa")
    clock = pygame.time.Clock()

    fondo_espacio = load_image("Pista.png")
    fig_conejo = load_image("Fig_Conejo.png")
    fig_fondo = load_image("FONDO1.png")

    num_c = 15
    tiempo = 100
    iniciar = False
    juego: Juego | None = None

    # Panel inferior centrado
    panel_h = 148
    panel_margin = 18
    panel_rect = pygame.Rect(
        panel_margin,
        WIN_H - panel_h - panel_margin,
        WIN_W - panel_margin * 2,
        panel_h,
    )

    # Filas de controles dentro del panel
    row1_y = panel_rect.y + 42
    row2_y = panel_rect.y + 92
    left_x = panel_rect.x + 28
    step_w, val_w, btn_h = 44, 72, 36
    gap = 8

    def stepper(x, y):
        menos = Button(
            (x, y, step_w, btn_h),
            "−",
            COL_BTN,
            COL_TEXT,
            22,
            COL_BTN_HOVER,
            COL_BTN_BORDER,
        )
        valor = Button(
            (x + step_w + gap, y, val_w, btn_h),
            "",
            COL_VALUE,
            COL_TEXT,
            16,
            COL_VALUE,
            COL_BTN_BORDER,
        )
        valor.enabled = False
        mas = Button(
            (x + step_w + gap + val_w + gap, y, step_w, btn_h),
            "+",
            COL_BTN,
            COL_TEXT,
            22,
            COL_BTN_HOVER,
            COL_BTN_BORDER,
        )
        return menos, valor, mas

    btn_menos_c, btn_conejos, btn_mas_c = stepper(left_x + 110, row1_y)
    btn_menos_ts, btn_ts, btn_mas_ts = stepper(left_x + 110, row2_y)
    btn_conejos.text = str(num_c)
    btn_ts.text = str(tiempo)

    btn_inicio = Button(
        (panel_rect.right - 170, panel_rect.centery - 24, 140, 48),
        "Iniciar",
        COL_ACCENT,
        COL_TEXT_LIGHT,
        20,
        COL_ACCENT_HOVER,
        radius=10,
    )
    btn_fin = Button(
        (WIN_W - 150, WIN_H - 52, 130, 40),
        "Finalizar",
        COL_DANGER,
        COL_TEXT_LIGHT,
        16,
        COL_DANGER_HOVER,
        radius=8,
    )
    btn_fin.visible = False

    ui_pre = [
        btn_inicio,
        btn_menos_c,
        btn_conejos,
        btn_mas_c,
        btn_menos_ts,
        btn_ts,
        btn_mas_ts,
    ]
    font_label = pygame.font.SysFont("dejavusans", 16, bold=True)
    font_hint = pygame.font.SysFont("dejavusans", 13)
    font_hud = pygame.font.SysFont("dejavusans", 15, bold=True)
    font_title_bar = pygame.font.SysFont("dejavusans", 14, bold=True)

    running = True
    while running:
        mouse = pygame.mouse.get_pos()
        for b in ui_pre + [btn_fin]:
            b.update_hover(mouse)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                elif event.key == pygame.K_o and iniciar:
                    btn_fin.visible = True
                elif event.key == pygame.K_i and iniciar:
                    btn_fin.visible = False
            elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                pos = event.pos
                if btn_inicio.hit(pos) and not iniciar:
                    juego = Juego(fondo_espacio, fig_conejo, num_c, tiempo)
                    iniciar = True
                    for b in ui_pre:
                        b.visible = False
                    btn_fin.visible = True
                elif btn_mas_c.hit(pos) and not iniciar:
                    num_c += 1
                    btn_conejos.text = str(num_c)
                elif btn_menos_c.hit(pos) and not iniciar:
                    if num_c >= 2:
                        num_c -= 1
                        btn_conejos.text = str(num_c)
                elif btn_mas_ts.hit(pos) and not iniciar:
                    tiempo += 50
                    btn_ts.text = str(tiempo)
                elif btn_menos_ts.hit(pos) and not iniciar:
                    if tiempo > 100:
                        tiempo -= 10
                        btn_ts.text = str(tiempo)
                elif btn_fin.hit(pos):
                    iniciar = False
                    juego = None
                    btn_fin.visible = False
                    for b in ui_pre:
                        b.visible = True

        if iniciar and juego is not None:
            juego.mover()
            screen.fill((230, 240, 235))
            juego.dibujar(screen, fondo_espacio, fig_conejo)

            # Barra HUD inferior
            hud = pygame.Rect(0, WIN_H - 56, WIN_W, 56)
            pygame.draw.rect(screen, COL_PANEL, hud)
            pygame.draw.line(screen, COL_PANEL_EDGE, (0, WIN_H - 56), (WIN_W, WIN_H - 56), 2)
            hud_text = font_hud.render(
                f"Conejos vivos:  {juego.nc}",
                True,
                COL_TEXT_LIGHT,
            )
            hint = font_hint.render("Esc salir   ·   O / I mostrar u ocultar Finalizar", True, COL_MUTED)
            screen.blit(hud_text, (24, WIN_H - 38))
            screen.blit(hint, (260, WIN_H - 36))
            btn_fin.draw(screen)
        else:
            # Ilustración arriba, panel limpio abajo (sin solapar el título del arte)
            art_h = WIN_H - panel_h - panel_margin * 2 - 8
            scaled = pygame.transform.smoothscale(fig_fondo, (WIN_W, art_h + 40))
            screen.fill((210, 220, 205))
            screen.blit(scaled, (0, -10))

            # Degradado suave hacia el panel
            fade = pygame.Surface((WIN_W, 70), pygame.SRCALPHA)
            for i in range(70):
                alpha = int(200 * (i / 70))
                pygame.draw.line(fade, (28, 42, 48, alpha), (0, i), (WIN_W, i))
            screen.blit(fade, (0, panel_rect.y - 55))

            draw_rounded_panel(screen, panel_rect, COL_PANEL, COL_PANEL_EDGE, radius=16)

            header = font_title_bar.render("Configuración de la simulación", True, COL_TEXT_LIGHT)
            screen.blit(header, (panel_rect.x + 28, panel_rect.y + 14))

            lbl_c = font_label.render("Conejos", True, COL_MUTED)
            lbl_t = font_label.render("Tiempo", True, COL_MUTED)
            screen.blit(lbl_c, (left_x, row1_y + 8))
            screen.blit(lbl_t, (left_x, row2_y + 8))

            for b in ui_pre:
                b.draw(screen)

        pygame.display.flip()
        clock.tick(FPS)

    pygame.quit()
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception as exc:
        print(f"Error al ejecutar: {exc}", file=sys.stderr)
        sys.exit(1)

