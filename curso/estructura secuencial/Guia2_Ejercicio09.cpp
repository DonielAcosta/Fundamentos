#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 9
 * Calcular el área de un cuadrado dada la medida de su lado.
 * Fórmula: A = lado * lado
 */

/* --------------------------------------------------------------------------
 * ANÁLISIS EPS
 * --------------------------------------------------------------------------
 * Entrada:    lado
 * Proceso:    A = lado * lado
 * Salida:     área A
 *
 * Especificación de parámetros:
 *   lado : float
 *   A    : float -> área del cuadrado
 *
 * Algoritmo general:
 *   Leer lado, calcular área, mostrar resultado.
 * -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * PSEUDOCÓDIGO
 * --------------------------------------------------------------------------
 * 1. Leer lado
 * 2. A = lado * lado
 * 3. Imprimir A
 * -------------------------------------------------------------------------- */

int main()
{
	float lado, A;

	cout << "Indique el lado: ";
	cin >> lado;

	A = lado * lado;

	cout << "Area = " << A << endl;

	return 0;
}
