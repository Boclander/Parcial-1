#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"
#define MAXPELICULAS 1000
#define OCUPADO 0
#define LIBRE -1
#define BORRADO 1

int sPelicula_inicializarLibre(sPelicula listado[], int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for (i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].id = 0;
        }
    }
    return retorno;
}

int menuPeliculas(sPelicula listado[], int limite)
{
    int opcion;
    int retorno = -1;

    sPelicula_inicializarLibre(listado, limite);
    //sPelicula_cargarPeliculasHardcode(listado, limite);

    do
    {
        system("cls");
        printf("====================================================\n");
        printf("1.Cargar peliculas\n");
        printf("\n");
        printf("2.Mostrar peliculas\n");
        printf("\n");
        printf("3.Modificar una pelicula\n");
        printf("\n");
        printf("4.Borrar una pelicula\n");
        printf("\n");
        printf("5.Salir\n");
        printf("====================================================\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            sPelicula_altaListado(listado, limite);
            break;
        case 2:
            sPelicula_mostrarListado(listado, limite);
            break;
        case 3:
            sPelicula_modificarPeliculaPorID(listado, limite);
            break;
        case 4:
            sPelicula_borrarPelicula(listado, limite);
            break;
        }
    }
    while(opcion != 5);

    return retorno;
}

int sPelicula_buscarLibre(sPelicula listado[], int limite)
{
    int retorno = -1;
    int i;

    for(i=0; i<limite; i++)
    {
        if(listado[i].estado == LIBRE)
        {
            retorno = i;
            break;
        }
    }
    if(retorno == -1)
    {
        printf("No queda espacio!!\n");
        system("pause");
        retorno = -8;
    }
    return retorno;
}

int sPelicula_alta(sPelicula listado[], int indice)
{
    system("cls");
    fflush(stdin);
    printf("Ingrese nombre de la pelicula: ");
    gets(listado[indice].nombre);
    fflush(stdin);
    printf("Ingrese anio de la pelicula: ");
    scanf("%d", &listado[indice].anio);
    fflush(stdin);
    printf("Ingrese iniciales del pais de la pelicula: ");
    gets(listado[indice].nacionalidad);
    fflush(stdin);
    printf("Ingrese director: ");
    gets(listado[indice].director);
    fflush(stdin);
    printf("Ingrese ID: ");
    scanf("%d", &listado[indice].id);
    fflush(stdin);
    listado[indice].estado = OCUPADO;

    return 0;
}

