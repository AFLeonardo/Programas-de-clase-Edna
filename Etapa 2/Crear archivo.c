#include <stdio.h>
// Este codigo es para crear un archivo vacio donde se escriben 50 registros vacios.
struct Peliculas
{
    int clave;
    char descripcion[50];
    char categoria;
    int inventario;
};

int main()
{
    FILE *archivo;
    int i;
    struct Peliculas PeliculaVacio = {0, "", '\0', 0};

    if ((archivo = fopen("peliculas.dat", "wb")) == NULL)
            printf("Error al abrir el archivo");
        else
        {
            for (i=0 ;  i<=50 ; i++)
                fwrite(&PeliculaVacio, sizeof(struct Peliculas), 1, archivo);
            fclose(archivo);
        }

    return 0;
}