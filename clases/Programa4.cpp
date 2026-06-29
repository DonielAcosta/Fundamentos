#include<iostream>
using namespace std;

/*
 * fecha: 12/06/2026
 *
 * Técnica para intercambiar los valores de dos variables usando una auxiliar.
 *
 * Antes:  a = 7, b = 8
 * Después: a = 8, b = 7
 */

int main()
{
	int a, b, aux;

	a = 7;
	b = 8;

	cout << "Antes del intercambio:" << endl;
	cout << "a = " << a << "  b = " << b << endl;

	// Intercambio de valores
	aux = a;
	a = b;
	b = aux;

	cout << "Después del intercambio:" << endl;
	cout << "a = " << a << "  b = " << b << endl;

	return 0;
}
