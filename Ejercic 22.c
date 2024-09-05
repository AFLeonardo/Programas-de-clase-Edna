#include <stdio.h>
#include <string.h>

struct Estudiante {
    char Nombre[40];
    int Matricula;
    int Semestre;
    int Promedio[9]; // Máximo 9 semestres
    char Carrera[40];
};

struct Alumnos_destacados {
    struct Estudiante Datos;
};

struct Alumnos_computacion_destacados {
    struct Estudiante Datos;
};

int main() {
    char agregar;
    int i = 0, j, alumnos = 0;
    struct Estudiante Datos[20]; // Máximo 20 estudiantes
    struct Alumnos_destacados Datos_destacados[20];
    struct Alumnos_computacion_destacados Datos_destacados_computacion[20];
    char Carrera[30];

    printf("¿Quieres agregar datos? (s/n): ");
    scanf(" %c", &agregar);

    while (agregar == 's' && i < 20) {
        printf("Ingresa tu nombre:\n");
        getchar(); // Consumir el salto de línea previo
        fgets(Datos[i].Nombre, 30, stdin);
        Datos[i].Nombre[strcspn(Datos[i].Nombre, "\n")] = 0; // Eliminar el salto de línea

        // Validación de matrícula mayor a 0
        do {
            printf("Ingresa tu matricula:\n");
            scanf("%d", &Datos[i].Matricula);

            if (Datos[i].Matricula <= 0)
                printf("La matricula no puede ser menor o igual a 0. Intenta de nuevo.\n");
        } while (Datos[i].Matricula <= 0);

        // Validar semestre entre 1 y 9
        do {
            printf("¿En que semestre te encuentras?\n");
            scanf("%d", &Datos[i].Semestre);

            if (Datos[i].Semestre < 1 || Datos[i].Semestre > 9)
                printf("Semestres permitidos del 1 al 9. Intente de nuevo.\n");
        } while (Datos[i].Semestre < 1 || Datos[i].Semestre > 9);

        for (j = 0; j < Datos[i].Semestre; j++) {
            // Validar que el promedio sea entre 0 y 100
            do {
                printf("Ingresa el promedio del semestre %d:\n", j + 1);
                scanf("%d", &Datos[i].Promedio[j]);

                if (Datos[i].Promedio[j] < 0 || Datos[i].Promedio[j] > 100)
                    printf("Rango permitido 0-100. Intenta de nuevo.\n");
            } while (Datos[i].Promedio[j] < 0 || Datos[i].Promedio[j] > 100);
        }

        printf("Ingresa tu carrera: \n");
        getchar(); // Consumir el salto de línea previo
        fgets(Datos[i].Carrera, 30, stdin);
        Datos[i].Carrera[strcspn(Datos[i].Carrera, "\n")] = 0; // Eliminar el salto de línea

        i++;
        alumnos++;

        printf("¿Quieres agregar otro alumno? (s/n): ");
        scanf(" %c", &agregar);
    }

    // Preguntar al usuario la carrera que desea filtrar
    printf("¿Cual es la carrera por la que quieres filtrar?: \n");
    getchar(); // Consumir el salto de línea previo
    fgets(Carrera, 30, stdin);
    Carrera[strcspn(Carrera, "\n")] = 0; // Eliminar el salto de línea

    // Proceso de alumnos con promedio mayor o igual a 90
    for (i = 0; i < alumnos; i++) {
        // Calcular el promedio general del estudiante
        int suma_promedio = 0;
        for (j = 0; j < Datos[i].Semestre; j++) {
            suma_promedio += Datos[i].Promedio[j];
        }
        float promedio_general = suma_promedio / (float)Datos[i].Semestre;

        // Inciso a) Alumnos con promedio >= 90
        if (promedio_general >= 90) {
            strcpy(Datos_destacados[i].Datos.Nombre, Datos[i].Nombre);
            Datos_destacados[i].Datos.Matricula = Datos[i].Matricula;
        }

        // Inciso b) Alumnos de computación con promedio >= 90
        if (promedio_general >= 90 && strcmp(Datos[i].Carrera, "Computacion") == 0) {
            strcpy(Datos_destacados_computacion[i].Datos.Nombre, Datos[i].Nombre);
            Datos_destacados_computacion[i].Datos.Matricula = Datos[i].Matricula;
        }

        // Inciso c) Alumnos de la carrera específica con promedio >= 90
        if (promedio_general >= 90 && strcmp(Datos[i].Carrera, Carrera) == 0) {
            strcpy(Datos_destacados_computacion[i].Datos.Nombre, Datos[i].Nombre);
            Datos_destacados_computacion[i].Datos.Matricula = Datos[i].Matricula;
        }
    }

    // Mostrar los alumnos destacados
    printf("Alumnos destacados:\n");
    for (i = 0; i < alumnos; i++) {
        if (Datos_destacados[i].Datos.Matricula != 0) {
            printf("Nombre: %s, Matricula: %d\n", Datos_destacados[i].Datos.Nombre, Datos_destacados[i].Datos.Matricula);
        }
    }

    printf("Alumnos destacados de computacion:\n");
    for (i = 0; i < alumnos; i++) {
        if (Datos_destacados_computacion[i].Datos.Matricula != 0) {
            printf("Nombre: %s, Matricula: %d\n", Datos_destacados_computacion[i].Datos.Nombre, Datos_destacados_computacion[i].Datos.Matricula);
        }
    }

    return 0;
}
