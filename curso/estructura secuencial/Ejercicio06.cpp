#include<iostream>
using namespace std;

/*
 * Ejercicio 6 - Programa corregido.
 * Errores del original: cin<<A (debía ser cin>>A) y falta using namespace std.
 */

int main()
{
	int A, B;

	A = 9;
	B = 4;
	cin >> A;
	A = A * 5;
	cout << A << endl;

	return 0;
}
