#include <stdio.h>

main() {
    float salario, nuevoSaldo;

    printf("Ingresa el salario actual del trabajador: $");
    scanf("%f", &salario);

    if (salario <= 20000)
        nuevoSaldo = salario * 1.75;
    else if (salario > 10000)
        nuevoSaldo = salario * 1.08;
    else 
        nuevoSaldo = salario;

    printf("El nuevo saldo del trabajador es: $%.2f\n", nuevoSaldo);
}
