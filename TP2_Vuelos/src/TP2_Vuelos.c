#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "estado.h"
#include "tipo.h"
#include "datawarehouse.h"
#include "informe.h"

#define TAM 10
#define TAM_T 4
#define TAM_E 2


int main(void) {
	setbuf(stdout, NULL);

	char seguir = 's';
	int nextID = 3000;
	ePasajero lista[TAM];
	char salida;
	int flagAlta = 0;

	eTipo tipos[TAM_T] = {
		{1000,"Turista"},
		{1001,"Primera Clase"},
		{1002,"Ejecutiva"},
		{1003,"Premium"}
	};

	eEstado estados[TAM_E] = {
		{3000,"ACTIVO"},
		{4000,"INACTIVO"}
	};

	if(!inicializarPasajero(lista, TAM)){
		printf("Error al inicializar \n");
	}

	hardcodearPasajero(lista, TAM, 9, &nextID);
	do{
	switch(menu()){
	case 1:
		if(addPassengers(lista, TAM,&nextID, estados, TAM_E, tipos, TAM_T)==0){
					printf("No se pudo realizar el alta \n");
				}else{
					printf("ALTA EXITOSA!!! \n");
				}
		flagAlta = 1;
	break;
	case 2:
		if(flagAlta == 0){
			printf("Primero debe ingresar el alta\n");
		}else{
			if(removePassenger(lista, TAM, estados, TAM_E, tipos, TAM_T)==0){
				printf("No se pudo realizar la baja \n");
			}else{
				printf("BAJA EXITOSA!!! \n");
			}
		}
	break;
	case 3:
		if(flagAlta == 0){
			printf("Primero debe ingresar el alta\n");
		}else{
			modificarPersona(lista, TAM, estados, TAM_E, tipos, TAM_T);
		}
	break;
	case 4:
		if(flagAlta == 0){
			printf("Primero debe ingresar el alta\n");
		}else{
			printPassengers(lista, TAM, estados, TAM_E, tipos, TAM_T);
		}
	break;
	case 5:
		mostrarEstados(estados, TAM_E);
	break;
	case 6:
		mostrarTipos(tipos, TAM_T);
	break;
	case 7:	 //informes
		switch(menuInformes()){
			case 1:
				sortPassengers(lista, TAM, tipos, TAM_T);
				printPassengers(lista, TAM, estados, TAM_E, tipos, TAM_T);
			break;
			case 2:
				OrdenarporApellidoyTipoDESC(lista, TAM, tipos, TAM_T);
				printPassengers(lista, TAM, estados, TAM_E, tipos, TAM_T);
			break;
			case 3:
				PromedioPrecioPasajero(lista, TAM);
			break;
			case 4:
				mostrarPasajerosActivos(lista, TAM, estados, TAM_E, tipos, TAM_T);
			break;
		}

	break;
	case 10:
		printf("		Seguro quiere salir? ");
		fflush(stdin);
		scanf("%c", &salida);

		if (salida == 's'|| salida == 'S'){
			seguir = 'n';
			printf("	Gracias, vuelva pronto\n");
		}
		else{
			printf("		Usted no salio\n");
		}
	break;
	default:
		printf("Opcion invalida!! \n");
	}
	system("pause");


}while(seguir == 's' || seguir == 'S' );




	return 0;
}
