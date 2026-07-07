#include<iostream>
using namespace std;

/*
 * Ejercicio 15 - Verificación de expresión (a=2, b=-2).
 */

int main()
{
	int a = 2, b = -2;
	double resultado;

	resultado = (a % 5 + b * 6 / 8 % 3 - 5 / 6.0 + 4) / (4 / 3 % 6 / 9.4);

	cout << "Resultado = " << resultado << endl;

	return 0;
}
