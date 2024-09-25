#include <stdio.h>
#include <stdbool.h>

int main()
{
    float salario, pago_x_hora;
    int hrs_extra, categoria;
    bool Categorias_hrs_extra = true;

    printf("Digite su salario: ");
    scanf("%f", &salario);
    printf("Digite su categoria: ");
    scanf("%d", &categoria);
    printf("Digite las horas extras trabajadas: ");
    scanf("%d", &hrs_extra);

    if (hrs_extra > 30)
    {
        printf("Lo sentimos, solo permitimos como maximo 30 horas extras.\n");
        hrs_extra = 30;
    }

    // Asigna el pago por hora dependiendo de la categoria
    switch (categoria)
    {
    case 1:
        pago_x_hora = 30;
        break;
    case 2:
        pago_x_hora = 40;
        break;
    case 3:
        pago_x_hora = 50;
        break;
    case 4:
        pago_x_hora = 70;
        break;
    default:
        pago_x_hora = 0;
        Categorias_hrs_extra = false;
        break;
    }

    salario += (hrs_extra * pago_x_hora);

    //Mensaje para los que ganan horas extras y quines no
    if (Categorias_hrs_extra)
    {
        printf("Su salario total es de: $%.2f\n", salario);
        printf("El monto generado por las horas extra es de: $%.2f\n", hrs_extra * pago_x_hora);
    }
    else    printf("No se genero horas extra, su salario total es de: $%.2f\n", salario);


}