/*
 * calculos.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Sol
 */



#ifndef CALCULOS_H_
#define CALCULOS_H_



 /** \brief realiza un descuento de los precios ingresados
  *
  * \param puntero a float
  * \param
  * \return retorna todoOk = 0 si hubo un error y retorna todoOk = 1 si salio todo bien.
  *
  */
int realizarDescuento(float numero, float* final);


/** \brief realiza una suma de en porcentaja y se lo agrega en los precios ingresados
*
* \param puntero a float
* \param
* \return retorna todoOk = 0 si hubo un error y retorna todoOk = 1 si salio todo bien.
*
*/
int realizarCredito(float numero, float* final);


/** \brief recibe un numero, realiza la transformacion de pesos a bitcoin y lo retorna
  *
  * \param float numero recibe el numero en pesos
  * \param
  * \return retorna bitcoin, resultado transformado de pesos a bitcoin.
  *
  */
float realizarBitcoin(float numero);


/** \brief recibe dos numeros(km y precios) y realiza el precio unitario de ellos.
  *
  * \param puntero a float.
  * \param
  * \return retorna todoOk = 0 si hubo un error y retorna todoOk = 1 si salio todo bien.
  *
  */
int realizarCalUnit(float precios, int km, float* PfinalUnit);


/** \brief recibe dos numeros(precio de Aerolineas y precio de Latam) y hace la dif de precios entre ambas.
 *
 * \param puntero a float.
 * \param
 * \return retorna todoOk = 0 si hubo un error y retorna todoOk = 1 si salio todo bien.
 *
 */
int diferenciaS(float pA, float pB,float* dif);



#endif /* CALCULOS_H_ */
