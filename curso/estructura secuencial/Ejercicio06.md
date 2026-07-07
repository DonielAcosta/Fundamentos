# Ejercicio 6 — Errores en el programa

**Fuente:** EjerciciosSecuencialidad01.pdf

## Código con errores

```cpp
#include<iostream>

int main()
{
    int A, B;
    A=9;
    B=4;
    cin<<A;      // ERROR 1
    A=A*5;
    cout<<A<<endl;
}
```

## Errores detectados

| # | Línea | Error | Corrección |
|---|-------|-------|------------|
| 1 | `cin<<A` | Operador incorrecto: `<<` es de salida | Usar `cin >> A` |
| 2 | Falta `using namespace std;` o prefijo `std::` | `cin` y `cout` no se encuentran | Agregar `using namespace std;` o `std::cin`, `std::cout` |
| 3 | (Opcional) | Falta `return 0;` | Buena práctica en `main` |

## Programa corregido

Ver: `Ejercicio06.cpp`
