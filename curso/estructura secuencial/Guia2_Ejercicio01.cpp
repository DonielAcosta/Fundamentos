#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 1 (Clase 15)
 * Leer un número e imprimir los 10 números consecutivos siguientes.
 */

int main()
{
	int n, i;

	cout << "Introduzca un numero: ";
	cin >> n;

	cout << "Los 10 numeros consecutivos son: ";
	for (i = 1; i <= 10; i++)
		cout << n + i << " ";
	cout << endl;

	return 0;
}
