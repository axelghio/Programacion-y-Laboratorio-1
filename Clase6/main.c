#include <stdio.h>
#include <stdlib.h>
#define CANT 5
#include "AxelUTN.h"
//Ordenamiento sobre vectores (inserción y burbujeo)
int main()
{
    int aux;
    //declaramos un vector.
    int vec[CANT]= {2,5,6,7,8};
    aux=vec[0];
    for(int i=0; i<CANT-1; i++)
    {
        for(int j=i+1; j<CANT; j++)
        {
            if(vec[i]>vec[j])
            {
                aux = vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
    for(int i=0; i<CANT; i++)
    {
        printf("Numero: %d\n",vec[i]);
    }
    return 0;
}
