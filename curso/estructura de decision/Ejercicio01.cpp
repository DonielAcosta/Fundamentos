#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 1
 * Corrida en frío: mostrar los valores finales de las variables.
 * Se corrigen las comillas dobles del enunciado por simples ('3').
 * B se inicializa en 0 para evitar comportamiento indefinido.
 */

int main()
{
	int A, B;
	bool a;
	char b;

	B = 0;

	a = true;
	b = '3';
	A = 9 * 3 + 8;
	b = '5';
	a = false == true;
	a = b != '6';
	B = 4 % (A + A) * B - 7;
	A = A * 5;

	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}
