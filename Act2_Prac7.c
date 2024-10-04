#include <stdio.h>

#define SIZE 20

int main() {
    int A[SIZE], B[SIZE], C[SIZE];

    // Leer los valores del vector A
    printf("Ingrese los 20 elementos del vector A:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    // Leer los valores del vector B
    printf("\nIngrese los 20 elementos del vector B:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    // Multiplicar elementos de A con B en orden inverso
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] * B[SIZE - 1 - i];
    }

    // Imprimir los vectores A, B y C
    printf("\nVector A:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }

    printf("\n\nVector B:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", B[i]);
    }

    printf("\n\nVector C (resultado de A[i] * B[SIZE - 1 - i]):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", C[i]);
    }

    printf("\n");

    return 0;
}
