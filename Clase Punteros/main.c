#include <stdio.h>
#include <stdlib.h>
#include "Pointer.h"
#define TAM 5

int main()
{
    eEmpleado unEmpleado = {1234, "JUAN", 'M', 30000, 13, 05, 2019};
    eEmpleado otroEmpleado = {2222, "JUANA", 'F', 32000, 14, 05, 2019};
    //eEmpleado* punteroEmpleado;
    //punteroEmpleado = &unEmpleado;
    /*system("cls");
    printf("LEGAJO: %d\n", punteroEmpleado ->legajo);
    printf("NOMBRE: %s\n", punteroEmpleado ->nombre);
    printf("SEXO: %c\n", punteroEmpleado ->sexo);
    printf("SUELDO: %.f\n", punteroEmpleado ->sueldo);
    printf("MOSTRAMOS CON FLECHA.\n");
    printf("FECHA: %d/%d/%d\n", punteroEmpleado ->fecha.dia, punteroEmpleado ->fecha.mes, punteroEmpleado ->fecha.anio);
    //mostrando con punto.
    printf("MOSTRAMOS CON PUNTO.\n");
    printf("FECHA: %d/%d/%d\n", (*punteroEmpleado).fecha.dia, (*punteroEmpleado).fecha.mes, (*punteroEmpleado).fecha.anio);
    system("pause");*/


    //Ahora creamos una lista
    eEmpleado lista[] = {unEmpleado, otroEmpleado};

    system("cls");
    for(int i = 0; i<2; i++)
    {
        printf("%s\n", (lista + i)->nombre);
    }
    system("pause");



    system("cls");
    int numeros[] = {3, 5, 2, 4, 3};
    mostrarVector1(numeros, TAM);
    mostrarVector2(numeros, TAM);
    mostrarVector3(numeros, TAM);
    mostrarVector4(numeros, TAM);
    system("pause");


    system("cls");
    char sexo;
    getChar("\n\nINGRESE SEXO: ", &sexo);
    printf("El SEXO ES: %c\n", sexo);
    system("pause");

    system("cls");
    char* mensaje = "HOLA MUNDO\n";
    mostrarCadena(mensaje);
    system("pause");



    return 0;
}
