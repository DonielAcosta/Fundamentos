#include<iostream>
using namespace std;

/*
Programa que solicita dos valores enteros y muestra su suma, resta, multiplicación y división.
fecha: 05/06/2026
*/

int main()
{
	int a,b,c;
	char c1, c2;
	float x, y;
	bool p;
	a = b = c = 5;
	c1 = c2 = 65;
	x = 6;
	y = 8;
	c1 = c1 + c;
	x = x / 8;
	a = ( a * b -c ) % 7;
	b = c - a;
	c = 8;
	c2 = c1 + c;
	p = (a + 6) <= (b - 5);
	x = 7 * a - y;
	cout 	<< " a = " << a 
			<< " b = " << b
			<< " c = " << c
			<< " c1 = " << c1
			<< " c2 = " << c2
			<< " x = " << x
			<< " y = " << y
			<< " p = " << p;
	
	
	return 0;
}
