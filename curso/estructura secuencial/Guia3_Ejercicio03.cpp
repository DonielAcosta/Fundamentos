#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 3 (Lección 21)
 * Función con 5 parámetros de al menos 3 tipos diferentes.
 */

void mostrarDatos(int entero, float real, char caracter, bool logico, double doble);

void mostrarDatos(int entero, float real, char caracter, bool logico, double doble)
{
	cout << "Entero: " << entero << endl;
	cout << "Real: " << real << endl;
	cout << "Caracter: " << caracter << endl;
	cout << "Logico: " << logico << endl;
	cout << "Doble: " << doble << endl;
}

int main()
{
	mostrarDatos(42, 3.14f, 'A', true, 2.71828);

	return 0;
}
