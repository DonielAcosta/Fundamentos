#include<iostream>
#include<cmath>
using namespace std;

/*
 * Programa 14 - Área de un triángulo por sus tres lados.
 *
 * Diseñe un programa que calcule el área de un triángulo dados sus tres lados.
 *
 * Conceptos: programación modular, paso por referencia, funciones que retornan
 * valor booleano y fórmula de Herón.
 */

// Procedimientos y funciones
void leer(float &l1, float &l2, float &l3);
bool desigualdad_triangula(float a, float b, float c);

void leer(float &l1, float &l2, float &l3)
{
	cout << "Introduzca los tres lados: ";
	cin >> l1 >> l2 >> l3;
}

bool desigualdad_triangula(float a, float b, float c)
{
	return a + b > c && a + c > b && b + c > a;
}

int main()
{
	float a, b, c, A, P, S, aux;

	// Inicialización
	a = b = c = 0;

	// Entrada: lectura de los tres lados
	leer(a, b, c);

	// Proceso: validar triángulo y calcular área (Herón)
	if (desigualdad_triangula(a, b, c)) {
		P = a + b + c;
		S = P / 2;
		aux = S * (S - a) * (S - b) * (S - c);
		A = sqrt(aux);
		cout << "Area = " << A << endl;
	}
	else {
		cout << "Error en los lados" << endl;
	}

	return 0;
}
