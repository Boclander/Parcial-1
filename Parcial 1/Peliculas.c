#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"
#define TAMANIO 1000
#define OCUPADO 0
#define LIBRE -1



int sPelicula_init( sPelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado=LIBRE;
            listado[i].id= 0;
        }
    }
    return retorno;
}

int sPelicula_buscarLugarLibre(sPelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int sPelicula_siguienteId(sPelicula listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].id>retorno)
                {
                    retorno=listado[i].id;
                }

            }
        }
    }

    return retorno+1;
}


int sPelicula_buscarPorId(sPelicula listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int sPelicula_mostrarUno(sPelicula parametro)
{
    printf(" %4d  %20s  %4d  %13s  %20s\n",parametro.id,parametro.nombre,parametro.anio, parametro.nacionalidad,
           parametro.director);

}

int sPelicula_mostrarListado(sPelicula listado[],int limite)
{
    int retorno = -1;
    int i;

    system("cls");
    printf("%4s  %20s  %4s  %4s  %20s\n", "ID", "Nombre", "Anio", "Nacionalidad", "Director");
    printf("==============================================================\n");
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {

                sPelicula_mostrarUno(listado[i]);
            }
        }
    }
    system("pause");
    return retorno;
}


int sPelicula_mostrarListadoConBorrados(sPelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            sPelicula_mostrarUno(listado[i]);
        }
    }
    return retorno;
}


int sPelicula_alta(sPelicula  listado[],int limite)
{
    int retorno = -1;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = sPelicula_buscarLugarLibre(listado,limite);
        if(indice == -1)
        {
            system("cls");
            printf("No queda espacio!");
            system("pause");
        }
        else if(indice >= 0)
        {
            retorno = -3;
            listado[indice].id = sPelicula_siguienteId(listado,limite);

            retorno = 0;
            fflush(stdin);
            system("cls");
            printf("Ingrese nombre de la pelicula: ");
            gets(listado[indice].nombre);
            fflush(stdin);
            printf("Ingrese anio de la pelicula: ");
            scanf("%d", &listado[indice].anio);
            fflush(stdin);
            printf("Ingrese siglas del pais de la pelicula: ");
            gets(listado[indice].nacionalidad);
            fflush(stdin);
            printf("Ingrese el director: ");
            gets(listado[indice].director);
            fflush(stdin);
            printf("Ingrese el identificador univoco de la pelicula: ");
            scanf("%d", &listado[indice].id);
            fflush(stdin);
            listado[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int sPelicula_altaListado(sPelicula listado[], int limite)
{
    int retorno =-1;
    int i;
    int seguir;

    for(i=0; i<limite; i++)
    {
        sPelicula_alta(listado, limite);
        seguir=preguntarIngresarPelicula();
        if(seguir == 0)
        {
            break;
        }
        else if(seguir == 1)
        {
            continue;
        }
    }
    return retorno;
}

int preguntarIngresarPelicula(void)
{
    int validarNumero;
    char rta;

    do
    {
        system("cls");
        printf("¿Desea ingresar otra pelicula?\n");
        printf("    (S para Si o N para No)\n");
        fflush(stdin);
        scanf("%c", &rta);

    }
    while(rta != 's' && rta != 'S' && rta != 'n' && rta != 'N');
    if (rta == 's' || rta == 'S')
    {
        validarNumero=1;
    }
    else if (rta == 'n' || rta == 'N')
    {
        validarNumero=0;
    }
    return validarNumero;
}

int sPelicula_ordenarNombre(sPelicula listado[], int limite)
{
    int retorno = -1;
    int i;
    int j;
    sPelicula aux;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite-1; i++)
        {
            for(j=i+1; j<limite; j++)
            {
                if(strcmp(listado[i].nombre, listado[j].nombre) > 0)
                    aux = listado[i];
                listado[i] = listado[j];
                listado[j] = aux;
            }
        }
    }
    return retorno;
}

int menu(sPelicula listadoPeliculas[], int limite, int opcion)
{
    system("cls");
    printf("==========================================================\n");
    printf("1.Ingresar una pelicula\n");
    printf("\n");
    printf("2.Mostrar listado de peliculas\n");
    printf("\n");
    printf("3.Salir\n");
    printf("============================================================\n");
    printf("\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        sPelicula_altaListado(listadoPeliculas, TAMANIO);
        break;
    case 2:
        sPelicula_mostrarListado(listadoPeliculas, TAMANIO);
        break;
    case 3:
        break;
    }

    return opcion;
}
