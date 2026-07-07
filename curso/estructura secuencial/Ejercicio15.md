# Ejercicio 15 — Evaluación manual de expresión

**Fuente:** EjerciciosSecuencialidad01.pdf  
**Datos:** `a = 2`, `b = -2`

**Expresión:**

```
(a % 5 + b * 6 / 8 % 3 - 5 / 6.0 + 4) / (4 / 3 % 6 / 9.4)
```

## Numerador: `(a % 5 + b * 6 / 8 % 3 - 5 / 6.0 + 4)`

| Paso | Operación | Resultado |
|------|-----------|-----------|
| 1 | `a % 5` → `2 % 5` | 2 |
| 2 | `b * 6` → `-2 * 6` | -12 |
| 3 | `-12 / 8` (entero) | -1 |
| 4 | `-1 % 3` | -1 |
| 5 | `5 / 6.0` | 0.833... |
| 6 | Suma: `2 + (-1) - 0.833... + 4` | **≈ 4.167** |

## Denominador: `(4 / 3 % 6 / 9.4)`

| Paso | Operación | Resultado |
|------|-----------|-----------|
| 1 | `4 / 3` (entero) | 1 |
| 2 | `1 % 6` | 1 |
| 3 | `1 / 9.4` | ≈ 0.1064 |

## Resultado final

```
4.167 / 0.1064 ≈ 39.17
```

**Respuesta: ≈ 39.17** (verificado con `Ejercicio15.cpp`)

Verificación: `Ejercicio15.cpp`
