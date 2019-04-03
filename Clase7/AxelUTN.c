#include <stdio.h>
#include <stdint.h>

float sumar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX+numeroY;
    return resultado;
}
float restar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX-numeroY;
    return resultado;
}
float dividir(float numeroX, float numeroY)
{
    float resultado;
    if(numeroY == 0)
    {
        printf("\n\nNo se puede dividir por '0'\n\n");
    }
    else
    {
        resultado = numeroX/numeroY;
    }
    return resultado;
}
float multiplicar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX*numeroY;
    return resultado;
}
unsigned long factorial(int numero)
{
    int fact=1;
    int i;
    if(numero == 0)
    {
        printf("\n\nEl operando no puede ser '0'\n\n");
    }
    else
    {
        for(i=1;i<=numero;i++)
        fact=fact*i;
    }
    return fact;
}
int getData(int min, int max, int* dato, int intentos, char* tipoDato, char* mensaje, char* eMensaje)
{
    int aux;
    int contador;
    int ok = 0;

    printf("%s %s entre: %d y %d : ", mensaje, tipoDato, min, max);
    scanf("%d", &aux);

    while((aux<min || aux>max) && contador < intentos)
    {
        contador++;
        //fflush(stdin);

        if(contador == intentos)
        {
            break;
        }
        printf("%s %d y %d.\n\n", eMensaje, min, max);
        printf("%s %s entre: %d y %d : ", mensaje, tipoDato, min, max);
        scanf("%d", &aux);
    }
    if(contador < intentos)
    {
        *dato = aux;
        ok = 1;
    }
    return ok;
}
