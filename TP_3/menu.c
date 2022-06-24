#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

int menu(int*pOpcionMenu)
{
    int error = 1;
    int opcion;

    if(pOpcionMenu != NULL)
    {

        system("cls");
        do
        {
        	printf("-------------------------------------\n");
			printf("     *** AMB de Pasajeros ***       \n");
			printf("-------------------------------------\n");
            printf(" 1- Cargar los datos de los Pasajeros desde el archivo data.csv (modo texto)\n");
            printf(" 2- Cargar los datos de los Pasajeros desde el archivo data.bin (modo binario)\n");
            printf(" 3- Alta de Pasajero\n");
            printf(" 4- Modificar datos de Pasajero\n");
            printf(" 5- Baja de Pasajero\n");
            printf(" 6- Listar Pasajeros\n");
            printf(" 7- Ordenar Pasajeros\n");
            printf(" 8- Guardar los datos de los Pasajeros en el archivo data.csv (modo texto)\n");
            printf(" 9- Guardar los datos de los Pasajeros en el archivo data.bin (modo binario)\n");
            printf(" 10- Salir\n");

            utn_getNumero(&opcion,"\nIngrese una opcion:","Error. Opcion invalida\n",0,10,4);

            error = 0;
        }while(opcion<1 || opcion>10);
        *pOpcionMenu = opcion;
    }
    return error;
}


int menuModificar(int*pOpcionMenu)	//usado en la funcion   controller_editPassenger()
{
    int error = 1;
	int opcion;

	system("cls");
	do{
		printf("-------------------------------------\n");
		printf("   *** Modificar Pasajeros ***       \n");
		printf("-------------------------------------\n");
		printf("1- Nombre del pasajero \n");
		printf("2- Apellido del pasajero \n");
		printf("3- Precio del pasaje \n");
		printf("4- Codigo de vuelo \n");
		printf("5- Tipo de pasaje \n");
		printf("6- Estado de vuelo \n");
		printf("7- Salir \n");
		utn_getNumero(&opcion,"\nIngrese una opcion:","Error. Opcion invalida\n",0,7,4);
		error = 0;
	}while(opcion<1 || opcion>7);
	*pOpcionMenu = opcion;

    return error;
}


int menuOrdenar(int*pOpcionMenu)
{
    int error = 1;
	int opcion;

	system("cls");
	do{
		printf("-------------------------------------\n");
		printf("   *** Lista Pasajeros ***       \n");
		printf("-------------------------------------\n");
		printf("1- Ordenar por Id \n");
		printf("2- Ordenar por nombre del pasajero \n");
		printf("3- Ordenar por apellido del pasajero \n");
		printf("4- Ordenar por precio del pasaje \n");
		utn_getNumero(&opcion,"\nIngrese una opcion:\n","Error. Opcion invalida\n",0,5,4);
		error = 0;
	}while(opcion<1 || opcion>7);
	*pOpcionMenu = opcion;

    return error;
}
