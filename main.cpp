#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

//Practica semanal Ejercicio 2.1
struct Registro
{
    int id;
    char nombre[20];
    double valor;
};

void escribirBinario(const string& nombreArchivo);
void leerBinario(const string& nombreArchivo);
bool leerDesdeOffset(const string& archivo, size_t offset, size_t n, vector<char>& buffer);

int main()
{
//Practica semanal Ejercicio 1.1
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

    //Practica semanal Ejercicio 1.2

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

    return 0;
}

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
