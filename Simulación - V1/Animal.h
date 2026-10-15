#pragma once
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "Fondo.h"
using namespace std;
enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno };


public class Animal
{
protected:
	int edad;
	int indiceX; //indice del sprite
	int indiceY; //indice de las figuras del sprite
	float x; //posicion del personaje dentro del canvas
	float y; //posicion del personaje dentro del canvas
	float xFu;
	float yFu;
	float ancho; //ancho del personaje
	float alto; //altura del personaje
	float dx; //para el desplazamiento de x
	float dy; //para el desplazamiento de y
	int prueba;
	int limx;
	int limy;
	char direccion; //direccion del personaje N, S , E, O

public:
	Animal();
	Animal(int x, int y, System::Drawing::Bitmap^ Fig_humano);
	~Animal();

	void setX(float x);
	float getX();
	void setY(float y);
	float getY();
	float getAncho();
	float getAlto();
	float getDX();
	float getDY();
	float getXFu();
	float getYFu();
	float getXpi()
	{
		return x + ancho / 2;
	}
	float getYpi()
	{
		return y + alto / 2;
	}
	int getEdad();
	void dibujar(System::Drawing::BufferedGraphics^ g, System::Drawing::Bitmap^ Fig_humano);
};

