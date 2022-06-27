#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "controller.h"
#include "miBiblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile = NULL;

	if ( path != NULL && pArrayListEmployee != NULL )
	{

		pFile = fopen( path, "r");
		if ( pFile == NULL )
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if ( parser_EmployeeFromText( pFile, pArrayListEmployee ) )
			{
				printf( "Carga de archivo de texto exitosa\n" );
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile= NULL;

	if ( path != NULL && pArrayListEmployee != NULL )
	{
		pFile = fopen( path, "rb");
		if ( pFile == NULL )
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if ( parser_EmployeeFromBinary( pFile, pArrayListEmployee ) )
			{
				printf( "Carga de archivo binario exitoso!!\n" );
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;

	Employee* auxEmpleado = NULL;

	if ( pArrayListEmployee != NULL )
	{
		printf("     *** Alta de empleado *** \n");


		auxEmpleado = employee_new();
		id = buscarIdMayor(pArrayListEmployee);
		id++;

		printf("El ID asignado sera: %d\n", id);

		pedirString(nombre, "Ingrese su  nombre: ", 60);
		validarInt(&horasTrabajadas, "Ingrese las horas trabajadas: ", "ERROR, Ingrese cantidad de horas validas (0-1000): ", 0, 1000, 6);
		validarInt(&sueldo, "Ingrese  sueldo: ", "ERROR, Ingrese un sueldo valido (0-200000): ", 0, 200000, 6);

		if ( employee_setId(auxEmpleado, id) &&
			 employee_setNombre(auxEmpleado, nombre) &&
			 employee_setSueldo(auxEmpleado, sueldo) &&
			 employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas)
		   )
		{
			ll_add( pArrayListEmployee, auxEmpleado );
			printf("Alta exitosa!!\n");
			todoOk =1;
		}
		else
		{
			employee_delete(auxEmpleado);
		}
	}
	return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk= 0;
	int id;
	Employee* auxEmpleado;
	int indice;
	char seguir = 's';
	char confirma;

	char auxNombre[60];
	int auxHorasTrabajadas;
	int auxSueldo;


	controller_ListEmployee(pArrayListEmployee);

	if(pArrayListEmployee != NULL)
	{

		printf("   *** MODIFICACION PASAJEROS *** \n\n");

		printf("Ingrese ID del empleado: \n");
		scanf("%d", &id);

		indice = buscarEmpleadoId(pArrayListEmployee, id);

		if ( indice != -1)
		{
			auxEmpleado = ll_get(pArrayListEmployee, indice);

			do
			{
			    system("cls");
				printf("\n");
				printf("--------------------------------------------------------\n");
				printf(" ID      NOMBRE         HORAS-TRABAJADAS        SUELDO\n");
				printf("--------------------------------------------------------\n");
				showEmployee(auxEmpleado);


				switch (menuEdit())
				{
				case 1:

					pedirString(auxNombre,"Ingrese nuevo nombre: \n",50);

					printf("Confirma mofidicacion? (S/N): \n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S')
					{
						employee_setNombre(auxEmpleado, auxNombre);
						printf("MODIFICACION EXITOSA!!\n");
					}
					else
					{
						printf("MODIFICACION CANCELADA \n");
					}
					break;

				case 2:

					validarInt(&auxHorasTrabajadas,"Ingrese nueva cantidad de horas trabajadas: \n", "ERROR,Ingrese cantidad de horas trabajadas(0-1000) ", 0, 1000, 6 );
					printf("confirma modificacion? (S/N): \n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S')
					{
						employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas);
						printf("MODIFICACION EXITOSA!!\n");
					}
					else
					{
						printf("MODIFICACION CANCELADA \n");
					}

					break;

				case 3:

					validarInt(&auxSueldo,"Ingrese nuevo sueldo: (0-200000): \n", "ERROR, Ingrese nuevo sueldo valido (0-200000): \n", 0, 200000, 6 );
					printf("Confirma modificacion? (S/N): \n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S')
					{
						employee_setSueldo(auxEmpleado, auxSueldo);
						printf("MODIFICACION EXITOSA!!\n");
					}
					else
					{
						printf("MODIFICACION CANCELADA \n");
					}
					break;

				case 4:
					printf("Ha seleccionado salir\n");
					seguir='n';
					break;

				default:
					printf("Opcion invalida!!\n");
					break;
				}
				system("pause");
			}
			while(seguir == 's');
		}

		todoOk=1;
	}
	return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;

	Employee* auxEmpleado;

	controller_ListEmployee(pArrayListEmployee);

	if ( pArrayListEmployee != NULL )
	{
		printf("\n        *** BAJA EMPLEADO ***\n");

		printf("Ingrese ID del empleado: ");
		scanf("%d", &id);


        indice = buscarEmpleadoId( pArrayListEmployee, id );
		if ( indice == -1 )
		{
			printf("No se pudo encontrar al empleado!!\n");
		}
		else
		{
			auxEmpleado = ll_get(pArrayListEmployee, indice);
			printf("--------------------------------------------------------\n");
			printf(" ID      NOMBRE         HORAS-TRABAJADAS        SUELDO\n");
			printf("--------------------------------------------------------\n");
			showEmployee(auxEmpleado);

			printf("Confirma baja? (S/N)\n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = toupper(confirma);

			if ( confirma == 'S' )
			{
				ll_remove(pArrayListEmployee, indice);
				printf("BAJA EXITOSA!!\n");
				todoOk = 1;
			}
			else
			{
				printf("BAJA CANCELADA POR EL USUARIO!!\n");
			}
		}

	}
	return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	Employee* auxEmpleado;
	if (pArrayListEmployee != NULL)
	{
        printf("----------------------------------------------------\n");
		printf("              *** LISTA EMPLEADOS ***	\n");
		printf("----------------------------------------------------\n");
		printf(" ID      NOMBRE      HORAS-TRABAJADAS    SUELDO\n");
		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = (Employee*) ll_get( pArrayListEmployee, i );
			showEmployee(auxEmpleado);
		}
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	char seguir = 's';
	int todoOk = 0;

	if ( pArrayListEmployee != NULL )
	{
        printf("----------------------------------------------------\n");
		printf("         *** ORDENAMIENTO EMPLEADOS ***\n");
		printf("----------------------------------------------------\n");

		do
		{
		    system("cls");

			switch (menuSort())
			{
			case 1:
				ll_sort( pArrayListEmployee, compararEmpleadosHorasTrabajadas, 1 );
				controller_ListEmployee(pArrayListEmployee);

				break;

			case 2:
				ll_sort( pArrayListEmployee, compararEmpleadosHorasTrabajadas, 0 );
				controller_ListEmployee(pArrayListEmployee);

				break;

			case 3:

				ll_sort( pArrayListEmployee, compararEmpleadosSueldo, 1 );
				controller_ListEmployee(pArrayListEmployee);
				break;
			case 4:
				ll_sort( pArrayListEmployee, compararEmpleadosSueldo, 0 );
				controller_ListEmployee(pArrayListEmployee);
				break;

			case 5:
				printf("Ha seleccionado salir\n");
				seguir='n';
				break;

			default:
				printf("Opcion invalida!!\n");
				break;
			}
			system("pause");
		}
		while(seguir == 's');
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile;
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	Employee* auxEmpleado;

	if ( path != NULL && pArrayListEmployee != NULL )
	{
		pFile = fopen(path, "w");
		if ( pFile == NULL )
		{
			printf("ERROR,No se pudo abrir el archivo\n");

		}

		fprintf( pFile, "id,nombre,horasTrabajadas,sueldo\n" );

		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			if ( employee_getId(auxEmpleado, &id) &&
					employee_getNombre(auxEmpleado, nombre) &&
					employee_getHorasTrabajadas( auxEmpleado, &horasTrabajadas) &&
					employee_getSueldo(auxEmpleado, &sueldo)
			   )
			{
				fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
				todoOk = 1;
			}
		}
		fclose(pFile);
	}

	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile;
	Employee* auxEmpleado;

	if ( path != NULL && pArrayListEmployee != NULL )
	{
		pFile = fopen(path, "wb");
		if ( pFile == NULL )
		{
			printf("ERROR, No se pudo abrir el archivo\n");

		}

		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);

			if ( auxEmpleado != NULL )
			{
				fwrite( auxEmpleado, sizeof(Employee), 1, pFile );
				todoOk = 1;
			}
		}
		fclose(pFile);
	}

	return todoOk;
}

int controller_masHoras(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int flag = 0;
	int mayorHoras;
	Employee* auxEmp;
	int indiceEncontrado;


	if(pArrayListEmployee != NULL)
	{

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
	        auxEmp =  ll_get(pArrayListEmployee, i);

			if(flag == 0 || (mayorHoras < auxEmp->horasTrabajadas ))
			{
				mayorHoras = auxEmp->horasTrabajadas;

				flag = 1;
			}
		}

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmp = ll_get(pArrayListEmployee, i);

			if(mayorHoras == auxEmp->horasTrabajadas )
			{
				indiceEncontrado = ll_indexOf(pArrayListEmployee, auxEmp);
				retorno = 1;
			}
		}
	      auxEmp = ll_pop(pArrayListEmployee, indiceEncontrado);

	      showEmployee(auxEmp);

	      printf("\n\nEmpleado con mas horas trabajadas encontrado exitosamente...\n");

	      employee_delete(auxEmp);
	}

	return retorno;
}

int controller_clonarLista(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    LinkedList* listaClonada = NULL;

    if (pArrayListEmployee != NULL )
    {

    	listaClonada = ll_clone(pArrayListEmployee);

        if ( ll_containsAll(pArrayListEmployee, listaClonada)  )
        {
            controller_ListEmployee( listaClonada );
            printf("\nLista clonada exitosamente!!\n" );
            retorno = 1;
            ll_deleteLinkedList(listaClonada); //la borro porque no la uso, el sistema la muestra igual la lista, despues de apretar cualquier tecla el espacio esta liberado.
        }

    }
    return retorno;
}

