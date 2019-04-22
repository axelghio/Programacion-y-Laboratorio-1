#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED
typedef struct
{
    int id;
    char desc[31];
} eSector;
void obtenerSector(eSector sectores[], int tam, int id, char desc[]);
#endif // SECTORES_H_INCLUDED
