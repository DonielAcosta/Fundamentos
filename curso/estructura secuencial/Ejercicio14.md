# Ejercicio 14 — Evaluación manual de expresión

**Fuente:** EjerciciosSecuencialidad01.pdf  
**Datos:** `a = 7`, `b = 3` (enteros, división entera)

**Expresión:**

```
(a % 5 + b * 6 / 8 % 3 - 5 / 6 + 4) / (a + b - 4 / 3 % 6 / 9)
```

## Numerador: `(a % 5 + b * 6 / 8 % 3 - 5 / 6 + 4)`

| Paso | Operación | Resultado |
|------|-----------|-----------|
| 1 | `a % 5` → `7 % 5` | 2 |
| 2 | `b * 6` → `3 * 6` | 18 |
| 3 | `18 / 8` (entero) | 2 |
| 4 | `2 % 3` | 2 |
| 5 | `5 / 6` (entero) | 0 |
| 6 | Suma: `2 + 2 - 0 + 4` | **8** |

## Denominador: `(a + b - 4 / 3 % 6 / 9)`

| Paso | Operación | Resultado |
|------|-----------|-----------|
| 1 | `a + b` → `7 + 3` | 10 |
| 2 | `4 / 3` (entero) | 1 |
| 3 | `1 % 6` | 1 |
| 4 | `1 / 9` (entero) | 0 |
| 5 | Resta: `10 - 0` | **10** |

## Resultado final

```
8 / 10 = 0   (división entera)
```

**Respuesta: 0**

Verificación: `Ejercicio14.cpp`
