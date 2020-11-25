#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"

//The parser

int parser_JugadorATexto(FILE* pFile , LinkedList* pLista)
{
	int exito = 1;
	eJugador* pJugador;
	char id[200];
	char nombreCompleto[200];
	char nombreUsuario[200];
	char pais[200];
	char puntos[200];

	if(pFile != NULL && pLista != NULL)
	{
	    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, nombreUsuario, pais, puntos);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, nombreUsuario, pais, puntos) == 5)
			{
				pJugador = jugadoresParametros(id, nombreCompleto, nombreUsuario, pais, puntos);

				if(pJugador != NULL)//osea si pudo cargar
				{
					ll_add(pLista, pJugador);
					exito = 0;
				}
			}
			else
			{
				break;
			}

		}while(feof(pFile) == 0);
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

int parser_JugadorABinario(FILE* pFile , LinkedList* pLista)
{
	int exito = 1;
	eJugador* pJugador;

	if(pFile != NULL)
	{
		do
		{
			pJugador = nuevo_Jugador();
			if(fread(pJugador, sizeof(eJugador), 1, pFile) == 1)
			{
				ll_add(pLista, pJugador);
				printf("Aniadido con exito\n");
				exito = 0;
			}
		}while(!feof(pFile));
	}

    return exito;
}
