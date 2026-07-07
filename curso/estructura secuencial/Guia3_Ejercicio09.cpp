#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 9 (Problema 5)
 * Calcular el perímetro de un cuadrado.
 * Fórmula: P = 4 * lado
 */

double perimetroCuadrado(double lado);

double perimetroCuadrado(double lado)
{
	return 4 * lado;
}

int main()
{
	double lado;

	cout << "Introduzca el lado del cuadrado: ";
	cin >> lado;

	cout << "Perimetro = " << perimetroCuadrado(lado) << endl;

	return 0;
}
