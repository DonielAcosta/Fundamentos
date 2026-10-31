#include "Juego.hpp"
#include <algorithm>

// Inicializa el escenario, 3 madrigueras, la población inicial de conejos y el zorro cazador.
Juego::Juego(const sf::Texture& fondoTex, const sf::Texture& conejoTex,
	const sf::Texture& zorroTex,
	int numC, int p,
	float vistaX, float vistaY, float vistaW, float vistaH)
{
	casoCero = false;
	NC = 0;
	ticks = 0;
	terminado = false;
	stats = Estadisticas{};
	stats.poblacionInicial = numC;

	fondo = new Fondo(vistaX, vistaY, vistaW, vistaH, fondoTex);
	conejo = new Conejo*[1000];
	for (int i = 0; i < 1000; i++)
		conejo[i] = nullptr;

	// 3 madrigueras repartidas en el césped
	madrigueras.emplace_back(vistaX + vistaW * 0.22f, vistaY + vistaH * 0.30f);
	madrigueras.emplace_back(vistaX + vistaW * 0.72f, vistaY + vistaH * 0.28f);
	madrigueras.emplace_back(vistaX + vistaW * 0.48f, vistaY + vistaH * 0.68f);

	for (int i = 0; i < numC; i++)
		setConejo(conejoTex);

	// Zorro en una esquina
	zorro = new Zorro(vistaX + vistaW * 0.85f, vistaY + vistaH * 0.75f, zorroTex);
	tiempo = p;
}

// Libera memoria de todos los conejos, el zorro y el fondo.
Juego::~Juego()
{
	for (int i = 0; i < 1000; i++)
		delete conejo[i];
	delete[] conejo;
	delete zorro;
	delete fondo;
}

// Marca la simulación como terminada y guarda la población final en las estadísticas.
void Juego::finalizar()
{
	if (terminado) return;
	terminado = true;
	stats.poblacionFinal = NC;
}

// Busca y devuelve la madriguera más cercana al punto (px, py).
Madriguera* Juego::madrigueraMasCercana(float px, float py)
{
	Madriguera* best = nullptr;
	double bestD = 1e18;
	for (auto& m : madrigueras) {
		double d = dist(px, py, m.getX(), m.getY());
		if (d < bestD) {
			bestD = d;
			best = &m;
		}
	}
	return best;
}

// Elimina al conejo i; si porZorro es true suma a "comidos", si no a "muertes naturales".
void Juego::matarConejo(int i, bool porZorro)
{
	if (conejo[i] == nullptr) return;
	delete conejo[i];
	conejo[i] = nullptr;
	NC--;
	if (porZorro)
		stats.comidosPorZorro++;
	else
		stats.muertosNatural++;
}

// Devuelve true si ya hay un conejo demasiado cerca de (px, py) (evita solapes al nacer).
bool Juego::hayChoque(float px, float py) const
{
	for (int i = 0; i < 1000; i++) {
		if (conejo[i] != nullptr) {
			if (dist(px, py, conejo[i]->getX(), conejo[i]->getY()) < 45.f)
				return true;
		}
	}
	return false;
}

// Coloca un conejo inicial cerca de una madriguera al azar (no cuenta como nacimiento).
void Juego::setConejo(const sf::Texture& figConejo)
{
	// Nacen cerca de una madriguera al inicio
	Madriguera& m = madrigueras[static_cast<size_t>(rand() % madrigueras.size())];
	float px = 0, py = 0;
	int intentos = 0;
	do {
		float ang = static_cast<float>(rand() % 628) / 100.f;
		float r = 40.f + static_cast<float>(rand() % 70);
		px = m.getX() + std::cos(ang) * r - 30.f;
		py = m.getY() + std::sin(ang) * r - 30.f;
		intentos++;
	} while ((!esPosible(px + 30.f, py + 30.f, 40.f) || hayChoque(px, py)) && intentos < 200);

	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) {
			conejo[i] = new Conejo(px, py, figConejo,
				static_cast<int>(fondo->getAncho()),
				static_cast<int>(fondo->getAlto()));
			NC++;
			return;
		}
	}
}

