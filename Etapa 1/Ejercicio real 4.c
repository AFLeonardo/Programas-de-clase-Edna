#include <stdio.h>

main()
{
    float p1x, p1y, p2x, p2y, p3x, p3y, perimetro, distancia1, distancia2, distancia3;
    printf("Digite las coordenadas del primer punto (x y): ");
    scanf("%f %f", &p1x, &p1y);
    printf("Digite las coordenadas del segundo punto (x y): ");
    scanf("%f %f", &p2x, &p2y);
    printf("Digite las coordenadas del tercer punto (x y): ");
    scanf("%f %f", &p3x, &p3y);

    distancia1 = sqrt(pow(p1x + p2x, 2) + pow(p1y + p2y, 2));
    distancia2 = sqrt(pow(p2x + p3x, 2) + pow(p2y + p3y, 2));
    distancia3 = sqrt(pow(p1x + p3x, 2) + pow(p1y + p3y, 2));

    perimetro = distancia1 + distancia2 + distancia3;
    printf("El perimetro del triangulo es: %.2f", perimetro);

}