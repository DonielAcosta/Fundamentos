#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 10 (Problema 6)
 * Calcular el área de un cuadrado dada la longitud de uno de sus lados.
 * Fórmula: A = lado * lado
 */

double areaCuadrado(double lado);

double areaCuadrado(double lado)
{
	return lado * lado;
}

int main()
{
	double lado;

	cout << "Introduzca el lado del cuadrado: ";
	cin >> lado;

	cout << "Area = " << areaCuadrado(lado) << endl;

	return 0;
}
