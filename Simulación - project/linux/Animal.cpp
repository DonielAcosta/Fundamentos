#include "Animal.hpp"
#include <cstdlib>

// Constructor por defecto: crea un animal sano, fértil, en (100,100) y sexo aleatorio.
Animal::Animal()
{
	enfermo = false;
	fertilidad = true;
	hambre = 15;
	edad = 0;
	x = y = 100;
	xFu = yFu = 100;
	dx = 0;
	dy = 1;
	indiceX = indiceY = 0;
	ancho = alto = 32;
	limx = limy = 0;
	direccion = 'S';
	sexo = rand() % 2;
}

// Constructor con posición: coloca al animal y calcula el tamaño de una celda del spritesheet (textura 4x4).
Animal::Animal(float px, float py, const sf::Texture& textura)
{
	enfermo = false;
	fertilidad = true;
	hambre = 15;
	edad = 0;
	x = px;
	y = py;
	xFu = px;
	yFu = py;
	dx = 0;
	dy = 0;
	indiceX = indiceY = 0;
	ancho = static_cast<float>(textura.getSize().x) / 4.f;
	alto = static_cast<float>(textura.getSize().y) / 4.f;
	if (ancho < 1) ancho = 32;
	if (alto < 1) alto = 32;
	limx = limy = 0;
	direccion = 'S';
	sexo = rand() % 2;
}

// Destructor: no libera recursos dinámicos propios (las subclases pueden ampliarlo).
Animal::~Animal() {}

// Asigna la coordenada X del animal.
void Animal::setX(float px) { x = px; }

// Devuelve la coordenada X actual.
float Animal::getX() const { return x; }

// Asigna la coordenada Y del animal.
void Animal::setY(float py) { y = py; }

// Devuelve la coordenada Y actual.
float Animal::getY() const { return y; }

// Devuelve el ancho de una celda del sprite.
float Animal::getAncho() const { return ancho; }

// Devuelve el alto de una celda del sprite.
float Animal::getAlto() const { return alto; }

// Devuelve el desplazamiento horizontal por paso.
float Animal::getDX() const { return dx; }

// Devuelve el desplazamiento vertical por paso.
float Animal::getDY() const { return dy; }

// Devuelve la posición X futura calculada antes de mover.
float Animal::getXFu() const { return xFu; }

// Devuelve la posición Y futura calculada antes de mover.
float Animal::getYFu() const { return yFu; }

// Devuelve la edad actual del animal.
int Animal::getEdad() const { return edad; }

// Elige el sprite (hembra, macho o enfermo), aumenta la edad y lo dibuja en la ventana.
void Animal::dibujar(sf::RenderWindow& ventana,
	const sf::Texture& figHembra,
	const sf::Texture& figMacho,
	const sf::Texture& figEnfermo)
{
	edad++;
	if (hambre < -10)
		hambre = rand() % 20 + 15;

	const sf::Texture* tex = &figHembra;
	if (enfermo)
		tex = &figEnfermo;
	else if (sexo)
		tex = &figMacho;

	sf::IntRect recorte(
		static_cast<int>(indiceX * ancho),
		static_cast<int>(indiceY * alto),
		static_cast<int>(ancho),
		static_cast<int>(alto));

	sf::Sprite sprite;
	sprite.setTexture(*tex);
	sprite.setTextureRect(recorte);
	sprite.setPosition(x, y);
	sprite.setScale(72.f / ancho, 72.f / alto);
	ventana.draw(sprite);
}
