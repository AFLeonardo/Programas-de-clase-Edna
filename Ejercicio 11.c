#include <stdio.h>

int main()
{
    int astediscos = 0, f = 0;

    printf("Ingrese la cantidad de astediscos (valor max de 20): \n");
    scanf("%d", &astediscos);

    while (astediscos <= 1 || astediscos > 20)
    {
        printf("Ingrese la cantidad de astediscos (valor max de 20): \n");
        scanf("%d", &astediscos);
    }

    for (f=0; f < astediscos; f++)
    {
        for (int i = 0; i < astediscos; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    
        
    
}