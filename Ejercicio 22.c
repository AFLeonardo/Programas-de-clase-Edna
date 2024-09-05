#include <stdio.h>

struct Deportista
{
    char nombre[50];
    int edad;
    float Peso,
          Altura;
};

main()
{
    int i;
    struct Deportista Informacion[5];

    for (i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre del deportista: ");
        scanf("%s", Informacion[i].nombre);
        printf("Ingrese la edad del deportista: ");
        scanf("%d", &Informacion[i].edad);
        printf("Ingrese el peso del deportista: ");
        scanf("%f", &Informacion[i].Peso);
        printf("Ingrese la altura del deportista: ");
        scanf("%f", &Informacion[i].Altura);
    }
    
    for (i = 0; i < 5; i++)
    {
        printf("Nombre: %s\n", Informacion[i].nombre);
        printf("Edad: %d\n", Informacion[i].edad);
        printf("Peso: %.2f\n", Informacion[i].Peso);
        printf("Altura: %.2f\n", Informacion[i].Altura);
    }
}