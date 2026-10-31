#include "Juego.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>

namespace {

const sf::Color COL_AMARILLO(255, 204, 0);
const sf::Color COL_AZUL(0, 36, 125);
const sf::Color COL_ROJO(207, 20, 43);
const sf::Color COL_BG(8, 18, 55);
const sf::Color COL_PANEL(0, 28, 95);
const sf::Color COL_PANEL_EDGE(255, 204, 0);
const sf::Color COL_ACCENT(255, 204, 0);
const sf::Color COL_DANGER(207, 20, 43);
const sf::Color COL_MUTED(190, 205, 230);
const sf::Color COL_TEXT(255, 255, 255);
const sf::Color COL_CHIP(0, 45, 140);

/** Botón rectangular con sombra, hover y texto centrado. */
struct Boton {
	sf::RectangleShape rect;
	sf::RectangleShape sombra;
	sf::Text label;
	sf::Color fill;
	sf::Color fillHover;
	bool primario;

	/** Crea el botón en (x,y) con tamaño w×h. */
	Boton(const sf::Font& font, const std::string& texto,
		float x, float y, float w, float h,
		sf::Color color, bool esPrimario = false)
		: fill(color)
		, fillHover(sf::Color(
			  static_cast<sf::Uint8>(std::min(255, color.r + 18)),
			  static_cast<sf::Uint8>(std::min(255, color.g + 18)),
			  static_cast<sf::Uint8>(std::min(255, color.b + 18))))
		, primario(esPrimario)
	{
		sombra.setPosition(x, y + 3.f);
		sombra.setSize(sf::Vector2f(w, h));
		sombra.setFillColor(sf::Color(0, 0, 0, 70));
		rect.setPosition(x, y);
		rect.setSize(sf::Vector2f(w, h));
		rect.setFillColor(fill);
		rect.setOutlineThickness(1.5f);
		rect.setOutlineColor(sf::Color(255, 255, 255, 28));
		label.setFont(font);
		label.setString(texto);
		label.setCharacterSize(esPrimario ? 20 : 18);
		label.setFillColor(COL_TEXT);
		label.setStyle(esPrimario ? sf::Text::Bold : sf::Text::Regular);
		centrarLabel();
	}

	// Centra el texto del botón dentro del rectángulo.
	void centrarLabel()
	{
		sf::FloatRect bounds = label.getLocalBounds();
		sf::Vector2f pos = rect.getPosition();
		sf::Vector2f size = rect.getSize();
		label.setPosition(
			pos.x + (size.x - bounds.width) / 2.f - bounds.left,
			pos.y + (size.y - bounds.height) / 2.f - bounds.top - 1.f);
	}

	// Devuelve true si el punto (mx, my) está dentro del botón (clic / hover).
	bool contiene(float mx, float my) const
	{
		return rect.getGlobalBounds().contains(mx, my);
	}

	// Cambia el color del botón cuando el mouse está encima.
	void actualizarHover(float mx, float my)
	{
		rect.setFillColor(contiene(mx, my) ? fillHover : fill);
	}

	// Dibuja la sombra, el rectángulo y la etiqueta del botón.
	void dibujar(sf::RenderWindow& w) const
	{
		w.draw(sombra);
		w.draw(rect);
		w.draw(label);
	}

