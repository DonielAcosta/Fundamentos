#include<iostream>
#include<cmath>
using namespace std;

/*
 * Guía 3 - Ejercicio 4 (Lección 22)
 * Función que recibe a y b (enteros distintos de cero, a+b != 0) y retorna:
 *   sqrt((a^2 + b*a) / (a+b))
 */

double calcularExpresion(int a, int b);

double calcularExpresion(int a, int b)
{
	return sqrt((a * a + b * a) / double(a + b));
}

int main()
{
	int a, b;
	double resultado;

	cout << "Introduzca a: ";
	cin >> a;
	cout << "Introduzca b: ";
	cin >> b;

	resultado = calcularExpresion(a, b);

	cout << "Resultado = " << resultado << endl;

	return 0;
}
