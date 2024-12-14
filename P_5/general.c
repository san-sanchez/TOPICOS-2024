#include <stdio.h>
#include <string.h>
#include "general.h"

int mostrarMovimientoALU(void* v)
{
    tMovimiento *aux=(tMovimiento*)v;
    printf("%s|%d\n",aux->CodProducto,aux->cantidad);
    return aux->cantidad;
}
int cmpMovimientoALU(const void* a, const void* b)
{
    tMovimiento *aux1=(tMovimiento*)a;
    tMovimiento *aux2=(tMovimiento*)b;
    return strcmp(aux1->CodProducto,aux2->CodProducto);
}
int agruparMovimientoALU(void*dest, const void* origen)
{
    tMovimiento *aux1=(tMovimiento*)origen;
    tMovimiento *aux2=(tMovimiento*)dest;

    int rta=aux2->cantidad+=aux1->cantidad;
    return rta;
}
