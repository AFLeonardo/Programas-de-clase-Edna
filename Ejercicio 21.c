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
    struct Deportista Informacion;

    printf("Ingrese el nombre del deportista: ");
    scanf("%s", Informacion.nombre);
    printf("Ingrese la edad del deportista: ");
    scanf("%d", &Informacion.edad);
    printf("Ingrese el peso del deportista: ");
    scanf("%f", &Informacion.Peso);
    printf("Ingrese la altura del deportista: ");
    scanf("%f", &Informacion.Altura);
    
    printf("Nombre: %-20s\n", Informacion.nombre);
    printf("Edad: %2d\n", Informacion.edad);
    printf("Peso: %6.2f kg\n", Informacion.Peso);
    printf("Altura: %5.2f m\n", Informacion.Altura);
}