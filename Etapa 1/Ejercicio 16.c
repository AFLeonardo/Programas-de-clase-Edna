#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Empleado
{
    char clave;
    int edad;
    char sexo;
    float sueldo;
};

int main()
{
    char agregar_datos = 'n';
    int numero_hombres = 0,
        numero_mujeres = 0,
        mujeres_ganan_mas_30k = 0,
        hombres_ganan_menos_40k = 0,
        empleados_mayores_50 = 0;

    float sueldo_max_mujeres = -1,
          sueldo_min_hombres = 1000000000000000,
          nuevo_sueldo = 0;

    struct Empleado Datos_empleado[100];
    int n_empleado = 0;

    printf("Quieres agregar datos?: \n");
    fflush(stdin);
    scanf(" %c", &agregar_datos);

    if (agregar_datos == 's' || agregar_datos == 'S')
    {
        while (agregar_datos  == 's' || agregar_datos  == 'S')
        {
            // CLAVE
            do
            {
                printf("Ingresa la clave del empleado: \n");
                fflush(stdin);
                scanf(" %c", &Datos_empleado[n_empleado].clave);

                if (Datos_empleado[n_empleado].clave != 'A' && Datos_empleado[n_empleado].clave != 'a' &&
                    Datos_empleado[n_empleado].clave !=  'B' && Datos_empleado[n_empleado].clave != 'b')
                    printf("Clave no valida.\n");
                
                
            } while (Datos_empleado[n_empleado].clave != 'A' && Datos_empleado[n_empleado].clave != 'a' &&
                     Datos_empleado[n_empleado].clave != 'B' && Datos_empleado[n_empleado].clave != 'b');

            // EDAD
            do
            {
                printf("Ingresa la edad del empleado: \n");
                scanf("%d", &Datos_empleado[n_empleado].edad);

                if (Datos_empleado[n_empleado].edad > 65 || Datos_empleado[n_empleado].edad < 0)
                {
                    printf("Edad no valida. Rango permitido 0-65.\n");
                }
                
            } while (Datos_empleado[n_empleado].edad > 65 || Datos_empleado[n_empleado].edad < 0);
            
            // SEXOS
            do
            {
                printf("Ingresa el sexo del empleado: \n");
                fflush(stdin);
                scanf(" %c", &Datos_empleado[n_empleado].sexo);

            if (Datos_empleado[n_empleado].sexo != 'f' && Datos_empleado[n_empleado].sexo != 'F' &&
                Datos_empleado[n_empleado].sexo != 'm' && Datos_empleado[n_empleado].sexo != 'M')
                    printf("Sexo no válido.\n");
            if (Datos_empleado[n_empleado].sexo == 'f' || Datos_empleado[n_empleado].sexo == 'F')
                numero_mujeres++;
            else
                numero_hombres++;

            } 
            while (Datos_empleado[n_empleado].sexo != 'f' && Datos_empleado[n_empleado].sexo != 'F' &&
                       Datos_empleado[n_empleado].sexo != 'm' && Datos_empleado[n_empleado].sexo != 'M');

            // SUELDOS
            do
            {
                printf("Ingresa el sueldo del empleado: \n");
                scanf("%f", &Datos_empleado[n_empleado].sueldo);

                if (Datos_empleado[n_empleado].sueldo < 0)
                {
                    printf("El sueldo tiene que ser mayor a 0.\n");
                }
                
            } while (Datos_empleado[n_empleado].sueldo < 0);
            
            if ((Datos_empleado[n_empleado].sexo == 'f' && Datos_empleado[n_empleado].sueldo > 30000 ) || 
                (Datos_empleado[n_empleado].sexo == 'F' && Datos_empleado[n_empleado].sueldo > 30000))
                mujeres_ganan_mas_30k++;

            if ((Datos_empleado[n_empleado].sexo == 'm' && Datos_empleado[n_empleado].sueldo < 40000) ||
                (Datos_empleado[n_empleado].sexo == 'M' && Datos_empleado[n_empleado].sueldo < 40000))
                hombres_ganan_menos_40k++;

            if (Datos_empleado[n_empleado].edad > 50)
                empleados_mayores_50++;

            if (sueldo_max_mujeres < Datos_empleado[n_empleado].sueldo)
                    sueldo_max_mujeres = Datos_empleado[n_empleado].sueldo;

            if (Datos_empleado[n_empleado].sexo == 'm' || Datos_empleado[n_empleado].sexo == 'M')
            {
                if (Datos_empleado[n_empleado].sueldo < sueldo_min_hombres)
                    sueldo_min_hombres = Datos_empleado[n_empleado].sueldo;
            }

            //Aumento de sueldo segun categoria
            if (Datos_empleado[n_empleado].clave == 'A' || Datos_empleado[n_empleado].clave == 'a')
                nuevo_sueldo = Datos_empleado[n_empleado].sueldo * 1.75;
            else
                nuevo_sueldo = Datos_empleado[n_empleado].sueldo * 1.07;

            Datos_empleado[n_empleado].sueldo = nuevo_sueldo;
            printf("Sueldo actualizado: %f\n", Datos_empleado[n_empleado].sueldo);

            printf("Quieres agregar datos?: \n");
            fflush(stdin);
            scanf(" %c", &agregar_datos);
            

        n_empleado++;
        }

        printf("Numero de mujeres: %d\n", numero_mujeres);
        printf("Numero de hombres: %d\n", numero_hombres);
        printf("Numero de mujeres que ganan mas de 30k: %d\n", mujeres_ganan_mas_30k);
        printf("Numero de hombres que ganan menos de 40k: %d\n", hombres_ganan_menos_40k);
        printf("Numero de empleados mayores a 50: %d\n", empleados_mayores_50);
        printf("Sueldo maximo de las mujeres: %f\n", sueldo_max_mujeres);
        printf("Sueldo minimo de los hombres: %f\n", sueldo_min_hombres);
    }
    else
        printf("No se agregaron datos.\n");
    
    return 0;
}