#ifndef MY_MATRIZ_H_INCLUDED
#define MY_MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM_COL   100



void __function__(int Mat[][TAM_COL],int fila);

void Mostrar__Matriz(int mat[][TAM_COL],int f,int c);
void Cargar__Matriz(int mat[][TAM_COL],int F,int C);

void **Generar_Matriz(size_t Tam_Element,size_t Colum,size_t File);

void Mostrar_Diagonal_Principal(int Mat[][TAM_COL],size_t FC );
void Mostrar_Diagonal_Secundaria(int Mat[][TAM_COL],size_t FC );

void Mostrar_Diagonal_Inferior(int Mat[][TAM_COL],size_t FC);
void Mostrar_Diagonal_Superior(int Mat[][TAM_COL],size_t FC);

int **Multiplicar_Matriz(int Mat_1[][TAM_COL],size_t F1,size_t C1, int Mat_2[][TAM_COL],size_t F2,size_t C2);

void Matriz_Traspuesta(int Mat[][TAM_COL],size_t F, size_t C);

int Es_Identidad(int Mat[][TAM_COL],size_t F,size_t C);
#endif // MY_MATRIZ_H_INCLUDED
