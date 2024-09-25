#include <stdio.h>
// GUARDALO EN UN ARREGLO

float potencia(float, float)

float potencia(float base, float indice)
{
    float resultado = 1;
    int i;
    for (i = 0; i < indice ; i++)
        resultado *= base;
    return resultado;
}

int main()
{
    int i;
    float Resultados[5][3];
    for (i = 0 ; i < 5 ;i++)
    {
        printf("Ingrese la base: \n");
        scanf("%f", &Resultados[i][0]);
        printf("Ingrese el indice: \n");
        scanf("%f", &Resultados[i][1]);
        Resultados[i][2] = potencia(Resultados[i][0], Resultados[i][1]);
    }

    printf("%10s %10s %10s\n", "Base", "Exponente", "Resultado");
    
    for (i = 0; i < 5; i++)
    {
        printf("%10.0f %10.0f %10.0f\n", Resultados[i][0], Resultados[i][1], Resultados[i][2]);
    }
    
    return 0;
}