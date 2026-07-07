#include<iostream>
using namespace std;

/*
 * Ejercicio 13 - Área de una habitación.
 *
 * Solicite al usuario la longitud y la anchura de una habitación y visualice
 * en pantalla su área.
 * Fórmula: area = longitud * anchura
 */

int main()
{
	float longitud, anchura, area;

	cout << "Introduzca la longitud: ";
	cin >> longitud;
	cout << "Introduzca la anchura: ";
	cin >> anchura;

	area = longitud * anchura;

	cout << "Area de la habitacion = " << area << endl;

	return 0;
}
