#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
#include "UTNValidaciones.h"
#include "menus.h"
#include "archivos.h"
#define ARCHIVO ".\\data.csv"

FILE* file(void)
{
    FILE* auxBin;
    if((auxBin=fopen(ARCHIVO, "rb+"))==NULL)
    {
        if ((auxBin=fopen(ARCHIVO, "wb+")) == NULL)
        {
            printf("NO SE PUEDE ABRIR EL ARCHIVO.\n");
            exit(1);
        }
    }
    return auxBin;
}

void cargar(eEmpleado* persona)
{
    int cant;
    FILE* bin;
    bin=file();
    rewind(bin);

    while(!feof(bin))
    {
        cant = fread(&persona,sizeof(persona),1,bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("NO PUDO LEER EL ULTIMO REGISTRO");
                break;
            }
        }
        printf("%d %s %c %f\n", persona->legajo, persona->nombre, persona->sexo, persona->sueldo);
        system("pause");
    }
    fclose(bin);
    //getch();
}
