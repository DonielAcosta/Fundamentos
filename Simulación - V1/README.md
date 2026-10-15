# Modelo Predador–Presa (Simulación V1)

Simulación gráfica de población de conejos con movimiento, reproducción y mortalidad. Proyecto del diplomado de **Fundamentos**, originalmente en **C++/CLI + Windows Forms** (Visual Studio), con puertos para Linux en **C++ (SDL2)** y Python + pygame.

---

## Descripción

La aplicación muestra un escenario donde varios conejos:

- Se mueven de forma aleatoria (Norte, Sur, Este, Oeste).
- Envejecen en cada fotograma.
- Se reproducen al acercarse si ambos tienen edad suficiente.
- Mueren al superar una edad máxima.

El usuario puede configurar la cantidad inicial de conejos y un parámetro de tiempo antes de iniciar la simulación.

---

## Requisitos

### Windows (versión original)

| Componente | Versión / detalle |
|---|---|
| Visual Studio | 2019 o 2022 (recomendado) |
| Toolset | MSVC v143 |
| Framework | .NET Framework 4.7.2 |
| Plataforma | x64 o Win32 |
| Tipo de proyecto | C++/CLI con CLR (`CLRSupport`) |

### Linux — C++ (recomendado)

Detalle completo en la sección **Puerto C++ en Linux — qué se usó**.

### Linux — Python (alternativa)

| Componente | Detalle |
|---|---|
| Python | 3.10+ (probado en 3.12) |
| pygame | ≥ 2.6.0 |

```bash
pip3 install --user --break-system-packages -r requirements-linux.txt
```

---

## Cómo ejecutar

### Linux (C++)

Desde la carpeta del proyecto (`Simulación - V1`):

```bash
cd cpp
make
./run.sh
```

Si ya estás dentro de `cpp/`:

```bash
./run.sh
```

### Linux (Python)

```bash
cd "Simulación - V1"
./run.sh
# o: python3 run_linux.py
```

### Windows

1. Abrir `Predador_Presa.sln` en Visual Studio.
2. Seleccionar configuración **Debug | x64**.
3. Compilar y ejecutar (F5).
4. Asegurar que las imágenes PNG estén en el directorio de trabajo del ejecutable (o en la carpeta del proyecto).

Ejecutable ya compilado (si existe):

```
x64/Debug/Modelo_Predador_Presa.exe
```

---

## Controles

| Acción | Control |
|---|---|
| Aumentar / disminuir conejos | Botones `+` / `-` junto a **C** |
| Aumentar / disminuir tiempo (TS) | Botones `+` / `-` junto al valor de tiempo |
| Iniciar simulación | Botón **inicio** |
| Mostrar botón Finalizar | Tecla **O** |
| Ocultar botón Finalizar | Tecla **I** |
| Finalizar y volver al menú | Botón **Finalizar** |
| Salir (solo Linux) | Tecla **Esc** |

---

## Estructura del proyecto

```
Simulación - V1/
├── Predador_Presa.sln          # Solución Visual Studio (Windows)
├── Juego_Lider.vcxproj         # Proyecto C++/CLI
├── MyForm.* / Metdos_MyFrom.cpp
├── Juego.hpp / Animal.* / Conejo.* / Fondo.*
│
├── cpp/                        # Puerto Linux en C++ (SDL2)
│   ├── main.cpp                # UI y bucle principal
│   ├── Animal.hpp / Conejo.hpp / Fondo.hpp / Juego.hpp
│   ├── Makefile
│   ├── run.sh
│   └── deps/                   # Headers/libs SDL2 locales (opcional)
│
├── Fig_Conejo.png / Pista.png / FONDO1.png ...
├── run_linux.py                # Puerto Linux (pygame)
├── run.sh
└── README.md
```

---

## Arquitectura

