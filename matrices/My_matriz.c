#include  "My_matriz.h"
void Cargar__Matriz(int mat[][TAM_COL],int F,int C)
{
    int i,j;
    for(i=0;i<F;i++)
    {
        for(j=0;j<C;j++)
        {
        mat[i][j]=i+j;
        }
    }
}
void Mostrar__Matriz(int mat[][TAM_COL],int F,int C)
{
    int i,j;
    for(i=0;i<F;i++)
    {
        for(j=0;j<C;j++)
        {
            printf("%d|",mat[i][j]);
        }
        printf("\n");
    }
}
void Mostrar_Diagonal_Principal(int Mat[][TAM_COL],size_t FC )
{
    size_t I;
    for(I=0;I<FC;I++)
    {
        printf("%d \n",Mat[I][I]);
    }
}
void Mostrar_Diagonal_Secundaria(int Mat[][TAM_COL],size_t FC )
{
    size_t I;

    for(I=0;I<FC;I++)
    {
        printf("%d\n",Mat[I][(FC-I-1)]);
    }
}


void Mostrar_Diagonal_Inferior(int Mat[][TAM_COL],size_t FC)
{
    size_t i,j;
    for(i=0;i<FC;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%d|",Mat[i][j]);
        }
        printf("\n");
    }
}
void Mostrar_Diagonal_Superior(int Mat[][TAM_COL],size_t FC)
{
    size_t i,j;
    for(i=0;i<FC;i++)
    {
        for(j=i+1; j>i && j<FC;j++)
        {
            printf("%d|",Mat[i][j]);
        }
        printf("\n");
    }
}


void **Generar_Matriz(size_t Tam_Element,size_t Colum,size_t File)//evaluar
{
    void*init=malloc(File*sizeof(void*));
    if(!init)
    {
        return NULL;
    }
    for(void**col=init;*col<(init+File*Tam_Element);col++)
    {
        *col=malloc(Tam_Element*Colum);
        if(!*col)
        {
            for(void **k=init;k<col;k++)
            {
                free(*col);
            }
            free(init);
            return NULL;
        }
    }
 return init;
}


int **Multiplicar_Matriz( int Mat_1[][TAM_COL],size_t F1,size_t C1, int Mat_2[][TAM_COL],size_t F2,size_t C2)
{
    if(C1!=F2)
    {
        return NULL;
    }
    int **mat=(int**)Generar_Matriz(sizeof(int),F1,C2);

    size_t F,C,K;
    for(F=0;F<F1;F++)
    {
        for(C=0;C<C2;C++)
        {
            mat[F][C]=0;
            for(K=0;K<C1;K++)
            {
                mat[F][C]+=Mat_1[F][K]* Mat_2[K][C];
            }
        }
    }
    return mat;
}
void Matriz_Traspuesta(int Mat[][TAM_COL],size_t F, size_t C)// Rehacer
{
    size_t File,Colum;
    int aux;

    if(F==C)
    {
        for(File=0;File<F;File++)
        {
            for(Colum=File+1;Colum<C;Colum++)
            {
                aux=Mat[File][Colum];
                Mat[File][Colum]=Mat[Colum][File];
                Mat[Colum][File]=aux;
            }
        }
    }

}
int Es_Identidad(int Mat[][TAM_COL],size_t FIL,size_t COL)//rehacer
{
    size_t File,Colum;
    for(File=0;File < FIL;File++)
    {
        if(Mat[File][File]!=1)
        {
            return 0;
        }
        for(Colum=0; Colum<COL ;Colum++)
        {
            if((File!=Colum && Mat[File][Colum]!=0))
                return 0;
        }
    }
    return 1;
}

