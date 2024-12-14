#include <stdio.h>
#include <stdlib.h>
//#include "minunit.h"
#include "examen.h"

int main()
{
    char s1[TAM]="hola";
    const char s2[]="mundo";
    char *prueba;
    int mat[][MAX_COL]={{1,2,3,4,1},
                        {4,5,6,5,1},
                        {7,4,9,6,1},
                        {7,4,9,6,1},
                        {7,4,9,6,1}};
    int suma,ce=4;
   /*-----CASOS DE PRUEBA----
    int vec[]={1,3,5,6};
    int ikey=6;
    int*resultado;
     resultado=mbsearch(&ikey,vec,ce,sizeof(int),comparaentero);
     if(resultado){
    printf("\nEL ELEMENTO ES: %d",*resultado);
    }
    else
    printf("\nNo se encontro el elemento");*/

    /*talu alumnos[]={{1,"MARY"},{2,"jose"},{3,"leo"},{5,"sebas"}};
    talu tkey={1,"MARY"};
    talu*resultado;

    resultado=mbsearch(&tkey,alumnos,ce,sizeof(talu),comparastruct);
        if(resultado){
        printf("\nEL ELEMENTO ES: %d %s",resultado->id,resultado->nombre);
        }
        else
        printf("\nNo se encontro el elemento");*/

    float fvec[]={1.1,2.1,4.5,13.4};
    float fkey=1.1;
    float *resultado;

    resultado=mbsearch(&fkey,fvec,ce,sizeof(float),comparafloat);
        if(resultado){
        printf("\nEL ELEMENTO ES: %.1f",*resultado);
        }
        else
        printf("\nNo se encontro el elemento");


    suma=sumTrianInfEntreDiag(mat,COL);
    printf("\nEJERCICIO 2\n SUMA: %d",suma);

    prueba=mstrcat(s1,s2);
    printf("\nEJERCICIO 1\n s1:%s  y s2:%s",prueba,s2);
    return 0;
}

    //Realice aqui todas las pruebas que considere para asegurar que las funciones
    //operan correctamente en todos los casos. Cualquier codigo adicional que necesite
    //declare e implemente en examen.h/examen.c


