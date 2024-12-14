#include "Firma.h"

void Seleccion(void *vec,size_t tam,size_t ce,cmp comparar)
{
    void *menor;
    size_t i;

    for(i=0;i<ce;i++)
    {
        menor=buscarMenor(vec,tam,ce-i,comparar);
        if(menor != vec)
        {
            cambiarValor(vec,menor,tam);
        }
        vec+=tam;
    }
}
void *buscarMenor(void *vec,size_t tam,size_t ce,cmp comparar)
{
    void *menor=vec;
    size_t i;
    vec+=tam;

    for(i=0;i<ce-1;i++)
    {
        if(comparar(menor,vec)>0)
        {
            menor=vec;
        }
        vec+=tam;
    }
    return menor;
}
int cambiarValor(void *posA, void *posB,size_t tam)
{
    char *aux=malloc(tam);
    if(!aux)
    {
        return FATAL_ERROR;
    }

    memcpy(aux,posA,tam);
    memcpy(posA,posB,tam);
    memcpy(posB,aux,tam);

    free(aux);
    return TODO_OK;
}


void *insercion(void *vec,void *valor,size_t *ce,size_t tope,size_t tam,cmp comparar)
{
    if(*ce==tope && comparar(vec+((*ce-1)*tam),valor)>0) return NULL;

    void *inicio=vec;
    vec= *ce==tope? vec+((*ce-1)*tam) : vec+(*ce*tam);

    while(vec>inicio && comparar(valor,vec-tam)<0)
    {
        memcpy(vec,vec-tam,tam);
        vec-=tam;
    }

    memcpy(vec,valor,tam);
    (*ce)++;

    return inicio;
}


void mostrargenerico(void *vec,size_t tam,size_t ce,accion mostrar)
{
    size_t i;

    for(i=0;i<ce;i++)
    {
        mostrar(vec);
        vec+=tam;
    }
}
void mostrarInt(const void *src)
{
    int *aux=(int*)src;
    printf("|%d",*aux);
}
void mostrarFloat(const void *src)
{
    float *aux=(float*)src;
    printf("|%0.2f",*aux);
}
int cmpInt(const void *A,const void *B)
{
    int *aux1=(int*)A;
    int *aux2=(int*)B;

    return *aux1-*aux2;
}
int cmpFloat(const void *A,const void *B)
{
    float *aux1=(float*)A;
    float *aux2=(float*)B;

    return *aux1-*aux2;
}

void* my_bsearch(const void *vec,const void *elemento,size_t ce,size_t tam,cmp comparar)
{
    char *medio;
    size_t pm;

    while(ce>0)
    {
        pm=ce/2;
        medio=(char*)vec + pm*tam;
        if(comparar((char*)elemento,medio) == 0 )
        {
            return (void*)medio;
        }
        if(comparar((char*)elemento,medio) > 0 )
        {
            ce=ce-pm-1;
            vec=medio + tam;
        }
        if(comparar((char*)elemento,medio) < 0 )
        {
            ce=pm;
        }
    }
    return NULL;
}


