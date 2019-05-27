#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

FILE* file(void);

void guardar(eEmpleado* persona, FILE* bin);

void cargar(eEmpleado* persona);

#endif // ARCHIVOS_H_INCLUDED
