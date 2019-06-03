#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
   Employee* empleado= (Employee*) malloc(sizeof(Employee));

   return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    int id=atoi(idStr);
    int horasTrabajada=atoi(horasTrabajadasStr);
    int sueldo=atoi(sueldoStr);
    Employee* list=employee_new();

    employee_setId(list,id);
    employee_setNombre(list, nombreStr);
    employee_setHorasTrabajadas(list,horasTrabajada);
    employee_setSueldo(list,sueldo);

    return list;
}

void employee_delete();

int employee_setId(Employee* this,int id)
{
    if(this!=NULL)
    {
        this->id=id;
    }
    return 0;
}
int employee_getId(Employee* this,int* id)
{
    if(this!=NULL)
    {
        *id=this->id;
    }
    return 0;
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
    }
    return 0;
}
int employee_getNombre(Employee* this,char* nombre)
{
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
    }
    return 0;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
    }
    return 0;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
    }
    return 0;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL)
    {
        this->sueldo=sueldo;
    }
    return 0;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
    }
    return 0;
}