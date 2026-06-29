#include<iostream>
using namespace std;

/*
 * Recto 2: día del año (sin estructuras de decisión).
 * fecha: 17/06/2026
 *
 * Diseñe un programa que lea una fecha en día y mes y muestre por consola
 * qué día del año es, sin usar estructuras de decisión.
 *
 * Enfoque: días acumulados por mes y selección mediante expresiones
 * booleanas (true = 1, false = 0).
 * Año no bisiesto (febrero = 28 días).
 */

int main()
{
	// Declaración de variables
	int AcumEnero, AcumFebrero, AcumMarzo, AcumAbril, AcumMayo, AcumJunio;
	int AcumJulio, AcumAgosto, AcumSeptiembre, AcumOctubre, AcumNoviembre, AcumDiciembre;
	int m, d;
	int usarAcumulado1, usarAcumulado2, usarAcumulado3, usarAcumulado4;
	int usarAcumulado5, usarAcumulado6, usarAcumulado7, usarAcumulado8;
	int usarAcumulado9, usarAcumulado10, usarAcumulado11, usarAcumulado12;
	int sumaTotal;

	// Inicialización: días acumulados al inicio de cada mes
	AcumEnero = 0;
	AcumFebrero = 31;
	AcumMarzo = 59;
	AcumAbril = 90;
	AcumMayo = 120;
	AcumJunio = 151;
	AcumJulio = 181;
	AcumAgosto = 212;
	AcumSeptiembre = 243;
	AcumOctubre = 273;
	AcumNoviembre = 304;
	AcumDiciembre = 334;

	// Entrada: lectura de mes y día
	cout << "Mes requerido: ";
	cin >> m;
	cout << "Dia requerido: ";
	cin >> d;

	// Proceso: seleccionar acumulado del mes sin usar if
	// (m == n) vale 1 si coincide, 0 si no
	usarAcumulado1  = (m == 1)  * AcumEnero;
	usarAcumulado2  = (m == 2)  * AcumFebrero;
	usarAcumulado3  = (m == 3)  * AcumMarzo;
	usarAcumulado4  = (m == 4)  * AcumAbril;
	usarAcumulado5  = (m == 5)  * AcumMayo;
	usarAcumulado6  = (m == 6)  * AcumJunio;
	usarAcumulado7  = (m == 7)  * AcumJulio;
	usarAcumulado8  = (m == 8)  * AcumAgosto;
	usarAcumulado9  = (m == 9)  * AcumSeptiembre;
	usarAcumulado10 = (m == 10) * AcumOctubre;
	usarAcumulado11 = (m == 11) * AcumNoviembre;
	usarAcumulado12 = (m == 12) * AcumDiciembre;

	sumaTotal = usarAcumulado1 + usarAcumulado2 + usarAcumulado3 + usarAcumulado4 +
				usarAcumulado5 + usarAcumulado6 + usarAcumulado7 + usarAcumulado8 +
				usarAcumulado9 + usarAcumulado10 + usarAcumulado11 + usarAcumulado12 + d;

	// Salida: mostrar día del año
	cout << "Total de dias en el anio: " << sumaTotal << endl;

	return 0;
}
