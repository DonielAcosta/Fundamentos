#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 2
 * Lea un número e imprima "eureka" solo si está entre 50 y 75 (incluidos).
 */

int main()
{
	int n;

	cout << "Introduzca un numero: ";
	cin >> n;

	if (n >= 50 && n <= 75)
		cout << "eureka" << endl;

	return 0;
}
