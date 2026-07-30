# Guía 3 - Ejercicio 1 (Corrida en frío)

Código del enunciado (con comillas dobles como aparece en la guía). En C++ real, un `char` debe asignarse con comillas simples (`'3'`). Se asume esa corrección para la corrida.

```cpp
int A, B;          // A y B sin inicializar
bool a;
char b;

a = true;          // a = true
b = '3';           // b = '3'
A = 9 * 3 + 8;     // A = 27 + 8 = 35
b = '5';           // b = '5'
a = false == true; // a = false
a = b != '6';      // '5' != '6' → a = true
B = 4 % (A + A) * B - 7;
                   // A+A = 70 → 4 % 70 = 4
                   // B aún no tiene valor definido → resultado indefinido
A = A * 5;         // A = 35 * 5 = 175
```

## Valores finales (asumiendo B inicializado en 0)

| Variable | Valor |
|----------|-------|
| A        | 175   |
| B        | -7    |
| a        | true  |
| b        | '5'   |

**Nota:** En la línea `B = 4 % (A + A) * B - 7`, `B` se usa antes de asignarse. Eso es un error lógico (comportamiento indefinido). Si `B` valiera 0: `4 * 0 - 7 = -7`.
