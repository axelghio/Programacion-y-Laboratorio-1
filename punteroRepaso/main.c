#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* punteroCadena);
void mostrarCadena2(char* punteroCadena);
void mostrarCadena3();

int main()
{
    char palabra[]="hola";

    mostrarCadena(palabra);
    mostrarCadena2(palabra);
    mostrarCadena3();
    return 0;
}
void mostrarCadena(char* punteroCadena)
{
    printf("IMPRIMIMOS LA CADENA HOLA Y SUS DIRECCIONES A MEMORIA. CON WHILE.\n");
    while(*punteroCadena != '\0')
    {
        printf("%c\t",*punteroCadena);
        printf("%p\n",*punteroCadena);
        punteroCadena++;
    }
}

void mostrarCadena2(char* punteroCadena)
{
    printf("IMPRIMIMOS LA CADENA HOLA Y SUS DIRECCIONES A MEMORIA. CON FOR.\n");
    for(int i = 0; i<4; i++)
    {
        printf("%c\t",*(punteroCadena+i));
        printf("%p\n", punteroCadena);
    }
}

void mostrarCadena3()
{
    int numero= 25;
    int* puntero;
    int** punteroDoble;

    puntero=&numero;
    punteroDoble = &puntero;

    printf("IMPRIMIMOS EL PUNTERO SIMPLE Y EL PUNTERO A PUNTERO.\n");

    printf("%d\n", *puntero);
    printf("%d\n", **punteroDoble);
}
