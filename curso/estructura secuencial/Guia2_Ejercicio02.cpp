#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 2 (Clase 15)
 * Leer un número e imprimir, de cinco en cinco, los siguientes cinco números.
 * Ejemplo: si n = 10 -> 15  20  25  30  35
 */

int main()
{
	int n, i;

	cout << "Introduzca un numero: ";
	cin >> n;

	cout << "Los siguientes cinco numeros (de 5 en 5): ";
	for (i = 1; i <= 5; i++)
		cout << n + 5 * i << " ";
	cout << endl;

	return 0;
}
