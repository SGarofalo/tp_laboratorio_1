#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "tipo.h"
#include "estado.h"
#include "datawarehouse.h"

char nombres[10][51] = {
		"Juan",
		"Pedro",
		"Sofi",
		"Miguel",
		"Valentina",
		"Camila",
		"Sergio",
		"Luis",
		"Luciana",
		"Analia"
};

char apellidos[10][51] = {
		"Gomez",
		"Lopez",
		"Perez",
		"Garcia",
		"Rodriguez",
		"Reyes",
		"Moreira",
		"Serrano",
		"Leal",
		"Fernandez"
};

float precios[10] = {20000, 22500,33000,45500,78000,21500,34600,77000,66400,52000};
char codigos[10][10]= {
		"Catamarca",
		"Chaco",
		"Chubut",
		"Cordoba",
		"Cordoba",
		"Salta",
		"Jujuy",
		"Jujuy",
		"Chubut",
		"Tucuman"
};
int idTipos[10]= {1001,1000,1003,1000,1001,1002,1003,1002,1000,1001};
int idEstados[10] = {3000, 4000,4000,3000,3000,3000,4000,4000,3000,4000};

int hardcodearPasajero(ePasajero lista[], int tam,int cant, int* pId){

	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){ //cant >=0 y =< al tamaño
		contador = 0;
		for(int i=0; i<cant; i++){
			lista[i].id = *pId; //pId es la direc de mem de la var nextId de MAIN
								//con el * accedemos al valor
			(*pId)++; //para INCREMENTAR el valor desde la func
			strcpy(lista[i].name, nombres[i]);
			strcpy(lista[i].lastname, apellidos[i]);
			lista[i].precio = precios[i];
			strcpy(lista[i].flycode, codigos[i]);
			lista[i].typePassenger = idTipos[i];
			lista[i].statusFlight = idEstados[i];
			lista[i].isEmpty = 0; //al llenarlo lo deja en 0

			contador++;
		}

	}

	return contador;
}


