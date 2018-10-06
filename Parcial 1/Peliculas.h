#ifndef Peliculas
typedef struct
{
    char nombre[21];
    int anio;
    char nacionalidad[4];
    char director[42];
    int id;
    int estado;
} sPelicula;

/** \brief Menu de opciones para peliculas
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int retorno
 *
 */
int menuPeliculas(sPelicula[], int);

/** \brief Inicializa el array de peliculas como vacio
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int retorno
 *
 */
int sPelicula_inicializarVacio(sPelicula[], int);

/** \brief Busca un elemento vacio en el array de peliculas
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int el indice del elemento vacio
 *
 */
int sPelicula_buscarLibre(sPelicula[], int);

/** \brief Carga una pelicula
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int retorno
 *
 */
int sPelicula_alta(sPelicula[], int);

/** \brief Carga un listado de peliculas
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int retorno
 *
 */
int sPelicula_altaListado(sPelicula[], int);

/** \brief Pregunta si se quieren seguir ingresando peliculas
 *
 * \param void
 * \return int retorno - si se quiere seguir ingresando o no
 *
 */
int sPelicula_preguntarSeguirIngresando(void);

/** \brief Muestra una pelicula del array
 *
 * \param sPelicula un elemento del array de peliculas
 * \return int retorno
 *
 */
int sPelicula_mostrarUnaPelicula(sPelicula);

/** \brief Muestra el listado de peliculas (sin Vacio ni Borrados)
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int retorno
 *
 */
int sPelicula_mostrarListado(sPelicula[], int);

/** \brief Busca una pelicula por su ID
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int retorno - si se encontro o no
 *
 */
int sPelicula_buscarPeliculaPorID(sPelicula[], int);

/** \brief Llama a las funciones necesarias para modificar una pelicula que se buscó por ID
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int retorno - si fue modificado o no
 *
 */
int sPelicula_modificarPeliculaPorID(sPelicula[], int);

/** \brief Modifica los datos de una pelicula buscada por ID
 *
 * \param sPelicula[] el array de peliculas
 * \param int el indice en el array
 * \param int respuesta a qué dato se deseaba modificar
 * \return int retorno
 *
 */
int sPelicula_cargarDatosModificados(sPelicula[], int, int);

/** \brief Borra una pelicula que se buscó por ID
 *
 * \param sPelicula[] el array de peliculas
 * \param int el limite
 * \return int retorno - si fue borrada o no
 *
 */
int sPelicula_borrarPelicula(sPelicula[], int);
#endif // Peliculas
