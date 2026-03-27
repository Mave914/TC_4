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

void numerarLineas(const string& entrada, const string& salida)
{
    ifstream e(entrada);
    ofstream s(salida);
    if (!e.good())
    {
        cout<<"Error al abrir archivo entrada\r\n";
        return;
    }

    if (!s.good())
    {
        cout<<"Error al abrir archivo salida\r\n";
        return;
    }

    string linea;
    int cont =1;

    while (getline(e,linea))
    {
        if (!linea.empty() && linea[0] != '#')
        {
            s<<cont<<". "<<linea<<endl;
            cont++;
        }

    }

    e.close();
    s.close();
}

```

### Ejercicio 2: Estadísticas de números en archivo

Lea desde un archivo una lista de números. Calcule promedio, máximo y mínimo; escriba los tres en otro archivo y en pantalla. Si encuentra valor no numérico, muestre advertencia y continúe. Compruebe el estado del flujo.

```cpp
// Lectura con >>; comprobar good/eof/fail; track max, min, suma, count
void procesarNumeros(const string& entrada, const string& salida)
{
    ifstream e(entrada);
    ofstream s(salida);
    if (!e.good())
    {
        cout<<"Error al abrir archivo entrada\r\n";
        return;
    }
    if (!s.good())
    {
        cout<<"Error al abrir archivo salida\r\n";
        return;
    }
    double num, suma=0, max, min;
    int cont = 0;
    bool primer = true;

    while (e>>num)
    {
        if (primer)
        {
            max = num;
            min = num;
            primer = false;
        } else
        {
            if (num > max) max = num;
            if (num < min) min = num;
        }
        suma += num;
        cont++;
    }
    if (e.fail()&& !e.eof()) {cout<<"ADVERTENCIA"<<endl;}
    if (cont > 0)
    {
        double promedio = suma / cont;
        cout<<"Promedio: "<<promedio<<endl;
        cout<<"Maximo: "<<max<<endl;
        cout<<"Minimo: "<<min<<endl;

        s<<"Promedio: "<<promedio<<endl;
        s<<"Maximo: "<<max<<endl;
        s<<"Minimo: "<<min<<endl;
    } else
    {
        cout<<"No hay datos"<<endl;
    }
    e.close();
    s.close();
}

```

### Ejercicio 3: Tabla con datos desde archivo

Use `setw` y `setprecision` para generar una tabla de al menos 3 columnas. Lea los datos de un archivo de texto y formatee la salida. Indique en comentario qué manipuladores usó.

```cpp
// #include <iomanip>; leer datos, luego imprimir con setw/setprecision/fixed
void tabla(const string& entrada, const string& salida)
{
    ifstream e(entrada);
    ofstream s(salida);
    if (!e.good())
    {
        cout<<"Error al abrir archivo entrada\r\n";
        return;
    }
    if (!s.good())
    {
        cout<<"Error al abrir archivo salida\r\n";
        return;
    }

    string nombre;
    double n1, n2;

    s<<setw(15)<<"Nombre"
    <<setw(15)<<"Nota 1"
    <<setw(15)<<"Nota 2"<<endl;

    s<<fixed<<setprecision(2);
    while (e>>nombre>>n1>>n2)
    {
        if (e.fail())
        {
            cout<<"Error en datosr\n";
        } else
        {
            s<<setw(15)<<nombre
            <<setw(15)<<n1
            <<setw(15)<<n2<<endl;
        }
    }
    e.close();
    s.close();
}
```

---

## Criterios de validación (para el profesor)

- [ ] Uso de `using namespace std;`
