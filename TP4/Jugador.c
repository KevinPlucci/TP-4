#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "utn.h"
#include <string.h>


eJugador* nuevo_Jugador()
{
	return (eJugador*) malloc(sizeof(eJugador));
}

//---------------------------------------------------------------------------------------------------

eJugador* jugadoresParametros(char* idStr, char* nombreCompletoStr, char* nombreUsuarioStr, char* paisStr, char* puntosStr)
{
	eJugador* nJugador = NULL;
	nJugador = nuevo_Jugador();

	if(puntosStr != NULL && idStr != NULL && nombreCompletoStr != NULL && nombreUsuarioStr != NULL && paisStr != NULL)
	{

		if(jugador_setId(nJugador, atoi(idStr)) == -1 ||
            jugador_setNombreCompleto(nJugador, nombreCompletoStr) == -1 ||
            jugador_setNombreUsuario(nJugador, nombreUsuarioStr) == -1 ||
            jugador_setPais(nJugador, paisStr) == -1 ||
            jugador_setPuntos(nJugador, atoi(puntosStr)) == -1)
		{
			borrar_jugador(nJugador);
			nJugador = NULL;
		}
		else
        {
            jugador_setId(nJugador, atoi(idStr));
            jugador_setNombreCompleto(nJugador, nombreCompletoStr);
            jugador_setNombreUsuario(nJugador, nombreUsuarioStr);
            jugador_setPais(nJugador, paisStr);
            jugador_setPuntos(nJugador, atoi(puntosStr));
        }
	}

	return nJugador;
}

//---------------------------------------------------------------------------------------------------

int borrar_jugador(eJugador* this)
{
	int exito = 1;

	if(this != NULL)
	{
		free(this);
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------
//------------------------------------------ SETTERS ------------------------------------------------

int jugador_setId(eJugador* this, int id)
{
	int exito = 1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int jugador_setNombreCompleto(eJugador* this, char* nombreCompleto)
{
	int exito = 1;

	if(this != NULL && nombreCompleto != NULL)
	{
        strncpy(this->nombreCompleto, nombreCompleto, 128);
        exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int jugador_setNombreUsuario(eJugador* this, char* nombreUsuario)
{
	int exito = 1;

	if(this != NULL && nombreUsuario != NULL)
	{
        strncpy(this->nombreUsuario, nombreUsuario, 128);
        exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int jugador_setPais(eJugador* this, char* pais)
{
	int exito = 1;

	if(this != NULL && pais != NULL)
	{
	    strncpy(this->pais, pais, 21);
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int jugador_setPuntos(eJugador* this, int puntos)
{
	int exito = 1;

	if(this != NULL && puntos >= 0)
	{
		this->puntos = puntos;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------
//------------------------------------------ GETTERS ------------------------------------------------

int jugador_getId(eJugador* this, int* id)
{
	int exito = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int jugador_getNombreCompleto(eJugador* this, char* nombreCompleto)
{
	int exito = 1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strncpy(nombreCompleto, this->nombreCompleto, 128);
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int jugador_getNombreUsuario(eJugador* this, char* nombreUsuario)
{
	int exito = 1;

	if(this != NULL && nombreUsuario != NULL)
	{
		strncpy(nombreUsuario, this->nombreUsuario, 128);
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int jugador_getPais(eJugador* this, char* pais)
{
	int exito = 1;

	if(this != NULL && pais != NULL)
	{
		strncpy(pais, this->pais, 21);
		exito = 0;
	}

	return exito;
}

//------------------------------------------------------------------

int jugador_getPuntos(eJugador* this, int* puntos)
{
	int exito = 1;

	if(this != NULL && puntos != NULL)
	{
		*puntos = this->puntos;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int mostrarJugador(LinkedList* pLista, int indice)
{
	int auxId;
	char auxNombreC[128];
	char auxNombreU[128];
	char auxPais[21];
	int auxPuntos;
	int exito = 1;

	eJugador* pJugador;

	if(pLista != NULL && indice >= 0)
	{
	    pJugador = ll_get(pLista, indice);

		jugador_getId(pJugador, &auxId);
        jugador_getNombreCompleto(pJugador, auxNombreC);
        jugador_getNombreUsuario(pJugador, auxNombreU);
        jugador_getPais(pJugador, auxPais);
        jugador_getPuntos(pJugador, &auxPuntos);

        printf("%-5d \t%-30s %-20s \t%-20s \t%-30d \n", auxId, auxNombreC, auxNombreU, auxPais, auxPuntos);

        exito = 0;
	}
    else if(exito == 1)
    {
        printf("Error\n");
    }

	return exito;

}

//---------------------------------------------------------------------------------------------------

int buscarJugadorPorId(LinkedList* pLista, int id)
{
	int indice = -1;
	eJugador* pJugador = nuevo_Jugador();
	int flagId = 1;
    int auxId = 0;

	for(int i = 0; i < ll_len(pLista); i++)
	{
		pJugador = (eJugador*) ll_get(pLista, i);

		if(!(jugador_getId(pJugador, &auxId)) && auxId == id)
		{
			indice = i;
			flagId = 0;
			break;
		}
	}

	if(flagId == 1) //Si el flag sigue valiendo 1
    {
        printf("No hay registro de jugadores con ese ID\n");
    }

	return indice;
}

//---------------------------------------------------------------------------------------------------

int jugador_proxId(LinkedList* pLista)
{
	eJugador* pJugador;
	int auxId;
	int ultId = 0;
	int flagId = 0;

	if(pLista != NULL)
	{
		for(int i = 0; i < ll_len(pLista); i++)
		{
			pJugador = (eJugador*) ll_get(pLista, i);
			jugador_getId(pJugador, &auxId);

			if(auxId > ultId || flagId == 0)
			{
				ultId = auxId;
				flagId = 1;
			}
		}
	}
	return ultId;
}

//---------------------------------------------------------------------------------------------------

int sortJugadorxNombreCompleto(void* x, void* y)
{
	int cambio;
	char nombreUno[128];
	char nombreDos[128];

	jugador_getNombreCompleto(x, nombreUno);
	jugador_getNombreCompleto(y, nombreDos);

	if(strcmp(nombreUno, nombreDos) > 0)
	{

		cambio = 1;

	}
	else if(strcmp(nombreUno, nombreDos) < 0)
	{

		cambio = -1;

	}

	return cambio;
}

//---------------------------------------------------------------------------------------------------

int sortJugadorxPuntos(void* x, void* y)
{

		int cambio;
		int puntosUno;
		int puntosDos;

		jugador_getPuntos(x, &puntosUno);
		jugador_getPuntos(y, &puntosDos);

		if(puntosUno>puntosDos)
		{

			cambio = 1;

		}
		else if(puntosUno<puntosDos)
		{

			cambio = -1;

		}

		return cambio;
}

//---------------------------------------------------------------------------------------------------
