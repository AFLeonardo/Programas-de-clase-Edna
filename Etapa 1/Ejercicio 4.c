#include <stdio.h>
#include <math.h>

main()
{
    float radio, generatriz, cono_altura;
    float area_base, area_lateral, area_total, volumen;
    
    printf("Ingrese el radio del cono: ");
    scanf("%f", &radio);
    printf("Ingrese la generatriz del cono: ");
    scanf("%f", &generatriz);
    printf("Ingrese la altura del cono: ");
    scanf("%f", &cono_altura);

    area_base = M_PI * pow(radio, 2);
    area_lateral = M_PI * radio * generatriz;
    area_total = area_base + area_lateral;
    volumen = (1.0/3.0) * area_base * cono_altura;

    printf("Area de la base: %.2f\n", area_base);
    printf("Area lateral: %.2f\n", area_lateral);
    printf("Area total: %.2f\n", area_total);
    printf("Volumen: %.2f\n", volumen);


}