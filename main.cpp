#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

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

    return 0;
}

