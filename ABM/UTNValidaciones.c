#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
#include "UTNValidaciones.h"
#include "menus.h"
#include "archivos.h"

///FUNCIONES PARA LAS VALIDACIONES DE DATOS.

void esLetra(char* letras)
{
    esCadena(letras);
}

int esCadena(char* cadena)
{
    int i=0;
    int j;
    int realizoValidacion=0;

    j=strlen(cadena);

    while(i<j && realizoValidacion == 0)
    {
        if(isalpha(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            realizoValidacion=1;
        }
    }
    return realizoValidacion;
}

int esDato(char* dato, char* texto)
{
    int esDatoExito = 0;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        gets(dato);
        if(esCadena(dato)==1)
        {
            printf("RE ");
        }
    }
    while(esCadena(dato)==1);
    return esDatoExito;
}

char esDatoSexo(char* texto)
{
    int salir=0;
    char dato;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        scanf("%c",&dato);
        dato=tolower(dato);
        if(dato == 'f'|| dato =='m' )
        {
            salir=1;
        }
        else
        {
            printf("RE ");
        }
    }
    while(salir == 0);
    return dato;
}

int esNumero(char* cadena)
{
    int i=0;
    int j;
    int realizoValidacion=0;

    j=strlen(cadena);

    while(i<j && realizoValidacion == 0)
    {
        if(isdigit(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            realizoValidacion=1;
        }
    }
    return realizoValidacion;
}

int esNumerico(char* numeros, char* texto)
{
    int esNumericoExito = 0;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        gets(numeros);
        if(esNumero(numeros)==1)
        {
            printf("RE ");
        }
    }
    while(esCadena(numeros)==1);
    return esNumericoExito;
}

