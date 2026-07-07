#include<iostream>
#include<cmath>
using namespace std;

/*
 * Guía 3 - Ejercicio 8 (Problema 4)
 * Calcular el área de un círculo dados el centro C y un punto sobre la circunferencia.
 * El radio es la distancia entre ambos puntos.
 */

const double PI = 3.14159265359;

double distancia(double x1, double y1, double x2, double y2);
double areaCirculoPorPuntos(double cx, double cy, double px, double py);

double distancia(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double areaCirculoPorPuntos(double cx, double cy, double px, double py)
{
	double radio = distancia(cx, cy, px, py);
	return PI * radio * radio;
}

int main()
{
	double cx, cy, px, py;

	cout << "Centro del circulo (x y): ";
	cin >> cx >> cy;
	cout << "Punto sobre la circunferencia (x y): ";
	cin >> px >> py;

	cout << "Area del circulo = " << areaCirculoPorPuntos(cx, cy, px, py) << endl;

	return 0;
}
