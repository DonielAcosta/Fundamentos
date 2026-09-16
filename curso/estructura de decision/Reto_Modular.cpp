#include<iostream>

using namespace std;

void Ofrecer_menu();
void calAreaTriangulo();
void calAreaCua();
void AreaRectangulo();
void Trapecio_area();
void Acirculo();

int main()
{
	int op;
	Ofrecer_menu();
	cin>>op;
	switch (op)
	{
		case 1:	calAreaTriangulo();
			break;
		case 2: calAreaCua();
			break;
		case 3: AreaRectangulo();
			break;
		case 4: Trapecio_area();
			break;
		case 5: Acirculo();
			break;
		default: cout<<"Opcion incorrecta, hasta luego"<<endl;
			break;
	}
	return 0;
}


void Ofrecer_menu()
{
	cout<<"MENU \n"<<endl;
	cout<<"1.- Calcular el area de un triangulo"<<endl;
	cout<<"2.- Calcular el area de un cuadrado"<<endl;
	cout<<"3.- Calcular el area de un rectangulo"<<endl;
	cout<<"4.- Calcular el area de un trapecio"<<endl;
	cout<<"5.- Calcular el area de un circulo"<<endl;
	cout<<"\nIntroduzca la opcion que desea"<<endl;
}

void calAreaTriangulo()
{
	float base, altura, area;
	cout<<"Base: ";
	cin>>base;
	cout<<"\nAltura: ";
	cin>>altura;
	cout<<endl;
	area = base*altura/2;
	cout<<"El area del triangulo es: "<<area<<endl;
	
}


void calAreaCua()
{
	float lado, area;
	cout<<"Introduzca el valor del lado"<<endl;
	cin>>lado;
	area = lado*lado;
	cout<<"El area del cuadrado es: "<<area<<endl;
}
void AreaRectangulo()
{
	float base, altura, area;
	cout<<"Base: ";
	cin>>base;
	cout<<"\nAltura: ";
	cin>>altura;
	cout<<endl;
	area = base*altura;
	cout<<"El area del rectangulo es: "<<area<<endl;
}
void Trapecio_area()
{
	float BM, bm, h, a;
	cout<<"Introduzca el valor de base mayor y base menor"<<endl;
	cin>>BM>>bm;
	cout<<"Introduzca el valor de la altura"<<endl;
	cin>>h;
	a = (BM+bm)/2*h;
	cout<<"El area del trapecio es: "<<a<<endl;
}
void Acirculo()
{
	float radio, area;
	const float pi = 3.14;
	cout<<"Introduzca el valor del radio"<<endl;
	cin>>radio;
	area = pi*radio*radio;
	cout<<"El area del circulo es: "<<area<<endl;
}
