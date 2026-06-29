#include<iostream>
using namespace std;

/*
 *  Recetas de masa para arepas.
 * fecha: 12/06/2026
 *
 * Diseñar un programa que le ofrezca a un usuario los algoritmos de
 * preparación de tres tipos de masa para arepas: normal, dulce y tuneada.
 *
 * Conceptos: programación modular, procedimientos y apilamiento de
 * decisiones simples.
 */

// Procedimientos
void tipos_masa();
void receta_normal();
void receta_dulce();
void receta_tuneada();
void error();

void tipos_masa()
{
	cout << "Menu\n\n";
	cout << "\tA. Masa normal" << endl;
	cout << "\tB. Masa dulce" << endl;
	cout << "\tC. Masa tuneada\n" << endl;
}

void receta_normal()
{
	cout << "\tAgregar una porcion de harina" << endl;
	cout << "\tAgregar tres porciones de agua" << endl;
	cout << "\tAgregar una pizca de sal" << endl;
}

void receta_dulce()
{
	cout << "\tAgregar una porcion de harina" << endl;
	cout << "\tAgregar tres porciones de agua" << endl;
	cout << "\tAgregar una pizca de sal" << endl;
	cout << "\tAgregar una cucharada de azucar" << endl;
}

void receta_tuneada()
{
	cout << "\tAgregar una porcion de harina" << endl;
	cout << "\tAgregar tres porciones de agua" << endl;
	cout << "\tAgregar una pizca de sal" << endl;
	cout << "\tAgregar un cuarto de cucharada de azucar" << endl;
	cout << "\tAgregar una cucharada de mayonesa" << endl;
	cout << "\tAgregar dos cucharadas de leche en polvo" << endl;
}

void error()
{
	cout << "Error en su opcion" << endl;
}

int main()
{
	char respuesta;

	// Salida: mostrar menú de opciones
	tipos_masa();

	// Entrada: leer opción del usuario
	cout << "Que tipo de masa quiere? ";
	cin >> respuesta;

	// Proceso: apilamiento de decisiones simples
	if (respuesta == 'A' || respuesta == 'a'){
		receta_normal();
	}else if (respuesta == 'B' || respuesta == 'b'){
		receta_dulce();
	}else if (respuesta == 'C' || respuesta == 'c'){
		receta_tuneada();
	}else{
		error();
	}

	return 0;
}
