#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "../inc/LinkedList.h"
typedef struct
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* pEmployee);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int menu();

int showEmployee(Employee* employee);

int buscarIdMayor(LinkedList* pArrayListEmployee);
int buscarEmpleadoId(LinkedList* pArrayListEmployee, int id);

int menuEdit();


int menuSort();
int compararEmpleadosHorasTrabajadas(void* pEmpleadoA,void* pEmpleadoB);
int compararEmpleadosSueldo(void* pEmpleadoA,void* pEmpleadoB);

int employee_filterSalMin (void* pElement);

#endif // employee_H_INCLUDED
