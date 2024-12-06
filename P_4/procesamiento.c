#include "Archivos_sensor.h"

int cargarSensor(t_sensor*vec, const char*nombreArchivo)
{
    FILE *txt=fopen(nombreArchivo,"rt");
    if(!txt)
    {
        return FATAL_ERROR;
    }
    char *linea=malloc(BUFFER*sizeof(char));
    if(!linea)
    {
        fclose(txt);
        return FATAL_ERROR;
    }

    while(fgets(linea,BUFFER,txt))
    {
        desglosarlinea(vec,linea);
        vec++;
    }

    fclose(txt);
    free(linea);
    return TODO_OK;
}

void desglosarlinea(t_sensor *vec, char *cad)
{
    cad=mystrrchr(cad,'\n');
    *cad='\0';

    cad-=TAM_ESTADO;
    cad++;
    strcpy(vec->estado,cad);
    cad--;
    *cad='\0';

    cad-=TAM_TEMPERATURA;
    sscanf(cad,"%f",&vec->temperatura);
    *cad='\0';

    cad-=TAM_SENSOR;
    cad++;
    strcpy(vec->cod,cad);

}

char *mystrrchr(const char *cad, int c)
{
    cad = cad + mystrlen(cad) + 1;
    while(*cad != (char)c)
    {
        cad--;
    }
    return *cad == (char)c ? (char*)cad : NULL;
}
size_t mystrlen(const char *cad)
{
    size_t total=0;
    while(*cad)
    {
        cad++;
        total++;
    }
    return total;
}
char *mystrcpy(char *cad,const char *src)
{
    char *inicio=cad;

    while(*src)
    {
        *cad=*src;
        cad++;
        src--;
    }

    *cad='\0';

    return inicio;
}

void *Insercion(void *vec, void *dato, size_t tam, size_t tope, size_t *ce, cmp comparar)
{
    if(*ce==tope && comparar((char*)dato,(char*)vec+ (*ce-1)*tam)>0)return NULL;

    char *inicio=(char*)vec;
    vec=*ce==tope?(char*)vec+(*ce-1)*tam:(char*)vec + *ce*tam;

    while((char*)vec>inicio &&comparar(dato,(char*)vec-tam)<0)
    {
        memcpy((char*)vec,(char*)vec-tam,tam);
        vec-=tam;
    }

    memcpy((char*)vec,(char *)dato,tam);
    (*ce)++;

    return inicio;
}
void seleccion(void *src, size_t tam, size_t ce, cmp comparar)
{
    char *menor;
    char *vec=(char *)src;
    size_t i;

    for(i=0;i<ce;i++)
    {
        menor=(char*)buscarMenor(vec,ce-i,tam,comparar);
        if(menor!=vec)
        {
            intercambiar(vec,menor,tam);
        }
        vec+=tam;
    }
}
void *buscarMenor(void *vec, size_t ce, size_t tam, cmp comparar)
{
    char * menor=(char*)vec;
    vec+=tam;
    size_t i;
    for(i=0;i<ce-1;i++)
    {
        if(comparar(menor,(char*)vec)>0)
        {
            menor=(char*)vec;
        }
        vec+=tam;
    }
    return menor;
}
int intercambiar(void *src1, void*src2, size_t tam)
{
    char *aux=malloc(tam);
    if(!aux)
    {
        return FATAL_ERROR;
    }
    memcpy(aux,src1,tam);
    memcpy(src1,src2,tam);
    memcpy(src2,aux,tam);
    free(aux);
    return TODO_OK;
}
int cmpCod(const void *a, const void *b)
{
    t_sensor *A=(t_sensor*)a;
    t_sensor *B=(t_sensor*)b;

    return strcmp(A->cod,B->cod);
}
void cargarPromSensores(t_sensor *vec,t_dato *src,size_t ce)
{
    strcpy(src->cod,vec->cod);
    src->temperatura=0;
    src->cantidad=0;

    while(ce>0)
    {
        if(strcmp(src->cod,vec->cod) == 0 && strcmp(vec->estado,"      READY") == 0)
        {
            src->temperatura+=vec->temperatura;
            src->cantidad++;
        }
        vec++;
        if(strcmp(src->cod,vec->cod) !=0 )
        {
            src++;
            strcpy(src->cod,vec->cod);
            src->temperatura=0;
            src->cantidad=0;
        }

        ce--;
    }

}
