#include <stdio.h>
#include <string.h> // Para usar strcpy

float sueldo = 0, Pago_total = 0, pago_por_hora = 0, pago_venta = 0, pago_pieza = 0;
int empleados, horas_trabajadas, horas_extra = 0, ventas_sem, piezas;
char categoria;
char puesto[40];

int main()
{
    for (empleados = 1; empleados <= 50; empleados++)
    {
        printf("Bienvenido empleado # %d\n", empleados);
        printf("Ingrese su categoria: ");
        
        scanf(" %c", &categoria);
        
        // Usar un switch para asignar el sueldo según la categoría
        switch (categoria)
        {
        case 'A':
            // Sueldo semanal fijo
            strcpy(puesto, "Gerente");
            sueldo = 5000;
            break;

        case 'B':
            strcpy(puesto, "Trabajadores por hora");

            printf("Ingrese la cantidad de horas trabajadas: ");
            scanf("%d", &horas_trabajadas);

            printf("Ingrese el pago por hora: ");
            scanf("%f", &pago_por_hora);

            if (horas_trabajadas > 40)
            {
                horas_extra = horas_trabajadas - 40;
            }

            sueldo = horas_trabajadas * pago_por_hora;
            sueldo += horas_extra * (pago_por_hora * 1.5);
            break;

        case 'C':
            strcpy(puesto, "Trabajadores comision");
            sueldo = 3000;
            printf("Ingrese la cantidad de ventas semanal: ");
            scanf("%d", &ventas_sem);

            printf("Ingrese el pago por venta: ");
            scanf("%f", &pago_venta);

            sueldo += (ventas_sem * pago_venta) * 0.057;
            break;
            
        case 'D':
            strcpy(puesto, "Trabajadores destajo");
            printf("Ingrese la cantidad de piezas fabricadas: ");
            scanf("%d", &piezas);
            printf("Ingrese el pago por pieza: ");
            scanf("%f", &pago_pieza);

            sueldo = piezas * pago_pieza;
            break;

        default:
            printf("Categoria invalida. Intente de nuevo.\n");
            empleados--;
            continue; // Vuelve al inicio del bucle

        }

        printf("El puesto es: %s\n", puesto);
        printf("El sueldo asignado es: %.2f\n", sueldo);

        Pago_total += sueldo; // Acumula el pago total
    }
    
    printf("Listo.\nEl pago total es de: %.2f. Tenga un buen dia.\n", Pago_total);
    return 0;
}
