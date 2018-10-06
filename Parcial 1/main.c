#include <stdio.h>
#include <stdlib.h>
#include "Peliculas.h"
#include "Directores.h"
#define MAXPELICULAS 1000
#define MAXDIRECTORES 500

int main()
{
    sPelicula listadoPeliculas[MAXPELICULAS];
    sDirector listadoDirectores[MAXDIRECTORES];
    int opcion;

    do
    {
        system("cls");
        printf("===================================================\n");
        printf("|||                     |||                     |||\n");
        printf("|||  P E L I C U L A S  ||| D I R E C T O R E S |||\n");
        printf("|||                     |||                     |||\n");
        printf("===================================================\n");
        printf("    O P C I O N -1-             O P C I O N -2-\n");
        printf("===================================================\n");
        printf("                    S A L I R -3-\n");
        printf("===================================================\n");
        printf("\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            menuPeliculas(listadoPeliculas, MAXPELICULAS);
            break;
        case 2:
            menuDirectores(listadoDirectores, MAXDIRECTORES);
            break;
        }
    }
    while(opcion != 3);

    return 0;
}
