#include<iostream>
using namespace std;

/*
 *  Recto 2: día del año (sin estructuras de decisión).
 * fecha: 12/06/2026
 *
 * Diseñe un programa que lea una fecha en día y mes y muestre por consola
 * qué día del año es.
 *
 * Ejemplo:
 *   30 de enero  -> día 30
 *   2 de febrero -> día 33  (31 + 2)
 *
 * Enfoque: arreglo con los días acumulados al inicio de cada mes.
 */

int main()
{
	int dia, mes, diaDelAnio;
	int diasAcumulados[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << "Ingrese el mes: ";
	cin >> mes;

	diaDelAnio = diasAcumulados[mes] + dia;

	cout << "Dia del anio: " << diaDelAnio << endl;

	return 0;
}
