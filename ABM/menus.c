#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
#include "UTNValidaciones.h"
#include "menus.h"
#include "archivos.h"

int menuPrincipal(void)
{
    int opcion;

    printf("INGRESE UNA OPCION.\n");
    printf("1.-ALTA DE UN EMPLEADO.\n");
    printf("2.-BAJA DE UN EMPLEADO.\n");
    printf("3.-MODIFICACION DE UN EMPLEADO.\n");
    printf("4.-LISTAR EMPLEADOS.\n");
    printf("5.-SALIR.\n");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
