#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    //.........
    //.........
    //.........
    //.........
    lowLimit = 1;
    hiLimit = 100;
    printf("%s",message);
    fflush(stdin);
    scanf("%d", input);
    if(*input< lowLimit|| *input>hiLimit)
    {
        printf("%s", eMessage);
        return -1;
    }
    return 0;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    //.........
    //.........
    //.........
    //.........
    lowLimit = 0;
    hiLimit = 10000;
    printf("%s",message);
    fflush(stdin);
    scanf("%f", input);
    if(*input<lowLimit || *input>hiLimit)
    {
        printf("%s", eMessage);
        return -1;
    }
    return 0;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    //.........
    //.........
    //.........
    //.........
    lowLimit = 'A';
    hiLimit = 'C';
    printf("%s",message);
    fflush(stdin);
    scanf("%c", input);
    input=toupper(input);
    if(input == 'A' || input == 'B' || input == 'C')
    {
        return 0;
    }
    else
    {
        printf(eMessage);
        return -1;
    }
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    //.........
    //.........
    //.........
    //.........

    strcpy(input,"Sheldon");
    return 0;
}
