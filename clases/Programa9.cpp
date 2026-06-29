#include<iostream>
using namespace std;

/*
 * Ordenar tres enteros de menor a mayor.
 * fecha: 13/06/2026
 *
 * Autor: Yeberth Martinez
 * C.I.V.: 31.199.033
 * Carrera: Ing. de Sistemas
 *
 * Solicita tres números enteros al usuario, los ordena de menor a mayor
 * mediante intercambios condicionales y muestra el resultado en pantalla.
 */

int main()
{
	// Declaración de variables
	int A, B, C, aux;

	// Entrada: lectura de los tres valores
	cout << "Ingrese el valor de A: ";
	cin >> A;
	cout << "Ingrese el valor de B: ";
	cin >> B;
	cout << "Ingrese el valor de C: ";
	cin >> C;

	cout << "Antes: A = " << A << "  B = " << B << "  C = " << C << endl;

	// Proceso: ordenar A <= B <= C mediante intercambios
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

	// Salida: mostrar valores ordenados
	cout << "Ordenados: A = " << A << "  B = " << B << "  C = " << C << endl;

	return 0;
}
