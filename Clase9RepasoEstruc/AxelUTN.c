#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "AxelUTN.h"
#include <ctype.h>

float sumar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX+numeroY;
    return resultado;
}
float restar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX-numeroY;
    return resultado;
}
float dividir(float numeroX, float numeroY)
{
    float resultado;
    if(numeroY == 0)
    {
        printf("\n\nNo se puede dividir por '0'\n\n");
    }
    else
    {
        resultado = numeroX/numeroY;
    }
    return resultado;
}
float multiplicar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX*numeroY;
    return resultado;
}
unsigned long factorial(int numero)
{
    int fact=1;
    int i;
    if(numero == 0)
    {
        printf("\n\nEl operando no puede ser '0'\n\n");
    }
    else
    {
        for(i=1; i<=numero; i++)
            fact=fact*i;
    }
    return fact;
}
int getData(int min, int max, int* dato, int intentos, char* tipoDato, char* mensaje, char* eMensaje)
{
    int aux;
    int contador;
    int ok = 0;

    printf("%s %s entre: %d y %d : ", mensaje, tipoDato, min, max);
    scanf("%d", &aux);

    while((aux<min || aux>max) && contador < intentos)
    {
        contador++;
        //fflush(stdin);

        if(contador == intentos)
        {
            break;
        }
        printf("%s %d y %d.\n\n", eMensaje, min, max);
        printf("%s %s entre: %d y %d : ", mensaje, tipoDato, min, max);
        scanf("%d", &aux);
    }
    if(contador < intentos)
    {
        *dato = aux;
        ok = 1;
    }
    return ok;
}
int getInt(char* mensaje)
{
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}

float getFloat(char* mensaje)
{
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;

}

char getChar(char* mensaje)
{
    fflush(stdin);
    char aux;
    printf("%s",mensaje);
    scanf("%c",&aux);
    return aux;
}

int esNumerico(char cadena[])
{
    int sePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
            sePudo=0;
        }
        else
        {
            sePudo=1;
        }
        i++;
    }
    return sePudo;
}
int esSoloLetras(char cadena[])
{
    int sePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z'))
        {
            sePudo=0;
        }
        else
        {
            sePudo=1;
        }
        i++;
    }

    return sePudo;
}
int esAlfaNumerico(char cadena[])
{
    int sePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z')&&(cadena[i]<'0' || cadena[i]>'9'))
        {
            sePudo=0;
        }
        else
        {
            sePudo=1;
        }
        i++;
    }

    return sePudo;
}
int esTelefono(char cadena[])
{
    int sePudo=0;
    int i=0;
    int cantidadGuiones=0;
    while(cadena[i]!= '\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]!='-')&&(cadena[i]<'0' || cadena[i]>'9'))
        {
            sePudo=0;
        }
        if(cadena[i]=='-')
        {
            cantidadGuiones++;
        }
        i++;
    }
    if(cantidadGuiones==1)
    {
        sePudo=1;
    }
    return sePudo;
}

