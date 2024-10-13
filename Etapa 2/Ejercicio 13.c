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
void Mostrar_Planeta_X(FILE *, int *);
void Mostrar_Planeta_Vida(FILE *);

int main()
{   
    char opcion;
    FILE *archivo;
    int X_clave;

    do
    {
        opcion = menu();
        if ((opcion < 'A' || opcion > 'E') && (opcion < 'a' || opcion > 'e'))
            printf("Opcion invalida\n");
        
    } while ((opcion < 'A' || opcion > 'E') && (opcion < 'a' || opcion > 'e'));

    while (opcion != 'E' && opcion != 'e')
    {
        switch (opcion)
        {
            case 'A':
            case 'a':
                printf("\nLectura de datos\n");
                if ( (archivo = fopen("Planetas.txt","ab+")) == NULL)
                    printf("Error al abrir el archivo.");
                else
                {
                    Lectura_datos(archivo);
                    // Cerrando archivo
                    fclose(archivo);
                }
                break;

            case 'B':
            case 'b':
                printf("\nMostrar planeta\n");
                if ( (archivo = fopen("Planetas.txt","rb")) == NULL)
                    printf("Error al abrir el archivo.");
                else
                {
                    printf("Ingresa la clave del planeta: ");
                    scanf("%d", &X_clave);

                    Mostrar_Planeta_X(archivo, &X_clave);
                    // Cerrando archivo
                    fclose(archivo);
                }
                break;
            
            case 'C':
            case 'c':
                printf("\nMostrar en forma tabular todos los planetas y sus datos que tienen posibilidad de vida\n");
                if ( (archivo = fopen("Planetas.txt","rb")) == NULL)
                    printf("Error al abrir el archivo.");
                else
                {
                    Mostrar_Planeta_Vida(archivo);
                    // Cerrando archivo
                    fclose(archivo);
                }
                break;

            case 'D':
            case 'd':
                printf("\nMostrar en forma tabular todos los planetas y sus datos que en sus caracteristicas contienen la palabra agua\n");
                break;
            
            case 'E':
            case 'e':
                break;
        }

        do
        {
            opcion = menu();
            if ((opcion < 'A' || opcion > 'E') && (opcion < 'a' || opcion > 'e'))
                printf("Opcion invalida\n");
            
        } while ((opcion < 'A' || opcion > 'E') && (opcion < 'a' || opcion > 'e'));
        printf("\n");
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
    
    printf("Ingresa el nombre del planeta: ");
    fflush(stdin);
    gets(planeta_X.nombre);

    do
    {
        printf("Ingresa la dimension del planeta: ");
        scanf("%d", &planeta_X.dimension);
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

void Mostrar_Planeta_X(FILE *archivo, int *clave) {
    struct Planeta Y_Planeta;
    bool encontrado = false;
    char vida[3] = "No";

    fseek(archivo, 0, SEEK_SET);

    while (fread(&Y_Planeta, sizeof(struct Planeta), 1, archivo) && !encontrado) 
    {
        if (Y_Planeta.clave == *clave) 
        {
            encontrado = true; 
            if (Y_Planeta.vida)
                strcpy(vida, "Si");
            
            printf("============================================================================================\n");
            printf("%-20s %-20s %-20s %-20s %-20s\n", "Clave", "Nombre", "Dimension", "Caracteristicas", "Vida");
            printf("============================================================================================\n");
            printf("%-20d %-20s %-20d %-20s %-20s\n", Y_Planeta.clave, Y_Planeta.nombre, Y_Planeta.dimension, Y_Planeta.caracteristicas, vida);
            printf("============================================================================================\n");
        }
    }

    if (!encontrado) 
    {
        printf("============================================================================================\n");
        printf("NO SE ENCONTRO NINGUN PLANETA CON LA CLAVE: %d\n\n", *clave);
    }
}

void Mostrar_Planeta_Vida(FILE *archivo)
{
    struct Planeta Y_Planeta;
    bool encontrado = false;
    printf("============================================================================================");
    printf("\n%-20s %-20s %-20s %-20s %-20s\n", "Clave", "Nombre", "Dimension", "Caracteristicas", "Vida");
    printf("============================================================================================\n");
    while (fread(&Y_Planeta, sizeof(struct Planeta), 1, archivo))
    {
        if (Y_Planeta.vida)
        {
            printf("%-20d %-20s %-20d %-20s %-20s\n", Y_Planeta.clave, Y_Planeta.nombre, Y_Planeta.dimension, Y_Planeta.caracteristicas, "Si");
            encontrado = true;
        }
    }
    printf("============================================================================================\n");
    if (!encontrado)
        printf("\n\nNO SE ENCONTRO NINGUN PLANETA CON VIDA\n");
}