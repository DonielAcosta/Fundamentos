# Guía 3 - Ejercicio 13
# Diseño modular para los problemas anteriores

Propuesta de módulos (funciones) para los ejercicios 2 al 12.

## Ejercicio 2 — Eureka
- `bool estaEnRango(int n, int min, int max)` → verdadero si `n` está en [min, max]

## Ejercicio 3 — Impar
- `bool esImpar(int n)` → verdadero si `n % 2 != 0`

## Ejercicios 4, 5, 6 y 7 — Caracteres
- `bool esIgual(char c, char esperado)`
- `bool esTresOa(char c)` → `'3'` o `'A'`
- `bool entreAyF(char c)` → `c > 'a' && c < 'f'`

## Ejercicio 8 — Mayor de edad
- `bool esMayorDeEdad(int edad)` → `edad >= 18`

## Ejercicio 9 — Edad exacta
- `int diasDelMes(int mes, int anio)`
- `void calcularEdad(int dN, int mN, int aN, int dA, int mA, int aA, int &anios, int &meses, int &dias)`

## Ejercicio 10 — Mes
- `void nombreMes(int mes)` → imprime el nombre según el número

## Ejercicio 11 — Día
- `void nombreDia(int dia)` → imprime el día de la semana

## Ejercicio 12 — Pago del trabajador
- `int aMinutos(int hora, int minuto)`
- `int minutosTrabajados(int hEnt, int mEnt, int hSal, int mSal)`
- `int calcularPago(int minutos)` → aplica tarifa normal y extra

La implementación modular de ejemplo está en `Ejercicio13.cpp` (pago del trabajador, el más completo).
