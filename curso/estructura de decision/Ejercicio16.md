# Guía 3 - Ejercicio 16 (Corrida en frío)

```cpp
int a = 6;
int b = '2';        // valor ASCII de '2' = 50
char c = 'e';
char d = 't';
bool aux = true;
bool A = true && (5 < 6 == true) && false;
```

## Evaluación de `A`

1. `5 < 6` → `true`
2. `true == true` → `true`
3. `true && true && false` → `false`
4. **A = false**

## Decisión

`if (aux || A)` → `true || false` → entra al `if`:

- `a = b + 5` → `50 + 5` → **a = 55**
- imprime: `hola`

## Salidas

```
hola
5550et10
A= 0
```

Explicación de la segunda línea (`cout << a << b << c << d << aux << A`):

| Valor | Impreso |
|-------|---------|
| a=55  | 55      |
| b=50  | 50      |
| c='e' | e       |
| d='t' | t       |
| aux   | 1       |
| A     | 0       |

Sin espacios → `5550et10`
