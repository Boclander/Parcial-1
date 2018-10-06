#ifndef Directores

typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    char nombre[42];
    sFecha fechaNacimiento;
    char nacionalidad[4];
    int estado;
} sDirector;

/** \brief Menu de opciones de directores
 *
 * \param sDirector[] el array de directores
 * \param int limite de cantidad de directores
 * \return int retorno
 *
 */
int menuDirectores(sDirector[], int);

/** \brief Inicializa el vector de directores como libre
 *
 * \param sDirector[] el array de directores
 * \param int el limite
 * \return int retorno
 *
 */
int sDirector_inicializarLibre(sDirector[], int);

/** \brief Busca una posicion libre en el array
 *
 * \param sDirector[] el array de directores
 * \param int el limite
 * \return int el indice encontrado
 *
 */
int sDirector_buscarLibre(sDirector[], int);

/** \brief Carga un director
 *
 * \param sDirector[] el array de directores
 * \param int el limite
 * \param int el indice donde se lo quiere cargar
 * \return int retorno
 *
 */
int sDirector_alta(sDirector[], int, int);

/** \brief Carga un listado de directores
 *
 * \param sDirector[] el array de directores
 * \param int el limite
 * \return int retorno
 *
 */
int sDirector_altaListado(sDirector[], int);

/** \brief Busca un nombre igual al ingresado
 *
 * \param sDirector[] el array de directores
 * \param char[] el nombre ingresado
 * \param int el limite
 * \return int retorno - si se encontró o no
 *
 */
int sDirector_buscarNombre(sDirector[], char[], int);

/** \brief Pregunta si se quiere seguir ingresando directores
 *
 * \param void
 * \return int retorno - se sigue ingresando o no
 *
 */
int sDirector_preguntarSeguirIngresando(void);

/** \brief Muestra un director
 *
 * \param sDirector el elemento del array de directores a mostrar
 * \return int retorno
 *
 */
int sDirector_mostrarUnDirector(sDirector);

/** \brief Muestra el listado de directores (sin Vacios ni Borrados)
 *
 * \param sDirector[] el array de directores
 * \param int el limite
 * \return int retorno
 *
 */
int sDirector_mostrarListado(sDirector[], int);

/** \brief Borra un director del listado
 *
 * \param sDirector[] el array de directores
 * \param el limite
 * \return retorno
 *
 */

int sDirector_borrarDirector(sDirector[], int);
#endif // Directores