int burbujeo(char cadena[], int largoCadena, char signo)
{
    int retorno=0;
    char aux;
    if(signo=='<')
    {
        for(int i = 0; i< largoCadena-1; i++)
        {
            for(int j = i; j< largoCadena; j++)
            {
                if(cadena[i]>cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                    fflush(stdin);
                }
            }
        }
        retorno = 1;
    }
    else if(signo=='>')
    {
        for(int i = 0; i< largoCadena-1; i++)
        {
            for(int j = i; j< largoCadena; j++)
            {
                if(cadena[i]<cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                    fflush(stdin);
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eEmpleado emp)
{
    printf("%d  %5s %c  %.2f    %d  %d  %d %d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaNac.dia, emp.fechaNac.mes, emp.fechaNac.anio, emp.idSector);

}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int contador = 0;

    printf(" Legajo   Nombre  Sexo  Sueldo          dia         mes         anio    sector\n\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

void mostrarEmpleadoOrden(eEmpleado emp)
{
    printf("%d  %5s %c  %.2f    %d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.idSector);

}

void mostrarEmpleadosOrdenados(eEmpleado vec[], int tam)
{
    int contador = 0;

    printf(" Legajo   Nombre  Sexo  Sueldo  sector\n\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleadoOrden(vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }

}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam)
{

    int indice;
    int legajo;
    int esta;


    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(vec[esta]);
        }
        else
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            printf("Ingrese dia de nacimiento: ");
            scanf("%d", &vec[indice].fechaNac.dia );

            printf("Ingrese mes de nacimiento: ");
            scanf("%d", &vec[indice].fechaNac.mes );

            printf("Ingrese anio de nacimiento: ");
            scanf("%d", &vec[indice].fechaNac.anio );

            listaSector();
            printf("Ingrese Sector: ");
            scanf("%d", &vec[indice].idSector );

            vec[indice].ocupado = 1;

            printf("\n\nAlta empleado exitosa!!!\n\n");

        }

    }
}
void listaSector()
{
    system("cls");
    printf("Indique en que sector va a ser dirigido este empleado.\n\n");
    printf("1.- Sector 1\n");
    printf("2.- Sector 2\n");
    printf("3.- Sector 3\n\n");

}

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int esta;
    int legajo;
    char opcion = 'n';

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    esta = buscarEmpleado(vec, tam, legajo);
    if(esta!=-1)
    {
        printf("El empleado que desea dar de baja es: %s\n", vec[esta].nombre);
        if(vec[esta].ocupado ==0)
        {
            printf("No hay nada que mostrar");
        }
        else
        {
            printf(" Legajo   Nombre  Sexo  Sueldo          dia         mes         anio    Sector\n\n");
            mostrarEmpleado(vec[esta]);
        }

        printf("\nDesea dar de baja a %s. Ingrese 'n' o 's': ", vec[esta].nombre);
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);
        if(opcion == 's')
        {
            vec[esta].ocupado = 0;
        }
        system("cls");
        printf("Baja Exitosa.");
    }
}
void modificarEmpleado(eEmpleado vec[], int tam)
{
    int auxLeg;
    int esta;
    char opcion='n';
    char opcionSubMenu='n';
    char auxNomb[20];
    char auxSex;
    float auxSueldo;
    int auxOcupacion;
    int auxDiaNac;
    int auxMesNac;
    int auxAnioNac;
    int auxSector;
    do
    {
        system("cls");
        printf("Ingrese legajo del empleado que desea modificar: ");
        fflush(stdin);
        scanf("%d", &auxLeg);
        esta = buscarEmpleado(vec, tam, auxLeg);
        if(esta!=-1)
        {
            system("cls");
            printf(" Legajo   Nombre  Sexo  Sueldo          dia         mes         anio    sector\n\n");
            mostrarEmpleado(vec[esta]);
            printf("Este es el empleado que desea modificar? ingrese 's' o 'n' ");
            fflush(stdin);
            scanf("%c", &opcion);
            opcion=tolower(opcion);
            if(opcion == 's')
            {
                do
                {
                    switch(menuMod())
                    {
                    case 1:
                        printf("Ingrese el nombre: ");
                        fflush(stdin);
                        gets(auxNomb);
                        strcpy(vec[esta].nombre, auxNomb);
                        printf("Se ha cambiado el nombre satisfactoriamente.\n\n");
                        system("pause");
                        break;
                    case 2:
                        printf("Ingrese el Sexo: ");
                        fflush(stdin);
                        scanf("%c", &auxSex);
                        vec[esta].sexo=auxSex;
                        printf("Se ha cambiado el sexo satisfactoriamente.\n\n");
                        system("pause");
                        break;
                    case 3:
                        printf("Ingrese el Sueldo: ");
                        fflush(stdin);
                        scanf("%f", &auxSueldo);
                        vec[esta].sueldo=auxSueldo;
                        printf("Se ha cambiado el sueldo satisfactoriamente.\n\n");
                        system("pause");
                        break;
                    case 4:
                        printf("Ingrese el Ocupacion: ");
                        fflush(stdin);
                        scanf("%d", &auxOcupacion);
                        vec[esta].ocupado=auxOcupacion;
                        printf("Se ha cambiado el estado de Ocupado satisfactoriamente.\n\n");
                        system("pause");
                        break;
                    case 5:
                        printf("Ingrese el dia de nacimiento: ");
                        fflush(stdin);
                        scanf("%d", &auxDiaNac);
                        vec[esta].fechaNac.dia=auxDiaNac;
                        printf("Ingrese el mes de nacimiento: ");
                        fflush(stdin);
                        scanf("%d", &auxMesNac);
                        vec[esta].fechaNac.mes=auxMesNac;
                        printf("Ingrese el anio de nacimiento: ");
                        fflush(stdin);
                        scanf("%d", &auxAnioNac);
                        vec[esta].fechaNac.anio=auxAnioNac;
                        printf("Se ha cambiado la fecha de nacimiento satisfactoriamente.\n\n");
                        system("pause");
                        break;
                    case 6:
                        printf("Ingrese el Sector: ");
                        fflush(stdin);
                        scanf("%d",&auxSector);
                        vec[esta].idSector=auxSector;
                        printf("Se ha cambiado el sector satisfactoriamente.\n\n");
                        system("pause");
                        break;
                    case 7:
                        opcionSubMenu = 's';
                        break;
                    }
                }
                while(opcionSubMenu=='n');
            }
        }
        else
        {
            printf("No se encontro a ningun empleado con el siguien legajo.\n\n");

        }
    }
    while(opcion == 'n');

}
void listar(eEmpleado vec[], int tam)
{
    mostrarEmpleados(vec, tam);
}
int menuMod()
{
    int opcion;

    system("cls");
    printf("  *** Modificar Empleado ***\n\n");
    printf("Seleccione la opcion que desea modificar.\n\n");
    printf("1- Nombre\n");
    printf("2- Sexo\n");
    printf("3- Sueldo\n");
    printf("4- Ocupacion\n");
    printf("5- Fecha Nacimiento\n");
    printf("6- Sector\n\n");
    printf("7- Volver menu principal.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
int ordenarEmpleados(eEmpleado vec[], int tam)
{
    int auxLeg;
    char auxNombre[20];
    char auxSex;
    float auxSueldo;
    int auxSec;

    eEmpleadoDos vecDos[tam];
    for(int i = 0; i < tam; i++)
    {
        vecDos[i].idSector = vec[i].idSector;
        vecDos[i].legajo = vec[i].legajo;
        strcpy(vecDos[i].nombre, vec[i].nombre);
        vecDos[i].ocupado = vec[i].ocupado;
        vecDos[i].sexo = vec[i].sexo;
        vecDos[i].sueldo = vec[i].sueldo;
    }
    int retorno;
    switch(opcionOrdenar())
    {
    case 1:
        for(int i = 0; i< tam -1; i++)
        {
            for(int j=i; j < tam ; j++)
            {
                if(vecDos[i].legajo>vecDos[j].legajo)
                {
                    auxLeg = vecDos[i].legajo;
                    vecDos[i].legajo = vecDos[j].legajo;
                    vecDos[j].legajo = auxLeg;

                    strcpy(auxNombre, vecDos[i].nombre);
                    strcpy(vecDos[i].nombre, vecDos[j].nombre);
                    strcpy(vecDos[j].nombre, auxNombre);

                    auxSex = vecDos[i].sexo;
                    vecDos[i].sexo = vecDos[j].sexo;
                    vecDos[j].sexo = auxSex;

                    auxSueldo = vecDos[i].sueldo;
                    vecDos[i].sueldo = vecDos[j].sueldo;
                    vecDos[j].sueldo = auxSueldo;

                    auxSec = vecDos[i].idSector;
                    vecDos[i].idSector = vecDos[j].idSector;
                    vecDos[j].idSector = auxSec;
                }
            }
        }
        mostrarEmpleadosOrdenados(vecDos,tam);

        retorno = 1;
        break;
    case 2:
        for(int i = 0; i< tam -1; i++)
        {
            for(int j=i; j < tam ; j++)
            {
                if(strcmp(vecDos[i].nombre,vecDos[j].nombre))
                {
                    strcpy(auxNombre, vecDos[i].nombre);
                    strcpy(vecDos[i].nombre, vecDos[j].nombre);
                    strcpy(vecDos[j].nombre, auxNombre);

                    auxLeg = vecDos[i].legajo;
                    vecDos[i].legajo = vecDos[j].legajo;
                    vecDos[j].legajo = auxLeg;

                    auxSex = vecDos[i].sexo;
                    vecDos[i].sexo = vecDos[j].sexo;
                    vecDos[j].sexo = auxSex;

                    auxSueldo = vecDos[i].sueldo;
                    vecDos[i].sueldo = vecDos[j].sueldo;
                    vecDos[j].sueldo = auxSueldo;

                    auxSec = vecDos[i].idSector;
                    vecDos[i].idSector = vecDos[j].idSector;
                    vecDos[j].idSector = auxSec;
                }
            }
        }
        mostrarEmpleadosOrdenados(vecDos,tam);
        retorno =1;
        break;
    case 3:
        for(int i = 0; i< tam -1; i++)
        {
            for(int j=i; j < tam ; j++)
            {
                if(vecDos[i].idSector >vecDos[j].idSector)
                {
                    auxSec = vecDos[i].idSector;
                    vecDos[i].idSector = vecDos[j].idSector;
                    vecDos[j].idSector = auxSec;

                    auxLeg = vecDos[i].legajo;
                    vecDos[i].legajo = vecDos[j].legajo;
                    vecDos[j].legajo = auxLeg;

                    strcpy(auxNombre, vecDos[i].nombre);
                    strcpy(vecDos[i].nombre, vecDos[j].nombre);
                    strcpy(vecDos[j].nombre, auxNombre);

                    auxSex = vecDos[i].sexo;
                    vecDos[i].sexo = vecDos[j].sexo;
                    vecDos[j].sexo = auxSex;

                    auxSueldo = vecDos[i].sueldo;
                    vecDos[i].sueldo = vecDos[j].sueldo;
                    vecDos[j].sueldo = auxSueldo;
                }
            }
        }
        mostrarEmpleadosOrdenados(vecDos,tam);
        retorno=1;
        break;
    }
    return retorno;
}
int opcionOrdenar()
{
    system("cls");
    int opcion;
    printf("1.-Ordenar por legajo.\n");
    printf("2.-Ordenar por Nombre.\n");
    printf("3.-Ordenar por Sector.\n\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
