#include <stdio.h>
#include <string.h>

int main() {
    char cadena[51]; 
    int suma = 0;

    printf("Introduce una cadena (máximo 50 caracteres): ");
    gets(cadena);

    cadena[strcspn(cadena, "\n")] = '\0';

    for (int i = 0; cadena[i] != '\0'; i++) {
        suma += (int)cadena[i];  

    printf("La suma de los valores ASCII de los caracteres es: %d\n", suma);

    return 0;
}
