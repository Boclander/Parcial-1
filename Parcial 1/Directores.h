#ifndef SDIRECTOR_H_INCLUDED
#define SDIRECTOR_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    char nombre[50];
    int sFecha;
    char pais[4];
} sDirector;
#endif // SDIRECTOR_H_INCLUDED
