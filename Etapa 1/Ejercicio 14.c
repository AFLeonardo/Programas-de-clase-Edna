#include <stdio.h>

main()
{
    int i;
    float temp_mayor = -1000, temp_menor = 1000, promedio = 0, temperatura; 

    for (i=0; i < 5; i++)
    {
        printf("Ingresa la temperatura: ");
        scanf("%f", &temperatura);

        promedio += temperatura;

        if (temperatura >= temp_mayor)
        {
            temp_mayor = temperatura;
        }
        if (temperatura < temp_menor) 
            temp_menor = temperatura;

         
    }
    promedio /= i;

     printf("\tTemperaturas \nMaxima: %.2f \nMinima: %.2f \nPromedio: %.2f\n", temp_mayor, temp_menor, promedio);
}