#include<iostream>
using namespace std;

/*
 * Guía 2 - Ejercicio 6 (Clase 19)
 * Leer dos fechas (día y mes) y calcular cuántos días hay entre ellas (ambas inclusive).
 */

/* --------------------------------------------------------------------------
 * ANÁLISIS EPS
 * --------------------------------------------------------------------------
 * Entrada:    dia1, mes1, dia2, mes2
 * Proceso:    convertir cada fecha a día del año
 *             dias = |diaAnio2 - diaAnio1| + 1
 * Salida:     cantidad de días entre fechas (inclusive)
 *
 * Algoritmo general:
 *   Leer ambas fechas, convertir a día del año, calcular diferencia inclusive.
 * -------------------------------------------------------------------------- */

int diaAnio(int d, int m)
{
	int diasAcumulados[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	return diasAcumulados[m] + d;
}

int main()
{
	int dia1, mes1, dia2, mes2;
	int anio1, anio2, dias;

	cout << "Primera fecha (dia mes): ";
	cin >> dia1 >> mes1;
	cout << "Segunda fecha (dia mes): ";
	cin >> dia2 >> mes2;

	anio1 = diaAnio(dia1, mes1);
	anio2 = diaAnio(dia2, mes2);

	if (anio1 > anio2)
		dias = anio1 - anio2 + 1;
	else
		dias = anio2 - anio1 + 1;

	cout << "Dias entre fechas (inclusive): " << dias << endl;

	return 0;
}
