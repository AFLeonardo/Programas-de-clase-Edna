#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void Alta_empleado(int *, char *, char *, float *);
void Listado_empleados();
void Listado_mayor_10000();
void Buscar_empleado(char *);

int main()
{
    int Num_empleado, opcion;
    char Nombre[50], Categoria;
    float Sueldo;
    bool menu = true;

    while (menu)
    {
        printf("1. Alta de empleado\n2.Listado de empleados en forma tabular.\n3.Listado con empleados cuyo sueldo es mayor a 10 000, en forma tabular.\n4.Mostar los datos de un empleado indicado por el usuario (Nombre)\n5.Salir.");
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Numero de empleado: ");
                scanf("%d", &Num_empleado);

                printf("Nombre: ");
                fflush(stdin);
                gets(Nombre);

                do
                {
                    printf("Categoria: ");
                    fflush(stdin);
                    scanf(" %c", &Categoria);

                    if (Categoria != 'A' && Categoria != 'B' && Categoria != 'C' && Categoria != 'D')
                    {
                        printf("ERROR.\nCategoria valida\n.CATEGORIAS VALIDAS: A B C D.\nIntenta de nuevo");
                    }
                    
                } while (Categoria != 'A' && Categoria != 'B' && Categoria != 'C' && Categoria != 'D');
                
                do
                {
                    printf("Sueldo: ");
                    scanf("%f", &Sueldo);

                    if (Sueldo < 0)
                        printf("Sueldo invalido.\nIntenta de nuevo.");
                    
                } while (Sueldo < 0);
                Alta_empleado(&Num_empleado, Nombre, &Categoria, &Sueldo);
                break;

            case 2:
                system("cls");
                Listado_empleados();    
                break;

            case 3:
                system("cls");
                Listado_mayor_10000();   
                break;

            case 4:
                system("cls");
                printf("Nombre: ");
                fflush(stdin);
                gets(Nombre);

                Buscar_empleado(Nombre);
                break;

            case 5:
                printf("Saliendo...");
                menu = false;
                break;
        }

    }
    
    return 1;
}

void Alta_empleado(int *Num_empleado, char *Nombre, char *Categoria, float *Sueldo)
{
    FILE *archivo;
    if ((archivo = fopen("Empleados.txt", "a")) == NULL)
    {
        printf("Error al abrir el archivo.");
    }
    else
    {
        fprintf(archivo, "%d %s %c %.2f\n", *Num_empleado, Nombre, *Categoria, *Sueldo);
        fclose(archivo);
    }
}

void Listado_empleados()
{
    FILE *archivo;
    int Num_empleado;
    char Nombre[50], Categoria;
    float Sueldo;

    if ((archivo = fopen("Empleados.txt", "r")) == NULL)
    {
        printf("Error al abrir el archivo.");
    }
    else
    {
        printf("%10s %10s %10s %10s\n", "Numero", "Nombre", "Categoria", "Sueldo");
        while (fscanf(archivo, "%d %49s %c %f", &Num_empleado, Nombre, &Categoria, &Sueldo) == 4)
        {
            printf("%10d %10s %10c %10.2f\n", Num_empleado, Nombre, Categoria, Sueldo);
        }
        printf("\n");
        fclose(archivo);
    }
}

void Listado_mayor_10000()
{
    FILE *archivo;
    int Num_empleado;
    char Nombre[50], Categoria;
    float Sueldo;

    if ((archivo = fopen("Empleados.txt", "r")) == NULL)
    {
        printf("Error al abrir el archivo.");
    }
    else
    {
        printf("%10s %10s %10s %10s\n", "Numero", "Nombre", "Categoria", "Sueldo");
        while (fscanf(archivo, "%d %49s %c %f", &Num_empleado, Nombre, &Categoria, &Sueldo) == 4)
        {
            if (Sueldo > 10000)
            {
                printf("%10d %10s %10c %10.2f\n", Num_empleado, Nombre, Categoria, Sueldo);
            }
        }
        printf("\n");
        fclose(archivo);
    }
}

void Buscar_empleado(char *Nombre)
{
    FILE *archivo;
    int Num_empleado;
    char Nombre_archivo[50], Categoria;
    float Sueldo;
    bool encontrado = false;

    if ((archivo = fopen("Empleados.txt", "r")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
    }
    else
    {
        while (fscanf(archivo, "%d %49s %c %f", &Num_empleado, Nombre_archivo, &Categoria, &Sueldo) == 4)
        {
            if (strcmp(Nombre_archivo, Nombre) == 0)
            {
                encontrado = true;
                printf("%10s %10s %10s %10s\n", "Numero", "Nombre", "Categoria", "Sueldo");
                printf("%10d %10s %10c %10.2f\n", Num_empleado, Nombre_archivo, Categoria, Sueldo);
            }
        }
        
        if (!encontrado)
        {
            printf("Empleado no encontrado.\n");
        }
        fclose(archivo);
    }
}
