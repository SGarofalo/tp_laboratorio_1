#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "tipo.h"
#include "estado.h"
#include "datawarehouse.h"

int menu(){
	int opcion;

	system("cls");
	printf("		***	ABM Pasajeros ***		\n\n");
	printf("1- Alta pasajero \n");
	printf("2- Baja pasajero \n");
	printf("3- Modificar pasajero \n");
	printf("4- Listar Pasajeros\n");
	printf("5- Listar Estados \n");
	printf("6- Listar Tipos \n");
	printf("7- Informes\n"); //submenu
	printf("10- Salir \n");
	printf("Ingrese opcion: ");
	scanf("%d",&opcion);

	return opcion;

}

int inicializarPasajero(ePasajero lista[], int tam){

	int todoOk = 0;

	if(lista != NULL && tam > 0){

		for(int i=0; i<tam; i++){

			lista[i].isEmpty = 1;
		}

		todoOk = 1;
	}

	return todoOk;

}
int buscarLibre(ePasajero lista[], int tam){

	int indice = -1;
		for(int i=0; i<tam; i++){
			if(lista[i].isEmpty){
				indice = i;
				break;
		}

	}
		return indice;

}
int addPassengers(ePasajero lista[], int tam, int* pId, eEstado estados[], int tamE, eTipo tipos[], int tamT){

	int todoOk = 0;
	int indice;		//me fijo si hay lugar con la func BUSCARLIBRE

	ePasajero auxPasajero;

	if(lista != NULL && tam > 0 && pId != NULL && estados != NULL && tamE >0 && tipos != NULL && tamT>0){
		system("cls");
		printf("       *** Eligio ALTA PASAJERO ***      \n\n");

		indice = buscarLibre(lista, tam);
		if(indice == -1){ //NO HAY LUGAR
			printf("No hay lugar!! \n");
		}else{
		//como HAY lugar pedimos:

			auxPasajero.id = *pId;
			(*pId)++;

			printf("Ingrese nombre: ");
			fflush(stdin);
			gets(auxPasajero.name);

			printf("Ingrese apellido: ");
			fflush(stdin);
			gets(auxPasajero.lastname);

			printf("Ingrese precio: ");
			scanf("%f",&auxPasajero.precio);

			printf("    *** Codigos de Vuelo *** \n\n");
			printf("**  Descripcion  **\n"
					"1. Chaco\n"
					"2. Chubut\n"
					"3. Cordoba\n"
					"4. Salta\n"
					"5. Salta\n"
					"6. Jujuy\n"
					"7. Tucuman\n");

			printf("Ingrese codigo de vuelo: ");
			fflush(stdin);
			gets(auxPasajero.flycode);

			mostrarEstados(estados, tamE);
			printf("Ingrese Estado de vuelo: ");
			scanf("%d",&auxPasajero.statusFlight);

			while(validarIdEstado(auxPasajero.statusFlight, estados, tamE)==0){
			printf("Id invalido. Ingrese Estado: ");
			scanf("%d",&auxPasajero.statusFlight);
			}

			mostrarTipos(tipos, tamT);
			printf("Ingrese Tipo de pasajero: ");
			scanf("%d", &auxPasajero.typePassenger);

			while(!validarIdTipo(auxPasajero.typePassenger, tipos, tamT)){
			printf("Id invalido. Ingrese Tipo: ");
			scanf("%d", &auxPasajero.statusFlight);
			}

			auxPasajero.isEmpty = 0;

			lista[indice] = auxPasajero;
		}

				todoOk = 1;
	}

		return todoOk;
}
void mostrarPasajero(ePasajero p, eEstado estados[], int tamE, eTipo tipos[], int tamT){
	char descripcionE[20];
	char descripcionT[20];

	cargardescripcionL(estados, tamE, p.statusFlight, descripcionE);
	cargardescripcionT(tipos, tamT, p.typePassenger, descripcionT);

	printf("%d   	%-10s  	 %-10s     	%.2f		   %-10s		  %-10s		  %-10s\n",
		p.id,
		p.name,
		p.lastname,
		p.precio,
		p.flycode,
		descripcionT,
		descripcionE
		);

}
int printPassengers(ePasajero lista[], int tam, eEstado estados[], int tamE, eTipo tipos[], int tamT){
	int todoOk = 0;
	int flag = 1;

	if(lista != NULL && tam > 0 && estados != NULL && tamE >0 && tipos != NULL && tamT>0){
		system("cls");
		printf("\n      	    						*** Lista de Pasajeros *** \n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID   	Nombre  	Apellido   	 	Precio			Cod Vuelo		 Tipos			Estado Vuelo\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------\n");

		for(int i=0; i<tam; i++){

			if((lista[i].isEmpty) == 0){
				mostrarPasajero(lista[i], estados, tamE, tipos, tamT);
				flag = 0;
			}
		}
		if(flag == 1){
			printf("		No hay Pasajeros para mostrar. \n\n");
		}

		todoOk = 1;
	}


	return todoOk;

}
int findPassengerById(ePasajero lista[], int tam, int id){

	int indice = -1;
		for(int i=0; i<tam; i++){
			if(!lista[i].isEmpty && lista[i].id == id){
				indice = i;
				break;
		}

	}
		return indice;
}
int removePassenger(ePasajero lista[], int tam, eEstado estados[], int tamE, eTipo tipos[], int tamT){
	int todoOk = 0;
	int indice;
	int id;
	char confirma;

	if(lista != NULL && tam>0){

		printf("       					*** Eligio BAJA PASAJERO ***      \n\n");
		printPassengers(lista, tam, estados, tamE, tipos, tamT);
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = findPassengerById(lista, tam, id);
		if(indice == -1){ //la persona NO se encuentra en el sist
			printf("El Id: %d no esta registrado en el sistema.\n", id);

		}else{
			mostrarPasajero(lista[indice], estados, tamE, tipos, tamT);
			printf("Confirma baja?\n");
			fflush(stdin);
			scanf("%c", &confirma);
			if(confirma == 's' || confirma == 'S'){
			lista[indice].isEmpty = 1;		//DADO DE BAJA
			todoOk = 1;
			}else{

				printf("Baja cancelada por el usuario.\n"); //NO confirmo.
			}
		}


	}

	return todoOk;
}
int sortPassengers(ePasajero lista[],int tam, eTipo tipos[], int tamT){

	int todoOk = 0;
	ePasajero auxPersona;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT >0){

		for(int i=0; i<tam-1; i++){
			for(int j=i+1; j<tam; j++){

				if((lista[i].typePassenger > lista[j].typePassenger) ||
					(lista[i].typePassenger == lista[j].typePassenger &&
					strcmp(lista[i].lastname, lista[j].lastname)>0)){

						auxPersona = lista[i];
						lista[i] = lista[j];
						lista[j] = auxPersona;

				}

				}

			}

		}

				todoOk = 1;

				return todoOk;
}
int modificarPersona(ePasajero lista[], int tam, eEstado estados[], int tamE, eTipo tipos[], int tamT){

	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	char auxNombre[51];
	char auxApellido[51];
	float auxPrecio;
	char auxCod[10];
	int auxTipo;

	printf("     					  *** Eligio MODIFICAR PASAJERO ***      \n\n");

	printPassengers(lista, tam, estados, tamE, tipos, tamT);
	printf("Ingrese Id: ");
	scanf("%d", &id);

	indice = findPassengerById(lista, tam, id);

	if(indice == -1){ //la persona NO se encuentra en el sist
		printf("El Id: %d no esta registrado en el sistema.\n", id);

	}else{
		mostrarPasajero(lista[indice], estados, tamE, tipos, tamT);//recibe la persona q tiene q mostrar, el array de local y el tam para poder recuperr la descripcion
		printf(" Confirma modificacion? ");
		fflush(stdin);
		scanf("%c", &confirma);
		if(confirma == 's' || 'S'){

		switch(menuModificacion()){
			case 1:
				printf("Ingrese nuevo nombre: ");
				fflush(stdin);
				gets(auxNombre);
				strcpy(lista[indice].name, auxNombre);
			break;
			case 2:
				printf("Ingrese nuevo nombre: ");
				fflush(stdin);
				gets(auxApellido);
				strcpy(lista[indice].lastname, auxApellido);
			break;
			case 3:
				printf("Ingrese nuevo precio: ");
				scanf("%f", &auxPrecio);
				lista[indice].precio = auxPrecio;
			break;
			case 4:
				printf("Ingrese nuevo codigo: ");
				fflush(stdin);
				gets(auxCod);
				strcpy(lista[indice].flycode, auxCod);
			break;
			case 5:
				mostrarTipos(tipos, tamT);
				printf("Ingrese tipos: ");
				scanf("%d", &auxTipo);
				lista[indice].typePassenger = auxTipo;
			break;


			default:
				printf("Opcion INVALIDA! \n");
		}

				todoOk = 1;
		}else{

			printf("Se ha cancelado la modificacion.\n"); //NO confirmo.
		}
	}

				return todoOk;

}
int menuModificacion(){
	int opcion;

	printf("1- Nombre \n");
	printf("2- Apellido \n");
	printf("3- Precio \n");
	printf("4- Codigo \n");
	printf("5- Tipo \n");
	printf("Ingrese opcion: ");
	scanf("%d",&opcion);


	return opcion;
}
int menuInformes(){
	int opcion;

	printf("		1- Informar pasajeros x TIPO y APELLIDO ASC\n");
	printf("		2- Informar pasajeros x TIPO y APELLIDO DESC\n");
	printf("		3- Informar calculos \n");
	printf("		4- Listar ESTADOS de pasajeros por 'ACTIVO' \n");

	printf("Ingrese opcion: ");
	scanf("%d",&opcion);
	return opcion;
}

