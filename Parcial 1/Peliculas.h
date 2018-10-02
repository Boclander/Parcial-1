#ifndef SPELICULA_H_INCLUDED
#define SPELICULA_H_INCLUDED
typedef struct
{
    char nombre[21];
    int anio;
    char nacionalidad[4];
    char director[42];
    int id;
    int estado;
} sPelicula;
#endif // SPELICULA_H_INCLUDED

int menu (sPelicula[], int limite, int opcion);
int sPelicula_init(sPelicula[],int limite);
int sPelicula_buscarPorId(sPelicula[],int limite, int id);
int sPelicula_siguienteId(sPelicula[],int limite);
int sPelicula_buscarLugarLibre(sPelicula listado[],int limite);

int sPelicula_mostrarUno(sPelicula parametro);
int sPelicula_mostrarListado(sPelicula[],int limite);
int sPelicula_mostrarListadoConBorrados(sPelicula[],int limite);

int sPelicula_altaListado(sPelicula[], int limite);
int sPelicula_alta(sPelicula[],int limite);
int sPelicula_baja(sPelicula[],int limite, int id);
int sPelicula_modificacion(sPelicula[],int limite, int id);

int sPelicula_ordenarNombre(sPelicula[],int limite);

int preguntarIngresarPelicula(void);
