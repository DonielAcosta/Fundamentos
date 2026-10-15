#pragma once
#include "Animal.h"

Animal::Animal()
{
	x = y = 100;
	dx = 0;
	dy = 1;//avance hacia abajo
	indiceX = indiceY = 0;
}


Animal::Animal(int x, int y, System::Drawing::Bitmap^ Fig_humano)
{
	edad = 0;
	this->prueba = 4;
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;//avance hacia abajo
	indiceX = indiceY = 0;
	ancho = Fig_humano->Width / 4;
	alto = Fig_humano->Height / 4;
}

Animal::~Animal() {}
void Animal::setX(float x) { this->x = x; }
float Animal::getX() { return this->x; }
void Animal::setY(float y) { this->y = y; }
float Animal::getY() { return this->y; }
float Animal::getAncho() { return this->ancho; }
float Animal::getAlto() { return this->alto; }
float Animal::getDX() { return this->dx; }
float Animal::getDY() { return this->dy; }
float Animal::getXFu() { return this->xFu; }
float Animal::getYFu() { return this->yFu; }

int Animal::getEdad() { return this->edad; }

void Animal::dibujar(System::Drawing::BufferedGraphics^ g, System::Drawing::Bitmap^ Fig_humano)
{
	edad++;
	System::Drawing::Rectangle recorte = System::Drawing::Rectangle(indiceX*ancho,indiceY*alto, ancho, alto);
	System::Drawing::Rectangle contenedor = System::Drawing::Rectangle(x, y, 60, 60);

	g->Graphics->DrawImage(Fig_humano, contenedor, recorte, System::Drawing::GraphicsUnit::Pixel);
}
