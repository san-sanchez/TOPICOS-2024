///A Implementar por el alumno
#include "TDASimpleVec.h"


TDASimVec* crearTDASimVecALU(unsigned tamEle)
{
    TDASimVec *lista=malloc(sizeof(TDASimVec));
    if(!lista) return NULL;

    lista->ce=0;
    lista->tamEle=tamEle;
    lista->maxEle=MIN_ELE;

    lista->vec=malloc(lista->tamEle*lista->maxEle);
    if(!lista->vec)
    {
        free(lista);
        return NULL;
    }
    return lista;
}
TDASimVec* ordenarALU(TDASimVec* sv, int cmp(const void*a, const void* b))
{
    void *menor;
    size_t i;
    void *src=sv->vec;
    for(i=0;i<sv->ce;i++)
    {
        menor=buscarMenor(src,sv->ce-i,sv->tamEle,cmp);
        if(menor != src)
        {
            intercambio(src,menor,sv->tamEle);
        }
        src+=sv->tamEle;
    }

    return sv;
};
void *buscarMenor(void *vec, size_t ce, size_t tam,int cmp(const void*a, const void* b))
{
    char *menor=(char*)vec;
    char *src=(char*)vec + tam;
    size_t i;
    for(i=0;i < ce-1;i++)
    {
        if(cmp(menor,src)>0)
        {
            menor=src;
        }
        src+=tam;
    }
    return (void*)menor;
}
int intercambio(void *s1, void *s2, size_t tam)
{
    char *aux=malloc(tam*sizeof(char));
    if(!aux)
    {
        return 0;
    }
    memcpy(aux,(char*)s1,tam);
    memcpy((char*)s1,(char*)s2,tam);
    memcpy((char*)s2,aux,tam);
    free(aux);
    return 1;
}
TDASimVec* agruparALU(TDASimVec* sv, int cmp(const void*, const void*), int fagrup(void*dest, const void* origen))
{
     size_t i;
     size_t ceInterna = 0;

     char *pl = (char*)sv->vec ;
     char *pe = (char*)sv->vec;

    for(i=0;i < sv->ce;i++)
     {
         if(cmp(pl,pe) == 0)
         {
             if(pe != pl)
             {
                fagrup(pe,pl);
             }
         }

         pl+=sv->tamEle;

         if(cmp(pl,pe)!= 0)
         {
             memcpy(sv->vec + sv->tamEle*ceInterna,pe,sv->tamEle);
             pe=pl;
             ceInterna++;
         }

     }

     sv->ce = ceInterna;

    return sv;
}
int insertarAlFinalALU(TDASimVec* sv, void* ele)
{
    if(sv->ce == sv->maxEle)
    {
        void *newVec=malloc(sv->tamEle*(sv->ce + 3));
        if(!newVec)
        {
            return 0;
        }
        sv->maxEle+=3;

        memcpy(newVec,sv->vec,sv->tamEle*sv->ce);
        free(sv->vec),
        sv->vec=newVec;
    }
    memcpy(sv->vec+(sv->ce*sv->tamEle),ele,sv->tamEle);
    sv->ce+=1;
    return 1;
}
void destruirALU(TDASimVec* sv)
{
    free(sv->vec);
    free(sv);
};

