#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hardcodeo.h"
#include "ArrayPassenger.h"


#define TAM 6


//int sortPassengers(ePasajero lista[], int tam);


int menu();
int menuModificacion();
int main(void) {
	setbuf(stdout, NULL);

	ePasajero lista[TAM];
	char seguir = 's';
	int nextID = 20000;



	initPassengers(lista, TAM);
	hardcodearPersonas(lista, TAM, 5, &nextID);

	do{
	switch(menu()){
	case 1:
		addPassengers(lista, TAM, &nextID);
	break;
	case 2:
		printPassengers(lista, TAM);
	break;
	case 3:
		removePassenger(lista, TAM);
	break;
	case 4:
		modificarPasajero(lista, TAM);
	break;
	case 5:

	case 9:
		printf("Ha seleccionado salir \n");
		seguir = 'n';
	break;
	default:
		printf("Opcion invalida!! \n");
	}
	system("pause");


}while(seguir == 's' || seguir == 'S' );

		return 0;



}





