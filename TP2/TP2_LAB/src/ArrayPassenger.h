#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int id;
	char name[51];
	char lastname[51];
	float precio; //precio
	char flycode[10]; //cod de vuelo
	int typePassenger; //tipo pasajero
	int statusFlight; //status vuelo
	int isEmpty;
}ePasajero;

int initPassengers(ePasajero lista[], int tam);
int findPassengerById(ePasajero lista[], int tam, int id);
int buscarLibre(ePasajero lista[], int tam);
int addPassengers(ePasajero lista[], int tam, int* pId);
void mostrarPersona(ePasajero p);
int printPassengers(ePasajero lista[], int tam);
int removePassenger(ePasajero lista[], int tam);
int modificarPasajero(ePasajero lista[], int tam);
#endif /* ARRAYPASSENGER_H_ */
