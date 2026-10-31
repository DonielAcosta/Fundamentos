# Modelo Predador–Presa (Simulación de Conejos)

Simulación gráfica de una población de conejos: movimiento, reproducción, mortalidad y propagación de enfermedades.

> **Documentación completa de cada método y función:** ver [`DOCUMENTACION.md`](DOCUMENTACION.md).

Hay **dos versiones**:

| Versión | Carpeta / archivos | Plataforma |
|---------|--------------------|------------|
| **Linux (recomendada aquí)** | `linux/` + `Makefile` → `simulacion_linux` | Linux + C++17 + SFML |
| Windows (original) | `Predador_Presa.sln`, `MyForm.*` | Windows + C++/CLI + WinForms |

---

## Ejecutar en Linux (C++ / SFML)

### Compilar

```bash
make
```

### Ejecutar

```bash
make run
# o:
./simulacion_linux
```

Debes lanzarlo **desde la raíz del proyecto** (donde están los PNG).

### Controles

1. Con **+ / −** ajusta la población inicial (por defecto 15).
2. Pulsa **Iniciar** para arrancar (césped, madrigueras, conejos de colores y zorro).
3. **Finalizar** corta la simulación y muestra estadísticas.
4. **Salir** o **ESC** cierra la ventana.

### Mecánicas nuevas

- **Madrigueras**: las crías nacen saliendo de la madriguera más cercana.
- **Colores**: cada conejo tiene un pelaje distinto.
- **Zorro**: persigue y come conejos; los cercanos huyen.
- **Estadísticas finales**: nacimientos, muertes naturales y comidos por el zorro.

### Librerías usadas en Linux

| Librería | Módulo / paquete | Para qué se usa en el proyecto |
|----------|------------------|--------------------------------|
| **SFML 2.6** | `sfml-graphics` | Ventana de dibujo, sprites (conejos, zorro, césped), formas (madrigueras, UI), colores y texto |
| **SFML 2.6** | `sfml-window` | Ventana, eventos de mouse/teclado, bucle de la aplicación |
| **SFML 2.6** | `sfml-system` | Utilidades base que requieren los módulos anteriores (tiempo, etc.) |
| **libstb** | `libstb.so` (dependencia de SFML) | Carga de imágenes PNG que usa `sfml-graphics` |
| **STL / C++17** | `<vector>`, `<string>`, `<cmath>`, `<cstdlib>`, … | Contenedores, matemáticas, memoria y lógica del modelo |
| **FreeType / X11** | libs del sistema (vía SFML) | Fuentes tipográficas y ventana gráfica en Linux |

Headers principales incluidos en el código:

```cpp
#include <SFML/Graphics.hpp>   // RenderWindow, Texture, Sprite, Text, Font, shapes
```

Enlace en el `Makefile`:

```text
-lsfml-graphics -lsfml-window -lsfml-system
```

#### Cómo están instaladas aquí

El `Makefile` usa **SFML 2.6 embebido** en `deps/prefix` (headers + `.so`, sin `sudo`).

Si prefieres SFML del sistema:

```bash
sudo apt install libsfml-dev
# opcional si hace falta la dependencia de imágenes:
# sudo apt install libstb0t64

g++ -std=c++17 -O2 -Ilinux linux/*.cpp -o simulacion_linux \
  -lsfml-graphics -lsfml-window -lsfml-system
```

### Estructura del puerto Linux

```text
linux/
  main.cpp        # Ventana SFML, botones, stats y bucle
  Animal.*        # Clase base
  Conejo.*        # Movimiento, color, huida
  Zorro.*         # Depredador
  Madriguera.*    # Nidos / partos
  Fondo.*         # Escenario (césped)
  Juego.*         # Reglas + estadísticas
Makefile
simulacion_linux
deps/prefix/      # SFML local (headers + .so) + libstb
```

---

## Qué simula el modelo

| Mecánica | Descripción |
|----------|-------------|
| Movimiento | Cada conejo elige dirección N/S/E/O y avanza si cabe en el escenario |
| Sexo | Aleatorio (macho / hembra); sprites distintos |
| Edad | Sube cada frame; mueren si edad > 200 |
| Reproducción | Distinto sexo, edad 18–150, fértiles, sanos, distancia < 60 (~2 %) |
| Enfermedad | Si hay > 200 conejos aparece un caso cero; se propaga por cercanía (~15 %) |
| Capacidad | Hasta 1000 conejos |

---

## Imágenes necesarias

- `Cesped.png` — fondo al iniciar la simulación
- `Fig_Conejo.png` / `Fig_Conejo_Macho.png` / `Fig_Conejo_Enfermo.png`
- `Fig_Zorro.png` — depredador
- `FONDO1.png` — vista previa antes de iniciar (opcional: `Pista.png`)

---

## Versión Windows (original C++/CLI)

Requiere Visual Studio + .NET Framework 4.7.2.

1. Abre `Predador_Presa.sln`.
2. Configuración **Debug | x64**.
3. F5.

Ejecutable típico: `x64\Debug\Modelo_Predador_Presa.exe` (junto a los PNG).

Archivos UI originales: `MyForm.h`, `MyForm.cpp`, `Metdos_MyFrom.cpp`, `Juego.hpp` (versión administrada).

---

## Compilar / limpiar

```bash
make          # genera ./simulacion_linux
make run      # compila si hace falta y ejecuta
make clean    # borra el binario
```

---

## Notas

- El puerto Linux reescribe la lógica en **C++ nativo + SFML** (sin C++/CLI ni Windows Forms).
- La versión Windows original usa **.NET Framework / Windows Forms** (`System::Windows::Forms`, `System::Drawing`).
- Autoría académica: diplomado de Fundamentos — módulo de Simulación.
