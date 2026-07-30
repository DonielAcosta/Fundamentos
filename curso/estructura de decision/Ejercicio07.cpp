#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 7
 * Lea un carácter e indique si está entre la 'a' y la 'f', sin incluirlos.
 * Es decir: 'b', 'c', 'd' o 'e'.
 */

int main()
{
	char c;

	cout << "Introduzca un caracter: ";
	cin >> c;

	if (c > 'a' && c < 'f')
		cout << "El caracter esta entre 'a' y 'f' (sin incluirlos)" << endl;
	else
		cout << "El caracter no esta entre 'a' y 'f'" << endl;

	return 0;
}
