#include <stdio.h>

main()
{
   //Declaracion de variables
   int matricula, alumnos= 1;
   
   // For para controlar la cantidad de alumnos
   for(alumnos; alumnos <= 3; alumnos++)
   {
      // Variables que cambian de valor en cada iteracion
      float promedio = 0, calificacion = 0;
      int examen = 1;

      // Validacion de la matricula > 0
      do
      {
         printf("Ingrese tu matricula: \n");
         scanf(" %d", &matricula);

         if (matricula <= 0)
            printf("Matricula no valida. Intenta de nuevo.\n");

      } while (matricula <= 0);
      
      // For para pedir las califaciones de los 5 examenes
      for (examen; examen<= 5 ;examen++)
      {
         // Validacion de calif en rango (0,100)
         do
         {
            printf("Ingrese la calificacion del examen %d: ", examen);
            scanf("%f", &calificacion);

            if (calificacion < 0 || calificacion > 100)
               printf("Error. Datos permitidos entre 0 y 100. Intente de nuevo\n");

         } while (calificacion < 0 || calificacion > 100);
         
         // Variable que guarda las 5 califs del alumnos para despues sacar el promedio
         promedio += calificacion;
      }

      // Operacion para obtener el promedio de las califs
      promedio /= 5;

      // Formato de impresion
      printf("-------------------\n");
      printf("Alumno %d \n", alumnos);
      printf("\t- Matricula: %d \n", matricula);
      printf("\t- Promedio: %.2f \n", promedio);
      printf("-------------------\n\n\a");
   }
   
}
