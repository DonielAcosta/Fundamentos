#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 6 (Problema 2)
 * Recibir tres números reales y devolver su promedio.
 */

float promedio(float a, float b, float c);

float promedio(float a, float b, float c)
{
	return (a + b + c) / 3.0;
}

int main()
{
	float a, b, c;

	cout << "Introduzca tres numeros reales: ";
	cin >> a >> b >> c;

	cout << "Promedio = " << promedio(a, b, c) << endl;

	return 0;
}
