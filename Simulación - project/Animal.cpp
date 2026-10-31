#pragma once
#include "Animal.h"

Animal::Animal()
{
	enfermo = false;
	hambre = 15;
	x = y = 100;
	dx = 0;
	dy = 1;//avance hacia abajo
	indiceX = indiceY = 0;
	sexo = rand() % 2;
}


Animal::Animal(int x, int y, System::Drawing::Bitmap^ Fig_humano)
{
	enfermo = false;
	hambre = 15;
	edad = 0;
	this->prueba = 4;
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;//avance hacia abajo
	indiceX = indiceY = 0;
	ancho = Fig_humano->Width / 4;
	alto = Fig_humano->Height / 4;
	sexo = rand() % 2;
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

void Animal::dibujar(	System::Drawing::BufferedGraphics^ g, 
						System::Drawing::Bitmap^ Fig_Conejo_Hembra,
						System::Drawing::Bitmap^ Fig_Conejo_Macho,
						System::Drawing::Bitmap^ Fig_Conejo_Enfermo)
{
	fertilidad = true;
	
	edad++;
	System::Drawing::Rectangle recorte;
	System::Drawing::Rectangle contenedor;
	if (hambre < -10)
	{
		hambre = rand()%20 + 15;
	}


	if (hambre > 0)
	{
		recorte = System::Drawing::Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		contenedor = System::Drawing::Rectangle(x, y, 60, 60);
	}
	else
	{
		recorte = System::Drawing::Rectangle(0, 0, ancho, alto);
		contenedor = System::Drawing::Rectangle(x, y, 60, 60);
	}


	if (!enfermo)
	{
			if (sexo)
			{
				g->Graphics->DrawImage(Fig_Conejo_Macho, contenedor, recorte, System::Drawing::GraphicsUnit::Pixel);
			}
			else
			{
				g->Graphics->DrawImage(Fig_Conejo_Hembra, contenedor, recorte, System::Drawing::GraphicsUnit::Pixel);
			}
	}
	else
	{
		g->Graphics->DrawImage(Fig_Conejo_Enfermo, contenedor, recorte, System::Drawing::GraphicsUnit::Pixel);
	}
	
}
