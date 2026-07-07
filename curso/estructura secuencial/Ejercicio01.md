# Ejercicio 1 — Valores de variables

**Fuente:** EjerciciosSecuencialidad01.pdf  
**Datos:** `a` es variable real (`float`), `b` es variable entera (`int`).

## Expresiones y resultados

| Expresión | Variable | Resultado | Notas |
|-----------|----------|-----------|-------|
| `a = 15/12` | a | **1.25** | División real |
| `b = 15/12` | b | **1** | División entera |
| `b = 15 % 12` | b | **3** | Resto de la división |
| `a = 15*14 - 3*7` | a | **189** | 210 − 21 |
| `b = -4*5*2` | b | **-40** | |
| `b = (24+2*6) % 4` | b | **0** | (24+12) % 4 = 36 % 4 |
| `a = 3+4*(8*(4-(9+3)/6))` | a | **67** | Ver desarrollo abajo |

## Desarrollo del último caso

```
3 + 4 * (8 * (4 - (9+3)/6))
= 3 + 4 * (8 * (4 - 12/6))
= 3 + 4 * (8 * (4 - 2))
= 3 + 4 * (8 * 2)
= 3 + 4 * 16
= 3 + 64
= 67
```

Verificación en código: `Ejercicio01.cpp`
