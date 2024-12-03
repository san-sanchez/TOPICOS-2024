#include "gbib.h"

int restaurarColumnaALU(const char* archOri, const char* archDes, unsigned campo){
    FILE *perm=fopen("perm.txt","rt");
    if(!perm){
        return 0;
    }
    FILE *origen=fopen(archOri,"rt");
    if(!origen){
        fclose(perm);
        return 0;
    }
    FILE *destino=fopen(archDes,"wt");
    if(!destino){
        fclose(origen);
        fclose(perm);
        return 0;
    }

    TDA_PERM *lista=crearTDA(sizeof(char)*(CARACTERESARCHPERM+2));

    while(fgets((char*)lista->vec,(CARACTERESARCHPERM+2),perm))
    {
        lista->vec+=lista->tam;
        lista->pos++;
    }
    //while(fgets)
    fclose(destino);
    fclose(origen);
    fclose(perm);
    return 1; //Modifique retorno segun corresponda;
}

TDA_PERM *crearTDA(size_t tam)
{
    void *vec=malloc(tam);
    if(!vec)
    {
        return NULL;
    }
    TDA_PERM *list=malloc(sizeof(TDA_PERM));
    if(!list)
    {
        free(vec);
        return NULL;
    }
    list->vec = vec;
    list->tam = tam;
    list->ce = MAXPERM;
    list->pos=0;

    return list;
}
int insertarTDA(TDA_PERM *list, void *elemento)
{
    if(list->pos == list->ce)
    {
        char *aux=malloc(list->tam *(list->ce + 10));
        if(!aux)
        {
            return 0;
        }
        memcpy(aux,list->vec,(list->pos*list->tam));
        free(list->vec);

        list->vec = aux;
        list->ce+=10;
    }

    memcpy(list->vec + (list->pos * list->tam),elemento,list->tam);
    list->pos++;

    return 1;
}
void *destruirTDA(TDA_PERM *list)
{
    free(list->vec);
    free(list);
}
