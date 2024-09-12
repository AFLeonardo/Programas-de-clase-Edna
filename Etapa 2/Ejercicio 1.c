// Funciones para determinar el area de un triangulo.
#include <stdio.h>

float areaTriangulo(float base, float altura)
{
    return base * altura / 2;
}

int main()
{
    float base, altura;
    printf("Ingresa la altura: ");
    scanf("%f", &altura);
    printf("Ingresa la base: ");
    scanf("%f", &base);
    printf("El area del triangulo es: %f", areaTriangulo(base, altura));
    return 0;
}