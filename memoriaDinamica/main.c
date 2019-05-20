#include <stdio.h>
#include <stdlib.h>
#include "memoDinamic.h"

int main()
{
    ///CREAMOS UN PUNTERO ENTER Y LE ASIGNAMOS MEMORIA DINAMICA.
    ///COMO NOS DEVUELVE UN PUNTERO A VOID LO QUE HACEMOS ES CASTEARLO A ENTERO.
    int* pNum = (int*) malloc(sizeof(int));

    ///VERIFICAMOS QUE NUESTRO PUNTERO SEA DISTINTO DE NULL.
    if(pNum!=NULL)
    {
        ///SI ES DISTINTO DE NULL REALIZAMOS ALGORITMOS.
        *pNum = 10;
        printf("Num: %d", *pNum);
    }
    ///BORRAMOS EL PUNTERO EN MEMORIA.
    free(pNum);


    ///USAMOS VECTORES.
    ///QUEREMOS PEDIR ESPACIO PARA 5 ENTEROS.
    int* pVecNum = (int*) malloc(sizeof(int) * 5);

    ///BORRAMOS LA PANTALLA.
    system("cls");

    ///PREGUNTAMOS QUE EL PUNTERO RECIVIDO NO SEA NULL.
    if(pVecNum!=NULL)
    {
        ///INICIALIZAMOS UN FOR PARA ASIGNARLE VALOR AL VECTOR.
        for(int i = 0; i<5; i++)
        {
            ///UTILIZAMOS UN SCANF PARA GUARDAR ESOS NUMEROS.
            printf("INGRESE El NUMERO A GUARDAR EN LA POSICION %d\n",(i+1));
            scanf("%d", (pVecNum+i));
        }

        ///INICIALIZAMOS OTRO FOR PARA MOSTRAR POR PANTALLA LOS VALORES INGRESADOS ANTERIORMENTE.
        for(int i = 0; i<5; i++)
        {
            printf("NUMERO GUARDADO EN LA POSICION %d: ",(i+1));
            printf("%d\n",*(pVecNum+i));
        }
    }
    ///AHORA QUEREMOS AGRANDAR EL VECTOR.

    ///NECESITAMOS UN AUX.
    int* pAux;

    pAux = (int*) realloc(pVecNum,sizeof(int) * 10);
    if(pAux != NULL)
    {
        pVecNum = pAux;
    }
    else
    {
        printf("No SE PUDO CONSEGUIR MAS ESPACIO EN MEMORIA.");
    }

    for(int i = 5; i<10; i++)
        {
            ///UTILIZAMOS UN SCANF PARA GUARDAR ESOS NUMEROS.
            printf("INGRESE El NUMERO A GUARDAR EN LA POSICION %d\n",(i+1));
            scanf("%d", (pVecNum+i));
        }
    ///INICIALIZAMOS OTRO FOR PARA MOSTRAR POR PANTALLA LOS VALORES INGRESADOS ANTERIORMENTE.
    for(int i = 0; i<10; i++)
    {
        printf("NUMERO GUARDADO EN LA POSICION %d: ",(i+1));
        printf("%d\n",*(pVecNum+i));
    }
    ///BORRAMOS LOS DATOS PARA LIBERAR MEMORIA.
    free(pVecNum);
    return 0;
}
