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
    //int i;
    char auxP[50];
    char auxI[10];
    char auxS[10];
    char auxH[5];
    Employee* aux;

    FILE* data;
    data=fopen(pFile,"r");
    if(data!=NULL)
    {
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
    }else
    {
        printf("\n\nError archivo dato.csv");
        system("pause");
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
int parser_EmployeeFromBinary(char* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    char auxP[50];
    char auxI[10];
    char auxS[10];
    char auxH[5];
    Employee* aux;
    FILE* data;
    data=fopen(pFile,"rb");
    if(data!=NULL)
    {
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

    }else
    {
        printf("\n\nError archivo dato.csv\n");
        system("pause");
    }

    return 1;
}
