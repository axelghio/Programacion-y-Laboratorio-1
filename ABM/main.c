#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
#include "UTNValidaciones.h"
#include "menus.h"

int main()
{
    eEmpleado* primerEmp;
    int salirPrograma=0;
    int opcion;
    do
    {
        system("cls");
        switch(menuPrincipal())
        {
        case 1:
            primerEmp=new_Empleado();
            system("cls");
            printf("SE HA DADO DE ALTA EXITOZAMENTE.\n");
            system("pause");
            break;
        case 2:
            mostrarEmpleado(primerEmp);
            system("cls");
            printf("SE HA DADO DE BAJA EXITOZAMENTE.\n");
            system("pause");
            break;
        case 3:

            break;
        case 4:
            cargar(primerEmp);
            system("cls");
            printf("SE HA MODIFICADO EXITOZAMENTE.\n");
            system("pause");
            break;
        case 5:
            salirPrograma = -1;
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA.\n");
            system("pause");
        }
    }while(salirPrograma!=-1);
    return 0;
}
