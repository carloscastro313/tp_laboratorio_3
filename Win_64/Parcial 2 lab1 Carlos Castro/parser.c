#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param idMax int*
 * \return int
 *
 */
int parser_EmployeeFromText(char* pFile ,LinkedList* pArrayListEmployee)
{
    int r;
    char auxP[50];
    char auxE[50];
    char auxI[10];
    char auxS[10];
    char auxH[5];
    Employee* aux;

    FILE* data;

    data=fopen(pFile,"r");

    //r=parser_maxId(pFileLen ,idMax);

    if(data!=NULL)
    {

        do
        {
            r=fscanf(data,"%[^,],%[^,],%[^,],%[^,],%[^\n]",auxI,auxP,auxE,auxH,auxS);

            if(r==5)
            {
                aux=employee_newParametros(auxI,auxP,auxE,auxH,auxS);
                ll_add(pArrayListEmployee, aux);


            }

        }while(!feof(data));
        fclose(data);

        printf("\n\nOK¡¡¡\n");
        printf("Cantidad de datos cargados: %d\n",ll_len(pArrayListEmployee));
        system("pause");

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
/*int parser_EmployeeFromBinary(char* pFile ,char* pFileLen ,LinkedList* pArrayListEmployee ,int* idMax)
{
    int r;
    Employee* aux=NULL;
    FILE* data;

    data=fopen(pFile,"rb");

    r=parser_maxId(pFileLen ,idMax);

    if(data!=NULL&&r!=0)
    {
        if(pArrayListEmployee!=NULL)
        {
            while(!feof(data))
            {
                aux=employee_new();
                r=fread(aux,sizeof(Employee),1,data);

                ll_add(pArrayListEmployee, aux);

            }
        }

        fclose(data);

        printf("\n\nOK¡¡¡\n");
        printf("Cantidad de datos cargados: %d\n",ll_len(pArrayListEmployee));
        system("pause");

    }else
    {
        printf("\n\nError archivo dato.csv\n");
        system("pause");
    }

    return 1;
}

int parser_maxId(char* pFileLen ,int* idMax)
{
    int flag=0;
    FILE* data;

    data=fopen(pFileLen,"rb");

    if(data!=NULL)
    {
        fscanf(data,"%d",idMax);
        flag=1;

    }
    fclose(data);

    return flag;
}*/
