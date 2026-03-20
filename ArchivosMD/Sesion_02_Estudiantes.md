| <div align="right"><img src="../Logo-UNA-Rojo_FondoTransparente%20(2).png" width="120" alt="Logo UNA" /></div> | | <p align="right"><img src="../images.jpeg" width="120" alt="Logo EscINF" /></p> |
|:----------------------------------------------------|:-------------------------------------------------------------:|------------------------------------------------------------:|

**Programa de curso** · **Programación II**  
**Carrera:** Ingeniería de Sistemas de Información con grado en Bachillerato y salida lateral de Diplomado en Programación de Aplicaciones Informáticas.

---

# Semana 5 – Sesión 2 (Estudiantes)

**Duración:** 2 horas  
**Tema:** Flujos binarios y buenas prácticas

---

## Explicación (resumen)

- **Binario:** `read`/`write` con `char*` y tamaño; abrir con `ios::binary`. Mismo orden y tamaño al leer y escribir. No serializar punteros crudos.
- **Buenas prácticas:** Comprobar apertura y estado; cerrar flujos; no asumir que el archivo existe.

---

## Espacio para tu código

### Ejercicio 1: Array de enteros (datos dinámicos)

Genere un array de 10 enteros (leídos de `cin` o con bucle) y guárdelo en un archivo binario. Léalo en otro array y muéstrelo. Verifique apertura antes de leer/escribir.

```cpp
// Leer 10 int; ofstream ios::binary write; ifstream read; verificar !out, !in

```

### Ejercicio 2: Tres estructuras en binario

Defina `Registro { int id; double valor; }`. Guarde tres registros en un archivo binario (uno tras otro) y léalos en un bucle. En comentario indique riesgos si cambia orden o tamaño de miembros.

```cpp
// for: write(&r[i], sizeof(Registro)); read(&r2[i], sizeof(Registro));

```

### Ejercicio 3: Función leer N bytes + main de prueba

Función que lea los primeros N bytes en un buffer. Maneje archivo no encontrado y lectura incompleta. En `main`, invóquela y muestre cuántos bytes se leyeron (`gcount`).

```cpp
// Comprobar is_open(), gcount(); main que llama y muestra resultado

```

---

## Criterios de validación (para el profesor)

- [ ] Uso de `using namespace std;`
