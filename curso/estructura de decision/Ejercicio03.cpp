#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 3
 * Lea un número entero y decida si es impar.
 * Debe escribir en consola "Si es impar".
 */

int main()
{
	int n;

	cout << "Introduzca un numero entero: ";
	cin >> n;

	if (n % 2 != 0)
		cout << "Si es impar" << endl;

	return 0;
}
