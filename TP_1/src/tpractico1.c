#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "utn.h"


int main()
{
	setbuf(stdout, NULL);

    int x; //km
    float y; //PrecioAerolineas
    float z; //PrecioLatam
    float preciocondescA;
    float preciocondescB;
    float precioconcredA;
    float precioconcredB;
    float pesoBitA;
    float pesoBitB;
    float calunitA;
    float calunitB;
    float resultadodif;
    char seguir = 's';
    int flagKM = 0; //no se ingreso km
    int flagPrecio = 0; //no se ingreso precios
    int flagCalculo = 0; //no se ingreso km ni precios
    char salir;



do{
      switch(menu()){
        case 1:
            x = getnumero("Ingresar kilometros: ");
            flagKM = 1;
        break;
        case 2:
            if(flagKM == 1)
            {
             y = getnumero("Ingresar Precio Aerolineas: ");

             z = getnumero("Ingresar Precio Latam: ");

              printf("Los Precios ingresados son, para Aerolineas es $%.2f y para Latam $%.2f\n",y,z);

                flagPrecio = 1;
            }
            else{
                printf("Primero debes colocar los KMs para continuar. \n");
            }
         break;
        case 3:
            if(flagPrecio == 1 ){
                            //DESCUENTO
                if(realizarDescuento(y, &preciocondescA) == 0){
                        printf("Algo salio mal.");
                }

                if(realizarDescuento(z, &preciocondescB) == 0){
                        printf("Algo salio mal.");
                }
                            //CREDITO
                if(realizarCredito(y, &precioconcredA) == 0){
                        printf("Algo salio mal.");
                }
                if(realizarCredito(z, &precioconcredB) == 0){
                        printf("Algo salio mal.");
                }
                        //BITCOIN
               pesoBitA=  realizarBitcoin(y);

                pesoBitB=realizarBitcoin(z);

                        //CALCULO UNITARIO
                if(realizarCalUnit(y, x, &calunitA) == 0){
                        printf("Algo salio mal.");
                  }

                 if(realizarCalUnit(z, x, &calunitB) == 0){
                        printf("Algo salio mal.");
                  }
                            //DIFERENCIAS
                  if(diferenciaS(y,z,&resultadodif)==0){
                	  	printf("Hubo un error. Ingrese precios mayores a 0.\n");
                   }

                        flagCalculo = 1;
                    }
                else{
                		printf("Debes colocar los KMs y precios para poder calcular. \n");
                    }
           break;
           case 4:
                if(flagCalculo == 1){
                 system("cls");
                 printf("\nKMS Ingresados: %d km\n\n" ,x );
                 printf("\nPrecio Aerolineas: $%.2f\n" ,y);
                 printf("\na) Precio con tarjeta de debito: $%.2f\n" ,preciocondescA);
                 printf("\nb) Precio con tarjeta de credito: $%.2f\n" ,precioconcredA);
                 printf("\nc) Precio pagando con bitcoin %.2f BTC\n" ,pesoBitA);
                 printf("\nc) Precio unitario: $%.2f\n\n" ,calunitA);
                 printf("\nPrecio Latam: %.2f\n" ,z);
                 printf("\na) Precio con tarjeta de debito: $%.2f\n" ,preciocondescB);
                 printf("\nb) Precio con tarjeta de credito: $%.2f\n" ,precioconcredB);
                 printf("\nc) Precio pagando con bitcoin %.2f BTC\n" ,pesoBitB);
                 printf("\nc) Precio unitario: $%.2f\n\n" ,calunitB);
                 printf("\nc) La diferencia de precio es: $%.2f\n\n" ,resultadodif);

                 system("pause");
                 system("cls");
                 break;
                }
                else{
                    printf("Primero deberia ingresar realizar los calculo para poder mostrar los resultados. \n");
                }
            break;

            case 5:
                 x = 7090;
                 y = 162965;
                 z = 159339;

                 if(realizarDescuento(y, &preciocondescA) == 0){
                        printf("Algo salio mal.");
                }

                if(realizarDescuento(z, &preciocondescB) == 0){
                        printf("Algo salio mal.");
                }
                            //CREDITO
                if(realizarCredito(y, &precioconcredA) == 0){
                        printf("Algo salio mal.");
                }
                if(realizarCredito(z, &precioconcredB) == 0){
                        printf("Algo salio mal.");
                }
                        //BITCOIN
               pesoBitA=  realizarBitcoin(y);

               pesoBitB=realizarBitcoin(z);

                        //CALCULO UNITARIO
                if(realizarCalUnit(y, x, &calunitA) == 0){
                        printf("Algo salio mal.");
                  }

                if(realizarCalUnit(z, x, &calunitB) == 0){
                        printf("Algo salio mal.");
                  }
                            //DIFERENCIAS
                 if(diferenciaS(y,z,&resultadodif)==0){
                	 	printf("Hubo un error. Ingrese precios mayores a 0.\n");
                   }

                                  system("cls");
                 printf("\nKMS Ingresados: %d km\n\n" ,x );
                 printf("\nPrecio Aerolineas: $%.2f\n" ,y);
                 printf("\na) Precio con tarjeta de debito: $%.2f\n" ,preciocondescA);
                 printf("\nb) Precio con tarjeta de credito: $%.2f\n" ,precioconcredA);
                 printf("\nc) Precio pagando con bitcoin %f BTC\n" ,pesoBitA);
                 printf("\nc) Precio unitario: $%.2f\n\n" ,calunitA);
                 printf("\nPrecio Latam: %.2f\n" ,z);
                 printf("\na) Precio con tarjeta de debito: $%.2f\n" ,preciocondescB);
                 printf("\nb) Precio con tarjeta de credito: $%.2f\n" ,precioconcredB);
                 printf("\nc) Precio pagando con bitcoin %f BTC\n" ,pesoBitB);
                 printf("\nc) Precio unitario: $%.2f\n\n" ,calunitB);
                 printf("\nc) La diferencia de precio es: $%.2f\n\n" ,resultadodif);
                 system("pause");
                 system("cls");
            break;
            case 6:
            		printf("Seguro que quiere salir?\n");
            		fflush(stdin);
            		scanf("%c",&salir);

            		if(salir == 's' || salir == 'S'){
                      seguir = 'n';
}

                      break;
                      default:
                         printf("Opcion invalida.\n");
                }
                    system("pause");

    }while(seguir == 's');

                    return 0;
}


