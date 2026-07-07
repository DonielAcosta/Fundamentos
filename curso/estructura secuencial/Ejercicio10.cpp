#include<iostream>
using namespace std;

/*
 * Ejercicio 10 - Número disminuido en el triple del número aumentado en dos.
 *
 * Lea un número e imprima dicho número disminuido en el triple del número
 * aumentado en dos.
 * Fórmula: n - 3 * (n + 2)
 */

int main()
{
	int n, resultado;

	cout << "Introduzca un numero: ";
	cin >> n;

	resultado = n - 3 * (n + 2);

	cout << "Resultado = " << resultado << endl;

	return 0;
}
