#include<iostream>

using namespace std;

int main()
{
	float area, lado, base, altura, radio, h, a, BM, bm;
	const float pi = 3.14;
	int op;
	cout<<"MENU \n"<<endl;
	cout<<"1.- Calcular el area de un triangulo"<<endl;
	cout<<"2.- Calcular el area de un cuadrado"<<endl;
	cout<<"3.- Calcular el area de un rectangulo"<<endl;
	cout<<"4.- Calcular el area de un trapecio"<<endl;
	cout<<"5.- Calcular el area de un circulo"<<endl;
	cout<<"\nIntroduzca la opcion que desea"<<endl;
	cin>>op;
	switch (op)
	{
		case 1:		
			cout<<"Base: ";
			cin>>base;
			cout<<"\nAltura: ";
			cin>>altura;
			cout<<endl;
			area = base*altura/2;
			cout<<"El area del triangulo es: "<<area<<endl;
			break;
		case 2: 
			cout<<"Introduzca el valor del lado"<<endl;
			cin>>lado;
			area = lado*lado;
			cout<<"El area del cuadrado es: "<<area<<endl;
			break;
		case 3: 
			cout<<"Base: ";
			cin>>base;
			cout<<"\nAltura: ";
			cin>>altura;
			cout<<endl;
			area = base*altura;
			cout<<"El area del rectangulo es: "<<area<<endl;
			break;
		case 4: 
			cout<<"Introduzca el valor de base mayor y base menor"<<endl;
			cin>>BM>>bm;
			cout<<"Introduzca el valor de la altura"<<endl;
			cin>>h;
			a = (BM+bm)/2*h;
			cout<<"El area del trapecio es: "<<a<<endl;
			break;
		case 5: 
			cout<<"Introduzca el valor del radio"<<endl;
			cin>>radio;
			area = pi*radio*radio;
			cout<<"El area del circulo es: "<<area<<endl;
			break;
		default: cout<<"Opcion incorrecta, hasta luego"<<endl;
			break;
	}
	return 0;
}
