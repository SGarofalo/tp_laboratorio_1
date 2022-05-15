#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hardcodeo.h"
#include "ArrayPassenger.h"


char nombres[5][51] = {
		"Juan",
		"Pedro",
		"Sofi",
		"Miguel",
		"Luisa"

};

char apellidos[5][51] = {
		"Lopez",
		"Rey",
		"Gomez",
		"Perez",
		"Baez"
};


float precios[5] = {20000, 23500, 48000, 29300, 56000};

char cod[5][10] = {
		"Ushuaia",
		"Jujuy",
		"Cordoba",
		"Neuquen",
		"SanLuis"
};

int idTipo[5] = {1,4,3,2,4};




int hardcodearPersonas(ePasajero lista[], int tam,int cant, int* pId){

	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){
		contador = 0;
		for(int i=0; i<tam; i++){
			lista[i].id = *pId;

			(*pId)++;
			strcpy(lista[i].name, nombres[i]);
			strcpy(lista[i].lastname, apellidos[i]);
			lista[i].precio=precios[i];
			strcpy(lista[i].flycode, cod[i]);
			lista[i].typePassenger = idTipo[i];

			lista[i].isEmpty = 0;

			contador++;
		}

	}

	return contador;


}
