#include<iostream>
#include<cmath>
using namespace std;

/*
 * Pago por días trabajados.
 * fecha: 19/06/2026
 * Una empresa contrató personal del 1 de enero hasta el 31 de marzo.
 * El día de hoy decidieron despedir a todo el mundo y pagarán como arreglo
 * 87 dólares por cada día trabajado.
 *
 * El programa lee la fecha de ingreso del empleado (día y mes) y calcula
 * el pago desde esa fecha hasta hoy (19 de junio).
 *
 * Conceptos: funciones booleanas, día del año sin decisiones y cálculo EPS.
 */

// Funciones
bool esBisiesto(int anio);
bool esBisiesto2(int anio);
int diaAnio(int d, int m);

bool esBisiesto(int anio)
{
	return anio % 4 == 0;
}

bool esBisiesto2(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int diaAnio(int d, int m)
{
	return 31 * (m > 1) + 28 * (m > 2) + 31 * (m > 3) + 30 * (m > 4) +
		   31 * (m > 5) + 30 * (m > 6) + 31 * (m > 7) + 31 * (m > 8) +
		   30 * (m > 9) + 31 * (m > 10) + 30 * (m > 11) + d;
}

int main()
{
	int d, m, dt, pago;
	const int diaHoy = 19;
	const int mesHoy = 6;
	const int pagoPorDia = 87;

	// Entrada: fecha de ingreso del empleado
	cout << "Ingrese la fecha de ingreso (dia mes): ";
	cin >> d >> m;

	// Proceso: días trabajados desde el ingreso hasta hoy
	dt = diaAnio(diaHoy, mesHoy) - diaAnio(d, m) + 1;
	pago = pagoPorDia * dt;

	// Salida: monto a pagar
	cout << "Dias trabajados: " << dt << endl;
	cout << "El pago es " << pago << endl;

	return 0;
}
