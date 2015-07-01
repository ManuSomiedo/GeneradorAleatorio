#ifndef GEN_AL_INCLUIDO
#define GEN_AL_INCLUIDO

#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::string;

class GeneradorAleatorio
{
private:
    vector<string> cadenas_usadas;  //Almacena las cadenas que ya han sido usadas y que se cargan desde el archivo usadas.data
    vector<string> cadenas_generadas;   //Almacena las caderas a generat

    const char* ruta_archivo_cadenas_usadas;    //Almacena la ruta del archivo usadas.data
    const char* ruta_archivo_cadenas_generadas; //Almacena la rauta del archivo de salida:  
public:
    GeneradorAleatorio(const char*, const char*);   //Inicia las rutas de archivo
    bool buscar_iguales(const string);  //Busca coincidencias entre el argumento proporcionado y los strings del vector cadenas generadas
    void cargar_archivo();  //Carga el archivo en el que se almacenan las cadenas usadas
    void guardar_archivos();    //Guarda los vectores cadenas_usadas y cadenas generadas en archivos de texto
    void generar_cadenas(const unsigned int);   //Genera un numero de cadenas aleatorias que no coinciden entre si
};

#endif // GEN_AL_INCLUIDO