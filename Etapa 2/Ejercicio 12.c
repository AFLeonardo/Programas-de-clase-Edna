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
void Mostrar_xcategoria(FILE *, char *);
void Inventario(FILE *archivo, int *clave, int *inventario_n);

int main()
{
    char Categoria;
    FILE *archivo;
    int opcion, clave, nuevo_inventario;

    system("cls");
    do
    {
        printf("--- Menu ---\n"
        "1. Leer datos y guardarlos\n"
        "2. Mostrar pelicula por categoria indicada\n"
        "3. Actualizar inventario\n"
        "4. Salir\n"
        "Opcion: ");
        scanf("%d", &opcion);

        if(opcion > 4 || opcion < 1)
            printf("Opcion no valida. Intenta de muevo.\n");
    } while (opcion > 4 || opcion < 1);
    
    while (opcion != 4)
    {
        switch(opcion)
            {
                case 1:
                    if ((archivo = fopen("peliculas.dat", "a")) == NULL)
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

                        if ((Categoria <= 'A' && Categoria >= 'D') || (Categoria <= 'a' && Categoria >= 'd'))
                        {
                            printf("\nSolo estan permitidas las categorias mencionandas.");
                            system("pause");
                        }
                    }
                    while((Categoria <= 'A' && Categoria >= 'D') || (Categoria <= 'a' && Categoria >= 'd'));
                    
                    if ((archivo = fopen("peliculas.dat", "r")) == NULL)
                        printf("Error al abrir el archivo.\n");
                    else
                    {
                        Mostrar_xcategoria(archivo, &Categoria);
                        fclose(archivo);
                    }
                    
                    break;

                case 3:

                    if ((archivo = fopen("peliculas.dat", "r+")) == NULL)
                        printf("Error al abrir el archivo");
                    else
                    {
                        do
                        {
                            printf("Ingresa la clave de la pelicula a actualizar su inventario: ");
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

                        Inventario(archivo, &clave, &nuevo_inventario);
                        system("pause");
                    }
                    break;

                case 4:
                    printf("Adios");
                    break;
            }
        }
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
            
    }
    
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
    
    do
    {
        printf("Inventario: ");
        scanf("%d", &pelicula.inventario);

        if(pelicula.inventario < 0)
            printf("Como valor minimo se acepta 1.\n");
    } while (pelicula.inventario < 0);

    fwrite(&pelicula, sizeof(struct Peliculas), 1 ,archivo);
}

void Mostrar_xcategoria(FILE *archivo, char *Categoria)
{
    struct Peliculas pelicula;
    bool peliculasEncontrada = false; 
    
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
            peliculasEncontrada = true;
        }
    }
    fclose(archivo);

    if (!peliculasEncontrada) 
        printf("\nNo se encontraron peliculas en la categoria %c.\n", *Categoria);
    system("pause");
}

void Inventario(FILE *archivo, int *clave, int *inventario_n)
{
    // Hay que modificarlo para que funcione con el fseek
    struct Peliculas Pelicula_Modificada;
    bool encontrado = false;

    while ((fread(&Pelicula_Modificada, sizeof(struct Peliculas), 1, archivo)) && !encontrado)
    {
        if (Pelicula_Modificada.clave == *clave)
        {
            Pelicula_Modificada.inventario = *inventario_n;
            fseek(archivo, -sizeof(struct Peliculas), SEEK_CUR);
            fwrite(&Pelicula_Modificada, sizeof(struct Peliculas), 1, archivo);
            printf("Inventario actualizado exitosamente.\n");
            encontrado = true;
        }
    }

    if(!encontrado)
        printf("Pelicula con clave %d no encontrada.\n", *clave);

    fclose(archivo);
}