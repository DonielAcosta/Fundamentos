#include "Conejo.h"

Conejo::Conejo(): Animal()
{
}
Conejo::Conejo(int x, int y, System::Drawing::Bitmap^ Fig_humano, int ancho, int largo): Animal( x, y, Fig_humano)
{	this->limx = ancho;
	this->limy = largo;
	dx = 10;
	dy = 10;
	contador = 0;
	limiteContador = rand()%20+1;
	
}
Conejo::~Conejo() {}


void Conejo::mover()
{
	if (hambre >= 0)
	{
		x = xFu;
		y = yFu;

	}
}
void Conejo::mover2(Direccion tecla)
{
	int auxx = 0;
	
	int aux = rand() % 100;
	if (aux < 10)
	{
		aux = rand() % 100;

		if (aux > 75)
		{
			this->dx = 5;
			this->dy = 0;
			this->indiceY = 2;
		}
		else
		{
			if (aux > 55)
			{
				this->dx = -5;
				this->dy = 0;
				this->indiceY = 1;
			}
			else
			{
				if (aux > 25)
				{
					this->dx = 0;
					this->dy = 5;
					this->indiceY = 0;
				}
				else
				{
					this->dx = 0;
					this->dy = -5;
					this->indiceY = 3;
				}
			}
		}
	}

	//las columnas
	indiceX++;
	if (indiceX > 3)//indice de la figura es {0,1,2,3}
		indiceX = 0;
	//actualizar la posicion de la figura en el canvas

	x += dx;
	y += dy;
	//esta parte controla los limites del escenario
	if (this->x > 500)
	{
		this->x = this->x - this->dx;//lo regresa al paso anterior
	}
	if (this->x <= 20)
	{
		this->x = this->x - this->dx;//un paso hacia abajo
	}
	if (this->y > 300)
	{
		this->y = this->y - this->dy;
	}
	if (this->y <= 0)
	{
		this->y = this->y - this->dy;
	}

}

char Conejo::decidirDireccion()
	{
		switch (rand() % 4)
		{
			case 0:
				return 'N';
			case 1:
				return 'S';
			case 2:
				return 'E';
			case 3:
				return 'O';
		}
	}

void Conejo::enfermar()
{
	enfermo = !enfermo;
}


void Conejo::decidir()
{


	contador++;
	hambre--;

	indiceX = (indiceX + 1) % 4;
	cout << contador << endl;
	if (contador > limiteContador)
	{
		direccion = decidirDireccion();
		contador = 0;
		limiteContador = rand() % 20 + 1;
		cout << "DECIDO "<< endl;
	}
		


	switch (direccion)
	{
	case 'N':
		indiceY = 3;
		yFu = y - dy;
		break;
	case 'S':
		indiceY = 0;
		yFu = y + dy;
		break;
	case 'E':
		indiceY = 2;
		xFu = x + dx;
		break;
	case 'O':
		indiceY = 1;
		xFu = x - dx;
		break;
	}

}