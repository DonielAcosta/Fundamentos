#include "Fondo.hpp"

// Constructor por defecto: escenario de 1200x700 en el origen.
Fondo::Fondo()
	: x(0), y(0), ancho(1200), alto(700), texW(1200), texH(700)
{
}

// Constructor con vista: fija origen y tamaño visual; guarda el tamaño real de la textura para escalar.
Fondo::Fondo(float px, float py, float anchoVista, float altoVista, const sf::Texture& textura)
	: x(px), y(py), ancho(anchoVista), alto(altoVista)
{
	texW = static_cast<float>(textura.getSize().x);
	texH = static_cast<float>(textura.getSize().y);
}

// Destructor del fondo.
Fondo::~Fondo() {}

// Devuelve la coordenada X del origen del escenario.
float Fondo::getX() const { return x; }

// Devuelve la coordenada Y del origen del escenario.
float Fondo::getY() const { return y; }

// Devuelve el ancho lógico del escenario (límites de movimiento).
float Fondo::getAncho() const { return ancho; }

// Devuelve el alto lógico del escenario (límites de movimiento).
float Fondo::getAlto() const { return alto; }

// Dibuja la textura escalada para llenar exactamente el rectángulo del escenario.
void Fondo::dibujar(sf::RenderWindow& ventana, const sf::Texture& textura)
{
	sf::Sprite sprite;
	sprite.setTexture(textura);
	sprite.setPosition(x, y);
	if (texW > 0.f && texH > 0.f)
		sprite.setScale(ancho / texW, alto / texH);
	ventana.draw(sprite);
}
