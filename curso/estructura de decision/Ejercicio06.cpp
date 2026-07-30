#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 6
 * Lea un carácter del teclado e indique si éste es '3' o 'A'.
 */

int main()
{
	char c;

	cout << "Introduzca un caracter: ";
	cin >> c;

	if (c == '3' || c == 'A')
		cout << "El caracter es '3' o 'A'" << endl;
	else
		cout << "El caracter no es '3' ni 'A'" << endl;

	return 0;
}
