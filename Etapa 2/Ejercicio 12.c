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

void Leer_guardar_datos_Secuencial(FILE *);
void Mostrar_xcategoria_Secuencial(FILE *, char *);

void Leer_guardar_datos_Directo(FILE *);
void Mostrar_xcategoria_Directo(FILE *);
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
               "1. Leer datos y guardarlos (ARCHIVO SECUENCIAL)\n"
               "2. Mostrar pelicula por categoria indicada (ARCHIVO SECUENCIAL)\n"
               "3. Leer datos y guardarlos (ARCHIVO DIRECTO)\n"
               "4. Mostrar las peliculas de la categoria indicada por el usuario (ARCHIVO DIRECTO)\n"
               "5. Actualizar inventario de la pelicula (ARCHIVO DIRECTO)\n"
               "6. Salir\n"
               "Opcion: ");
        scanf("%d", &opcion);

        if (opcion > 6 || opcion < 1)
            printf("Opcion no valida. Intenta de nuevo.\n");

    } while (opcion > 6 || opcion < 1);

    while (opcion != 6)
    {
        switch (opcion)
        {
        case 1:
            if ((archivo = fopen("peliculas.dat", "a")) == NULL)
            {
                printf("Error al abrir el archivo.\n");
                system("pause");
            }  
            else
            {
                Leer_guardar_datos_Secuencial(archivo);
                printf("Datos guardados correctamente.\n");
                system("pause");
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

                if ((Categoria < 'A' || Categoria > 'D') && (Categoria < 'a' || Categoria > 'd'))
                {
                    printf("\nSolo estan permitidas las categorias mencionandas.\n");
                    system("pause");
                }
            } while ((Categoria < 'A' || Categoria > 'D') && (Categoria < 'a' || Categoria > 'd'));

            if ((archivo = fopen("peliculas.dat", "r")) == NULL)
            {
                printf("Error al abrir el archivo.\n");
                system("pause");
            }
            else
            {
                Mostrar_xcategoria_Secuencial(archivo, &Categoria);
                fclose(archivo);
            }

            break;

        case 3:

            if ((archivo = fopen("peliculas.dat", "rb+")) == NULL)
            {
                printf("Error al abrir el archivo.\n");
                system("pause");
            }  
            else
            {
                Leer_guardar_datos_Directo(archivo);
                printf("Datos guardados correctamente.\n");
                system("pause");
                fclose(archivo);
            }
            break;

        case 4:
            if ((archivo = fopen("peliculas.dat", "rb+")) == NULL)
            {
                printf("Error al abrir el archivo.\n");
                system("pause");
            }  
            else
            {
                Mostrar_xcategoria_Directo(archivo);
                system("pause");
                fclose(archivo);
            }
            break;
        
        case 5:

            if ((archivo = fopen("peliculas.dat", "rb+")) == NULL)
            {
                printf("Error al abrir el archivo");
                system("pause");
            }
            else
            {
                do
                {
                    printf("Ingresa la clave de la pelicula: ");
                    scanf("%d", &clave);

                    if (clave < 0)
                        printf("La clave necesita ser mayor a 0.");

                } while (clave < 0);

                do
                {
                    printf("Ingresa la cantidad el inventario: ");
                    scanf("%d", &nuevo_inventario);

                    if (nuevo_inventario < 0)
                        printf("El inventario necesita ser mayor a 0.\n");

                } while (nuevo_inventario < 0);

                Inventario(archivo, &clave, &nuevo_inventario);
                fclose(archivo);
                system("pause");
            }
            break;

        case 6:
            printf("Adios");
            break;
        }

        do
        {
            printf("--- Menu ---\n"
                "1. Leer datos y guardarlos (ARCHIVO SECUENCIAL)\n"
                "2. Mostrar pelicula por categoria indicada (ARCHIVO SECUENCIAL)\n"
                "3. Leer datos y guardarlos (ARCHIVO DIRECTO)\n"
                "4. Mostrar las peliculas de la categoria indicada por el usuario (ARCHIVO DIRECTO)\n"
                "5. Actualizar inventario de la pelicula (ARCHIVO DIRECTO)\n"
                "6. Salir\n"
                "Opcion: ");
            scanf("%d", &opcion);

            if (opcion > 6 || opcion < 1)
                printf("Opcion no valida. Intenta de nuevo.\n");

        } while (opcion > 6 || opcion < 1);
    }

    return 0;
}

void Leer_guardar_datos_Secuencial(FILE *archivo)
{
    struct Peliculas pelicula;

    do
    {
        printf("Clave: ");
        scanf("%d", &pelicula.clave);
        if(pelicula.clave < 0)
            printf("No se permiten claves menores a 0\n");
    } while (pelicula.clave < 0);
    
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

        if (pelicula.inventario <= 0)
            printf("Como valor minimo se acepta 1.\n");
    } while (pelicula.inventario <= 0);

    fwrite(&pelicula, sizeof(struct Peliculas), 1, archivo);
}

void Mostrar_xcategoria_Secuencial(FILE *archivo, char *Categoria)
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
    struct Peliculas Pelicula_Modificada;

    //MOVER EL PUNTERO A LA CLAVE
    fseek(archivo, (*clave) * sizeof(struct Peliculas), SEEK_SET);
    fread(&Pelicula_Modificada, sizeof(struct Peliculas), 1, archivo);
    Pelicula_Modificada.inventario = *inventario_n;
    fseek(archivo, (*clave) * sizeof(struct Peliculas), SEEK_SET);
    fwrite(&Pelicula_Modificada, sizeof(struct Peliculas), 1, archivo);
}

void Leer_guardar_datos_Directo(FILE *archivo)
{
    struct Peliculas pelicula;

    do
    {
        printf("Clave: ");
        scanf("%d", &pelicula.clave);
        if(pelicula.clave < 0)
            printf("No se permiten claves menores a 0\n");
    } while (pelicula.clave < 0);
    
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

        if (pelicula.inventario <= 0)
            printf("Como valor minimo se acepta 1.\n");
    } while (pelicula.inventario <= 0);

    //MOVER EL PUNTERO A LA POSICION DE LA CLAVE
    fseek(archivo, pelicula.clave * sizeof(struct Peliculas), SEEK_SET);
    fwrite(&pelicula, sizeof(struct Peliculas), 1, archivo);
}

void Mostrar_xcategoria_Directo(FILE *archivo)
{
    struct Peliculas pelicula;

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