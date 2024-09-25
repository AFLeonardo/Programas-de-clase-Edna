#include <stdio.h>

float Pago_vehiculo(int Horas){

    float cargo = 0;

    if (Horas > 24)
        cargo = 300;
    else if (Horas > 3)
        cargo = 10;
    else
        cargo = Horas * 5;
    return cargo;

}

int main()
{
    int i = 0, hora;
    float Estacionamiento[5], Total = 0;
    int horas[5];

    for(i = 0; i < 5 ;  i++)
    {
        printf("Auto# %d\n",i + 1);
        printf("Ingresa las horas de estancia en el estacionamiento: ");
        scanf("%d", &hora);

        horas[i] = hora;
        Estacionamiento[i] = Pago_vehiculo(hora);
        Total += Estacionamiento[i];
    }

    printf("%10s %10s %10s\n", "Auto", "Horas", "Cobro");
    for ( i = 0; i < 5; i++)
    {
        printf("%10d%10d%10.2f\n", i + 1, horas[i], Estacionamiento[i]);
    }

    printf("Total general: %.2f\n", Total);
    return 0;
}
