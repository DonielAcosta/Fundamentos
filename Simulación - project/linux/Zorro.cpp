#include "Zorro.hpp"
#include <cmath>

// Crea el zorro en (px, py), configura el spritesheet desde la textura y fija la velocidad.
Zorro::Zorro(float px, float py, const sf::Texture& textura)
	: x(px), y(py), xFu(px), yFu(py)
	, dx(0), dy(0)
	, indiceX(0), indiceY(0), contador(0)
	, velocidad(7.5f)
{
	ancho = static_cast<float>(textura.getSize().x) / 4.f;
	alto = static_cast<float>(textura.getSize().y) / 4.f;
	if (ancho < 1.f) ancho = 48.f;
	if (alto < 1.f) alto = 48.f;
}

// Calcula el movimiento hacia el objetivo (tx, ty), actualiza (xFu, yFu) y la animación del sprite.
void Zorro::perseguir(float tx, float ty)
{
	float cx = x + 35.f;
	float cy = y + 35.f;
	float vx = tx + 30.f - cx;
	float vy = ty + 30.f - cy;
	float len = std::sqrt(vx * vx + vy * vy);
	if (len < 1.f) {
		xFu = x;
		yFu = y;
		return;
	}
	dx = (vx / len) * velocidad;
	dy = (vy / len) * velocidad;
	xFu = x + dx;
	yFu = y + dy;

	if (std::abs(dx) > std::abs(dy))
		indiceY = dx > 0 ? 2 : 1;
	else
		indiceY = dy > 0 ? 0 : 3;

	contador++;
	if (contador % 4 == 0)
		indiceX = (indiceX + 1) % 4;
}

// Confirma el desplazamiento aplicando la posición futura como posición actual.
void Zorro::mover()
{
	x = xFu;
	y = yFu;
}

// Dibuja el sprite del zorro en su posición actual con la animación correspondiente.
void Zorro::dibujar(sf::RenderWindow& ventana, const sf::Texture& textura)
{
	sf::IntRect recorte(
		static_cast<int>(indiceX * ancho),
		static_cast<int>(indiceY * alto),
		static_cast<int>(ancho),
		static_cast<int>(alto));

	sf::Sprite sprite;
	sprite.setTexture(textura);
	sprite.setTextureRect(recorte);
	sprite.setPosition(x, y);
	sprite.setScale(80.f / ancho, 80.f / alto);
	ventana.draw(sprite);
}
