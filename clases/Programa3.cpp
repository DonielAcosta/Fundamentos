#include<iostream>
using namespace std;

/*
 * Programa secuencial que calcula el área de un triángulo.
 * fecha: 05/06/2026
 */

/* --------------------------------------------------------------------------
 * ANÁLISIS
 * --------------------------------------------------------------------------
 * Análisis EPS (Entrada - Proceso - Salida)
 *
 * Especificación de parámetros:
 *   b : float  -> base del triángulo
 *   h : float  -> altura del triángulo
 *   A : float  -> área del triángulo
 *
 * Algoritmo general (preciso, definido y finito):
 *   Leer b y h, calcular b * h / 2 y asignarlo a A.
 *   Finalmente mostrar A.
 * -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * PSEUDOCÓDIGO - Algoritmo específico
 * --------------------------------------------------------------------------
 * 1. A, b, h : float
 * 2. A = b = h = 0
 * 3. Imprimir "Indique los datos"
 * 4. Leer b, h
 * 5. A = b * h / 2
 * 6. Imprimir A
 * -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
 * CICLO DE DESARROLLO
 * --------------------------------------------------------------------------
 * 1. Código      -> C++
 * 2. Compilar
 * 3. Ejecutar
 * 4. Depurar
 * 5. Verificar
 * 6. Documentar
 * 7. Mantener
 * -------------------------------------------------------------------------- */

int main()
{
	// Declaración de variables
	float A, b, h;

	// Inicialización de variables
	A = b = h = 0;

	// Entrada: lectura de base y altura
	cout << "Indique la base ";
	cin >> b;
	cout << "Indique la altura ";
	cin >> h;

	// Proceso: cálculo del área
	A = b * h / 2;

	// Salida: mostrar resultado
	cout << "A = " << A;

	return 0;
}
