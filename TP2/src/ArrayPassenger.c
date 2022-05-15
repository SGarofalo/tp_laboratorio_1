#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hardcodeo.h"
#include "ArrayPassenger.h"


int menu(){
	int opcion;

	system("cls");
	printf("		***	ABM Pasajeros ***		\n\n");
	printf("1- Alta pasajero \n");
	printf("2- Baja pasajero \n");
	printf("3- Modificar pasajero \n");
	printf("4- Informar pasajeros \n");
	printf("5- Informar calculos \n");
	printf("6- Listar estados de pasajeros\n");
	printf("9- Salir \n");
	printf("Ingrese opcion: ");
	scanf("%d",&opcion);



	return opcion;

}
int initPassengers(ePasajero lista[], int tam){

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
int findPassengerById(ePasajero lista[], int tam, int id){

	int indice = -1;
		for(int i=0; i<tam; i++){
			if(!lista[i].isEmpty && lista[i].id == id){ //busco en la lista q NO este VACIA
				indice = i;
				break;
		}

	}
		return indice;

}
int addPassengers(ePasajero lista[], int tam, int* pId){


	int todoOk = 0;
	int indice;		//me fijo si hay lugar con la func BUSCARLIBRE

	ePasajero auxPasajero;

	if(lista != NULL && tam > 0){

		system("cls");
		printf("       *** Eligio ALTA PERSONA ***      \n\n");

		indice = buscarLibre(lista, tam);
		if(indice == -1){ //NO HAY LUGAR
			printf("No hay lugar!! \n");
		}else{
		//como HAY lugar pedimos:

			auxPasajero.id = *pId; //leo el 20000 cn esto
			(*pId)++; //para INCREMENTAR el valor desde la func ALTA PERSONA

			/*printf("Ingrese ID: ");
			scanf("%d", &auxPersona.id);*/

			printf("Ingrese nombre: ");
			fflush(stdin);
			gets(auxPasajero.name);

			printf("Ingrese apellido: ");
			fflush(stdin);
			gets(auxPasajero.lastname);

			printf("Ingrese precio: ");
			scanf("%f", &auxPasajero.precio);

			printf("Ingrese codigo de vuelo: ");
			fflush(stdin);
			gets(auxPasajero.flycode);

			printf("Ingrese Tipo de pasajero: ");
			scanf("%d", &auxPasajero.typePassenger);

			printf("Ingrese Estado de vuelo: ");
			scanf("%d", &auxPasajero.statusFlight);


			auxPasajero.isEmpty = 0;

			lista[indice] = auxPasajero;
		}

				todoOk = 1;
	}

		return todoOk;
}

void mostrarPersona(ePasajero p){



    printf("%d   	%-10s   	 	 %-10s     	 %.2f    	  %-10s   		  %d 		 %d\n",
        p.id,
        p.name,
        p.lastname,
    	p.precio,
		p.flycode,
		p.typePassenger,
		p.statusFlight

		);
}

int printPassengers(ePasajero lista[], int tam){
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam > 0){
		system("cls");
		printf("\n      	    				 		 *** Lista de Pasajeros *** \n");
		printf("----------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID   		Nombre  	Apellido   	Precio		 Cod_Vuelo			Tipo		Estado_Vuelo\n");
		printf("-----------------------------------------------------------------------------------------------------------------------------\n");

		for(int i=0; i<tam; i++){

			if((lista[i].isEmpty) == 0){ //muestro las estruc CARGADAS
										//q no esten vacias
				mostrarPersona(lista[i]); //c/ elemento d lista es una persona
				flag = 0;
			}
		}
		if(flag == 1){
			printf("No hay personas para mostrar. \n");
		}

		todoOk = 1;
	}


	return todoOk;

}
int removePassenger(ePasajero lista[], int tam){

	int todoOk = 0;
	int indice;
	int id;
	char confirma;

	if(lista != NULL && tam>0){
		system("cls");
		printf("       *** Eligio BAJA PERSONA ***      \n\n");
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = findPassengerById(lista, tam, id);
		if(indice == -1){ //la persona NO se encuentra en el sist
			printf("El Id: %d no esta registrado en el sistema.\n", id);

		}else{

			mostrarPersona(lista[indice]);
			printf("¿Confirma baja?\n");
			fflush(stdin);
			scanf("%c", &confirma);
			if(confirma == 's' || 'S'){
			lista[indice].isEmpty= 1;		//DADO DE BAJA
			todoOk = 1;
			}else{

				printf("Baja cancelada por el usuario.\n"); //NO confirmo.
			}
		}


	}



	return todoOk;



}
int modificarPasajero(ePasajero lista[], int tam){

	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	char auxNombre[51];
	char auxApellido[51];
	int auxPrecio;
	char auxCodVu[10];
	int auxTipo; //tipo pasajero
	int auxEstatus; //status vuelo

	system("cls");
	printf("       *** Eligio MODIFICAR PASAJERO ***      \n\n");
	printf("Ingrese Id: ");
	scanf("%d", &id);

	indice = findPassengerById(lista, tam, id);

	if(indice == -1){ //la persona NO se encuentra en el sist
		printf("El Id: %d no esta registrado en el sistema.\n", id);

	}else{

		mostrarPersona(lista[indice]);
		printf("¿Confirma modificacion? ");
		fflush(stdin);
		scanf("%c", &confirma);
		if(confirma == 's' || 'S'){ 			//hacer un SUBMENU preg Q quiere MODIF
										//si quiere nombre o ke
		switch(menuModificacion()){

			case 1:
				printf("Ingrese nuevo nombre: ");
				fflush(stdin);
				gets(auxNombre);
				strcpy(lista[indice].name, auxNombre);
			break;
			case 2:
				printf("Ingrese nuevo apellido: ");
				fflush(stdin);
				gets(auxApellido);
				strcpy(lista[indice].lastname, auxApellido);
			break;
			case 3:
				printf("Ingrese nuevo precio: ");
				scanf("%d", &auxPrecio);
				lista[indice].precio = auxPrecio;
			break;
			case 4:
				printf("Ingrese nuevo Cod. de Vuelo: ");
				fflush(stdin);
				gets(auxCodVu);
				strcpy(lista[indice].flycode, auxCodVu);
			break;
			case 5:
				printf("Ingrese nuevo Tipo: ");
				scanf("%d", &auxTipo);
				lista[indice].typePassenger = auxTipo;
			break;
			case 6:
				printf("Ingrese nuevo Estatus: ");
				scanf("%d", &auxEstatus);
				lista[indice].statusFlight = auxEstatus;
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
	printf("4- Cod. Vuelo \n");
	printf("5- Tipo \n");
	printf("6- Estatus \n");
	printf("Ingrese opcion: ");
	scanf("%d",&opcion);


	return opcion;


}
/*int sortPassengers(ePasajero lista[], int tam){
	int todoOk = 0;
	ePasajero auxPasajero;

	if(lista != NULL && tam > 0){

		for(int i=0; i<tam-1; i++){
			for(int j=i+1; j<tam; j++){

				if((lista[i].sexo > lista[j].sexo) ||
					(lista[i].sexo == lista[j].sexo &&
					strcmp(lista[i].nombre, lista[j].nombre)>0)){

					auxPasajero = lista[i];
						lista[i] = lista[j];
						lista[j] = auxPasajero;

				}

				}

			}

		}

				todoOk = 1;

				return todoOk;




}*/
