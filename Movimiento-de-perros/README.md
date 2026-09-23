# Movimiento de perros

Simulación en C++ de un grupo de perros que se mueven sobre una grilla bidimensional. El programa muestra en consola cómo los animales se desplazan, siguen a un líder, reproducen y “mueren” cuando alcanzan una edad límite aleatoria.

## ¿Qué hace este proyecto?

El programa crea un **espacio** de **15 filas × 25 columnas**. En cada celda puede haber un perro o estar vacía (`_`).

En cada ciclo de simulación ocurre lo siguiente:

1. **Pensar** — cada perro elige una dirección (Norte, Sur, Este u Oeste).
2. **Mover** — se actualiza su posición si la celda destino está libre.
3. **Finalizar** — si un perro supera su edad máxima, se elimina del espacio.
4. **Reproducir** — hembras adultas cerca de un macho pueden generar un nuevo perro.
5. **Imprimir** — se dibuja la grilla en consola y se espera 200 ms antes del siguiente ciclo.

El bucle es infinito (`while(true)`), así que la simulación solo termina si cierras el programa.

## Ejecución por defecto (`main.cpp`)

```cpp
Espacio *E1 = new Espacio();
for (int i = 1; i < 15; i++)
    E1->setPerro(new PerroS('*'));
E1->ponerLider();
E1->simular();
```

- Se colocan **14 perros seguidores** (`*`) en posiciones aleatorias.
- Se crea un **líder** (`L`) y todos los perros reciben referencia a él.
- Los seguidores intentan moverse hacia el líder según su posición relativa (NE, NO, SE, SO).
- El líder se mueve al azar como un `Perro` normal.

## Estructura del código

| Archivo | Rol |
|---------|-----|
| `preliminares.h` | Constantes: `fila = 15`, `columna = 25`, `lon = 20`. Incluye `iostream` y `windows.h`. |
| `perro.h` | Clase base `Perro`: raza, edad, sexo, posición, decisión de movimiento aleatoria. |
| `perroSeguidor.h` | `PerroS` hereda de `Perro` y sigue al líder en lugar de moverse al azar. |
| `perroEspacializado.h` | `PerroE` recorre el borde de la grilla (no se usa en `main.cpp`). |
| `espacio.h` | Clase `Espacio`: grilla, movimiento, reproducción, muerte y simulación. |
| `nodo.h` / `lista.h` | Lista enlazada de perros (ejercicio auxiliar; no usada en el `main` actual). |
| `main.cpp` | Punto de entrada: crea el espacio, perros y arranca la simulación. |

## Conceptos que practica

- **Programación orientada a objetos**: herencia (`Perro` → `PerroS`, `PerroE`).
- **Grilla 2D** y colisiones (no dos perros en la misma celda).
- **Vecindad de Moore** (8 celdas alrededor) para detectar machos en reproducción.
- **Simulación por turnos** con flag `procesado` para evitar mover el mismo perro dos veces en un ciclo.
- **Memoria dinámica**: `new` / `delete` en perros y celdas.

## Reglas de movimiento

### Perro normal (`Perro`)

- Cada turno incrementa la edad.
- Elige al azar: `N`, `S`, `E` u `O`.
- No sale de los bordes de la grilla.

### Perro seguidor (`PerroS`)

- Si **no** tiene líder: igual que `Perro`.
- Si **tiene** líder: según si está al NE, NO, SE o SO del líder, prefiere moverse hacia él (combinación de dos direcciones con 50 % de probabilidad).

### Perro espacializado (`PerroE`)

- Recorre el perímetro: al tocar un borde cambia de dirección en ciclo N → O → S → E.
- A partir de edad 15 cambia su símbolo según sexo (`O` / `L`).

## Reproducción y población

- Solo hembras (`sexo == false`) con edad > 15.
- Debe haber un **macho adulto** en la vecindad de Moore.
- Solo se crea un nuevo perro si hay **espacio**: al menos **60 %** de celdas vacías.
- Al morir un perro sin líder asignado, se llama `ponerLider()` para crear uno nuevo.

## Requisitos

- Compilador C++ (g++, MinGW, MSVC).
- **Windows**: el código usa `windows.h`, `Sleep()` y `system("cls")`. En Linux habría que reemplazar `Sleep` por `sleep`/`usleep` y `cls` por `clear`.

## Compilar y ejecutar

### Windows (MinGW / g++)

```bash
cd Movimiento-de-perros
g++ -o movimiento_perros main.cpp
movimiento_perros.exe
```

### Si ya existe el ejecutable

```bash
./output/main.exe
```

## Vista en consola

Cada celda muestra:

- `_` — vacío
- `*` — perro seguidor
- `L` — líder

Ejemplo simplificado:

```
_ _ * _ L _ _ ...
_ * _ _ _ _ _ ...
...
```

## Notas

- La simulación no tiene menú ni entrada de usuario; es solo visualización.
- `lista.h` y `perroEspacializado.h` son código de apoyo o variantes del ejercicio; el flujo principal está en `espacio.h` + `perroSeguidor.h`.
- El proyecto incluye repositorio Git (rama `main`).

## Autor / contexto

Proyecto de **Fundamentos de programación** (Diplomado), orientado a modelar comportamiento simple con clases, grillas y simulación por turnos.
