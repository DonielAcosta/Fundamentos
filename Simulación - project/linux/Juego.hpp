#pragma once
#include "Conejo.hpp"
#include "Fondo.hpp"
#include "Madriguera.hpp"
#include "Zorro.hpp"
#include <cmath>
#include <cstdlib>
#include <vector>

/** Contadores mostrados al finalizar la simulación. */
struct Estadisticas {
	int nacimientos = 0;       ///< Crías nacidas en la corrida
	int muertosNatural = 0;    ///< Muertes por edad/enfermedad
	int comidosPorZorro = 0;   ///< Presas cazadas
	int poblacionInicial = 0;  ///< Conejos al inicio
	int poblacionFinal = 0;    ///< Conejos al terminar
};

/**
 * Motor de la simulación: población, madrigueras, epidemia, caza y dibujo.
 */
class Juego {
	Fondo* fondo;
	Conejo** conejo;                 ///< Hasta 1000 slots (nullptr = vacío)
	std::vector<Madriguera> madrigueras;
	Zorro* zorro;
	int tiempo;
	int NC;                          ///< Conejos vivos
	bool casoCero;                   ///< Ya hubo primer infectado
	Estadisticas stats;
	int ticks;                       ///< Frames de simulación
	bool terminado;

	/** Madriguera con menor distancia a (px,py). */
	Madriguera* madrigueraMasCercana(float px, float py);
	/** Elimina conejo i y actualiza estadísticas (natural o zorro). */
	void matarConejo(int i, bool porZorro);
	/** Crea una cría saliendo de la madriguera más cercana. */
	bool nacerEnMadriguera(const sf::Texture& figConejo, float cercaX, float cercaY);

public:
	/**
	 * Inicializa escenario, 3 madrigueras, numC conejos y un zorro.
	 * @param p parámetro de tiempo histórico (reservado)
	 * @param vistaX/Y/W/H rectángulo del área de juego
	 */
	Juego(const sf::Texture& fondoTex, const sf::Texture& conejoTex,
		const sf::Texture& zorroTex,
		int numC, int p,
		float vistaX, float vistaY, float vistaW, float vistaH);
	~Juego();

	int getNC() const { return NC; }                         ///< Conejos vivos
	bool estaTerminado() const { return terminado; }         ///< Fin de corrida
	const Estadisticas& getStats() const { return stats; }   ///< Stats finales
	void finalizar();                                        ///< Corta y fija población final

	/** true si hay otro conejo demasiado cerca de (x,y). */
	bool hayChoque(float x, float y) const;
	/** Conejo inicial cerca de una madriguera (no cuenta nacimiento). */
	void setConejo(const sf::Texture& figConejo);
	/** Inserta conejo; si cuentaNacimiento, sale de madriguera. */
	void setConejo(const sf::Texture& figConejo, float px, float py, bool cuentaNacimiento);

	/** true si (x,y) con margen a está dentro del escenario. */
	bool esPosible(float x, float y, float a) const;
	/** Vejez, enfermedad y cambios de fertilidad. */
	void controldeMortalidad();
	/** Mortalidad + partos en madriguera + reproducción por parejas. */
	void reproducir(const sf::Texture& figConejo);
	/** Marca el primer conejo infectado (caso cero). */
	void enfermar();
	/** Contagia enfermedad a vecinos cercanos. */
	void propagar();
	/** Si no quedan enfermos, reinicia el flag casoCero. */
	void verificarCasoCero();
	/** Zorro persigue, conejos huyen, posible captura. */
	void cazar();
	/** Un frame completo de simulación (o no-op si terminado). */
	void mover(const sf::Texture& figConejo);
	/** Dibuja fondo, madrigueras, conejos y zorro. */
	void dibujar(sf::RenderWindow& ventana,
		const sf::Texture& figuraFondo,
		const sf::Texture& figConejo,
		const sf::Texture& figConejoMacho,
		const sf::Texture& figConejoEnfermo,
		const sf::Texture& figZorro);

	/** Distancia euclidiana entre dos puntos. */
	static double dist(float posx, float posy, float posxx, float posyy)
	{
		return std::sqrt(std::pow(posx - posxx, 2) + std::pow(posy - posyy, 2));
	}
};
