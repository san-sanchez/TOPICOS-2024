#include  "My_matriz.h"

int main()
{
    printf("Hello world!\n");
////////////////////////////////////////////////////////////////////////////////////////////
   int Mat[2][2]={{11,12},
                   {21,22}}; //[FILA][COLUMNA]

    int MAT_1[TAM_COL][TAM_COL]={
                                    {11,12,13},
                                    {21,22,23},
                                    {31,32,33}
                                };//Matriz prueba cuadrada impar
    int MAT_2[TAM_COL][TAM_COL]={
                                    {11,12,13,14},
                                    {21,22,23,24},
                                    {31,32,33,34},
                                    {41,42,43,44}
                                };//Matriz prueba cuadrada par

    int MAT_3[TAM_COL][TAM_COL]={
                                    {11,12,13,14,15},
                                    {21,22,23,24,25},
                                    {31,32,33,34,35},
                                    {41,42,43,44,45},
                                    {51,52,53,54,55}
                                };//Matriz prueba cuadrada impar
////////////////////////////////////////////////////////////////////////////////////////////

    int Mat_Identidad[TAM_COL][TAM_COL]={{1,0},
                                         {0,1}
                                        };
    int Mat_Identidad_1[TAM_COL][TAM_COL]={{1,0,0},
                                           {0,1,0},
                                           {0,0,1}
                                          };
    int Mat_Identidad_2[TAM_COL][TAM_COL]={{1,0,0,0,0},
                                           {0,1,0,0,0},
                                           {0,0,1,0,0},
                                           {0,0,0,1,0},
                                           {0,0,0,0,1}
                                          };
    int Mat_Identidad_Error[TAM_COL][TAM_COL]={ {1,0,0,0,1},
                                                {0,1,0,0,0},
                                                {0,0,1,0,1},
                                                {0,0,0,1,0},
                                                {0,1,0,0,1}
                                              };

////////////////////////////////////////////////////////////////////////////////////////////


    int Mat_4[TAM_COL][TAM_COL]={
                                    {11,12,13},
                                    {21,22,23},
                                    {31,32,33},
                                    {41,42,43}
                                };
    int Mat_5[TAM_COL][TAM_COL]={
                                    {11,12,13},
                                    {21,22,23}
                                };
   int Mat_6[TAM_COL][TAM_COL]={
                                    {11,12,13,14},
                                    {21,22,23,24},
                                    {31,32,33,34}
                                };
   int Mat_7[TAM_COL][TAM_COL]={
                                    {11,12,13,14,15},
                                    {21,22,23,24,25}
                                };
    int Mat_8[TAM_COL][TAM_COL]={
                                    {11,12},
                                    {21,22},
                                    {31,32},
                                    {41,42},
                                    {51,52}
                                };
////////////////////////////////////////////////////////////////////////////////////////////

    Mostrar__Matriz(MAT_3,5,5);
    printf("\n");
    Mostrar__Matriz(Mat_8,7,2);
    printf("\n");
    Mostrar_Diagonal_Principal(MAT_2,4);
    printf("\n");
    Mostrar_Diagonal_Secundaria(MAT_2,4);
    printf("\n");
    Mostrar_Diagonal_Inferior(MAT_3,5);
    printf("\n");
    Mostrar_Diagonal_Superior(MAT_3,5);
////////////////////////////////////////////////////////////////////////////////////////////

    int **Mat__Dinamica=(int**)Generar_Matriz(sizeof(int),5,5);
    Cargar__Matriz(Mat__Dinamica,5,5);
    Mostrar__Matriz(Mat__Dinamica,5,5);
////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n");
    int **MAT_RTA=Multiplicar_Matriz(Mat_7,2,5,Mat_8,5,2);
    Mostrar__Matriz(MAT_RTA,2,2);
////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n");
    printf("%d",Es_Identidad(Mat_Identidad_1,3,3));
    printf("\n");
    printf("%d",Es_Identidad(Mat_Identidad_Error,5,5));
////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n");
    Mostrar__Matriz(MAT_3,5,5);
    printf("\n");
    Matriz_Traspuesta(MAT_3,5,5);
    Mostrar__Matriz(MAT_3,5,5);


    return 0;
}
