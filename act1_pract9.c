#include <stdio.h>

int main() {
    char cad[51];
    int i;

    printf("Introduzca una cadena de a los mas 50 carácteres: ");
    fgets(cad, sizeof(cad), stdin);

    printf("Vocales encontrada en la cadena: ");
    for (i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == 'a' || cad[i] == 'e' || cad[i] == 'i' || cad[i] == 'o' || 
            cad[i] == 'u' || cad[i] == 'A' || cad[i] == 'E' || cad[i] == 'I' ||
            cad[i] == 'O' || cad[i] == 'U') {
            printf("%c, ", cad[i]);
        }
    }
    printf("\n");
    return 0;
}
