#ifndef ESTADO_H_
#define ESTADO_H_



typedef struct{
	int idEstado; //1000
	char nombreEstado[51];
}eEstado;


/** \brief descripcion de estados
 * \param estados eEstado[] array estados
 * \param tamE tamaño estados
 * \param idEstado variable id estado
 * \param descripcion cadena de caracteres
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int cargardescripcionL(eEstado estados[], int tamE, int idEstado, char descripcion[]);

/** \brief mostrar estados
 * \param estados eEstado[] array estados
 * \param tamE tamaño estados
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarEstados(eEstado estados[], int tamE);

/** \brief validar id del estado
 * \param int id le paso id estado
 * \param estados eEstado[] array estados
 * \param tamE tamaño estados
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int validarIdEstado(int id, eEstado estados[], int tamE);
int validarPalabra(char palabra[]);
#endif /* ESTADO_H_ */
