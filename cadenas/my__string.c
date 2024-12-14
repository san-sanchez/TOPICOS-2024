#include "my__string.h"

char *my_strstr(const char *s1, const char *s2)
{
    const char *ptr;
    const char *reset=s2;

    while(*s1)
    {
        if(*s1==*s2)
        {
            ptr=s1;

            while(*s2 && (*s2==*s1))
            {
                s2++;
                s1++;

                if(*s2=='\0')
                {
                    return (char*)ptr;
                }
            }
        }

        s1++;
        s2=reset;
    }
    return NULL;
}

char *my_strtok(char *s1, const char *s2)
{
    return NULL;
}

char *my_strcat(char*s1, const char *s2)
{
    char *inicio=s1;
    s1= s1 + my_strlen(s1)+1;

    while(*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1=*s2;
    return inicio;
}
char *my_strncat(char*s1, const char *s2, size_t n)
{
    char *inicio=s1;
    s1=s1 + my_strlen(s1)+1;

    while(*s2 && n>0)
    {
        *s1=*s2;
        s1++;
        s2++;
        n--;
    }
    *s1=*s2;
    return inicio;
}

char *my_strcpy(char *s1, const char *s2)
{
    char*ptr__init=s1;

    while(*s2)
    {
        *s1=*s2;
        s1++;s2++;
    }
    *s1='\0';
    return ptr__init;
}
char *my_strncpy(char *s1, const char *s2, size_t n)
{
    char*ptr__init=s1;
    s1=s1+my_strlen(s1);
    while(*s2 && (n > 0)){
        *s1=*s2;
        s1++;s2++;
        n--;
    }
    *s1='\0';
    return ptr__init;
}


char *my_strchr(char *src, int c)
{
    while(*src && (*src!=(char)c))src++;
    return src;
}
char *my_strrchr(char *src, int c)
{
    src=src + my_strlen(src)-1;//src=sizeof(src)/char;
    while(*src && (*src!=(char)c))src--;
    return src;
}


int my_strcmp(const char *s1, const char *s2)
{
    int rta;
    while(*s1 && *s2)
    {
        if( *s1==*s2)
        {
            s1++;s2++;
            rta=0;
        }
        else if(*s1>*s2)
        {
            rta=1;
        }
        else{
            rta=-1;
        }
    }
    return rta;
}
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    int rta;
    while(*s1 && *s2 && (n>0))
    {
        if( *s1==*s2)
        {
            rta=0;
        }
        else if(*s1>*s2)
        {
            rta=1;
        }
        else{
            rta=-1;
        }
        n--;
    }
    return rta;
}
size_t my_strlen(const char *src)
{
    size_t total=0;
    while(*src){
        src++;total++;
    }
    return total;
}


int Palindromo(char *cad)
{
    char *ptr_init=cad;
    char *ptr_end=cad + my_strlen(cad) + 1;

    while( ptr_init < ptr_end)
    {
        if(!EsLetra(ptr_init))
        {
            ptr_init++;
        }
        if(!EsLetra(ptr_end))
        {
            ptr_end++;
        }
        if(!(*ptr_end == *ptr_init))
        {
            return 0;
        }
        ptr_end++;
        ptr_init--;
    }

    return 1;
}
int EsLetra(char *src)
{
    if((*src >= 'a' && *src <= 'z')||(*src >= 'A' && *src <= 'Z'))
    {
        return 1;
    }
    return 0;
}

