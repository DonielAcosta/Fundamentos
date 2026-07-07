# Ejercicio 4 — Diferencia entre sentencias de asignación

**Fuente:** EjerciciosSecuencialidad01.pdf

## A = B  vs  A = 'B'

| Sentencia | Tipo de dato | Significado |
|-----------|--------------|-------------|
| `A = B` | Depende del tipo de `A` y `B` | Asigna el **valor** de la variable `B` a `A`. |
| `A = 'B'` | `char` (carácter) | Asigna el **carácter** `'B'` (código ASCII 66) a `A`. No es la variable `B`. |

## A = 7  vs  A = '7'

| Sentencia | Tipo | Significado |
|-----------|------|-------------|
| `A = 7` | numérico (`int`, `float`, etc.) | Asigna el **número** 7. |
| `A = '7'` | `char` | Asigna el **carácter** `'7'` (código ASCII 55), no el número siete. |

## A = verdadero  vs  A = (5 <= 6)

| Sentencia | Significado |
|-----------|-------------|
| `A = verdadero` | En C++ no existe `verdadero` como palabra reservada. Equivalente: `A = true` (tipo `bool`). |
| `A = (5 <= 6)` | Asigna el **resultado lógico** de la comparación. Como 5 ≤ 6, el valor es `true` (1). |

### Ejemplo en C++

```cpp
bool A;
A = true;           // verdadero
A = (5 <= 6);       // true, porque 5 es menor o igual que 6
```
