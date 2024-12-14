#include <stdio.h>

#include "examen.h"

//Implemente su propia version de strcat
//La descripcion de la funcion esta disponible en pdf ANSI C
char* mstrcat(char*s1, const char *s2){
 char *pv = s1;
    int fin = mstrlen(s1);
    pv += fin;  // Posicionamos pv al final de s1

    while (*s2) {
        *pv = *s2;
        pv++;
        s2++;
    }
    *pv = '\0';  // Agregamos el carácter nulo al final

    return s1;
}

int mstrlen(char*s1){
    int cant=0;
    while(*s1){
        cant++;
        s1++;
    }
return cant;
}
char *mstrcpy(char*s1,const char*s2){
    while(*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1=*s2;
    return s1;
}
//Suma los elementos del triangulo que queda debajo de las diagonales
//(sin incluirlas) de una matriz de enteros
//arg 1: matriz a sumar
//arg 2: cantidad de filas o columnas (La matriz es cuadrada)
int sumTrianInfEntreDiag(int mat[][MAX_COL], int fc){
    int c,medio=fc/2,sum=0,i,j;
    if(fc%2){
       c=medio;
    }
    else
        c=medio-1;

    for(i=(medio+1);i<=(fc-1);i++){
        for(j=c;j<i;j++){
            sum=sum+mat[i][j];
        }
        c--;
    }
    return sum;
}

//Implemente su propia version de bsearch
//La descripcion de la funcion esta disponible en pdf ANSI C
void *mbsearch(const void *k, const void* vec, size_t ce, size_t tam, int cmp(const void *, const void *)){
    int posactual,ini=0,fin=ce-1,r;
    char *poselem=(char*)vec;



        while(ini<=fin){
            posactual=(ini+fin)/2;
            poselem=(char*)vec+(posactual*tam);
            r=cmp(k,poselem);
            if(r==0){
                return poselem;
            }
            if(r<0){
                fin=posactual-1;
            }
            if(r>0){
                ini=posactual+1;
            }
        }

    return NULL;
}

int comparaentero(const void*a,const void*b){
    int r=((*(int*)a)-(*(int*)b));
    return r;

}
int comparafloat(const void*a,const void*b){
    float dif=((*(float*)a)-(*(float*)b));
    if(dif==0){
        return 0;
    }
    if(dif<0){
        return -1;
    }
    else{
        return 1;
    }
}
int comparastruct(const void*a,const void*b){
    talu* aa=(talu*)a;
    talu *bb=(talu*)b;
    int r=(aa->id)-(bb->id);
    if(r){
        return r;
    }
    else{
       return mstrcmp(aa->nombre,bb->nombre);
    }
}

int mstrcmp(char*cad,char*c2){

    while(*cad&&*c2){
        if(*cad==*c2){
            cad++;
            c2++;
        }
        else{
            return 1;
        }
    }
    return 0;
}

