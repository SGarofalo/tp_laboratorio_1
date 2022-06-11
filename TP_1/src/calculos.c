#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int realizarDescuento(float numero, float* final){

int todoOk = 0;
float descuento;

if(numero > 0 && final != NULL){

    descuento = numero * 0.1;
    *final = numero - descuento;

    todoOk = 1;
}
    return todoOk;

}
int realizarCredito(float numero, float* final){

int todoOk = 0;
float credito;

if(numero > 0 && final != NULL){

    credito = numero * 0.25;
    *final = numero + credito;

    todoOk = 1;
}
    return todoOk;

}
float realizarBitcoin(float numero){

float bitcoin;

    bitcoin = (float)numero/4606954.55;


    return bitcoin;

}
int realizarCalUnit(float precios, int km, float* PfinalUnit){

int todoOk = 0;

if(precios > 0 &&  PfinalUnit != NULL){

    *PfinalUnit = precios/km;
    todoOk = 1;
}
        return todoOk;

}
int diferenciaS(float pA, float pB,float* dif){

    int todoOk = 0;

    if(dif != NULL && pA >= 0 && pB >= 0){

     if (pA > pB) {
        *dif = pA - pB;
     }
      else {
        *dif = pB - pA;
     }

     todoOk = 1;
    }
        return todoOk;
}
