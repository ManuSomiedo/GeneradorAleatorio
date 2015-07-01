#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <vector>
#include "generadoraleatorio.h"

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::fstream;
using std::endl;
using std::ios;

GeneradorAleatorio::GeneradorAleatorio(const char* rta_usadas, const char* rta_nueva)
{
    ruta_archivo_cadenas_usadas = rta_usadas;
    ruta_archivo_cadenas_generadas = rta_nueva;

}

void GeneradorAleatorio::guardar_archivos()
{
    ofstream flujo_salida_actual(ruta_archivo_cadenas_generadas, ios::trunc);
    ofstream flujo_salida_usadas(ruta_archivo_cadenas_usadas, ios::app);

    for(unsigned int i = 0; i < cadenas_generadas.size(); i++)
    {
        flujo_salida_actual<<cadenas_generadas.at(i)<<endl;
        flujo_salida_usadas<<cadenas_generadas.at(i)<<endl;
    }
}

void GeneradorAleatorio::cargar_archivo()
{
    ifstream flujo_entrada;
    flujo_entrada.open(ruta_archivo_cadenas_usadas, ios::in);

    if( !flujo_entrada.is_open() )
    {
        cout<<"No se encontro el archivo, creando uno nuevo"<<endl;
    }
    else
    {
        string linea;
        while(!flujo_entrada.eof())
        {
            getline(flujo_entrada,linea);
            cadenas_usadas.push_back(linea);
        }
    }
}

void GeneradorAleatorio::generar_cadenas(const unsigned int numero)
{
    srand( unsigned( time(NULL) ) );

    for(unsigned int i = 0; i < numero; i++)
    {
        string cadena_temporal;
        do
        {
            char caracter = 0;
            for(int x = 0; x < 7; x++)
            {
                caracter = 48 + rand() % 74;
                cadena_temporal.push_back(caracter);
            }

        }while( buscar_iguales(cadena_temporal) );

        cadenas_generadas.push_back(cadena_temporal);
        cadenas_usadas.push_back(cadena_temporal);
    }
}

bool GeneradorAleatorio::buscar_iguales(const string cadena_entrada)
{
    bool coincidencia_encontrada = false;
    for(unsigned int i = 0; i < cadenas_usadas.size(); i++)
    {
        cadena_entrada.compare(cadenas_usadas.at(i));
    }
    return coincidencia_encontrada;
}
