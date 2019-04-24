#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#define MAX_EMPLEADOS 100

int main()
{
    eEmpleado empleados[MAX_EMPLEADOS];

    eSector sectores[5];
    eMenu menues[10];

    inicializarSectores(sectores, 5);
    inicializarMenus(menues, 10);

    altaEmpleado(empleados, MAX_EMPLEADOS);

    return 0;
}
