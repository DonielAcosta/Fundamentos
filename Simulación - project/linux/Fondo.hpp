#pragma once
#include <SFML/Graphics.hpp>

/**
 * Escenario del juego (césped u otra textura) escalado al área visible.
 */
class Fondo {
	float x, y;       ///< Origen superior-izquierdo
	float ancho, alto;///< Tamaño lógico/visual del escenario
	float texW, texH; ///< Tamaño original de la textura

public:
	Fondo();
	/**
	 * Define el rectángulo del escenario.
	 * @param anchoVista / altoVista tamaño al que se escala la textura
	 */
	Fondo(float x, float y, float anchoVista, float altoVista, const sf::Texture& textura);
	~Fondo();

	float getX() const;     ///< Origen X
	float getY() const;     ///< Origen Y
	float getAncho() const; ///< Ancho lógico (límites de movimiento)
	float getAlto() const;  ///< Alto lógico

	/** Dibuja la textura escalada para cubrir todo el escenario. */
	void dibujar(sf::RenderWindow& ventana, const sf::Texture& textura);
};
