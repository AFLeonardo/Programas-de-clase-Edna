#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// PROTOTIPO de funciones
bool ValidarLetraEnString(char *string, char *letra);
bool ValidarCadena(char *cadena);

int main()
{
    char cadena[100], letra;
    bool encontrada;

    do
    {
        printf("Ingrese una cadena de caracteres: ");
        gets(cadena); 
        // Validar la cadena con el código ASCII
        if (!ValidarCadena(cadena))
            printf("ERROR. \nCadena no valida.\n");

    } while (!ValidarCadena(cadena));

    printf("Ingrese una letra: ");
    fflush(stdin);
    scanf(" %c", &letra);

    encontrada = ValidarLetraEnString(cadena, &letra);

    printf("La letra \"%c\" %s en la cadena \n\"%s\"\n", letra, encontrada ? "esta" : "no esta", cadena);
    system("pause");
    return 0;
}


bool ValidarLetraEnString(char *string, char *letra)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == *letra)
            return true;
        i++;
    }
    return false;
}

// Rama main
bool ValidarCadena(char *cadena) 
{
    while (*cadena != '\0') 
    {
        
        if (!((*cadena >= 'A' && *cadena <= 'Z') || 
              (*cadena >= 'a' && *cadena <= 'z') || 
              *cadena == ' '))
        {
            return false;
        }
        cadena++;
    }
    return true;
}