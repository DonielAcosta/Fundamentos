#include<iostream>
using namespace std;

/*
 * Promedio de notas.
 * fecha: 26/06/2026
 *
 * Diseñar un programa que lea notas del teclado e imprima su promedio.
 *
 * Conceptos: funciones, ciclo for y acumuladores.
 */

float leer();

float leer()
{
	float n;
	cout << "Introduzca la nota" << endl;
	cin >> n;
	return n;
}

int main()
{
	const int n = 5;
	float nota, suma, prome;

	// Inicialización
	suma = 0;

	// Proceso: leer notas y acumular suma
	for (int i = 1; i <= n; i++) {
		nota = leer();
		suma = suma + nota;
	}

	prome = suma / n;

	// Salida: mostrar promedio
	cout << "Promedio = " << prome << endl;

	return 0;
}
