#pragma once
#ifndef __HABITANTE_HPP__
#define __HABITANTE_HPP__

#include "Animal.h"

//enum Direccion {Arriba,Abajo,Izquierda,Derecha,Ninguno};
class Conejo: public Animal
{	
	
	int contador;
	int limiteContador;
	
public:
	Conejo();
	Conejo(int x, int y, System::Drawing::Bitmap^ Fig_humano,int lx, int ly);
	~Conejo();
	void mover();
	void mover2(Direccion tecla);
	void decidir();
	void enfermar();

	private:
	

	char decidirDireccion();
};
#endif
