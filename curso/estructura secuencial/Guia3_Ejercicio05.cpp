#include<iostream>
#include<cmath>
using namespace std;

/*
 * Guía 3 - Ejercicio 5 (Problema 1)
 * Calcular la distancia entre dos puntos en el plano y en el espacio.
 *
 * Plano:  d = sqrt((x2-x1)^2 + (y2-y1)^2)
 * Espacio: d = sqrt((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2)
 */

double distanciaPlano(double x1, double y1, double x2, double y2);
double distanciaEspacio(double x1, double y1, double z1, double x2, double y2, double z2);

double distanciaPlano(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double distanciaEspacio(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

int main()
{
	double x1, y1, x2, y2, z1, z2;

	cout << "Punto 1 en el plano (x y): ";
	cin >> x1 >> y1;
	cout << "Punto 2 en el plano (x y): ";
	cin >> x2 >> y2;

	cout << "Distancia en el plano = " << distanciaPlano(x1, y1, x2, y2) << endl;

	cout << "\nCoordenada z del punto 1: ";
	cin >> z1;
	cout << "Coordenada z del punto 2: ";
	cin >> z2;

	cout << "Distancia en el espacio = "
		 << distanciaEspacio(x1, y1, z1, x2, y2, z2) << endl;

	return 0;
}
