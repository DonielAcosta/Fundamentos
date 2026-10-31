#pragma once
#include "Conejo.h"

class Juego
{
private:
	Fondo* fondo;
	Conejo** conejo;//un conejo
	int tiempo;
	int NC;
	bool casoCero;

public:
	Juego(System::Drawing::Bitmap^ Fondo_Espacio,
		System::Drawing::Bitmap^ Fig_Conejo,
		int Num_C,
		int P)
	{
		casoCero = false;
		NC = Num_C;
		int x;
		int y;
		fondo = new Fondo(20, 20, Fondo_Espacio);
		conejo = new Conejo * [1000];
		for (int i = 0; i < 1000; i++)
			conejo[i] = nullptr;

		for (int i = 0; i < NC; i++)
		{
			setConejo(Fig_Conejo);
		}
		tiempo = P;

	}

	int getNC()
	{
		return NC;
	}

	bool hayChoque(float x, float y)
	{
		for (int i = 0; i < NC; i++)
			if (conejo[i] != nullptr)
				if (dist(x, y, conejo[i]->getX(), conejo[i]->getY()) < (conejo[i]->getAncho()))
					return true;
		return false;
	}


	void setConejo(System::Drawing::Bitmap^ Fig_Conejo)
	{
		float x, y;
		do
		{
			x = rand() % (fondo->getAncho() - 200) + 100;
			y = rand() % (fondo->getAlto() - 200) + 100;
		} while (hayChoque(x, y));

		for (int i = 0; i < NC; i++)
			if (conejo[i] == nullptr)
			{
				conejo[i] = new Conejo(x, y, Fig_Conejo, fondo->getAncho(), fondo->getAlto());
				return;
			}
	}

	void setConejo(System::Drawing::Bitmap^ Fig_Conejo, float px, float py)
	{
		float x = px, y = py;
		int cont = 0;
		/*do
		{
			cont++;
			x = rand() % 150 + px - 75;
			y = rand() % 150 + py - 75;
			if (cont > 150)
				break;
		} while (hayChoque(x, y) || x < 60 || y < 60 || x > fondo->getAncho() - 60 || y > fondo->getAlto() - 60);
		*/if (cont < 150)
	for (int i = 0; i < 1000; i++)
		if (conejo[i] == nullptr)
		{
			conejo[i] = new Conejo(x, y, Fig_Conejo, fondo->getAncho(), fondo->getAlto());
			NC++;
			return;
		}
	}

	void setTiempo(int a)
	{
		this->tiempo = a;
	}

	bool esPosible(float x, float y, float a)
	{
		if (x >= a && x < fondo->getAncho() - a && y >= a && y < fondo->getAlto() - a)
			return true;
		else
			return false;
	}

	void controldeMortalidad()
	{
		for (int i = 0; i < 1000; i++)
		{
			if (conejo[i] != nullptr)
			{
				if (rand() % 1000 < 40)
				{
					conejo[i]->cambiarFertilidad();
				}

				if (conejo[i]->getEdad() > 200)
				{
					delete conejo[i];
					conejo[i] = nullptr;
					NC--;
					return;
				}

				if (conejo[i]->getEnfermo() && rand() % 1000 < 100)
				{
					delete conejo[i];
					conejo[i] = nullptr;
					NC--;
				}
			}
		}
	}

	void reproducir(System::Drawing::Bitmap^ Fig_Conejo)
	{
		controldeMortalidad();
		for (int i = 0; i < 1000; i++)
		{
			if (conejo[i] != nullptr)
			{
				for (int j = 0; j < 1000; j++)
				{
					if (conejo[j] != nullptr && i != j)
					{
						if ((conejo[i]->getSexo() != conejo[j]->getSexo()) && (conejo[i]->getEdad() > 18 && conejo[j]->getEdad() > 18))
						{
							if (dist(conejo[i]->getX(), conejo[i]->getY(), conejo[j]->getX(), conejo[j]->getY()) < 60)
							{
								if (rand() % 100 < 2)
									if (conejo[i]->getFertilidad() && conejo[j]->getFertilidad())
										if (conejo[i]->getEnfermo() == false && conejo[j]->getEnfermo() == false)
											if(conejo[i]->getEdad() > 18 && conejo[j]->getEdad() > 18 && conejo[i]->getEdad()< 150 && conejo[j]->getEdad() < 150)
											this->setConejo(Fig_Conejo, (conejo[i]->getX() + conejo[j]->getX()) / 2, (conejo[i]->getY() + conejo[j]->getY()) / 2);
								//revisar porque se reproducen a lo loco con m[as de una pareja por iteración

							}
						}
					}
				}
			}
		}








	}

	void enfermar()
	{
		int pos;
		if (casoCero)
			return;
		do
		{
			pos = rand() % 1000;
			if (conejo[pos] != nullptr)
			{
				conejo[pos]->enfermar();
				casoCero = true;
			}

		} while (casoCero == false);
	}



	void propagar()
	{
		for (int i = 0; i < 1000; i++)
		{
			if (conejo[i] != nullptr)
			{
				for (int j = 0; j < 1000; j++)
				{
					if (conejo[j] != nullptr && i != j)
					{
						if (dist(conejo[i]->getX(), conejo[i]->getY(), conejo[j]->getX(), conejo[j]->getY()) < 60)
						{
							if (conejo[j]->getEnfermo())
							{
								if (rand() % 1000 < 150)
									conejo[i]->enfermar();
							}
						}
					}
				}
			}
		}
	}

	void verificarCadoCero()
	{
		int contador = 0;
		for (int i = 0; i < 1000; i++)
		{
			if (conejo[i] != nullptr)
			{
				if (conejo[i]->getEnfermo())
				{
					contador++;
				}
			}
		}
		if (contador == 0)
		{
			casoCero = false;
		}
	}

	void mover(Direccion teclaPulsada, System::Drawing::Bitmap^ Fig_Conejo)
	{	
		verificarCadoCero();
		reproducir(Fig_Conejo);
		if (NC > 200)
			enfermar();

		if (casoCero)
			propagar();

		for (int i = 0; i < 1000; i++)
		{
			if (conejo[i] != nullptr)
			{
				conejo[i]->decidir();
				if (esPosible(
								conejo[i]->getXFu() + conejo[i]->getAncho() / 2,
								conejo[i]->getYFu() + conejo[i]->getAlto() / 2,
								conejo[i]->getAncho()
								)
					)
				{
					conejo[i]->mover();
				}
			}
		}
	
	}

	void pararjuego()
	{
	}


	void dibujar(System::Drawing::BufferedGraphics^ g, 
		System::Drawing::Bitmap^ figura_fondo, 
		System::Drawing::Bitmap^ Fig_Conejo,
		System::Drawing::Bitmap^ Fig_Conejo_Macho,
		System::Drawing::Bitmap^ Fig_Conejo_Enfermo)
	{
		fondo->dibujar(g, figura_fondo);
		for (int i = 0; i < 1000; i++)
		{
			if (conejo[i] != nullptr)
			{
				conejo[i]->dibujar(g, Fig_Conejo, Fig_Conejo_Macho, Fig_Conejo_Enfermo);
			}
		}
	}

	//distancia Euclidiana entre dos puntos en el plano
	double dist(int posx, int posy, int posxx, int posyy)
	{
		return sqrt(pow(posx-posxx,2)+ pow(posy - posyy, 2));
	}
};

