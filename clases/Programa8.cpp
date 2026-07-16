#include<iostream>
using namespace std;

/*
 * Recetas de masa para arepas.
 * fecha: 12/06/2026
 *
 * Diseñar un programa que le ofrezca a un usuario los algoritmos de
 * preparación de tres tipos de masa para arepas: normal, dulce y tuneada.
 *
 * Conceptos: programación modular, procedimientos y apilamiento de
 * decisiones simples.
 * Autor: Ing. Doniel Acosta
 */
// Declaración de funciones como javascript
void tipos_masa();
void receta_normal(int porciones);
void receta_dulce(int porciones);
void receta_tuneada(int porciones);
void error();
int pedir_porciones();

void tipos_masa()
{
	cout << "Menu\n\n";
	cout << "\tA. Masa normal" << endl;
	cout << "\tB. Masa dulce" << endl;
	cout << "\tC. Masa tuneada\n" << endl;
}

int pedir_porciones()
{
	int porciones;

	cout << "Cuantas porciones desea preparar? ";
	cin >> porciones;

	if (porciones < 1)
		porciones = 1;

	return porciones;
}

void receta_normal(int porciones)
{
	cout << "\n--- Receta masa normal (" << porciones << " porcion/es) ---\n" << endl;
	cout << "\tAgregar " << 1 * porciones << " porcion(es) de harina" << endl;
	cout << "\tAgregar " << 3 * porciones << " porcion(es) de agua" << endl;
	cout << "\tAgregar " << 1 * porciones << " pizca(s) de sal" << endl;
}

void receta_dulce(int porciones)
{
	cout << "\n--- Receta masa dulce (" << porciones << " porcion/es) ---\n" << endl;
	cout << "\tAgregar " << 1 * porciones << " porcion(es) de harina" << endl;
	cout << "\tAgregar " << 3 * porciones << " porcion(es) de agua" << endl;
	cout << "\tAgregar " << 1 * porciones << " pizca(s) de sal" << endl;
	cout << "\tAgregar " << 1 * porciones << " cucharada(s) de azucar" << endl;
}

void receta_tuneada(int porciones)
{
	cout << "\n--- Receta masa tuneada (" << porciones << " porcion/es) ---\n" << endl;
	cout << "\tAgregar " << 1 * porciones << " porcion(es) de harina" << endl;
	cout << "\tAgregar " << 3 * porciones << " porcion(es) de agua" << endl;
	cout << "\tAgregar " << 1 * porciones << " pizca(s) de sal" << endl;
	cout << "\tAgregar " << 0.25 * porciones << " cucharada(s) de azucar" << endl;
	cout << "\tAgregar " << 1 * porciones << " cucharada(s) de mayonesa" << endl;
	cout << "\tAgregar " << 2 * porciones << " cucharada(s) de leche en polvo" << endl;
}

void error()
{
	cout << "Error en su opcion" << endl;
}

int main()
{
	char respuesta;
	int porciones;

	tipos_masa();

	cout << "Que tipo de masa quiere? ";
	cin >> respuesta;

	porciones = pedir_porciones();

	if (respuesta == 'A' || respuesta == 'a')
		receta_normal(porciones);
	else if (respuesta == 'B' || respuesta == 'b')
		receta_dulce(porciones);
	else if (respuesta == 'C' || respuesta == 'c')
		receta_tuneada(porciones);
	else
		error();

	return 0;
}
