#ifndef ARCHIVOS_SENSOR_H_INCLUDED
#define ARCHIVOS_SENSOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_REGISTRO 50


#define TAM_SENSOR 8
#define TAM_TEMPERATURA 6
#define TAM_ESTADO 12

#define BUFFER 40

#define TODO_OK 1
#define FATAL_ERROR 0

typedef int cmp(const void *A,const void *B);

typedef struct{
    char cod[TAM_SENSOR];
    float temperatura;
    char estado[TAM_ESTADO];
}t_sensor;
typedef struct{
    char cod[TAM_SENSOR];
    float temperatura;
    int cantidad;
}t_dato;

int cargarSensor(t_sensor*vec,const char*nombreArchivo);
void desglosarlinea(t_sensor *vec,char *cad);

size_t mystrlen(const char *cad);
char *mystrrchr(const char *cad,int c);
char *mystrcpy(char *cad,const char *src);

void *Insercion(void *vec,void *dato,size_t tam,size_t tope,size_t *ce,cmp comparar);
void seleccion(void *vec,size_t tam,size_t ce,cmp comparar);
void *buscarMenor(void *vec,size_t ce,size_t tam,cmp comparar);
int intercambiar(void *src1,void*src2,size_t tam);
int cmpCod(const void *a,const void *b);
void cargarPromSensores(t_sensor *vec,t_dato *src,size_t ce);
#endif // ARCHIVOS_SENSOR_H_INCLUDED
