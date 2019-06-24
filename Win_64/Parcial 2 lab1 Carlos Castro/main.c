#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int main()
{
    int option = 1;
    int flag=-1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaProgramadores;
    do{
        printf("\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2.Listar empleados\n3.Calcular Sueldos\n4.Listar empleadosn\n5.Filtro programadores\n6. Salir\nSelecion:");
        scanf("%d",&option);
        system("cls");
        switch(option)
        {
            case 1:
                controller_loadFromText("datos.csv",listaEmpleados);
                break;
            case 2:
                controller_ListEmployee(listaEmpleados,"id   |Nombre              |Empleo              |horas trabajadas |edad\n",0);
                break;
            case 3:
                flag=controller_salary(listaEmpleados);
                break;
            case 4:
                controller_ListEmployee(listaEmpleados,"id   |Nombre              |Empleo              |horas trabajadas |Sueldo   |edad\n",flag);
                break;
            case 5:
                listaProgramadores=controller_programadoresList(listaEmpleados);
                break;
            case 6:
                controller_saveAsText("resultados.csv", listaProgramadores);
                break;

            default:
                break;
        }
        system("cls");
    }while(option != 7);
    return 0;
}

