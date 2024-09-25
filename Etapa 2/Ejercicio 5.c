#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaraciones de las funciones
void calculo(float *, float *);
void Lectura_datos(float *);
void Impresion(float *, float *);

int main()
{
    float estudiantes[3][5],  // Máximo 3 alumnos, 5 calificaciones
          promedios[3];       // Un promedio por cada alumno (3 alumnos)

    int opcion;
    bool repeticion = true,
         opcion1 = false,
         opcion2 = false;

    while (repeticion)
    {
        system("cls");
        printf("\n%20s", "Menu de opciones\n1. Lectura de datos\n2. Calculo de promedio\n3. Imprimir resultados\n4. Salir\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                Lectura_datos(&estudiantes[0][0]);
                opcion1 = true;
                break;
            case 2:
                if (opcion1)
                {
                    calculo(&estudiantes[0][0], promedios);
                    opcion2 = true;
                    printf("Promedios calculados exitosamente.\n");
                    system("pause");
                }
                else
                {
                    printf("Primero debes leer los datos.\n");
                    system("pause");
                }
                break;
            case 3:
                if (opcion2)
                {
                    Impresion(&estudiantes[0][0], promedios);
                    system("pause");
                }
                else
                {
                    printf("Primero debes calcular los promedios.\n");
                    system("pause");
                }
                break;
                
            case 4:
                repeticion = false;
                break;
            default:
                printf("\nOpcion no valida.\nIntenta de nuevo\n");
                break;
        }
    }

    return 0;
}

//========================================
// Lectura de datos
void Lectura_datos(float *ptr_calif)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        printf("\nAlumno #%d\n", i + 1);
        for (j = 0; j < 5; j++)
        {
            // Validación de notas
            do
            {
                printf("Ingrese la nota %d: ", j + 1);
                scanf("%f", (ptr_calif + i * 5 + j));
                if (*(ptr_calif + i * 5 + j) < 0 || *(ptr_calif + i * 5 + j) > 100)
                {
                    system("cls");
                    printf("VALORES PERMITIDOS DE 0 A 100. Intenta de nuevo.\n");
                }
            } while (*(ptr_calif + i * 5 + j) < 0 || *(ptr_calif + i * 5 + j) > 100);
        }
    }
}

//========================================
// Cálculo de los promedios
void calculo(float *ptr_calif, float *promedios)
{
    int i, j;
    float suma;

    for (i = 0; i < 3; i++)
    {
        suma = 0;
        for (j = 0; j < 5; j++)
        {
            suma += *(ptr_calif + i * 5 + j);
        }
        promedios[i] = suma / 5;
    }
}

//========================================
// Impresión de datos
void Impresion(float *ptr_calif, float *promedios) {
    int i, j;

    // Imprimir encabezado de las columnas
    printf("\n%10s", "Alumno");
    for (j = 0; j < 5; j++) {
        printf("%10s%d", "Nota", j + 1);
    }
    printf("%12s", "Promedio");  
    printf("\n");

    // Imprimir cada fila de datos
    for (i = 0; i < 3; i++) {
        printf("%10d", i + 1);
        for (j = 0; j < 5; j++)
            printf("%10.2f", *(ptr_calif + i * 5 + j));
        printf("%12.2f", promedios[i]);
        printf("\n");
    }
}
