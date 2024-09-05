#include <stdio.h>
#include <math.h>

main()
{
    float pi = 3.14, radio, area, circunferencia;
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);
    area = pi * pow(radio,2);
    circunferencia = 2 * pi * radio;

    printf("El area del circulo es: %.2f\n", area);
    printf("La circunferencia del circulo es: %.2f\n", circunferencia);
}