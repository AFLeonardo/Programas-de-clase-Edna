#include <stdio.h>

struct Estudiante{
    char Nombre[30];
    int Matricula;
    int Semestre;
    int Promedio[9]; // Máximo 9 semestres
    char Carrera[30];
};

struct Alumnos_destacados{
    struct Estudiante Datos;
}

struct Alumnos_computacion_destacados{
    struct Estudiante Datos;
}


int main()
{
    char agregar;
    int i = 0, j, alumnos = 0;
    struct Estudiante Datos[20]; // Máximo 20 estudiantes
    struct Alumnos_destacados Datos_destacados[20];
    struct Alumnos_computacion_destacados Datos_destacados_computacion[20];
    float Alumnos_promedio_general[10][10];
    char Carrera[30];


    printf("¿Quieres agregar datos? (s/n): ");
    fflush(stdin);
    gets(agregar);

    while(agregar == 's' && i < 20)
    {
        printf("Ingresa tu nombre:\n");
        fflush(stdin);
        gets(Datos[i].Nombre);

        // Validación de matrícula mayor a 0
        do
        {
            printf("Ingresa tu matrícula:\n");
            scanf("%d", &Datos[i].Matricula);

            if (Datos[i].Matricula <= 0)
                printf("La matrícula no puede ser menor o igual a 0. Intenta de nuevo.\n");
        }
        while(Datos[i].Matricula <= 0);

        // Validar semestre entre 1 y 9
        do
        {
            printf("¿En qué semestre te encuentras?\n");
            scanf("%d", &Datos[i].Semestre);

            if (Datos[i].Semestre < 1 || Datos[i].Semestre > 9)
                printf("Semestres permitidos del 1 al 9. Intente de nuevo.\n");
        }
        while(Datos[i].Semestre < 1 || Datos[i].Semestre > 9);

        for (j = 0; j < Datos[i].Semestre; j++)
        {
            // Validar que el promedio sea entre 0 y 100
            do
            {
                printf("Ingresa el promedio del semestre %d:\n", j + 1);
                scanf("%d", &Datos[i].Promedio[j]);

                if (Datos​[i].Promedio[j] < 0 || Datos.[i].Promedio[j])
                    printf("Rango permitido 0-100. Intenta de nuevo.\n");
            }
            while(Datos[i].Promedio[j] < 0 || Datos.[i].Promedio[j])
        }

        printf("Ingresa tu carrera: \n");
        gets(Datos[i].Carrera);
    }

    // Prueba
    printf("Nombre: %c",Datos[0].Nombre, "Matricula: %d", Datos[0].Matricula, "Semestre: %d", Datos[0].Semestre);

    // Proceso de alumnos con promedio mayor o igual a 90
    for (i =0 ; i < alumnos ; i++)
    {
        // Inciso a)
        if(Datos[i].Promedio >= 90)
        {
            Datos_destacados[i].Nombre = Datos[i].Nombre;
            Datos_destacados[i].Matricula = Datos_destacados[i].Matricula;
        }

        // Inciso b)
        if(Datos[i].Promedio >= 90 && Datos[i].Carrera == "Computacion")
        {
            Datos_destacados_computacion[i].Nombre = Datos[i].Nombre;
            Datos_destacados_computacion[i].Matricula = Datos[i].Matricula;
        }

        // Inciso c)
        if(Datos[i].Promedio )
    }

    //Preguntar al usuario la carrera que desea filtrar
    printf("Cual es la carrera por la ue quieres filtrar: \n");
    gets(Carrera);


}