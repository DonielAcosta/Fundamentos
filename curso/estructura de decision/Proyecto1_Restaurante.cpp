#include<iostream>
using namespace std;

/*
 * Proyecto 1: El restaurante.
 *
 * Diseñar un programa que permita a un usuario elegir de un sistema de menús
 * los platos que desea comer para su almuerzo.
 *
 * El restaurante ofrece: entradas, platos fuertes, bebidas y postres.
 * El usuario puede pedir a lo sumo una opción de cada menú.
 * Al final se muestra el pedido con montos y el total a pagar.
 * Luego puede aceptar, rechazar o volver a pedir.
 *
 * Conceptos: programación modular, menús y decisiones.
 * Autor: Ing. Doniel Acosta
 */

void menu_entradas();
void menu_fuertes();
void menu_bebidas();
void menu_postres();
void menu_confirmacion();
void error();

float precio_entrada(int op);
float precio_fuerte(int op);
float precio_bebida(int op);
float precio_postre(int op);

void nombre_entrada(int op);
void nombre_fuerte(int op);
void nombre_bebida(int op);
void nombre_postre(int op);

void mostrar_pedido(int e, int f, int b, int p, float total);

void menu_entradas()
{
	cout << "\n--- ENTRADAS ---\n" << endl;
	cout << "\t1. Tequenos         $3.50" << endl;
	cout << "\t2. Ensalada Cesar   $4.00" << endl;
	cout << "\t3. Sopa del dia     $3.00" << endl;
	cout << "\t0. Sin entrada" << endl;
}

void menu_fuertes()
{
	cout << "\n--- PLATOS FUERTES ---\n" << endl;
	cout << "\t1. Pabellon criollo $8.50" << endl;
	cout << "\t2. Pollo a la plancha $7.00" << endl;
	cout << "\t3. Pasta bolognesa  $6.50" << endl;
	cout << "\t0. Sin plato fuerte" << endl;
}

void menu_bebidas()
{
	cout << "\n--- BEBIDAS ---\n" << endl;
	cout << "\t1. Refresco         $2.00" << endl;
	cout << "\t2. Jugo natural     $2.50" << endl;
	cout << "\t3. Agua             $1.00" << endl;
	cout << "\t0. Sin bebida" << endl;
}

void menu_postres()
{
	cout << "\n--- POSTRES ---\n" << endl;
	cout << "\t1. Quesillo         $3.00" << endl;
	cout << "\t2. Helado           $2.50" << endl;
	cout << "\t3. Torta de chocolate $3.50" << endl;
	cout << "\t0. Sin postre" << endl;
}

void menu_confirmacion()
{
	cout << "\n--- CONFIRMACION ---\n" << endl;
	cout << "\tA. Aceptar pedido" << endl;
	cout << "\tR. Rechazar pedido" << endl;
	cout << "\tV. Volver a pedir" << endl;
}

void error()
{
	cout << "Error en su opcion" << endl;
}

float precio_entrada(int op)
{
	if (op == 1)
		return 3.50;
	else if (op == 2)
		return 4.00;
	else if (op == 3)
		return 3.00;
	else
		return 0;
}

float precio_fuerte(int op)
{
	if (op == 1)
		return 8.50;
	else if (op == 2)
		return 7.00;
	else if (op == 3)
		return 6.50;
	else
		return 0;
}

float precio_bebida(int op)
{
	if (op == 1)
		return 2.00;
	else if (op == 2)
		return 2.50;
	else if (op == 3)
		return 1.00;
	else
		return 0;
}

float precio_postre(int op)
{
	if (op == 1)
		return 3.00;
	else if (op == 2)
		return 2.50;
	else if (op == 3)
		return 3.50;
	else
		return 0;
}

void nombre_entrada(int op)
{
	if (op == 1)
		cout << "Tequenos";
	else if (op == 2)
		cout << "Ensalada Cesar";
	else if (op == 3)
		cout << "Sopa del dia";
	else
		cout << "(ninguna)";
}

void nombre_fuerte(int op)
{
	if (op == 1)
		cout << "Pabellon criollo";
	else if (op == 2)
		cout << "Pollo a la plancha";
	else if (op == 3)
		cout << "Pasta bolognesa";
	else
		cout << "(ninguno)";
}

void nombre_bebida(int op)
{
	if (op == 1)
		cout << "Refresco";
	else if (op == 2)
		cout << "Jugo natural";
	else if (op == 3)
		cout << "Agua";
	else
		cout << "(ninguna)";
}

void nombre_postre(int op)
{
	if (op == 1)
		cout << "Quesillo";
	else if (op == 2)
		cout << "Helado";
	else if (op == 3)
		cout << "Torta de chocolate";
	else
		cout << "(ninguno)";
}

void mostrar_pedido(int e, int f, int b, int p, float total)
{
	cout << "\n========== SU PEDIDO ==========" << endl;

	cout << "Entrada:      ";
	nombre_entrada(e);
	cout << "  $" << precio_entrada(e) << endl;

	cout << "Plato fuerte: ";
	nombre_fuerte(f);
	cout << "  $" << precio_fuerte(f) << endl;

	cout << "Bebida:       ";
	nombre_bebida(b);
	cout << "  $" << precio_bebida(b) << endl;

	cout << "Postre:       ";
	nombre_postre(p);
	cout << "  $" << precio_postre(p) << endl;

	cout << "--------------------------------" << endl;
	cout << "TOTAL A PAGAR: $" << total << endl;
	cout << "================================" << endl;
}

int main()
{
	int entrada, fuerte, bebida, postre;
	char confirmacion;
	float total;
	bool seguir;

	seguir = true;

	cout << "=== RESTAURANTE EL ALMUERZO ===" << endl;

	while (seguir)
	{
		menu_entradas();
		cout << "Elija entrada: ";
		cin >> entrada;
		if (entrada < 0 || entrada > 3)
		{
			error();
			entrada = 0;
		}

		menu_fuertes();
		cout << "Elija plato fuerte: ";
		cin >> fuerte;
		if (fuerte < 0 || fuerte > 3)
		{
			error();
			fuerte = 0;
		}

		menu_bebidas();
		cout << "Elija bebida: ";
		cin >> bebida;
		if (bebida < 0 || bebida > 3)
		{
			error();
			bebida = 0;
		}

		menu_postres();
		cout << "Elija postre: ";
		cin >> postre;
		if (postre < 0 || postre > 3)
		{
			error();
			postre = 0;
		}

		total = precio_entrada(entrada) + precio_fuerte(fuerte)
			  + precio_bebida(bebida) + precio_postre(postre);

		mostrar_pedido(entrada, fuerte, bebida, postre, total);

		menu_confirmacion();
		cout << "Que desea hacer? ";
		cin >> confirmacion;

		if (confirmacion == 'A' || confirmacion == 'a')
		{
			cout << "\nPedido aceptado. Gracias por su compra!" << endl;
			seguir = false;
		}
		else if (confirmacion == 'R' || confirmacion == 'r')
		{
			cout << "\nPedido rechazado. Hasta luego." << endl;
			seguir = false;
		}
		else if (confirmacion == 'V' || confirmacion == 'v')
		{
			cout << "\nVolvamos a armar su pedido...\n" << endl;
		}
		else
		{
			error();
			seguir = false;
		}
	}

	return 0;
}