// Crea una cría saliendo de la madriguera más cercana a (cercaX, cercaY) y suma un nacimiento.
bool Juego::nacerEnMadriguera(const sf::Texture& figConejo, float cercaX, float cercaY)
{
	Madriguera* m = madrigueraMasCercana(cercaX, cercaY);
	if (!m) return false;

	float px = 0, py = 0;
	int intentos = 0;
	do {
		float ang = static_cast<float>(rand() % 628) / 100.f;
		float r = 28.f + static_cast<float>(rand() % 45);
		px = m->getX() + std::cos(ang) * r - 30.f;
		py = m->getY() + std::sin(ang) * r - 30.f;
		intentos++;
	} while ((!esPosible(px + 30.f, py + 30.f, 40.f) || hayChoque(px, py)) && intentos < 120);

	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) {
			conejo[i] = new Conejo(px, py, figConejo,
				static_cast<int>(fondo->getAncho()),
				static_cast<int>(fondo->getAlto()));
			NC++;
			stats.nacimientos++;
			m->reiniciarCooldown();
			return true;
		}
	}
	return false;
}

// Inserta un conejo: si cuentaNacimiento, sale de madriguera; si no, se coloca en (px, py).
void Juego::setConejo(const sf::Texture& figConejo, float px, float py, bool cuentaNacimiento)
{
	if (cuentaNacimiento) {
		nacerEnMadriguera(figConejo, px, py);
		return;
	}
	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) {
			conejo[i] = new Conejo(px, py, figConejo,
				static_cast<int>(fondo->getAncho()),
				static_cast<int>(fondo->getAlto()));
			NC++;
			return;
		}
	}
}

// Comprueba si el punto (px, py) con margen "a" está dentro de los límites del escenario.
bool Juego::esPosible(float px, float py, float a) const
{
	return px >= fondo->getX() + a
		&& px < fondo->getX() + fondo->getAncho() - a
		&& py >= fondo->getY() + a
		&& py < fondo->getY() + fondo->getAlto() - a;
}

// Aplica mortalidad: cambia fertilidad al azar, mata por vejez o por enfermedad.
void Juego::controldeMortalidad()
{
	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) continue;

		if (rand() % 1000 < 40)
			conejo[i]->cambiarFertilidad();

		if (conejo[i]->getEdad() > 220) {
			matarConejo(i, false);
			continue;
		}

		if (conejo[i]->getEnfermo() && rand() % 1000 < 80)
			matarConejo(i, false);
	}
}

// Ejecuta mortalidad, partos en madrigueras y reproducción por parejas (crías salen del hoyo).
void Juego::reproducir(const sf::Texture& figConejo)
{
	controldeMortalidad();

	for (auto& m : madrigueras)
		m.tick();

	// Partos espontáneos desde madriguera si hay adultos cerca
	for (auto& m : madrigueras) {
		if (!m.listaParaParto() || NC >= 350) continue;
		int adultosCerca = 0;
		for (int i = 0; i < 1000; i++) {
			if (conejo[i] == nullptr) continue;
			if (conejo[i]->getEdad() > 18 &&
				dist(conejo[i]->getX(), conejo[i]->getY(), m.getX(), m.getY()) < 140.f)
				adultosCerca++;
		}
		if (adultosCerca >= 2 && rand() % 100 < 35)
			nacerEnMadriguera(figConejo, m.getX(), m.getY());
	}

	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) continue;
		for (int j = i + 1; j < 1000; j++) {
			if (conejo[j] == nullptr) continue;
			if (conejo[i]->getSexo() == conejo[j]->getSexo()) continue;
			if (conejo[i]->getEdad() <= 18 || conejo[j]->getEdad() <= 18) continue;
			if (conejo[i]->getEdad() >= 160 || conejo[j]->getEdad() >= 160) continue;
			if (dist(conejo[i]->getX(), conejo[i]->getY(), conejo[j]->getX(), conejo[j]->getY()) >= 70)
				continue;
			if (rand() % 100 >= 3) continue;
			if (!conejo[i]->getFertilidad() || !conejo[j]->getFertilidad()) continue;
			if (conejo[i]->getEnfermo() || conejo[j]->getEnfermo()) continue;
			if (NC >= 400) continue;

			// La cría sale de la madriguera más cercana a la pareja
			nacerEnMadriguera(figConejo,
				(conejo[i]->getX() + conejo[j]->getX()) / 2.f,
				(conejo[i]->getY() + conejo[j]->getY()) / 2.f);
		}
	}
}

