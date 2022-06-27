/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"



int main(void)
{
    /*startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort*/

    /****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo datos.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo datos.bin (modo binario).
    10. Salir
    *****************************************************/


    char seguir = 's';
    int dataLoaded = 0;


    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listSalariesMin = NULL;


    if (listaEmpleados == NULL)
    {
        printf("No se pudo crear el linkedList\n");
        exit(1);
    }

    do
    {
        switch (menu())
        {
        case 1:
            if(ll_isEmpty(listaEmpleados) == 1)
            {
                if(!controller_loadFromText("data.csv", listaEmpleados))
                {
                    printf("No se pudieron cargar todos los datos en texto correctamente\n\n");
                }
                else
                {
                    dataLoaded = 1;
                }
            }
            else
            {
                printf("%d      ",ll_isEmpty(listaEmpleados));
                printf("No se puede cargar is empy.\n\n");
            }
            break;

        case 2:
            if ( !controller_loadFromBinary("data.bin", listaEmpleados) )
            {
                printf("ERROR \n");
            }
            break;
        case 3:
            if  (dataLoaded == 1)  //la bandera esta para no repetir id.
            {


                if ( !controller_addEmployee(listaEmpleados) && (dataLoaded != 0))
                {
                    printf("Error \n");
                }
            }
            else
            {
                printf("Debe primero cargar el listado\n");
            }
            break;
        case 4:
            if ( !controller_editEmployee(listaEmpleados) )
            {
                printf("Error \n");
            }
            break;
        case 5:
            if ( !controller_removeEmployee(listaEmpleados) )
            {
                printf("Error \n");
            }
            break;
        case 6:
            if ( !controller_ListEmployee(listaEmpleados) )
            {
                printf("Error \n");
            }
            break;
        case 7:
            if ( !controller_sortEmployee(listaEmpleados) )
            {
                printf("Error \n");
            }
            break;
        case 8:
            if ( !controller_saveAsText("data.csv", listaEmpleados) )
            {
                printf("Error \n");
            }

            break;
        case 9:
            if ( !controller_saveAsBinary("data.bin", listaEmpleados) )
            {
                printf("Error \n");
            }

            break;
        case 10:
            if(!ll_isEmpty(listaEmpleados))
            {
                listSalariesMin = ll_filter(listaEmpleados, employee_filterSalMin);
                controller_ListEmployee(listSalariesMin);
            }
            else
            {
                printf("Error\n");
            }
            break;
        case 11:

            if(ll_isEmpty(listaEmpleados) == 0)
            {
                if(!controller_masHoras(listaEmpleados));
                {
                    printf("Error al ejecutar controller\n");
                }
            }
            else
            {
                printf("\nSe deben ingresar empleados...\n");
            }
            break;
        case 12:
            if(!controller_clonarLista(listaEmpleados) )
            {
                printf("Error\n");
            }
            break;

        case 13:
            printf("Ha seleccionado salir\n");
            seguir='n';
            break;
        default:
            printf("Opcion invalida!!\n");
        }
        system("pause");
        system("cls");
    }
    while(seguir == 's');

    //elimino listado extra.
    ll_deleteLinkedList(listSalariesMin);

    return 0;
}

