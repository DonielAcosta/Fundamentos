# Guía 3 - Ejercicio 11 — Corrida en frío

**Fuente:** Ejercicios_Funciones.pdf (Problema 7)

## Programa

Ver: `Guia3_Ejercicio11.cpp`

## Valores iniciales

| Variable | Valor |
|----------|-------|
| a | 7 |
| b | 3 |

## Corrida en frío — función `intercambiar(a, b)`

| Paso | Acción | a | b | aux |
|------|--------|---|---|-----|
| 0 | Estado inicial en `main` | 7 | 3 | — |
| 1 | Entra a `intercambiar`, `aux = a` | 7 | 3 | 7 |
| 2 | `a = b` | 3 | 3 | 7 |
| 3 | `b = aux` | 3 | 7 | 7 |
| 4 | Retorna a `main` | 3 | 7 | — |

## Salida esperada

```
Paso 0 - Antes: a = 7, b = 3
Paso final - Despues: a = 3, b = 7
```

## Conclusión

La función `intercambiar` usa una variable auxiliar y parámetros por referencia (`&`) para modificar los valores originales de `a` y `b` en `main`.
