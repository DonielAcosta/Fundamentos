#include <iostream>
#include <ctime>

using namespace std;

const int f = 4;
const int c = 8;

const float precio = 10;
const float porce = 0.10;

bool HayEspacio(float M[f][c])
{
	for (int i=0; i<f; i++)
	{
		for (int j=0; j<c; j++)
		{
			if (M[i][j]==0)
				{
					return true;
				}
		}
	}
	
	return false;
}

void ReservarUnoAleatorio(float Z1[f][c], float Z2[f][c], float saldo)
{
	int zona, i, j;
	do
	{
		cout<<"Indique la zona 1 o 2"<<endl;
		cin>>zona;
	}while(!(zona == 1 || zona == 2));
	

	if (zona == 1)
	{
		if (HayEspacio(Z1))
		{
			do
			{
				i = rand()%f;
				j = rand()%c;	
			}while(Z1[i][j]!=0);
			
			if (saldo<precio)
			{
				cout<<"Pagar: "<<precio - saldo<<endl;
				Z1[i][j]=precio;
			}
			else
			{
				cout<<"Devolver: "<<saldo - precio<<endl;
				Z1[i][j]=precio;
			}
		}
		else
		{
			cout<<"No hay espacio"<<endl;
		}
	}
	else
	{
		if (HayEspacio(Z2))
		{
			do
			{
				i = rand()%f;
				j = rand()%c;	
			}while(Z2[i][j]!=0);
			
			if (saldo<(precio - porce*precio))
			{
				cout<<"Pagar: "<<(precio - porce*precio) - saldo<<endl;
				Z2[i][j]=(precio - porce*precio);
			}
			else
			{
				cout<<"Devolver: "<<saldo - (precio - porce*precio)<<endl;
				Z2[i][j]=(precio - porce*precio);
			}
		}
		else
		{
			cout<<"No hay espacio"<<endl;
		}
	}
}

void ReservarPosicion(float Z1[f][c], float Z2[f][c], float saldo)
{
	int zona, i, j;
	do
	{
		cout<<"Indique la zona 1 o 2"<<endl;
		cin>>zona;
	}while(!(zona == 1 || zona == 2));	
	
	if (zona == 1)
	{
		if (HayEspacio(Z1))
		{
			do
			{
				cout<<"i: ";
				cin>>i;
				cout<<"\nj: ";
				cin>>j;
			}while(Z1[i][j]!=0);
		
			
			if (saldo<precio)
			{
				cout<<"Pagar: "<<precio - saldo<<endl;
				Z1[i][j]=precio;
			}
			else
			{
				cout<<"Devolver: "<<saldo - precio<<endl;
				Z1[i][j]=precio;
			}
		}
		else
		{
			cout<<"No hay espacio"<<endl;
		}
	}
	else
	{
		if (HayEspacio(Z2))
		{
			do
			{
				cout<<"i: ";
				cin>>i;
				cout<<"\nj: ";
				cin>>j;
			}while(Z1[i][j]!=0);	
					
			if (saldo<(precio - porce*precio))
			{
				cout<<"Pagar: "<<(precio - porce*precio) - saldo<<endl;
				Z2[i][j]=(precio - porce*precio);
			}
			else
			{
				cout<<"Devolver: "<<saldo - (precio - porce*precio)<<endl;
				Z2[i][j]=(precio - porce*precio);
			}
		}
		else
		{
			cout<<"No hay espacio"<<endl;
		}
	}
}


bool verificar(float M[f][c], int ff, int ng, int pos)
{
	for (int i=pos; i<pos+ng; i++)
	{
		if (M[ff][i]!=0)
			return false;
	}
	
	return true;
}

int HayEspacio_(float M[f][c], int ng, int ff)
{
	int pos;
	for (int i=0; i<=c-ng; i++)
	{
		pos = i;
		if (verificar(M,ff,ng,pos))
			return pos;
	}
	pos =-1;
	
	
	return pos;
}

