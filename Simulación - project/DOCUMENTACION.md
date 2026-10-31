# Documentación de métodos y funciones (Linux / C++)

Referencia de **todas** las clases, métodos y funciones del puerto Linux (`linux/`).

---

## Índice

1. [enum Direccion](#1-enum-direccion)
2. [class Animal](#2-class-animal)
3. [class Conejo](#3-class-conejo)
4. [class Fondo](#4-class-fondo)
5. [class Madriguera](#5-class-madriguera)
6. [class Zorro](#6-class-zorro)
7. [struct Estadisticas](#7-struct-estadisticas)
8. [class Juego](#8-class-juego)
9. [main.cpp — UI y bucle](#9-maincpp--ui-y-bucle)

---

## 1. enum Direccion

| Valor | Significado |
|-------|-------------|
| `Arriba` | Movimiento hacia arriba |
| `Abajo` | Movimiento hacia abajo |
| `Izquierda` | Movimiento hacia la izquierda |
| `Derecha` | Movimiento hacia la derecha |
| `Ninguno` | Sin dirección activa |

Usado históricamente para teclado; los conejos usan además `char` (`N/S/E/O`).

---

## 2. class Animal

Clase base de cualquier animal del escenario (posición, edad, sexo, sprites).

### Atributos principales

| Atributo | Tipo | Descripción |
|----------|------|-------------|
| `hambre` | `int` | Baja cada tick; si llega muy bajo se reinicia |
| `edad` | `int` | Aumenta al dibujar; define madurez y muerte |
| `indiceX`, `indiceY` | `int` | Celda del spritesheet (animación / dirección) |
| `x`, `y` | `float` | Posición actual en pantalla |
| `xFu`, `yFu` | `float` | Posición futura propuesta |
| `ancho`, `alto` | `float` | Tamaño de una celda del sprite |
| `dx`, `dy` | `float` | Paso de desplazamiento |
| `sexo` | `bool` | `true` = macho, `false` = hembra |
| `fertilidad` | `bool` | Puede reproducirse |
| `enfermo` | `bool` | Estado de enfermedad |

### Métodos

| Método | Qué hace |
|--------|----------|
| `Animal()` | Constructor por defecto: posición (100,100), hambre 15, sexo aleatorio, sano y fértil. |
| `Animal(float x, float y, const sf::Texture& textura)` | Coloca al animal en `(x,y)` y calcula `ancho`/`alto` dividiendo la textura en 4×4 celdas. |
| `~Animal()` | Destructor virtual (permite herencia segura). |
| `setX(float x)` / `setY(float y)` | Asigna la coordenada X o Y. |
| `getX()` / `getY()` | Devuelve la posición actual. |
| `getAncho()` / `getAlto()` | Devuelve el tamaño de celda del sprite. |
| `getDX()` / `getDY()` | Devuelve el paso de movimiento. |
| `getXFu()` / `getYFu()` | Devuelve la posición futura calculada en `decidir()`. |
| `getEdad()` | Devuelve la edad actual. |
| `getSexo()` | `true` macho, `false` hembra. |
| `getFertilidad()` | Indica si puede reproducirse. |
| `cambiarFertilidad()` | Invierte el flag de fertilidad. |
| `getEnfermo()` | Indica si está enfermo. |
| `dibujar(ventana, hembra, macho, enfermo)` | Elige el sprite según sexo/enfermedad, avanza la edad y dibuja en la ventana. |

---

## 3. class Conejo

Hereda de `Animal`. Añade movimiento autónomo, color de pelaje y huida del zorro.

### Atributos propios

| Atributo | Descripción |
|----------|-------------|
| `contador` / `limiteContador` | Controla cada cuántos frames cambia de dirección |
| `colorPelaje` | Tinte SFML aplicado al sprite |

### Métodos

| Método | Qué hace |
|--------|----------|
| `colorAleatorio()` *(privado, estático)* | Elige un color de una paleta (blanco, beige, marrón, gris, rosa, azul, verde, amarillo…). |
| `decidirDireccion()` *(privado)* | Devuelve al azar `'N'`, `'S'`, `'E'` u `'O'`. |
| `Conejo()` | Constructor por defecto + color aleatorio. |
| `Conejo(x, y, textura, limAncho, limAlto)` | Crea un conejo en `(x,y)`, guarda límites del mapa, paso 8 px y color aleatorio. |
| `~Conejo()` | Libera el objeto. |
| `mover()` | Si tiene hambre ≥ 0, aplica `xFu/yFu` como nueva posición. |
| `decidir()` | Baja hambre, anima el sprite, periódicamente cambia dirección y calcula `xFu/yFu`. |
| `enfermar()` | Marca `enfermo = true`. |
| `huirDe(zx, zy)` | Orienta la dirección **en sentido contrario** al zorro y sube la velocidad (huida). |
| `getColor()` | Devuelve el color de pelaje. |
| `dibujar(ventana, hembra, macho, enfermo)` | Como `Animal::dibujar`, pero aplica `colorPelaje` si no está enfermo. |

---

## 4. class Fondo

Representa el escenario (césped) escalado al área de juego.

### Métodos

| Método | Qué hace |
|--------|----------|
| `Fondo()` | Escenario por defecto 1200×700 en (0,0). |
| `Fondo(x, y, anchoVista, altoVista, textura)` | Fija origen y tamaño **visual/lógico** del mapa; guarda tamaño real de la textura para escalar. |
| `~Fondo()` | Destructor. |
| `getX()` / `getY()` | Esquina superior izquierda del escenario. |
| `getAncho()` / `getAlto()` | Ancho y alto lógicos (usados por colisiones y límites). |
| `dibujar(ventana, textura)` | Dibuja el fondo escalado para llenar exactamente el rectángulo del escenario. |

---

## 5. class Madriguera

Hoyo donde “salen” las crías al nacer.

### Métodos

| Método | Qué hace |
|--------|----------|
| `Madriguera(x, y)` | Crea la madriguera en `(x,y)` con radio ~34 y un cooldown aleatorio. |
| `getX()` / `getY()` | Centro de la madriguera. |
| `getRadio()` | Radio del hoyo dibujado. |
| `listaParaParto()` | `true` si el cooldown llegó a 0 (puede liberar una cría). |
| `reiniciarCooldown()` | Vuelve a poner un tiempo de espera tras un nacimiento. |
| `tick()` | Decrementa el cooldown cada frame de simulación. |
| `dibujar(ventana)` | Dibuja tierra marrón + hueco oscuro + sombra (formas SFML). |

---

## 6. class Zorro

Depredador que persigue al conejo más cercano.

### Métodos

| Método | Qué hace |
|--------|----------|
| `Zorro(x, y, textura)` | Coloca al zorro y calcula celdas del spritesheet; velocidad base 7.5. |
| `getX()` / `getY()` | Posición actual. |
| `getXFu()` / `getYFu()` | Posición futura tras `perseguir()`. |
| `getAncho()` | Ancho lógico aproximado (~70) para colisiones/visual. |
| `perseguir(tx, ty)` | Calcula vector hacia el objetivo, normaliza, aplica velocidad, actualiza `xFu/yFu` e índices de animación. |
| `mover()` | Confirma el desplazamiento (`x = xFu`, `y = yFu`). |
| `dibujar(ventana, textura)` | Dibuja el sprite del zorro (escala ~80 px). |

---

## 7. struct Estadisticas

Acumuladores mostrados al finalizar la simulación.

| Campo | Significado |
|-------|-------------|
| `nacimientos` | Crías que salieron de madrigueras durante la corrida |
| `muertosNatural` | Muertes por edad o enfermedad |
| `comidosPorZorro` | Conejos cazados por el zorro |
| `poblacionInicial` | Conejos al empezar |
| `poblacionFinal` | Conejos al terminar |

---

## 8. class Juego

Motor de la simulación: población, reglas, depredación y dibujo.

### Atributos clave

| Atributo | Descripción |
|----------|-------------|
| `fondo` | Escenario |
| `conejo[1000]` | Arreglo de punteros a conejos vivos (`nullptr` = vacío) |
| `madrigueras` | Vector con 3 madrigueras |
| `zorro` | Único depredador |
| `NC` | Número de conejos vivos |
| `casoCero` | Si ya apareció la primera infección |
| `stats` | Contadores finales |
| `ticks` | Frames transcurridos |
| `terminado` | La simulación ya no avanza |

### Métodos privados

| Método | Qué hace |
|--------|----------|
| `madrigueraMasCercana(px, py)` | Devuelve la madriguera con menor distancia euclidiana al punto. |
| `matarConejo(i, porZorro)` | Borra el conejo `i`, baja `NC` y suma a `comidosPorZorro` o `muertosNatural`. |
| `nacerEnMadriguera(fig, cercaX, cercaY)` | Crea una cría cerca de la madriguera más cercana a `(cercaX,cercaY)`, suma `nacimientos` y reinicia cooldown. |

### Métodos públicos

| Método | Qué hace |
|--------|----------|
| `Juego(fondo, conejo, zorro, numC, p, vista…)` | Crea fondo, 3 madrigueras, `numC` conejos alrededor de ellas y un zorro; inicializa stats. |
| `~Juego()` | Libera conejos, zorro y fondo. |
| `getNC()` | Cantidad de conejos vivos. |
| `estaTerminado()` | `true` si ya se llamó `finalizar()` o se cumplió fin automático. |
| `getStats()` | Referencia constante a las estadísticas. |
| `finalizar()` | Marca terminado y guarda `poblacionFinal`. |
| `hayChoque(x, y)` | `true` si hay un conejo a menos de ~45 px (evita solapes al nacer). |
| `setConejo(fig)` | Coloca un conejo inicial cerca de una madriguera al azar (**no** cuenta como nacimiento). |
| `setConejo(fig, px, py, cuentaNacimiento)` | Si `cuentaNacimiento`, nace por madriguera; si no, inserta en `(px,py)`. |
| `esPosible(x, y, a)` | Comprueba que el punto con margen `a` esté dentro del escenario. |
| `controldeMortalidad()` | Alterna fertilidad al azar; mata por vejez (>220) o enfermedad. |
| `reproducir(fig)` | Llama mortalidad, hace tick de madrigueras, partos espontáneos y reproducción por parejas (cría sale de madriguera). |
| `enfermar()` | Elige un conejo vivo como “caso cero” (solo una vez hasta reinicio del flag). |
| `propagar()` | Contagia enfermedad a vecinos cercanos con cierta probabilidad. |
| `verificarCasoCero()` | Si no queda ningún enfermo, reinicia `casoCero` a `false`. |
| `cazar()` | Halla el conejo más cercano; hace huir a los cercanos; el zorro persigue; si está a <48 px, lo come. |
| `mover(fig)` | Un tick completo: reproducir, epidemia, cazar, mover conejos; auto-finaliza si `NC==0` o `ticks>=1350`. |
| `dibujar(ventana, …)` | Dibuja fondo → madrigueras → conejos → zorro. |
| `dist(x1,y1,x2,y2)` *(estático)* | Distancia euclidiana entre dos puntos. |

---

## 9. main.cpp — UI y bucle

Archivo de entrada: ventana, botones, eventos y overlay de estadísticas.

### `struct Boton`

| Método / miembro | Qué hace |
|------------------|----------|
| `Boton(font, texto, x, y, w, h, color, primario)` | Crea rectángulo + sombra + etiqueta centrada. |
| `centrarLabel()` | Centra el texto dentro del botón. |
| `contiene(mx, my)` | Hit-test: ¿el clic está sobre el botón? |
| `actualizarHover(mx, my)` | Cambia el color si el mouse está encima. |
| `dibujar(w)` | Dibuja sombra, rectángulo y texto. |
| `setTexto(t)` | Cambia la etiqueta y recentra. |

### Funciones libres (namespace anónimo)

| Función | Qué hace |
|---------|----------|
| `loadTexture(tex, path)` | Carga un PNG en `sf::Texture`; imprime error si falla. |
| `dibujarPanel(w, x, y, ancho, alto)` | Barra inferior azul con franja amarillo/azul/rojo (bandera). |
| `dibujarEstadisticas(w, font, vista…, stats)` | Oscurece el escenario y muestra la tarjeta de estadísticas finales. |
| `tryLoad` *(lambda en `main`)* | Prueba varias rutas hasta cargar una textura. |
| `dibujarFranjaBandera` *(lambda)* | Pinta la cabecera con las tres franjas de Venezuela. |
| `actualizarChip` *(lambda)* | Actualiza el texto “Habitantes N” en la esquina. |

### `int main()`

1. Crea ventana 1400×900 e inicializa fuente.
2. Carga texturas (`Cesped`, preview, conejos, zorro).
3. Prepara botones: `−` / contador / `+` / `Iniciar` / `Finalizar` / `Salir`.
4. Bucle:
   - Procesa cierre, ESC y clics.
   - Si está en curso, llama `juego->mover()` y actualiza habitantes.
   - Dibuja cabecera, escenario, UI inferior y, si aplica, estadísticas.
5. Libera `juego` al salir.

---

## Flujo de un tick (`Juego::mover`)

```text
verificarCasoCero()
reproducir()          → mortalidad + madrigueras + nacimientos
si NC > 180 → enfermar()
si hay epidemia → propagar()
cazar()               → zorro persigue / come
mover cada conejo
¿NC==0 o ticks>=1350? → finalizar()
```

---

## Archivos fuente ↔ responsabilidad

| Archivo | Responsabilidad |
|---------|-----------------|
| `Animal.hpp/.cpp` | Estado común de animales |
| `Conejo.hpp/.cpp` | Presa: movimiento, color, huida |
| `Zorro.hpp/.cpp` | Depredador |
| `Madriguera.hpp/.cpp` | Nidos / partos |
| `Fondo.hpp/.cpp` | Escenario escalado |
| `Juego.hpp/.cpp` | Reglas + estadísticas |
| `main.cpp` | Interfaz SFML y ciclo de vida de la app |
