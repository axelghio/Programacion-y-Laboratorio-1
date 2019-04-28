#include "empleado.h"
#include "input.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void inicializarSectores(eSector sectores[], int cantidad)
{
    eSector sec[]=
    {
        {1,"RRHH\n"},
        {2,"Compras\n"},
        {3,"Ventas\n"},
        {4,"Atencion al cliente\n"},
        {5,"Sistemas\n"}
    };
    for(int i = 0; i< cantidad; i++)
    {
        sectores[i].id = sec[i].id ;
        strcpy(sectores[i].descripcion, sec[i].descripcion);
    }
}
void inicializarMenus(eMenu menues[], int cantidad)
{

    eMenu menu[]=
    {
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
    for(int i = 0; i< cantidad; i++)
    {
        menu[i].codigoMenu= menues[i].codigoMenu;
        strcpy(menu[i].descripcion, menues[i].descripcion);
    }
}
void iniciarlizarEmpleados(eEmpleado emp[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        emp[i].isEmpty = 0;
    }
}
int buscarEspacio(eEmpleado emp[], int tam)
{
    int espacio = -1;
    for(int i = 0; i<tam; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            espacio = i;
            break;
        }
    }
    return espacio;
}

int menuPrincipal()
{
    int opcionPrincipal;
    printf("**---Bienvenidos a mi ABM---**\n\n");
    printf("1.- Alta Empleado.\n");
    printf("2.- Modificar Empleado.\n");
    printf("3.- Baja Empleado.\n");
    printf("4.- Listar Empleados.\n");
    printf("5.- Salir.\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcionPrincipal);

    return opcionPrincipal;
}
void mostrarSectores(eSector sec[], int tamSec)
{
    for(int i = 0; i<tamSec; i++)
    {
        printf("");
        printf("%d ",sec[i].id);
        printf(" %s",sec[i].descripcion);
    }
}
int altaEmpleado(eEmpleado emp[], int tam, eSector sec[], int tamSec, int id)
{
    int sePudoAlta=0;
    int indice;
    char auxNomb[51];
    int salir = 0;
    char auxApell[51];
    char auxSex;
    float auxSalario;
    int auxDia;
    int auxMes;
    int auxAnio;
    int auxSector;

    indice = id;

    if(buscarEspacio(emp,tam)!=-1)
    {
        emp[indice].legajo = indice;
        system("cls");
        printf("Bienvenido a la alta de empleados.\n");
        do
        {

            fflush(stdin);
            printf("\nIngrese apellido: ");
            gets(auxApell);
            if(esSoloLetras(auxApell)==1)
            {
                strcpy(emp[indice].apellido,auxApell);
                salir=1;
            }
            else
            {
                system("cls");
                printf("Ingrese solo letras\n");
                system("pause");
            }
        }
        while(salir==0);
        salir = 0;
        do
        {
            system("cls");
            fflush(stdin);
            printf("\nIngrese nombre: ");
            gets(auxNomb);
            if(esSoloLetras(auxNomb)==1)
            {
                strcpy(emp[indice].nombre,auxNomb);
                salir=1;
            }
            else
            {
                system("cls");
                printf("Ingrese solo letras\n");
                system("pause");
            }
        }
        while(salir==0);
        salir=0;
        do
        {
            system("cls");
            fflush(stdin);
            printf("\nIngrese sexo: ");
            scanf("%c",&auxSex);
            if(esSoloLetra(auxSex)==1)
            {
                emp[indice].sexo = auxSex;
                salir=1;
            }
            else
            {
                system("cls");
                printf("Has ingresado una letra no valida para el formato sexo, solo 'f' o 'm'.\n");
                system("pause");
            }
        }while(salir==0);
        salir=0;
        do{
            system("cls");
            printf("\nIngrese salario: ");
            scanf("%f",&auxSalario);
            if(auxSalario>0)
            {
                emp[indice].salario = auxSalario;
                salir=1;
            }
            else
            {
                system("cls");
                printf("\nEl salario no puede ser menor a 0, por favor ingrese un salario correcto.\n");
                system("pause");
            }
        }while(salir==0);
        salir=0;
        printf("\nFecha de ingreso.");
        do
        {
            system("cls");
            printf("\nIngrese el dia: ");
            scanf("%d",&auxDia);
            if(esDia(auxDia)==0)
            {
                system("cls");
                printf("\nError no existen dias menores a 1 o mayores a 31.\n");
                system("pause");
            }
            else
            {
                emp[indice].fechaIngreso.dia = auxDia;
                salir=1;
            }
        }while(salir == 0);
        salir = 0;
        do
        {
            system("cls");
            printf("\nIngrese el mes: ");
            scanf("%d",&auxMes);
            if(esDia(auxMes)==0)
            {
                system("cls");
                printf("\nError no existen meses menores a 1 o mayores a 12.\n");
                system("pause");
            }
            else
            {
                emp[indice].fechaIngreso.mes = auxMes;
                salir=1;
            }
        }while(salir == 0);
        salir = 0;
        do
        {
            printf("\nIngrese el anio: ");
            scanf("%d",&auxAnio);
            if(esDia(auxAnio)==0)
            {
                system("cls");
                printf("\nSolo esta permitido anios entre 1900 y 2019.\n");
                system("pause");
            }
            else
            {
                emp[indice].fechaIngreso.anio = auxAnio;
                salir=1;
            }
        }while(salir == 0);
        salir = 0;
        system("cls");
        printf("Sectores\n");
        do
        {
            mostrarSectores(sec, tamSec);
            printf("\nIngrese sector: ");
            scanf("%d",&auxSector);
            int i = 0;
            while(i<tamSec || auxSector ==sec[i].id)
            {
                if(auxSector==sec[i].id)
                {
                    emp[indice].idSector = auxSector;
                    salir=1;
                    break;
                }
                i++;
            }
        }while(salir == 0);
        salir=0;
        emp[indice].isEmpty = 1;
        printf("\nAlta realizada con exito!!\n");
        system("pause");
        sePudoAlta = 1;
    }
    else
    {
        system("cls");
        printf("\nNo hay espacio en el sistema para dar un nuevo alta.\n");
        system("pause");
    }
    return sePudoAlta;
}

void bajaEmpleados(eEmpleado emp[], int tam)
{
    int auxLeg;
    int auxEstLeg;
    char opcionBajaLogica = 'n';
    system("cls");
    printf("Para dar de baja a un empleado ingrese legajo: ");
    scanf("%d",&auxLeg);
    auxEstLeg=buscarEmpleado(emp,tam,auxLeg);
    if(auxEstLeg == auxLeg)
    {
        printf("\nDesea dar de baja a este empleado.\n");
        mostrarEmpleado(emp[auxLeg]);
        do
        {
            printf("Ingrese 's' o 'n'");
            fflush(stdin);
            scanf("%c",&opcionBajaLogica);
            opcionBajaLogica=tolower(opcionBajaLogica);
            if(opcionBajaLogica == 's')
            {
                emp[auxLeg].isEmpty = 0;
                printf("\nSe ha realizado la baja satisfactoriamente.\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("\nIngreso una letra incorrecta.\n");
                system("pause");
            }
        }while(opcionBajaLogica == 'n');
    }
    else
    {
        printf("No se encontro ningun empleado con ese legajo.");
        system("pause");
    }
}

void mostrarEmpleados(eEmpleado emp[], int tam)
{
    eEmpleado auxEmpleado;
    printf("Estado, Apellido, Nombre, Sexo, Salario, Fecha Ingreso, Sector.\n");
    for(int i = 0; i<tam-1; i++)
    {
        for(int j = 0; j<tam; j++)
        {
            if(strcmp(emp[i].apellido,emp[j].apellido)>0)
            {
                auxEmpleado = emp[i];
                emp[i] = emp[j];
                emp[j] = auxEmpleado;
            }
            else
            {
                if(strcmp(emp[i].apellido,emp[j].apellido)==0)
                {
                    if(strcmp(emp[i].nombre,emp[j].nombre)>0)
                    {
                        auxEmpleado = emp[i];
                        emp[i] = emp[j];
                        emp[j] = auxEmpleado;
                    }
                }

            }

        }
    }
    for(int i = 0; i<tam; i++)
    {
        printf("%d \t %s \t %s \t %c \t %.2f \t %d/%d/%d \t %d\n", emp[i].legajo, emp[i].apellido, emp[i].nombre, emp[i].sexo, emp[i].salario, emp[i].fechaIngreso.dia, emp[i].fechaIngreso.mes, emp[i].fechaIngreso.anio, emp[i].idSector);
    }
    system("pause");
}
int menuModifica()
{
    int opcionModifica;
    printf("1.- Apellido.\n");
    printf("2.- Nombre.\n");
    printf("3.- Sexo.\n");
    printf("4.- Salario.\n");
    printf("5.- Fecha ingreso.\n");
    printf("6.- Sector.\n");
    printf("7.- Salir.\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcionModifica);

    return opcionModifica;
}
int buscarEmpleado(eEmpleado emp[], int tam, int legajoAbuscar)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(emp[i].isEmpty==1 && emp[i].legajo == legajoAbuscar)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarEmpleado(eEmpleado emp)
{
    printf("Legajo \t Apellido \t Nombre\n");
    printf("%d \t %s \t %s\n",emp.legajo, emp.apellido, emp.nombre);
    system("pause");
}
void modificarEmpleado(eEmpleado emp[], int tam, eSector sec[], int tamSec)
{
    int auxLeg;
    int auxEstLeg;
    char opcion='n';
    int salirModifica = 0;
    int salirSwitch = 0;
    int salirCase = 0;
    int indice;
    int id=0;
    char auxApellido[51];
    char auxNombre[51];
    char auxSexo;
    float auxSalario;
    int auxDia;
    int auxMes;
    int auxAnio;
    int auxSector;
    do
    {
        system("cls");
        printf("Bienvenido al modificador de empleados.\n\n");
        printf("Por favor ingrese el legajo del empleado a editar: ");
        scanf("%d",&auxLeg);
        auxEstLeg=buscarEmpleado(emp,tam,auxLeg);
        if(auxEstLeg == auxLeg)
        {
            system("cls");
            indice = id;
            printf("Existe un empleado con ese legajo: %d\n",auxLeg);
            printf("Quiere modificarlo, 's' o 'n': ");
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                do
                {
                    system("cls");

                    switch(menuModifica())
                    {
                    case 1:
                        do
                        {

                            fflush(stdin);
                            printf("\nIngrese nuevo apellido: ");
                            gets(auxApellido);
                            if(esSoloLetras(auxApellido)==1)
                            {
                                strcpy(emp[indice].apellido,auxApellido);
                                system("cls");
                                printf("\nSe ha cambiado con exito el apellido.\n");
                                system("pause");
                                salirCase=1;
                            }
                            else
                            {
                                printf("Ingrese solo letras.\n");
                                system("pause");
                            }
                        }
                        while(salirCase==0);
                        salirCase=0;
                        break;
                    case 2:
                        do
                        {

                            fflush(stdin);
                            printf("\nIngrese nuevo nombre: ");
                            gets(auxNombre);
                            if(esSoloLetras(auxNombre)==1)
                            {
                                strcpy(emp[indice].apellido,auxNombre);
                                system("cls");
                                printf("\nSe ha cambiado con exito el nombre.\n");
                                system("pause");
                                salirCase=1;
                            }
                            else
                            {
                                printf("Ingrese solo letras.\n");
                                system("pause");
                            }
                        }
                        while(salirCase==0);
                        salirCase=0;
                        break;
                    case 3://Sexo.
                        do
                        {

                            fflush(stdin);
                            printf("\nIngrese nuevo sexo: ");
                            scanf("%c",&auxSexo);
                            if(esSoloLetra(auxSexo)==1)
                            {
                                emp[indice].sexo=auxSexo;
                                system("cls");
                                printf("\nSe ha cambiado con exito el sexo.\n");
                                system("pause");
                                salirCase=1;
                            }
                        }
                        while(salirCase==0);
                        salirCase=0;
                        break;
                    case 4://Salario.
                        do
                        {
                            printf("\nIngrese nuevo salario: ");
                            scanf("%f",&auxSalario);
                            if(auxSalario>=1)
                            {
                                emp[indice].salario = auxSalario;
                                system("cls");
                                printf("\nSe ha cambiado con exito el salario.\n");
                                system("pause");
                                salirCase=1;
                            }
                            else
                            {
                                printf("Ingrese solo numeros validos mayores a 0.\n");
                                system("pause");
                            }
                        }
                        while(salirCase==0);
                        salirCase=0;
                        break;
                    case 5://dia/mes/año/sector.
                        do
                        {
                            printf("\nModificar Fecha de ingreso.");
                            switch(menuModificaFecha())
                            {
                            case 1:
                                printf("\nIngrese el dia: ");
                                scanf("%d",&auxDia);
                                if(esDia(auxDia)==1);
                                {
                                    emp[indice].fechaIngreso.dia = auxDia;
                                }
                                break;
                            case 2:
                                printf("\nIngrese el mes: ");
                                scanf("%d",&auxMes);
                                if(esMes(auxMes)==1);
                                {
                                    emp[indice].fechaIngreso.mes = auxMes;
                                }
                                break;
                            case 3:
                                printf("\nIngrese el anio: ");
                                scanf("%d",&auxAnio);
                                if(esAnio(auxAnio)==1)
                                {
                                    emp[indice].fechaIngreso.anio = auxAnio;
                                }
                                break;
                            case 4:
                                salirCase =1;
                                break;
                            default:
                            {
                                printf("Ingreso una opcion incorrecta.");
                                system("pause");
                                break;
                            }
                            }
                        }
                        while(salirCase==0);
                        salirCase=0;
                        break;
                    case 6://Sector.
                        do
                        {
                            printf("Sectores\n");
                            mostrarSectores(sec, tamSec);
                            printf("Ingrese sector: ");
                            scanf("%d",&auxSector);
                            int i = 0;
                            while(i<tamSec || auxSector ==sec[i].id)
                            {
                                if(auxSector==sec[i].id)
                                {
                                    emp[indice].idSector = auxSector;
                                    break;
                                }
                                i++;
                            }
                            salirCase=1;
                        }
                        while(salirCase==0);
                        salirCase=0;
                        break;
                    case 7://Salir.
                        salirModifica=1;
                        salirSwitch=1;
                        break;
                    }
                }
                while(salirSwitch==0);
                salirSwitch=0;
            }
        }
        else
        {
            system("cls");
            printf("No existe un empleado con ese legajo.\n");
            system("pause");
        }
    }
    while(salirModifica==0);
    salirModifica =0;
}
int menuModificaFecha()
{
    int opcionModificaFecha;
    printf("\n1.- Dia.\n");
    printf("2.- Mes.\n");
    printf("3.- Anio.\n");
    printf("4.- Salir.\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcionModificaFecha);

    return opcionModificaFecha;
}
