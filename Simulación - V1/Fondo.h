#pragma once

class Fondo
{
public:

protected:

	int indiceX; //indice del sprite
	int indiceY; //indice de las figuras del sprite
	int x; //posicion del personaje dentro del canvas
	int y; //posicion del personaje dentro del canvas
	int ancho; //ancho del personaje
	int alto; //altura del personaje
	int dx; //para el desplazamiento de x
	int dy; //para el desplazamiento de y
public:
	Fondo();
	Fondo(int x, int y, System::Drawing::Bitmap^ Fig_humano);
	~Fondo();
	void setX(int x);
	int getX();
	void setY(int y);
	void setdx(int y);
	void setdy(int y);
	int getY();
	int getAncho();
	int getAlto();
	int getDX();
	int getDY();
	void dibujar(System::Drawing::BufferedGraphics^ g, System::Drawing::Bitmap^ Fig_humano);
};