#include "empleado.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void inicializarSectores(eSector sectores[], int cantidad)
{
    eSector sec[]={
        {1,"RRHH\n"},
        {2,"Compras\n"},
        {3,"Ventas\n"},
        {4,"Atencion al cliente\n"},
        {5,"Sistemas\n"}
        };
    for(int i = 0;i< cantidad; i++)
    {
        sectores[i].id = sec[i].id ;
        strcpy(sectores[i].descripcion, sec[i].descripcion);
    }
}
void inicializarMenus(eMenu menues[], int cantidad)
{

    eMenu menu[]={
        {1,"Sopa\n",35},
        {2,"Ensalada\n",},
        {3,"Milanesa con pure\n"},
        {4,"Pizza\n"},
        {5,"Guiso\n"},
        {6,"Puchero\n"},
        {7,"Churrasco\n"},
        {8,"Pastel de papas\n"},
        {9,"Ravioles\n"},
        {10,"Fideos con salsa\n"}
    };
    for(int i = 0;i< cantidad; i++)
    {
        menu[i].codigoMenu= menues[i].codigoMenu;
        strcpy(menu[i].descripcion, menues[i].descripcion);
    }
}

void altaEmpleado(eEmpleado emp[], int tam)
{
    char contMenu ='s';

    do
    {
        system("cls");
        switch(menu())
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                printf("has ingresado una opcion incorrecta.");
        }
        printf("Desea continuar, ingrese 'n' o 's'.");
        fflush(stdin);
        scanf("%c",&contMenu);
    }while(contMenu=='s');
}

void menu()
{
    int opcion;
    printf("1.- Apellido.\n");
    printf("2.- Nombre.\n");
    printf("3.- Sexo.\n");
    printf("4.- Salario.\n");
    printf("5.- Fecha ingreso.\n");
    printf("6.- Sector.\n");
    printf("7.- Salir.\n");
    scanf("%d", &opcion);

}
