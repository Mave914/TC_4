| <div align="right"><img src="../Logo-UNA-Rojo_FondoTransparente%20(2).png" width="120" alt="Logo UNA" /></div> | | <p align="right"><img src="../images.jpeg" width="120" alt="Logo EscINF" /></p> |
|:----------------------------------------------------|:-------------------------------------------------------------:|------------------------------------------------------------:|

**Programa de curso** · **Programación II**  
**Carrera:** Ingeniería de Sistemas de Información con grado en Bachillerato y salida lateral de Diplomado en Programación de Aplicaciones Informáticas.

---

# Semana 5 – Sesión 1 (Estudiantes)

**Duración:** 2 horas  
**Tema:** Manejo de flujos – conceptos y flujos de texto

---

## Explicación (resumen)

- **Streams:** `istream`/`ostream`; `ifstream`/`ofstream` para archivos; `getline`, `>>`, `<<`; estados `good`, `eof`, `fail`.
- **Manipuladores:** `setw`, `setprecision`, `fixed` para formatear salida.

---

## Espacio para tu código

### Ejercicio 1: Numerar líneas (con filtros)

Lea un archivo de texto línea por línea y escriba en otro archivo cada línea numerada (1. …, 2. …, etc.). Ignore líneas vacías y omita líneas que empiecen con `#`.

```cpp
// ifstream, getline, ofstream; verificar linea.empty(), linea[0]=='#'

```

### Ejercicio 2: Estadísticas de números en archivo

Lea desde un archivo una lista de números. Calcule promedio, máximo y mínimo; escriba los tres en otro archivo y en pantalla. Si encuentra valor no numérico, muestre advertencia y continúe. Compruebe el estado del flujo.

```cpp
// Lectura con >>; comprobar good/eof/fail; track max, min, suma, count

```

### Ejercicio 3: Tabla con datos desde archivo

Use `setw` y `setprecision` para generar una tabla de al menos 3 columnas. Lea los datos de un archivo de texto y formatee la salida. Indique en comentario qué manipuladores usó.

```cpp
// #include <iomanip>; leer datos, luego imprimir con setw/setprecision/fixed

```

---

## Criterios de validación (para el profesor)

- [ ] Uso de `using namespace std;`
