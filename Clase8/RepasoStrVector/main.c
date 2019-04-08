#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //Variables
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41];

    //Pedido de datos
    fflush(stdin);
    printf("Ingrese Apellido: ");
    gets(apellido);
    printf("Ingrese Nombre: ");
    gets(nombre);

    //Desarrollo
    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);
    strlwr(nombreCompleto);
    nombreCompleto[0] = toupper(nombreCompleto[0]);
    for(int i = 0; i<strlen(nombreCompleto); i++)
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
    }

    //Devolucion.
    puts(nombreCompleto);
    return 0;
}
