#include <stdio.h>
#include <string.h>

struct Estudiante {
    char Nombre[40];
    int Matricula;
    int Semestre;
    float Promedio[9]; // Máximo 9 semestres
    char Carrera[40];
};

struct Alumnos_destacados {
    struct Estudiante Datos;
};

struct Alumnos_computacion_destacados {
    struct Estudiante Datos;
};

int main() 
{
    char agregar;
    int i = 0, j, 
    alumnos = 0,
    contador_destacados = 0,
    contador_computacion = 0,
    contador_carrera = 0;
    struct Estudiante Alumnos[20]; // Máximo 20 estudiantes
    struct Alumnos_destacados Alumnos_promedio_superior[20];
    struct Alumnos_computacion_destacados Alumnos_computacion[20];
    struct Alumnos_destacados Alumnos_x_carrera[20];
    
    char Carrera[30];
    float promedio_general[20] = {0};

    printf("Quieres agregar datos? (s/n): ");
    scanf(" %c", &agregar);

    while (agregar == 's' && i < 20) {
        printf("Ingresa tu nombre:\n");
        fflush(stdin);
        gets(Alumnos[i].Nombre);

        // Validacion de matricula
        do {
            printf("Ingresa tu matricula:\n");
            scanf("%d", &Alumnos[i].Matricula);

            if (Alumnos[i].Matricula <= 0)
                printf("La matricula no puede ser menor o igual a 0. Intenta de nuevo.\n");
        } while (Alumnos[i].Matricula <= 0);

        //Validacion de semestre
        do {
            printf("En que semestre te encuentras?\n");
            scanf("%d", &Alumnos[i].Semestre);

            if (Alumnos[i].Semestre < 1 || Alumnos[i].Semestre > 9)
                printf("Semestres permitidos del 1 al 9. Intente de nuevo.\n");
        } while (Alumnos[i].Semestre < 1 || Alumnos[i].Semestre > 9);

        for (j = 0; j < Alumnos[i].Semestre; j++) 
        {
            do 
            {
                printf("Ingresa el promedio del semestre %d:\n", j + 1);
                scanf("%f", &Alumnos[i].Promedio[j]);

                promedio_general[i] += Alumnos[i].Promedio[j];

                if (Alumnos[i].Promedio[j] < 0 || Alumnos[i].Promedio[j] > 100)
                    printf("Rango permitido 0-100. Intenta de nuevo.\n");
            }
            while (Alumnos[i].Promedio[j] < 0 || Alumnos[i].Promedio[j] > 100);
        }
        promedio_general[i] /= Alumnos[i].Semestre;

        printf("Ingresa tu carrera: \n");
        fflush(stdin);
        gets(Alumnos[i].Carrera);

        i++;
        alumnos++;

        printf("Quieres agregar otro alumno? (s/n): ");
        fflush(stdin);
        scanf(" %c", &agregar);
    }

    if (alumnos > 0)
    {
        printf("Cual es la carrera por la que quieres filtrar?: \n");
        fflush(stdin);
        gets(Carrera);

        for (i = 0; i < alumnos; i++) 
        {
            // Inciso A: Alumnos con promedio >= 90
            if (promedio_general[i] >= 90) {
                // Usar strcpy para copiar el nombre
                strcpy(Alumnos_promedio_superior[contador_destacados].Datos.Nombre, Alumnos[i].Nombre);
                Alumnos_promedio_superior[contador_destacados].Datos.Matricula = Alumnos[i].Matricula;
                contador_destacados++;
            }

            // Inciso B: Alumnos de la carrera de computación con promedio >= 90
            if (promedio_general[i] >= 90 && strcmp(Alumnos[i].Carrera, "Computacion") == 0) {
                // Usar strcpy para copiar el nombre
                strcpy(Alumnos_computacion[contador_computacion].Datos.Nombre, Alumnos[i].Nombre);
                Alumnos_computacion[contador_computacion].Datos.Matricula = Alumnos[i].Matricula;
                contador_computacion++;
            }

            // Inciso C
            if (promedio_general[i] >= 90 && strcpy(Alumnos[i].Carrera, Carrera) == 0) {
                strcpy(Alumnos_x_carrera[contador_carrera].Datos.Nombre, Alumnos[i].Nombre);
                Alumnos_x_carrera[contador_carrera].Datos.Matricula = Alumnos[i].Matricula;
            }
        }

        printf("%10-- Alumnos destacados:-- \n");
        for (i = 0; i < contador_destacados; i++) 
        {
            printf("Nombre: %-6s\n Matricula: %-6d\n", Alumnos_promedio_superior[contador_destacados].Datos.Nombre, Alumnos_promedio_superior[contador_destacados].Datos.Matricula);
        }

        printf("%10-- Alumnos destacados de computacion:-- \n");
        for (i = 0; i < contador_computacion; i++) 
        {
            
            printf("Nombre: %-6s\n Matricula: %-6d\n", Alumnos_computacion[contador_computacion].Datos.Nombre, Alumnos_computacion[contador_computacion].Datos.Matricula);
        }

        printf("%10 -- Alumnos destacados de %s: --\n", Carrera);
        for (i = 0; i < contador_carrera; i++) 
        {
            printf("Nombre: %-6s\n Matricula: %-6d\n", Alumnos_x_carrera[contador_carrera].Datos.Nombre, Alumnos_x_carrera[contador_carrera].Datos.Matricula);
        }
    }
    else
        printf("No se ingresaron datos.\n");
}
