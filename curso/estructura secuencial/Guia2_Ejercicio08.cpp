#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 8
 * Calcular el área de un triángulo dada su base y su altura.
 * Fórmula: A = (base * altura) / 2
 */

/* --------------------------------------------------------------------------
 * ANÁLISIS EPS
 * --------------------------------------------------------------------------
 * Entrada:    base, altura
 * Proceso:    A = base * altura / 2
 * Salida:     área A
 *
 * Especificación de parámetros:
 *   base, altura : float
 *   A            : float -> área del triángulo
 *
 * Algoritmo general:
 *   Leer base y altura, calcular área, mostrar resultado.
 * -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * PSEUDOCÓDIGO
 * --------------------------------------------------------------------------
 * 1. Leer base, altura
 * 2. A = base * altura / 2
 * 3. Imprimir A
 * -------------------------------------------------------------------------- */

int main()
{
	float base, altura, A;

	cout << "Indique la base: ";
	cin >> base;
	cout << "Indique la altura: ";
	cin >> altura;

	A = base * altura / 2;

	cout << "Area = " << A << endl;

	return 0;
}
