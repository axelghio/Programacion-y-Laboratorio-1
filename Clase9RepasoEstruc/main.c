#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "AxelUTN.h"

#define TAM 2
int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM]={
        {1234, "Juan", 'm', 30000, 1},
        {2222, "Ana", 'f', 32000, 1},
        {2211, "Jorge", 'm', 28000, 0}
    };
    eSector sectores[5]={
        {1,"legales"},
        {2,"RRHH"},
        {3,"Cop"},
        {4,"legales"},
        {5,"legales"},
    };
    //inicializarEmpleados(lista, TAM);


    do
    {
        switch(menu())
        {

        case 1:
            altaEmpleado(lista, TAM);
            system("pause");
            break;

        case 2:
            bajaEmpleado(lista, TAM);
            system("pause");
            break;

        case 3:
            modificarEmpleado(lista, TAM);
            system("pause");
            break;

        case 4:
            //ordenarEmpleados(lista, TAM);
            system("pause");
            break;

        case 5:
            system("cls");
            listar(lista, TAM);
            system("pause");
            break;

        case 6:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

