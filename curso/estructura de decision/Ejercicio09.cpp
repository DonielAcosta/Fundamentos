#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 9
 * Lea la fecha de nacimiento e imprima la edad exacta
 * en años, meses y días (respecto a una fecha actual dada).
 */

int diasDelMes(int mes, int anio)
{
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
		return 31;
	if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
		return 30;
	if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
		return 29;
	return 28;
}

int main()
{
	int dNac, mNac, aNac;
	int dAct, mAct, aAct;
	int anios, meses, dias;

	cout << "Fecha de nacimiento (dia mes anio): ";
	cin >> dNac >> mNac >> aNac;

	cout << "Fecha actual (dia mes anio): ";
	cin >> dAct >> mAct >> aAct;

	anios = aAct - aNac;
	meses = mAct - mNac;
	dias = dAct - dNac;

	if (dias < 0)
	{
		meses = meses - 1;
		dias = dias + diasDelMes(mAct == 1 ? 12 : mAct - 1, mAct == 1 ? aAct - 1 : aAct);
	}

	if (meses < 0)
	{
		anios = anios - 1;
		meses = meses + 12;
	}

	cout << "Edad exacta: " << anios << " anios, "
		 << meses << " meses y " << dias << " dias" << endl;

	return 0;
}
