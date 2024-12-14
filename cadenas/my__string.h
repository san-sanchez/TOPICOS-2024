#ifndef MY__STRING_H_INCLUDED
#define MY__STRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// FIRMA DE FUNCIONES DE LA LIB <STRING.H>

char *my_strstr(const char *s1, const char *s2);
char *my_strtok(char *s1, const char *s2);
char *my_strcat(char*s1, const char *s2);
char *my_strcpy(char *s1, const char *s2);
char *my_strncpy(char *s1, const char *s2, size_t n);
char *my_strncat(char*s1, const char *s2, size_t n);
char *my_strchr(char *s, int c);
char *my_strrchr(char *s, int c);
char *my_strpbrk(const char *s1, const char *s2);
char *my_strerror(int errnum);

int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
int my_strcoll(const char *s1, const char *s2);

size_t my_strxfrm(char *s1, const char *s2, size_t n);
size_t my_strcspn(const char *s1, const char *s2);
size_t my_strspn(const char *s1, const char *s2);
size_t my_strlen(const char *src);

//MIS FUNCIONES AUXILIARES
int EsLetra(char *src);
int Palindromo(char *cad);
char *ProximaPalabra(const char *src, char **ptr_init,char ** _ptr_end);
// FUNCIONES DE USO DE MEMORIA GENERICAS

void *my_memchr(const void *s, int c, size_t n);
void *my_memset(void *s, int c, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);
void *my_memcpy(void *s1, const void *s2, size_t n);
void *my_memmove(void *s1, const void *s2, size_t n);

#endif // MY__STRING_H_INCLUDED
