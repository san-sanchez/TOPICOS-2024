#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#define TAM 30
#define MAX_COL 50
#define COL 5
#define TAM_COL 20

typedef struct{
    int id;
    char nombre[20];
}talu;

/*
IMPORTANTE No modifique el nombre ni el prototipo de las funciones
*/

//Implemente su propia version de strcat
//La descripcion de la funcion esta disponible en pdf ANSI C
char* mstrcat(char*s1, const char *s2);
int mstrlen(char*s1);
char *mstrcpy(char*s1,const char*s2);
int mstrcmp(char*cad,char*c2);
//Suma los elementos del triangulo que queda debajo de las diagonales
//(sin incluirlas) de una matriz de enteros
//arg 1: matriz a sumar
//arg 2: cantidad de filas o columnas (La matriz es cuadrada)
int sumTrianInfEntreDiag(int mat[][MAX_COL], int fc);
//Implemente su propia version de bsearch
//La descripcion de la funcion esta disponible en pdf ANSI C
void *mbsearch(const void *k, const void* vec, size_t ce, size_t tam, int cmp(const void *, const void *));
int comparaentero(const void*a,const void*b);
int comparafloat(const void*a,const void*b);
int comparastruct(const void*a,const void*b);

#endif // EXAMEN_H_INCLUDED
