#include <stdio.h>

int main()
{
    float Peso_promedio_h = 0,
          Peso_promedio_m = 0,
          Altura_promedio_h = 0,
          Altura_promedio_m = 0;
    char agregar = 'n',
         genero;
    int hombres = 0,
        mujeres = 0;

    printf("Quieres agregar datos?");
    fflush(stdin);
    scanf("%c", &agregar);

    if (agregar == 's')
    {
        while (agregar == 's')
        {
            printf("Ingrese su genero (h/m): ");
            fflush(stdin);
            scanf("%c", &genero);
            if (genero == 'h')
            {
                printf("Ingrese su peso: ");
                fflush(stdin);
                scanf("%f", &Peso_promedio_h);
                printf("Ingrese su altura: ");
                fflush(stdin);
                scanf("%f", &Altura_promedio_h);
                hombres += 1;
            }
            else
            {
                printf("Ingrese su peso: ");
                fflush(stdin);
                scanf("%f", &Peso_promedio_m);
                printf("Ingrese su altura: ");
                fflush(stdin);
                scanf("%f", &Altura_promedio_m);
                mujeres += 1;
            }

            printf("Quieres agregar datos?");
            fflush(stdin);
            scanf("%c", &agregar);
        }

        Peso_promedio_h = Peso_promedio_h / hombres;
        Peso_promedio_m = Peso_promedio_m / mujeres;
        Altura_promedio_h = Altura_promedio_h / hombres;
        Altura_promedio_m = Altura_promedio_m / mujeres;

        printf("El peso promedio de los hombres es: %.2f\n", Peso_promedio_h);
        printf("El peso promedio de las mujeres es: %.2f\n", Peso_promedio_m);
        printf("La altura promedio de los hombres es: %.2f\n", Altura_promedio_h);
        printf("La altura promedio de las mujeres es: %.2f\n", Altura_promedio_m);
    }
    else
        printf("No existen datos.");
    
}