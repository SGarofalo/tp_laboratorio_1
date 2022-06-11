#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "tipo.h"
#include "estado.h"
#include "datawarehouse.h"

int mostrarPasajerosActivos(ePasajero lista[], int tam, eEstado estados[], int tamE,eTipo tipos[], int tamT){
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam > 0 && estados != NULL && tamE>0 && tipos != NULL && tamT>0){
		system("cls");
		printf("\n      	    						*** Lista de Pasajeros x Estado *** \n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID   	Nombre  	Apellido   	 	Precio			Cod Vuelo		 Tipos			Estado Vuelo\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
		for(int i=0; i<tam; i++){

			if((!lista[i].isEmpty && lista[i].statusFlight == 3000)){

				mostrarPasajero(lista[i], estados, tamE, tipos, tamT);
				flag = 0;
			}
		}
		if(flag == 1){
			printf("		No hay pasajeros ACTIVOS para mostrar. \n\n");
		}

		todoOk = 1;
	}
	return todoOk;

}
int OrdenarporApellidoyTipoDESC(ePasajero lista[], int tam, eTipo tipos[], int tamT){

	int todoOk = 0;
	ePasajero auxPersona;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT >0){

		for(int i=0; i<tam-1; i++){
			for(int j=i+1; j<tam; j++){

				if((lista[i].typePassenger < lista[j].typePassenger) ||
					(lista[i].typePassenger == lista[j].typePassenger &&
					strcmp(lista[i].lastname, lista[j].lastname)<0)){

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
int PromedioPrecioPasajero(ePasajero lista[], int tam){
	int todoOk = 0;
	float acumulador = 0;
	int contador =0;
	float MayorPrecio =0;
	float promedio;
	if(lista != NULL && tam>0){
		for(int i=0; i<tam; i++){
			if(!lista[i].isEmpty){
				acumulador = acumulador + lista[i].precio;
				contador++;
			}
		}
		promedio = acumulador/contador;
		for(int i=0; i<tam;i++){
			if(lista[i].precio > promedio){
				MayorPrecio++;
			}
		}
		printf("El promedio de precios es: %.2f \n", promedio);
		printf("Cantidad de pasajeros cuyo pasaje esta por encima del promedio: %.2f\n", MayorPrecio);
		todoOk = 1;
	}
		return todoOk;
}
