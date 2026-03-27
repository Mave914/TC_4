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
void guardarLeerEnteros(const string& archivo)
{
    int datos [10];
    cout<<"Ingrese 10 numeros: "<<endl;
    for (int i=0; i<10; i++)
    {
        cin>>datos[i];
    }

    ofstream s(archivo, ios::binary);
    if (!s.good())
    {
        cout<<"Error al abrir archivo salida\r\n";
        return;
    }

    s.write((char*)&datos, sizeof(datos));
    s.close();

    int copia [10];
    ifstream e(archivo, ios::binary);
    if (!e.good())
    {
        cout<<"Error al abrir archivo entrada\r\n";
        return;
    }
    e.read((char*)&copia, sizeof(copia));
    e.close();

    cout<<"Datos leidos: "<<endl;
    for (int i=0; i<10; i++)
    {
        cout<<copia[i]<<endl;
    }
}

```

### Ejercicio 2: Tres estructuras en binario

Defina `Registro { int id; double valor; }`. Guarde tres registros en un archivo binario (uno tras otro) y léalos en un bucle. En comentario indique riesgos si cambia orden o tamaño de miembros.

```cpp
// for: write(&r[i], sizeof(Registro)); read(&r2[i], sizeof(Registro));
void registrosBinarios(const string& archivo)
{
    Registro2 r[3] ={
        {1, 12},
        {1, 20.5},
        {3, 22.4}
    };
    ofstream s(archivo, ios::binary);
    if (!s.good())
    {
        cout<<"Error al abrir archivo salida\r\n";
        return;
    }
     for (int i=0; i<3; i++)
     {
         s.write((char*)&r[i], sizeof(Registro2));
     }
    s.close();

    ifstream e(archivo, ios::binary);
    if (!e.good())
    {
        cout<<"Error al abrir archivo entrada\r\n";
        return;
    }
    Registro2 r2[3];
    for (int i=0; i<3; i++)
    {
        e.read((char*)&r2[i], sizeof(Registro2));

        if (e.fail())
        {
            cout<<"Error leyendo\r\n";
        } else
        {
            cout<<r2[i].id<<" - "<<r2[i].valor<<endl;
        }
    }
    e.close();
}
//Si cambia el orden o tamano, los datos no van a coincidir con los escritos y el archivo binario depende de la estructyura

```

### Ejercicio 3: Función leer N bytes + main de prueba

Función que lea los primeros N bytes en un buffer. Maneje archivo no encontrado y lectura incompleta. En `main`, invóquela y muestre cuántos bytes se leyeron (`gcount`).

```cpp
// Comprobar is_open(), gcount(); main que llama y muestra resultado
bool leerNBytes(const string& archivo, size_t n, vector<char>& buffer, size_t& leidos)
{
    ifstream e(archivo, ios::binary);
    if (!e.is_open())
    {
        cout<<"Archivo no encontrador\n";
        return false;
    }

    buffer.resize(n);
    e.read(&buffer[0], n);
    leidos = e.gcount();

    if (leidos<n)
    {
        cout<<"Lectura incompleta\n";
    }
    e.close();
    return true;
}

 //Sesion 2 Ejercicio 3
    vector<char> buffer2;
    size_t leidos;

    if (leerNBytes("datos.bin",20, buffer2,leidos))
    {
        cout<<"Bytes leidos: "<<leidos<<endl;
        for (size_t i = 0; i < leidos; i++)
        {
            cout<<(int)buffer2[i]<<" ";
        }
    }

```

---

## Criterios de validación (para el profesor)

- [ ] Uso de `using namespace std;`
