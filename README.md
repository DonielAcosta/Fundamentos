# Programación en C++, Fundamentos, Estructura y Modularidad

**Elementos de Programación en C++. Universitario. Análisis, Algoritmos Generales, Entradas Procesos Salidas.**

Repositorio de apuntes, ejercicios y proyectos del diplomado de fundamentos de programación en C++.

---

## Información del curso

| Detalle | Valor |
|---------|-------|
| **Instructor** | Isaac Guerrero Mora |
| **Idioma** | Español |
| **Plataforma** | Udemy |
| **Enfoque** | Análisis E-P-S, algoritmos, estructuras de control y programación modular |

---

## Contenido del curso

### Tipos de datos simples
- Enteros, reales, flotantes, caracteres y booleanos
- Declaración, inicialización, asignación y lectura destructiva

### Estructuras de control
- Secuenciales, de decisión y de repetición
- Uso simple, doble, anidado y apilado

### Apuntadores
- Concepto y uso de apuntadores
- Paso de parámetros por valor y por referencia

### Arreglos y cadenas
- Vectores, matrices y cadenas de caracteres

### Programación modular
- Procedimientos y funciones
- Diagramado y descomposición de problemas

### Diseño de algoritmos
- Análisis **E-P-S** (Entrada–Proceso–Salida)
- Algoritmos generales y específicos

---

## Estructura del repositorio

```
Fundamentos/
├── README.md
├── EVALUACION_MODULO1.md      # Indicaciones de evaluación del Módulo 1
├── Actividad 1 Programación -1.pdf
└── clases/
    ├── Programa0.cpp            # Bienvenida
    ├── Programa1.cpp … Programa17.cpp
    └── ...
```

---

## Programas de práctica

| Archivo | Tema |
|---------|------|
| `Programa0.cpp` | Mensaje de bienvenida |
| `Programa1.cpp` | Lectura y escritura de un entero |
| `Programa2.cpp` | Tipos de datos y operadores |
| `Programa3.cpp` | Área de un triángulo (análisis E-P-S) |
| `Programa4.cpp` | Intercambio de variables |
| `Programa5.cpp` | Ordenar tres enteros (Recto 1) |
| `Programa6.cpp` | Día del año con arreglo (sin `if`) |
| `Programa7.cpp` | Día del año con decisiones apiladas |
| `Programa8.cpp` | Menú de recetas de arepas (modularidad) |
| `Programa9.cpp` | Ordenar tres enteros (intercambios) |
| `Programa10.cpp` | Día del año con menú por mes |
| `Programa11.cpp` | Ordenar tres enteros con casillas auxiliares |
| `Programa12.cpp` | Día del año con variables por mes |
| `Programa13.cpp` | Día del año sin estructuras de decisión |
| `Programa14.cpp` | Área de triángulo por tres lados (Herón) |
| `Programa15.cpp` | Pago por días trabajados |
| `Programa16.cpp` | Promedio de notas (`for`) |
| `Programa17.cpp` | Ternas equiláteras (`while`, `rand`) |

### Compilar y ejecutar un programa

```bash
cd clases
g++ Programa3.cpp -o Programa3
./Programa3
```

En **Dev-C++**: abrir el archivo, compilar (F9) y ejecutar (F10).

---

## Herramientas para compilar y ejecutar

### IDE local

| Herramienta | Descripción | Enlace |
|-------------|-------------|--------|
| **Dev-C++** | IDE con compilador integrado (MinGW). Recomendado en el curso. | [Descargar Dev-C++](https://sourceforge.net/projects/orwelldevcpp/) |

### Línea de comandos

| Herramienta | Descripción | Ejemplo |
|-------------|-------------|---------|
| **g++** (GCC) | Compilador estándar en Linux | `g++ archivo.cpp -o programa && ./programa` |

### En línea

| Herramienta | Descripción | Enlace |
|-------------|-------------|--------|
| **Python Tutor** | Visualizador paso a paso para C/C++ | [pythontutor.com](https://pythontutor.com/) |
| **OnlineGDB** | Compilador C++ en el navegador | [onlinegdb.com](https://www.onlinegdb.com/online_c++_compiler) |
| **Compiler Explorer** | Código fuente y ensamblador generado | [godbolt.org](https://godbolt.org/) |

> Para ejercicios con apuntadores y memoria, [Python Tutor](https://pythontutor.com/) ayuda a ver cómo cambian las variables en cada paso.

---

## Evaluación

Las indicaciones del **Módulo 1** están en [EVALUACION_MODULO1.md](EVALUACION_MODULO1.md).

**Fecha límite:** hasta el 10 de julio de 2026.

Resumen:
1. Verificar las 4 secciones del curso en plataforma
2. Codificar el proyecto de evaluación
3. Proponer un módulo nuevo al proyecto
4. Presentar oralmente una parte del código y las estructuras usadas

---

## Autor

Material desarrollado en el marco del diplomado **Fundamentos**, basado en el curso de Udemy *Programación en C++, Fundamentos, Estructura y Modularidad* impartido por **Isaac Guerrero Mora**.
