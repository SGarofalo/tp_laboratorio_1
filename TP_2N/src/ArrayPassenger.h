#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <string.h>
#include "tipo.h"
#include "estado.h"

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

/** \brief inicializo autos
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \return int 1 en caso de exito, 0 en caso de error
 */
int inicializarPasajero(ePasajero lista[], int tam);

/** \brief busco lugar libre en pasajero
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int buscarLibre(ePasajero lista[], int tam);

/** \brief busco el idPasajero
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \param id variable id tipo pasajero
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int findPassengerById(ePasajero lista[], int tam, int id);

/** \brief es el alta de pasajero
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \param marcas eEstado[] array estados
 * \param tamE tamaño estados
 * \param colores eTipo[] array tipos
 * \param tamT tamaño tipos
 * \param *pId puntero de Id
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int addPassengers(ePasajero lista[], int tam, int* pId, eEstado estados[], int tamE, eTipo tipos[], int tamT);

/** \brief muestro el pasajero
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \param marcas eEstado[] array estados
 * \param tamE tamaño estados
 * \param colores eTipo[] array tipos
 * \param tamT tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
void mostrarPasajero(ePasajero p, eEstado estados[], int tamE, eTipo tipos[], int tamT);

/** \brief muestro los pasajeros
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \param marcas eEstado[] array estados
 * \param tamE tamaño estados
 * \param colores eTipo[] array tipos
 * \param tamT tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int printPassengers(ePasajero lista[], int tam, eEstado estados[], int tamE, eTipo tipos[], int tamT);

/** \brief es la baja de pasajero
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \param marcas eEstado[] array estados
 * \param tamE tamaño estados
 * \param colores eTipo[] array tipos
 * \param tamT tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int removePassenger(ePasajero lista[], int tam, eEstado estados[], int tamE, eTipo tipos[], int tamT);

/** \brief es la modif de pasajero
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \param marcas eEstado[] array estados
 * \param tamE tamaño estados
 * \param colores eTipo[] array tipos
 * \param tamT tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int modificarPersona(ePasajero lista[], int tam, eEstado estados[], int tamE, eTipo tipos[], int tamT);

/** \brief ordena pasajero
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \param marcas eEstado[] array estados
 * \param tamE tamaño estados
 * \param colores eTipo[] array tipos
 * \param tamT tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int sortPassengers(ePasajero lista[],int tam, eTipo tipos[], int tamT);

/** \brief crea el menu de pasajeros y lo muestra en pantalla
 * \return int retorna el valor de la opcion seleccionada
 *
 */
int menu();

/** \brief crea un submenu para elegir que quiere modificar el usuario
 * \return int retorna el valor de la opcion seleccionada
 *
 */
int menuModificacion();

/** \brief crea el menu de informes y lo muestra en pantalla
 * \return int retorna el valor de la opcion seleccionada
 *
 */
int menuInformes();

#endif /* ARRAYPASSENGER_H_ */
