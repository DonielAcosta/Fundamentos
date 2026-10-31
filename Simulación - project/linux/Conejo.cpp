#include "Conejo.hpp"
#include <cmath>
#include <cstdlib>

// Elige al azar un color de pelaje de la paleta predefinida.
sf::Color Conejo::colorAleatorio()
{
	static const sf::Color paleta[] = {
		sf::Color(255, 255, 255),
		sf::Color(240, 220, 180),
		sf::Color(210, 160, 110),
		sf::Color(160, 110, 70),
		sf::Color(120, 80, 50),
		sf::Color(90, 90, 95),
		sf::Color(200, 120, 140),
		sf::Color(170, 200, 230),
		sf::Color(190, 230, 160),
		sf::Color(255, 210, 90),
	};
	return paleta[rand() % 10];
}

// Constructor por defecto: inicializa contadores de movimiento y un color aleatorio.
Conejo::Conejo() : Animal()
{
	contador = 0;
	limiteContador = rand() % 20 + 1;
	colorPelaje = colorAleatorio();
}

// Constructor con posición: crea el conejo en (px,py), guarda límites del mapa y asigna color.
Conejo::Conejo(float px, float py, const sf::Texture& textura, int limAncho, int limAlto)
	: Animal(px, py, textura)
{
	limx = limAncho;
	limy = limAlto;
	dx = 8;
	dy = 8;
	contador = 0;
	limiteContador = rand() % 20 + 1;
	colorPelaje = colorAleatorio();
}

// Destructor del conejo.
Conejo::~Conejo() {}

// Aplica la posición futura (xFu, yFu) si el conejo aún tiene energía (hambre >= 0).
void Conejo::mover()
{
	if (hambre >= 0) {
		x = xFu;
		y = yFu;
	}
}

// Decide al azar una dirección cardinal: Norte, Sur, Este u Oeste.
char Conejo::decidirDireccion()
{
	switch (rand() % 4) {
	case 0: return 'N';
	case 1: return 'S';
	case 2: return 'E';
	default: return 'O';
	}
}

// Marca al conejo como enfermo.
void Conejo::enfermar()
{
	enfermo = true;
}

// Orienta la huida en sentido contrario al punto (zx, zy) y aumenta la velocidad.
void Conejo::huirDe(float zx, float zy)
{
	float vx = x - zx;
	float vy = y - zy;
	float len = std::sqrt(vx * vx + vy * vy);
	if (len < 1.f) {
		direccion = decidirDireccion();
		return;
	}
	if (std::abs(vx) > std::abs(vy))
		direccion = vx > 0 ? 'E' : 'O';
	else
		direccion = vy > 0 ? 'S' : 'N';
	dx = 12;
	dy = 12;
}

// Actualiza animación, cambia de rumbo periódicamente y calcula la posición futura.
void Conejo::decidir()
{
	contador++;
	hambre--;
	indiceX = (indiceX + 1) % 4;

	if (contador > limiteContador) {
		direccion = decidirDireccion();
		contador = 0;
		limiteContador = rand() % 20 + 1;
		dx = 8;
		dy = 8;
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

// Dibuja el conejo con el sprite correcto y aplica el color de pelaje si no está enfermo.
void Conejo::dibujar(sf::RenderWindow& ventana,
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
	sprite.setScale(68.f / ancho, 68.f / alto);
	if (!enfermo)
		sprite.setColor(colorPelaje);
	ventana.draw(sprite);
}
