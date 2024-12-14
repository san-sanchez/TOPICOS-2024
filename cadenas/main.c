#include "my__string.h"
#include <string.h>
#include <windows.h>

int main()
{
    ////////////////////////////////////////---STRLEN---/////////////////////////////////////////////
    char cad_prueba[100]="hola a todo el mundo\n";

    if(strlen(cad_prueba)==my_strlen(cad_prueba))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        printf("Funcion STRLEN creada de manera correcta \n");
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        printf("Fatal Error \n");
    }

////////////////////////////////////////---STRCPY---/////////////////////////////////////////////
    char s1[27] = "";
    char s2[7] = "amigos"; //nota: si entrego una cadena desbordada tendre errores en acceso a memoria
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    printf("//////////---STRCPY---//////////\n");
    printf("%s\n",strcpy(s1,s2));

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    printf("%s\n",my_strcpy(s1,s2));

    ////////////////////////////////////////---STRCMP---/////////////////////////////////////////////
    char cad_prueba_1[100]="hola a todo el mundo";
    char cad_prueba_2[100]="hola a todo el mundo";

    if(strcmp(cad_prueba_1,cad_prueba_2)==my_strcmp(cad_prueba_1,cad_prueba_2))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        printf("Funcion STRCMP creada de manera correcta \n");
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        printf("Fatal Error \n");
    }

    ////////////////////////////////////////---STRCHR---/////////////////////////////////////////////
    if(strchr(cad_prueba,97)==my_strchr(cad_prueba,97))// como devuelve valores invalidos?
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        printf("Funcion STRCHR creada de manera correcta \n");
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        printf("Fatal Error \n");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    ////////////////////////////////////////---STRRCHR---/////////////////////////////////////////////
    if(strrchr(cad_prueba,97)==my_strrchr(cad_prueba,97))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        printf("Funcion STRRCHR creada de manera correcta \n");
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        printf("Fatal Error \n");
    }
    ////////////////////////////////////////---STRSTR---/////////////////////////////////////////////
    if(strstr(cad_prueba,"mundo")==my_strstr(cad_prueba,"mundo"))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        printf("Funcion STRSTR creada de manera correcta \n");
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        printf("Fatal Error \n");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    return 0;
}