void ReservarVariosFila(float Z1[f][c], float Z2[f][c], float saldo)
{
	int zona, i, j, ng, ff, pos;
	do
	{
		cout<<"Indique la zona 1 o 2"<<endl;
		cin>>zona;
	}while(!(zona == 1 || zona == 2));
	
	//EL CONTROL DEL NUMERO DE PERSONAS LO SE INDICARA SI SE CREE NECESARIO
	cout<<"Indique numero de personas"<<endl;
	cin>>ng;		

	do
	{
		cout<<"Indique la fila"<<endl;
		cin>>ff;		
	}while(ff<0 || ff>f);
	
	if (zona == 1)
	{
		pos = HayEspacio_(Z1,ng,ff);
		if (pos!=-1)
		{
			if (saldo<(precio*ng+(porce*precio)*ng))
			{
				cout<<"Pagar: "<<precio*ng+(porce*precio)*ng - saldo<<endl;
				for (i=pos; i<pos+ng; i++)
					Z1[ff][i]=precio+(porce*precio);
			}
			else
			{
				cout<<"Devolver: "<<saldo - (precio*ng+(porce*precio)*ng)<<endl;
				for (i=pos; i<pos+ng; i++)
					Z1[ff][i]=precio+(porce*precio);
			}
		}
		else
		{
			cout<<"No hay espacio"<<endl;
		}
	}
	else
	{
		pos = HayEspacio_(Z2,ng,ff);
		if (pos!=-1)
		{
			if (saldo<((precio - porce*precio)*ng+(precio - porce*precio)*porce*ng))
			{
				cout<<"Pagar: "<<(precio - porce*precio)*ng+(precio - porce*precio)*porce*ng - saldo<<endl;
				for (i=pos; i<pos+ng; i++)
					Z2[ff][i]=(precio - porce*precio)+(precio - porce*precio)*porce;
			}
			else
			{
				cout<<"Devolver: "<<saldo - ((precio - porce*precio)*ng+(precio - porce*precio)*porce*ng)<<endl;
				for (i=pos; i<pos+ng; i++)
					Z2[ff][i]=(precio - porce*precio)+(precio - porce*precio)*porce;
			}
		}
		else
		{
			cout<<"No hay espacio"<<endl;
		}
	}
}


void ReservarVariosAleatorio(float Z1[f][c], float Z2[f][c], float saldo)
{
	int zona, i, j, ng, ff, pos;
	do
	{
		cout<<"Indique la zona 1 o 2"<<endl;
		cin>>zona;
	}while(!(zona == 1 || zona == 2));
	
	//Sólo se controla si se cree necesario
	cout<<"Indique numero de personas"<<endl;
	cin>>ng;		
	
	if (zona == 1)
	{
		for (ff=0; ff<f; ff++)
		{
			pos = HayEspacio_(Z1,ng,ff);
			if (pos!=-1)
				break;
		}
		
		if (pos!=-1)
		{
			if (saldo<(precio*ng+1*ng))
			{
				cout<<"Pagar: "<<precio*ng+1*ng - saldo<<endl;
				for (i=pos; i<pos+ng; i++)
					Z1[ff][i]=precio+(porce*precio);
			}
			else
			{
				cout<<"Devolver: "<<saldo - (precio*ng+(porce*precio)*ng)<<endl;
				for (i=pos; i<pos+ng; i++)
					Z1[ff][i]=precio+(porce*precio);
			}
		}
		else
		{
			cout<<"No hay espacio"<<endl;
		}
	}
	else
	{
		for (ff=0; ff<f; ff++)
		{
			pos = HayEspacio_(Z2,ng,ff);
			if (pos!=-1)
				break;			
		}
		
		if (pos!=-1)
		{
			if (saldo<((precio - porce*precio)*ng+(precio - porce*precio)*porce*ng))
			{
				cout<<"Pagar: "<<(precio - porce*precio)*ng+(precio - porce*precio)*porce*ng - saldo<<endl;
				for (i=pos; i<pos+ng; i++)
					Z2[ff][i]=(precio - porce*precio)+(precio - porce*precio)*porce;
			}
			else
			{
				cout<<"Devolver: "<<saldo - ((precio - porce*precio)*ng+(precio - porce*precio)*porce*ng)<<endl;
				for (i=pos; i<pos+ng; i++)
					Z2[ff][i]=(precio - porce*precio)+(precio - porce*precio)*porce;
			}
		}
		else
		{
			cout<<"No hay espacio"<<endl;
		}

	}
	
	
}
																															


void InicializarEnCero(float tab[f][c])
{
	for (int i=0; i<f; i++)
	{
		for (int j=0; j<c; j++)
			tab[i][j]=0;
		{
		}
	}
	
}