	// Cambia el texto mostrado y lo vuelve a centrar.
	void setTexto(const std::string& t)
	{
		label.setString(t);
		centrarLabel();
	}
};

/** Carga una textura desde disco; false si falla. */
bool loadTexture(sf::Texture& tex, const std::string& path)
{
	if (!tex.loadFromFile(path)) {
		std::cerr << "No se pudo cargar: " << path << '\n';
		return false;
	}
	return true;
}

/** Barra inferior de la UI con franja estilo bandera de Venezuela. */
void dibujarPanel(sf::RenderWindow& w, float x, float y, float ancho, float alto)
{
	sf::RectangleShape panel(sf::Vector2f(ancho, alto));
	panel.setPosition(x, y);
	panel.setFillColor(COL_PANEL);
	panel.setOutlineThickness(1.f);
	panel.setOutlineColor(COL_AMARILLO);
	w.draw(panel);

	const float h = 4.f;
	sf::RectangleShape amarillo(sf::Vector2f(ancho / 3.f, h));
	amarillo.setPosition(x, y);
	amarillo.setFillColor(COL_AMARILLO);
	sf::RectangleShape azul(sf::Vector2f(ancho / 3.f, h));
	azul.setPosition(x + ancho / 3.f, y);
	azul.setFillColor(sf::Color(80, 120, 220));
	sf::RectangleShape rojo(sf::Vector2f(ancho - 2.f * (ancho / 3.f), h));
	rojo.setPosition(x + 2.f * (ancho / 3.f), y);
	rojo.setFillColor(COL_ROJO);
	w.draw(amarillo);
	w.draw(azul);
	w.draw(rojo);
}

/** Overlay final: nacimientos, muertes naturales y comidos por el zorro. */
void dibujarEstadisticas(sf::RenderWindow& w, const sf::Font& font,
	float vistaX, float vistaY, float vistaW, float vistaH,
	const Estadisticas& s)
{
	sf::RectangleShape dim(sf::Vector2f(vistaW, vistaH));
	dim.setPosition(vistaX, vistaY);
	dim.setFillColor(sf::Color(5, 10, 30, 200));
	w.draw(dim);

	float cardW = 520.f;
	float cardH = 360.f;
	float cx = vistaX + (vistaW - cardW) / 2.f;
	float cy = vistaY + (vistaH - cardH) / 2.f;

	sf::RectangleShape card(sf::Vector2f(cardW, cardH));
	card.setPosition(cx, cy);
	card.setFillColor(sf::Color(0, 28, 95));
	card.setOutlineThickness(3.f);
	card.setOutlineColor(COL_AMARILLO);
	w.draw(card);

	sf::RectangleShape top(sf::Vector2f(cardW, 8.f));
	top.setPosition(cx, cy);
	top.setFillColor(COL_AMARILLO);
	w.draw(top);

	sf::Text titulo;
	titulo.setFont(font);
	titulo.setString("Estadisticas finales");
	titulo.setCharacterSize(28);
	titulo.setStyle(sf::Text::Bold);
	titulo.setFillColor(COL_AMARILLO);
	titulo.setPosition(cx + 28.f, cy + 28.f);
	w.draw(titulo);

	auto linea = [&](float y, const std::string& etq, int valor, sf::Color col) {
		sf::Text t;
		t.setFont(font);
		t.setCharacterSize(20);
		t.setFillColor(COL_MUTED);
		t.setString(etq);
		t.setPosition(cx + 40.f, y);
		w.draw(t);

		sf::Text v;
		v.setFont(font);
		v.setCharacterSize(22);
		v.setStyle(sf::Text::Bold);
		v.setFillColor(col);
		v.setString(std::to_string(valor));
		v.setPosition(cx + cardW - 100.f, y);
		w.draw(v);
	};

	linea(cy + 90.f,  "Poblacion inicial", s.poblacionInicial, COL_TEXT);
	linea(cy + 130.f, "Nacimientos (reproduccion)", s.nacimientos, sf::Color(120, 220, 160));
	linea(cy + 170.f, "Muertes naturales", s.muertosNatural, sf::Color(255, 200, 90));
	linea(cy + 210.f, "Comidos por el zorro", s.comidosPorZorro, COL_ROJO);
	linea(cy + 250.f, "Poblacion final", s.poblacionFinal, COL_AMARILLO);

	sf::Text hint;
	hint.setFont(font);
	hint.setString("Pulsa Salir o ESC para cerrar");
	hint.setCharacterSize(14);
	hint.setFillColor(COL_MUTED);
	hint.setPosition(cx + 40.f, cy + cardH - 45.f);
	w.draw(hint);
}

} // namespace

