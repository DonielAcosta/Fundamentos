#include "Fondo.h"

Fondo::Fondo()
{
	x = y = 100;
	dx = 0;
	dy = 1;//avance hacia abajo
	indiceX = indiceY = 0;
}
Fondo::Fondo(int x, int y, System::Drawing::Bitmap^ Fig_sprite)
{
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;//avance hacia abajo
	indiceX = indiceY = 0;
	ancho = Fig_sprite->Width;
	alto = Fig_sprite->Height;
}

Fondo::~Fondo() {}
void Fondo::setX(int x) { this->x = x; }
int Fondo::getX() { return this->x; }
void Fondo::setY(int y) { this->y = y; }

void Fondo::setdx(int y)
{
	this->dx = y;
}


void Fondo::setdy(int y)
{
	this->dy = y;
}
int Fondo::getY() { return this->y; }
int Fondo::getAncho() { return this->ancho; }
int Fondo::getAlto() { return this->alto; }
int Fondo::getDX() { return this->dx; }
int Fondo::getDY() { return this->dy; }

void Fondo::dibujar(System::Drawing::BufferedGraphics^ g, System::Drawing::Bitmap^ Fig_humano)
{
	System::Drawing::Rectangle recorte = System::Drawing::Rectangle(ancho * indiceX, alto * indiceY, ancho, alto);
	System::Drawing::Rectangle contenedor = System::Drawing::Rectangle(x, y, ancho, alto);

	g->Graphics->DrawImage(Fig_humano, contenedor, recorte, System::Drawing::GraphicsUnit::Pixel);
}