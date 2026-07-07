#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 2 (Lección 21)
 * Convertir temperatura de Celsius a Fahrenheit.
 * Fórmula: F = (9/5) * C + 32
 */

float celsiusAFahrenheit(float c);

float celsiusAFahrenheit(float c)
{
	return (9.0 / 5.0) * c + 32;
}

int main()
{
	float c, f;

	cout << "Temperatura en Celsius: ";
	cin >> c;

	f = celsiusAFahrenheit(c);

	cout << c << " C = " << f << " F" << endl;

	return 0;
}
