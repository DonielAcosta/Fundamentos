#include<iostream>
#include<cmath>
using namespace std;

/*
 * Guía 3 - Ejercicio 7 (Problema 3)
 * Calcular el área de un círculo dado su radio.
 * Fórmula: A = pi * r^2
 */

const double PI = 3.14159265359;

double areaCirculo(double radio);

double areaCirculo(double radio)
{
	return PI * radio * radio;
}

int main()
{
	double radio;

	cout << "Introduzca el radio: ";
	cin >> radio;

	cout << "Area del circulo = " << areaCirculo(radio) << endl;

	return 0;
}
