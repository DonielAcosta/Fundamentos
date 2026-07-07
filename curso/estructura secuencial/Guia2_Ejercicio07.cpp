#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 7 (Clase 19)
 * Leer dos fechas (día y mes) y calcular cuántas semanas hay entre ellas (ambas inclusive).
 */

/* --------------------------------------------------------------------------
 * ANÁLISIS EPS
 * --------------------------------------------------------------------------
 * Entrada:    dia1, mes1, dia2, mes2
 * Proceso:    dias = días entre fechas (inclusive)
 *             semanas = dias / 7  (semanas completas)
 * Salida:     cantidad de semanas
 *
 * Algoritmo general:
 *   Leer fechas, calcular días inclusive, dividir entre 7.
 * -------------------------------------------------------------------------- */

int diaAnio(int d, int m)
{
	int diasAcumulados[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	return diasAcumulados[m] + d;
}

int diasEntre(int dia1, int mes1, int dia2, int mes2)
{
	int a1 = diaAnio(dia1, mes1);
	int a2 = diaAnio(dia2, mes2);

	if (a1 > a2)
		return a1 - a2 + 1;
	return a2 - a1 + 1;
}

int main()
{
	int dia1, mes1, dia2, mes2;
	int dias, semanas;

	cout << "Primera fecha (dia mes): ";
	cin >> dia1 >> mes1;
	cout << "Segunda fecha (dia mes): ";
	cin >> dia2 >> mes2;

	dias = diasEntre(dia1, mes1, dia2, mes2);
	semanas = dias / 7;

	cout << "Dias entre fechas (inclusive): " << dias << endl;
	cout << "Semanas completas: " << semanas << endl;

	return 0;
}
