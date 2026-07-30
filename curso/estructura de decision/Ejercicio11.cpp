#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 11
 * Lea un número entre 1 y 7 e imprima el día de la semana.
 */

int main()
{
	int dia;

	cout << "Introduzca un numero entre 1 y 7: ";
	cin >> dia;

	if (dia == 1)
		cout << "Lunes" << endl;
	else if (dia == 2)
		cout << "Martes" << endl;
	else if (dia == 3)
		cout << "Miercoles" << endl;
	else if (dia == 4)
		cout << "Jueves" << endl;
	else if (dia == 5)
		cout << "Viernes" << endl;
	else if (dia == 6)
		cout << "Sabado" << endl;
	else if (dia == 7)
		cout << "Domingo" << endl;
	else
		cout << "Numero fuera de rango" << endl;

	return 0;
}
