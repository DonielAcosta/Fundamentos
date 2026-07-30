#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 8
 * Lea la edad de una persona e imprima si es o no mayor de edad.
 */

int main()
{
	int edad;

	cout << "Introduzca la edad: ";
	cin >> edad;

	if (edad >= 18)
		cout << "Es mayor de edad" << endl;
	else
		cout << "No es mayor de edad" << endl;

	return 0;
}
