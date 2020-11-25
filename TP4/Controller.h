#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/** \brief Carga los datos de los jugadores desde el archivo jugador.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int cargarTexto(char* path , LinkedList* pLista);

/** \brief Carga los datos de los jugadores desde el archivo jugador.csv (modo binario).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int cargarBinario(char* path , LinkedList* pLista);

/** \brief Toma el id desde el archivo
 *
 * \param id int*
 * \return int error [1] si hubo error, [0] si no hubo error
 *
 */
int obetenerId(int* id);

/** \brief Actualiza el id
 *
 * \param id int
 * \return int error [1] si hubo error, [0] si no hubo error
 *
 */
int actualizarId(int id);

/** \brief Da de alta a un nuevo jugador
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int agregarJugador(char* path , LinkedList* pLista);

/** \brief Modifica los datos de un jugador elegido por ID
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int editarJugador(LinkedList* pLista);

/** \brief Muestra las opciones para elegir la modificacion del jugador
 *
 * \return opcion elegida
 *
 */
int menuModificar();

/** \brief Da de baja a un jugador
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int eliminarJugador(LinkedList* pLista);

/** \brief Lista a los jugadores
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int mostrarJugadores(LinkedList* pLista);

/** \brief Ordena los jugadores
 *
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int sortJugador(LinkedList* pLista);

/** \brief Muestra las opciones para elegir el orden de los jugador
 *
 * \return opcion elegida
 *
 */
int menuSortJugador();

/** \brief Guarda los datos de los jugadores en el archivo jugador.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int guardarComoTexto(char* path, LinkedList* pLista);

/** \brief Guarda los datos de los jugadores en el archivo jugador.csv (modo binario).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int guardarComoBinario(char* path, LinkedList* pLista);

#endif // CONTROLLER_H_INCLUDED
