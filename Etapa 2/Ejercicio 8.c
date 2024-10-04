// NOMBRE MATRICULA PROMEDIO
#include <stdio.h>
#include <string.h>

int main() 
{
    char nombre[50], datos;
    int matricula, semestre;
    float promedio;
    FILE *archivo;

    printf("Desea ingresar datos? (s/n): ");
    scanf("%c", &datos);
    fflush(stdin);

    if ((archivo = fopen("Datos.txt", "w")) == NULL)
            printf("Error al abrir el archivo.\n");
    else
    {
        while (datos == 's' || datos == 'S')
        {
                printf("Ingrese su nombre: ");
                fflush(stdin);
                gets(nombre);

                printf("Ingrese su matricula: ");
                scanf("%d", &matricula);

                printf("Ingrese su promedio: ");
                scanf("%f", &promedio);

                printf("Ingresa tu semestre: ");
                scanf("%d", &semestre);

                fprintf(archivo, "%s %d %.2f %d\n", nombre, matricula, promedio, semestre);

                printf("Desea ingresar datos? (s/n): ");
                fflush(stdin);
                scanf("%c", &datos);
        }
        fclose(archivo);
    }
    return 0;
}