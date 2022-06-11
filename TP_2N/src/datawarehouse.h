#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_
#include "ArrayPassenger.h"
#include "tipo.h"
#include "estado.h"


/** \brief hardodea los datos de pasajeros
 * \param lista ePasajero[] array pasajero
 * \param tam tamaño pasajeros
 * \param cant cantidad entero
 * \param *pId puntero de pasajero
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int hardcodearPasajero(ePasajero lista[], int tam,int cant, int* pId);


#endif /* DATAWAREHOUSE_H_ */
