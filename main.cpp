#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

//Practica semanal Ejercicio 2
struct Registro
{
    int id;
    char nombre[20];
    double valor;
};

void escribirBinario(const string& nombreArchivo);
void leerBinario(const string& nombreArchivo);
bool leerDesdeOffset(const string& archivo, size_t offset, size_t n, vector<char>& buffer);

//Practica semanal Ejercicio 3
bool copiarArchivo(const string& original, const string& destino, size_t bloque);
bool compararArchivo(const string& f1, const string& f2);

//Sesion 1 Ejercicio 1
void numerarLineas (const string& entrada, const string& salida);

//Sesion 1 Ejercicio 2
void procesarNumeros(const string& entrada, const string& salida);


int main()
{
//Practica semanal Ejercicio 1
    ifstream archivo1("datos.txt");
    ofstream CSV("reporte.txt");

    if (!archivo1.good())
    {
        cout<<"Error al abrir archivo1\r\n"<<endl;
        return 1;
    }

    string linea;
    int cont =0;
    double suma =0, nota, maxNota, minNota;
    bool primer = true;

    while(getline(archivo1,linea))
    {
        if (archivo1.fail())
        {
            cout<<"Error al leer linea\r\n"<<endl;
        } else
        {
            if (!linea.empty())
            {
                stringstream ss(linea);
                string nombre, edad, notaSs;
                bool lineaValida = true;

                if (!getline(ss,nombre,',')) lineaValida = false;
                if (!getline(ss,edad,',')) lineaValida = false;
                if (!getline(ss,notaSs,',')) lineaValida = false;
                if (lineaValida)
                {
                    stringstream conversion(notaSs);
                    conversion >> nota;
                    if (conversion.fail())
                    {
                        cout<<"Nota invalida: "<<linea<<endl;
                    }else
                    {
                        if (primer)
                        {
                            maxNota = nota;
                            minNota = nota;
                            primer = false;
                        } else
                        {
                            if (nota > maxNota) maxNota = nota;
                            if (nota < minNota) minNota = nota;
                        }
                        suma += nota;
                        cont++;
                    }
                } else
                {
                    cout<<"Linea incorrecta: "<<linea<<endl;
                }
            }
        }
    }

    if (cont>0)
    {
        double promedio = suma/cont;
        CSV<<setw(15)<<"Promedio"
        <<setw(15)<<"Maximo"
        <<setw(15)<<"Minimo"<<endl;

        CSV<<fixed<<setprecision(2);

        CSV<<setw(15)<<promedio
       <<setw(15)<<maxNota
       <<setw(15)<<minNota<<endl;
    }else
    {
        cout<<"No hay datos validos\r\n";
    }

    archivo1.close();
    CSV.close();

    //Practica semanal Ejercicio 1

    ifstream a1("archivo1.txt");
    ifstream a2("archivo2.txt");
    ofstream salida("merge.txt");

    if (!a1.good() || !a2.good())
    {
        cout<<"Error al abrir archivos\r\n"<<endl;
        return 1;
    }

    if (!salida.good())
    {
        cout<<"Error al crear merge\r\n"<<endl;
        return 1;
    }

    string linea2;
    salida<<"----Archivo1.txt----"<<endl;
    while (getline(a1,linea2))
    {
        if (a1.fail()) {
    cout<<"Error leyendo archivo1"<<endl;
    }
        else{
        salida<<linea2<<endl;
        }
    }
    salida<<"----Archivo2.txt----"<<endl;
    while (getline(a2,linea2))
    {
        if (a2.fail()) {
            cout<<"Error leyendo archivo2"<<endl;
        }
        else{
            salida<<linea2<<endl;
        }
    }

    a1.close();
    a2.close();
    salida.close();

    //Practica semanal Ejercicio 2

    cout<<"Escribiendo binario"<<endl;
    escribirBinario("datos.bin");

    cout<<"Leyendo binario"<<endl;
    leerBinario("datos.bin");

    cout<<"Leyendo con offset"<<endl;
    vector<char> buffer;

    if (leerDesdeOffset("datos.bin",0,10,buffer))
    {
        cout<<"Bytes leidos: ";
        for (size_t i = 0; i < buffer.size(); i++)
        {
            cout<<(int)buffer[i]<<" ";
        }
        cout<<endl;
    }

    //Practica semanal Ejercicio 3

    cout<<"Copia por bloques"<<endl;
    copiarArchivo("datos.bin","copia.bin",512);

    cout<<"Comparador"<<endl;
    compararArchivo("datos.bin","copia.bin");


    //Sesion 1 Ejercicio 1

    numerarLineas("entrada.txt","salida.txt");

    //Sesion 1 Ejercicio 2
    procesarNumeros("numeros.txt","resultado.txt");







    return 0;
}

