#include <stdio.h>
#include <stdlib.h>

//PUNTEROS.
void muestra(int *x, int y);

int main()
{
    int nro;                //variable entera nro.
    int *n;                 //variable puntero n.
    nro=3;                  //le asignamos valor a la variable int nro.
    n=&nro;                 //asignamos el entero al puntero.
    printf("%d\n",nro);     //mostramos el valor de la variable int nro.
    printf("%p\n",n);       //mostramos la direccion de memoria de la variable puntero n.
    printf("%d\n",*n);      //mostramos el valor de la variable nro con la direccion de memoria que guardamos en n desde el puntero.


    int x, y;
    printf("Ingrese: ");
    scanf("%d",&x);
    printf("Ingrese: ");
    scanf("%d",&y);
    muestra(&x, y);
    printf("X: %d Y: %d", x, y);
    return 0;
}
void muestra(int *x, int y)
{
    *x=y;
    printf("X: %d Y: %d", x, y);
}
