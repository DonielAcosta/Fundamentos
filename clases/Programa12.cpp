#include<iostream>
using namespace std;

/*
 * Recto 2: día del año.
 * fecha: 17/06/2026
 *
 * Diseñe un programa que lea una fecha en día y mes y muestre por consola
 * qué día del año es, usando estructuras de decisión simples apiladas.
 *
 * Enfoque: variables con los días de cada mes y suma según el mes elegido.
 * Año no bisiesto (febrero = 28 días).
 */

int main()
{
	// Declaración de variables
	int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12;
	int M, D, TD; // TD: total de días transcurridos en el año hasta la fecha

	// Inicialización: días de cada mes
	m1 = 31;
	m2 = 28;
	m3 = 31;
	m4 = 30;
	m5 = 31;
	m6 = 30;
	m7 = 31;
	m8 = 31;
	m9 = 30;
	m10 = 31;
	m11 = 30;
	m12 = 31;

	// Entrada: lectura de mes y día
	cout << "Mes requerido: ";
	cin >> M;
	cout << "Dia requerido: ";
	cin >> D;

	// Proceso: apilamiento de decisiones simples por mes
	if (M == 1)
		TD = D;
	if (M == 2)
		TD = D + m1;
	if (M == 3)
		TD = D + m1 + m2;
	if (M == 4)
		TD = D + m1 + m2 + m3;
	if (M == 5)
		TD = D + m1 + m2 + m3 + m4;
	if (M == 6)
		TD = D + m1 + m2 + m3 + m4 + m5;
	if (M == 7)
		TD = D + m1 + m2 + m3 + m4 + m5 + m6;
	if (M == 8)
		TD = D + m1 + m2 + m3 + m4 + m5 + m6 + m7;
	if (M == 9)
		TD = D + m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8;
	if (M == 10)
		TD = D + m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9;
	if (M == 11)
		TD = D + m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10;
	if (M == 12)
		TD = D + m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11;

	// Salida: mostrar día del año
	cout << "Total de dias en el anio: " << TD << endl;

	return 0;
}
