#include<iostream>
using namespace std;

/*
 * Ejercicio 12 - Multiplicar entero por 2 (una sola variable).
 *
 * Lea un número entero, multiplíquelo por 2 y escriba el resultado en pantalla.
 * Usando una única variable para almacenar el valor.
 */

int main()
{
	int n;

	cout << "Introduzca un numero entero: ";
	cin >> n;

	n = n * 2;

	cout << "Resultado = " << n << endl;

	return 0;
}
