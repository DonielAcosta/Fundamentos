#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 15
 * Lea 10 notas entre 0 y 20 e imprima si eximió
 * (promedio mayor que 16).
 */

int main()
{
	float nota, suma, promedio;
	int i;

	suma = 0;

	for (i = 1; i <= 10; i++)
	{
		cout << "Nota " << i << " (0-20): ";
		cin >> nota;

		if (nota < 0 || nota > 20)
		{
			cout << "Nota invalida, se tomara como 0" << endl;
			nota = 0;
		}

		suma = suma + nota;
	}

	promedio = suma / 10.0;

	cout << "Promedio = " << promedio << endl;

	if (promedio > 16)
		cout << "Eximio" << endl;
	else
		cout << "No eximio" << endl;

	return 0;
}
