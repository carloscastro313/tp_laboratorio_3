#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(char* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    int i;
    char auxP[50];
    char auxI[10];
    char auxS[10];
    char auxH[5];
    Employee* aux;
    Employee* auxA;
    FILE* data;
    data=fopen("data.csv","r");

    fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",auxI,auxP,auxH,auxS);
    //printf("%s %s %s %s",auxI,auxP,auxH,auxS);



    do
    {
        r=fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",auxI,auxP,auxH,auxS);

        if(r==4)
        {
            aux=employee_newParametros(auxI,auxP,auxH,auxS);
            ll_add(pArrayListEmployee, aux);

            printf("\n%d",ll_len(pArrayListEmployee));
        }

    }while(!feof(data));
    fclose(data);
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {


        auxA= (Employee*)  ll_get(pArrayListEmployee, i);

        printf("%d--%s--%d--%d\n",auxA->id,auxA->nombre,auxA->sueldo,auxA->horasTrabajadas);
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    int i;
    char auxP[50];
    char auxI[10];
    char auxS[10];
    char auxH[5];
    Employee* aux;
    FILE* data;
    data=fopen("data.csv","rb");

    fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",auxI,auxP,auxH,auxS);
    //printf("%s %s %s %s",auxI,auxP,auxH,auxS);



    do
    {
        r=fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",auxI,auxP,auxH,auxS);

        if(r==4)
        {
            aux=employee_newParametros(auxI,auxP,auxH,auxS);
            ll_add(pArrayListEmployee, aux);

            printf("%d",ll_len(pArrayListEmployee));
        }

    }while(!feof(data));
    fclose(data);
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {


        aux= (Employee*)  ll_get(pArrayListEmployee, i);

        printf("%d--%s--%d--%d\n",aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
    }
    return 1;
}
