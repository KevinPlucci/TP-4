#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombreCompleto[128];
    char nombreUsuario[128];
    char pais[21];
    int puntos;
}eJugador;


/** \brief Guarda espacio en memoria para el nuevo jugador
 *
 * \return Puntero al espacio guardado
 *
 */
eJugador* nuevo_Jugador();


/** \brief Carga los nuevos parametros de jugadores
 *
 * \param idStr char*
 * \param nombreCompletoStr char*
 * \param nombreUsuarioStr char*
 * \param paisStr char*
 * \param puntosStr char*
 * \return nuevo jugador
 *
 */
eJugador* jugadoresParametros(char* idStr, char* nombreCompletoStr, char* nombreUsuarioStr, char* paisStr, char* puntosStr);

/** \brief Borra un jugador de la lista
 *
 * \param this Employee*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int borrar_jugador(eJugador* this);


/** \brief Carga el id
 *
 * \param this eJugador*
 * \param id int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_setId(eJugador* this, int id);

/** \brief Carga el nombre
 *
 * \param this eJugador*
 * \param nombreCompleto char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_setNombreCompleto(eJugador* this, char* nombreCompleto);

/** \brief Carga el nombre de usuario
 *
 * \param this eJugador*
 * \param nombreUsuario char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_setNombreUsuario(eJugador* this, char* nombreUsuario);

/** \brief Carga el pais
 *
 * \param this eJugador*
 * \param pais char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_setPais(eJugador* this, char* pais);

/** \brief Carga los puntos
 *
 * \param this eJugador*
 * \param puntos int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_setPuntos(eJugador* this, int puntos);

/** \brief Asigna el id a un jugador
 *
 * \param this eJugador*
 * \param id int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_getId(eJugador* this, int* id);

/** \brief Asigna el nombre completo a un jugador
 *
 * \param this eJugador*
 * \param nombreCompleto char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_getNombreCompleto(eJugador* this, char* nombreCompleto);

/** \brief Asigna el nombre de usuario a un jugador
 *
 * \param this eJugador*
 * \param nombreUsuario char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_getNombreUsuario(eJugador* this, char* nombreUsuario);

/** \brief Asigna el pais a un jugador
 *
 * \param this eJugador*
 * \param pais char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_getPais(eJugador* this, char* pais);

/** \brief Asigna los puntos a un jugador
 *
 * \param this eJugador*
 * \param puntos int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_getPuntos(eJugador* this, int* puntos);

/** \brief Muestra un jugador si la lista no esta vacia
 *
 * \param pLista LinkedList*
 * \param indice int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int mostrarJugador(LinkedList* pLista, int indice);

/** \brief Recorre la lista de jugadores buscando uno por ID
 *
 * \param pLista LinkedList*
 * \param id int
 * \return int indice [-1] si hubo error, [i: posicion del empleado] si no hubo error
 *
 */
int buscarJugadorPorId(LinkedList* pLista, int id);

/** \brief Muestra el proximo ID
 *
 * \param pLista LinkedList*
 * \return int ultId
 *
 */
int jugador_proxId(LinkedList* pLista);

/** \brief Ordena los jugadores por nombre completo
 *
 * \param x void*
 * \param y void*
 * \return int cambio
 *
 */
int sortJugadorxNombreCompleto(void* x, void* y);

/** \brief Ordena los jugadores por puntos
 *
 * \param x void*
 * \param y void*
 * \return int cambio
 *
 */
int sortJugadorxPuntos(void* x, void* y);

#endif // JUGADOR_H_INCLUDED
