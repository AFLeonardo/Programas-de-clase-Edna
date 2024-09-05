#include <stdio.h>

int main()
{
    float valor_vehiculo, enganche, mensualidad;
    printf("Ingrese el valor del vehiculo: ");
    scanf("%f", &valor_vehiculo);
    
    enganche = valor_vehiculo * 0.35;
    mensualidad = (valor_vehiculo - enganche);
    mensualidad = mensualidad + (mensualidad * 0.12);  // Cambié 1.12 a 0.12 para representar el 12% de interés
    mensualidad = mensualidad / 36;
    
    printf("El valor de la mensualidad es: %.2f\n", mensualidad); // Corregí la forma de imprimir con "\n"
    printf("El enganche es de: %.2f\n", enganche); // Añadí "\n" para un mejor formato de salida
    
    return 0;
}
