#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 4 (Clase 18)
 * Juan empaqueta caramelos en paquetes de 50 y los reparte en bolsas de 20.
 * Calcular cuántas bolsas de 20 necesita y cuántos caramelos sobran.
 */

/* --------------------------------------------------------------------------
 * ANÁLISIS EPS
 * --------------------------------------------------------------------------
 * Entrada:    cantidad de paquetes de 50 caramelos
 * Proceso:    total = paquetes * 50
 *             bolsas = total / 20
 *             sobran = total % 20
 * Salida:     bolsas y caramelos sobrantes
 *
 * Especificación de parámetros:
 *   paquetes : int -> cantidad de paquetes de 50
 *   total    : int -> total de caramelos
 *   bolsas   : int -> bolsas de 20 completas
 *   sobran   : int -> caramelos restantes
 *
 * Algoritmo general:
 *   Leer paquetes, calcular total, obtener bolsas y sobrantes, mostrar resultados.
 * -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * PSEUDOCÓDIGO
 * --------------------------------------------------------------------------
 * 1. Leer paquetes
 * 2. total = paquetes * 50
 * 3. bolsas = total / 20
 * 4. sobran = total % 20
 * 5. Imprimir bolsas y sobran
 * -------------------------------------------------------------------------- */

int main()
{
	int paquetes, total, bolsas, sobran;

	cout << "Cantidad de paquetes de 50 caramelos: ";
	cin >> paquetes;

	total = paquetes * 50;
	bolsas = total / 20;
	sobran = total % 20;

	cout << "Total de caramelos: " << total << endl;
	cout << "Bolsas de 20: " << bolsas << endl;
	cout << "Caramelos que sobran: " << sobran << endl;

	return 0;
}
