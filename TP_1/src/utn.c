#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int menu(){

        int opcion;

         system("cls");
         printf("\nSISTEMA DE VENTAS DE PASAJES\n\n");
         printf("1. Ingresar Kilometros:  \n");
         printf("2. Ingresar Precio de Vuelos:  \n");
         printf("3. Calcular todos los costos: \n");
         printf("             a) Tarjeta de debito \n");
         printf("             b) Tarjeta de credito \n");
         printf("             c) Bitcoin 1BTC -> 4606954.55 Pesos Argentinos\n");
         printf("             d) Mostrar precio por km (precio unitario)\n");
         printf("             e) Mostrar diferencia de precio ingresada Latam - Aerolineas\n");
         printf("4. Informar Resultados \n");
         printf("5. Carga forzada de datos \n");
         printf("6. Salir \n");

         printf("\nSelecciona la opción que desea utilizar: ");
         fflush(stdin);
         scanf("%d", &opcion);

         return opcion;
}


float getnumero(char* mensaje){

    float km;
        system("cls");
       puts(mensaje);
        scanf("%f", &km);

        system("cls");

    return km;
}
