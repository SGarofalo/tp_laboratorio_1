#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include "ArrayPassenger.h"

int cargardescripcionL(eEstado estados[], int tamE, int idEstado, char descripcion[]){

	int todoOk =0;
	int flag = 1;

	if(estados != NULL && tamE>0 && descripcion != NULL){

		todoOk =1;		 //me devuelve 1 si se puso a buscar y NO encontro
		for(int i=0;i<tamE;i++){
			if(estados[i].idEstado == idEstado){
				strcpy(descripcion,estados[i].nombreEstado);
				flag = 0;
				break; // es p/ q no siga iterando
			}
		}
		if(flag == 1){
			todoOk = -1;		//NO hay NINGUNA local con ese ID.
		}
	}

	return todoOk;

}
int mostrarEstados(eEstado estados[], int tamE){

	int todoOk = 0;
	if(estados != NULL && tamE > 0){

		printf("    *** Estados de Vuelo *** \n\n");
		printf("    Id        Descripcion\n");
		for(int i=0; i<tamE; i++){
			printf("    %d       %s\n", estados[i].idEstado, estados[i].nombreEstado);
		}
		printf("\n\n");

		todoOk = 1;
	}
	 return todoOk;
}
int validarIdEstado(int id, eEstado estados[], int tamE){
	int todoOk =0; //esta = NO ESTA

	if(estados != NULL && tamE>0){

		for(int i=0;i<tamE;i++){

			if(estados[i].idEstado == id){ //localidad con MISMO id q estoy BUSCANDO retorno 1
										//devuelve 0 si NO hay NINGUNA local o si me pasan CUALQUIER COSA
				todoOk = 1;	 //ESTA
				break;
			}
		}

	}

	return todoOk; //ESTA
	}

