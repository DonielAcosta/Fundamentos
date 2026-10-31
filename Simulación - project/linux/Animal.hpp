#pragma once
#include <SFML/Graphics.hpp>

/** Direcciones posibles para control por teclado / movimiento. */
enum class Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno };

/**
 * Clase base de un animal en el escenario.
 * Guarda posición, animación de sprite, edad, sexo, fertilidad y enfermedad.
 */
class Animal {
protected:
	int hambre;       ///< Baja cada tick; se reinicia si es muy baja
	int edad;         ///< Aumenta al dibujar
	int indiceX;      ///< Columna del spritesheet (frame de animación)
	int indiceY;      ///< Fila del spritesheet (dirección visual)
	float x, y;       ///< Posición actual
	float xFu, yFu;   ///< Posición futura propuesta
	float ancho, alto;///< Tamaño de una celda del sprite
	float dx, dy;     ///< Paso de desplazamiento
	int limx, limy;   ///< Límites del mapa (usados por subclases)
	char direccion;   ///< 'N','S','E','O'
	bool sexo;        ///< true = macho, false = hembra
	bool fertilidad;
	bool enfermo;

public:
	/** Estado inicial por defecto (posición 100,100). */
	Animal();
	/** Coloca al animal y calcula tamaño de celda a partir de la textura (4x4). */
	Animal(float x, float y, const sf::Texture& textura);
	virtual ~Animal();

	void setX(float x);           ///< Asigna coordenada X
	float getX() const;           ///< Posición X actual
	void setY(float y);           ///< Asigna coordenada Y
	float getY() const;           ///< Posición Y actual
	float getAncho() const;       ///< Ancho de celda del sprite
	float getAlto() const;        ///< Alto de celda del sprite
	float getDX() const;          ///< Paso horizontal
	float getDY() const;          ///< Paso vertical
	float getXFu() const;         ///< X futura
	float getYFu() const;         ///< Y futura
	int getEdad() const;          ///< Edad actual
	bool getSexo() const { return sexo; }                 ///< true macho
	bool getFertilidad() const { return fertilidad; }     ///< Puede reproducirse
	void cambiarFertilidad() { fertilidad = !fertilidad; }///< Invierte fertilidad
	bool getEnfermo() const { return enfermo; }           ///< Estado de salud

	/** Elige sprite (hembra/macho/enfermo), sube edad y dibuja. */
	void dibujar(sf::RenderWindow& ventana,
		const sf::Texture& figHembra,
		const sf::Texture& figMacho,
		const sf::Texture& figEnfermo);
};
