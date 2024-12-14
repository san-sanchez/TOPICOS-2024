#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#define MAX_COL 100
#define MAXNOMEMP 31
#define TAM 500
#include <stdlib.h>
#include <string.h>
typedef struct{
    int dni;
    char nomYAp[MAXNOMEMP];
    double sueldo;
}tEmpleado;


void* _bbinaria(const void *clave, const void *vec, size_t ce, size_t tam, int cmp(const void *, const void *));
int _contarPalabras(const char* nomArc, char* palMasLarga, int* cantVeces);
int _sumTrianDerEntreDiag(int mat[][MAX_COL], int filas);
int _sumTrianInfEntreDiag(int mat[][MAX_COL], int filas);

char *mystrncpy(char *cad, const char *src, size_t n);
int mystrncmp(const char *s1, const char *s2, size_t n);
void proximaCadena(char *cad,char **inicio,char **fin);
int esLetra(char *c);

int sumTrianDerEntreDiag(int mat[][MAX_COL], int filas);
int sumTrianInfEntreDiag(int mat[][MAX_COL], int filas);
void* bbinaria(const void *clave, const void *vec, size_t ce, size_t tam, int cmp(const void *, const void *));
//void* rbbinaria(const void *clave, const void *vec, size_t ce, size_t tam, int cmp(const void *, const void *));
int cmpEmpladoNombre(const void*, const void*);
int cmp_enteros(const void* a, const void* b);
int cmp_str(const void* a, const void* b);
int crearLotePruebaTxtFrasesSim(const char* nomArch);
int contarPalabras(const char* nomArc, char* palMasLarga, int* cantVeces);
#endif // EXAMEN_H_INCLUDED
