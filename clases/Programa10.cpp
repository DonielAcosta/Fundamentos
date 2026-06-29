#include<iostream>
using namespace std;

/*
 * Programa 10 - Día del año (año no bisiesto).
 * fecha: 15/06/2026
 *
 * Autor: Yeberth Martinez
 * C.I.V.: 31.199.033
 * Carrera: Ing. de Sistemas
 *
 * Solicita al usuario un mes (1-12) y un día, calcula e imprime el número
 * de día del año correspondiente. Febrero tiene 28 días (año no bisiesto).
 *
 * Conceptos: programación modular y decisiones simples apiladas con
 * validación anidada.
 */

// Procedimientos
int menu();

int menu()
{
	int m;

	cout << "Elige el mes del anio (1-12):\n";
	cout << "1. Enero" << endl;
	cout << "2. Febrero" << endl;
	cout << "3. Marzo" << endl;
	cout << "4. Abril" << endl;
	cout << "5. Mayo" << endl;
	cout << "6. Junio" << endl;
	cout << "7. Julio" << endl;
	cout << "8. Agosto" << endl;
	cout << "9. Septiembre" << endl;
	cout << "10. Octubre" << endl;
	cout << "11. Noviembre" << endl;
	cout << "12. Diciembre" << endl;
	cout << "Ingrese el numero del mes (1-12): ";
	cin >> m;

	return m;
}

int main()
{
	int d, m;

	// Entrada: selección del mes
	m = menu();

	// Proceso: apilamiento de decisiones simples por mes
	// Cada bloque valida el día e imprime el día del año

	if (m == 1) {
		cout << "Ingrese el dia (1-31): ";
		cin >> d;
		if (d > 31 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d << " dias en total" << endl;
	}

	if (m == 2) {
		cout << "Ingrese el dia (1-28): ";
		cin >> d;
		if (d > 28 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 31 << " dias en total" << endl;
	}

	if (m == 3) {
		cout << "Ingrese el dia (1-31): ";
		cin >> d;
		if (d > 31 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 59 << " dias en total" << endl;
	}

	if (m == 4) {
		cout << "Ingrese el dia (1-30): ";
		cin >> d;
		if (d > 30 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 90 << " dias en total" << endl;
	}

	if (m == 5) {
		cout << "Ingrese el dia (1-31): ";
		cin >> d;
		if (d > 31 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 120 << " dias en total" << endl;
	}

	if (m == 6) {
		cout << "Ingrese el dia (1-30): ";
		cin >> d;
		if (d > 30 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 151 << " dias en total" << endl;
	}

	if (m == 7) {
		cout << "Ingrese el dia (1-31): ";
		cin >> d;
		if (d > 31 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 181 << " dias en total" << endl;
	}

	if (m == 8) {
		cout << "Ingrese el dia (1-31): ";
		cin >> d;
		if (d > 31 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 212 << " dias en total" << endl;
	}

	if (m == 9) {
		cout << "Ingrese el dia (1-30): ";
		cin >> d;
		if (d > 30 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 243 << " dias en total" << endl;
	}

	if (m == 10) {
		cout << "Ingrese el dia (1-31): ";
		cin >> d;
		if (d > 31 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 273 << " dias en total" << endl;
	}

	if (m == 11) {
		cout << "Ingrese el dia (1-30): ";
		cin >> d;
		if (d > 30 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 304 << " dias en total" << endl;
	}

	if (m == 12) {
		cout << "Ingrese el dia (1-31): ";
		cin >> d;
		if (d > 31 || d < 1)
			cout << "Dia invalido" << endl;
		else
			cout << "hay " << d + 334 << " dias en total" << endl;
	}

	return 0;
}
