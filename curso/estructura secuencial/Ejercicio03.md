# Ejercicio 3 — Identificadores válidos

**Fuente:** EjerciciosSecuencialidad01.pdf

| Identificador | ¿Válido? | Motivo |
|---------------|----------|--------|
| n | Sí | Letra válida |
| MoProblema | Sí | Letras y dígitos; no inicia con dígito |
| MiJuiego | Sí | Letras válidas |
| Mi Juego | **No** | Contiene espacio |
| 85 Nombre | **No** | Inicia con dígito y contiene espacio |
| AAAAAAAAA | Sí | Letras válidas |
| Nombre_Apellido | Sí | Letras y guion bajo |
| 92 | **No** | Solo dígitos, no es identificador |
| 9_NumeRo | **No** | Inicia con dígito |
| *kilo | **No** | Inicia con carácter no permitido |
| Num1*M | **No** | Contiene `*` |
| Num_1 | Sí | Letras, dígito y guion bajo; no inicia con dígito |

## Reglas en C++

- Puede contener letras, dígitos y guion bajo `_`.
- **No** puede iniciar con dígito.
- **No** puede contener espacios ni símbolos especiales (`*`, `-` al inicio, etc.).
- Palabras reservadas (`int`, `return`, etc.) no son válidas como identificador.
