#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "Mgarofalo.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int flagTexto = 1;
    int flagBinario = 1;
    char salir = 'n';

    LinkedList* listaPasajeros = ll_newLinkedList();

//    printf("Funciona tp3_windows_prueba\n");

    do{
    	menu(&option);
        switch(option)
        {
            case 1:
            	if( !flagBinario )
            	{
            		printf("Se encuentra trabajando con el archivo binario, debe guardarlo primero.\n");
            	}
            	else
            	{
            		if( !flagTexto)
            		{
            			printf("Se abrio el archivo en modo texto.\n");
            		}
            		else
            		{
            			if( !controller_loadFromText("data.csv", listaPasajeros))
            			{
            				flagTexto = 0;
            				printf("Lista de pasajeros (modo texto) cargada exitosamente.\n");
            			}
            			else
            			{
            				printf("Error al cargar desde texto\n");
            			}
            		}
            	}
                break;
            case 2:
            	if( !flagTexto)
            	{
            		printf("Se encuentra trabajando con el archivo en texto, debe guardarlo primero.\n");
            	}
            	else
            	{
					if( !flagBinario )
					{
						printf("Se abrio el archivo en modo binario.\n");
					}
					else
					{
						if( !controller_loadFromBinary("data.bin", listaPasajeros))
						{
							flagBinario = 0;
							printf("Lista de pasajeros cargada (modo binario) exitosamente.\n");
						}
						else
						{
							printf("Error al cargar desde binario\n");
						}
					}
				}
            	break;
            case 3:
            	if( !flagTexto || !flagBinario)
            	{
            		if( !controller_addPassenger(listaPasajeros))
            		{
            			printf("Alta exitosa.\n");
            		}
            		else
            		{
            			printf("Error en alta de pasajeros\n");
            		}
            	}
            	else
            	{
            		printf("No se abrio ningun archivo.\n");
            	}
            	break;
            case 4:
            	if( !flagTexto || !flagBinario)
            	{
            		if( !ll_isEmpty(listaPasajeros))
            		{
            			if( !controller_editPassenger(listaPasajeros))
            			{
            				printf("Error en modificacion de pasajeros\n");
            			}
            		}
            	}
            	break;
            case 5:
            	if( !flagTexto || !flagBinario)
            	{
            		if( !ll_isEmpty(listaPasajeros))
            		{
            			if( controller_removePassenger(listaPasajeros))
            			{
            				printf("Baja del pasajero exitosa.\n");
            			}
            			else
            			{
            				printf("Baja cancelada por el usuario.\n");
            			}
            		}
            	}
            	break;
            case 6:
            	if( !flagTexto || !flagBinario)
            	{
            		if( !ll_isEmpty(listaPasajeros))
					{
						controller_ListPassenger(listaPasajeros);
					}
					else
					{
						printf("La lista no tiene elementos.\n");
					}
            	}
            	else
            	{
            		printf("No se abrio aun el archivo de pasajeros (en ningun modo) para poder mostrarlo.\n");
            	}
            	break;
            case 7:
            	if(flagBinario == 0 || flagTexto == 0)
				{
					if(!ll_isEmpty(listaPasajeros))
					{
						if(!controller_sortPassenger(listaPasajeros))
						{
							printf("Ordenamiento exitoso!\n");
						}else
						{
							printf("Error en ordenamiento de pasajeros\n");
						}
					}else
					{
						printf("No hay pasajeros en la lista para ordenar\n");
					}
				}
				else
				{
					printf("No se ha abierto el archivo para ordenar\n");
				}
            	break;
            case 8:
            	if(!flagTexto)
				{
					if(!controller_saveAsText("data.csv",listaPasajeros))
					{
						flagTexto = 1;
						printf("\nEl archivo data.csv se guardo en modo texto\n");
					}
					else
					{
						printf("Ocurrio un problema al guardar el archivo en modo texto\n");
					}
				}
				else
				{
					if(!flagBinario)
					{
						printf("Usted abrio el archivo binario, no puede guardarla como texto!");
					}
					else
					{
						printf("No se ha abierto el archivo  en texto para guardar\n");
					}
				}
            	break;
            case 9:
            	if(!flagBinario)
				{
					if(!controller_saveAsBinary("data.bin",listaPasajeros))
					{
						flagBinario = 1;
						printf("\nEl archivo data.bin se guardo en modo binario\n");
					}
					else
					{
						printf("Error al guardar en modo binario\n");
					}
				}
				else
				{
					if(!flagTexto)
					{
						printf("Usted abrio el archivo en texto, no puede guardarla como binario!\n");
					}
					else
					{
						printf("No se ha abierto el archivo  en binario para guardar\n");
					}
				}
            	break;
            case 10:
            	salir = opcionConfirmar("Seguro que quiere salir? s/n ", "Error, vuelva a intentarlo. Salir? s/n ");
            	break;
            default:
            	break;
        }
        system("pause");

    }while(salir == 'n');

    ll_deleteLinkedList(listaPasajeros);
    free(listaPasajeros);

    return 0;
}

