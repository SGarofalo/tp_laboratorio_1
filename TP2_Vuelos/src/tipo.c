#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "ArrayPassenger.h"


int cargardescripcionT(eTipo tipos[], int tamT, int idTipo, char descripcion[]){

	int todoOk =0;
	int flag = 1;

	if(tipos != NULL && tamT>0 && descripcion != NULL){

		todoOk =1;		 //me devuelve 1 si se puso a buscar y NO encontro
		for(int i=0;i<tamT;i++){
			if(tipos[i].id == idTipo){
				strcpy(descripcion,tipos[i].nombreTipo);
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
int mostrarTipos(eTipo tipos[], int tamT){

	int todoOk = 0;
	if(tipos != NULL && tamT > 0){

		printf("    *** Tipos de Vuelo *** \n\n");
		printf("    Id        Descripcion\n");
		for(int i=0; i<tamT; i++){
			printf("    %d       %s\n", tipos[i].id, tipos[i].nombreTipo);
		}
		printf("\n\n");

		todoOk = 1;
	}
	 return todoOk;
}
int validarIdTipo(int id, eTipo tipos[], int tamT){
	int todoOk =0; //esta = NO ESTA

	if(tipos != NULL && tamT>0){

		for(int i=0;i<tamT;i++){

			if(tipos[i].id == id){

				todoOk = 1;	 //ESTA
				break;
			}
		}

	}

	return todoOk; //ESTA
	}
