#ifndef FIRMA_H_INCLUDED
#define FIRMA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 500
void **crearMatriz(size_t tam, size_t columna, size_t fila);
void inicializarMatriz(int **MAT, unsigned fila, unsigned columna,int valor);

int sumaEntreDiagonalesDerecho(int mat[][TAM_MAX],size_t fc);
int sumaEntreDiagonalesIzquierdo(int mat[][TAM_MAX],size_t fc);
int sumaEntreDiagonalesSuperior(int mat[][TAM_MAX],size_t fc);
int sumaEntreDiagonalesInferior(int mat[][TAM_MAX],size_t fc);

#endif // FIRMA_H_INCLUDED
