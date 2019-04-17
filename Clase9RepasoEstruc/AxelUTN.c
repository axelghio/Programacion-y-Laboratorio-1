#include <stdio.h>
#include <stdint.h>
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

    printf("   %d     %10s     %c    %.2f         %d      %d      %d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaNac.dia, emp.fechaNac.mes, emp.fechaNac.anio);

}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int contador = 0;

    printf(" Legajo   Nombre  Sexo  Sueldo          dia         mes         anio\n\n");
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

            vec[indice].ocupado = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }

    }
}
