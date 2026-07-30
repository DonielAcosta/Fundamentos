#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 12
 * Calcule el pago de un trabajador según hora de entrada y salida.
 * - Minuto de trabajo: 3 dólares
 * - Jornada laboral: 8 horas (480 minutos)
 * - Minuto extra: 5 dólares
 *
 * Las horas se leen en formato: hora_entrada minuto_entrada
 *                              hora_salida  minuto_salida
 * (reloj de 24 horas).
 */

int main()
{
	int hEnt, mEnt, hSal, mSal;
	int minutosEntrada, minutosSalida, minutosTrabajados;
	int minutosNormales, minutosExtras;
	int pago;

	cout << "Hora de entrada (hora minuto): ";
	cin >> hEnt >> mEnt;

	cout << "Hora de salida (hora minuto): ";
	cin >> hSal >> mSal;

	minutosEntrada = hEnt * 60 + mEnt;
	minutosSalida = hSal * 60 + mSal;
	minutosTrabajados = minutosSalida - minutosEntrada;

	if (minutosTrabajados < 0)
		minutosTrabajados = minutosTrabajados + 24 * 60;

	if (minutosTrabajados <= 480)
	{
		minutosNormales = minutosTrabajados;
		minutosExtras = 0;
	}
	else
	{
		minutosNormales = 480;
		minutosExtras = minutosTrabajados - 480;
	}

	pago = minutosNormales * 3 + minutosExtras * 5;

	cout << "Minutos trabajados: " << minutosTrabajados << endl;
	cout << "Minutos normales: " << minutosNormales << endl;
	cout << "Minutos extras: " << minutosExtras << endl;
	cout << "Pago total: " << pago << " dolares" << endl;

	return 0;
}
