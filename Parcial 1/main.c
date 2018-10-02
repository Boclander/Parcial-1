#include <stdio.h>
#include <stdlib.h>
#include "Peliculas.h"
#define TAMANIO 2

int main()
{
    sPelicula listadoPeliculas[TAMANIO];
    int opcion;

    sPelicula_init(listadoPeliculas, TAMANIO);
    do
    {
        opcion=menu(listadoPeliculas, TAMANIO, opcion);
    }
    while(opcion!=3);

    return 0;
}
