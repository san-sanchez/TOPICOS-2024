#ifndef FIRMA_H_INCLUDED
#define FIRMA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 1
#define FATAL_ERROR 0

typedef int cmp(const void *a,const void *b);
typedef void accion(const void *src);

void Seleccion(void *vec,size_t tam,size_t ce,cmp comparar);
void *buscarMenor(void *vec,size_t tam,size_t ce,cmp comparar);
int cambiarValor(void *a, void *b,size_t tam);

void *insercion(void *vec,void *valor,size_t *ce,size_t tope,size_t tam,cmp comparar);

void mostrarFloat(const void *src);
void mostrarInt(const void *src);
void mostrargenerico(void *vec,size_t tam,size_t ce,accion mostrar);

int cmpInt(const void *A,const void *B);
int cmpFloat(const void *A,const void *B);

#endif // FIRMA_H_INCLUDED
