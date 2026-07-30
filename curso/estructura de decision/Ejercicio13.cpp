#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 13
 * Diseño modular (ejemplo): pago del trabajador (ejercicio 12).
 */

int aMinutos(int hora, int minuto);
int minutosTrabajados(int hEnt, int mEnt, int hSal, int mSal);
int calcularPago(int minutos);

int aMinutos(int hora, int minuto)
{
	return hora * 60 + minuto;
}

int minutosTrabajados(int hEnt, int mEnt, int hSal, int mSal)
{
	int trabajados;

	trabajados = aMinutos(hSal, mSal) - aMinutos(hEnt, mEnt);

	if (trabajados < 0)
		trabajados = trabajados + 24 * 60;

	return trabajados;
}

int calcularPago(int minutos)
{
	int normales, extras;

	if (minutos <= 480)
	{
		normales = minutos;
		extras = 0;
	}
	else
	{
		normales = 480;
		extras = minutos - 480;
	}

	return normales * 3 + extras * 5;
}

int main()
{
	int hEnt, mEnt, hSal, mSal;
	int minutos, pago;

	cout << "Hora de entrada (hora minuto): ";
	cin >> hEnt >> mEnt;

	cout << "Hora de salida (hora minuto): ";
	cin >> hSal >> mSal;

	minutos = minutosTrabajados(hEnt, mEnt, hSal, mSal);
	pago = calcularPago(minutos);

	cout << "Minutos trabajados: " << minutos << endl;
	cout << "Pago total: " << pago << " dolares" << endl;

	return 0;
}
