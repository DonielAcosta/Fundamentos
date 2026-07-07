#include<iostream>
using namespace std;

/*
 * Ejercicio 8 - Cociente con cinco.
 *
 * Lea un número del teclado e imprima en consola el cociente de este y cinco.
 * Fórmula: n / 5 (división entera)
 */

int main()
{
	int n, cociente;

	cout << "Introduzca un numero: ";
	cin >> n;

	cociente = n / 5;

	cout << "Cociente con cinco = " << cociente << endl;

	return 0;
}
