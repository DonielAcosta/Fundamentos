#include<iostream>
using namespace std;

/*
 * Ejercicio 14 - Verificación de expresión (a=7, b=3).
 */

int main()
{
	int a = 7, b = 3;
	int resultado;

	resultado = (a % 5 + b * 6 / 8 % 3 - 5 / 6 + 4) / (a + b - 4 / 3 % 6 / 9);

	cout << "Resultado (entero) = " << resultado << endl;

	return 0;
}
