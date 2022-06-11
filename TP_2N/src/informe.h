#ifndef INFORME_H_
#define INFORME_H_



/** \brief ordena los apellido y tipo de manera descendente
 * \param lista ePasajero[] array lista
 * \param tam tamaño pasajero
 * \param tipos eTipo[] array tipo
 * \param tamE tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int OrdenarporApellidoyTipoDESC(ePasajero lista[], int tam, eTipo tipos[], int tamT);

/** \brief muestro los pasajeros de estado activo
 * \param lista ePasajero[] array lista
 * \param tam tamaño pasajero
 * \param estados eEstado[] array estado
 * \param tamE tamaño estados
 * \param tipos eTipo[] array tipo
 * \param tamE tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarPasajerosActivos(ePasajero lista[], int tam, eEstado estados[], int tamE,eTipo tipos[], int tamT);

/** \brief promedio precio de pasajeros
 * \param lista ePasajero[] array lista
 * \param tam tamaño pasajero
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int PromedioPrecioPasajero(ePasajero lista[], int tam);


#endif /* INFORME_H_ */
