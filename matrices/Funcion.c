#include "Firma.h"

void **crearMatriz(size_t tam, size_t columna, size_t fila)
{
    void **Mat=malloc(fila*sizeof(void*));
    if(!Mat)
    {
        return NULL;
    }
    char **col;
    char **error;

    for(col=(char**)Mat;col<((char**)Mat + fila);col++)
    {
        *col=malloc(columna*tam);
        if(!*col)
        {
            for(error=(char**)Mat;error<col;error++)
            {
                free(*col);
            }
            free(Mat);
            return NULL;
        }
    }
    return Mat;
}
void inicializarMatriz(int **MAT, unsigned fila, unsigned columna,int valor)
{
    size_t i,j;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<columna;j++)
        {
            MAT[i][j]=valor;
            printf("%d|",MAT[i][j]);
        }
                    printf(" \n");

    }
}
int sumaEntreDiagonalesDerecho(int mat[][TAM_MAX],size_t fc)
{
    int medio=fc/2;
    int centro;
    int i,j;
    int suma=0;

    centro=(fc%2)?medio:medio-1;

    for(i=medio+1; i < fc ;i++)
    {
        for(j=centro; j < i;j++)
        {
            suma+=mat[j][i];
        }
        centro--;
    }
    return suma;
}
int sumaEntreDiagonalesIzquierdo(int mat[][TAM_MAX],size_t fc)
{
    int medio=fc/2;
    int centro;
    int i,j;
    int suma=0;

    centro=(fc%2)==0?medio:medio-1;

    for(i=0; i < centro+1 ;i++)
    {
        for(j=i+1; j < fc-i-1 ;j++)
        {
            suma+=mat[j][i];
        }
    }
    return suma;
}
int sumaEntreDiagonalesSuperior(int mat[][TAM_MAX],size_t fc)
{
    int medio=fc/2;
    int centro;
    int i,j;
    int suma=0;

    centro=(fc%2)==0?medio:medio-1;

    for(i=0; i < centro+1 ;i++)
    {
        for(j=i+1; j < fc-i-1 ;j++)
        {
            suma+=mat[i][j];
        }
    }
    return suma;
}
int sumaEntreDiagonalesInferior(int mat[][TAM_MAX],size_t fc)
{
    int medio=fc/2;
    int centro;
    int i,j;
    int suma=0;

    centro=(fc%2)?medio:medio-1;

    for(i=medio+1; i < fc ;i++)
    {
        for(j=centro; j < i;j++)
        {
            suma+=mat[i][j];
        }
        centro--;
    }
    return suma;
}

//dos formas de multiplicar matriz

//Pensado para matricez cuadradas
int esIdentidad(int mat[][TAM_MAX],size_t fc)
{
    size_t i,j;
    for(i=0;i<fc;i++)
    {
        if (mat[i][i] != 1)
        {
            return 0;
        }
        for(j=i+1;j<fc;j++)
        {
            if(  mat[i][j]!=0 && mat[j][i]!=0)
            {
                return 0;
            }
        }
    }
    return 1;
}
void transponer(int mat[][TAM_MAX],size_t fc)
{
    size_t i,j;
    int aux;
    for(i=0;i<fc;i++)
    {
        for(j=i+1;j<fc;j++)
        {
            aux=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=aux;
        }
    }
}
int **multiplicarMatriz(int mat1[][TAM_MAX],int mat2[][TAM_MAX],size_t f1, size_t c1, size_t f2,size_t c2)
{
    size_t i,j,k;
    int**mat=(int**)crearMatriz(sizeof(int),c2,f1);
    if(!mat)
    {
        return NULL;
    }
    for(i=0;i<f1;i++)
    {
        for(j=0;j<c2;j++)
        {
            mat[i][j]=0;
            for(k=0;k<c1;k++)
            {
                mat[i][k]+=mat1[i][j]*mat2[j][k];
            }
        }
    }
    return mat;
}
