#include<iostream>
using namespace std;

/*
 *  Recto 1: ordenar tres enteros de menor a mayor.
 * fecha: 12/06/2026
 *
 * Diseñar un programa que lea tres números enteros del teclado y los guarde
 * en las variables A, B y C, y muestre por consola los números ordenados
 * de menor a mayor, guardados en ese mismo orden en A, B y C.
 *
 * Sugerencia: primero hágalo con dos variables (intercambio).
 *
 * Ejemplo:
 *   Entrada: 9  6  8
 *   Estado inicial:  A = 9, B = 6, C = 8
 *   Salida:          A = 6, B = 8, C = 9
 */

int main()
{
	int A, B, C, aux;

	cout << "Ingrese tres numeros enteros: ";
	cin >> A >> B >> C;

	cout << "Antes: A = " << A << "  B = " << B << "  C = " << C << endl;

	// Ordenar A <= B <= C mediante intercambios
	if (A > B) {
		aux = A;
		A = B;
		B = aux;
	}
	if (A > C) {
		aux = A;
		A = C;
		C = aux;
	}
	if (B > C) {
		aux = B;
		B = C;
		C = aux;
	}

	cout << "Ordenados: A = " << A << "  B = " << B << "  C = " << C << endl;

	return 0;
}
