#include <stdio.h>
#include <stdlib.h>

/******************Punteros******************/
//EL PUNTERO GUARDA UNA DIRECCION DE MEMORIA.
//QUE APUNTA AL PRIMER ELEMENTO DE ESE TIPO DE DATO.

void puntero()
{
    //Creamos una variable normal.
    int x = 10;
    //Creamos un puntero.
    int* p;

    //Si queremos guardar la direccion de memoria de x;
    p = &x;

    //Mostramos X.
    //Mostramos normalmente.
    printf("%p \n", &x);

    //Mostramos puntero.
    printf("%d \n", *p);
}


//Codeamos una funcion para practicar.
void leerYescribirPuntero(int* x)
{
    //Imprimimos el vaor que nos pasan por referencia.
    printf("Variable sin modificar: %d\n", *x);

    //y tambien podemos escribirle otro valor.
    *x = 38;
    printf("Variable Modificada: %d\n", *x);

    //Puntero que guarda a puntero.
    int** r = &x;

    //y para leer el valor de esa variable.

    printf("Variable 'X' pero cargandola desde 2 punteros. y su valor es el mismo: '%d' \n", **r);
}

//Puntero en vectores.
void vectoresConPunteros()
{
    //Declaramos un vector y lo inicializamos.
    int vec[] = {3, 5, 2, 4, 3};

    //Mostramos vector + ziseoff para recorrer un vec.
    for(int i = 0; i<5; i++)
    {
        printf("%d\n", *(vec + i));
    }
}
//Mostrar Vector 1 en el desarrollo utiliza nomenclatura vectoria.
void mostrarVector1(int numeros[], int tam)
{
    printf("Mostramos vector con nomenclatura vectorial.\n");
    for(int i = 0; i<tam;i++)
    {
        printf("%d\t", numeros[i]);
    }
}

//Mostrar Vector 2 en el desarrollo utiliza nomenclatura Puntero.
void mostrarVector2(int numeros[], int tam)
{
    printf("\nMostramos vector con nomenclatura puntero.\n");
    for(int i = 0; i<tam;i++)
    {
        printf("%d\t", *(numeros+i));
    }
}

//Mostrar vector 3 en el desarrollo utiliza vector.
void mostrarVector3(int* numeros, int tam)
{
    printf("\nMostramos vector con vector.\n");
    for(int i = 0; i<tam;i++)
    {
        printf("%d\t", numeros[i]);
    }
}

//Mostrar vector 4 en el desarrollo utiliza puntero.
void mostrarVector4(int* numeros, int tam)
{
    printf("\nMostramos vector con puntero.\n");

    for(int i = 0; i<tam;i++)
    {
        printf("%d\t", *(numeros+i));
    }
}

void mostrarCadena(char* cadena)
{
   while(*cadena != '\0')
   {
        printf("%c", *cadena);
        cadena++;
   }
}

void getChar(char* message, char* caracter)
{
    printf("%s", message);
    fflush(stdin);
    scanf("%c", caracter);
}
