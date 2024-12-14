#include <stdio.h>
#include "examen.h"

int _contarPalabras(const char* nomArc, char* palMasLarga, int* cantVeces)
{
    FILE *txt=fopen(nomArc,"rt");
    if(!txt)
    {
        return 0;
    }
    char *linea;
    linea=malloc(TAM*sizeof(char));
    if(!linea)
    {
        fclose(txt);
        return 0;
    }

    char *ptr_inicio;
    char *ptr_fin;

    size_t tamanio = 0;
    int  cantidadDePalabras=0;

    while(fgets(linea,TAM,txt))
    {
        while(*linea && (*linea!='\n'))
        {
            proximaCadena(linea,&ptr_inicio,&ptr_fin);
            if(*ptr_inicio && *ptr_inicio!='\n')
            {
                cantidadDePalabras++;
            }
            linea = ptr_fin;

            if((ptr_fin - ptr_inicio)>tamanio)
            {
                tamanio = ptr_fin - ptr_inicio;
                 palMasLarga=mystrncpy(palMasLarga,ptr_inicio,tamanio);
                *cantVeces = 0;
            }
            if(strncmp(palMasLarga,ptr_inicio,tamanio)==0)
            {
                (*cantVeces)++;
            }

        }
    }
    fclose(txt);
    //free(linea);
    return cantidadDePalabras;
}
char *mystrncpy(char *cad, const char *src, size_t n)
{
    size_t posicion=0;
    char *inicio=cad;
    char *ptr=(char*)src;
    while(posicion < n)
    {
        *cad=*ptr;
        cad++;
        ptr++;
        posicion++;
    }
    *cad='\0';
    return inicio;
}
int mystrncmp(const char *s1, const char *s2, size_t n)
{
    size_t pos=0;
    while(*s1==*s2&&(pos<n)&&*s1)
    {
        s1++;s2++;
    }
    if(n==pos)
    {
        return 0;
    }
    if(*s1>*s2)
    {
        return 1;
    }
    return -1;
}
void proximaCadena(char *cad,char **inicio,char **fin)
{
    while(*cad!='\n' && (esLetra(cad)==0))
    {
        cad++;
    }
    *inicio=cad;
    while(esLetra(cad))
    {
        cad++;
    }
    *fin=cad;
}
int esLetra(char *c)
{
    if((*c>='a'&&*c<='z')||(*c>='A'&&*c<='Z'))
    {
        return 1;
    }
    return 0;
}


void* _bbinaria(const void *clave, const void *vec, size_t ce, size_t tam, int cmp(const void *, const void *))
{
    char *medio;
    size_t pm;
    while(ce>0)
    {
        pm=ce/2;
        medio=(char*)vec + pm*tam;
        if(cmp((char*)clave,medio)==0)
        {
            return(void*)medio;
        }
        if(cmp((char*)clave,medio)>0)
        {
            ce=ce-pm-1;
            vec=medio+tam;
        }else
        {
           ce=pm;
        }
    }
    return NULL;
}


int _sumTrianDerEntreDiag(int mat[][MAX_COL], int filas)
{
    int medio=filas/2;
    int centro=(filas%2)?medio:medio - 1;

    int i,j;
    int suma=0;

    for(i=medio+1;i<filas-1;i++)
    {
        for(j=centro;j<i;j++)
        {
            suma+=mat[j][i];
        }
        centro--;
    }
    return suma;
}

int _sumTrianInfEntreDiag(int mat[][MAX_COL], int filas)
{
    int medio=filas/2;
    int centro=(filas%2)?medio:medio - 1;

    int i,j;
    int suma=0;

    for(i=medio+1;i<filas-1;i++)
    {
        for(j=centro;j<i;j++)
        {
            suma+=mat[i][j];
        }
        centro--;
    }
    return suma;
}
