#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Peliculas
{
    int clave;
    char descripcion[50];
    char categoria;
    int inventario;
};

void Leer_guardar_datos(FILE *);
void Mostrar_xcategoria(char *);
void Inventario(FILE *archivo, int *clave, int *inventario_n);

int main()
{
    char resp, Categoria;
    FILE *archivo;
    int opcion, i, clave, nuevo_inventario;

    printf("Quieres agregar datos(S/N): ");
    scanf("%c", &resp);

    if (resp == 'S' || resp == 's')
    {
        if ((archivo = fopen("peliculas.dat", "wb")) == NULL)
            printf("Error al abrir el archivo");
        else
        {
            //Creamos datos de la estructura vacio
            struct Peliculas PeliculaVacio = {0, "", '\0', 0};
            for (i=0 ;  i<=50 ; i++)
                fwrite(&PeliculaVacio, sizeof(struct Peliculas), 1, archivo);
            fclose(archivo);
        }

        while (resp == 'S' || resp == 's')
        {
        
            do
            {
                system("cls");
                printf("--- Menu ---\n"
                "1. Leer datos y guardarlos\n"
                "2. Mostrar pelicula por categoria indicada\n"
                "3. Actualizar inventario\n"
                "4. Salir\n"
                "Opcion: ");
                scanf("%d", &opcion);

            } while (opcion > 4 || opcion < 1);
            
            switch(opcion)
            {
                case 1:
                    if ((archivo = fopen("peliculas.dat", "ab+")) == NULL)
                        printf("Error al abrir el archivo");
                    else
                    {
                        Leer_guardar_datos(archivo);
                        printf("Datos guardados correctamente.\n");
                        fclose(archivo);
                    }
                    break;

                case 2:

                    do
                    {
                        system("cls");
                        printf("SELECCIONA LA CATEGORIA A BUSCAR:\n"
                        "A: Drama\n"
                        "B: Suspenso\n"
                        "C: Misterio\n"
                        "D: Infantil\n"
                        "Categoria: ");

                        fflush(stdin);
                        scanf("%c", &Categoria);

                        if (!((Categoria >= 'A' && Categoria <= 'D') || (Categoria >= 'a' && Categoria <= 'd')))
                        {
                            printf("\nSolo estan permitidas las categorias mencionandas.");
                            system("pause");
                        }
                    }
                    while(!((Categoria >= 'A' && Categoria <= 'D') || (Categoria >= 'a' && Categoria <= 'd')));

                    Mostrar_xcategoria(&Categoria);
                    break;

                case 3:
                    if ((archivo = fopen("peliculas.dat", "rb+")) == NULL)
                        printf("Error al abrir el archivo");
                    else
                    {
                        do
                        {
                            printf("Ingresa la clave de la pelicula a actulizar su inventario: ");
                            scanf("%d", &clave);

                            if (clave < 0)
                                printf("La clave necesita ser mayor a 0.");
                            
                        } while (clave < 0);

                        do
                        {
                            printf("Ingresa la cantidad para actulizar el inventario: ");
                            scanf("%d", &nuevo_inventario);

                            if (nuevo_inventario < 0)
                                printf("El inventario necesita ser mayor a 0.");
                            
                        } while (nuevo_inventario < 0);

                        Inventario(archivo,&clave, &nuevo_inventario);
                        system("pause");
                    }
                    break;

                case 4:
                    printf("Adios");
                    resp = 'n';
                    break;
            }
        }
    }
    else
        printf("Ok...nos vemos...");
    
    return 0;
}

void Leer_guardar_datos(FILE *archivo)
{
    struct Peliculas pelicula;
    printf("Clave: ");
    scanf("%d", &pelicula.clave);
    printf("Descripcion: ");
    fflush(stdin);
    gets(pelicula.descripcion);

    do
    {
        printf("Categoria: ");
        fflush(stdin);
        scanf("%c", &pelicula.categoria);
        if (!((pelicula.categoria >= 'A' && pelicula.categoria <= 'D') || (pelicula.categoria >= 'a' && pelicula.categoria <= 'd')))
            printf("Categoria no existente.\nVALORES PERMITIDOS: A B C D.\n");
        
    } while (!((pelicula.categoria >= 'A' && pelicula.categoria <= 'D') || (pelicula.categoria >= 'a' && pelicula.categoria <= 'd')));
    
    
    printf("Inventario: ");
    scanf("%d", &pelicula.inventario);

    fwrite(&pelicula, sizeof(struct Peliculas), 1 ,archivo);
}

void Mostrar_xcategoria(char *Categoria)
{
    FILE *archivo;
    struct Peliculas pelicula;
    int peliculasEncontradas = 0; 
    
    if ((archivo = fopen("peliculas.dat", "rb")) == NULL)
        printf("Error al abrir el archivo.\n");
    
    while (fread(&pelicula, sizeof(struct Peliculas), 1, archivo)) 
    {
        if (pelicula.categoria == *Categoria || pelicula.categoria == (*Categoria) + 32) 
        {
            printf("\n----------------------------------------\n");
            printf("Clave: %d\n", pelicula.clave);
            printf("Descripcion: %s\n", pelicula.descripcion);
            printf("Categoria: %c\n", pelicula.categoria);
            printf("Inventario: %d\n", pelicula.inventario);
            printf("----------------------------------------\n");
            peliculasEncontradas++;
        }
    }
    fclose(archivo);

    if (peliculasEncontradas == 0) 
        printf("\nNo se encontraron peliculas en la categoria %c.\n", *Categoria);
    else
        printf("\nSe encontraron %d pelicula(s) en la categoria %c.\n", peliculasEncontradas, *Categoria);
    system("pause");
}

void Inventario(FILE *archivo, int *clave, int *inventario_n)
{
    struct Peliculas Pelicula_Modificada;
    bool encontrado = false;

    while ((fread(&Pelicula_Modificada, sizeof(struct Peliculas), 1, archivo)) && !encontrado)
    {
        if (Pelicula_Modificada.clave == *clave)
        {
            Pelicula_Modificada.inventario = *inventario_n;
            fseek(archivo, -sizeof(struct Peliculas), SEEK_CUR);
            fwrite(&Pelicula_Modificada, sizeof(struct Peliculas), 1, archivo);
            printf("Inventario actualizado exitasamente.\n");
            encontrado = true;
        }
    }

    if(!encontrado)
        printf("Pelicula con clave %d no encontrada.\n", *clave);

    fclose(archivo);
}