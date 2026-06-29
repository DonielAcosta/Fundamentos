#include<iostream>
using namespace std;

/*
 * Recto 2: día del año (con decisiones simples apiladas).
 * fecha: 12/06/2026
 *
 * Misma tarea que Programa6 usando if para sumar los días de cada mes anterior.
 *
 * Notas de clase:
 *   Esta semana:    estructuras de decisión simples y apiladas
 *   Próxima semana: estructuras de decisión dobles y anidadas
 */

int main()
{
	int dia, mes, diaDelAnio;

	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << "Ingrese el mes: ";
	cin >> mes;

	diaDelAnio = dia;

	if (mes > 1)  diaDelAnio = diaDelAnio + 31;
	if (mes > 2)  diaDelAnio = diaDelAnio + 28;
	if (mes > 3)  diaDelAnio = diaDelAnio + 31;
	if (mes > 4)  diaDelAnio = diaDelAnio + 30;
	if (mes > 5)  diaDelAnio = diaDelAnio + 31;
	if (mes > 6)  diaDelAnio = diaDelAnio + 30;
	if (mes > 7)  diaDelAnio = diaDelAnio + 31;
	if (mes > 8)  diaDelAnio = diaDelAnio + 31;
	if (mes > 9)  diaDelAnio = diaDelAnio + 30;
	if (mes > 10) diaDelAnio = diaDelAnio + 31;
	if (mes > 11) diaDelAnio = diaDelAnio + 30;

	cout << "Dia del anio: " << diaDelAnio << endl;

	return 0;
}
