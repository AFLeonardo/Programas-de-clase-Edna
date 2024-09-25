#include <stdio.h>
#include <stdbool.h>

float promedio(float a, float b, float c, float d, float e)
{  
    return (a + b + c + d + e) / 5;
}

int main()
{
    float estudiantes[20][6];  
    int i, j, opcion;
    bool repeticion = true, opcion1 = false, opcion2 = false;

    while (repeticion)
    {
        
        printf("\n%20s", "Menu de opciones\n1. Lectura de datos\n2. Calculo de promedio\n3. Imprimir resultados\n4. Salir\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                for (i = 0; i < 3; i++)
                {   
                    printf("\nAlumno #%d\n", i + 1);
                    for (j = 0; j < 5; j++)
                    {
                        // Validación de notas
                        do
                        {
                            printf("Ingrese la nota %d: ", j + 1);
                            scanf("%f", &estudiantes[i][j]);
                            if (estudiantes[i][j] < 0 || estudiantes[i][j] > 100)
                            {
                                printf("VALORES PERMITIDOS DE 0 A 100. Intenta de nuevo.\n");
                            }
                        } while (estudiantes[i][j] < 0 || estudiantes[i][j] > 100);
                    }
                }
                opcion1 = true;
                break;

            case 2:
                if (opcion1)
                {
                    printf("\nCalculo de promedios...\n");
                    for (i = 0; i < 3; i++)
                    {
                        estudiantes[i][5] = promedio(estudiantes[i][0], estudiantes[i][1], estudiantes[i][2], estudiantes[i][3], estudiantes[i][4]);
                    }
                    printf("Promedios calculados correctamente.\n");
                    opcion2 = true;  // Indicar que se han calculado los promedios
                }
                else
                {
                    printf("Primero debes ingresar los datos. Selecciona la opcion 1.\n");
                }
                break;

            case 3:
                if (opcion2)
                {
                    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Alumno", "Nota 1", "Nota 2", "Nota 3", "Nota 4", "Nota 5", "Promedio");

                    for (i = 0; i < 3; i++) {
                        // Imprimir número de alumno alineado a la izquierda
                        printf("%-12d", i + 1);

                        // Imprimir las 5 notas
                        for (j = 0; j < 5; j++) {
                            printf("%-12.2f", estudiantes[i][j]);
                        }

                        // Imprimir el promedio (columna 5)
                        printf("%-10.2f", estudiantes[i][5]);

                        // Salto de línea al final de cada fila de un alumno
                        printf("\n");
                    }

                }
                else
                {
                    printf("Primero debes calcular los promedios. Selecciona la opcion 2.\n");
                }
                break;

            case 4:
                printf("\nSaliendo del programa...\n");
                repeticion = false;
                break;

            default:
                printf("\nOpcion no valida.\n");
                break;
        }
    }

    return 0;
}