int sPelicula_altaListado(sPelicula listado[], int limite)
{
    int retorno = -1;
    int i;
    int indice;
    int seguir;

    for(i=0; i<limite; i++)
    {
        indice = sPelicula_buscarLibre(listado, limite);
        if(indice < 0)
        {
            break;
        }
        sPelicula_alta(listado, indice);
        seguir = sPelicula_preguntarSeguirIngresando();
        if(seguir == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return retorno;
}

int sPelicula_preguntarSeguirIngresando(void)
{
    int retorno;
    char rta;

    printf("=================================================\n");
    printf("        Desea ingresar otra pelicula?\n");
    printf("            S para Si, N para No\n");
    printf("\n");
    scanf("%c", &rta);
    fflush(stdin);
    while(rta != 's' && rta != 'S' && rta != 'n' && rta != 'N')
    {
        printf("Ingrese una opcion valida: ");
        scanf("%c", &rta);
        fflush(stdin);
    }

    if(rta == 's' || rta == 'S')
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int sPelicula_mostrarListado(sPelicula listado[], int limite)
{
    system("cls");
    int i;
    int retorno = -1;

    printf("%5s %21s %5s %11s %21s\n", "ID", "Nombre", "Anio", "Nacionalidad", "Director");

    for(i=0; i<limite; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            sPelicula_mostrarUnaPelicula(listado[i]);
        }
    }
    system("pause");
    return retorno;
}

int sPelicula_mostrarUnaPelicula(sPelicula unaPelicula)
{
    int retorno = -1;

    printf("%5d %21s %5d %6s %21s\n", unaPelicula.id, unaPelicula.nombre, unaPelicula.anio, unaPelicula.nacionalidad,
           unaPelicula.director);
    return retorno;
}

int sPelicula_buscarPeliculaPorID(sPelicula listado[], int limite)
{
    int i;
    int idBuscar;
    int retorno = -1;

    system ("cls");
    printf("Ingrese el ID de la pelicula a buscar: ");
    scanf("%d", &idBuscar);
    for(i=0; i<limite; i++)
    {
        if(listado[i].id == idBuscar)
        {
            retorno = i;
        }
    }
    if(retorno == -1)
    {
        printf("No se encontro la pelicula\n");
        system("pause");
    }
    return retorno;
}

int sPelicula_modificarPeliculaPorID(sPelicula listado[], int limite)
{
    int indice;
    int retorno;
    char rta;
    int opcionModif;

    indice = sPelicula_buscarPeliculaPorID(listado, limite);
    if(indice >= 0)
    {
        system("cls");
        printf("Esta seguro que desea modificar esta pelicula?\n");
        printf("        Ingrese S para Si o N para No\n");
        printf("\n");
        printf("%5d %21s %5d %6s %21s\n", listado[indice].id, listado[indice].nombre, listado[indice].anio,
               listado[indice].nacionalidad, listado[indice].director);
        printf("\n");
        fflush(stdin);
        scanf("%c", &rta);
        if(rta == 's' || rta == 's')
        {
            printf("1. Modificar nombre\n");
            printf("2. Modificar anio\n");
            printf("3. Modificar nacionalidad\n");
            printf("4. Modificar director\n");
            printf("\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opcionModif);

            sPelicula_cargarDatosModificados(listado, indice, opcionModif);
            retorno = -1;
        }
    }

    return retorno;
}

int sPelicula_cargarDatosModificados(sPelicula listado[], int indice, int opcionModif)
{
    system("cls");

    switch(opcionModif)
    {
    case 1:
        fflush(stdin);
        printf("Ingrese nuevo nombre: ");
        gets(listado[indice].nombre);
        break;
    case 2:
        fflush(stdin);
        printf("Ingrese nuevo anio: ");
        scanf("%d", &listado[indice].anio);
        break;
    case 3:
        fflush(stdin);
        printf("Ingrese nuevas iniciales del pais: ");
        gets(listado[indice].nacionalidad);
        break;
    case 4:
        fflush(stdin);
        printf("Ingrese nuevo director: ");
        gets(listado[indice].director);
        break;
    }
    return -1;
}

int sPelicula_borrarPelicula(sPelicula listado[], int limite)
{
    int indice;
    int retorno;
    char rta;

    system("cls");

    indice = sPelicula_buscarPeliculaPorID(listado, limite);
    if(indice >= 0)
    {
        system("cls");
        printf("Esta seguro que desea borrar esta pelicula?\n");
        printf("        Ingrese S para Si o N para No\n");
        printf("\n");
        printf("%5d %21s %5d %6s %21s\n", listado[indice].id, listado[indice].nombre, listado[indice].anio,
               listado[indice].nacionalidad, listado[indice].director);
        printf("\n");
        fflush(stdin);
        scanf("%c", &rta);
        if(rta == 's' || rta == 's')
        {
            printf("Pelicula borrada!");
            listado[indice].estado = BORRADO;
            retorno = -1;
        }
    }
    return retorno;
}

/*int sPelicula_cargarPeliculasHardcode(sPelicula listado[], int limite)
{
    int i;
    char nombres[10][21]={"Beetlejuice", "Relatos salvajes", "Princess Mononoke",
        "Infinity War", "Captain America", "Corpse Bride", "Pulp fiction", "Men in Black",
        "Ice Age", "Your Name", "Spiderman"};
    int anios[10][5] ={1995, 2015, 2006, 2018, 2015, 2007, 1999, 2006, 2004, 2016, 2008};
    int ids[10][4]={100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    char nacionalidades[10][4] ={"USA", "ARG", "JPN", "USA", "USA", "GBT", "USA", "FRA", "FRA", "JPN", "USA"};
    char directores[10][42] ={"Tim Burton", "Juan Jose Campanella", "Robert Miyazaki", "Dale Carnerige", "Dale Carnerige"
        , "Tim Burton", "Will Smith", "Will Smith", "Joseph Miner", "Hisaki Masashi", "Dale Carnerige"};

    for(i=0; i<limite; i++)
    {
        strcpy(listado[i].nombre, nombres[i]);
        listado[i].anio = anios[i];
        listado[i].id = ids[i];
        strcpy(listado[i].nacionalidad, nacionalidades[i]);
        strcpy(listado[i].director, directores[i]);
        listado[i].estado = OCUPADO;
    }
    return 0;
}
*/
