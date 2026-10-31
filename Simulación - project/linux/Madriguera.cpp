#include "Madriguera.hpp"
#include <cstdlib>

// Crea una madriguera en (px, py) con radio fijo y un cooldown inicial aleatorio.
Madriguera::Madriguera(float px, float py)
	: x(px), y(py), radio(34.f), cooldown(40 + rand() % 80)
{
}

// Indica si la madriguera ya puede liberar otra cría (cooldown terminado).
bool Madriguera::listaParaParto()
{
	return cooldown <= 0;
}

// Reinicia el tiempo de espera después de un nacimiento.
void Madriguera::reiniciarCooldown()
{
	cooldown = 50 + rand() % 100;
}

// Resta un frame al cooldown si todavía es positivo.
void Madriguera::tick()
{
	if (cooldown > 0)
		cooldown--;
}

// Dibuja la madriguera: círculo de tierra, hueco oscuro y sombra.
void Madriguera::dibujar(sf::RenderWindow& ventana) const
{
	sf::CircleShape tierra(radio + 10.f);
	tierra.setOrigin(radio + 10.f, radio + 10.f);
	tierra.setPosition(x, y);
	tierra.setFillColor(sf::Color(92, 64, 40));
	tierra.setOutlineThickness(3.f);
	tierra.setOutlineColor(sf::Color(60, 40, 22));
	ventana.draw(tierra);

	sf::CircleShape hueco(radio);
	hueco.setOrigin(radio, radio);
	hueco.setPosition(x, y);
	hueco.setFillColor(sf::Color(25, 18, 10));
	ventana.draw(hueco);

	sf::CircleShape sombra(radio * 0.55f);
	sombra.setOrigin(radio * 0.55f, radio * 0.55f);
	sombra.setPosition(x + 4.f, y + 6.f);
	sombra.setFillColor(sf::Color(0, 0, 0, 120));
	ventana.draw(sombra);
}
