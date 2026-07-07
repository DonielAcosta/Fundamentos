#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 5 (Clase 19)
 * Dada una fecha (día y mes), indicar qué día del año es (año de 365 días).
 * Ejemplo: 2 de marzo -> día 61 (31 + 28 + 2, año no bisiesto).
 */

/* --------------------------------------------------------------------------
 * ANÁLISIS EPS
 * --------------------------------------------------------------------------
 * Entrada:    dia, mes
 * Proceso:    diaAnio = dias acumulados al inicio del mes + dia
 * Salida:     número de día del año (1 a 365)
 *
 * Especificación de parámetros:
 *   dia, mes      : int -> fecha ingresada
 *   diaDelAnio    : int -> resultado
 *
 * Algoritmo general:
 *   Leer dia y mes, sumar dias de meses anteriores mas el dia, mostrar resultado.
 * -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * PSEUDOCÓDIGO
 * --------------------------------------------------------------------------
 * 1. Leer dia, mes
 * 2. diaDelAnio = diasAcumulados[mes] + dia
 * 3. Imprimir diaDelAnio
 * -------------------------------------------------------------------------- */

int diaAnio(int d, int m)
{
	int diasAcumulados[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	return diasAcumulados[m] + d;
}

int main()
{
	int dia, mes, diaDelAnio;

	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << "Ingrese el mes: ";
	cin >> mes;

	diaDelAnio = diaAnio(dia, mes);

	cout << "Dia del anio: " << diaDelAnio << endl;

	return 0;
}
