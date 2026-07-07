#include<iostream>
using namespace std;

/*
 * Ejercicio 1 - Verificación de valores de expresiones.
 * a : float (real), b : int (entero)
 */

int main()
{
	float a;
	int b;

	a = 15.0 / 12;
	cout << "a = 15/12        -> " << a << endl;

	b = 15 / 12;
	cout << "b = 15/12        -> " << b << endl;

	b = 15 % 12;
	cout << "b = 15 % 12      -> " << b << endl;

	a = 15 * 14 - 3 * 7;
	cout << "a = 15*14-3*7    -> " << a << endl;

	b = -4 * 5 * 2;
	cout << "b = -4*5*2       -> " << b << endl;

	b = (24 + 2 * 6) % 4;
	cout << "b = (24+2*6)%4   -> " << b << endl;

	a = 3 + 4 * (8 * (4 - (9 + 3) / 6.0));
	cout << "a = 3+4*(8*(...))-> " << a << endl;

	return 0;
}