```
┌─────────────────────┐
│   MyForm / UI       │  Botones, timer, teclado, buffer gráfico
└─────────┬───────────┘
          │
          ▼
┌─────────────────────┐
│   Juego             │  Lista de conejos, colisiones, reproducción, dibujo
└─────────┬───────────┘
          │
    ┌─────┴─────┐
    ▼           ▼
┌────────┐  ┌────────┐
│ Fondo  │  │ Conejo │ ──► hereda Animal
└────────┘  └────────┘
```

### Clases principales

| Clase | Responsabilidad |
|---|---|
| `MyForm` | Interfaz: inicia/detiene, ajusta parámetros, pinta cada tick |
| `Juego` | Orquesta conejos, fondo, mortalidad y reproducción |
| `Animal` | Posición, tamaño, edad, sprite (índices de frame) |
| `Conejo` | Decide dirección aleatoria y avanza |
| `Fondo` | Dimensiones y dibujo del escenario |

### Reglas de simulación

| Regla | Valor / comportamiento |
|---|---|
| Capacidad máxima | Hasta 1000 conejos |
| Edad mínima para reproducir | > 18 |
| Distancia para reproducir | < 60 px |
| Probabilidad de cría | 20 % |
| Edad máxima (muerte) | > 60 |
| Sprite | Hoja 4×4; `indiceX` anima frames, `indiceY` indica dirección |
| Tamaño en pantalla | 60×60 px |

Direcciones del sprite (`indiceY`):

| Índice | Dirección |
|---|---|
| 0 | Sur |
| 1 | Oeste |
| 2 | Este |
| 3 | Norte |

---

## Recursos gráficos

Los PNG deben estar en el mismo directorio desde el que se ejecuta la app:

| Archivo | Uso |
|---|---|
| `Pista.png` | Escenario durante la simulación |
| `Fig_Conejo.png` | Animación de cada conejo |
| `FONDO1.png` | Fondo del menú (Linux / recurso WinForms) |

---

## Puerto C++ en Linux — qué se usó

El original es **C++/CLI + Windows Forms** (`.NET Framework`). Eso **no compila ni corre nativo en Linux**. Para Linux se reescribió un puerto en **C++ estándar (ISO C++17)** con gráficos vía **SDL2**.

### Herramientas y librerías

| Pieza | Qué es / para qué |
|---|---|
| **g++** (GCC 13+) | Compilador C++ |
| **Make** | Compilación con `cpp/Makefile` |
| **SDL2** | Ventana, eventos (ratón/teclado), renderizado 2D |
| **SDL2_image** | Carga de PNG (`Pista.png`, `Fig_Conejo.png`, `FONDO1.png`) |
| **SDL2_ttf** | Texto en botones y HUD (fuentes TrueType del sistema) |
| **FreeType / libpng** | Dependencias de SDL2_ttf y SDL2_image |
| **Fuente DejaVu Sans** | `/usr/share/fonts/truetype/dejavu/` (si no, Liberation/FreeSans) |

Estándar del código: **C++17** (`-std=c++17`).

### Por qué SDL2 (y no WinForms)

| Original (Windows) | Puerto Linux |
|---|---|
| `System::Windows::Forms` | SDL2 (ventana + input) |
| `System::Drawing::Bitmap` | `SDL_Texture` + `IMG_Load` |
| `BufferedGraphics` / `Timer` | `SDL_Renderer` + bucle a ~30 FPS |
| C++/CLI (`gcnew`, `^`) | C++ estándar (`new` / `unique_ptr`) |

La lógica de simulación (`Juego`, `Conejo`, `Animal`, `Fondo`) se mantiene equivalente a la del proyecto original.

### Dependencias locales (`cpp/deps/`) — sin sudo

En muchos equipos Linux no hay headers de desarrollo instalados (`libsdl2-dev`, etc.) y `sudo` no está disponible. Se usó este flujo:

