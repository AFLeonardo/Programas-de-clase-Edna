#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool ValidarLetraEnString(char *string, char letra);
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

    } while (!ValidarCadena(cadena));

    printf("Ingrese una letra: ");
    fflush(stdin);
    scanf(" %c", &letra);

    if (islower(letra))
        encontrada = ValidarLetraEnString(&cadena, letra);
    else
        encontrada = ValidarLetraEnString(&cadena, toupper(letra));


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
    while (*cadena) 
    {
        if (!isalpha(*cadena) && !isspace(*cadena)) {
            return false; 
        }
        cadena++;
    }
    return true;
}