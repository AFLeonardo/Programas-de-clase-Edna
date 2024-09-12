#include <stdio.h>

int main() {
    int A = 3;  // Valor inicial de A
    int filas = 5;
    int columnas = 4;

    // Bucle para cada fila
    for (int i = 0; i < filas; i++) {
        // Bucle para cada columna
        for (int j = 0; j < columnas; j++) 
        {
            printf("%d\t", A + j * 2);
        }
        printf("\n");  // Nueva línea después de cada fila
        A += 3;  // Incrementar A para la siguiente fila
    }

    return 0;
}
