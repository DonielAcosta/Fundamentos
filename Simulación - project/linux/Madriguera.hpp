#pragma once
#include <SFML/Graphics.hpp>

/**
 * Hoyo del que salen las crías al nacer / en partos espontáneos.
 */
class Madriguera {
	float x, y;   ///< Centro
	float radio;  ///< Radio visual del hoyo
	int cooldown; ///< Frames de espera entre partos

public:
	/** Crea madriguera en (x,y) con cooldown inicial aleatorio. */
	Madriguera(float x, float y);

	float getX() const { return x; }
	float getY() const { return y; }
	float getRadio() const { return radio; }

	/** true si ya puede liberar otra cría. */
	bool listaParaParto();
	/** Reinicia el tiempo de espera tras un nacimiento. */
	void reiniciarCooldown();
	/** Decrementa el cooldown un frame. */
	void tick();

	/** Dibuja tierra + hueco + sombra. */
	void dibujar(sf::RenderWindow& ventana) const;
};
