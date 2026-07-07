#include<iostream>
using namespace std;

/*
 * Ejercicio 7 - Triple aumentado en tres.
 *
 * Lea un número del teclado e imprima en consola su triple aumentado en tres.
 * Fórmula: 3 * n + 3
 */

int main()
{
	int n, resultado;

	cout << "Introduzca un numero: ";
	cin >> n;

	resultado = 3 * n + 3;

	cout << "Triple aumentado en tres = " << resultado << endl;

	return 0;
}
