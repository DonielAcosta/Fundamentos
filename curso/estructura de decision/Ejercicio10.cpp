#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 10
 * Lea un número entre 1 y 12 e imprima el nombre del mes.
 */

int main()
{
	int mes;

	cout << "Introduzca un numero entre 1 y 12: ";
	cin >> mes;

	if (mes == 1)
		cout << "Enero" << endl;
	else if (mes == 2)
		cout << "Febrero" << endl;
	else if (mes == 3)
		cout << "Marzo" << endl;
	else if (mes == 4)
		cout << "Abril" << endl;
	else if (mes == 5)
		cout << "Mayo" << endl;
	else if (mes == 6)
		cout << "Junio" << endl;
	else if (mes == 7)
		cout << "Julio" << endl;
	else if (mes == 8)
		cout << "Agosto" << endl;
	else if (mes == 9)
		cout << "Septiembre" << endl;
	else if (mes == 10)
		cout << "Octubre" << endl;
	else if (mes == 11)
		cout << "Noviembre" << endl;
	else if (mes == 12)
		cout << "Diciembre" << endl;
	else
		cout << "Numero fuera de rango" << endl;

	return 0;
}
