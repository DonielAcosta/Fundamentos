#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 11 (Problema 7)
 * Programa para corrida en frío: intercambio de variables con función.
 * Ver tabla paso a paso en Guia3_Ejercicio11.md
 */

void intercambiar(int &a, int &b);

void intercambiar(int &a, int &b)
{
	int aux;
	aux = a;
	a = b;
	b = aux;
}

int main()
{
	int a = 7;
	int b = 3;

	cout << "Paso 0 - Antes: a = " << a << ", b = " << b << endl;
	intercambiar(a, b);
	cout << "Paso final - Despues: a = " << a << ", b = " << b << endl;

	return 0;
}
