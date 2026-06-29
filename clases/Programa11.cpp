#include<iostream>
using namespace std;

/*
 * ordenar tres enteros de menor a mayor.
 * fecha: 17/06/2026
 *
 * Diseñar un programa que lea tres números enteros del teclado y los guarde
 * en las variables A, B y C, y muestre por consola los números ordenados
 * de menor a mayor, guardados en ese mismo orden en A, B y C.
 *
 * Enfoque: ordenamiento por intercambios usando casillas auxiliares (c1, c2, c3).
 */

int main()
{
	// Declaración de variables
	int A, B, C;
	int c1, c2, c3, temp;

	// Entrada: lectura de los tres valores
	cout << "Introduce un valor para A ";
	cin >> A;
	cout << "Introduce un valor para B ";
	cin >> B;
	cout << "Introduce un valor para C ";
	cin >> C;

	cout << "Antes: A = " << A << "  B = " << B << "  C = " << C << endl;

	// Proceso: cargar valores en las casillas
	c1 = A;
	c2 = B;
	c3 = C;

	// Iteración 1: comparar c1 y c2, dejar el menor en c1
	if (c1 > c2) {
		temp = c1;
		c1 = c2;
		c2 = temp;
	}

	// Iteración 2: comparar c2 y c3, dejar el mayor en c3
	if (c2 > c3) {
		temp = c2;
		c2 = c3;
		c3 = temp;
	}

	// Iteración 3: comparar c1 y c2 nuevamente
	if (c1 > c2) {
		temp = c1;
		c1 = c2;
		c2 = temp;
	}

	// Devolver valores ordenados a las variables originales
	A = c1;
	B = c2;
	C = c3;

	// Salida: mostrar resultado
	cout << "Ordenados: A = " << A << "  B = " << B << "  C = " << C << endl;

	return 0;
}
