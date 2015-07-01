/*
* Programador del archivo: Manuel Ángel Suarez Álvarez
* Nombre programa: Generador aleatorio
* Uso: Pasar como argumento al programa desde la linea de comandos el numero de codigos a generar en esta iteracion
*/
#include "generadoraleatorio.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
    int numero = atoi(argv[1]);
    GeneradorAleatorio GA("usadas.data","actual.data");
    GA.cargar_archivo();
    GA.generar_cadenas(numero);
    GA.guardar_archivos();

    return 0;
}
