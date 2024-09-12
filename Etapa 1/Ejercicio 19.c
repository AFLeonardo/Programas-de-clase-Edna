#include <stdio.h>
int main()
{
    float calif_alum[6][2], // Cambié el tamaño del array a 6x2
          promedio[6] = {0}, // Inicializamos los promedios en 0
          calificacion; 
    int i, j;

    for (i = 0; i < 6; i++)
    {
        printf("Alumno %d \n", i + 1);
        for (j = 0; j < 3; j++)
        {
            do
            {
                printf("Calificaciones del examen %d: ", j + 1);
                scanf("%f", &calificacion);

                if (calificacion < 0 || calificacion > 100)
                    printf("Calificacion invalida. Intente de nuevo.\n");

            } while (calificacion < 0 || calificacion > 100);
            
            if (j == 1)
                calif_alum[i][j] = calificacion;

            promedio[i] += calificacion;
        }
        promedio[i] /= 3;
    }

    printf("\n%-10s %-15s %-10s\n", "NOMBRE", "2do PARCIAL", "PROMEDIO");
    printf("------------------------------------------\n");

    for (i = 0; i < 6; i++)
        printf("Alumno %-2d   %-15.2f %-10.2f\n", i + 1, calif_alum[i][1], promedio[i]);

    return 0;
}
