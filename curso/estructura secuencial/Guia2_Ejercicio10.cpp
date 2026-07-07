#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 10
 * Calcular el área de un rectángulo dado su largo y su ancho.
 * Fórmula: A = largo * ancho
 */

/* --------------------------------------------------------------------------
 * ANÁLISIS EPS
 * --------------------------------------------------------------------------
 * Entrada:    largo, ancho
 * Proceso:    A = largo * ancho
 * Salida:     área A
 *
 * Especificación de parámetros:
 *   largo, ancho : float
 *   A            : float -> área del rectángulo
 *
 * Algoritmo general:
 *   Leer largo y ancho, calcular área, mostrar resultado.
 * -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * PSEUDOCÓDIGO
 * --------------------------------------------------------------------------
 * 1. Leer largo, ancho
 * 2. A = largo * ancho
 * 3. Imprimir A
 * -------------------------------------------------------------------------- */

int main()
{
	float largo, ancho, A;

	cout << "Indique el largo: ";
	cin >> largo;
	cout << "Indique el ancho: ";
	cin >> ancho;

	A = largo * ancho;

	cout << "Area = " << A << endl;

	return 0;
}