1. Descargar los `.deb` de Ubuntu (sin instalar en el sistema):
   - `libsdl2-dev`, `libsdl2-2.0-0`
   - `libsdl2-image-dev`, `libsdl2-image-2.0-0`
   - `libsdl2-ttf-dev`, `libsdl2-ttf-2.0-0`
   - `libfreetype6`, `libfreetype-dev`, `libpng16-16t64`
2. Extraerlos con `dpkg-deb -x` dentro de `cpp/deps/`.
3. El `Makefile` detecta `deps/usr/include/SDL2/SDL.h` y enlaza contra esas libs.

Para regenerar deps:

```bash
cd cpp
make setup-deps
```

Alternativa con paquetes del sistema (si tienes sudo):

```bash
sudo apt install g++ make libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

### Cómo compila el Makefile

- Si existe `cpp/deps/` → usa includes/libs locales y `rpath` relativo (`$ORIGIN/...`) para encontrar `libSDL2_image` / `libSDL2_ttf` al ejecutar.
- Si no → usa `pkg-config` del sistema.
- Incluye la ruta multiarch Debian/Ubuntu: `deps/usr/include/x86_64-linux-gnu` (archivo `_real_SDL_config.h`).

Genera el binario:

```text
cpp/predador_presa
```

### Archivos del puerto C++

| Archivo | Rol |
|---|---|
| `cpp/main.cpp` | UI (menú, botones, HUD) y bucle principal SDL2 |
| `cpp/Juego.hpp` | Simulación: reproducción, mortalidad, movimiento |
| `cpp/Conejo.hpp` | Decisión de dirección y avance |
| `cpp/Animal.hpp` | Base: posición, edad, dibujo de sprite |
| `cpp/Fondo.hpp` | Escenario |
| `cpp/Makefile` | Build y `setup-deps` |
| `cpp/run.sh` | Compila si hace falta y lanza el ejecutable |

Los PNG se cargan desde el directorio padre (`../`), es decir la raíz de `Simulación - V1`. Hay que ejecutar desde `cpp/`.

### Entorno de prueba

| Dato | Valor |
|---|---|
| SO | Ubuntu 24.04 (noble) / Linux x86_64 |
| Compilador | g++ 13.3 |
| Display | `DISPLAY` activo (sesión gráfica) |

---

## Notas técnicas

- **Windows**: el proyecto usa C++/CLI (`gcnew`, `Bitmap^`, WinForms). No compila nativamente en Linux/macOS.
- **Linux C++**: puerto en `cpp/` con SDL2 (ver sección anterior).
- **Linux Python**: `run_linux.py` es una alternativa equivalente con pygame.
- En la decisión de movimiento se corrige un detalle del original: al cambiar de dirección se actualizan ambos ejes (`x`/`y`) para evitar posiciones inconsistentes.
- Advertencias `libpng: iCCP` al cargar PNG son inofensivas (perfil de color de las imágenes).

---

## Solución de problemas

| Problema | Solución |
|---|---|
| `cd: no existe ... Simulación - V1/cpp` | Ya estás dentro del proyecto; usa solo `cd cpp` |
| `/usr/bin/env: «bash\r»` | El script tenía CRLF de Windows; convertir a LF: `sed -i 's/\r$//' cpp/run.sh` |
| `SDL.h: No such file` | `cd cpp && make setup-deps` o instalar `libsdl2-dev` |
| No encuentra `libSDL2_image.so` al ejecutar | Compilar con el `Makefile` (pone `rpath` a `deps/`) |
| `ModuleNotFoundError: pygame` | `pip3 install --user --break-system-packages pygame` |
| No abre ventana | Verificar `echo $DISPLAY` y sesión gráfica |
| Falta imagen / error al cargar PNG | Ejecutar desde `cpp/` (`./run.sh`), con los PNG en la carpeta padre |
| Visual Studio no encuentra PNG | Copiar los PNG a `x64/Debug/` o configurar el directorio de trabajo |

---

## Autor / contexto

Proyecto académico — Diplomado de Fundamentos.  
Título de la ventana: **Modelo Predador - Presa**.