/**
 * Punto de entrada: carga recursos, muestra UI, corre la simulación
 * y presenta estadísticas al finalizar.
 */
int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	const unsigned W = 1400;
	const unsigned H = 900;
	const float MARGIN = 24.f;
	const float TOP_H = 64.f;
	const float BOTTOM_H = 110.f;
	const float VISTA_X = MARGIN;
	const float VISTA_Y = TOP_H + 12.f;
	const float VISTA_W = static_cast<float>(W) - 2.f * MARGIN;
	const float VISTA_H = static_cast<float>(H) - VISTA_Y - BOTTOM_H - MARGIN;

	sf::RenderWindow window(sf::VideoMode(W, H), "Simulacion Predador - Presa");
	window.setFramerateLimit(30);

	sf::Font font;
	const char* fonts[] = {
		"/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
		"/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf"
	};
	bool fontOk = false;
	for (const char* path : fonts) {
		if (font.loadFromFile(path)) {
			fontOk = true;
			break;
		}
	}
	if (!fontOk) {
		std::cerr << "No se pudo cargar una fuente del sistema\n";
		return 1;
	}

	sf::Texture texCesped, texPreview, texHembra, texMacho, texEnfermo, texZorro;
	const char* candidatesCesped[] = {"Cesped.png", "../Cesped.png", "Pista.png", "../Pista.png"};
	const char* candidatesPreview[] = {"FONDO1.png", "../FONDO1.png", "Pista.png", "../Pista.png"};
	const char* candidatesHembra[] = {"Fig_Conejo.png", "../Fig_Conejo.png"};
	const char* candidatesMacho[] = {"Fig_Conejo_Macho.png", "../Fig_Conejo_Macho.png"};
	const char* candidatesEnfermo[] = {"Fig_Conejo_Enfermo.png", "../Fig_Conejo_Enfermo.png"};
	const char* candidatesZorro[] = {"Fig_Zorro.png", "../Fig_Zorro.png"};

	auto tryLoad = [](sf::Texture& t, const char* const* paths, int n) {
		for (int i = 0; i < n; ++i)
			if (loadTexture(t, paths[i])) return true;
		return false;
	};

	if (!tryLoad(texCesped, candidatesCesped, 4) ||
		!tryLoad(texPreview, candidatesPreview, 4) ||
		!tryLoad(texHembra, candidatesHembra, 2) ||
		!tryLoad(texMacho, candidatesMacho, 2) ||
		!tryLoad(texEnfermo, candidatesEnfermo, 2) ||
		!tryLoad(texZorro, candidatesZorro, 2)) {
		std::cerr << "Faltan imagenes. Ejecuta desde la raiz del proyecto.\n";
		return 1;
	}
	texCesped.setSmooth(true);
	texPreview.setSmooth(true);
	texHembra.setSmooth(true);
	texMacho.setSmooth(true);
	texEnfermo.setSmooth(true);
	texZorro.setSmooth(true);

	auto dibujarFranjaBandera = [&](sf::RenderWindow& w, float y, float alto) {
		const float ancho = static_cast<float>(W);
		const float h = alto / 3.f;
		sf::RectangleShape amarillo(sf::Vector2f(ancho, h));
		amarillo.setPosition(0.f, y);
		amarillo.setFillColor(COL_AMARILLO);
		sf::RectangleShape azul(sf::Vector2f(ancho, h));
		azul.setPosition(0.f, y + h);
		azul.setFillColor(COL_AZUL);
		sf::RectangleShape rojo(sf::Vector2f(ancho, h));
		rojo.setPosition(0.f, y + 2.f * h);
		rojo.setFillColor(COL_ROJO);
		w.draw(amarillo);
		w.draw(azul);
		w.draw(rojo);
	};

	int numC = 15;
	bool iniciado = false;
	bool mostrandoStats = false;
	Juego* juego = nullptr;

	const float btnY = static_cast<float>(H) - BOTTOM_H + 34.f;
	Boton btnMenos(font, "−", 40.f, btnY, 52.f, 48.f, COL_CHIP);
	Boton btnConejos(font, "15", 102.f, btnY, 72.f, 48.f, sf::Color(55, 70, 90));
	Boton btnMas(font, "+", 184.f, btnY, 52.f, 48.f, COL_CHIP);
	Boton btnInicio(font, "Iniciar", 280.f, btnY, 150.f, 48.f, COL_AMARILLO, true);
	btnInicio.label.setFillColor(sf::Color(20, 30, 60));
	btnInicio.centrarLabel();
	Boton btnFinalizar(font, "Finalizar", 460.f, btnY, 150.f, 48.f, sf::Color(0, 70, 160));
	Boton btnFin(font, "Salir", static_cast<float>(W) - 170.f, btnY, 130.f, 48.f, COL_ROJO);

	sf::Text brand;
	brand.setFont(font);
	brand.setString("Predador - Presa");
	brand.setCharacterSize(26);
	brand.setStyle(sf::Text::Bold);
	brand.setFillColor(COL_TEXT);
	brand.setPosition(MARGIN, 18.f);

	sf::Text subtitle;
	subtitle.setFont(font);
	subtitle.setString("Madrigueras · colores · zorro cazador");
	subtitle.setCharacterSize(14);
	subtitle.setFillColor(COL_MUTED);
	subtitle.setPosition(MARGIN + 280.f, 28.f);

	sf::Text chipPoblacion;
	chipPoblacion.setFont(font);
	chipPoblacion.setCharacterSize(16);
	chipPoblacion.setFillColor(COL_ACCENT);
	chipPoblacion.setStyle(sf::Text::Bold);

	sf::Text labelPoblacion;
	labelPoblacion.setFont(font);
	labelPoblacion.setString("Poblacion inicial");
	labelPoblacion.setCharacterSize(13);
	labelPoblacion.setFillColor(COL_MUTED);
	labelPoblacion.setPosition(40.f, btnY - 22.f);

	sf::Text ayuda;
	ayuda.setFont(font);
	ayuda.setString("Ajusta conejos e Iniciar. El zorro cazara; al Finalizar veras estadisticas.");
	ayuda.setCharacterSize(14);
	ayuda.setFillColor(COL_MUTED);
	ayuda.setPosition(460.f, btnY + 14.f);

	sf::Text overlayMsg;
	overlayMsg.setFont(font);
	overlayMsg.setString("Configura la poblacion e inicia la simulacion");
	overlayMsg.setCharacterSize(28);
	overlayMsg.setStyle(sf::Text::Bold);
	overlayMsg.setFillColor(COL_TEXT);
	{
		sf::FloatRect b = overlayMsg.getLocalBounds();
		overlayMsg.setPosition(
			VISTA_X + (VISTA_W - b.width) / 2.f - b.left,
			VISTA_Y + VISTA_H / 2.f - 20.f);
	}

	auto actualizarChip = [&](int n) {
		chipPoblacion.setString("Habitantes  " + std::to_string(n));
		sf::FloatRect b = chipPoblacion.getLocalBounds();
		chipPoblacion.setPosition(static_cast<float>(W) - MARGIN - b.width - b.left, 24.f);
	};
	actualizarChip(numC);

	while (window.isOpen()) {
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		float mx = static_cast<float>(mouse.x);
		float my = static_cast<float>(mouse.y);

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed &&
				event.mouseButton.button == sf::Mouse::Left) {
				float cx = static_cast<float>(event.mouseButton.x);
				float cy = static_cast<float>(event.mouseButton.y);

				if (!iniciado && !mostrandoStats && btnMenos.contiene(cx, cy) && numC > 1) {
					numC--;
					btnConejos.setTexto(std::to_string(numC));
					actualizarChip(numC);
				}
				if (!iniciado && !mostrandoStats && btnMas.contiene(cx, cy) && numC < 200) {
					numC++;
					btnConejos.setTexto(std::to_string(numC));
					actualizarChip(numC);
				}
				if (!iniciado && !mostrandoStats && btnInicio.contiene(cx, cy)) {
					delete juego;
					juego = new Juego(texCesped, texHembra, texZorro, numC, 100,
						VISTA_X, VISTA_Y, VISTA_W, VISTA_H);
					iniciado = true;
					mostrandoStats = false;
				}
				if (iniciado && juego && !mostrandoStats && btnFinalizar.contiene(cx, cy)) {
					juego->finalizar();
					mostrandoStats = true;
				}
				if (btnFin.contiene(cx, cy))
					window.close();
			}
		}

		if (!iniciado && !mostrandoStats) {
			btnMenos.actualizarHover(mx, my);
			btnMas.actualizarHover(mx, my);
			btnInicio.actualizarHover(mx, my);
		}
		if (iniciado && !mostrandoStats)
			btnFinalizar.actualizarHover(mx, my);
		btnFin.actualizarHover(mx, my);

		if (iniciado && juego && !juego->estaTerminado()) {
			juego->mover(texHembra);
			actualizarChip(juego->getNC());
			if (juego->estaTerminado())
				mostrandoStats = true;
		}

		window.clear(COL_BG);

		dibujarFranjaBandera(window, 0.f, TOP_H);
		sf::RectangleShape headerShade(sf::Vector2f(static_cast<float>(W), TOP_H));
		headerShade.setFillColor(sf::Color(0, 0, 0, 90));
		window.draw(headerShade);
		window.draw(brand);
		window.draw(subtitle);
		window.draw(chipPoblacion);

		sf::RectangleShape marco(sf::Vector2f(VISTA_W + 4.f, VISTA_H + 4.f));
		marco.setPosition(VISTA_X - 2.f, VISTA_Y - 2.f);
		marco.setFillColor(sf::Color(10, 14, 20));
		marco.setOutlineThickness(1.f);
		marco.setOutlineColor(COL_PANEL_EDGE);
		window.draw(marco);

		if (iniciado && juego) {
			juego->dibujar(window, texCesped, texHembra, texMacho, texEnfermo, texZorro);
			if (mostrandoStats || juego->estaTerminado())
				dibujarEstadisticas(window, font, VISTA_X, VISTA_Y, VISTA_W, VISTA_H, juego->getStats());
		} else {
			sf::Sprite preview;
			preview.setTexture(texPreview);
			preview.setPosition(VISTA_X, VISTA_Y);
			preview.setScale(
				VISTA_W / static_cast<float>(texPreview.getSize().x),
				VISTA_H / static_cast<float>(texPreview.getSize().y));
			window.draw(preview);

			sf::RectangleShape dim(sf::Vector2f(VISTA_W, VISTA_H));
			dim.setPosition(VISTA_X, VISTA_Y);
			dim.setFillColor(sf::Color(8, 12, 18, 140));
			window.draw(dim);
			window.draw(overlayMsg);
		}

		dibujarPanel(window, 0.f, static_cast<float>(H) - BOTTOM_H,
			static_cast<float>(W), BOTTOM_H);

		if (!iniciado && !mostrandoStats) {
			window.draw(labelPoblacion);
			btnMenos.dibujar(window);
			btnConejos.dibujar(window);
			btnMas.dibujar(window);
			btnInicio.dibujar(window);
			window.draw(ayuda);
		} else if (iniciado && !mostrandoStats) {
			sf::Text running;
			running.setFont(font);
			running.setString("En curso: madrigueras + zorro cazando");
			running.setCharacterSize(16);
			running.setFillColor(COL_ACCENT);
			running.setPosition(40.f, btnY + 12.f);
			window.draw(running);
			btnFinalizar.dibujar(window);
		} else if (mostrandoStats) {
			sf::Text done;
			done.setFont(font);
			done.setString("Simulacion finalizada");
			done.setCharacterSize(18);
			done.setFillColor(COL_AMARILLO);
			done.setPosition(40.f, btnY + 12.f);
			window.draw(done);
		}
		btnFin.dibujar(window);

		window.display();
	}

	delete juego;
	return 0;
}
