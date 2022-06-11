#ifndef TIPO_H_
#define TIPO_H_


typedef struct{
	int id; //1000
	char nombreTipo[51];
}eTipo;


/** \brief descripcion de tipos
 * \param tipos eTipo[] array tipos
 * \param tamT tamaño tipos
 * \param idEstado variable id tipo
 * \param descripcion cadena de caracteres
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int cargardescripcionT(eTipo tipos[], int tamT, int idTipo, char descripcion[]);

/** \brief mostrar tipos
 * \param tipos eTipo[] array tipos
 * \param tamT tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarTipos(eTipo tipos[], int tamT);

/** \brief validar id del estado
 * \param int id le paso id estado
 * \param tipos eTipo[] array tipos
 * \param tamT tamaño tipos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int validarIdTipo(int id, eTipo tipos[], int tamT);

#endif /* TIPO_H_ */
