#ifndef MEMODINAMIC_H_INCLUDED
#define MEMODINAMIC_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[32];
    char sexo;
    float sueldo;
} eEmpleado;

eEmpleado* new_Empleado();

void mostrarEmpleado(eEmpleado* empleado);

#endif // MEMODINAMIC_H_INCLUDED