//Practica semanal Ejercicio 2
void escribirBinario(const string& nombreArchivo)
{
    ofstream binario(nombreArchivo, ios::binary);
    if (!binario.good())
    {
        cout<<"Error al abrir archivo binario\r\n"<<endl;
        return;
    }
    Registro datos[5] ={
        {1,"Ana",80.3},
        {2,"Luis",90.5},
        {3,"Maria",70.2},
        {4,"Pedro",72.3},
        {5,"Juan",84.7},
    };
    int cantidad =5;
    binario.write((char*)&cantidad,sizeof(int));
    binario.write((char*)datos,sizeof(datos));
    binario.close();
}

void leerBinario(const string& nombreArchivo)
{
    ifstream binario(nombreArchivo, ios::binary);
    if (!binario.good())
    {
        cout<<"Error al abrir archivo binario\r\n"<<endl;
        return;
    }

    int cantidad;
    binario.read((char*)&cantidad,sizeof(int));
    if (binario.fail() || cantidad <= 0)
    {
        cout<<"Cantidad invalida\r\n"<<endl;
        return;
    }

    Registro r;
    for (int i=0;i<cantidad;i++)
    {
        binario.read((char*)&r,sizeof(Registro));
        if (binario.fail())
        {
            cout<<"Error leyendo registro\r\n"<<endl;
        } else
        {
            cout<<r.id<<" - "<<r.nombre<<" - "<<r.valor<<endl;
        }
    }
    binario.close();
}

bool leerDesdeOffset(const string& archivo, size_t offset, size_t n, vector<char>& buffer)
{
    ifstream binario(archivo, ios::binary);
    if (!binario.good())
    {
        cout<<"Error al abrir archivo desde offset\r\n"<<endl;
        return false;
    }

    binario.seekg(0, ios::end);
    size_t tam = binario.tellg();

    if (offset >= tam)
    {
        cout<<"Offset fuera de rango\r\n";
        return false;
    }

    binario.seekg(offset, ios::beg);
    buffer.resize(n);
    binario.read(&buffer[0], n);

    if (binario.gcount()<n)
    {
        cout<<"Lectura incompleta\r\n";
        return false;
    }
    binario.close();
    return true;
}

//Practica semanal Ejercicio 3
bool copiarArchivo(const string& original, const string& destino, size_t bloque)
{
    ifstream binario(original, ios::binary);
    if (!binario.good())
    {
        cout<<"Error al abrir archivo original \r\n"<<endl;
        return false;
    }

    ofstream binSalida(destino, ios::binary);
    if (!binSalida.good())
    {
        cout<<"Error al crear archivo destino \r\n"<<endl;
        return false;
    }
    vector<char> buffer(bloque);
    while (binario)
    {
        binario.read(&buffer[0], bloque);
        streamsize leidos = binario.gcount();
        if (leidos > 0)
        {
            binSalida.write(&buffer[0], leidos);
        }
    }
    binario.clear();
    binario.seekg(0, ios::end);
    size_t tamO= binario.tellg();

    binSalida.seekp(0, ios::end);
    size_t tamD= binSalida.tellp();

    if (tamO != tamD)
    {
        cout<<"Tamanos distintos\r\n";
        return false;
    }
    cout<<"Copia hecha\r\n";
    return true;
}

bool compararArchivo(const string& f1, const string& f2)
{
    ifstream b1(f1, ios::binary);
    ifstream b2(f2, ios::binary);
    if (!b1.good() || !b2.good())
    {
        cout<<"Error al abrir archivos\r\n"<<endl;
        return false;
    }

    size_t posic =0;
    size_t diferencia =0;
    long distinta =-1;

    char d1, d2;
    while (true)
    {
        b1.read(&d1, 1);
        b2.read(&d2, 1);

        if (b1.gcount() ==0 && b2.gcount()==0) break;
        if (d1 != d2)
        {
            diferencia++;
            if (distinta == -1)
            {
                distinta = posic;
            }
        }
        posic++;
    }
    if (diferencia == 0)
    {
        cout<<"Archivos identicos\r\n";
    } else
    {
        cout<<"Archivos diferentes\r\n";
        cout<<"Primera diferencia: "<<distinta<<endl;
        cout<<"Diferencia total: "<<diferencia<<endl;
    }
    return true;
}

//Sesion 1 Ejercicio 1
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

//Sesion 1 Ejercicio 2
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
