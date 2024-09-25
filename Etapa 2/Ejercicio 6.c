#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Utilizar codigo ASCII
bool ValidarLetraEnString(char *, char *);
bool ValidarCadena(char *cadena);

int main()
{
    char cadena[100],
         letra;
    bool encontrada;

    do
    {
        printf("Ingrese una cadena de caracteres: ");
        gets(cadena);
        // Validar con codigo ASCII
        if(!ValidarCadena(cadena))
            printf("ERROR. \nCadena no valida.\n")

    } while (!ValidarCadena(cadena));

    printf("Ingrese una letra: ");
    fflush(stdin);
    scanf(" %c", &letra);

    if (islower(letra))
        encontrada = ValidarLetraEnString(&cadena, &letra);
    else
        encontrada = ValidarLetraEnString(&cadena, toupper(&letra));


    printf("La letra \"%c\" %s en la cadena \n\"%s\"\n", letra, encontrada ? "esta" : "no esta", cadena);
    system("pause");
    return 0;
}

bool ValidarLetraEnString(char *string, char letra)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == letra)
            return true;
        i++;
    }
    return false;
}

bool ValidarCadena(char *cadena) 
{
    bool valido = false;
    while (*cadena != "\0" || (*cadena > 65 || *cadena <= 90)) 
    {
        if (!isalpha(*cadena) && !isspace(*cadena)) {
            return false; 
        }
        cadena++;
    }
    return true;
}