#include <stdio.h>
#include <stdlib.h>
//arrays

int main()
{
    int numeros[10];                                    //Declaramos un vector de 10 espacios
    for(int i=0;i<10;i++)                               //Inicializamos un for para recorrer el array.
    {
        printf("Ingrese numero: ");                     //Texto para que el usuario sepa que tiene que ingresar numeros.
        scanf("%d",&numeros[i]);                        //Tomamos el ingreso de esos numeros y los guardamos en cada espacio del vector.
    }
    for(int i=0;i<10;i++)                               //Inicializamos otro for pero esta vez.
    {
        printf("\nlos numeros son: %d",numeros[i]);     //Mostramos los numeros ingresados en el vector por pantalla.
    }

    return 0;
}
