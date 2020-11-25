#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Controller.h"

int menu();

int main()
{
    char confirm;
    char seguir = 's';
    int flagTexto = 0;
    int flagBinario = 0;

    LinkedList* listaJugadores = ll_newLinkedList();
    //LinkedList* listaFiltrada;

    if(listaJugadores == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }
    printf("Lista declarada!!!\n");

    do{
        switch(menu())
        {
            case 1:
            	if(flagBinario != 1)//No existe
            	{
            		if(!cargarTexto("jugador.csv", listaJugadores))
					{
						flagTexto = 1;
					}
            	}
            	else
				{
					printf("Archivo ya cargado como binario\n\n");
				}
                break;
            case 2:
            	if(flagTexto != 1)//No existe
            	{
            		if(!cargarBinario("jugador.bin", listaJugadores))
            		{
            			flagBinario = 1;
            		}
            	}
            	else
            	{
            		printf("Archivo ya cargado como texto\n\n");
            	}
            	break;
            case 3:
            	//validar que no entre si no entro al primer case (ahi ya leeria el archivo)
            	if(flagTexto == 1 || flagBinario == 1)
            	{
            		agregarJugador("jugador.csv", listaJugadores);
            	}
            	else
            	{
            		printf("Error. No hay archivos registrados.\n");
            	}
            	break;
            case 4:
                if(flagTexto == 1 || flagBinario == 1)
				{
            		editarJugador(listaJugadores);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 5:
            	if(flagTexto == 1 || flagBinario == 1)
				{
            		eliminarJugador(listaJugadores);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 6:
            	if(flagTexto == 1 || flagBinario == 1)
				{
            		mostrarJugadores(listaJugadores);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 7:
                if(flagTexto == 1 || flagBinario == 1)
				{
            		sortJugador(listaJugadores);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 8:
            	guardarComoTexto("jugador.csv", listaJugadores);
            	break;
            case 9:
            	guardarComoBinario("jugador.bin", listaJugadores);
            	break;
            case 10:
            	printf("Confirma salida? s/n: ");
            	fflush(stdin);
            	scanf("%c", &confirm);
            	if(confirm == 's')
            	{
            		seguir = 'n';
            	}
            	break;
        }

        system("pause");

    }while(seguir == 's');

    return 0;
}

//---------------------------------------------------------------------------------------------------

int menu()
{
    int option;

    system("cls");
    printf("***** Sistema de Jugadores ******\n\n");
    printf("1. Cargar los datos de los jugadores desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los jugadores desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de jugador\n");
    printf("4. Modificar datos de jugador\n");
    printf("5. Baja de jugador\n");
    printf("6. Listar jugadores\n");
    printf("7. Ordenar jugadores\n");
    printf("8. Guardar los datos de los jugadores en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los jugadores en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

//---------------------------------------------------------------------------------------------------

