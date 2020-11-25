#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Analiza y parsea los datos de los jugadores desde el archivo jugador.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return exito [1] si hubo error, [0] si no hubo error
 *
 */
int parser_JugadorATexto(FILE* pFile , LinkedList* pLista);


/** \brief Analiza y parsea los datos de los jugadores desde el archivo jugadores.csv (modo binario).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return exito [1] si hubo error, [0] si no hubo error
 *
 */
int parser_JugadorABinario(FILE* pFile , LinkedList* pLista);


#endif // PARSER_H_INCLUDED
