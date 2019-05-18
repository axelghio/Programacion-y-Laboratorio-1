#include <stdio.h>
#include <stdlib.h>
#define TAM 5

///ESTRUCTURA USUARIOS.
typedef struct
{
    int numero;
    char nombre[31];
    float sueldo;
} eUsuario;

///PROTOTIPOS.
void imprimirEntero(int* puntero);
void imprimirArrayPuntero(int* puntero, int tam);
void imprimirUsuario(eUsuario user);
void imprimirUsuarios(eUsuario* pUsers,int tam);


///FUNCION MAIN.
int main()
{
    ///CREAMOS AL JEFE QUE VA A SER UN NEW USER.
    eUsuario newUser={0000,"CHAPO",50.000};

    ///CREAMOS VARIOS USUARIOS.
    eUsuario newUsers[TAM]= {{0001,"JOSE",15.000},{0002,"AXEL",20.000},{0003,"MAURO",10.000},{0004,"LAUTY",15.000},{0005,"MATHI",16.000}};

    ///ASIGNAMOS EL ARRAY A UN PUNTERO.
    eUsuario* pUser;
    pUser=newUsers;

    ///LLAMAMOS A LAS FUNCIONES PARA INPRIMIR INFORMACION.
    imprimirUsuario(newUser);
    imprimirUsuarios(pUser, TAM);


    ///RETORNO FUNCION MAIN.
    return 0;
}
///FUNCIONES.

///FUNCION QUE IMPRIME UN ENTERO.
void imprimirEntero(int* puntero)
{
    printf("EL NUMERO ES: %d\n", *puntero);
    system("pause");
}

///FUNCION QUE IMPRIME UN ARRAY DE PUNTERO.
void imprimirArrayPuntero(int* puntero, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("NUMERO: %d\n",*(puntero+i));
    }
}

///FUNCION QUE IMPRIME AL JEFE DE LA ESTRUCTURA.
void imprimirUsuario(eUsuario user)
{
    printf("EL JEFE ES: ID:%d // NOMBRE: %s // SUELDO %f \n\n\n",user.numero,user.nombre, user.sueldo);
}

///FUNCION QUE IMPRIME A LOS USUARIOS.
void imprimirUsuarios(eUsuario* pUsers,int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("EL USUARIO ES: ID:%d // NOMBRE: %s // SUELDO %f \n",(pUsers+i)->numero,(pUsers+i)->nombre, (pUsers+i)->sueldo);
    }
}
