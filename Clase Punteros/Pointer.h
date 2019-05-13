#ifndef POINTER_H_INCLUDED
#define POINTER_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fecha;
}eEmpleado;

void puntero();

void leerYescribirPuntero(int* x);

void mostrarVector1(int numeros[], int tam);
void mostrarVector2(int numeros[], int tam);
void mostrarVector3(int* numeros, int tam);
void mostrarVector4(int* numeros, int tam);

void mostrarCadena(char* cadena);
void getChar(char* message, char* caracter);
#endif // POINTER_H_INCLUDED