// Infecta al primer conejo vivo encontrado y activa el flag de caso cero (epidemia).
void Juego::enfermar()
{
	if (casoCero) return;
	for (int intento = 0; intento < 1000; intento++) {
		int pos = rand() % 1000;
		if (conejo[pos] != nullptr) {
			conejo[pos]->enfermar();
			casoCero = true;
			return;
		}
	}
}

// Propaga la enfermedad a conejos cercanos a uno enfermo con cierta probabilidad.
void Juego::propagar()
{
	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) continue;
		for (int j = 0; j < 1000; j++) {
			if (conejo[j] == nullptr || i == j) continue;
			if (dist(conejo[i]->getX(), conejo[i]->getY(), conejo[j]->getX(), conejo[j]->getY()) >= 60)
				continue;
			if (conejo[j]->getEnfermo() && rand() % 1000 < 120)
				conejo[i]->enfermar();
		}
	}
}

// Si no queda ningún conejo enfermo, reinicia el flag casoCero para permitir una nueva epidemia.
void Juego::verificarCasoCero()
{
	int contador = 0;
	for (int i = 0; i < 1000; i++) {
		if (conejo[i] != nullptr && conejo[i]->getEnfermo())
			contador++;
	}
	if (contador == 0)
		casoCero = false;
}

// El zorro persigue al conejo más cercano; los cercanos huyen; si lo alcanza, lo come.
void Juego::cazar()
{
	if (!zorro || NC <= 0) return;

	int objetivo = -1;
	double mejor = 1e18;
	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) continue;
		double d = dist(zorro->getX(), zorro->getY(), conejo[i]->getX(), conejo[i]->getY());
		if (d < mejor) {
			mejor = d;
			objetivo = i;
		}
	}
	if (objetivo < 0) return;

	// Conejos cercanos huyen
	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) continue;
		if (dist(zorro->getX(), zorro->getY(), conejo[i]->getX(), conejo[i]->getY()) < 160.f)
			conejo[i]->huirDe(zorro->getX(), zorro->getY());
	}

	zorro->perseguir(conejo[objetivo]->getX(), conejo[objetivo]->getY());
	float nx = zorro->getXFu() + 40.f;
	float ny = zorro->getYFu() + 40.f;
	if (esPosible(nx, ny, 40.f))
		zorro->mover();

	if (dist(zorro->getX(), zorro->getY(), conejo[objetivo]->getX(), conejo[objetivo]->getY()) < 48.f)
		matarConejo(objetivo, true);
}

// Un frame de simulación: reproducir, epidemia, cazar, mover conejos y posible fin automático.
void Juego::mover(const sf::Texture& figConejo)
{
	if (terminado) return;

	ticks++;
	verificarCasoCero();
	reproducir(figConejo);
	if (NC > 180)
		enfermar();
	if (casoCero)
		propagar();

	cazar();

	for (int i = 0; i < 1000; i++) {
		if (conejo[i] == nullptr) continue;
		conejo[i]->decidir();
		if (esPosible(
				conejo[i]->getXFu() + 30.f,
				conejo[i]->getYFu() + 30.f,
				35.f)) {
			conejo[i]->mover();
		}
	}

	// Fin automático: sin conejos o tiempo límite (~45 s a 30 fps)
	if (NC <= 0 || ticks >= 1350)
		finalizar();
}

// Dibuja en orden: fondo (césped), madrigueras, conejos y zorro.
void Juego::dibujar(sf::RenderWindow& ventana,
	const sf::Texture& figuraFondo,
	const sf::Texture& figConejo,
	const sf::Texture& figConejoMacho,
	const sf::Texture& figConejoEnfermo,
	const sf::Texture& figZorro)
{
	fondo->dibujar(ventana, figuraFondo);

	for (const auto& m : madrigueras)
		m.dibujar(ventana);

	for (int i = 0; i < 1000; i++) {
		if (conejo[i] != nullptr)
			conejo[i]->dibujar(ventana, figConejo, figConejoMacho, figConejoEnfermo);
	}

	if (zorro)
		zorro->dibujar(ventana, figZorro);
}
