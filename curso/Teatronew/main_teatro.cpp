#include "Metodos.hpp"

int main() 
{
	srand(time(NULL));
	float zona1[f][c];
	float zona2[f][c];
	


	
	InicializarEnCero(zona1);
	InicializarEnCero(zona2);
	ImprimirSala(zona1,zona2);
	while (HayCliente())
	{
		system("cls");
		AtenderUsuario(zona1,zona2);
		system("pause");
		ImprimirSala(zona1,zona2);
		system("pause");
		
	}
		
	ImprimirEstadisticas(zona1,zona2);
		
	
	
	return 0;
}
