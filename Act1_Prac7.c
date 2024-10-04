#include <stdio.h>
int main(){
	
    int n,i,count=0;
    float sum=0,prom;
    printf("Ingrese la cantidad de valores en el vector: "); scanf("%i",&n);
    int vector[n];
    printf("Ingrese los valores del vector:\n");
    for(i=0;i<n;i++){
        printf("%i. ", i+1); scanf("%i",&vector[i]);
        sum+=vector[i];
    }
    prom=(float)sum/n;
    printf("\nVector: ");
    for(i=0;i<n;i++){
        printf("%i ",vector[i]);
    }
    printf("\n\nEl promedio es: %.2f\n",prom);
    printf("Vector de valores mayores que el promedio: ");
    for(i=0;i<n;i++){
        if(vector[i]>prom){
            printf("%i ",vector[i]);
            count++;
        }
    }
    if(count==0){
        printf("No hay valores mayores que el promedio");
    }
    printf("\nCantidad de valores mayores que el promedio: %i\n",count);

    return 0;
}

