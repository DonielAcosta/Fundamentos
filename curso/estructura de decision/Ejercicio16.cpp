#include<iostream>
using namespace std;

/*
 * Guía 3 - Ejercicio 16
 * Corrida en frío: qué imprime el código del enunciado.
 */

int main()
{
	int a = 6;
	int b = '2';
	char c = 'e';
	char d = 't';
	bool aux = true;
	bool A = true && (5 < 6 == true) && false;

	if (aux || A)
	{
		a = b + 5;
		cout << "hola" << endl;
	}
	else
	{
		A = a < b;
		cout << "chao" << endl;
	}

	cout << a << b << c << d << aux << A << endl;
	cout << "A= " << A << endl;

	return 0;
}
