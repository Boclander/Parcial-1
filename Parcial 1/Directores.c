#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Directores.h"
#include "Peliculas.h"
#define OCUPADO 0
#define LIBRE -1
#define BORRADO 1

int menuDirectores(sDirector listado[], int limite)
{
    int opcion;
    sDirector_inicializarLibre(listado, limite);

    do
    {
        system("cls");
        printf("====================================================\n");
        printf("1.Cargar directores\n");
        printf("\n");
        printf("2.Mostrar directores\n");
        printf("\n");
        printf("3.Borrar un director\n");
        printf("\n");
        printf("4.Salir\n");
        printf("====================================================\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            sDirector_altaListado(listado, limite);
            break;
        case 2:
            sDirector_mostrarListado(listado, limite);
            break;
        case 3:
            sDirector_borrarDirector(listado, limite);
            break;
        case 4:
            break;
        }
    }
    while(opcion != 4);

    return 0;

}

int sDirector_inicializarLibre(sDirector listado[], int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for (i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
        }
    }
    return retorno;
}

int sDirector_buscarLibre(sDirector listado[], int limite)
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

int sDirector_alta(sDirector listado[], int indice, int limite)
{
    char nombreIngresado[42];

    system("cls");
    fflush(stdin);
    printf("Ingrese nombre del director: ");
    gets(nombreIngresado);
    fflush(stdin);
    if((sDirector_buscarNombre(listado, nombreIngresado, limite)) == -1)
    {
        strcpy(listado[indice].nombre, nombreIngresado);
        printf("Fecha de nacimiento: \n");
        printf("        Dia: ");
        scanf("%d", &listado[indice].fechaNacimiento.dia);
        printf("        Mes: ");
        scanf("%d", &listado[indice].fechaNacimiento.mes);
        printf("        Anio: ");
        scanf("%d", &listado[indice].fechaNacimiento.anio);
        fflush(stdin);
        printf("Ingrese iniciales del pais: ");
        gets(listado[indice].nacionalidad);
        listado[indice].estado = OCUPADO;
    }
    else{
        printf("Ese nombre ya se ha ingresado!");
    }
    return 0;
}

int sDirector_altaListado(sDirector listado[], int limite)
{
    int retorno = -1;
    int i;
    int indice;
    int seguir;

    for(i=0; i<limite; i++)
    {
        indice = sDirector_buscarLibre(listado, limite);
        if(indice < 0)
        {
            break;
        }
        sDirector_alta(listado, indice, limite);
        seguir = sDirector_preguntarSeguirIngresando();
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

int sDirector_preguntarSeguirIngresando(void)
{
    int retorno;
    char rta;

    printf("=================================================\n");
    printf("        Desea ingresar otro director?\n");
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

int sDirector_mostrarListado(sDirector listado[], int limite)
{
    system("cls");
    int i;
    int retorno = -1;

    printf("%21s %20s %11s\n", "Nombre", "Fecha de nacimiento", "Nacionalidad");

    for(i=0; i<limite; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            sDirector_mostrarUnDirector(listado[i]);
        }
    }
    system("pause");
    return retorno;
}

int sDirector_mostrarUnDirector(sDirector unDirector)
{
    int retorno = -1;
    if(unDirector.estado == OCUPADO)
    {
        printf("%21s %3d %3d %5d %11s\n", unDirector.nombre, unDirector.fechaNacimiento.dia, unDirector.fechaNacimiento.mes,
                        unDirector.fechaNacimiento.anio, unDirector.nacionalidad);
    }
    return retorno;
}

int sDirector_buscarNombre(sDirector listado[], char nombreIngresado[], int limite)
{
    int i;
    int retorno = -1;

    for(i=0; i<limite; i++)
    {
        if(strcmp(listado[i].nombre, nombreIngresado) == 0)
        {
            retorno = i;
        }
    }
    return retorno;
}

int sDirector_borrarDirector(sDirector listado[], int limite)
{
    char nombreIngresado[42];
    int indice;
    char rta;

    printf("Ingrese el nombre del director: ");
    fflush(stdin);
    gets(nombreIngresado);
    indice = sDirector_buscarNombre(listado, nombreIngresado, limite);
    if(indice >= 0)
    {
        system("cls");
    printf("Esta seguro que desea borrar este director?\n");
    printf("     Ingrese S para Si o N para No\n");
    printf("\n");
    sDirector_mostrarUnDirector(listado[indice]);
    printf("\n");
    fflush(stdin);
    scanf("%c", &rta);
    if(rta == 's' || rta == 'S')
    {
        printf("Borrado!");
        listado[indice].estado = BORRADO;
    }
    else {
        printf("No se encontro ningun director");
        system("pause");
    }
    }

    return 0;
}
