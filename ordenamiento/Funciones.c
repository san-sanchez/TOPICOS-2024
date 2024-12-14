#include "Genericos.h"

void *my_map(void *vec,size_t tam,size_t ce, Funcion accion)
{
    void *inicio=vec;

    unsigned i;

    for(i=0 ;i < ce; i++)
    {
        accion(vec);
        vec+=tam;
    }

    return inicio;
}
void *my_filter(void *vec, size_t tam, size_t *ce,void *elemento, accion metodo)
{
    void *pl=vec;
    void *pe=vec;

    unsigned i;
    unsigned ceInterna=*ce;

    for(i=0;i<ce;i++)
    {
        if(metodo(pl))
        {
            if(pe!=pl)
            {
                memcpy(pe,pl,tam);
            }

            pe+=tam;
        }else{
            ceInterna--;
        }
        pl+=tam;
    }
    *ce=ceInterna;
    return vec;
}
void *my_reduce(void *vec,size_t tam, size_t ce,reduccion metodo)
{

    unsigned i;
    void *acum;

    for(i=0;i<ce;i++)
    {
        metodo(vec,acum);
        vec+=tam;
    }
    return acum;
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
void *ordenSeleccion(void *vec,size_t tam,size_t ce,void *elemento,cmp comparar)
{
    void *src=vec;
    size_t i;

    for(i=0;i<ce-1;i++)
    {
        void *menor=buscarMenor(src,ce-i,tam,comparar);
        if(menor!=src)
        {
            intercambiar(menor,src,tam);
        }
        src+=tam;
    }
    return vec;
}
void *buscarMenor(void *src,size_t ce,size_t tam, cmp comparar)
{
    size_t i;
    void *menor=src;
    src+=tam;

    for(i=0;i<ce-1;i++)
    {
        if(comparar(menor,src))
        {
            menor=src;
        }
        src+=tam;
    }
    return (void*)menor;
}
int intercambiar(void *src1, void *src2, size_t tam)
{
    void *aux=malloc(tam);
    if(!aux)
    {
        return ERROR;
    }
    memcpy(aux,src1,tam);
    memcpy(src1,src2,tam);
    memcpy(src2,aux,tam);
    free(aux);

    return TODO_OK;
}

void* insertarOrdenado(void *vec,void *val,size_t tam,size_t *ce,size_t tamElem, cmp CMP)
{
    void *ini = vec;

    if(*ce == tam &&(CMP(val,(vec + (*ce - 1)*tamElem) > 0)) return NULL;

    vec = *ce == tam? vec + (*ce * tamElem) -1: vec + (*ce * tamElem);

    while(vec > ini && CMP(val,(vec-1)) < 0)
    {
        memcpy(vec,vec-tamElem,tamElem);
        vec -= tamElem;
    }

    memcpy(vec,val,tamElem);
    (*ce)++;

    return ini;
}
