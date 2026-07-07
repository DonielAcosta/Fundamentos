#include<iostream>
using namespace std;

/*
 * Ejercicio 9 - Suma del número y su quíntuplo aumentado en seis.
 *
 * Lea un número del teclado e imprima la suma de este número y su quíntuplo
 * aumentado en seis.
 * Fórmula: n + (5 * n + 6) = 6 * n + 6
 */

int main()
{
	int n, resultado;

	cout << "Introduzca un numero: ";
	cin >> n;

	resultado = n + (5 * n + 6);

	cout << "Resultado = " << resultado << endl;

	return 0;
}
