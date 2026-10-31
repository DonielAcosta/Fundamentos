#pragma once
#include "Animal.hpp"

/**
 * Presa del modelo: se mueve sola, tiene color de pelaje y puede huir del zorro.
 */
class Conejo : public Animal {
	int contador;          ///< Frames desde el último cambio de dirección
	int limiteContador;    ///< Cada cuántos frames cambia de rumbo
	sf::Color colorPelaje; ///< Tinte aplicado al sprite

	/** Devuelve 'N','S','E' u 'O' al azar. */
	char decidirDireccion();
	/** Elige un color de la paleta de pelajes. */
	static sf::Color colorAleatorio();

public:
	Conejo();
	/** Crea conejo en (x,y) con límites de mapa y color aleatorio. */
	Conejo(float x, float y, const sf::Texture& textura, int limAncho, int limAlto);
	~Conejo() override;

	/** Aplica la posición futura si aún tiene “hambre” (energía). */
	void mover();
	/** Actualiza animación, dirección periódica y calcula (xFu,yFu). */
	void decidir();
	/** Marca al conejo como enfermo. */
	void enfermar();
	/** Orienta la huida en sentido contrario al punto (zx,zy). */
	void huirDe(float zx, float zy);

	sf::Color getColor() const { return colorPelaje; }

	/** Dibuja el conejo aplicando color de pelaje (salvo si está enfermo). */
	void dibujar(sf::RenderWindow& ventana,
		const sf::Texture& figHembra,
		const sf::Texture& figMacho,
		const sf::Texture& figEnfermo);
};
