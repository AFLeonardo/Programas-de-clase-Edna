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

int main()
{   
    char opcion;
    FILE *archivo;
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
                printf("Lectura de datos\n");
                if ((archivo = fopen("archivo.txt","a") == NULL))
                    printf("Error al abrir el archivo.");
                else
                {
                    Lectura_datos(archivo);
                }
                
                break;
            
            case 'B':
                // Lectura de datos
                break;
            
            case 'C':
                // Lectura de datos
                break;

            case 'D':
                // Lectura de datos
                break;
            
            case 'E':
                break;
        }
        opcion = menu();
        printf("\n\n");
    }
    
    
    return 0;
}

char menu()
{
    char opcion;
    printf("A - Lectura de datos\n");
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

}