#include<iostream>
using namespace std;

/*
 * Ejercicio 11 - Multiplicación de dos números.
 *
 * Lea dos números del teclado e imprima en consola la multiplicación de ambos.
 */

int main()
{
	int a, b, producto;

	cout << "Introduzca el primer numero: ";
	cin >> a;
	cout << "Introduzca el segundo numero: ";
	cin >> b;

	producto = a * b;

	cout << "Multiplicacion = " << producto << endl;

	return 0;
}
