#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
#include "UTNValidaciones.h"
#include "menus.h"
#include "archivos.h"

eEmpleado* new_Empleado()
{
    FILE* bin;
    int cantidad;
    eEmpleado* nuevo;
    int auxLegajo;
    char* auxNombre[32];
    char auxSexo;
    float auxSueldo;

    nuevo = (eEmpleado*) malloc (sizeof(eEmpleado));

    if(nuevo != NULL)
    {
        system("cls");
        printf("INGRESE LEGAJO: ");
        scanf("%d", &auxLegajo);
        nuevo->legajo = auxLegajo;

        /*** PEDIMOS NOMBRE ***/

        system("cls");
        printf("INGRESE NOMBRE: ");
        fflush(stdin);
        gets(auxNombre);
        strcpy(nuevo->nombre, auxNombre);

        system("cls");
        /*** PEDIMOS SEXO ***/
        auxSexo=esDatoSexo("SEXO");
        {
            nuevo->sexo = auxSexo;
        }

        system("cls");
        /*** PEDIMOS SUELDO ***/
        printf("INGRESE SUELDO: ");
        scanf("%f", &auxSueldo);
        nuevo->sueldo = auxSueldo;


        /*** GUARDAMOS ***/
        fflush(stdin);
        bin=file();
        fseek(bin, 0L, SEEK_END);
        cantidad=fwrite(&nuevo, sizeof(nuevo), 1, bin);
        if(cantidad<1)
        {
            printf("\nERROR AL ESCRIBIR EL ARCHIVO\n");
        }
        fclose(bin);
        }
    return nuevo;
}

void mostrarEmpleado(eEmpleado* empleado)
{
    if(empleado != NULL)
    {
        printf("LEGAJO: %d //// NOMBRE: %s //// SEXO %c //// SUELDO %.2f \n", empleado->legajo, empleado->nombre, empleado->sexo, empleado->sueldo);
        system("pause");
    }
}
