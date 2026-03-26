| <div align="right"><img src="../Logo-UNA-Rojo_FondoTransparente%20(2).png" width="120" alt="Logo UNA" /></div> | | <p align="right"><img src="../images.jpeg" width="120" alt="Logo EscINF" /></p> |
|:----------------------------------------------------|:-------------------------------------------------------------:|------------------------------------------------------------:|

**Programa de curso** · **Programación II**  
**Carrera:** Ingeniería de Sistemas de Información con grado en Bachillerato y salida lateral de Diplomado en Programación de Aplicaciones Informáticas.

---

# Semana 5 – Práctica semanal

**Contenidos:** Manejo de flujos (texto y binario).

---

## Actividad 1 (Flujos de texto – nivel avanzado)

- **Parser CSV:** Lea un archivo CSV con al menos 3 columnas (ej.: `nombre,edad,nota` por línea). Calcule el promedio de la columna numérica (nota), identifique el valor máximo y mínimo, y escriba un reporte en otro archivo con formato tabular usando `setw` y `setprecision`. Debe manejar líneas con formato incorrecto (mostrar advertencia y omitir sin abortar). Compruebe estados del flujo tras cada lectura.
- **Merge con cabeceras:** Lea dos archivos de texto y genere un tercero que contenga ambos concatenados, cada uno precedido por una cabecera indicando el nombre del archivo origen. Use `getline` y verifique apertura de cada archivo.

---

## Actividad 2 (Flujos binarios – nivel avanzado)

- **Array de estructuras:** Serialice un array de al menos 5 estructuras `Registro { int id; char nombre[20]; double valor; }` en un archivo binario. El formato debe ser: primero un entero con la cantidad de registros, luego los datos. Escriba un programa separado (o función distinta) que lea ese archivo, valide la cantidad y muestre los registros. En MD documente por qué no se puede serializar directamente un `std::string` en la estructura.
- **Lectura con offset:** Implemente una función `bool leerDesdeOffset(const string& archivo, size_t offset, size_t n, vector<char>& buffer)` que lea `n` bytes desde la posición `offset` (no desde el inicio). Maneje: archivo no encontrado, offset fuera de rango, lectura incompleta. Use `seekg` y `tellg`.

**DOCUMENTACION:**
No se puede serializar `std::string`, porque no guarda el texto dentro de la estructura como tal sino en otra parte de la memoria, es decir guarda referencias no los datos concretos. 
---

## Actividad 3 (Robustez y combinación texto/binario)

- **Copia por bloques:** Implemente una función que copie un archivo (texto o binario) a otro por bloques de tamaño configurable (ej. 512 bytes). Verifique que el archivo destino tenga exactamente el mismo tamaño que el origen usando `tellg`/`tellp`. Maneje archivo origen inexistente o sin permisos de lectura.
- **Comparador binario:** Escriba un programa que compare dos archivos binarios byte a byte. Indique si son idénticos o, si no, en qué posición (byte) se encuentra la primera diferencia y cuántas diferencias hay en total. Documente en MD el uso de comprobación de apertura y de estado.

---

**Formato de entrega:** Código y comentarios en **archivo(s) MD (Markdown)**.
