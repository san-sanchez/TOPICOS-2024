#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "examen.h"


void* _ordenarSeleccion(void* vec, int ce, unsigned tam, int cmp(const void*, const void*)){
    void *elemento1, *elemento2;
    void* elementoAux = malloc(tam);
    int  comparacion;
    for(int j = 0; j< ce-1; j++){

        for(int i = 0; i < ce-1; i++){
            memset(elementoAux, 0, tam);
            elemento1 = (char*)vec + (i*tam);
            elemento2 = (char*)vec + ((i+1)*tam);


            comparacion = cmp(elemento1, elemento2);

            if(comparacion > 0){
                memcpy(elementoAux, elemento1, tam);
                memcpy(elemento1, elemento2, tam);
                memcpy(elemento2, elementoAux, tam);
            }
        }
    }
    free(elementoAux);
    return NULL;
}

int _cmpEmpleadoNombre(const void* a, const void* b){
    tEmpleado* empleado1 = (tEmpleado*)a;
    tEmpleado* empleado2 = (tEmpleado*)b;

    void* nombre1 = (void*)empleado1->nomYAp;
    void* nombre2 = (void*)empleado2->nomYAp;


    return _cmp_enteros(nombre1, nombre2);

}

int _cmp_enteros(const void* a, const void* b){
    int* nro1 = (int*)a;
    int* nro2 = (int*)b;

    return *nro1 - *nro2;
}

int _cmp_str(const void* a, const void* b){
    char* str1 = (char*)a;
    char* str2 = (char*)b;
    int comp = 0;

    while(*str1 != '\0'){
        comp += (int)(*str1);
        str1++;
    }
    while(*str2 != '\0'){
        comp -= (int)(*str2);
        str2++;
    }

    return comp;
}

char* _mstrstr(const char *s1, const char *s2){
    return NULL;
}

int _contarCelulasVivasEnVecindario(int mat[][MAX_COL], int filas, int columnas, int fila, int columna){
    int sumador = 0;

    if((fila - 1) >= 0){
        sumador += mat[fila-1][columna];
        if(columna -1 >= 0){
            sumador += mat[fila-1][columna-1];
        }
        if(columna+1 < columnas){
            sumador += mat[fila-1][columna+1];
        }
    }
    if(fila +1 < filas){
        sumador+= mat[fila+1][columna];
        if(columna -1 >= 0){
            sumador += mat[fila+1][columna-1];
            }
        if(columna+1 < columnas){
            sumador += mat[fila+1][columna+1];
            }
        }
    if(columna -1 >= 0){
        sumador += mat[fila][columna-1];
    }
    if(columna+1 < columnas){
        sumador += mat[fila][columna+1];
    }


    return sumador;
}
