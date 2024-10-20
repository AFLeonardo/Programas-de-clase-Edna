#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Solicitar 5 nombres y guardalos en arreglo de punteros
// ALFONSO RUIZ GRUPO 33

int main()
{
    char *Lista_nombrePtr[5];
    int i;
    char nombre[40];

    for(i=0; i<5; i++)
    {
        printf("Ingrese nombre %d: ", i+1);
        fflush(stdin);
        gets(nombre);

        Lista_nombrePtr[i] = (char *)malloc(strlen(nombre) + 1);
        strcpy(Lista_nombrePtr[i], nombre);
    }

    printf("%20s", "\n--------------------------------------\n");
    printf("%10s %20s\n", "Nombres", "Direccion en memoria");
    for(i=0; i<5; i++)
         printf("%10s %-20p\n", Lista_nombrePtr[i], Lista_nombrePtr[i]);
    return 0;
}
