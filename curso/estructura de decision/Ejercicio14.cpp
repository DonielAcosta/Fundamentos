#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 14
 * Calcular el área de un triángulo usando módulos.
 * Fórmula: area = (base * altura) / 2
 */

double areaTriangulo(double base, double altura);

double areaTriangulo(double base, double altura)
{
	return (base * altura) / 2.0;
}

int main()
{
	double base, altura, area;

	cout << "Introduzca la base: ";
	cin >> base;

	cout << "Introduzca la altura: ";
	cin >> altura;

	area = areaTriangulo(base, altura);

	cout << "Area del triangulo = " << area << endl;

	return 0;
}
