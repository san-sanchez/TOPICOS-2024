#include "Firma.h"
int main()
{
    printf("Hello world!\n");

    int vecInt[]={5,2,3,10,9,1,4,7,8};
    float vecFloat[]={5.5,5.5,9.3,8,11.57,1.1};


    Seleccion(vecInt,sizeof(int),sizeof(vecInt)/sizeof(vecInt[0]),cmpInt);
    mostrargenerico(vecInt,sizeof(int),sizeof(vecInt)/sizeof(vecInt[0]),mostrarInt);
    printf("\n------------------------------------------------------------------\n");
    Seleccion(vecFloat,sizeof(float),sizeof(vecFloat)/sizeof(vecFloat[0]),cmpFloat);
    mostrargenerico(vecFloat,sizeof(float),sizeof(vecFloat)/sizeof(vecFloat[0]),mostrarFloat);
    printf("\n------------------------------------------------------------------\n");

    size_t capacidad = 10;
    size_t contador = 0;
    int *arreglo = malloc(capacidad * sizeof(int));

    // Vector de valores a insertar
    int valores[] = {5, 3, 8, 1, 6};
    size_t num_valores = sizeof(valores) / sizeof(valores[0]);

    // Pruebas de inserción usando un bucle for
    for (size_t i = 0; i < num_valores; i++) {
        insercion(arreglo, &valores[i], &contador, capacidad, sizeof(int), cmpInt);
    }

        mostrargenerico(arreglo,sizeof(int),contador,mostrarInt);
    return 0;
}
