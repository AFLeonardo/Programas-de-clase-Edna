#include <stdio.h>
#include <stdbool.h>

struct Planeta
{
    int clave;
    char nombre[50];
    int dimension;
    char caracteristicas[100];
    bool vida;
};


int main()
{
    FILE *archivo;
    int i;
    struct Planeta Registro = {0, "", 0, "", false};

    if ((archivo = fopen("Planetas.txt", "w")) == NULL)
            printf("Error al abrir el archivo");
        else
        {
            for (i=0 ;  i<=200 ; i++)
                fwrite(&Registro, sizeof(struct Planeta), 1, archivo);
            fclose(archivo);
        }

    return 0;
}