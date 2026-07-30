#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 5
 * Lea un carácter del teclado e indique si éste es '+'.
 */

int main()
{
	char c;

	cout << "Introduzca un caracter: ";
	cin >> c;

	if (c == '+')
		cout << "El caracter es '+'" << endl;
	else
		cout << "El caracter no es '+'" << endl;

	return 0;
}
