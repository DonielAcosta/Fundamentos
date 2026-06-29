#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

/*
 * Ternas equiláteras.
 * fecha: 26/06/2026
 *
 * Diseñar un programa que genere ternas de números hasta encontrar una
 * que pueda definir un triángulo equilátero.
 *
 * Conceptos: funciones, ciclo while y números aleatorios (rand, srand).
 *
 * Pendiente:
 *   - Modificar el while para que pare al encontrar 10 equiláteros.
 *   - Generar 10000 ternas e indicar cuántas fueron equiláteros, isósceles y escalenos.
 */

void generar_ternas(int &l1, int &l2, int &l3);
bool es_equilatero(int &l1, int &l2, int &l3);

void generar_ternas(int &l1, int &l2, int &l3)
{
	l1 = rand() % 11 + 1;
	l2 = rand() % 11 + 1;
	l3 = rand() % 11 + 1;
	cout << l1 << " " << l2 << " " << l3 << endl;
}

bool es_equilatero(int &l1, int &l2, int &l3)
{
	return l1 == l2 && l2 == l3 && l1 == l3;
}

int main()
{
	int l1, l2, l3;
	int contador = 1;

	// Inicialización: semilla para números aleatorios
	srand(time(NULL));

	// Proceso: generar ternas hasta encontrar un triángulo equilátero
	cout << contador << " ";
	generar_ternas(l1, l2, l3);

	while (!es_equilatero(l1, l2, l3)) {
		cout << contador++ << " ";
		generar_ternas(l1, l2, l3);
	}

	// Salida: intento en que se encontró la terna
	cout << "Terna equilatera encontrada en el intento " << contador << endl;

	return 0;
}
