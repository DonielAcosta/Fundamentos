#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 4
 * Lea un carácter del teclado e indique si éste es '3'.
 */

int main()
{
	char c;

	cout << "Introduzca un caracter: ";
	cin >> c;

	if (c == '3')
		cout << "El caracter es '3'" << endl;
	else
		cout << "El caracter no es '3'" << endl;

	return 0;
}
