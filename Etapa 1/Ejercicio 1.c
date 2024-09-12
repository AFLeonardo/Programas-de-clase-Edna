#include <stdio.h>

main()
{
    int numero1, numero2, resultado;
    
    printf("Digite el primer numero: ");
    scanf("%d", &numero1);
    
    printf("Digite el segundo numero: ");
    scanf("%d", &numero2);
    
    resultado = numero1 + numero2;
    printf("El resultado de la suma es: %d\n", resultado);
}