void ImprimirSala(float Z1[f][c], float Z2[f][c])
{
	system("cls");
	cout<<"SALA:"<<endl;
	
	cout<<"Zona 2"<<endl;
	for (int i=0; i<f; i++)
	{
		for (int j=0; j<c; j++)
		{
			cout<<Z2[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Zona 1"<<endl;
	for (int i=0; i<f; i++)
	{
		for (int j=0; j<c; j++)
		{
			cout<<Z1[i][j]<<"\t";
		}
		cout<<endl;
	}
}

bool HayCliente()
{
	char opcion;
	cout<<"Hay otro cliente?"<<endl;
	cout<<"S -Si \t N -No"<<endl;
	cin>>opcion;
	
	if (opcion == 'S')
		return true;
	else
		return false;
	
}

void OfrecerOpciones()
{
	//Pudiese agregarse un do-while ara controlar que el usuario no se equivoque en la opción
	//Sin embargo esto puede controlarse en el default del switch. 
	cout<<"1.- Reservar asiento."<<endl;
	cout<<"2.- Cancelar reservacion."<<endl;
	cout<<"3.- Cambiar asiento"<<endl;
	cout<<"Presione una opcion"<<endl;
}

void MenuReserva()
{
	cout<<"1.- Una reservacion aleatoria."<<endl;
	cout<<"2.- Una reservacion aleatoria grupal"<<endl;
	cout<<"3.- Una reservacion indicando la posicion."<<endl;
	cout<<"4.- Una reservacion grupal indicando la fila"<<endl;
	cout<<"Indique una opcion"<<endl;
}

void Reservar(float Z1[f][c], float Z2[f][c], float saldo)
{
	int op;
	MenuReserva();
	cin>>op;
	
	switch(op)
	{
		case 1: ReservarUnoAleatorio(Z1,Z2,saldo);
		break;
		
		case 2: ReservarVariosAleatorio(Z1,Z2,saldo);
		break;
		
		case 3: ReservarPosicion(Z1,Z2,saldo);
		break;
		
		case 4: ReservarVariosFila(Z1,Z2,saldo);
		break;
		
		default: cout<<"Opcion incorrecta"<<endl;
		break;
	}
}

void Cancelar(float Z1[f][c], float Z2[f][c])
{
	int zona, fila, columna;
	do
	{
		cout<<"Indique la zona 1 o 2"<<endl;
		cin>>zona;
	}while(!(zona == 1 || zona == 2));
	
	if (zona==1)
	{
		do
		{
			cout<<"\nfila: ";
			cin>>fila;
			cout<<"\ncolumna: ";
			cin>>columna;						
		}while(!(Z1[fila][columna]!=0));
		
		if (Z1[fila][columna]!=0)
		{
			cout<<"Devolver: "<<Z1[fila][columna]<<endl;
			Z1[fila][columna]=0;
		}
		else
		{
			cout<<"Error en los datos"<<endl;
		}
	}
	else
	{
		do
		{
			cout<<"\nfila: ";
			cin>>fila;
			cout<<"\ncolumna: ";
			cin>>columna;						
		}while(!(Z1[fila][columna]!=0));
			
		if (Z2[fila][columna]!=0)
		{
			cout<<"Devolver: "<<Z2[fila][columna]<<endl;
			Z2[fila][columna]=0;
		}
		else
		{
			cout<<"Error en los datos"<<endl;
		}
	}
}

float Cancelar_(float Z1[f][c], float Z2[f][c])
{
	int zona, fila, columna;
	float saldo;

	do
	{
		cout<<"Indique la zona 1 o 2"<<endl;
		cin>>zona;
	}while(!(zona == 1 || zona == 2));
	
	if (zona==1)
	{
		do
		{
			cout<<"\nfila: ";
			cin>>fila;
			cout<<"\ncolumna: ";
			cin>>columna;						
		}while(!(Z1[fila][columna]!=0));
			
		if (Z1[fila][columna]!=0)
		{
			saldo =Z1[fila][columna];
			Z1[fila][columna]=0;
		}
		else
		{
			saldo = 0;
		}
	}
	else
	{
		do
		{
			cout<<"\nfila: ";
			cin>>fila;
			cout<<"\ncolumna: ";
			cin>>columna;						
		}while(!(Z1[fila][columna]!=0));
			
		if (Z2[fila][columna]!=0)
		{
			saldo = Z2[fila][columna];
			Z2[fila][columna]=0;
		}
		else
		{
			saldo = 0;
		}
	}
	
	return saldo;
}

void Cambiar(float Z1[f][c], float Z2[f][c])
{
	float saldo = 0;
	saldo = Cancelar_(Z1,Z2);
	Reservar(Z1,Z2,saldo);
	
}

void AtenderUsuario(float Z1[f][c], float Z2[f][c])
{
	int op;
	OfrecerOpciones();
	cin>>op;
	
	switch (op)
	{
		case 1: Reservar(Z1, Z2, 0);
		break;
		
		case 2: Cancelar(Z1, Z2);
		break;
		
		case 3: Cambiar(Z1, Z2);
		break;
		
		default: cout<<"No tenemos ese servicio"<<endl;
		break;
	}
}

int NAO(float Z[f][c])
{
	int contador =0;
	for (int i=0; i<f; i++)
	{
		for (int j=0; j<c; j++)
		{
			if (Z[i][j]!=0)
				contador++;
		}
	}
	return contador;
}

float TOTAL(float Z[f][c])
{
	float suma=0;
	for (int i=0; i<f; i++)
	{
		for (int j=0; j<c; j++)
		{
			suma = suma + Z[i][j];
		}
	}
	return suma;
}
void ImprimirEstadisticas(float Z1[f][c], float Z2[f][c])
{
	cout<<"ZONA 1"<<endl;
	cout<<"Numero de asientos ocupados: "<<NAO(Z1)<<endl;
	cout<<"Numero de asientos vacios: "<<32-NAO(Z1)<<endl;
	cout<<"Total recaudado: "<<TOTAL(Z1)<<endl;

	cout<<"ZONA 2"<<endl;
	cout<<"Numero de asientos ocupados: "<<NAO(Z2)<<endl;
	cout<<"Numero de asientos vacios: "<<32-NAO(Z2)<<endl;
	cout<<"Total recaudado: "<<TOTAL(Z2)<<endl;
	
	cout<<"TOTAL SALA: "<<TOTAL(Z1)+TOTAL(Z2)<<endl;
}

