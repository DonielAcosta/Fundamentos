#pragma once
#include <SFML/Graphics.hpp>

/**
 * Depredador: persigue al conejo más cercano y lo elimina al alcanzarlo.
 */
class Zorro {
	float x, y;
	float xFu, yFu;
	float dx, dy;
	float ancho, alto; ///< Celda del spritesheet
	int indiceX, indiceY;
	int contador;
	float velocidad;

public:
	/** Coloca al zorro y configura el spritesheet desde la textura. */
	Zorro(float x, float y, const sf::Texture& textura);

	float getX() const { return x; }
	float getY() const { return y; }
	float getXFu() const { return xFu; }
	float getYFu() const { return yFu; }
	float getAncho() const { return 70.f; }

	/** Calcula desplazamiento hacia el objetivo (tx,ty) y anima el sprite. */
	void perseguir(float tx, float ty);
	/** Confirma el movimiento a (xFu,yFu). */
	void mover();
	/** Dibuja el sprite del zorro. */
	void dibujar(sf::RenderWindow& ventana, const sf::Texture& textura);
};
