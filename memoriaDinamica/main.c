#include <stdio.h>
#include <stdlib.h>
#include "memoDinamic.h"

typedef struct{
    int legajo;
    char nombre[32];
    char sexo;
    float sueldo;
} eEmpleado;

eEmpleado* new_Empleado();
void mostrarEmpleado(eEmpleado* empleado);
eEmpleado* new_EmpleadoParam(int leg, char* nombre, char sexo, float sueldo);

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

    ///UTILIZAMOS LA FUNCION REALOC.
    pAux = (int*) realloc(pVecNum,sizeof(int) * 10);

    ///VERIFICAMOS QUE NO NOS DEVUELVA NULL.
    if(pAux != NULL)
    {
        ///SI ES DISTINTO DE NULL ASIGNAMOS EL AUXILIAR A NUESTRO PUNTERO ORIGINAL.
        pVecNum = pAux;
    }
    else
    {
        printf("No SE PUDO CONSEGUIR MAS ESPACIO EN MEMORIA.");
    }

    ///INICIALIZAMOS OTRO FOR PARA AGREGAR LOS NUMEROS RESTANTES.
    for(int i = 5; i<10; i++)
        {
            ///UTILIZAMOS UN SCANF PARA GUARDAR ESOS NUEVOS NUMEROS.
            printf("INGRESE El NUMERO A GUARDAR EN LA POSICION %d\n",(i+1));
            scanf("%d", (pVecNum+i));
        }
    ///INICIALIZAMOS OTRO FOR PARA MOSTRAR POR PANTALLA LOS VALORES INGRESADOS ANTERIORMENTE.
    for(int i = 0; i<10; i++)
    {
        printf("NUMERO GUARDADO EN LA POSICION %d: ",(i+1));
        printf("%d\n",*(pVecNum+i));
    }

    ///AHORA VAMOS A ACHICAR EL ARRAY

    ///LO HACEMOS CON UN REALLOC Y COMO SABEMOS QUE YA NO NOS PUEDE DEVOLVER NULL NO LO VERIFICAMOS.
    pVecNum = (int*) realloc(pVecNum, sizeof(int) * 5);

    ///MOSTRAMOS QUE REALMENTE SE ACHICO EL ARRAY
    for(int i = 0; i<10; i++)
    {
        printf("NUMERO GUARDADO EN LA POSICION %d: ",(i+1));
        printf("%d\n",*(pVecNum+i));
    }


    ///AHORA VAMOS A CREAR UNA ESTRUCTURA.
    eEmpleado* pEmp = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(pEmp == NULL)
    {
        exit(1);
    }
    else
    {
        printf("INGRESE LEGAJO: ");
        scanf("%d", &pEmp->legajo);

        printf("INGRESE NOMBRE: ");
        fflush(stdin);
        gets(pEmp->nombre);

        printf("INGRESE SEXO: ");
        scanf("%c",&pEmp->sexo);

        printf("INGRESE SUELDO: ");
        scanf("%f",&pEmp->sueldo);

        printf("LEGAJO: %d //// NOMBRE: %s //// SEXO %c //// SUELDO %.2f ", pEmp->legajo, pEmp->nombre, pEmp->sexo, pEmp->sueldo);
    }
    eEmpleado* unEmpleado;
    unEmpleado = new_Empleado();
    eEmpleado* otroEmpleado;
    otroEmpleado = new_EmpleadoParam(222, "Jose", 'm', 4000);
    mostrarEmpleado(otroEmpleado);

    ///BORRAMOS LOS DATOS PARA LIBERAR MEMORIA.
    free(pNum);
    free(pAux);
    free(pVecNum);

    return 0;
}
eEmpleado* new_Empleado(){
    eEmpleado* nuevo;

    nuevo = (eEmpleado*) malloc (sizeof(eEmpleado));

    if(nuevo != NULL)
    {
        nuevo->legajo = 0;
        strcpy(nuevo->nombre, "");
        nuevo->sexo = '';
        nuevo->sueldo = 0;
    }
    return nuevo;
}

eEmpleado* new_EmpleadoParam(int leg, char* nombre, char sexo, float sueldo){
    eEmpleado* nuevo;

    nuevo = (eEmpleado*) malloc (sizeof(eEmpleado));

    if(nuevo != NULL)
    {
        nuevo->legajo = leg;
        strcpy(nuevo->nombre, nombre);
        nuevo->sexo = sexo;
        nuevo->sueldo = sueldo;
    }
    return nuevo;
}

void mostrarEmpleado(eEmpleado* empleado)
{
    if(empleado != NULL)
    {
        printf("LEGAJO: %d //// NOMBRE: %s //// SEXO %c //// SUELDO %.2f ", empleado->legajo, empleado->nombre, empleado->sexo, empleado->sueldo);
    }
}
