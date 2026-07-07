#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 1 (Lección 21)
 * Función lógica positivo: devuelve verdadero si el entero es mayor que 1.
 * Sin estructuras de decisión.
 */

bool positivo(int n);

bool positivo(int n)
{
	return n > 1;
}

int main()
{
	int n;

	cout << "Introduzca un entero: ";
	cin >> n;

	cout << "positivo(" << n << ") = " << positivo(n) << endl;

	return 0;
}
