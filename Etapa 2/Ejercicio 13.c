#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Planeta
{
    int clave;
    char nombre[50];
    int dimension;
    char caracteristicas[100];
    bool vida;
};

// FUNCIONES
char menu();
void Lectura_datos(FILE *);
void Mostar_Planeta_X(FILE *, int *);

int main()
{   
    char opcion;
    FILE *archivo;
    int X_clave;

    do
    {
        opcion = menu();
        if (opcion < 'A' || opcion > 'E')
            printf("Opcion invalida\n");
        
    } while (opcion < 'A' || opcion > 'E');

    while (opcion != 'E')
    {
        switch (opcion)
        {
            case 'A':
                printf("\n\nLectura de datos\n");
                if ( (archivo = fopen("Planetas.txt","a")) == NULL)
                    printf("Error al abrir el archivo.");
                else
                {
                    Lectura_datos(archivo);
                    // Cerrando archivo
                    fclose(archivo);
                    break;
                }
            
            case 'B':
                printf("\n\nMostrar planeta\n");
                if ( (archivo = fopen("Planetas.txt","r")) == NULL)
                    printf("Error al abrir el archivo.");
                else
                {
                    printf("Ingresa la clave del planeta: ");
                    scanf("%d", &X_clave);

                    Mostar_Planeta_X(archivo, &X_clave);
                    // Cerrando archivo
                    fclose(archivo);
                    break;
                }
            
            case 'C':
                // Lectura de datos
                break;

            case 'D':
                // Lectura de datos
                break;
            
            case 'E':
                break;
        }
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++");
        opcion = menu();
        printf("\n\n");
    }
    
    
    return 0;
}

char menu()
{
    char opcion;
    printf("\nMenu");
    printf("\nA - Lectura de datos\n");
    printf("B - Mostrar datos de planeta en particular\n");
    printf("C - Mostrar en forma tabular todos los planetas y sus datos que tienen posibilidad de vida\n");
    printf("D - Mostrar en forma tabular todos los planetas y sus datos que en sus caracteristicas contienen la palabra agua\n");
    printf("E - Salir\n");
    printf("Ingrese una opcion: ");

    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}

void Lectura_datos(FILE *archivo)
{
    struct Planeta planeta_X;
    char vida;

    do
    {
        printf("Ingresa la clave del planeta: ");
        scanf("%d", &planeta_X.clave);
        if (planeta_X.clave < 0)
            printf("Clave invalida.\nIngresa valores mayores a 0.\n");
        
    } while (planeta_X.clave < 0);
    
    do
    {
        printf("Ingresa la dimension del planeta: ");
        scanf("%d", &planeta_X.clave);
        if (planeta_X.dimension < 0)
            printf("Dimension invalida.\nIngresa valores mayores a 0.\n");
        
    } while (planeta_X.dimension < 0);

    printf("Ingresa las caracteristicas del planeta: ");
    fflush(stdin);
    gets(planeta_X.caracteristicas);

    do
    {
        printf("El planeta tiene posibilidad de vida? (S/N): ");
        fflush(stdin);
        scanf("%c", &vida);
    } while (vida != 'S' && vida != 's' && vida != 'N' && vida != 'n');
    
    if (vida == 'S' || vida == 's')
        planeta_X.vida = true;
    else
        planeta_X.vida = false;

    // Escribir los datos en el archivo directo
    fwrite(&planeta_X, sizeof(struct Planeta), 1, archivo);
}

void Mostar_Planeta_X(FILE *archivo, int *clave)
{
    struct Planeta Y_Planeta;
    bool encontrado = false;
    char vida[3] = "No";
    while (fread(&Y_Planeta, sizeof(struct Planeta), 1, archivo))
    {
        if (Y_Planeta.clave == *clave)
        {
            if (Y_Planeta.vida)
                strcpy(vida, "Si");
            
            printf("Clave: %d\n"
                   "Nombre: %s\n"
                   "Dimension: %d\n"
                   "Caracteristicas: %s\n"
                   "Vida: %s\n", 
                    Y_Planeta.clave, 
                    Y_Planeta.nombre, 
                    Y_Planeta.dimension, 
                    Y_Planeta.caracteristicas, 
                    vida);
            encontrado = true;
        }
    }
    if (!encontrado)
        printf("\n\nNO SE ENCONTRO NINGUN PLANETA CON LA CLAVE: %d", *clave);
}
